# asin(x) funkcijas saknes meklēšana diapazonā izmantojot dishotomijas metodi

Izmantojot dishotomijas metodi ir iespējams atrast vienu no funkcijas `f(x)` saknēm pie nosacījuma, ka funkcijai ir nepāra sakņu skaits. Funkcijas sakne ir argumenta `x` vērtība pie kura ir spēkā vienādība `f(x)=0`.
Izmantojot šo metodi ir arī iespējams noteikt pa `y` asi nobīdītas `f(x)` funkcijas sakni. Laboratorijas darba ietvaros tika apskatīta dishotomijas metode meklējot `asin(x)` sakni, un izstrādāta C programma, kas šo sakni atrod pie uzdotas precizitātes un citiem parametriem.

![asin(x) un šīs funkcijas nobīdītā veidā izmantojot gnuplot](images/asin.png)

Dotajā attēlā ir redzams `asin(x)` funkcijas grafiks visā tā definīcijas apgabalā `[-1,1]`, kā arī šī funkcija nobīdītā veidā - `asin(x) - 1` un `asin(x) + 1`.
