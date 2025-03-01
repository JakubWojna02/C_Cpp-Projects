#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct {
    char *name;  // dynamiczna nazwa węzła
    int *edges;  // dynamiczna tablica krawędzi
    int edge_count;
    int edge_capacity;  // pojemność tablicy krawędzi
} Node;

typedef struct {
    Node *nodes;  // dynamiczna tablica węzłów
    int node_count;
    int node_capacity;  // pojemność tablicy węzłów
} Graph;

char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}

// inicjalizujemy graf
void init_graph(Graph *graph) {
    graph->node_count = 0;
    graph->node_capacity = 10;  // początkowa wielkość
    graph->nodes = malloc((size_t)graph->node_capacity * sizeof(Node));
}

// Inicjalizacja węzła
void init_node(Node *node, const char *name) {
    node->name = my_strdup(name); // Kopiowanie nazwy węzła
    node->edge_count = 0;
    node->edge_capacity = 10;
    node->edges = malloc((size_t)node->edge_capacity * sizeof(int));
    if (!node->edges) {
        fprintf(stderr, "Memory allocation failed for edges array.\n");
        exit(1);
    }
}

void free_graph(Graph *graph) {
    for (int i = 0; i < graph->node_count; i++) {
        free(graph->nodes[i].name);
        free(graph->nodes[i].edges);
    }
    free(graph->nodes);
}

// Funkcja porównująca węzły leksykograficznie
int compare_nodes(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

// Funkcja znajduje indeks węzła w grafie na podstawie jego nazwy
int find_node_index(Graph *graph, const char *name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Parsuje graf w języku DOT
void add_edge(Graph *graph, const char *from, const char *to) {
    int from_index = find_node_index(graph, from);
    if (from_index == -1) {
        if (graph->node_count == graph->node_capacity) {
            graph->node_capacity *= 2;
            graph->nodes = realloc(graph->nodes, (size_t)graph->node_capacity * sizeof(Node));
        }
        from_index = graph->node_count++;
        init_node(&graph->nodes[from_index], from);
    }

    int to_index = find_node_index(graph, to);
    if (to_index == -1) {
        if (graph->node_count == graph->node_capacity) {
            graph->node_capacity *= 2;
            graph->nodes = realloc(graph->nodes, (size_t)graph->node_capacity * sizeof(Node));
        }
        to_index = graph->node_count++;
        init_node(&graph->nodes[to_index], to);
    }

    Node *from_node = &graph->nodes[from_index];
    if (from_node->edge_count == from_node->edge_capacity) {
        from_node->edge_capacity *= 2;
        from_node->edges = realloc(from_node->edges, (size_t)from_node->edge_capacity * sizeof(int));
    }
    from_node->edges[from_node->edge_count++] = to_index;
}
// parsowanie
void parse_dot(Graph *graph, const char *input) {
    if (!input) {
        return;
    }

    const char *ptr = input;
    int braces_count = 0;

    size_t buffer_size = 256;
    char *from = calloc(buffer_size, sizeof(char));
    char *to = calloc(buffer_size, sizeof(char));
    if (!from || !to) {
        fprintf(stderr, "Memory allocation failed for parsing buffers.\n");
        exit(1);
    }

    while (*ptr) {
        // Pomijanie białych znaków
        if(isspace(*ptr)) {
            ptr++;
            continue;
        }

        // Ignorowanie słowa "digraph"
        if (strncmp(ptr, "digraph", 7) == 0) {
            //printf("Found 'digraph'. Skipping...\n");
            ptr += 7;
            continue;
        }

        // Obsługa nawiasów klamrowych
        if (*ptr == '{') {
            braces_count++;
            ptr++;
            continue;
        } else if (*ptr == '}') {
            braces_count--;
            ptr++;
            continue;
        }

        // Parsowanie krawędzi
        int parsed = sscanf(ptr, " %256[a-zA-Z0-9] -> %256[a-zA-Z0-9]", from, to);
        if (parsed == 2) {
            add_edge(graph, from, to);

            while (*ptr && *ptr != ';' && *ptr != '\n' && *ptr != ' ' && *ptr != '}') {
                ptr++;
            }

            // Pomijanie separatorów
            if (*ptr == ';' || *ptr == ' ') {
                ptr++;
            }
            // komntujacja przetwarzanie tej samej linii
            continue;
        }
        ptr++;
    }

    // Sprawdzenie, czy nawiasy są poprawnie zamknięte
    if (braces_count != 0) {
        fprintf(stderr, "Error: Mismatched braces in input.\n");
        exit(1);
    }

    free(from);
    free(to);
}


// BFS do obliczenia odległości
void bfs(Graph *graph, int start_index, int *distances) {
    int *queue = malloc((size_t)graph->node_count * sizeof(int));  // Dynamiczna tablica dla kolejki
    if (!queue) {
        fprintf(stderr, "Memory allocation failed for BFS queue.\n");
        exit(1);
    }

    int front = 0, back = 0;

    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = INT_MAX;
    }
    distances[start_index] = 0;
    queue[back++] = start_index;

    while (front < back) {
        int current = queue[front++];
        int current_distance = distances[current];

        for (int i = 0; i < graph->nodes[current].edge_count; i++) {
            int neighbor = graph->nodes[current].edges[i];
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = current_distance + 1;
                queue[back++] = neighbor;
            }
        }
    }
    free(queue);  // Zwalnianie pamięci kolejki po zakończeniu BFS
}

void print_result(Graph *graph, int *distances) {
    int max_distance = 0;
    for (int i = 0; i < graph->node_count; i++) {
        if (distances[i] != INT_MAX && distances[i] > max_distance) {
            max_distance = distances[i];
        }
    }

    // Alokacja tablicy wskaźników
    char **nodes = malloc((size_t)graph->node_count * sizeof(char*));  // Zmiana na node_count, valgrind
    if (!nodes) {
        fprintf(stderr, "Memory allocation failed for nodes array.\n");
        exit(1);
    }

    for (int d = 0; d <= max_distance; d++) {
        int count = 0;
        for (int i = 0; i < graph->node_count; i++) {
            if (distances[i] == d) {
                nodes[count++] = graph->nodes[i].name;
            }
        }

        if (count > 0) {
            qsort(nodes, (size_t)count, sizeof(char*), compare_nodes);
            for (int i = 0; i < count; i++) {
                printf("%s%s", nodes[i], (i == count - 1) ? "\n" : " ");
            }
        }
    }
    free(nodes);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <start_node>\n", argv[0]);
        return 1;
    }

    char *start_node = argv[1];

    // Inicjalizacja grafu
    Graph graph;
    init_graph(&graph);

    // Dynamiczne wczytanie danych wejściowych
    size_t buffer_size = 256;  // Początkowy rozmiar bufora
    size_t input_length = 0;
    char *input = malloc(buffer_size);
    if (!input) {
        fprintf(stderr, "Memory allocation failed for input buffer.\n");
        free_graph(&graph);
        return 1;
    }

    int word;
    while ((word = getchar()) != EOF) {
        if (input_length + 1 >= buffer_size) {
            buffer_size *= 2;
            input = realloc(input, buffer_size);
            if (!input) {
                fprintf(stderr, "Memory reallocation failed for input buffer.\n");
                free_graph(&graph);
                return 1;
            }
            // Inicjalizacja nowo zaalokowanej pamięci
            memset(input + input_length, 0, buffer_size - input_length);
        }
        input[input_length++] = (char)word;
    }
    input[input_length] = '\0';

    // Parsowanie grafu
    parse_dot(&graph, input);
    free(input);

    // Znajdowanie indeksu węzła początkowego
    int start_index = find_node_index(&graph, start_node);
    if (start_index == -1) {
        fprintf(stderr, "Start node not found in the graph.\n");
        free_graph(&graph);
        return 1;
    }

    // BFS i obliczenie odległości
    int *distances = malloc((size_t)graph.node_count * sizeof(int));
    if (!distances) {
        fprintf(stderr, "Memory allocation failed for distances array.\n");
        free_graph(&graph);
        return 1;
    }
    bfs(&graph, start_index, distances);

    // Drukowanie wyniku
    print_result(&graph, distances);

    // Zwalnianie pamięci
    free(distances);
    free_graph(&graph);

    return 0;
}
