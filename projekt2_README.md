

## Wprowadzenie

**Kostka Rubika** to łamigłówka, która składa się z ruchomych sześciennych bloków.

Ściany kostki dzielą się na kolorowe kwadraty, należące do poszczególnych bloków. W stanie ułożonym wszystkie kwadraty danej ściany pokryte są jednym kolorem, dla każdej ściany innym.

Blok należy do trzech prostopadłych warstw kostki. Bloki można przemieszczać, obracając warstwy o wielokrotność kąta prostego.

Celem układającego jest doprowadzenie losowo uporządkowanej kostki do stanu ułożonego.

Najczęściej używa się kostek rozmiaru 3 x 3 x 3, ale są też większe lub mniejsze.

## Polecenie

Napisz program, który wykonuje ciąg rozkazów obracających warstwy kostki rozmiaru N x N x N, gdzie N jest dodatnią wartością z zakresu typu int. Program zaczyna od kostki ułożonej. Na życzenie drukuje aktualny stan kostki.

Stałą symboliczną N, określającą rozmiar kostki, należy zdefiniować dyrektywami:

```c
#ifndef N
#define N 5
#endif
```

Wskazują one 5 jako wartość domyślną. Inną wartość stałej można wybrać podczas kompilacji programu za pomocą opcji `-DN=wartość`.

## Postać danych

Dane programu to ciąg rozkazów obrotu warstw i wydruku aktualnego stanu kostki, zakończony kropką.

Program ignoruje zawartość wejścia po kropce kończącej dane.

Rozkazem wydruku stanu kostki jest koniec wiersza.

Rozkaz obrotu warstw składa się z trzech części, które wskazują:
- liczbę warstw,
- ścianę kostki,
- kąt obrotu.

Jeśli część rozkazu, określająca liczbę warstw, jest pusta, to wskazuje liczbę 1. W przeciwnym przypadku jest pozycyjnym dziesiętnym zapisem dodatniej liczby warstw. Wartość tej liczby nie przekracza stałej N, definiującej rozmiar kostki.

Ściana jest określona literą:
- **u** - góra (ang. up),
- **l** - lewo (ang. left),
- **f** - przód (ang. front),
- **r** - prawo (ang. right),
- **b** - tył (ang. back),
- **d** - dół (ang. down).

Część rozkazu określająca kąt jest albo pusta albo jest apostrofem lub cudzysłowem. Pusta część wskazuje kąt 90 stopni, apostrof to -90 stopni, a cudzysłów to 180 stopni.

Wykonanie rozkazu obrotu, z liczbą warstw W, ścianą S, i kątem K, powoduje jednoczesne obrócenie W warstw, patrząc od strony ściany S, o kąt K, zgodnie z ruchem wskazówek zegara.

Składnię danych opisuje gramatyka z symbolem początkowym **Dane**:

```
Dane → CiągRozkazów Kropka
CiągRozkazów → ε | Rozkaz CiągRozkazów
Rozkaz → Obrót | Drukowanie
Obrót → LiczbaWarstw Strona Kąt
Drukowanie → KoniecWiersza
Strona → Litera
LiczbaWarstw → Jedna | Wiele
Jedna → ε
Wiele → Liczba
Liczba → Dodatnia | Liczba Cyfra
Kąt → Prosty | MinusProsty | Półpełny
Prosty → ε
MinusProsty → Apostrof
Półpełny → Cudzysłów
Litera → 'u' | 'l' | 'f' | 'r' | 'b' | 'd'
Dodatnia → '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
Cyfra → '0' | Dodatnia
Apostrof → '\''
Cudzysłów → '"'
KoniecWiersza → '\n'
Kropka → '.'
```

Symbole końcowe 'u', 'l', 'f', 'r', 'b', 'd', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '"', reprezentują znaki zapisane między apostrofami, '\'' to apostrof, a '\n' to koniec wiersza.

## Postać wyniku

Wynik programu jest efektem wykonania rozkazów drukowania aktualnego stanu kostki.

Wydruk stanu kostki składa się ze znaków 0, 1, 2, 3, 4, 5, symbolizujących kolory kwadratów na ścianach kostki, oraz ze spacji i kresek pionowych |.

Przyjmujemy, że w ułożonej kostce:
- kwadraty ściany górnej mają kolor 0,
- kwadraty ściany lewej mają kolor 1,
- kwadraty ściany przedniej mają kolor 2,
- kwadraty ściany prawej mają kolor 3,
- kwadraty ściany tylnej mają kolor 4,
- kwadraty ściany dolnej mają kolor 5.

Położenie ścian na wydruku stanu kostki jest zgodne ze schematem:

```
  u
l|f|r|b
  d
```

gdzie u, l, f, r, b, d to, odpowiednio, ściana górna, lewa, przednia, prawa, tylna i dolna.

Dla stałej N, definiującej rozmiar kostki, wydruk stanu kostki składa się z 3 * N + 1 wierszy:
- pierwszy wiersz jest pusty,
- N kolejnych wierszy opisuje ścianę górną,
- następnych N wierszy to opis ściany lewej, przedniej, prawej i tylnej,
- ostatnich N wierszy opisuje ścianę dolną.

Każdy wiersz opisu ściany górnej i dolnej zaczyna się od N + 1 spacji, po których jest N cyfr określających kolory kwadratów tej ściany.

Wiersze opisu ściany lewej, przedniej, prawej i tylnej mają kolejno:
- N cyfr określających kolory kwadratów na ścianie lewej,
- znak |,
- N cyfr określających kolory kwadratów na ścianie przedniej,
- znak |,
- N cyfr określających kolory kwadratów na ścianie prawej,
- znak |,
- N cyfr określających kolory kwadratów na ścianie tylnej.

Na wydruku stanu kostki, cyfry określające kolory kwadratów każdej ściany zajmują obszar rozmiaru N x N.

Dla ściany lewej, przedniej, prawej i tylnej, kolory kwadratów opisane są w kolejności, jaką zobaczylibyśmy po obrocie całej kostki o wielokrotność kąta prostego wokół osi przechodzącej przez ścianę górną i dolną.

Dla ściany górnej i dolnej kolejność jest taka, jaką zobaczylibyśmy, gdybyśmy obrócili kostkę o wielokrotność kąta prostego wokół osi przechodzącej przez ścianę lewą i prawą.

## Przykłady

Do treści zadania dołączone są pliki `.in` z przykładowymi danymi i pliki `.out` z wynikami wzorcowymi.

Przykłady zakładają, że stała N, definiująca rozmiar kostki, ma wartość 5.

Dla danych `przyklad1.in` poprawny wynik to `przyklad1.out`.
Dla danych `przyklad2.in` poprawny wynik to `przyklad2.out`.
Dla danych `przyklad3.in` poprawny wynik to `przyklad3.out`.

## Walidacja i testy

Rozwiązania podlegają walidacji, wstępnie badającej zgodność ze specyfikacją.

Walidacja sprawdza działanie programu na przykładach dołączonych do treści zadania.

Pomyślne przejście walidacji jest warunkiem dopuszczenia programu do testów poprawności.
