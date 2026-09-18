# 14 – LCD displej

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – možnosti připojení periférií, komunikační sběrnice
**Výsledky vzdělávání:** V5
**Učivo:** U4, U12, U13

## Návaznost na předchozí bloky

Navazuje na I2C (blok 13) – displej se připojuje přes I2C převodník, takže sběrnice je
už zvládnutá a zbývá jen obsluha displeje. Zobrazované hodnoty pocházejí z bloků 07, 12 a 13.

## Cíle tématu

Žák po probrání tématu:

- připojí LCD 16×2 přes I2C převodník podle schématu a nastaví jeho adresu a kontrast
- vypisuje text a čísla na zvolenou pozici (`setCursor`, `print`), maže jen to, co je potřeba
- vysvětlí, proč se nesmí překreslovat celý displej v každém průchodu `loop()`
- zobrazuje měnící se hodnotu bez blikání (přepis pozice, doplnění mezerami)
- vytvoří vlastní znak a použije jej pro bargraf

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Řadič HD44780, I2C převodník PCF8574, adresa 0x27 / 0x3F, trimr kontrastu. `LiquidCrystal_I2C`: `init`, `backlight`, `setCursor`, `print`, `clear`. Překreslování jen při změně hodnoty. Vlastní znaky `createChar`, bargraf. Jednoduché menu ovládané tlačítky nebo enkodérem. | Displej ukazuje aktuální hodnotu ze senzoru a nebliká. |

## Klíčové pojmy

HD44780, I2C převodník, adresa displeje, kontrast, `setCursor`, `clear`,
překreslování jen při změně, vlastní znak (`createChar`), bargraf, menu

## Navržené úlohy

1. **Měřič** – hodnota z potenciometru ve voltech na prvním řádku, minimum a maximum na druhém.
2. **Bez blikání** – stejná úloha s `clear()` v každém průchodu a bez něj; popsat rozdíl.
3. **Teploměr** – DHT11 + LCD (spojení s blokem 13).
4. **Bargraf hlasitosti** – vlastní znaky, úroveň z analogového vstupu (dokončení úlohy z bloku 07).
5. **Menu** – tři položky procházené enkodérem z bloku 12, potvrzení tlačítkem.

## Ověření měřením (U17)

Změřit proudový odběr displeje s podsvícením a bez něj (důležité pro bateriové projekty
v bloku 16). Osciloskopem ověřit provoz na I2C při překreslování displeje a odhadnout,
kolik času obsluha displeje ubírá hlavní smyčce.

## HW a SW

LCD 16×2 s I2C převodníkem, trimr, tlačítka nebo enkodér, multimetr.
Knihovna `LiquidCrystal_I2C`.

## Starší podklady k tomuto tématu

- `vyuka/LCD displej/lcd_displej_s_tlacitkem/`
- `vyuka/LCD displej/lcd_displej_s_enkoderem/` – navazuje na blok 12
- `vyuka/LCD displej/vizualizace_hlasitosti/` – bargraf
- `vyuka/DHT11/dht11_a_lcd_displej/`

## Poznámky k výuce

<!-- Adresa I2C převodníku se u různých kusů liší – nechat žáky najít ji scannerem z bloku 13. -->
