# 07 – Analogové vstupy a PWM

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – analogové vstupy a výstupy
**Výsledky vzdělávání:** V4, V5
**Učivo:** U4, U9, U17

## Návaznost na 2. ročník

Celočíselná a reálná aritmetika, typové konverze a přetypování jsou ze 2. ročníku známé –
tady se poprvé ukáže, **proč na tom záleží**: `(x * 5) / 1023` v `int` přeteče,
dělení celých čísel uřízne desetinnou část.

## Cíle tématu

Žák po probrání tématu:

- popíše princip A/D převodníku, jeho rozlišení (10 bitů) a referenční napětí
- přečte hodnotu z `analogRead()` a převede ji na napětí ve voltech bez chyby přetečení
- vysvětlí, že „analogový výstup“ Arduina je **PWM**, ne skutečné analogové napětí
- nastaví střídu `analogWrite()`, vysvětlí pojmy perioda, střída, frekvence PWM
- zapojí potenciometr a fotorezistor jako dělič napětí podle schématu
- ověří střídu PWM osciloskopem a porovnám ji s nastavenou hodnotou

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | A/D převodník: rozlišení, reference, vzorkování. `analogRead()`, převod na napětí, `map()` a `constrain()`. Dělič napětí, potenciometr, fotorezistor. Typové pasti při přepočtu. | Potenciometrem plynule mění hodnotu vypisovanou do sériového monitoru ve voltech. |
| 2 | PWM: perioda, střída, frekvence, které piny ji umí a odkud se bere (Timer0/1/2 z bloku 04). `analogWrite()`, řízení jasu LED, nelinearita vnímání jasu. Filtrace PWM RC článkem na skutečné analogové napětí. | Jas LED řízený potenciometrem; na osciloskopu ukáže změnu střídy. |

## Klíčové pojmy

A/D převodník, rozlišení, referenční napětí, `analogRead`, dělič napětí, `map`, `constrain`,
PWM, střída (duty cycle), perioda, `analogWrite`, RC filtr

## Navržené úlohy

1. **Voltmetr** – potenciometr na A0, výpis napětí s přesností na 2 desetinná místa.
2. **Stmívač** – jas LED řízený potenciometrem; přidat plynulý náběh bez `delay()`.
3. **Soumrakový spínač** – fotorezistor sepne LED pod nastavenou úrovní, s hysterezí, aby na hranici nekmital.
4. **Bargraf** – úroveň z analogového vstupu zobrazená pěti LED (příprava na bargraf na LCD v bloku 14).

## Ověření měřením (U17)

Multimetrem změřit napětí na běžci potenciometru a porovnat s hodnotou vypočtenou
z `analogRead()`. Osciloskopem změřit frekvenci a střídu PWM pro `analogWrite(0/64/128/255)`;
za RC filtrem změřit stejnosměrnou složku a porovnat se střídou.

## HW a SW

Potenciometr 10 kΩ, fotorezistor, rezistory, LED, kondenzátor 10 µF, multimetr, osciloskop.

## Starší podklady k tomuto tématu

- `vyuka/LCD displej/vizualizace_hlasitosti/` – bargraf z analogového vstupu (dokončit v bloku 14)

## Poznámky k výuce

<!-- Nejčastější chyba: analogRead() * 5 / 1023 v int. Nechat je na to přijít měřením. -->
