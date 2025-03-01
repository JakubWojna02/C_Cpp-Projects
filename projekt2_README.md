{\rtf1\ansi\ansicpg1250\cocoartf2821
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\froman\fcharset0 Times-Roman;\f1\froman\fcharset0 Times-Bold;\f2\fmodern\fcharset0 Courier;
}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red109\green109\blue109;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;\cssrgb\c50196\c50196\c50196;}
{\*\listtable{\list\listtemplateid1\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid1\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid1}
{\list\listtemplateid2\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid101\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid2}
{\list\listtemplateid3\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid201\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid3}
{\list\listtemplateid4\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid301\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid4}
{\list\listtemplateid5\listhybrid{\listlevel\levelnfc23\levelnfcn23\leveljc0\leveljcn0\levelfollow0\levelstartat1\levelspace360\levelindent0{\*\levelmarker \{disc\}}{\leveltext\leveltemplateid401\'01\uc0\u8226 ;}{\levelnumbers;}\fi-360\li720\lin720 }{\listname ;}\listid5}}
{\*\listoverridetable{\listoverride\listid1\listoverridecount0\ls1}{\listoverride\listid2\listoverridecount0\ls2}{\listoverride\listid3\listoverridecount0\ls3}{\listoverride\listid4\listoverridecount0\ls4}{\listoverride\listid5\listoverridecount0\ls5}}
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

\fs28 \cf0 Kostka Rubika
\f0\b0  to \uc0\u322 amig\u322 \'f3wka, kt\'f3ra sk\u322 ada si\u281  z ruchomych sze\u347 ciennych blok\'f3w.\
\uc0\u346 ciany kostki dziel\u261  si\u281  na kolorowe kwadraty, nale\u380 \u261 ce do poszczeg\'f3lnych blok\'f3w. W stanie u\u322 o\u380 onym wszystkie kwadraty danej \u347 ciany pokryte s\u261  jednym kolorem, dla ka\u380 dej \u347 ciany innym.\
Blok nale\uc0\u380 y do trzech prostopad\u322 ych warstw kostki. Bloki mo\u380 na przemieszcza\u263 , obracaj\u261 c warstwy o wielokrotno\u347 \u263  k\u261 ta prostego.\
Celem uk\uc0\u322 adaj\u261 cego jest doprowadzenie losowo uporz\u261 dkowanej kostki do stanu u\u322 o\u380 onego.\
Najcz\uc0\u281 \u347 ciej u\u380 ywa si\u281  kostek rozmiaru 3 x 3 x 3, ale s\u261  te\u380  wi\u281 ksze lub mniejsze.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Polecenie\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Napisz program, kt\'f3ry wykonuje ci\uc0\u261 g rozkaz\'f3w obracaj\u261 cych warstwy kostki rozmiaru N x N x N, gdzie N jest dodatni\u261  warto\u347 ci\u261  z zakresu typu int. Program zaczyna od kostki u\u322 o\u380 onej. Na \u380 yczenie drukuje aktualny stan kostki.\
Sta\uc0\u322 \u261  symboliczn\u261  N, okre\u347 laj\u261 c\u261  rozmiar kostki, nale\u380 y zdefiniowa\u263  dyrektywami:\
\pard\pardeftab720\partightenfactor0

\f2 \cf0 #ifndef N\
#define N 5\
#endif\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 Wskazuj\uc0\u261  one 5 jako warto\u347 \u263  domy\u347 ln\u261 . Inn\u261  warto\u347 \u263  sta\u322 ej mo\u380 na wybra\u263  podczas kompilacji programu za pomoc\u261  opcji 
\f2 -DN=warto\uc0\u347 \u263 
\f0 .\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Posta\uc0\u263  danych\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Dane programu to ci\uc0\u261 g rozkaz\'f3w obrotu warstw i wydruku aktualnego stanu kostki, zako\u324 czony kropk\u261 .\
Program ignoruje zawarto\uc0\u347 \u263  wej\u347 cia po kropce ko\u324 cz\u261 cej dane.\
Rozkazem wydruku stanu kostki jest koniec wiersza.\
Rozkaz obrotu warstw sk\uc0\u322 ada si\u281  z trzech cz\u281 \u347 ci, kt\'f3re wskazuj\u261 :\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls1\ilvl0\cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 liczb\uc0\u281  warstw,\
\ls1\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \uc0\u347 cian\u281  kostki,\
\ls1\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 k\uc0\u261 t obrotu.\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Je\uc0\u347 li cz\u281 \u347 \u263  rozkazu, okre\u347 laj\u261 ca liczb\u281  warstw, jest pusta, to wskazuje liczb\u281  1. W przeciwnym przypadku jest pozycyjnym dziesi\u281 tnym zapisem dodatniej liczby warstw. Warto\u347 \u263  tej liczby nie przekracza sta\u322 ej N, definiuj\u261 cej rozmiar kostki.\
\uc0\u346 ciana jest okre\u347 lona liter\u261 :\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls2\ilvl0
\f1\b \cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 u
\f0\b0  - g\'f3ra (ang. up),\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 l
\f0\b0  - lewo (ang. left),\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 f
\f0\b0  - prz\'f3d (ang. front),\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 r
\f0\b0  - prawo (ang. right),\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 b
\f0\b0  - ty\uc0\u322  (ang. back),\
\ls2\ilvl0
\f1\b \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 d
\f0\b0  - d\'f3\uc0\u322  (ang. down).\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Cz\uc0\u281 \u347 \u263  rozkazu okre\u347 laj\u261 ca k\u261 t jest albo pusta albo jest apostrofem lub cudzys\u322 owem. Pusta cz\u281 \u347 \u263  wskazuje k\u261 t 90 stopni, apostrof to -90 stopni, a cudzys\u322 \'f3w to 180 stopni.\
Wykonanie rozkazu obrotu, z liczb\uc0\u261  warstw W, \u347 cian\u261  S, i k\u261 tem K, powoduje jednoczesne obr\'f3cenie W warstw, patrz\u261 c od strony \u347 ciany S, o k\u261 t K, zgodnie z ruchem wskaz\'f3wek zegara.\
Sk\uc0\u322 adni\u281  danych opisuje gramatyka z symbolem pocz\u261 tkowym 
\f1\b Dane
\f0\b0 :\
\pard\pardeftab720\partightenfactor0

\f2 \cf0 Dane \uc0\u8594  Ci\u261 gRozkaz\'f3w Kropka\
Ci\uc0\u261 gRozkaz\'f3w \u8594  \u949  | Rozkaz Ci\u261 gRozkaz\'f3w\
Rozkaz \uc0\u8594  Obr\'f3t | Drukowanie\
Obr\'f3t \uc0\u8594  LiczbaWarstw Strona K\u261 t\
Drukowanie \uc0\u8594  KoniecWiersza\
Strona \uc0\u8594  Litera\
LiczbaWarstw \uc0\u8594  Jedna | Wiele\
Jedna \uc0\u8594  \u949 \
Wiele \uc0\u8594  Liczba\
Liczba \uc0\u8594  Dodatnia | Liczba Cyfra\
K\uc0\u261 t \u8594  Prosty | MinusProsty | P\'f3\u322 pe\u322 ny\
Prosty \uc0\u8594  \u949 \
MinusProsty \uc0\u8594  Apostrof\
P\'f3\uc0\u322 pe\u322 ny \u8594  Cudzys\u322 \'f3w\
Litera \uc0\u8594  'u' | 'l' | 'f' | 'r' | 'b' | 'd'\
Dodatnia \uc0\u8594  '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'\
Cyfra \uc0\u8594  '0' | Dodatnia\
Apostrof \uc0\u8594  '\\''\
Cudzys\uc0\u322 \'f3w \u8594  '"'\
KoniecWiersza \uc0\u8594  '\\n'\
Kropka \uc0\u8594  '.'\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 Symbole ko\uc0\u324 cowe 'u', 'l', 'f', 'r', 'b', 'd', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '"', reprezentuj\u261  znaki zapisane mi\u281 dzy apostrofami, '\\'' to apostrof, a '\\n' to koniec wiersza.\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Posta\uc0\u263  wyniku\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Wynik programu jest efektem wykonania rozkaz\'f3w drukowania aktualnego stanu kostki.\
Wydruk stanu kostki sk\uc0\u322 ada si\u281  ze znak\'f3w 0, 1, 2, 3, 4, 5, symbolizuj\u261 cych kolory kwadrat\'f3w na \u347 cianach kostki, oraz ze spacji i kresek pionowych |.\
Przyjmujemy, \uc0\u380 e w u\u322 o\u380 onej kostce:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls3\ilvl0\cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany g\'f3rnej maj\u261  kolor 0,\
\ls3\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany lewej maj\u261  kolor 1,\
\ls3\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany przedniej maj\u261  kolor 2,\
\ls3\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany prawej maj\u261  kolor 3,\
\ls3\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany tylnej maj\u261  kolor 4,\
\ls3\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 kwadraty \uc0\u347 ciany dolnej maj\u261  kolor 5.\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Po\uc0\u322 o\u380 enie \u347 cian na wydruku stanu kostki jest zgodne ze schematem:\
\pard\pardeftab720\partightenfactor0

\f2 \cf0   u\
l|f|r|b\
  d\
\pard\pardeftab720\sa280\partightenfactor0

\f0 \cf0 gdzie u, l, f, r, b, d to, odpowiednio, \uc0\u347 ciana g\'f3rna, lewa, przednia, prawa, tylna i dolna.\
Dla sta\uc0\u322 ej N, definiuj\u261 cej rozmiar kostki, wydruk stanu kostki sk\u322 ada si\u281  z 3 * N + 1 wierszy:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls4\ilvl0\cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 pierwszy wiersz jest pusty,\
\ls4\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 N kolejnych wierszy opisuje \uc0\u347 cian\u281  g\'f3rn\u261 ,\
\ls4\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 nast\uc0\u281 pnych N wierszy to opis \u347 ciany lewej, przedniej, prawej i tylnej,\
\ls4\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 ostatnich N wierszy opisuje \uc0\u347 cian\u281  doln\u261 .\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Ka\uc0\u380 dy wiersz opisu \u347 ciany g\'f3rnej i dolnej zaczyna si\u281  od N + 1 spacji, po kt\'f3rych jest N cyfr okre\u347 laj\u261 cych kolory kwadrat\'f3w tej \u347 ciany.\
Wiersze opisu \uc0\u347 ciany lewej, przedniej, prawej i tylnej maj\u261  kolejno:\
\pard\tx220\tx720\pardeftab720\li720\fi-720\partightenfactor0
\ls5\ilvl0\cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 N cyfr okre\uc0\u347 laj\u261 cych kolory kwadrat\'f3w na \u347 cianie lewej,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 znak |,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 N cyfr okre\uc0\u347 laj\u261 cych kolory kwadrat\'f3w na \u347 cianie przedniej,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 znak |,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 N cyfr okre\uc0\u347 laj\u261 cych kolory kwadrat\'f3w na \u347 cianie prawej,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 znak |,\
\ls5\ilvl0\kerning1\expnd0\expndtw0 \outl0\strokewidth0 {\listtext	\uc0\u8226 	}\expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 N cyfr okre\uc0\u347 laj\u261 cych kolory kwadrat\'f3w na \u347 cianie tylnej.\
\pard\pardeftab720\sa280\partightenfactor0
\cf0 Na wydruku stanu kostki, cyfry okre\uc0\u347 laj\u261 ce kolory kwadrat\'f3w ka\u380 dej \u347 ciany zajmuj\u261  obszar rozmiaru N x N.\
Dla \uc0\u347 ciany lewej, przedniej, prawej i tylnej, kolory kwadrat\'f3w opisane s\u261  w kolejno\u347 ci, jak\u261  zobaczyliby\u347 my po obrocie ca\u322 ej kostki o wielokrotno\u347 \u263  k\u261 ta prostego wok\'f3\u322  osi przechodz\u261 cej przez \u347 cian\u281  g\'f3rn\u261  i doln\u261 .\
Dla \uc0\u347 ciany g\'f3rnej i dolnej kolejno\u347 \u263  jest taka, jak\u261  zobaczyliby\u347 my, gdyby\u347 my obr\'f3cili kostk\u281  o wielokrotno\u347 \u263  k\u261 ta prostego wok\'f3\u322  osi przechodz\u261 cej przez \u347 cian\u281  lew\u261  i praw\u261 .\
\pard\pardeftab720\sa348\partightenfactor0

\f1\b\fs42 \cf0 Przyk\uc0\u322 ady\
\pard\pardeftab720\sa280\partightenfactor0

\f0\b0\fs28 \cf0 Do tre\uc0\u347 ci zadania do\u322 \u261 czone s\u261  pliki 
\f2 .in
\f0  z przyk\uc0\u322 adowymi danymi i pliki 
\f2 .out
\f0  z wynikami wzorcowymi.\
Przyk\uc0\u322 ady zak\u322 adaj\u261 , \u380 e sta\u322 a N, definiuj\u261 ca rozmiar kostki, ma warto\u347 \u263  5.\
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

\f0\b0\fs28 \cf0 Rozwi\uc0\u261 zania podlegaj\u261  walidacji, wst\u281 pnie badaj\u261 cej zgodno\u347 \u263  ze specyfikacj\u261 .\
Walidacja sprawdza dzia\uc0\u322 anie programu na przyk\u322 adach do\u322 \u261 czonych do tre\u347 ci zadania.\
Pomy\uc0\u347 lne przej\u347 cie walidacji jest warunkiem dopuszczenia programu do test\'f3w poprawno\u347 ci.\
}