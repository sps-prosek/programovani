# 00 – Opakování jazyka C pro mikrokontrolery

**Rozsah:** 1 h jádro + rozšiřující slidy (celkem materiál zhruba na 2 h)
**Zařazení dle ŠVP:** není samostatné učivo – vstupní opakování před tématem 01,
hradí se z rezervy 14 h
**Výsledky vzdělávání:** příprava na V1, V4 (ověření vstupních znalostí)
**Učivo:** navazuje na 2. ročník, zavádí kontext U7 (rozdělení paměti)

## Proč toto téma existuje

Tematický plán počítá s tím, že se ve 3. ročníku syntaxe jazyka C neopakuje.
Podle [`plan/vstupni_znalosti_2ea.md`](../../plan/vstupni_znalosti_2ea.md) ale platí:

- k tématům „Funkce a struktury“ a „Základy mikropočítačů“ **chybí v kurzu 2EA prezentace**,
- **ukazatele** jsou v osnově, ale nejsou ani v otázkách, ani v domácích úlohách,
- žáci programovali **jen konzolové aplikace**, nikdy ne hardware.

Tato hodina proto neopakuje C jako takový, ale **přerámuje ho do kontextu
mikrokontroleru**: co z něj platí jinak, když `int` má 2 bajty, SRAM 2 kB
a program nikdy neskončí. Zároveň slouží jako **neformální vstupní test** –
z odpovědí na kvíz je hned vidět, co třída skutečně umí.

## Jádro × rozšíření

Slidy označené v titulku **„(rozšíření)“** nejsou součástí 45minutového jádra.
Dají se bez ztráty souvislosti přeskočit. Hodí se, když třída stíhá, na druhou
hodinu opakování, nebo jako opora do Moodle.

| | Kvízy | Témata |
|---|---|---|
| **Jádro** (45 min) | 1, 2, 3, 5, 7, 8, 9, 10 | datové typy a rozsahy, přetečení, větvení, cykly, program bez konce, funkce, pole a SRAM |
| **Rozšíření** | 4, 6, 11 | `#define` × `const`, kontrola typu překladačem a k čemu je preprocesor naopak dobrý (5 slidů), `switch`/`case`, `printf` → `Serial.print`, lokální × globální proměnná, bitové operace, práce s chybami překladače |

**Správné odpovědi:** 1-B, 2-C, 3-C, 4-B, 5-B, 6-B, 7-B, 8-B, 9-B, 10-C, 11-C

## Cíle hodiny

Žák po hodině:

- uvede velikost `int` na AVR a vysvětlí, proč se liší od PC
- vysvětlí přetečení `unsigned` typu a řekne, kdy k němu dojde u `millis()`
- zdůvodní, proč se místo `int` píše `uint8_t` / `uint16_t` / `uint32_t`
- rozliší `=` a `==` a vysvětlí, proč `if (x = 5)` projde překladem
- vybere vhodný cyklus (`for` / `while` / `do-while`) a spočítá počet iterací
- vysvětlí, proč je čekání v cyklu na mikrokontroleru problém
- popíše, co dělá skrytý `main()` v Arduinu a co z toho plyne pro `loop()`
- řekne, co se stane při zápisu za konec pole, a proč to překladač nezachytí
- vysvětlí, že parametr funkce se předává kopií

Navíc v rozšíření: rozdíl `#define` a `const` a **co způsobí chybějící nebo špatný
datový typ** – textová náhrada mění prioritu operátorů, mezivýsledek se počítá
v 16 bitech a tiše přeteče (`adc * 5000 / 1023`), a chybové hlášení ukazuje
dosazenou hodnotu místo jména konstanty. Na to navazuje **k čemu je preprocesor
naopak nenahraditelný**: podmíněný překlad ladicích výpisů (`#ifdef DEBUG`,
makro expandující na nic), přepnutí podle platformy (`#if defined(__AVR__)`)
a ochrana hlavičkového souboru. Dělicí čára: preprocesor rozhoduje, které řádky
se vůbec přeloží; pojmenovat hodnotu má `const`. Dále `switch` včetně propadnutí
bez `break`, převod `printf` na `Serial.print`, rozsah platnosti proměnné,
bitové operace.

## Průběh hodiny – jádro (45 min)

| Čas | Fáze | Co se děje |
|---:|---|---|
| 0–3 | Zahájení | Cíle, pravidla kvízu (tip nahlas / rukou A–D). |
| 3–7 | Rámování | 2. ročník vs. 3. ročník – stejný jazyk, jiný stroj. |
| 7–17 | Kvíz 1–3 | `sizeof(int)`, přetečení `uint8_t`, proč `unsigned long`. |
| 17–25 | Větvení, kvíz 5 | `if` / `else if` / `else`, relační a logické operátory, past `=` × `==`. |
| 25–33 | Cykly, kvíz 7 | `for` / `while` / `do-while`, počet iterací, čekání v cyklu jako past. |
| 33–38 | Kvíz 8 | Kde je `main()`, co na mikrokontroleru není. |
| 38–43 | Kvíz 9–10 | Předání parametru kopií, meze pole, rozpočet 2 kB SRAM. |
| 43–45 | Závěr | Šest věcí k zapamatování, přechod na téma 01. |

## Klíčové pojmy

velikost datového typu, `uint8_t` / `int16_t` / `uint32_t`, přetečení, `unsigned`,
`=` × `==`, `if` / `else if` / `else`, relační a logické operátory, `switch` / `case` /
`break`, `for` / `while` / `do-while`, blokující čekání, skrytý `main()`,
`setup()` a `loop()`, meze pole, SRAM, zásobník, předávání hodnotou, lokální ×
globální proměnná, bitový posun, maska

## Návaznost

Hodina se drží **výhradně** toho, co žáci podle Moodle kurzu 2EA prokazatelně
měli. Nové věci se jen **pojmenují jako budoucí** a odloží do příslušných bloků:

| Zmíněno jako teaser | Probere se v bloku |
|---|---|
| ukazatele | 06 – Funkce a strukturování kódu |
| `static` lokální proměnná, detekce hrany, registry | 03 – Digitální vstupy |
| zákaz `delay()`, neblokující časování | 04 – Časování `millis()` |
| `switch` nad proměnnou `stav` = stavový automat | 05 – Stavové automaty |
| `F()`, `PROGMEM`, řetězce ve Flash | 09 – Pole a řetězce |
| vlastní hlavičkové soubory `.h` / `.cpp` | 15 – Vlastní knihovny |

## Materiály

- `prezentace/prezentace.tex` – 31 slidů, 11 kvízů s odkrýváním odpovědi
- `obrazky/` – tři obrázky k dodání (viz níže)

## Obrázky k dodání

| Soubor | Co má být na obrázku |
|---|---|
| `01_pc_vs_mcu` | Srovnání vedle sebe: notebook (OS, klávesnice, obrazovka, GB RAM) a Arduino UNO (piny, žádný OS, 2 kB SRAM) |
| `02_konzole_vs_serial` | Screenshot: konzole OnlineGDB s výstupem `printf` vedle sériového monitoru Arduino IDE s výstupem `Serial.println` |
| `03_chyba_prekladace` | Screenshot Arduino IDE s chybovým hlášením překladače, vyznačené číslo řádku a text chyby |

Dokud soubory nejsou, prezentace se přeloží a místo obrázku se vysází šedý
rámeček s popisem (makro `\obrazek` ve společné preambuli). Přijímá se
`.pdf`, `.png` i `.jpg` – přípona se do `\obrazek` nepíše.

## Poznámky k výuce

<!-- Vyplnit po hodině: které otázky třídu zastavily, kde byl výsledek kvízu
     překvapivý, co z toho plyne pro bloky 06 a 15 (ukazatele, knihovny). -->

- Stihnuto:
- Kde třída tápala:
- Příště jinak:
