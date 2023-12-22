# asin(x) funkcijas laukuma aprēķināšana izmantojot skaitlisko integrēšanu

Izmantojot skaitlisko integrēšanu ir iespējams noteikt funkcijas laukuma vērtību noteiktā diapazonā. Laboratorijas darba laikā tika izstrādāta C programma, kura, izmantojot trīs dažādas skaitliskās integrācijas metodes, spēj atrast `asin(x)` funkcijas laukumu uzdotajā diapazonā `[a, b]`.

![asin(x) funkcijas laukuma attēlojums diapazonā [0, 1]](images/integral.png)

Izmantojot `gnuplot` grafiku vizualizācijas rīku ir iespējams uzskatāmi parādīt `asin(x)` funkcijas laukumu. Piemērā tiek parādīts laukums diapazonā `[0, 1]`, jo praktiskos gadījumos ir vēlams noteikt funkcijas laukumu apgabalos kur saknes zīme nemainās. Citādi var rasties nekorekta laukuma vērtība, saskaitot pozitīvus laukuma apgabalus ar negatīviem.

![Funkcijas asin(x) diapazonā [0, 1] integrēšana izmantojot WolframAlpha rīku](images/wolfram_alpha_proovement.png)

Izmantojot `WolframAlpha` rīku ir iespējams pārbaudīt vai realizētā programma darbojas pareizi.

# Programmas darbības apraksts un analīze

Nokompilējot failu `main.c` izmantojot sekojošu komandu:
```shell
$ mkdir build && gcc main.c -o build/integral -lm
```
Un palaižot izpildāmo failu:
```shell
$ ./build/integral
```

Lietotājam tiks prasīts ievadīt:
- diapazona sākuma skaitli `a` diapazonā no `[-1, 1]`;
- diapazona beigu skaitli `b` diapazonā no `[a, 1]`;
- precizitātes lielumu `precision`.

Pēc tam kad lietotājs ievadīja visus skaitļus un nospieda `Enter`, notiek funkcijas `asin(x)` laukuma atrašana trīs dažādos veidos.

```
$ ./build/integral
Please input lower range value a in range[-1:1]:
0
Please input upper range value b in range[a:1]:
1
Please input precision value:
0.0000000001
asin(x) integral value in range [ 0.00000 : 1.00000 ] using step function method: 0.570796326766552696236126096530
asin(x) integral value in range [ 0.00000 : 1.00000 ] using trapezoidal rule:     0.570796326703464975966910432970
asin(x) integral value in range [ 0.00000 : 1.00000 ] using Simpson's rule:       0.570796326703464839953747894663
```

Katra no trīs metodēm darbojas pēc līdzīga principa, mainoties tikai katras metodes formulai. Katra no metodēm paredz grafika dalīšanu mazākos gabalos, to laukumu aprēķināšanu, un rezultējošo laukumu saskaitīšanu.

### Soļu metode

Šī metode sadala doto grafiku vairākās vienādās daļās pa `x` asi, katrā solī aprēķinot arī `y` vērtību. Šādā veidā doto grafiku ir iespējams sadalīt vairākos taisnstūros, kur soļa lielums ir viena taisnstūra mala, un aprēķinātā vērtība soļa sākumpunktā (vai viduspunktā) ir otra taisnstūra malas garums. Zinot abu taisnstūra malu garumus ir iespējams noteikt dotā apgabala laukuma vērtību.

### Trapeču metode

Tā pat kā soļu metode, šī metode paredz grafika sadalīšanu vairākās vienādās daļās, taču lai izveidotos trapece, ir nepieciešams aprēķināt funkcijas vērtību gan soļa sākumpunktā, gan soļa galapunktā. Uztverot aprēķinātās vērtības kā trapeces malas `a` un `b`, un soļa lielumu kā trapeces augstumu `h`, ir iespējams aprēķināt trapeces laukumu.

### Simpsona metode

Pēc grafika sadalīšanas vairākās daļās, šī metode paredz aprēķināt trīs vērtības soļa diapazonā. Ir nepieciešams aprēķināt funkcijas vērtību soļa sākumā, soļa vidū, un soļa beigās. No šiem trīs punktiem ir iespējams izveidot parabolu, kurai ir iespējams aprēķināt laukumu.
