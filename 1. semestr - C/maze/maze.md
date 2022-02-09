# Uloha nalezeni cesty pomoci backtracing

- Pomyslna oblast obdelnikoveho tvaru o velikosti 8 x 4 policek (w x h). V teto oblasti hledame cestu z policka [0, 0] na policko cilove urcene nahodne [ex, ey]. V oblasti je jedna prekazka nahodne umistena na policku [ox, oy].

- Pro hledani cesty plati pravidla
  - z jednoho policka na druhe se chodi ve smerech v tomto poradi doprava (x + 1), dolu (y + 1), doleva (x - 1), nahoru (y - 1)
  - nemohu jit na policko na kterem jsem uz byl, nebo je mimo oblast ci jde o prekazku, napr. pokud bych mel jit doprava a nemohu tam, jdu dalsim smerem, tedy dolu a pokud ani tam nemohu jit, zkusim jit doleva atd.

- Abych si pamatoval kde jsem uz byl, tak si musim policko oznacit. Pro ulozeni se pouzije 32 bitova hodnota, kde jednotlive bity odpovidaji prislusnym polickum oblasti (proto oblast velikosti 8x4). Navstivene policku = nastaveny bit. Cislo bitu pro prislusne policko je dano vztahem b = y * w + x (napr. pro policko [3, 2], kdy w = 8, to bude bit c. 19). Stejnym zpusobem bude ulozena uspesne nalezena cesta.

1) napiste funkci, ktera nastavi bit promenne pro navstivena policka podle souradnic [x, y]

2) napiste funkci, ktera otestuje nastaveni bitu promenne pro navstivena policka podle souradnic [x, y]

3) analogicky jako v 1) a 2) pro uspesnou cestu

4) napiste rekurzivni funkci pro prochazeni oblasti, zacinate predanim souradnic [0, 0]

5) vykreslete do vystupu nalezenou cestu v oblasti a vyznacte prekazku (znakem X) a cil (znakem O)

Pozn.:
- promenne w, h, ex, ey, ox, oy a pro ulozeni stavu navstivenych policek a uspesne cesty definujte jako globalni
- pro nastavovani bitu a cteni jeho stavu vyuzijte bitoveho posunu

Priklad vystupu:
1.  ```
    Start 0,0 / Cil 6,1
    ++X
    +++++O
    ```

    - Jak probiha cesta:
    ```
    >vX
    >>>>>O
    ```

2)  ```
    Start 0,0 / Cil 7,3
    +X
    ++++++++
    +
    O
    ```

    - Jak probiha cesta:
    ```
    vX 
    >>>>>>>v
    v
    O
    ```

3.  ```
    Start 0,0 / Cil 4,3
    ++++++++
    +
    ++++
    OX++
    ```
    - Jak probiha cesta:
    ```
    >>>>>>>v
    v
    v<<v
    OX^<
    ```

4. ```
    Start 0,0 / Cil 5,1
    ++++++++
    O++
    ++++++
    X++++++
    ```

    - Jak probiha cesta:
    ```
    >>>>>>>v
    O<v
    >>>>^v
    X^<<<<<
    ```