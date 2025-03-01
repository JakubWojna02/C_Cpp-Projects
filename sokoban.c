#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Pozycja gracza na planszu
typedef struct {
    int x, y;
} Position;

// Struktura pomagajaca wczytywac ruchy z pliku
typedef struct {
    char** ruchy;
    int liczbaRuchow;
} RuchyPliku;

// Struktura do kolejki
typedef struct {
    Position *positions;
    int front, rear;
} Queue;

// Struktura obslugujaca ruchy ktorymi "gram"
typedef struct {
    char** ruchy;
    int liczbaRuchow;
    int pojemnosc;
} Ruchy;

// Struktura opisujaca stan gry
typedef struct {
    Position player;
    Position boxes[26];
    char*** snapshot_history;
    int snapshot_count;
    int box_count;
    char** board;
    int height;
    int width;
    int max_moves;
} GameState;

// Wymyslanie kola na nowa
char *my_strdup(const char *src) {
    if (src == NULL) {
        return NULL;
    }
    size_t length = strlen(src) + 1; // +1 dla znaku null
    char *dest = malloc(length);
    if (dest == NULL) {
        return NULL;
    }
    memcpy(dest, src, length);
    return dest;
}


// Ta funkcja jest po to, aby ustalic mi zmienna w stylu MAX_MOVES (ktora byla kiedys zadeklarowana ale ja usunalem
// dla przejrzystosci kodu. Teraz MAX_MOVES to po prostu liczba znakow (gdybym mial plik gdzie trafia sie same zera,
// to liczba tych zer to ilosc maksymalnych ruchow)
void policzZnakiZBufora(GameState *state, const char *bufor) {
    const char *ptr = bufor;
    char linia[1024];
    bool liczenieRozpoczete = false;
    state->max_moves = 0; // Inicjalizacja zmiennej w strukturze

    while (*ptr != '\0') {
        size_t i = 0;

        // Odczytywanie jednej linii z bufora
        while (*ptr != '\n' && *ptr != '\0' && i < sizeof(linia) - 1) {
            linia[i++] = *ptr++;
        }
        if (*ptr == '\n') ptr++; // Pomijanie znaku nowej linii
        linia[i] = '\0'; // Null-terminator

        if (liczenieRozpoczete) {
            // Sprawdź, czy linia zawiera kropkę
            if (linia[0] == '.' && linia[1] == '\0') {
                break; // Koniec liczenia, znaleziono kropkę
            }
            state->max_moves += (int)strlen(linia); // Dodaj długość linii do licznika znaków
        } else if (strlen(linia) == 0) {
            // Znaleziono pustą linię, rozpoczynamy liczenie
            liczenieRozpoczete = true;
        }
    }
}



// Funkcja inicjalizująca dynamiczne strukturę Ruchy
void inicjalizujRuchy(Ruchy* ruchy, RuchyPliku* ruchyPliku) {
    int poczatkowaPojemnosc = (ruchyPliku->liczbaRuchow > 0) ? ruchyPliku->liczbaRuchow : 10;
    ruchy->ruchy = malloc((size_t)poczatkowaPojemnosc * sizeof(char*));
    if (!ruchy->ruchy) {
        perror("Błąd alokacji pamięci w inicjalizujRuchy");
        exit(EXIT_FAILURE);
    }
    ruchy->liczbaRuchow = 0;
    ruchy->pojemnosc = poczatkowaPojemnosc;
}

//
// Funkcja dodająca ruch do struktury
void dodajRuch(Ruchy* ruchy, const char* ruch) {
    if (ruchy->liczbaRuchow >= ruchy->pojemnosc) {
        // Zwiększanie pojemności tablicy
        ruchy->pojemnosc *= 2;
        ruchy->ruchy = realloc(ruchy->ruchy, (size_t)ruchy->pojemnosc * sizeof(char*));
        if (!ruchy->ruchy) {
            perror("Błąd alokacji pamięci w dodajRuch");
            exit(EXIT_FAILURE);
        }
    }
    // Dodanie ruchu do tablicy
    ruchy->ruchy[ruchy->liczbaRuchow] = my_strdup(ruch);
    ruchy->liczbaRuchow++;
}

// Funkcja dodająca wartość "1" do struktury
void dodajZnacznik(Ruchy* ruchy) {
    dodajRuch(ruchy, "1");
}

// Funkcja zwalniająca pamięć używaną przez strukturę Ruchy
void zwolnijRuchy(Ruchy* ruchy) {
    for (int i = 0; i < ruchy->liczbaRuchow; i++) {
        free(ruchy->ruchy[i]);
    }
    free(ruchy->ruchy);
}

// Funkcja sprawdzająca, czy ruch jest prosty, pomysl jest taki ze wczytuje z pliku ruchy, jesli sa zwykle to okej
// Jesli sa dluzsze niz dwa to rozbijam te ruchy na proste, natomiast gdy trafie na endline to wpisuje 1 do tablicy
// Ta jedynka jest potrzebna po to, aby moj program mogl drukowac plansze w odpowiednim momencie
int czyRuchProsty(const char* ruch) {
    size_t dlugosc = strlen(ruch);
    if (dlugosc == 1 && ruch[0] == '0') {
        return 1;
    }
    if (dlugosc == 2 && isalpha(ruch[0]) && isdigit(ruch[1])) {
        return 1;
    }
    return 0;
}

// Funkcja rozbijająca ruch złożony na składowe
char** rozbijRuchZlozony(const char* ruch, int* liczbaSkadowych) {
    size_t dlugosc = strlen(ruch);
    *liczbaSkadowych = 0;
    char** skadowe = malloc(dlugosc * sizeof(char*));
    if (!skadowe) {
        perror("Błąd alokacji pamięci w rozbijRuchZlozony");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < dlugosc; i += 2) {
        size_t skadowaDlugosc = (i + 1 < dlugosc) ? 2 : 1;
        skadowe[*liczbaSkadowych] = malloc((skadowaDlugosc + 1) * sizeof(char));
        if (!skadowe[*liczbaSkadowych]) {
            perror("Błąd alokacji pamięci w rozbijRuchZlozony");
            exit(EXIT_FAILURE);
        }
        strncpy(skadowe[*liczbaSkadowych], ruch + i, skadowaDlugosc);
        skadowe[*liczbaSkadowych][skadowaDlugosc] = '\0';
        (*liczbaSkadowych)++;
    }
    return skadowe;
}


// Funkcja przetwarzająca ruchy i zapisująca je w strukturze Ruchy
void przetwarzajRuchy(RuchyPliku* ruchyPliku, Ruchy* zapisaneRuchy) {
    for (int i = 0; i < ruchyPliku->liczbaRuchow; i++) {
        if (czyRuchProsty(ruchyPliku->ruchy[i])) {
            dodajRuch(zapisaneRuchy, ruchyPliku->ruchy[i]);
        } else {
            int liczbaSkadowych = 0;
            char** skadowe = rozbijRuchZlozony(ruchyPliku->ruchy[i], &liczbaSkadowych);
            for (int j = 0; j < liczbaSkadowych; j++) {
                dodajRuch(zapisaneRuchy, skadowe[j]);
                free(skadowe[j]);
            }
            free(skadowe);
        }
        // Dodaj znacznik "1" po każdym ruchu
        dodajZnacznik(zapisaneRuchy);
    }
}

// Funkcja wczytująca ruchy z pliku
RuchyPliku wczytajRuchyZBufora(const char* bufor) {
    const char* ptr = bufor;
    char** ruchy = NULL; // Dynamiczna alokacja tablicy
    int liczbaRuchow = 0;
    size_t pojemnosc = 10; // Początkowa pojemność
    ruchy = malloc(pojemnosc * sizeof(char*));
    if (!ruchy) {
        perror("Błąd alokacji pamięci");
        exit(EXIT_FAILURE);
    }

    char linia[256];
    int czyZaczacCzytac = 0;

    while (*ptr != '\0') {
        size_t i = 0;

        // Czytanie linii z bufora
        while (*ptr != '\n' && *ptr != '\0' && i < sizeof(linia) - 1) {
            linia[i++] = *ptr++;
        }
        if (*ptr == '\n') ptr++; // Przejdź do następnej linii
        linia[i] = '\0'; // Null-terminator

        if (linia[0] == '\0') {
            czyZaczacCzytac = 1; // Pusta linia sygnalizuje początek ruchów
            continue;
        }

        if (czyZaczacCzytac) {
            if (strcmp(linia, ".") == 0) {
                break; // Kropka kończy wczytywanie
            }

            // Zwiększenie tablicy, jeśli jest pełna
            if (liczbaRuchow >= (int)pojemnosc) {
                pojemnosc *= 2;
                ruchy = realloc(ruchy, pojemnosc * sizeof(char*));
                if (!ruchy) {
                    perror("Błąd alokacji pamięci przy zwiększaniu tablicy");
                    exit(EXIT_FAILURE);
                }
            }

            // Kopiowanie linii do tablicy ruchów
            ruchy[liczbaRuchow] = my_strdup(linia);
            if (!ruchy[liczbaRuchow]) {
                perror("Błąd alokacji pamięci dla ruchu");
                exit(EXIT_FAILURE);
            }
            liczbaRuchow++;
        }
    }

    // Alokuje zmienne dla struktury RuchyPliku, które pomogą w późniejszym rozczłonkowaniu tych ruchów
    RuchyPliku wynik;
    wynik.ruchy = ruchy;
    wynik.liczbaRuchow = liczbaRuchow;

    return wynik;
}


void freeWczytaneRuchy(RuchyPliku* ruchyPliku) {
    if (ruchyPliku->ruchy) {
        // Zwolniam pamięc dla każdego ruchu
        for (int i = 0; i < ruchyPliku->liczbaRuchow; i++) {
            free(ruchyPliku->ruchy[i]);
        }
        // Zwolniam pamięc dla tablicy ruchów
        free(ruchyPliku->ruchy);
        ruchyPliku->ruchy = NULL; // Ustawiam wskaźnik na NULL dla bezpieczeństwa wycieku pamieci
    }
    ruchyPliku->liczbaRuchow = 0; // Resetuje liczbe ruchów
}

// Funkcja aloukjaca pamiec dla samej planszy do gru
int alokujPlansze(GameState* state) {
    state->board = malloc((size_t)state->height * sizeof(char*));
    if (!state->board) {
        perror("Błąd alokacji pamięci dla board");
        return 0;
    }
    for (size_t i = 0; i < (size_t)state->height; i++) {
        state->board[i] = malloc((size_t)(state->width + 1) * sizeof(char)); // +1 dla '\0'
        if (!state->board[i]) {
            perror("Błąd alokacji pamięci dla wiersza");
            for (size_t j = 0; j < i; j++) {
                free(state->board[j]);
            }
            free(state->board);
            state->board = NULL;
            return 0;
        }
    }
    return 1; // Sukces
}

// Funkcja alokujaca pamiec dla snapshotow planszy
char*** allocate_snapshot_history(GameState* state) {
    char*** snapshot_history = malloc((size_t)state->max_moves * sizeof(char**));
    if (!snapshot_history) {
        perror("Błąd alokacji pamięci dla snapshot_history");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < (size_t)state->max_moves; i++) {
        snapshot_history[i] = malloc((size_t)state->height * sizeof(char*));
        if (!snapshot_history[i]) {
            perror("Błąd alokacji pamięci dla snapshot_history[i]");
            exit(EXIT_FAILURE);
        }
        for (size_t j = 0; j < (size_t)state->height; j++) {
            snapshot_history[i][j] = malloc((size_t)(state->width + 1) * sizeof(char));
            if (!snapshot_history[i][j]) {
                perror("Błąd alokacji pamięci dla snapshot_history[i][j]");
                exit(EXIT_FAILURE);
            }
        }
    }
    return snapshot_history;
}

void free_snapshot_history(GameState*state) {
    for (int i = 0; i < state->max_moves; i++) {
        for (int j = 0; j < state->height; j++) {
            free(state->snapshot_history[i][j]); // Zwalniam każdy wiersz
        }
        free(state->snapshot_history[i]); // Zwalniam tablice wierszy
    }
    free(state->snapshot_history); // Zwalniam główna tablice wskaźników
}
// Funkcja wczytująca planszę z pliku
int wczytajPlansze(const char* bufor, GameState* state) {
    const char* ptr = bufor;
    char linia[1024];
    state->height = 0;
    state->width = 0;

    // Pierwszy przebieg: Obliczenie wymiarów planszy
    while (*ptr != '\0') {
        size_t i = 0;
        while (*ptr != '\n' && *ptr != '\0' && i < sizeof(linia) - 1) {
            linia[i++] = *ptr++;
        }
        if (*ptr == '\n') ptr++; // Przejdź do następnej linii w buforze
        linia[i] = '\0'; // Null-terminator

        if (i == 0) {
            break; // Koniec wczytywania planszy
        }
        if (i > (size_t)state->width) {
            state->width = (int)i; // Rzutowanie na int
        }
        state->height++;
    }
    if (state->height == 0 || state->width == 0) {
        fprintf(stderr, "Plansza jest pusta lub niepoprawna!\n");
        return 0;
    }

    // Alokacja tablicy na podstawie wymiarów
    if (!alokujPlansze(state)) {
        return 0;
    }

    // Drugi przebieg: Wczytanie danych do tablicy
    ptr = bufor;
    state->height = 0;
    while (*ptr != '\0') {
        size_t i = 0;
        while (*ptr != '\n' && *ptr != '\0' && i < sizeof(linia) - 1) {
            linia[i++] = *ptr++;
        }
        if (*ptr == '\n') ptr++; // Przejdź do następnej linii w buforze
        linia[i] = '\0'; // Null-terminator

        if (i == 0) {
            break; // Koniec wczytywania planszy
        }
        strncpy(state->board[state->height], linia, (size_t)state->width); // Rzutowanie na size_t
        state->board[state->height][state->width] = '\0'; // Null-terminator
        state->height++;
    }

    // Alokacja historii snapshotów po ustaleniu height i width
    state->snapshot_history = allocate_snapshot_history(state);

    // Inicjalizuje snapshoty
    state->snapshot_count = 0;

    return 1;
}

// Funkcja zwalniajaca zaalokowana pamiec dla planszy
void free_board(GameState* state) {
    if (state->board) {
        for (int i = 0; i < state->height; i++) {
            free(state->board[i]);
        }
        free(state->board);
        state->board = NULL;
    }
}
// Funkcja znajdująca pozycje gracza "@" na zaimportowanej planszy
Position player_pos = {0};
void find_player_position(GameState* state) {
    for (int y = 0; y < state->height; y++) {
        for (int x = 0; x < state->width; x++) {
            if (state->board[y][x] == '@' || state->board[y][x] == '*') {
                player_pos = (Position){x, y};
                return;
            }
        }
    }
}

// Tutaj są funkcje do kolejki
// Inicjalizuje kolejkę i alokuje pamięć dla pozycji
void queue_init(Queue *queue, GameState *state) {
    queue->front = 0;
    queue->rear = 0;
    queue->positions = malloc((size_t)state->height * (size_t)state->width * sizeof(Position));
    // Errory dot. alokacji pamięci postanowiłem pozostawić w kodzie ze względu na testy valgrind
    if (!queue->positions) {
        perror("Błąd alokacji pamięci dla kolejki");
        queue->positions = NULL; // Zabezpieczenie
    }
}
// Sprawdzam czy kolejka pusta
bool queue_is_empty(Queue *q) {
    return q->front == q->rear;
}
// Pcham kolejke
bool queue_push(Queue *q, Position pos, GameState*state) {
    if ((q->rear + 1) % (state->height * state->width) == q->front) {
        return false; // Queue is full
    }
    q->positions[q->rear] = pos;
    q->rear = (q->rear + 1) % (state->height * state->width);
    return true;
}

Position queue_pop(Queue *q, GameState *state) {
    if (queue_is_empty(q)) {
        fprintf(stderr, "Błąd: próba pobrania z pustej kolejki\n");
        exit(EXIT_FAILURE); // Lub obsłuż błąd w inny sposób
    }
    Position pos = q->positions[q->front];
    q->front = (q->front + 1) % (state->height * state->width);
    return pos;
}
// Funkcja zwalanjaca pamiec zalokowana dla kolejki
void queueFree(Queue *queue) {
    if (queue->positions) { // Sprawdzam czy pamięć została zaalokowana
        free(queue->positions); // Zwalniam pamięć
        queue->positions = NULL; // Ustawiam wskaźnik na NULL
    }
    queue->front = queue->rear = 0; // Resetujem wskaźniki
}



// Funkcja zapisująca plansze (snapshot) w ustalonym momencie
void save_current_board(GameState* state) {
    if (state->snapshot_count < state->max_moves) {
        for (int i = 0; i < state->height; i++) {
            strcpy(state->snapshot_history[state->snapshot_count][i], state->board[i]);
        }
        state->snapshot_count++;
    }
}
// Funkcja drukująca snapshot gry w ustalonym momencie
void print_snapshots(GameState*state) {
    for (int s = 0; s < state->snapshot_count; s++) {
        for (int i = 0; i < state->height; i++) {
            printf("%s\n", state->snapshot_history[s][i]);
        }
        printf("\n");
    }
}

// Ta logika gwagranuje, że pierwsze cofnięcie jest zawsze o jeden ruch, a nie o dwa
bool first_undo = true;
bool undo_move(GameState* state) {
    if (first_undo) {
        first_undo = false;
    }

    if (state->snapshot_count > 1) { // Cofanie jest możliwe tylko przy więcej niż jednym snapshotcie
        state->snapshot_count--; // Cofamy dokładnie jeden krok
        for (int i = 0; i < state->height; i++) {
            strcpy(state->board[i], state->snapshot_history[state->snapshot_count - 1][i]);
        }

        // Przywracam pozycję gracza
        for (int y = 0; y < state->height; y++) {
            for (int x = 0; x < state->width; x++) {
                if (state->board[y][x] == '@') {
                    player_pos = (Position){x, y};
                }
            }
        }
        return true;
    }
    return false;
}

// Funkcja wyswietlająca planszę
void display_board(GameState* state) {
    for (int y = 0; y < state->height; y++) {
        printf("%s\n", state->board[y]);
    }
}

// Funkcja sprawdzajaca, czy ople na ktore sie poruszam jest legalne czy nie
bool is_valid_position(int x, int y, GameState* state) {
    // Najpierw sprawdzam, czy współrzędne są w granicach planszy
    if (x < 0 || x >= state->width || y < 0 || y >= state->height) {
        return false;
    }
    if (state->board[y][x] == '\0') {
        return false;
    }
    // Następnie sprawdzam, czy nie jest to ściana
    if (state->board[y][x] == '#') {
        return false;
    }
    return true;
}


// Funkcja ktora usuwa znaki gracza "@" po iteracji BFS, pozostawia tylko ten docelowy
void clear_player_position(GameState* state) {
    for (int y = 0; y < state->height; y++) {
        for (int x = 0; x < state->width; x++) {
            if (state->board[y][x] == '@' || state->board[y][x] == '*') {
                char new_char = (state->board[y][x] == '*') ? '+' : '-';
                state->board[y][x] = new_char;
            }
        }
    }
}

// Wpadlem na pomysł aby użyć BFSu do znaleznenia najkrotszej drogi miedzy graczem a pudełkiem,
// Moim zdaniem jest to wygodne a zarazem dość szybkie w porównnaniu z moimi alternatywnymi pomysłami
bool bfs_find_path(Position start, Position target, Position *path, GameState* state) {
    // Dynamiczna alokacja tablicy
    int **visited = malloc((size_t)state->height * sizeof(int *));
    Position **previous = malloc((size_t)state->height * sizeof(Position *));
    for (int i = 0; i < state->height; i++) {
        visited[i] = malloc((size_t)state->width * sizeof(int));
        previous[i] = malloc((size_t)state->width * sizeof(Position));
    }

    // Inicjalizacja tablic
    for (int i = 0; i < state->height; i++) {
        for (int j = 0; j < state->width; j++) {
            visited[i][j] = 0;
            previous[i][j] = (Position){-1, -1};
        }
    }

    Queue q;
    queue_init(&q, state);
    if (!q.positions) {
        // Zwolnienie pamięci w przypadku błędu alokacji
        for (int i = 0; i < state->height; i++) {
            free(visited[i]);
            free(previous[i]);
        }
        free(visited);
        free(previous);
        return false;
    }

    if (!queue_push(&q, start, state)) {
        queueFree(&q);
        fprintf(stderr, "Błąd: kolejka jest pełna.\n");
        // Zwolnienie pamięci w przypadku błędu alokacji
        for (int i = 0; i < state->height; i++) {
            free(visited[i]);
            free(previous[i]);
        }
        free(visited);
        free(previous);
        return false;
    }
    visited[start.y][start.x] = 1;

    while (!queue_is_empty(&q)) {
        Position current = queue_pop(&q, state);
        if (current.x == target.x && current.y == target.y) {
            Position step = target;
            int path_length = 0;
            while (step.x != -1 && step.y != -1) {
                path[path_length++] = step;
                step = previous[step.y][step.x];
            }
            for (int i = 0; i < path_length / 2; i++) {
                Position temp = path[i];
                path[i] = path[path_length - i - 1];
                path[path_length - i - 1] = temp;
            }
            queueFree(&q); // Zwolnienie pamięci kolejki
            // Zwolnienie pamięci tablic
            for (int i = 0; i < state->height; i++) {
                free(visited[i]);
                free(previous[i]);
            }
            free(visited);
            free(previous);
            return true;
        }
        Position directions[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            Position next = {current.x + directions[k].x, current.y + directions[k].y};

            if (is_valid_position(next.x, next.y, state) &&
                !visited[next.y][next.x] &&
                !isalpha(state->board[next.y][next.x])) {
                visited[next.y][next.x] = 1;
                previous[next.y][next.x] = current;

                if (!queue_push(&q, next, state)) {
                    queueFree(&q); // Zwolnienie pamięci w przypadku błędu
                    fprintf(stderr, "Błąd: kolejka jest pełna.\n");
                    // Zwolnienie pamięci tablic
                    for (int i = 0; i < state->height; i++) {
                        free(visited[i]);
                        free(previous[i]);
                    }
                    free(visited);
                    free(previous);
                    return false;
                }
            }
        }
    }
    queueFree(&q); // Zwolnienie pamięci w przypadku niepowodzenia
    // Zwolnienie pamięci tablic
    for (int i = 0; i < state->height; i++) {
        free(visited[i]);
        free(previous[i]);
    }
    free(visited);
    free(previous);
    return false;
}


// Funkja poruszajaca gracza do żądanej pozycji po iteracji BFS
bool move_player_to(Position target, GameState* state) {
    // Jeśli ruch nie jest legalny, zwróć false
    if (!is_valid_position(target.x, target.y, state) || (state->board[target.y][target.x] >= 'a' && state->board[target.y][target.x] <= 'z')) {
        return false;
    }
    // Jeśli nie, to zrób BFS
    Position *path = malloc((size_t)state->height * (size_t)state->width * sizeof(Position));

    if (!path) {
        perror("Błąd alokacji pamięci dla path");
        return false;
    }
    if (bfs_find_path(player_pos, target, path, state)) {
        for (int i = 0; path[i].x != target.x || path[i].y != target.y; i++) {
            clear_player_position(state); // Czyścimy pozycję gracza
            player_pos = path[i];
            // Zapisuje nową pozycję gracza
            state->board[player_pos.y][player_pos.x] = (state->board[player_pos.y][player_pos.x] == '+') ? '*' : '@';
        }
        free(path); // Zwolnienie pamięci
        return true;
    }
    free(path); // Zwolnienie pamięci w przypadku niepowodzenia
    return false;
}

bool push_box(Position box_pos, Position direction, char box_type, GameState* state) {

    Position new_box_pos = {box_pos.x + direction.x, box_pos.y + direction.y};
    Position player_target = {box_pos.x - direction.x, box_pos.y - direction.y};

    // Sprawdzam, czy nowe pole dla skrzynki jest prawidłowe
    char current_player_field = state->board[player_pos.y][player_pos.x];
    if (!is_valid_position(new_box_pos.x, new_box_pos.y, state) ||
        ((state->board[new_box_pos.y][new_box_pos.x] != '-' &&
          state->board[new_box_pos.y][new_box_pos.x] != '+' &&
          state->board[new_box_pos.y][new_box_pos.x] != current_player_field))) {
        return false;
    }
    // Sprawdź, czy mogę podejść do skrzynki
    if (!move_player_to(player_target, state)) {
        return false;
    }
    // Zaktualizuj obecne pole skrzynki
    if (state->board[box_pos.y][box_pos.x] == toupper(box_type)) {
        // Skrzynka była na celu
        state->board[box_pos.y][box_pos.x] = '+';
    } else if (state->board[box_pos.y][box_pos.x] == box_type) {
        // Skrzynka była na zwykłym polu
        state->board[box_pos.y][box_pos.x] = '-';
    }

    // Zaktualizuje nowe pole skrzynki
    if (state->board[new_box_pos.y][new_box_pos.x] == '+') {
        // Skrzynka wchodzi na cel
        state->board[new_box_pos.y][new_box_pos.x] = (char)toupper(box_type);
    } else if (state->board[new_box_pos.y][new_box_pos.x] == '-' || state->board[new_box_pos.y][new_box_pos.x] == box_type) {
        // Skrzynka wchodzi na zwykłe pole
        state->board[new_box_pos.y][new_box_pos.x] = box_type;
    }

    // Usuń symbole gracza z planszy, po iteracji BFS
    clear_player_position(state);

    // Przenieś gracza na pozycję skrzynki po wykonaniu ruchu
    player_pos = box_pos;
    state->board[player_pos.y][player_pos.x] = (state->board[player_pos.y][player_pos.x] == '+') ? '*' : '@';
    return true;
}


void execute_command(const char *command, GameState* state) {
    // Jeżeli trafimy na kropkę, kończymy wykonywanie funkcji
    if (strcmp(command, ".") == 0) {
        //printf("Znaleziono kropkę. Kończymy...\n");
        return;
    }
    // Jeśli wczytamy zero to cofamy ruch.
    else if (strcmp(command, "0") == 0) {
        if (!undo_move(state)) {
            //printf("Brak ruchu do cofnięcia.\n");
        }
    }
        // Jeśli wczytamy 1 to oznacza ze natrafilem na endline w pliku przyklad1.in -> drukuje plansze
    else if(strcmp(command, "1") == 0){
        display_board(state);
    }
        // wpp. wykonuje taki ruch jaki powinienem wykonac
    else if (strlen(command) == 2 && command[0] >= 'a' && command[0] <= 'z') {
        Position direction = {0, 0};
        switch (command[1]) {
            case '2': direction = (Position){0, 1}; break;
            case '8': direction = (Position){0, -1}; break;
            case '4': direction = (Position){-1, 0}; break;
            case '6': direction = (Position){1, 0}; break;
            default: printf("Invalid direction.\n"); return;
        }

        Position box_pos = {-1, -1};
        for (int y = 0; y < state->height; y++) {
            for (int x = 0; x < state->width; x++) {
                if (state->board[y][x] == command[0] || state->board[y][x] == toupper(command[0])) {
                    box_pos = (Position){x, y};
                }
            }
        }
        if (box_pos.x != -1) {
            if (push_box(box_pos, direction, command[0], state)) {
                save_current_board(state); // Zapisuje stan planszy po wykonaniu ruchu
            }
        }
    }
}


int main(int argc, char *argv[]) {
    const char *nazwaPliku = NULL;
    char *dataBuffer = NULL;

    // Sprawdzam, czy plik został podany jako argument
    if (argc > 1) {
        nazwaPliku = argv[1];
    } else if (!isatty(STDIN_FILENO)) {
        // Jeśli wejście jest przekierowane, wczytujemy dane do bufora
        size_t bufferSize = 1024;
        size_t dataSize = 0;
        size_t bytesRead;
        dataBuffer = malloc(bufferSize);
        if (!dataBuffer) {
            perror("Nie można zaalokować pamięci");
            return 1;
        }

        while ((bytesRead = fread(dataBuffer + dataSize, 1, bufferSize - dataSize, stdin)) > 0) {
            dataSize += bytesRead;
            if (dataSize == bufferSize) {
                bufferSize *= 2;
                char *newBuffer = realloc(dataBuffer, bufferSize);
                if (!newBuffer) {
                    perror("Nie można realokować pamięci");
                    free(dataBuffer);
                    return 1;
                }
                dataBuffer = newBuffer;
            }
        }
        dataBuffer[dataSize] = '\0'; // Dodaj kończący znak null
    } else {
        fprintf(stderr, "Błąd: Nie podano nazwy pliku wejściowego ani przekierowanego wejścia.\n");
        fprintf(stderr, "Użycie: %s <nazwa_pliku> lub ./test < przyklad1.in\n", argv[0]);
        return 1;
    }

    // Jeśli używam bufora w pamięci, przekaauje go do odpowiednich funkcji
    if (dataBuffer) {
        GameState state;
        policzZnakiZBufora(&state, dataBuffer); // Nowa funkcja, która działa na buforze
        if (!wczytajPlansze(dataBuffer, &state)) {
            free(dataBuffer);
            return 1;
        }
        find_player_position(&state);
        save_current_board(&state);
        display_board(&state);

        RuchyPliku wczytaneRuchy = wczytajRuchyZBufora(dataBuffer);
        Ruchy zapisaneRuchy;
        inicjalizujRuchy(&zapisaneRuchy, &wczytaneRuchy);
        przetwarzajRuchy(&wczytaneRuchy, &zapisaneRuchy);

        for (int i = 0; i < zapisaneRuchy.liczbaRuchow; i++) {
            execute_command(zapisaneRuchy.ruchy[i], &state);

            // Sprawdzam, czy w komendzie pojawiła się kropka na wypadek sytuacji np: w2p2. (kropka nie w noej linii)
            if (strcmp(zapisaneRuchy.ruchy[i], ".") == 0) {
                break; // Przerywam pętlę
            }
        }

        free(dataBuffer);
        //funkcje do valgrinda zwalniające pamięć
        zwolnijRuchy(&zapisaneRuchy);
        freeWczytaneRuchy(&wczytaneRuchy);
        free_snapshot_history(&state);
        free_board(&state);
    } else {
        // Jeśli podam nazwę pliku, działaj na pliku
        GameState state;
        policzZnakiZBufora(&state, nazwaPliku);
        if (!wczytajPlansze(nazwaPliku, &state)) {
            return 1;
        }
        find_player_position(&state);
        save_current_board(&state);
        display_board(&state);

        RuchyPliku wczytaneRuchy = wczytajRuchyZBufora(nazwaPliku);
        Ruchy zapisaneRuchy;
        inicjalizujRuchy(&zapisaneRuchy, &wczytaneRuchy);
        przetwarzajRuchy(&wczytaneRuchy, &zapisaneRuchy);

        for (int i = 0; i < zapisaneRuchy.liczbaRuchow; i++) {
            execute_command(zapisaneRuchy.ruchy[i], &state);

            // Sprawdzam, czy w komendzie pojawiła się kropka na wypadek sytuacji np: w2p2. (kropka nie w noej linii)
            if (strcmp(zapisaneRuchy.ruchy[i], ".") == 0) {
                break; // Przerywam pętlę
            }
        }
        //funkcje do valgrinda zwalniające pamięć
        zwolnijRuchy(&zapisaneRuchy);
        freeWczytaneRuchy(&wczytaneRuchy);
        free_snapshot_history(&state);
        free_board(&state);
    }

    return 0;
}

