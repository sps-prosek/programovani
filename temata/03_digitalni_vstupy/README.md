# 03 – Digitální vstupy: tlačítka, pull-up, zákmity

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – digitální vstupy
**Výsledky vzdělávání:** V4, V5
**Učivo:** U4, U8, U17

## Návaznost na 2. ročník

Podmínky a logické operátory žák zná. Nové je **plovoucí vstup** (na PC nic takového není)
a to, že mechanický kontakt nesepne čistě – s tím se v čistém C nikdy nesetkal.

## Cíle tématu

Žák po probrání tématu:

- vysvětlí, proč nesmí zůstat vstup nezapojený, a zapojí pull-up / pull-down
- použije interní pull-up (`INPUT_PULLUP`) a správně vyhodnotí obrácenou logiku
- načte stav tlačítka a rozliší **úroveň** a **hranu** (náběžná / sestupná)
- popíše zákmity kontaktu a odstraní je softwarově (časové ošetření) i hardwarově (RC)
- ověří zákmity na osciloskopu

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Pin jako vstup, plovoucí vstup, pull-up a pull-down, interní pull-up. Čtení `digitalRead()`. Detekce hrany: uchování minulého stavu. | Program reaguje na stisk (hrana), ne na držení (úroveň). |
| 2 | Zákmity kontaktu – ukázka na osciloskopu, počítadlo stisků bez ošetření. Softwarový debounce s `millis()`, hardwarový RC filtr. Přepínání stavu LED stiskem. | Počítadlo stisků počítá správně, řešení funguje i při rychlém mačkání. |

## Klíčové pojmy

digitální vstup, plovoucí vstup, pull-up / pull-down, `INPUT_PULLUP`, `digitalRead`,
úroveň vs. hrana, náběžná / sestupná hrana, zákmity (bounce), debounce, RC filtr

## Navržené úlohy

1. **Hrana místo úrovně** – LED přepne stav při každém stisku (ne bliká, dokud držím).
2. **Počítadlo stisků** – bez ošetření zákmitů a s ním; porovnat naměřený počet.
3. **Dvě tlačítka** – jedno zvyšuje, druhé snižuje jas / rychlost blikání.
4. **Dlouhý a krátký stisk** – krátký stisk přepne LED, dlouhý (nad 1 s) ji rozbliká.

## Ověření měřením (U17)

Osciloskopem zobrazit stisk tlačítka a změřit dobu trvání zákmitů. Naměřenou hodnotu
použít jako konstantu v softwarovém debounce – žák si tak odvodí, proč zrovna 20–50 ms.

## HW a SW

Mikrotlačítka, rezistory 10 kΩ, kondenzátor 100 nF, LED, osciloskop.

## Starší podklady k tomuto tématu

- `3EA/nabezna_hrana/` – detekce hrany
- `3EA/tlacitko/debounce/` – včetně `README.MD` a `wiring.png` → `obrazky/`
- `3EA/nabezna_hrana_s_funkci/` – použít až v bloku 06 jako ukázku refaktoringu

## Poznámky k výuce

<!-- Obrácená logika u INPUT_PULLUP je nejčastější zdroj zmatku – nechat žáky vypsat stav do sériové linky. -->
