# 06 – Funkce a strukturování kódu

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – vytváření knihoven (příprava)
**Výsledky vzdělávání:** V6 (příprava)
**Učivo:** U14

## Návaznost na 2. ročník

Funkce (deklarace, definice, parametry, návratová hodnota, lokální proměnné) žák **umí
z bloku „Programování“ 2. ročníku**, stejně jako vlastní knihovnu funkcí. Proto je blok
krátký: neučíme funkce, učíme **jak podle nich rozdělit program pro mikrokontroler**
a na co si dát pozor (globální stav, sdílené proměnné, doba běhu funkce v `loop()`).

## Cíle tématu

Žák po probrání tématu:

- rozdělí delší skicu do funkcí tak, aby `loop()` zůstal čitelný
- rozliší, co patří do globální proměnné (stav zařízení) a co má být lokální
- pojmenuje funkce podle toho, co dělají, a napíše k nim hlavičkový komentář
- vyhne se funkci, která v `loop()` „stojí“ (obsahuje `delay()` nebo čekací cyklus)
- refaktoruje cizí kód bez změny chování a ověří, že se chování nezměnilo

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Refaktoring hotové úlohy z bloku 03/05 do funkcí. Parametry místo kopírovaného kódu. Globální stav vs. lokální proměnná. `const` a `#define` pro čísla pinů. Hlavičkový komentář, konvence pojmenování. Krok k vlastní knihovně (blok 15). | Přepsaná úloha z bloku 05 – `loop()` má nejvýše 15 řádků a volá pojmenované funkce. |

## Klíčové pojmy

funkce, parametr, návratová hodnota, lokální vs. globální proměnná, `const`, `#define`,
refaktoring, hlavičkový komentář, jedna funkce = jedna úloha

## Navržené úlohy

1. **Refaktoring blikačky** – vzít vlastní řešení z bloku 05 a rozdělit na funkce `nacti_tlacitko()`, `zmen_rezim()`, `obsluz_led()`. Chování se nesmí změnit.
2. **Funkce s parametrem** – `blikni(pin, pocet, perioda)` místo trojnásobně opsaného kódu.
3. **Čtení cizího kódu** – dostat neroztříděnou skicu a rozdělit ji; porovnat délku `loop()` před a po.

## HW a SW

Beze změny oproti blokům 03–05.

## Starší podklady k tomuto tématu

- `3EA/nabezna_hrana_s_funkci/` – ukázka refaktoringu detekce hrany do funkce
- `vyuka/LCD displej/lcd_displej_s_tlacitkem_pomoci_funkci/` – dobrá ukázka rozdělení do funkcí

## Poznámky k výuce

<!-- Nejde o novou látku, ale o návyk. Od tohoto bloku se čitelnost promítá do známky. -->
