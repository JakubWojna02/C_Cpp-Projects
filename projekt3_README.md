Oczywiście! Oto przepisany tekst, który możesz umieścić w pliku README na GitHubie:

---

## Wprowadzenie

**Sokoban** jest jednoosobową grą logiczną rozgrywaną na dwuwymiarowej planszy o kwadratowych polach.

Niektóre pola planszy są wolne, na innych są ściany lub skrzynie. Pewna liczba pól jest oznaczona jako pola docelowe. Polem docelowym może być pole wolne lub pole, na którym jest skrzynia.

Na jednym z pól planszy jest postać sterowana przez gracza. Może się ona przesuwać na pola sąsiadujące z aktualnym w pionie lub poziomie.

Za sąsiadujące z polem w wierszu w i kolumnie k uznajemy pola, które są w:
- wierszu w - 1, kolumnie k;
- wierszu w + 1, kolumnie k;
- wierszu w, kolumnie k - 1;
- wierszu w, kolumnie k + 1.

Postać może się przesunąć na pole, jeśli jest ono wolne lub jest na nim skrzynia, którą postać może pchnąć. Pchnięcie skrzyni jest możliwe, jeśli bezpośrednio za nią, w kierunku ruchu postaci, jest pole wolne. Nie jest możliwe przesunięcie postaci lub pchnięcie skrzyni poza planszę. Nie jest możliwe pchnięcie na raz więcej niż jednej skrzyni.

Celem gry jest umieszczenie skrzyń na polach docelowych.

## Polecenie

Napisz program umożliwiający grę w Sokobana.

Program czyta opis stanu początkowego planszy, a następnie czyta i wykonuje kolejne rozkazy. Rozpoznawane są rozkazy wydruku aktualnego stanu planszy, pchnięcia skrzyni i cofnięcia wykonanego wcześniej pchnięcia.

Inaczej niż w typowych implementacjach Sokobana, użytkownik nie musi podawać ruchów przesuwających postać po wolnych polach. Program sam ustala, jak doprowadzić postać na pole, z którego będzie możliwe pchnięcie skrzyni we wskazanym kierunku.

## Postać danych

Na wejściu programu jest opis stanu początkowego planszy i niepusty ciąg rozkazów, zakończony kropką. Pierwszym rozkazem jest rozkaz wydruku stanu planszy. Program ignoruje zawartość wejścia po kropce kończącej dane.

Opis planszy składa się z niepustych wierszy, w których są jednoznakowe reprezentacje stanu pól:
- **-** wolne pole, które nie jest polem docelowym;
- **+** wolne pole, które jest polem docelowym;
- **#** ściana;
- **@** wolne pole, nie będące polem docelowym, na którym jest postać;
- **\*** wolne pole docelowe, na którym jest postać;
- **[a .. z]** (mała litera) pole, które nie jest polem docelowym, na którym jest skrzynia o podanej nazwie;
- **[A .. Z]** (wielka litera) pole docelowe, na którym jest skrzynia o nazwie będącej małą literą odpowiadającą podanej wielkiej literze.

W poprawnym opisie planszy jest dokładnie jedna postać. Każda skrzynia, oznaczona literą alfabetu łacińskiego, może wystąpić tylko raz.

Program rozpoznaje rozkazy:
- **koniec wiersza**: Wydruk aktualnego stanu planszy.
- **[a .. z][2 | 4 | 6 | 8]** (mała litera, po której jest cyfra 2, 4, 6 lub 8): Pchnięcie skrzyni o nazwie, będącej pierwszym znakiem rozkazu, w kierunku określonym drugim znakiem. Cyfra 2 oznacza pchnięcie w dół, 8 w górę, 4 w lewo, a 6 w prawo. Na pole, z którego można wykonać pchnięcie, postać doprowadzana jest ścieżką składającą się z wolnych pól. Nie może być na niej ściany ani skrzyni. Jeśli skuteczne wykonanie pchnięcia nie jest możliwe, bo postać nie może podejść do skrzyni lub skrzyni nie da się pchnąć, stan planszy nie zmienia się.
- **0**: Cofnięcie ostatniego skutecznie wykonanego i jeszcze nie cofniętego pchnięcia. Postać wraca na pole, na którym była przed cofanym pchnięciem. Jeśli nie było żadnego pchnięcia, które można cofnąć, rozkaz nie zmienia stanu planszy.

## Postać wyniku

Wynik programu jest efektem wykonania rozkazów drukowania aktualnego stanu planszy. Opis stanu planszy w wyniku programu ma postać taką, jak w danych.

## Przykłady

Do treści zadania dołączone są pliki `.in` z przykładowymi danymi i pliki `.out` z wynikami wzorcowymi.

Dla danych `przyklad1.in` poprawny wynik to `przyklad1.out`.
Dla danych `przyklad2.in` poprawny wynik to `przyklad2.out`.
Dla danych `przyklad3.in` poprawny wynik to `przyklad3.out`.

## Walidacja i testy

Rozwiązania podlegają walidacji, wstępnie badającej zgodność ze specyfikacją. Walidacja sprawdza działanie programu na przykładach dołączonych do treści zadania. Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności. Program, który walidacji nie przejdzie, dostaje zerową ocenę poprawności.

Walidacja i testy są prowadzone na komputerze `students`.

Programy są kompilowane poleceniem:

```sh
gcc @opcje nazwa.c -o nazwa
```

gdzie `nazwa.c` to nazwa pliku z kodem źródłowym, a plik `opcje` ma zawartość:

```sh
-std=c17
-pedantic
-Wall
-Wextra
-Wformat-security
-Wduplicated-cond
-Wfloat-equal
-Wshadow
-Wconversion
-Wjump-misses-init
-Wlogical-not-parentheses
-Wnull-dereference
-Wvla
-Werror
-fstack-protector-strong
-fsanitize=undefined
-fno-sanitize-recover
-g
-fno-omit-frame-pointer
-O1
```

Opcje `-std=c17`, `-pedantic` wskazują, że kompilator ma dbać o zgodność kodu z aktualnym standardem języka C. Dzięki opcjom `-Wall`, `-Wextra` kompilator zgłosi zauważone usterki. Opcje `-Wformat-security`, `-Wduplicated-cond`, `-Wfloat-equal`, `-Wshadow`, `-Wconversion`, `-Wjump-misses-init`, `-Wlogical-not-parentheses`, `-Wnull-dereference` umożliwiają wykrywanie dodatkowych usterek. Opcja `-Wvla` sprawia, że użycie tablic zmiennej długości jest uznawane za usterkę. Opcja `-Werror` wskazuje, że kompilator ma uznać usterki za błędy.

Dzięki opcji `-fstack-protector-strong`, podczas wykonania programu zostaną wykryte niektóre błędne odwołania do pamięci na stosie. Opcje `-fsanitize=undefined`, `-fno-sanitize-recover` umożliwiają wykrywanie operacji, które mają efekt nieokreślony. Opcje `-g`, `-fno-omit-frame-pointer` poprawiają jakość komunikatów o błędach wykonania. Opcja `-O1` włącza optymalizacje, co zwiększa prawdopodobieństwo ujawnienia się błędów.

Wymagane są wszystkie wymienione opcje kompilatora. Nie będą do nich dodawane żadne inne.

Zwracamy uwagę, że poszczególne wersje kompilatora gcc mogą się różnić sposobem obsługi tych samych opcji. Przed wysłaniem rozwiązania warto więc skompilować je i przetestować na `students` w sposób opisany powyżej.

Podczas walidacji i testów, program `nazwa` jest uruchamiany pod kontrolą programu Valgrind poleceniem:

```sh
valgrind --leak-check=full -q --error-exitcode=1 ./nazwa
```

Jeśli Valgrind wykryje błąd, to nawet gdyby wynik był prawidłowy, uznajemy,
