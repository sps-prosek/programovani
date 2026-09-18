# 01 – HW platformy a vývojové prostředí

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** téma *HW platformy* (4 h) celé + úvodní část tématu *Elektronické obvody s mikroprocesorem*
**Výsledky vzdělávání:** V1, V2, V3
**Učivo:** U1, U2, U3, U5, U6, U7, U15 (zavedení)

## Návaznost na 2. ročník

Žák umí napsat, přeložit a odladit program v C na PC. Zná strukturu zdrojového kódu,
proměnné, datové typy a práci s pamětí. **Nezná** rozdíl mezi programem pro PC
a programem pro mikrokontroler – to je hlavní obsah tohoto bloku.

## Cíle tématu

Žák po probrání tématu:

- vysvětlí, co je hardwarová platforma a proč se stejný program nepřeloží pro každý procesor
- porovná architektury AVR a ARM a uvede přednosti a omezení obou
- popíše cestu od zdrojového kódu k programu v paměti mikrokontroleru (preprocesor, překlad, linkování, `.hex`, nahrání)
- rozliší nahrávání přes bootloader a přes ICSP a uvede, kdy se které používá
- popíše rozdělení paměti ATmega328P (Flash / SRAM / EEPROM) a řekne, co kam patří
- přeloží a nahraje skicu v Arduino IDE, najde chybu v hlášení překladače
- založí si repozitář, provede `commit` a `push` svojí první skici

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Co je mikrokontroler a čím se liší od PC. Architektury procesorů, AVR vs. ARM (šířka slova, periferie, spotřeba, cena, vývojové nástroje), kde se která používá. Rozdělení paměti ATmega328P. Deska UNO/Nano, popis pinů, napájení. | Vybere vhodnou platformu pro zadanou úlohu a rozhodnutí zdůvodní. Řekne, kolik má UNO Flash a SRAM a co je v které paměti. |
| 2 | Arduino IDE a alternativy (Arduino CLI, PlatformIO, VS Code). Struktura skici `setup()` / `loop()`, co dělá překladač „navíc“ oproti čistému C. Kompilace, `.hex`, nahrání přes bootloader vs. ICSP. Sériový monitor. Git: klon repozitáře s ukázkami, vlastní repozitář, `commit`, `push`. | Přeloží a nahraje skicu, změní parametr, odchytí chybu v překladu. Odevzdá první commit. |

## Klíčové pojmy

architektura procesoru, AVR, ARM, Harvardská vs. von Neumannova architektura, Flash, SRAM,
EEPROM, překlad, linkování, `.hex`, bootloader, ICSP, `setup()`, `loop()`, skica, repozitář, commit

## Navržené úlohy

1. **Porovnání platforem** – tabulka AVR (ATmega328P) vs. ARM (STM32 / RP2040): frekvence, paměti, napájení, cena, periferie. Ke každému řádku jedna věta, kdy to rozhoduje.
2. **První skica** – rozblikat vestavěnou LED na pinu 13, změnit periodu, ověřit, co je v `setup()` a co v `loop()`.
3. **Kde je chyba** – žák dostane skicu se třemi chybami (chybějící `;`, nedeklarovaná proměnná, špatný typ) a opraví ji podle hlášení překladače.
4. **Paměťový rozpočet** – z výpisu překladače přečíst využití Flash a SRAM, přidat velké pole a sledovat, co se stane.

## Ověření měřením (U17)

Změřit napětí na napájecích pinech desky (5 V, 3,3 V, VIN) a ověřit, že deska je napájená
podle očekávání. Zavést pravidlo: **před připojením čehokoliv nejdřív změřit.**

## HW a SW

Arduino UNO/Nano + USB kabel, multimetr. Arduino IDE 2.x, ovladač CH340 u klonů, git.

## Starší podklady k tomuto tématu

- `3EA/init/init.ino` – v `_archiv/`, přenést do `kod/` jako kostru skici

## Materiály

- `prezentace/prezentace.tex` – **část 1 ze 2**: učivo U1 a U2, zavedení U5, U6, U7.
  28 slidů na 45 minut. Přehledové téma – každý slide nese jednu myšlenku,
  záměrně spíš víc krátkých slidů než jeden nabitý.
  TikZ schémata: cesta kódu od `.ino` do Flash, harvardská architektura ×
  jednotný adresní prostor, paměťová mapa ATmega328P ve správném měřítku,
  nahrávání přes bootloader × ICSP.
  Slide „Čipy zblízka“ je rezerva – při zpoždění se vypustí.
- Část 2 (Arduino IDE a alternativy, první přeložená a nahraná skica, git a první
  `commit`) zatím **není napsaná**.

### Klíčové snímky

Prostředí `keyframe` (červený pruh vlevo) je v této prezentaci vyhrazené pro
snímky, které drží strukturu hodiny. Dělicí snímky sekcí jsou proto vypnuté
(`\SPSSectionSlidesOff`); `\section` zůstává jen pro záložky v PDF.

| Slide | Klíčový snímek |
|---:|---|
| 2 | Co dnes zvládneme – cíle hodiny |
| 4 | Část 1 (U1): co se dozvíte |
| 18 | Shrnutí části 1 (U1) |
| 19 | Část 2 (U2): co se dozvíte |
| 28 | Shrnutí hodiny – závěr a co příště |

### Rozdělení učiva mezi obě části

| Část | Učivo |
|---|---|
| 1 (hotová) | U1, U2, dále U5 (kompilace a křížový překlad), U6 (bootloader, ICSP), U7 (Flash / SRAM / EEPROM) |
| 2 (chybí) | U3 (Arduino IDE a alternativy), U15 (git – zavedení), praktické ověření U5 a U17 (měření napájecích napětí desky) |

## Obrázky

Všechny čtyři jsou **dodané** a v prezentaci se sázejí (stav k 18. 9. 2026).
Přípona se do makra `\obrazek` nepíše – přijímá se `.pdf`, `.png` i `.jpg`.
Kdyby soubor chyběl, vysází se místo obrázku šedý rámeček s popisem, takže
prezentace jde přeložit i bez nich.

| Soubor | Co je na obrázku |
|---|---|
| `01_kde_jsou_mcu` | Koláž „kde všude je mikrokontroler“: pračka, myš, klíček od auta, elektrokolo, nabíječka, ovladač televize |
| `02_rodina_desek` | Fotografie desek vedle sebe ve stejném měřítku: Arduino UNO, Arduino Nano, Raspberry Pi Pico, STM32 „Blue Pill“, ESP32 |
| `03_cipy_avr_arm` | Fotografie čipů vedle sebe: ATmega328P v patici DIP-28 a čip ARM v pouzdře LQFP, stejné měřítko |
| `04_deska_uno_popis` | Deska Arduino UNO s vyznačenými částmi: ATmega328P, převodník USB-UART, krystal 16 MHz, stabilizátor 5 V, konektor ICSP, tlačítko RESET, LED na pinu 13 |

Blokové schémata (cesta kódu, architektury pamětí, paměťová mapa, bootloader ×
ICSP) jsou nakreslená přímo TikZem v prezentaci – ty se nedodávají. Celé schéma
desky je v `zdroje/schemata/arduino_uno_rev3_schematic.pdf`, ale na slide je
příliš podrobné; hodí se spíš jako ukázka „takhle vypadá reálné schéma“.

**Po přidání nebo výměně obrázku je potřeba vynutit překlad:**
`latexmk -g -xelatex prezentace.tex`. Latexmk chybějící soubor nezná jako
závislost, takže bez `-g` usoudí, že je PDF aktuální, a obrázek se do něj
nedostane.

## Poznámky k výuce

<!-- Co žákům dělalo problém, co příště udělat jinak, časový odhad. -->
