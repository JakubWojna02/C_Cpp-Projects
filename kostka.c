#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifndef N
#define N 5
#endif
// Wypełniam kostkę bazowo liczbami wg. wzoru
void fill_face(int face[N][N], int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            face[i][j] = value;
        }
    }
}
// Funkcja drukująca stan kostki po obrocie
void print(int u[N][N], int l[N][N], int f[N][N], int r[N][N], int b[N][N], int d[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("      ");
        for (int j = 0; j < N; j++) printf("%d", u[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d", l[i][j]);
        printf("|");
        for (int j = 0; j < N; j++) printf("%d", f[i][j]);
        printf("|");
        for (int j = 0; j < N; j++) printf("%d", r[i][j]);
        printf("|");
        for (int j = 0; j < N; j++) printf("%d", b[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        printf("      ");
        for (int j = 0; j < N; j++) printf("%d", d[i][j]);
        printf("\n");
    }
    printf("\n");
}
// Obrót o 90 stopni w prawo
void rotate_face_90(int face[N][N]) {
    int temp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[j][N - 1 - i] = face[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            face[i][j] = temp[i][j];
}
// Funkcja obracająca kostkę
void rotate_cube(int u[N][N], int l[N][N], int f[N][N], int r[N][N], int b[N][N], int d[N][N], int layers, char face, char angle) {
    int rotations = (angle == '\'') ? 3 : (angle == '\"') ? 2 : 1;

    while (rotations--) {
        int temp[N];
        switch (face) {
            case 'f':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = u[N - 1 - j][i];
                    for (int i = 0; i < N; i++) u[N - 1 - j][i] = l[N - 1 - i][N - 1 - j];
                    for (int i = 0; i < N; i++) l[N - 1 - i][N - 1 - j] = d[j][i];
                    for (int i = 0; i < N; i++) d[j][i] = r[i][j];
                    for (int i = 0; i < N; i++) r[i][j] = temp[i];
                }
                rotate_face_90(f);
                break;

            case 'b':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = u[j][N - 1 - i];
                    for (int i = 0; i < N; i++) u[j][N - 1 - i] = r[i][N - 1 - j];
                    for (int i = 0; i < N; i++) r[i][N - 1 - j] = d[N - 1 - j][i];
                    for (int i = 0; i < N; i++) d[N - 1 - j][i] = l[N - 1 - i][j];
                    for (int i = 0; i < N; i++) l[N - 1 - i][j] = temp[i];
                }
                rotate_face_90(b);
                break;

            case 'u':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = f[j][i];
                    for (int i = 0; i < N; i++) f[j][i] = r[j][i];
                    for (int i = 0; i < N; i++) r[j][i] = b[j][i];
                    for (int i = 0; i < N; i++) b[j][i] = l[j][i];
                    for (int i = 0; i < N; i++) l[j][i] = temp[i];
                }
                rotate_face_90(u);
                break;

            case 'd':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = f[N - 1 - j][i];
                    for (int i = 0; i < N; i++) f[N - 1 - j][i] = l[N - 1 - j][i];
                    for (int i = 0; i < N; i++) l[N - 1 - j][i] = b[N - 1 - j][i];
                    for (int i = 0; i < N; i++) b[N - 1 - j][i] = r[N - 1 - j][i];
                    for (int i = 0; i < N; i++) r[N - 1 - j][i] = temp[i];
                }
                rotate_face_90(d);
                break;

            case 'r':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = u[i][N - 1 - j];
                    for (int i = 0; i < N; i++) u[i][N - 1 - j] = f[i][N - 1 - j];
                    for (int i = 0; i < N; i++) f[i][N - 1 - j] = d[i][N - 1 - j];
                    for (int i = 0; i < N; i++) d[i][N - 1 - j] = b[N - 1 - i][j];
                    for (int i = 0; i < N; i++) b[N - 1 - i][j] = temp[i];
                }
                rotate_face_90(r);
                break;

            case 'l':
                for (int j = 0; j < layers; j++) {
                    for (int i = 0; i < N; i++) temp[i] = u[i][j];
                    for (int i = 0; i < N; i++) u[i][j] = b[N - 1 - i][N - 1 - j];
                    for (int i = 0; i < N; i++) b[N - 1 - i][N - 1 - j] = d[i][j];
                    for (int i = 0; i < N; i++) d[i][j] = f[i][j];
                    for (int i = 0; i < N; i++) f[i][j] = temp[i];
                }
                rotate_face_90(l);
                break;
        }
    }
}
// Funkcja inicjalizująca kostkę oraz wczytująca z pliku odpowiednie paramatery
void parse_and_execute(FILE *input) {
    int u[N][N], l[N][N], f[N][N], r[N][N], b[N][N], d[N][N];
    fill_face(u, 0);
    fill_face(l, 1);
    fill_face(f, 2);
    fill_face(r, 3);
    fill_face(b, 4);
    fill_face(d, 5);

    int ch;  // Zmieniamy na typ int, aby pomieścić wynik fgetc()
    int layers = 1;

    while ((ch = fgetc(input)) != EOF) {
        if (ch == '.') break;

        if (isdigit(ch)) {
            layers = ch - '0';
        } else if (strchr("ulfrbd", ch)) {
            int angle = fgetc(input);
            if (angle != '\'' && angle != '"') {
                ungetc(angle, input);
                angle = ' ';
            }
            rotate_cube(u, l, f, r, b, d, layers, (char)ch, (char)angle);
            layers = 1; // Reset warstw do domyślnej wartości
        } else if (ch == '\n') {
            // Drukuje stan kostki tylko po zakończeniu bieżącej linii
            print(u, l, f, r, b, d);
        }
    }
}

int main(void) {

    FILE *input = fopen("przyklad3.in", "r");
    if (!input) {
        fprintf(stderr, "Błąd otwarcia pliku.\n");
        return 1;
    }

    parse_and_execute(input);
    fclose(input);

    return 0;
}
