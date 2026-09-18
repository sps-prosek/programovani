# 13 – Sběrnice I2C a SPI, senzory

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – komunikační sběrnice (I2C, SPI), možnosti připojení periférií
**Výsledky vzdělávání:** V4, V5
**Učivo:** U4, U12, U13

## Návaznost na předchozí bloky

Navazuje na UART (blok 08) – třetí ze sběrnic požadovaných ŠVP. Práce s registry senzoru
navazuje na bitové operace a struktury z 2. ročníku.

## Cíle tématu

Žák po probrání tématu:

- porovná UART, I2C a SPI (počet vodičů, adresace, rychlost, počet zařízení, typické použití)
- popíše I2C: SDA, SCL, master/slave, adresa, pull-up rezistory, potvrzení (ACK)
- najde na sběrnici připojená zařízení (scanner) a přečte registr senzoru (`Wire`)
- popíše SPI: MOSI, MISO, SCK, SS, plný duplex, řetězení zařízení
- připojí senzor podle schématu a přepočítá surová data na fyzikální veličinu
- ošetří chybějící nebo nereagující senzor, aby program nezamrzl

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Proč sběrnice. I2C: fyzická vrstva, pull-upy, adresa, zápis a čtení registru, `Wire`. I2C scanner. Senzor MPU6050: registry, surová data, převod na `g` a °/s. | Vypisuje zrychlení ve třech osách; pozná odpojený senzor. |
| 2 | Filtrace měřené veličiny (klouzavý průměr, exponenciální filtr) a proč je nutná. Senzor DHT11/DHT22 (vlastní jednovodičový protokol – proti I2C). SPI: signály, zapojení, `SPI` knihovna, ukázka s SD kartou nebo displejem. Kdy zvolit kterou sběrnici. | Vyhlazená hodnota zrychlení + tabulka porovnání UART / I2C / SPI. |

## Klíčové pojmy

sběrnice, I2C, SDA / SCL, adresa zařízení, ACK, pull-up, `Wire`, registr senzoru,
SPI, MOSI / MISO / SCK / SS, plný duplex, klouzavý průměr, kalibrace, offset

## Navržené úlohy

1. **I2C scanner** – vypsat adresy všech připojených zařízení; ověřit odpojením senzoru.
2. **Náklonoměr** – z MPU6050 určit náklon a rozsvítit LED při překročení mezního úhlu.
3. **Filtrace** – porovnat surový a filtrovaný signál v sériovém plotteru.
4. **Teplota a vlhkost** – DHT11/DHT22, výpis každé 2 s, ošetření chyby čtení.
5. **Náklon → servo** – spojení s blokem 10: servo kopíruje náklon senzoru.

## Ověření měřením (U17)

Dvoukanálovým osciloskopem zobrazit SDA a SCL při čtení registru, změřit taktovací frekvenci
a v průběhu ukázat start, adresu a ACK. Změřit napětí na pull-up rezistorech.

## HW a SW

MPU6050, DHT11/DHT22, pull-up rezistory 4,7 kΩ, dvoukanálový osciloskop, volitelně modul SPI
(SD karta). Knihovny `Wire` (součást IDE), `DHT sensor library`, `SPI` (součást IDE).

## Starší podklady k tomuto tématu

- `3EA/zrychleni/jednoduche_cteni_senzoru_po_i2c/`
- `3EA/zrychleni/filtrace_mereneho_zrychleni/`
- `3EA/servo/ovladani_serva_mpu6050_bez_vypoctu_uhlu/` – navazuje na blok 10
- `vyuka/servo/servo_s_MPU6050/`
- `vyuka/DHT11/dht11_a_lcd_displej/` – dokončit v bloku 14

## Poznámky k výuce

<!-- SPI stačí na úrovni „umí popsat a zapojit“, hloubka jde do bloku 16, pokud si ji projekt vyžádá. -->
