#include <stdio.h>
#include <stdbool.h>

#define MAX_CARDS 81
// Funkcja potęgująca liczby
int power(int n, int i) {
    int result = 1;
    if (i == 0)
        return 1;
    // Zakladam od tego miejsca, ze moja petla jest poprawna, tj. eksponent jest dodatni
    for (int j = 0; j < i; j++)
        result *= n;

    return result;
}

bool all_same(int a, int b, int c) {
    return a == b && b == c;
}

bool all_different(int a, int b, int c) {
    return (a != b) && (b != c) && (a != c);
}

bool is_set(int card1, int card2, int card3) {
    for (int i = 3; i >= 0; i--) {
        int a = (card1 / power(10, i)) % 10;
        int b = (card2 / power(10, i)) % 10;
        int c = (card3 / power(10, i)) % 10;

        if (!(all_same(a, b, c) || all_different(a, b, c))) {
            return false;
        }
    }
    return true;
}

// Funkcja drukująca stan stołu
void print_table(FILE *output, int *cards, int table_start, int table_size) {
    fprintf(output, "=");
    for (int i = 0; i < table_size; i++) {
        fprintf(output, " %d", cards[table_start + i]);
    }
    fprintf(output, "\n");
}

// Funkcja obsługująca znaleziony set
void handle_set(FILE *output, int *cards, int *table_size, int *deck_start, int card_count, int table_start, int i, int j, int k) {
    fprintf(output, "- %d %d %d\n", cards[table_start + i], cards[table_start + j], cards[table_start + k]);

    // Usuwanie seta
    for (int x = k; x < *table_size - 1; x++) {
        cards[table_start + x] = cards[table_start + x + 1];
    }
    (*table_size)--;

    for (int x = j; x < *table_size - 1; x++) {
        cards[table_start + x] = cards[table_start + x + 1];
    }
    (*table_size)--;

    for (int x = i; x < *table_size - 1; x++) {
        cards[table_start + x] = cards[table_start + x + 1];
    }
    (*table_size)--;

    // Uzupełnianie kartami z talii
    while (*table_size < 12 && *deck_start < card_count) {
        cards[table_start + *table_size] = cards[*deck_start];
        (*deck_start)++;
        (*table_size)++;
    }
}

// Funkcja szukająca seta na stole
bool find_set(int *cards, int *table_size, int *deck_start, int card_count, int table_start, FILE *output) {
    for (int i = 0; i < *table_size - 2; i++) {
        for (int j = i + 1; j < *table_size - 1; j++) {
            for (int k = j + 1; k < *table_size; k++) {
                if (is_set(cards[table_start + i], cards[table_start + j], cards[table_start + k])) {
                    handle_set(output, cards, table_size, deck_start, card_count, table_start, i, j, k);
                    return true;
                }
            }
        }
    }
    return false;
}

// Funkcja dodająca 3 nowe karty do stołu, jeśli brak seta
void add_cards_to_table(int *cards, int *table_size, int *deck_start, int card_count, int table_start, FILE *output) {
    fprintf(output, "+\n");
    for (int i = 0; i < 3 && *deck_start < card_count; i++) {
        cards[table_start + *table_size] = cards[*deck_start];
        (*deck_start)++;
        (*table_size)++;
    }
}

// Główna funkcja symulująca grę
void play_set(int *cards, int card_count, FILE *output) {
    int table_start = 0;
    int table_size = card_count < 12 ? card_count : 12;
    int deck_start = table_size;

    print_table(output, cards, table_start, table_size);

    while (true) {
        bool found_set = find_set(cards, &table_size, &deck_start, card_count, table_start, output);

        if (!found_set) {
            if (deck_start >= card_count) {
                break; // Koniec gry
            } else {
                add_cards_to_table(cards, &table_size, &deck_start, card_count, table_start, output);
            }
        }

        print_table(output, cards, table_start, table_size);
    }
}

int main() {
    int cards[MAX_CARDS];
    int card_count = 0;

    // Odczyt danych z wejścia standardowego
    while (card_count < MAX_CARDS && scanf("%d", &cards[card_count]) == 1) {
        card_count++;
    }

    // Symulacja gry
    play_set(cards, card_count, stdout);

    return 0;
}
