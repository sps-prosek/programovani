# Kalibrace úloh – co už ve 3. ročníku existuje

Zdroj: Moodle záloha kurzu **Programování (3EA)** (`E-PRG-3EA_1`,
`zaloha-moodle2-course-389-...mbz`, stav k 18. 9. 2026).
14 oddílů, 76 aktivit, banka otázek ~250 položek.

Kurz je obsahově nedodělaný a oddíly se místy překrývají (I2C je dvakrát,
LCD prázdné), ale **zadání úloh a banka otázek jsou použitelné skoro beze změny**.
Tento dokument je inventář: co převzít, kam to patří v novém plánu.

---

## 1. Zadání samostatných prací – seřazeno podle obtížnosti

Všechna zadání mají stejnou strukturu: **Zadání → Požadavky → Hodnocení v %**.
Procentní rubriku převzít, je to hotový a funkční systém.

### Úroveň A – rozjezd (téma 02–03)

| Úloha | Zadání ve zkratce | Nové proti 2. ročníku |
|---|---|---|
| tlačítko a LED (pull-down) | stisk = svítí, uvolnění = nesvítí | pull-down/pull-up, negace vstupu |
| LED zapnout tlačítkem 1, zhasnout tlačítkem 2 | SR klopný obvod; současný stisk nic nemění | dva vstupy, priorita |
| LED ovládaná jedním tlačítkem (toggle) | 1 stisk rozsvítí, další zhasne | **detekce náběžné hrany + `static`** |

### Úroveň B – hrany a počítání (téma 03–04)

| Úloha | Zadání ve zkratce | Rubrika |
|---|---|---|
| LED na 3 stisky | rozsvítí se po 3 krátkých stiscích, zhasne po dalších 3 | 40/30/30 |
| tlačítko s LED – 5 bliknutí | stisk → 5× blikne (500/500 ms), další stisk přeruší; `delay()` zakázán | 25/25/20/30 |

### Úroveň C – neblokující časování a stavový automat (téma 04–05)

| Úloha | Zadání ve zkratce | Rubrika |
|---|---|---|
| blikačka s různými režimy | 3 režimy přepínané krátkým stiskem (500/500, 500/250, trvale), držení >3 s vypne | – |
| LED s plynulou změnou jasu | 1 s náběh → 2 s svítí → 1 s doběh → 1 s tma, cyklicky; `delay()` zakázán | 30/20/30/20 |
| plynulá změna intenzity LED s potenciometrem | cyklus spouštěn tlačítkem, rychlost kroku 10–100 ms dle potenciometru, cyklus lze přerušit | 10/30/40/20 |

### Úroveň D – analogové vstupy a převod (téma 07)

| Úloha | Zadání ve zkratce | Rubrika |
|---|---|---|
| LED s řízenou intenzitou | tlačítko toggluje LED, potenciometr řídí jas | 20/20/40/20 |
| blikání řízené potenciometrem | krajní polohy = 20 ms a 2 s ON/OFF, lineární převod | – |
| funkce `hlasitost_na_pocet_znaku(int h)` | doplnit tělo funkce: 0–100 → 0–16 | – |

### Úroveň E – sériová linka (téma 08–09)

| Úloha | Zadání ve zkratce | Rubrika |
|---|---|---|
| blikání LED přes UART | znak `.` → LED na 1 s zhasne | – |
| rotující znak v sériovém monitoru | 10 pozic, `+` se posouvá 2×/s, přijatý znak a–z ho nahradí a resetuje animaci; `delay()` zakázán | 20/20/10/25/25 |
| detekce konce věty | UART 9600, buffer 32 znaků, při `.` `?` `!` pošle větu zpět | – |
| blikání LED ovládané přes UART | počet bliknutí 1–5 zadaný z PC, jiné ignorovat, během blikání ignorovat příjem | – |
| parsování čísla | PC posílá `Cislo:X`, Arduino extrahuje `int`, na násobky 3 odpovídá | – |
| **Morseův kód** (dobrovolný DÚ) | 19200 Bd, `.` = 1 jednotka, `-` = 3, mezera 1, jednotka 100 ms, max 6 znaků, ukončeno `/`, `delay()` zakázán, po dokončení hlášení do PC | 20/40/30/10 |

### Úroveň F – periferie (téma 10–14)

| Úloha | Zadání ve zkratce | Rubrika |
|---|---|---|
| ovládání serva přes sériovou linku | 19200 Bd, `+`/`−` po 1°, omezení 0–180, hlášení krajní polohy | 10/10/30/30/20 |
| ovládání serva enkoderem | enkodér polohuje servo, tlačítko uloží 2 polohy, pak cyklování s periodou 2 s | 40/30/30 |
| RGB LED tlačítkem (dobrovolný) | pilový průběh intenzity, tlačítko cykluje barvy | – |
| tachometr | 2 tlačítka (pull-down) simulují pulzy kola ⌀72 cm; měří dráhu (km) a rychlost (km/h), reset | 40/40/10/10 |
| enkodér jako senzor polohy (dobrovolný) | KY-040 na pinech 2/3, 20 pulzů/otáčku, kolo ⌀72 cm, jednosměrný přírůstek, rozsah ≥1000 m | – |
| krokový motor s tlačítky | ±10 kroků, 10 kroků/s, průběžné přičítání během pohybu, oba stisky = stop a nulování; `Stepper.h` i `delay()` zakázány | 30/30/20/20 |
| krokový motor s joystickem | pásmo necitlivosti, plynulá regulace 0–0,5 ot/s, výpis ot/min 5×/s | 30/20/30/20 |
| polohování krokového motoru | 200 kroků/ot., tlačítka CW/CCW po 1/4 otáčky, stisk během pohybu nesmí rušit, oba >3 s = návrat do výchozí polohy | 20/20/20/40 |
| krokový motor jako zobrazovač času | stopky 200 s/otáčku, START/STOP jedním tlačítkem, RESET držením >3 s i za běhu | 25/10/10/15/10/20/10 |
| LCD displej s potenciometrem | znak `#` se pohybuje po zadané trajektorii podle potenciometru | 30/30/40 |
| **LCD postřehová hra** | `O` jezdí po spodním řádku 1 pole/100 ms, `I` se generuje náhodně na horním řádku po 2 s, trefa tlačítkem → `WINNER`; `delay()` zakázán | 35/35/30 |

---

## 2. Opakující se prvky zadání – převzít jako standard

- **`delay()` není povolena** – objevuje se v naprosté většině úloh vyšší úrovně.
  Je to hlavní didaktická osa 3. ročníku.
- **Knihovna je zakázána** (`Stepper.h`) tam, kde se má pochopit princip.
- **Konkrétní piny v zadání** (LED pin 3 nebo 13, tlačítko pin 2, potenciometr A0,
  enkodér 2/3, servo 5) – usnadňuje kontrolu a hromadné hodnocení.
- **Procentní rubrika** rozdělená na 3–7 položek, součet 100 %.
- **Hraniční chování** v každém zadání (co se stane při současném stisku,
  při dosažení krajní polohy, při příchodu dalšího znaku během akce).

---

## 3. Banka otázek – co je hotové

| Kategorie | Počet | Typy | Kam v novém plánu |
|---|---:|---|---|
| platforma Arduino a vlastnosti UNO | 16 | multichoice, truefalse, numerical | 01 |
| základy arduina (části desky) | 4 | ddimageortext | 01 |
| digitální vstupy | 8 | ddimageortext (pull-up/pull-down zapojení), multichoice | 03 |
| digitální výstupy | 1 | multichoice | 02 |
| tlačítko + LED (logika stavů) | 11 | multichoice | 03 |
| analogové vstupy | 15 | numerical, **calculated** (napětí ↔ dílky) | 07 |
| analogové výstupy | 1 | numerical (doba zapnutí PWM) | 07 |
| sériová linka | 21 | multichoice, numerical (rámec, parita, piny, ASCII) | 08 |
| délka bitu | 1 | numerical | 08 |
| velikost datových typů | 6 | numerical | opakování |
| deklarace pole | 6 | shortanswer | 09 |
| `if` | 2 | shortanswer | opakování |
| přerušení | 13 | multichoice, **ddwtos** (doplňování inicializace) | 12 |
| servo | 21 | numerical, multichoice, match, essay | 10 |
| H-můstek | 6 | multichoice | 11 |
| ovládání (směr proudu, rotace) | 4 | multichoice | 11 |
| stejnosměrný motor | 7 | multichoice | 11 |
| krokový motor | 12 | multichoice, ddimageortext, numerical | 11 |
| I2C | 9 | multichoice, numerical | 13 |
| adresy I2C | 5 | multichoice | 13 |
| master/slave | 2 | shortanswer | 13 |
| LED + potenciometr (doplňování kódu) | 4 | **ddwtos** | 07 |

**Silné stránky banky:** `calculated` otázky pro ADC (nekonečně variant),
`ddimageortext` pro zapojení a části desky, `ddwtos` pro doplňování kódu.
Tyto typy stojí za to zachovat – jsou pracné vyrobit, ale výborně fungují.

**Díry v bance:** millis()/neblokující časování, zákmity, stavové automaty,
funkce a hlavičkové soubory, LCD (kategorie neexistuje), pole/řetězce v Arduinu.

---

## 4. Teoretické texty v 3EA, které stojí za zachování

| Stránka | Obsah | Kam |
|---|---|---|
| základní vlastnosti digitálních vstupů | logické úrovně, toleranční pásma 0,3·Vcc / 0,6·Vcc, Schmittův KO, proč pull-up/pull-down a jaká hodnota (jednotky kΩ), detekce hrany, `static` | **03** – nejlepší text v celém kurzu, převzít celý |
| základní vlastnosti I2C sběrnice | single-ended, bus topologie, master-slave, SDA/SCL, otevřený kolektor + pull-up 2–10 kΩ, 128 zařízení, 400 pF, 100/400 kHz, rámec zprávy, I3C | **13** |
| Příklad 1–3 (analogové vstupy) | 4,9 mV/dílek, čtení potenciometru, **odvození lineárního převodu přes podobnost trojúhelníků**, včetně upozornění na nedostatek `delay()` | **07** |
| Ovládání Arduina slovními příkazy | `String`, `trim()`, `equals()`, `startsWith()`, `substring().toInt()`, sběr znaků do příkazu po `\n` | **09** |
| instalace nástrojů pro I2C a LCD | I2CScanner by Luis Llamas, LiquidCrystal I2C by Frank de Brabander 1.1.2 | **13/14** |
| vodováha (MPU-6050 + LCD) | hotový program s `atan()`, bargraf na LCD | **13** – dobrý námět na projekt |
| návod pro Tinkercad | postup práce se simulátorem | **01** – záloha pro chybějící HW |
| dekompilace HEX kódu | `objdump -S ...elf` | volitelné rozšíření k 01 |

---

## 5. Klasifikace ze starého 3EA kurzu

| Prostředek | Váha (bodů) |
|---|---:|
| opakovací (kontrolní) test | 50 |
| ústní zkoušení | 30–40 |
| samostatná práce (programování) | 20–30 |
| test | 10–15 |
| doplňující klasifikace | 5 |

Stupnice: 1 = 100–92,5 %, 1− = 92,5–85, 2 = 85–77,5, 2− = 77,5–70,
3 = 70–62,5, 3− = 62,5–55, 4 = 55–47,5, 4− = 47,5–40, 5 = pod 40 %.

> Pozn.: `plan/tematicky_plan.md` má jiný model (procentní váhy složek).
> Rozhodnout, který platí – tento vážený bodový je konzistentní se školou.

---

## 6. Vytažené učitelské soubory

`zdroje/kod_3ea/`
- `veta.ino` – buffer 32 znaků, detekce konce věty (téma 09)
- `blikani.ino` – blikání bez `delay()` řízené přes UART (téma 04/08)
- `enkoder.ino` – čtení enkodéru bez přerušení (téma 12)
- `servo_ovladane_enkoderem.ino` – enkodér → servo (téma 10+12)
- `lcd_displej_s_tlacitkem.ino` – LCD I2C + tlačítko, časování přes `millis()` (téma 14)
- `potenciometr_test.ino` – potenciometr → LCD (téma 07+14)
- `test3.ino` – parsování příkazu ze `String` (téma 09)

`zdroje/schemata/`
- `Arduino_Uno_Rev3-schematic.pdf`, `arduino-uno-schematic.pdf`
- `rgb_led_s_tlacitkem.pdf`, `Prg - analogové výstupy.pdf`

`zdroje/prezentace_2ea/` – prezentace 01–07 z 2. ročníku, `ArduinoPriruckaProgramatora.pdf`
a archivy zdrojových kódů k tématům proměnné / podmínky / cykly.
