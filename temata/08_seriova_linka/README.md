# 08 – Sériová linka (UART)

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – komunikační sběrnice (UART)
**Výsledky vzdělávání:** V4
**Učivo:** U12

## Návaznost na 2. ročník

Formátovaný vstup a výstup (`printf`, `scanf`) žák zná. Tady se místo obrazovky a klávesnice
používá **sériová linka** – a poprvé se ukáže, že data přicházejí **po znacích a asynchronně**,
takže se na ně nedá čekat v cyklu.

## Cíle tématu

Žák po probrání tématu:

- popíše asynchronní sériový přenos: start bit, datové bity, stop bit, modulační rychlost
- nastaví `Serial.begin()` a vysvětlí, proč musí obě strany mít stejnou rychlost
- vypisuje formátovaně (`print`, `println`, `print(x, DEC/HEX/BIN)`) a používá sériový monitor k ladění
- přijme znak z PC neblokujícím způsobem (`Serial.available()`) a reaguje na něj
- rozliší TTL UART na pinech 0/1 a USB převodník na desce a ví, proč se navzájem ruší

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | UART: rámec, baud rate, TX/RX, křížení vodičů, TTL úrovně vs. RS-232. `Serial.begin/print/available/read`. Ladicí výpisy jako nástroj (a jejich cena v čase). Ovládání LED a bzučáku znakem z PC. | Deska reaguje na příkazy `1`/`0`/`b` z klávesnice a hlásí zpět, co provedla. |

## Klíčové pojmy

UART, asynchronní přenos, start/stop bit, baud rate, TX / RX, TTL úrovně, `Serial`,
`Serial.available()`, sériový monitor, echo

## Navržené úlohy

1. **Ovládání z PC** – znak `1` rozsvítí LED, `0` zhasne, `b` pípne; deska odpoví potvrzením.
2. **Telemetrie** – deska každých 500 ms pošle hodnotu z analogového vstupu; ověřit v sériovém plotteru.
3. **Špatná rychlost** – nastavit v monitoru jinou rychlost než v programu, popsat, co se stane a proč.
4. **Morseovka** – text z PC vyslaný LED nebo bzučákem v morseovce.

## Ověření měřením (U17)

Osciloskopem zobrazit průběh na pinu TX při vyslání jednoho znaku, spočítat z šířky bitu
modulační rychlost a přečíst z průběhu odeslaný znak.

## HW a SW

Arduino UNO/Nano, LED, bzučák, osciloskop. Sériový monitor a sériový plotter Arduino IDE.

## Starší podklady k tomuto tématu

- `3EA/uart/ovladani_led_pres_uart/`
- `3EA/zapinani_bzucaku_prikazem_z_pc/` – část s příkazem z PC
- `vyuka/sériová linka/Morseovka/` – přejmenovat bez diakritiky na `morseovka`

## Poznámky k výuce

<!-- Ladicí Serial.print v rychlé smyčce dokáže program zpomalit tak, že úloha „přestane fungovat“. Ukázat to. -->
