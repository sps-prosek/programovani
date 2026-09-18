# Tematický plán – Programování, 3. ročník (Mechatronika)

**Školní rok:** 2026/2027
**Obor:** 26-41-M/01 Elektrotechnika, ŠVP Mechatronika (SPŠ na Proseku, platnost od 1. 9. 2024)
**Dotace podle ŠVP:** 2 h týdně, praktické vyučování, **64 hodin v ročníku**
**Plánovaná náplň:** **50 hodin = 25 dvouhodinovek**; zbylých 14 h je rezerva na odpadlé
hodiny (svátky, exkurze, projektové dny, nemoc), dopsání testů a dokončení projektů.

## Co ŠVP předepisuje pro 3. ročník

| ŠVP téma | Hodin dle ŠVP | Pokrývají bloky |
|---|---:|---|
| HW platformy | 4 | 01 |
| Elektronické obvody s mikroprocesorem (Arduino) | 60 | 02–16 |

### Výsledky vzdělávání (žák)

| Kód | Výsledek vzdělávání |
|---|---|
| V1 | seznámí se s problematikou tvorby programů pro různé platformy hardware |
| V2 | pracuje v základním programovacím prostředí |
| V3 | rozumí principu kompilace zdrojového kódu |
| V4 | nakonfiguruje základní části mikroprocesoru v rámci programu |
| V5 | zapojí obvod s mikroprocesorem |
| V6 | ovládá vytváření jednoduchých knihoven pro danou platformu |
| V7 | používá základní funkce systému správy verzí |
| V8 | navrhuje a realizuje program pro zadaný komplexní projekt |

### Učivo

| Kód | Učivo |
|---|---|
| U1 | možnosti tvorby programů pro různé hardwarové platformy (architektury procesorů) |
| U2 | vybrané platformy (ARM, AVR) a jejich přednosti a omezení |
| U3 | programovací prostředí (Arduino IDE a jeho alternativy) |
| U4 | zapojení elektrické části zařízení dle schématu |
| U5 | kompilace zdrojového kódu |
| U6 | metody nahrávání programu (bootloader, ICSP) |
| U7 | rozdělení paměti |
| U8 | digitální vstupy a výstupy (připojení el. prvků) |
| U9 | analogové vstupy a výstupy (připojení el. prvků) |
| U10 | časovače |
| U11 | přerušení |
| U12 | komunikační sběrnice (UART, I2C, SPI) |
| U13 | možnosti připojení periférií |
| U14 | vytváření knihoven |
| U15 | systémy správy verzí (např. git) |
| U16 | komplexní projekty |
| U17 | ověřování zapojení dle měření |

## Na co se navazuje – Programování ve 2. ročníku (70 h)

| Blok 2. ročníku | Co si žák přináší |
|---|---|
| Úvod do programování (8 h) | formulace úlohy, dekompozice, algoritmus a vývojový diagram, porovnání algoritmů |
| Základy programování (22 h) | jazyk C: struktura zdrojového kódu, proměnné, řídicí struktury (podmínky, cykly, `switch`), formátovaný vstup/výstup, knihovny funkcí, ladění, druhy chyb, testování |
| Programování (40 h) | pole (i vícerozměrná), funkce (deklarace, definice, parametry, návratová hodnota), **vlastní knihovna funkcí**, **ukazatele**, **struktury**, **makra preprocesoru**, práce s pamětí (alokace, typová konverze), parametry příkazové řádky |

**Důsledek pro 3. ročník:** syntaxi jazyka C už neučíme. Žák zná funkce, pole, ukazatele
i strukturu vlastní knihovny – ve 3. ročníku se učí, **jak se tyto prostředky chovají
na mikrokontroleru** (omezená SRAM, žádné dynamické alokace, program bez konce, sdílení
proměnných s obsluhou přerušení) a **jak se program propojí s reálným hardwarem**.
Proto jsou bloky 06, 09 a 15 oproti běžnému rozvržení zkrácené – slouží jen k přenesení
známé látky do nového kontextu, ne k jejímu výkladu od začátku.

Co je oproti PC nové a je třeba na to upozornit hned v bloku 01:
program neskončí (`loop()`), není `printf` na obrazovku ani klávesnice, není operační systém,
paměť se počítá v kilobajtech, `int` má 16 bitů, `malloc()` se nepoužívá,
chyba se neprojeví výjimkou, ale tím, že se deska „zasekne“ nebo restartuje.

## Rozvržení – 25 dvouhodinovek

| # | Téma | Hodin | Bloků | Kumul. | Období | ŠVP: V | ŠVP: U |
|---|---|---:|---:|---:|---|---|---|
| 01 | HW platformy a vývojové prostředí | 4 | 2 | 4 | září | V1, V2, V3 | U1, U2, U3, U5, U6, U7, U15 |
| 02 | Digitální výstupy – LED a bzučák | 2 | 1 | 6 | září | V5 | U4, U8, U17 |
| 03 | Digitální vstupy – tlačítka, pull-up, zákmity | 4 | 2 | 10 | říjen | V4, V5 | U4, U8, U17 |
| 04 | Časování bez `delay()` – `millis()` a časovače | 4 | 2 | 14 | říjen–listopad | V4 | U10, U8 |
| 05 | Stavové automaty – cyklistická blikačka | 4 | 2 | 18 | listopad | V4, V8 | U8, U10 |
| 06 | Funkce a strukturování kódu | 2 | 1 | 20 | prosinec | V6 | U14 |
| 07 | Analogové vstupy a PWM | 4 | 2 | 24 | prosinec–leden | V4, V5 | U4, U9, U17 |
| 08 | Sériová linka (UART) | 2 | 1 | 26 | leden | V4 | U12 |
| 09 | Pole a řetězce – parsování příkazů | 2 | 1 | 28 | únor | V4 | U7, U12 |
| 10 | Modelářské servo | 2 | 1 | 30 | únor | V5 | U4, U9, U13 |
| 11 | DC motor a H-můstek | 2 | 1 | 32 | březen | V5 | U4, U9, U13, U17 |
| 12 | Přerušení a inkrementální enkodér | 4 | 2 | 36 | březen–duben | V4 | U11, U13, U17 |
| 13 | Sběrnice I2C a SPI, senzory | 4 | 2 | 40 | duben | V4, V5 | U4, U12, U13 |
| 14 | LCD displej | 2 | 1 | 42 | květen | V5 | U4, U12, U13 |
| 15 | Vlastní knihovny a správa verzí | 2 | 1 | 44 | květen | V6, V7 | U14, U15 |
| 16 | Závěrečný projekt | 6 | 3 | 50 | květen–červen | V8 | U4, U16, U17 |

**Rezerva 14 h** (do 64 h dle ŠVP): odpadlé hodiny, opakovací a testové hodiny,
dokončení a obhajoby závěrečných projektů, případné prohloubení bloků 05, 12 a 13,
pokud třída stíhá.

## Kontrola pokrytí ŠVP

Každý výsledek vzdělávání i každá položka učiva má přiřazený alespoň jeden blok:

| Kód | Bloky |
|---|---|
| V1 | 01 |
| V2 | 01, průběžně |
| V3 | 01 |
| V4 | 03, 04, 05, 07, 08, 09, 12, 13 |
| V5 | 02, 03, 07, 10, 11, 13, 14, 16 |
| V6 | 06, 15 |
| V7 | 01 (zavedení), 15 (systematicky), průběžně |
| V8 | 05, 16 |
| U1, U2 | 01 |
| U3, U5, U6, U7 | 01 (U7 znovu v 09 – řetězce v SRAM, `F()`, `PROGMEM`) |
| U4 | 02, 03, 07, 10, 11, 13, 14, 16 |
| U8 | 02, 03, 04, 05 |
| U9 | 07, 10, 11 |
| U10 | 04, 05 |
| U11 | 12 |
| U12 | 08, 09 (UART), 13 (I2C, SPI), 14 |
| U13 | 10, 11, 12, 13, 14 |
| U14 | 06, 15 |
| U15 | 01, 15, průběžně |
| U16 | 16 (příprava už v 05) |
| U17 | 02, 03, 07, 11, 12, 16 |

## Logika posloupnosti

Bloky 01–06 staví jádro, které se pak už jen používá:
platforma a nástroje → výstup → vstup → neblokující časování → stavový automat → funkce.
Od bloku 07 se přidávají periferie a **každá nová periferie se cvičí na už zvládnuté
struktuře programu, ne na `delay()`**. Jakmile žák v bloku 05 napíše stavový automat,
vrací se k němu ve všech dalších úlohách.

Bloky 10–14 jsou vzájemně relativně nezávislé – pořadí lze podle dostupnosti sad HW
zaměnit. Blok 15 lze zařadit dřív, jakmile je potřeba rozdělit rozsáhlejší program.

## Průběžné (průřezové) prvky

Neučí se jako samostatný blok, ale opakují se v každé praktické hodině:

- **Zapojení dle schématu (U4):** ke každé úloze je schéma; žák zapojuje podle něj, ne podle fotky.
- **Ověření měřením (U17):** multimetr a osciloskop na stole od bloku 02.
  Proud LED, zákmity tlačítka, střída PWM, signály A/B enkodéru, hodiny I2C/SPI.
- **Správa verzí (U15):** žák si od bloku 01 vede vlastní repozitář a každou hotovou úlohu
  commituje; odevzdání do Moodle je odkaz na commit nebo export skici.
- **Bezpečnost a ochrana HW:** oddělené napájení pohonů, společná zem, nepřipojovat
  induktivní zátěž přímo na pin.

## Hodnocení

| Složka | Váha | Poznámka |
|---|---:|---|
| Průběžné úlohy na cvičení (funkční kód) | 40 % | odevzdání do Moodle, hodnotí se funkčnost + čitelnost + zapojení dle schématu |
| Krátké testy k tématům | 20 % | Moodle, banka otázek v `temata/*/moodle/otazky.gift` |
| Domácí úlohy | 15 % | |
| Závěrečný projekt | 25 % | funkčnost, dokumentace, obhajoba |

## Očekávané výstupy za ročník

Žák popíše rozdíly mezi hardwarovými platformami (AVR, ARM) a vysvětlí, proč se program
pro mikrokontroler píše jinak než pro PC. Samostatně navrhne, zapojí a naprogramuje
jednoduché mechatronické zařízení s mikrokontrolerem: ovládá digitální i analogové vstupy
a výstupy, používá neblokující časování, přerušení a stavový automat, komunikuje po sériové
lince, po I2C a rámcově rozumí SPI, řídí servo a DC motor, obslouží LCD displej, rozdělí
program do funkcí a vlastní knihovny, ověří zapojení měřením a svou práci vede v systému
správy verzí.

---

# Dodatek – dostupnost materiálu (revize 18. 9. 2026)

Doplněno po inventuře Moodle záloh kurzů 2EA a 3EA. Podrobnosti:
`plan/vstupni_znalosti_2ea.md` a `plan/kalibrace_uloh_3ea.md`.

## Co je k jednotlivým blokům už hotové

| # | Teorie / výklad | Testové otázky | Zadání úloh |
|---|---|---|---|
| 01 | Tinkercad návod, schémata UNO, dekompilace HEX | ✅ 20 (platforma, části desky) | ❌ |
| 02 | ❌ | ⚠️ 1 | ⚠️ |
| 03 | ✅ **výborný text** (log. úrovně, toleranční pásma, Schmitt, pull-up/down, detekce hrany, `static`) | ✅ 19 (vč. ddimageortext zapojení) | ✅ 5 |
| 04 | ❌ | ❌ | ✅ 2 |
| 05 | ❌ | ❌ | ✅ 2 (blikačka s režimy, plynulá změna jasu) |
| 06 | ❌ | ❌ | ✅ 1 (doplnění těla funkce) |
| 07 | ✅ Příklady 1–3 vč. odvození lineárního převodu | ✅ 20 (**calculated** napětí ↔ dílky) | ✅ 5 |
| 08 | ❌ | ✅ 22 (rámec, parita, start/stop bit, ASCII) | ✅ 4 (vč. Morseovky) |
| 09 | ✅ „Ovládání Arduina slovními příkazy“ + `veta.ino`, `test3.ino` | ✅ 6 (deklarace pole) | ✅ 3 |
| 10 | ❌ | ✅ 21 | ✅ 2 |
| 11 | ❌ | ✅ 29 (H-můstek, DC motor, **krokový motor**) | ✅ 4 (krokový motor) |
| 12 | ✅ `enkoder.ino`, `servo_ovladane_enkoderem.ino` | ✅ 13 (**ddwtos** doplňování inicializace) | ✅ 2 |
| 13 | ✅ text o I2C + vodováha (MPU-6050) | ✅ 16 (vlastnosti, adresace, master/slave) | ⚠️ |
| 14 | ✅ `lcd_displej_s_tlacitkem.ino`, `potenciometr_test.ino` | ❌ | ✅ 2 (LCD hra, LCD s potenciometrem) |
| 15 | ❌ | ❌ | ❌ |
| 16 | – | – | – |

**Priorita výroby:** bloky **04, 05, 06** (ze starého kurzu není nic použitelného,
a přitom nesou hlavní didaktickou osu ročníku), pak **02**, pak **14** (chybí otázky),
nakonec **15**.

## Nesoulad: krokový motor

Blok 11 je v rozvržení *DC motor a H-můstek* (2 h). Starý kurz 3EA má ke **krokovému
motoru** 12 testových otázek (unipolární/bipolární, wave drive, full-step, half-step,
typy rotoru) a **4 propracované samostatné práce** – polohování po 1/4 otáčky,
stopky, řízení joystickem, řízení tlačítky, všechny se zákazem `Stepper.h` i `delay()`.
Je to obsahově nejsilnější hotový materiál v celém kurzu.

Možnosti:
1. rozšířit blok 11 na 4 h (2 dvouhodinovky) z rezervy 14 h – *doporučeno*;
2. zařadit krokový motor jako jedno z témat závěrečného projektu (blok 16);
3. vypustit a otázky z banky nepoužít.

## Nesoulad: ukazatele a vlastní knihovna ve 2. ročníku

ŠVP uvádí pro 2. ročník ukazatele, struktury, makra i vlastní knihovnu funkcí.
**Moodle kurz 2EA to nepotvrzuje:** ukazatele a dynamická alokace se neobjevují ani
v otázkách k zapamatování, ani v žádné ze sedmi domácích úloh. K blokům
„Funkce a struktury“ a „Základy mikropočítačů“ navíc v kurzu **chybí prezentace**.

→ Před blokem 06 a 15 ověřit skutečný stav krátkým vstupním testem; nespoléhat
na to, že ukazatele a vlastní knihovna jsou odučené.

## Zákaz `delay()`

Ve starých zadáních je explicitně u prakticky každé netriviální úlohy
(„Funkce delay() není povolena“), stejně jako zákaz `Stepper.h` tam, kde má žák
pochopit princip. Převzít jako standardní formulaci zadání od bloku 04 dál.

## Hodnocení – k rozhodnutí

Tabulka výše používá procentní váhy složek. Starý kurz 3EA i kurz 2EA používají
**bodové klasifikační prostředky školy** (kontrolní test 50, ústní zkoušení 30–40,
samostatná práce 20–30, test 10–15, doplňující 5) a stupnici po 7,5 %.
Sjednotit – návrh v `plan/moodle_sablona.md`.
