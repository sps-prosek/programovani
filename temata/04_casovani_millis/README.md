# 04 – Časování bez `delay()`: `millis()` a časovače

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – časovače
**Výsledky vzdělávání:** V4
**Učivo:** U10, U8

## Návaznost na 2. ročník

Žák zná cykly a proměnné. Program na PC běžel „odshora dolů a skončil“. Tady program
**nikdy neskončí** a musí zvládat několik dějů najednou – to je pro žáky největší
myšlenkový skok celého ročníku.

## Cíle tématu

Žák po probrání tématu:

- vysvětlí, proč `delay()` blokuje program, a ukáže to na úloze se dvěma rychlostmi blikání
- napíše neblokující časování pomocí `millis()` a vzorce `now - last >= interval`
- zdůvodní, proč se časy porovnávají rozdílem (přetečení `unsigned long` po ~49 dnech)
- popíše hardwarové časovače ATmega328P (Timer0/1/2), k čemu je používá jádro Arduina
- zvolí vhodný datový typ pro čas a periodu (`unsigned long`, ne `int`)

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Proč `delay()` vadí – dvě LED s různou periodou, tlačítko nereaguje během `delay()`. `millis()`, `micros()`, vzorec neblokujícího časování, přetečení a proč rozdíl funguje i po něm. | Dvě LED blikají nezávisle různou rychlostí, tlačítko reaguje okamžitě. |
| 2 | Hardwarové časovače: co je čítač, předdělička, přetečení. Timer0 (`millis`), Timer1, Timer2 a jejich souvislost s `analogWrite()` a `tone()`. Několik nezávislých „úloh“ v jednom `loop()`. | Tři nezávislé děje v jednom programu (blikání, pípání, čtení tlačítka). |

## Klíčové pojmy

`delay()`, blokující vs. neblokující kód, `millis()`, `micros()`, `unsigned long`,
přetečení, čítač, předdělička, Timer0/1/2, perioda, interval

## Navržené úlohy

1. **Dvě periody** – LED1 bliká 200 ms, LED2 1 s, obojí současně a bez `delay()`.
2. **Tlačítko během blikání** – tlačítko musí zabrat do 50 ms i při běžícím blikání; ověřit.
3. **Odpočet** – po stisku tlačítka LED zhasne přesně za 5 s, mezitím program dál pípá.
4. **Přetečení** – simulovat `millis()` blízko přetečení (vlastní proměnná) a ukázat, že vzorec s rozdílem obstojí.

## Ověření měřením (U17)

Osciloskopem změřit skutečnou periodu blikání a porovnat s nastavenou hodnotou;
vysvětlit odchylku (doba běhu `loop()`).

## HW a SW

Dvě LED s rezistory, tlačítko, bzučák, osciloskop.

## Starší podklady k tomuto tématu

- `3EA/cyklisticka_blikacka/rezimy/` – výchozí verze bez přepínání

## Poznámky k výuce

<!-- Kdo tenhle blok nezvládne, neudělá blok 05. Raději zde přidat hodinu z rezervy. -->
