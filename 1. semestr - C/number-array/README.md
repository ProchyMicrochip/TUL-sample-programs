# Prace s dvojrozmernym polem

1) Napiste funkci pro zobrazeni dvourozmerneho pole velikosti R x C ve std. vystupu  Napr. definovane pole o velikosti 5x5 s prvky inicializovanymi na 0 (R = 5, C = 5)
    ```
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    ```

2) Napiste funkci, ktera vygeneruje do dvourozmerneho pole na N nahodnych pozic specificke cislo D Napr. 3x vygenerovana hodnota 8 (N = 3, D = 8)
    ```
    8 0 0 0 0
    0 0 0 8 0
    8 0 0 0 0
    0 0 8 0 0
    0 0 0 0 0
    ```

3) Napiste funkci, ktera vygeneruje sekvenci cisel v miste specificke hodnoty D tak, ze postupne naplni policka pod danou pozici v rade polovicnimi hodnotami v dane rade az do hodnoty 0. Napr. D = 8
    ```
    8 0 0 0 0
    4 0 0 8 0
    8 0 0 4 0
    4 0 8 2 0
    2 0 4 1 0
    ```
   
4) V hlavnim programu definujte pole R x C inicializovane na 0, kde hodnoty R a C definujte jako makro a pouzivejte je pak vsude kde je potreba znat rozmery pole. Vygenerujte pomoci funkce nahodne hodnoty D do pole a aplikujte funkci pro modifikaci pole.