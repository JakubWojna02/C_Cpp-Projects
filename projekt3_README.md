{\rtf1\ansi\ansicpg1250\cocoartf2821
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\froman\fcharset0 Times-Roman;\f1\froman\fcharset0 Times-Bold;\f2\fmodern\fcharset0 Courier;
}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red109\green109\blue109;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;\cssrgb\c50196\c50196\c50196;}
{\*\listtable{\list\listtemplateid1\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid1\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid1}
{\list\listtemplateid2\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid101\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid2}
{\list\listtemplateid3\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid201\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid3}}
{\*\listoverridetable{\listoverride\listid1\listoverridecount0\ls1}{\listoverride\listid2\listoverridecount0\ls2}{\listoverride\listid3\listoverridecount0\ls3}}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sa280\partightenfactor0

\f0\fs28 \cf0 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 Oczywi\uc0\u347 cie! Oto przepisany tekst, kt\'f3ry mo\u380 esz umie\u347 ci\u263  w pliku README na GitHubie:\
\pard\pardeftab720\partightenfactor0
\cf3 \strokec3 \
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 \strokec2 Wprowadzenie\
\pard\pardeftab720\sa280\partightenfactor0

\fs28 \cf0 Sokoban
\f0\b0  jest jednoosobow\uc0\u261  gr\u261  logiczn\u261  rozgrywan\u261  na dwuwymiarowej planszy o kwadratowych polach.\
Niekt\'f3re pola planszy s\uc0\u261  wolne, na innych s\u261  \u347 ciany lub skrzynie. Pewna liczba p\'f3l jest oznaczona jako pola docelowe. Polem docelowym mo\u380 e by\u263  pole wolne lub pole, na kt\'f3rym jest skrzynia.\
Na jednym z p\'f3l planszy jest posta\uc0\u263  sterowana przez gracza. Mo\u380 e si\u281  ona przesuwa\u263  na pola s\u261 siaduj\u261 ce z aktualnym w pionie lub poziomie.\
Za s\uc0\u261 siaduj\u261 ce z polem w wierszu w i kolumnie k uznajemy pola, kt\'f3re s\u261  w:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls1\ilvl0\cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 wierszu w - 1, kolumnie k;\
\ls1\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 wierszu w + 1, kolumnie k;\
\ls1\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 wierszu w, kolumnie k - 1;\
\ls1\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 wierszu w, kolumnie k + 1.\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Posta\uc0\u263  mo\u380 e si\u281  przesun\u261 \u263  na pole, je\u347 li jest ono wolne lub jest na nim skrzynia, kt\'f3r\u261  posta\u263  mo\u380 e pchn\u261 \u263 . Pchni\u281 cie skrzyni jest mo\u380 liwe, je\u347 li bezpo\u347 rednio za ni\u261 , w kierunku ruchu postaci, jest pole wolne. Nie jest mo\u380 liwe przesuni\u281 cie postaci lub pchni\u281 cie skrzyni poza plansz\u281 . Nie jest mo\u380 liwe pchni\u281 cie na raz wi\u281 cej ni\u380  jednej skrzyni.\
Celem gry jest umieszczenie skrzy\uc0\u324  na polach docelowych.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Polecenie\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Napisz program umo\uc0\u380 liwiaj\u261 cy gr\u281  w Sokobana.\
Program czyta opis stanu pocz\uc0\u261 tkowego planszy, a nast\u281 pnie czyta i wykonuje kolejne rozkazy. Rozpoznawane s\u261  rozkazy wydruku aktualnego stanu planszy, pchni\u281 cia skrzyni i cofni\u281 cia wykonanego wcze\u347 niej pchni\u281 cia.\
Inaczej ni\uc0\u380  w typowych implementacjach Sokobana, u\u380 ytkownik nie musi podawa\u263  ruch\'f3w przesuwaj\u261 cych posta\u263  po wolnych polach. Program sam ustala, jak doprowadzi\u263  posta\u263  na pole, z kt\'f3rego b\u281 dzie mo\u380 liwe pchni\u281 cie skrzyni we wskazanym kierunku.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Posta\uc0\u263  danych\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Na wej\uc0\u347 ciu programu jest opis stanu pocz\u261 tkowego planszy i niepusty ci\u261 g rozkaz\'f3w, zako\u324 czony kropk\u261 . Pierwszym rozkazem jest rozkaz wydruku stanu planszy. Program ignoruje zawarto\u347 \u263  wej\u347 cia po kropce ko\u324 cz\u261 cej dane.\
Opis planszy sk\uc0\u322 ada si\u281  z niepustych wierszy, w kt\'f3rych s\u261  jednoznakowe reprezentacje stanu p\'f3l:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls2\ilvl0
\f1\b \cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 -
\f0\b0  wolne pole, kt\'f3re nie jest polem docelowym;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 +
\f0\b0  wolne pole, kt\'f3re jest polem docelowym;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #
\f0\b0  \uc0\u347 ciana;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 @
\f0\b0  wolne pole, nie b\uc0\u281 d\u261 ce polem docelowym, na kt\'f3rym jest posta\u263 ;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 *
\f0\b0  wolne pole docelowe, na kt\'f3rym jest posta\uc0\u263 ;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 [a .. z]
\f0\b0  (ma\uc0\u322 a litera) pole, kt\'f3re nie jest polem docelowym, na kt\'f3rym jest skrzynia o podanej nazwie;\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 [A .. Z]
\f0\b0  (wielka litera) pole docelowe, na kt\'f3rym jest skrzynia o nazwie b\uc0\u281 d\u261 cej ma\u322 \u261  liter\u261  odpowiadaj\u261 c\u261  podanej wielkiej literze.\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 W poprawnym opisie planszy jest dok\uc0\u322 adnie jedna posta\u263 . Ka\u380 da skrzynia, oznaczona liter\u261  alfabetu \u322 aci\u324 skiego, mo\u380 e wyst\u261 pi\u263  tylko raz.\
Program rozpoznaje rozkazy:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls3\ilvl0
\f1\b \cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 koniec wiersza
\f0\b0 : Wydruk aktualnego stanu planszy.\
\ls3\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 [a .. z][2 | 4 | 6 | 8]
\f0\b0  (ma\uc0\u322 a litera, po kt\'f3rej jest cyfra 2, 4, 6 lub 8): Pchni\u281 cie skrzyni o nazwie, b\u281 d\u261 cej pierwszym znakiem rozkazu, w kierunku okre\u347 lonym drugim znakiem. Cyfra 2 oznacza pchni\u281 cie w d\'f3\u322 , 8 w g\'f3r\u281 , 4 w lewo, a 6 w prawo. Na pole, z kt\'f3rego mo\u380 na wykona\u263  pchni\u281 cie, posta\u263  doprowadzana jest \u347 cie\u380 k\u261  sk\u322 adaj\u261 c\u261  si\u281  z wolnych p\'f3l. Nie mo\u380 e by\u263  na niej \u347 ciany ani skrzyni. Je\u347 li skuteczne wykonanie pchni\u281 cia nie jest mo\u380 liwe, bo posta\u263  nie mo\u380 e podej\u347 \u263  do skrzyni lub skrzyni nie da si\u281  pchn\u261 \u263 , stan planszy nie zmienia si\u281 .\
\ls3\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 0
\f0\b0 : Cofni\uc0\u281 cie ostatniego skutecznie wykonanego i jeszcze nie cofni\u281 tego pchni\u281 cia. Posta\u263  wraca na pole, na kt\'f3rym by\u322 a przed cofanym pchni\u281 ciem. Je\u347 li nie by\u322 o \u380 adnego pchni\u281 cia, kt\'f3re mo\u380 na cofn\u261 \u263 , rozkaz nie zmienia stanu planszy.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Posta\uc0\u263  wyniku\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Wynik programu jest efektem wykonania rozkaz\'f3w drukowania aktualnego stanu planszy. Opis stanu planszy w wyniku programu ma posta\uc0\u263  tak\u261 , jak w danych.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Przyk\uc0\u322 ady\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Do tre\uc0\u347 ci zadania do\u322 \u261 czone s\u261  pliki 
\f2 .in
\f0  z przyk\uc0\u322 adowymi danymi i pliki 
\f2 .out
\f0  z wynikami wzorcowymi.\
Dla danych 
\f2 przyklad1.in
\f0  poprawny wynik to 
\f2 przyklad1.out
\f0 . Dla danych 
\f2 przyklad2.in
\f0  poprawny wynik to 
\f2 przyklad2.out
\f0 . Dla danych 
\f2 przyklad3.in
\f0  poprawny wynik to 
\f2 przyklad3.out
\f0 .\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Walidacja i testy\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Rozwi\uc0\u261 zania podlegaj\u261  walidacji, wst\u281 pnie badaj\u261 cej zgodno\u347 \u263  ze specyfikacj\u261 . Walidacja sprawdza dzia\u322 anie programu na przyk\u322 adach do\u322 \u261 czonych do tre\u347 ci zadania. Pomy\u347 lne przej\u347 cie walidacji jest warunkiem dopuszczenia programu do test\'f3w poprawno\u347 ci. Program, kt\'f3ry walidacji nie przejdzie, dostaje zerow\u261  ocen\u281  poprawno\u347 ci.\
Walidacja i testy s\uc0\u261  prowadzone na komputerze 
\f2 students
\f0 .\
Programy s\uc0\u261  kompilowane poleceniem:\
\pard\pardeftab720\partightenfactor0

\f2 \cf0 gcc @opcje nazwa.c -o nazwa\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 gdzie 
\f2 nazwa.c
\f0  to nazwa pliku z kodem \uc0\u378 r\'f3d\u322 owym, a plik 
\f2 opcje
\f0  ma zawarto\uc0\u347 \u263 :\
\pard\pardeftab720\partightenfactor0

\f2 \cf0 -std=c17\
-pedantic\
-Wall\
-Wextra\
-Wformat-security\
-Wduplicated-cond\
-Wfloat-equal\
-Wshadow\
-Wconversion\
-Wjump-misses-init\
-Wlogical-not-parentheses\
-Wnull-dereference\
-Wvla\
-Werror\
-fstack-protector-strong\
-fsanitize=undefined\
-fno-sanitize-recover\
-g\
-fno-omit-frame-pointer\
-O1\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 Opcje 
\f2 -std=c17
\f0 , 
\f2 -pedantic
\f0  wskazuj\uc0\u261 , \u380 e kompilator ma dba\u263  o zgodno\u347 \u263  kodu z aktualnym standardem j\u281 zyka C. Dzi\u281 ki opcjom 
\f2 -Wall
\f0 , 
\f2 -Wextra
\f0  kompilator zg\uc0\u322 osi zauwa\u380 one usterki. Opcje 
\f2 -Wformat-security
\f0 , 
\f2 -Wduplicated-cond
\f0 , 
\f2 -Wfloat-equal
\f0 , 
\f2 -Wshadow
\f0 , 
\f2 -Wconversion
\f0 , 
\f2 -Wjump-misses-init
\f0 , 
\f2 -Wlogical-not-parentheses
\f0 , 
\f2 -Wnull-dereference
\f0  umo\uc0\u380 liwiaj\u261  wykrywanie dodatkowych usterek. Opcja 
\f2 -Wvla
\f0  sprawia, \uc0\u380 e u\u380 ycie tablic zmiennej d\u322 ugo\u347 ci jest uznawane za usterk\u281 . Opcja 
\f2 -Werror
\f0 wskazuje, \uc0\u380 e kompilator ma uzna\u263  usterki za b\u322 \u281 dy.\
Dzi\uc0\u281 ki opcji 
\f2 -fstack-protector-strong
\f0 , podczas wykonania programu zostan\uc0\u261  wykryte niekt\'f3re b\u322 \u281 dne odwo\u322 ania do pami\u281 ci na stosie. Opcje 
\f2 -fsanitize=undefined
\f0 , 
\f2 -fno-sanitize-recover
\f0  umo\uc0\u380 liwiaj\u261  wykrywanie operacji, kt\'f3re maj\u261  efekt nieokre\u347 lony. Opcje 
\f2 -g
\f0 , 
\f2 -fno-omit-frame-pointer
\f0  poprawiaj\uc0\u261  jako\u347 \u263  komunikat\'f3w o b\u322 \u281 dach wykonania. Opcja 
\f2 -O1
\f0  w\uc0\u322 \u261 cza optymalizacje, co zwi\u281 ksza prawdopodobie\u324 stwo ujawnienia si\u281  b\u322 \u281 d\'f3w.\
Wymagane s\uc0\u261  wszystkie wymienione opcje kompilatora. Nie b\u281 d\u261  do nich dodawane \u380 adne inne.\
Zwracamy uwag\uc0\u281 , \u380 e poszczeg\'f3lne wersje kompilatora gcc mog\u261  si\u281  r\'f3\u380 ni\u263  sposobem obs\u322 ugi tych samych opcji. Przed wys\u322 aniem rozwi\u261 zania warto wi\u281 c skompilowa\u263  je i przetestowa\u263  na 
\f2 students
\f0  w spos\'f3b opisany powy\uc0\u380 ej.\
Podczas walidacji i test\'f3w, program 
\f2 nazwa
\f0  jest uruchamiany pod kontrol\uc0\u261  programu Valgrind poleceniem:\
\pard\pardeftab720\partightenfactor0

\f2 \cf0 valgrind --leak-check=full -q --error-exitcode=1 ./nazwa\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 Je\uc0\u347 li Valgrind wykryje b\u322 \u261 d, to nawet gdyby wynik by\u322  prawid\u322 owy, uznajemy,\
}