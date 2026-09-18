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

## Poznámky k výuce

<!-- Co žákům dělalo problém, co příště udělat jinak, časový odhad. -->
