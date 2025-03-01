

---

## Wprowadzenie

Powiemy, że w grafie skierowanym węzeł **b** jest osiągalny z węzła **a**, jeśli:
- **a** i **b** są tym samym węzłem lub
- istnieje krawędź z węzła **a** do węzła **c** i węzeł **b** jest osiągalny z węzła **c**.

Jeśli węzeł **b** jest osiągalny z węzła **a**, to odległość węzła **b** od węzła **a** jest równa:
- 0, gdy **a** i **b** są tym samym węzłem;
- 1 + **M**, gdy **a** i **b** nie są tym samym węzłem, a **M** to minimum z odległości węzła **b** od węzłów, do których prowadzi krawędź z węzła **a** i z których węzeł **b** jest osiągalny.

## Polecenie

Napisz program, który czyta opis grafu skierowanego **G**, w podzbiorze języka DOT. Program dostaje jako argument nazwę węzła **w** tego grafu.

Program pisze nazwy węzłów osiągalnych w grafie **G** z węzła **w**. Porządkuje je niemalejąco po odległości węzłów od węzła **w**. Nazwy węzłów, których odległości od **w** są takie same, porządkuje leksykograficznie.

## Postać danych

Język danych jest opisany gramatyką w rozszerzonej notacji BNF:

```
<graf> ::= DIGRAPH LEWY { ID STRZALKA ID } PRAWY
```

Symbolami końcowymi gramatyki są:
- **DIGRAPH**: ciąg liter opisany wyrażeniem regularnym `[Dd][Ii][Gg][Rr][Aa][Pp][Hh]`, gdzie `[Dd]` oznacza małą lub wielką literę d itd.;
- **LEWY**: znak `{`;
- **PRAWY**: znak `}`;
- **STRZALKA**: ciąg znaków `->`;
- **ID**: ciąg wielkich lub małych liter i cyfr, zaczynający się od litery, który nie jest żadnej z postaci `[Dd][Ii][Gg][Rr][Aa][Pp][Hh]`, `[Ee][Dd][Gg][Ee]`, `[Gg][Rr][Aa][Pp][Hh]`, `[Nn][Oo][Dd][Ee]`, `[Ss][Tt][Rr][Ii][Cc][Tt]`, `[Ss][Uu][Bb][Gg][Rr][Aa][Pp][Hh]` i po którym w danych występuje znak inny niż litera lub cyfra.

W danych, przed i po symbolach końcowych, mogą wystąpić, w dowolnej liczbie, spacje i końce wiersza.

Symbol **ID** reprezentuje nazwę węzła.

Zapis `ID1 -> ID2` znaczy, że w grafie jest krawędź z węzła **ID1** do węzła **ID2**.

## Postać wyniku

Wynikiem programu, wywołanego z argumentem **w**, jest ciąg niepustych wierszy, numerowanych od 1. W i-tym wierszu są nazwy węzłów, osiągalnych z węzła **w**, których odległość od tego węzła jest równa **i - 1**. W każdym wierszu nazwy węzłów są uporządkowane leksykograficznie rosnąco. Między każdą parą nazw sąsiadujących w wierszu jest jedna spacja.

## Przykłady

Do treści zadania dołączone są pliki `.in` z przykładowymi danymi i pliki `.out` z wynikami wzorcowymi.

W każdym z poniższych przykładów argumentem programu jest napis **start**.

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
valgrind --leak-check=full -q --error-exitcode=1 ./nazwa argument
```

Jeśli Valgrind wykryje błąd, to nawet gdyby wynik był prawidłowy, uznajemy, że program testu nie przeszedł.

Opcja `-q` powoduje, że jedynymi informacjami, wypisywanymi przez program Valgrind, są komunikaty o błędach. Opcja `--leak-check=full` wskazuje Valgrindowi, że powinien, między innymi, szukać wycieków pamięci. Opcja `--error-exitcode=1` określa kod wyjścia programu w przypadku, gdy Valgrind wykryje błąd.

Przyjmujemy, że niezerowy wynik funkcji `main()` informuje o błędzie wykonania programu. Poprawność wyniku sprawdzamy, przekierowując na wejście programu zawartość pliku `.in` i porównując rezultat, za pomocą programu `diff`, z plikiem `.out`, np.:

```sh
< przyklad.in ./nazwa argument | diff - przyklad.out
```

Ocena poprawności wyniku jest binarna. Wynik uznajemy za poprawny, jeżeli program `diff` nie
