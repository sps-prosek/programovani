# Vstupní znalosti žáků z 2. ročníku

Zdroj: Moodle záloha kurzu **2EA Programování (2025/2026)** (`2EA_PRG_25/26`,
`zaloha-moodle2-course-378-...mbz`, stav k 18. 9. 2026).
Kurz má 9 tematických oddílů + organizační část, 125 aktivit.

Tento dokument je **smlouva o vstupních znalostech**: co ve 3. ročníku smím
předpokládat jako známé a co musím zopakovat nebo teprve zavést.

---

## Přehled oddílů 2EA kurzu

| # | Téma v Moodle | Materiál v kurzu | Stav |
|---|---|---|---|
| 01 | Úvod do programování | prezentace PDF, zdroje, otázky | hotové |
| 02 | Algoritmy, vývojové diagramy a pseudokód | prezentace PDF, zdroje, otázky | hotové |
| 03 | Úvod do jazyka C | prezentace PDF, zdroje, otázky | hotové |
| 04 | Proměnné a datové typy | prezentace PDF, **zdrojové kódy**, otázky | hotové |
| 05 | Podmínky a větvení programu | prezentace PDF, **zdrojové kódy**, otázky | hotové |
| 06 | Cykly v programování | prezentace PDF, **zdrojové kódy**, otázky | hotové |
| 07 | Pole a textové řetězce | prezentace PDF + studijní materiál algoritmy, otázky | hotové |
| 08 | Funkce a struktury | jen zdroje + otázky, **prezentace chybí** | neúplné |
| 09 | Základy mikropočítačů | zdroje + otázky + Arduino příručka, **prezentace chybí** | neúplné |

Prezentace 01–07 a Arduino příručka jsou vytažené do `zdroje/prezentace_2ea/`.

---

## Co žáci UMÍ (lze stavět bez opakování)

### Jazyk C – syntaxe a základy (T03)
- struktura programu, `main()`, `return 0;`, `#include`, knihovny
- typy závorek `<> {} () []` a jejich význam
- `printf()`, formátovací značky `\n`, komentáře `//` a `/* */`
- pojem IDE (učili se ve VS Code / CLion / OnlineGDB)

### Proměnné a datové typy (T04)
- deklarace × inicializace, pojmenovávací konvence
- `int`, `char`, `float`, `double`, `short`, `long`, `_Bool`
- velikosti a rozsahy: bajt = 8 bitů, `char` = 1 B (−128…127 / 0…255), `int` obvykle 4 B
- `signed` × `unsigned`
- statický typový systém (C je staticky typovaný)
- formátovací značky `%d %f %c %s`, zaokrouhlení `%.2f`
- konstanty: číselné, znakové, řetězcové, `#define`, `const`
- lokální × globální proměnná

### Podmínky a větvení (T05)
- `if` / `else if` / `else`, bloky `{}`
- relační operátory `== != > < >= <=`, negace `!`
- logické operátory `&&`, `||`
- ternární operátor `? :`
- `switch` / `case` / `break` / `default`, kdy `switch` a kdy `else-if`
- operátor `%` (modulo) – sudé/liché

### Cykly (T06)
- `for`, `while`, `do-while` – syntaxe i kdy který použít
- vnořené cykly (matice, vykreslování obrazců)

### Pole a řetězce (T07)
- deklarace `typ nazev[velikost]`, indexace od 0, poslední index = velikost−1
- C nekontroluje meze pole
- způsoby inicializace, vícerozměrné pole `m[radek][sloupec]`
- řetězec = pole `char` ukončené `\0`; knihovna `string.h`
  (`strlen`, `strcpy`, `strcat`, `strcmp`)
- algoritmy: **Bubble Sort**, binární vyhledávání (projekty), analýza pole
  (min/max, počty sudých/lichých, průměr, procenta)

### Funkce a struktury (T08)
- definice funkce `navratovy_typ jmeno(parametry) { }`, volání, `return`, `void`
- parametry, návratová hodnota, výhody funkcí
- **rekurze** (faktoriál)
- `struct`, přístup tečkou, inicializace, `typedef`, rozdíl `struct` × `union`

### Základy mikropočítačů – HW (T09)
- co je Arduino, ATmega328P, hlavní části desky UNO
- typy desek (UNO, Mega, Nano, Leonardo, UNO R4), shieldy
- digitální × analogové piny, ADC 10 bit → 0–1023, symbol `~` = PWM
- napájení: USB / VIN 7–12 V / 5V pin, stabilizátor
- UART piny D0 (RX) a D1 (TX), pin 13 = vestavěná LED
- nepájivé pole, anoda/katoda LED, předřadný odpor 220–330 Ω
- tlačítko → digitální vstup + `INPUT_PULLUP`; potenciometr → analogový vstup
- senzory: HC-SR04 (ultrazvuk), PIR; LCD s I2C × bez I2C

### Základy mikropočítačů – SW (T09)
- `setup()` × `loop()`
- instalace a použití knihoven, `#include`
- `pinMode()` (INPUT / OUTPUT / INPUT_PULLUP)
- `digitalWrite()` / `digitalRead()` / `analogWrite()` (0–255) / `analogRead()` (0–1023)
- `Serial.begin(9600)`, `Serial.print()`, `Serial.read()`, baudová rychlost
- `delay()` × `millis()` – **rozdíl blokující/neblokující už byl vysvětlen**

---

## Co žáci NEUMÍ (ve 3. ročníku zavádím jako nové)

| Oblast | Poznámka |
|---|---|
| Ukazatele, dynamická alokace | v osnově 2EA slíbeno, v otázkách k zapamatování se **neobjevuje** – ověřit, zda se to stihlo |
| Zákmity tlačítka (debounce) | vůbec |
| Detekce hrany (náběžná/sestupná), `static` proměnná | vůbec |
| Stavový automat jako návrhový vzor | vůbec |
| Praktické neblokující časování (`millis()` v úloze) | teorie ano, praxe ne |
| Přerušení (`attachInterrupt`) | vůbec |
| PWM jako fyzikální jev (střída, frekvence) | jen že `~` = PWM |
| UART na úrovni rámce (start/stop bit, parita, délka bitu) | vůbec |
| Zpracování přijatého textu (parsování, `String`, buffer) | vůbec |
| I2C sběrnice | jen že "LCD s I2C má 4 vodiče" |
| Servo, krokový motor, DC motor, H-můstek | vůbec |
| Inkrementální enkodér | vůbec |
| Vlastní hlavičkové soubory / knihovny | vůbec |

---

## Rizika a nesrovnalosti

1. **Prezentace k T08 (funkce, struktury) a T09 (mikropočítače) v kurzu chybí** –
   existují jen otázky k zapamatování. Znalost funkcí je přitom klíčová pro téma 06
   nového plánu. → Na začátku roku ověřit krátkým vstupním testem.
2. **Ukazatele** jsou v osnově 2EA, ale nejsou v otázkách k zapamatování ani
   v domácích úlohách. Nepředpokládat je.
3. Žáci programovali v **konzolové aplikaci** (`printf`/`scanf`, OnlineGDB), ne
   na HW. Přechod na `Serial.print()` a absenci `scanf()` je potřeba explicitně řešit.
4. T09 je jediné, kde už zazněl Arduino slovník. Téma 01 nového plánu tedy může být
   spíš **rychlá rekapitulace + rozjezd IDE**, ne výklad od nuly.

---

## Kalibrace obtížnosti – domácí úlohy 2EA

Sedm povinných domácích úloh, vzestupně. Toto je laťka, na kterou navazuji.

| # | Úloha | Ověřuje |
|---|---|---|
| 1 | Bankovní účet – menu, vklad/výběr, nekonečná smyčka, kontrola zůstatku | `while`, `switch`, podmínky |
| 2 | Rám s křížem – vykreslení obrazce N×N z `*` a `/` | vnořené cykly |
| 3 | Měnová kalkulačka – menu, 4 směry převodu, opakování do ukončení | `float`, menu, validace |
| 4 | Generátor PIN kódů – N unikátních 4místných PINů, max 10 | `rand()`, kontrola duplicit |
| 5 | Výměna hodnot mezi dvěma poli | práce s polem, cyklus |
| 6 | Bubble Sort + analýza pole (min, max, sudá/lichá, průměr, procenta) | třídění, statistika |
| 7 | Kontrola palindromu (ignoruje velikost písmen a mezery) | řetězce, `char` |

Společné požadavky ve všech zadáních: **smysluplné názvy proměnných,
okomentovaný kód, správné odsazení**. Tuto formulaci převzít i do 3. ročníku.

Dále: **dlouhodobý projekt** (správa rozvrhu – odevzdané kódy mají 10–25 kB),
pravidelné **samostatné práce v hodině** (4× za rok) a **Moodle testy**
označené tématy, verze SEB i NSEB.
