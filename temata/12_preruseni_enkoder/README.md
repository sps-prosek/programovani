# 12 – Přerušení a inkrementální enkodér

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – přerušení, možnosti připojení periférií
**Výsledky vzdělávání:** V4
**Učivo:** U11, U13, U17

## Návaznost na předchozí bloky

Navazuje na hrany a zákmity (blok 03) a na časovače (blok 04). Přerušení je jediné téma
ročníku, kde se program **nevykonává v pořadí, ve kterém je napsaný** – to je pro žáky nové
a je třeba na to dát dvě hodiny navíc.

## Cíle tématu

Žák po probrání tématu:

- vysvětlí, co je přerušení, vektor přerušení a obsluha (ISR), a čím se liší od dotazování (polling)
- nastaví externí přerušení (`attachInterrupt`, `digitalPinToInterrupt`, `RISING`/`FALLING`/`CHANGE`)
- napíše krátkou ISR a ví, co v ní nesmí být (`delay`, `Serial.print`, dlouhý výpočet)
- použije `volatile` u proměnných sdílených s ISR a vysvětlí proč
- ošetří atomické čtení vícebajtové proměnné (`noInterrupts()` / `interrupts()`)
- popíše funkci inkrementálního enkodéru (signály A/B, kvadratura) a určí z nich směr

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Polling vs. přerušení. Vektory, priority, latence. `attachInterrupt()`, pravidla psaní ISR, `volatile`, atomický přístup. Počítadlo impulzů z tlačítka na přerušení. | Počítadlo impulzů běží na přerušení, hlavní smyčka jen vypisuje. |
| 2 | Inkrementální enkodér: disk, signály A a B, kvadratura, určení směru, rozlišení. Čtení bez přerušení a s přerušením – porovnání ztracených kroků. Zákmity enkodéru a RC filtr. | Enkodér otáčením zvyšuje a snižuje hodnotu spolehlivě v obou směrech. |

## Klíčové pojmy

přerušení, ISR, vektor přerušení, latence, polling, `attachInterrupt`, `RISING` / `FALLING` / `CHANGE`,
`volatile`, atomický přístup, inkrementální enkodér, kvadratura, signály A/B

## Navržené úlohy

1. **Počítadlo na přerušení** – impulzy z tlačítka; porovnat se stejnou úlohou řešenou pollingem při vytížené smyčce.
2. **Enkodér bez přerušení** – ukázat ztrátu kroků při rychlém otáčení.
3. **Enkodér s přerušením** – hodnota 0–100, směr podle kvadratury, tlačítko enkodéru nuluje.
4. **Chybná ISR** – vložit do ISR `delay()` a `Serial.print()`, popsat a změřit, co se stane.

## Ověření měřením (U17)

Dvoukanálovým osciloskopem zobrazit signály A a B při otáčení oběma směry a odvodit z fázového
posuvu směr. Změřit zákmity enkodéru a ověřit účinek RC filtru. Změřit latenci obsluhy
(pin nastavený na začátku ISR).

## HW a SW

Inkrementální enkodér KY-040, tlačítko, rezistory, kondenzátory, dvoukanálový osciloskop.

## Starší podklady k tomuto tématu

- `3EA/enkoder/enkoder_bez_preruseni/` – `CW.JPG`, `CCW.JPG` → `obrazky/`, `README.MD` je základ výkladu
- `3EA/enkoder/enkoder_s_preruseni/`
- `3EA/enkoder/pcb_encoder_filter/` – KiCad projekt, nechat v archivu, v tématu jen schéma jako obrázek

## Poznámky k výuce

<!-- Obrázky CW/CCW z archivu promítnout hned na začátku – kvadratura se bez nich vysvětluje těžko. -->
