# Uloha na praci s polem - prohazovani prvku podle nahodne zvoleneho klice

Mejme pole znaku o definovane velikosti N (zdrojove pole) a prazdne cilove pole o velikosti N. Do pole o velikosti K vygenerujeme nahodne ciselne
hodnoty klice (pole klice), podle ktereho se budou znaky prohazovat, v rozsahu 0 az K - 1. Hodnoty v poli klice se nesmi opakovat.
Prehazovani se provadi pro kazdou K-tici zdrojoveho pole, Prohozeni se provede podle klice tak, ze prohodime A-ty prvek zdrojoveho 
pole do B-teho prvku ciloveho pole, kde index B = hodnota prvku klice na indexu K-tice z A. Pokud nejde na konci zdrojoveho pole urcit
prvek k prohozeni, zustane puvodni prvek.

Pr. 
```
zdrojove pole => src = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'], tzn. N = 11
cilove pole => dest = [ \0, \0, \0, \0, \0, \0, \0, \0, \0, \0, \0], tzn. N = 11
pole klice => key = [1, 0, 3, 2], tzn. K = 4
```
```
pro A = 0 prohazuji src[0] do dest[1], B = 1     1. K-tice
pro A = 1 prohazuji src[1] do dest[0], B = 0
pro A = 2 prohazuji src[2] do dest[3], B = 3
pro A = 3 prohazuji src[3] do dest[2], B = 2

pro A = 4 prohazuji src[4] do dest[4], B = 1	2. K-tice

pro A = 8 prohazuji src[8] do dest[9], B = 1	3. K-tice
pro A = 9 prohazuji src[9] do dest[8], B = 2	
pro A = 10 prohazuji src[10] do dest[10], B = 3	!! tady vychazi dest[11], ale to nelze provest, proto zustane puvodni hodnota z src[10] !!
```
```
cilove pole => dest = ['B', 'A', 'D', 'C', 'F', 'E', 'H', 'G', 'J', 'I', 'K']
```

1) Definujte funkci, ktera vygeneruje do pole klic (neopakujici se hodnoty v rozsahu 0 az K-1)

2) Definujte funkce pro vypsani hodnot pole na radek std. vystupu (procisla i znaky, hodnoty oddelte mezerou)

3) Definujte funkci, ktera prohazi hodnoty ze zdrojoveho pole do ciloveho pole podle predaneho klice

4) Napiste hlavni funkci, kde vygenerujete nahodne klic a provedete prehozeni znaku z jednoho pole do druheho,
   vypiste do std. vystupu zdrojove pole, klic a vysledne prehazene pole. Zdrojove pole si definujte jako
   pevne v hlavnim programu.
