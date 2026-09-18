# Přehled vybavení a součástek

Kontrolní seznam pro přípravu hodiny – co musí být na stole a kolik sad je k dispozici.
Čísla témat odpovídají [`tematicky_plan.md`](tematicky_plan.md).

## Základní sada (1 na žáka / dvojici)

| Položka | Počet sad | Kde je | Poznámka |
|---|---:|---|---|
| Arduino UNO R3 (nebo Nano + adaptér) |  |  | + USB kabel |
| Nepájivé pole (breadboard) |  |  | |
| Sada drátků M–M |  |  | |
| LED 5 mm (červená, zelená, žlutá) |  |  | |
| Rezistory 220 Ω / 1 kΩ / 10 kΩ |  |  | |
| Mikrotlačítka |  |  | |
| Potenciometr 10 kΩ |  |  | |

## Měřicí přístroje (průřezové – učivo U17)

| Přístroj | Počet | Od tématu | K čemu |
|---|---:|---|---|
| Multimetr |  | 01 | napájení, proud LED, odběr serva a motoru |
| Osciloskop (nejlépe dvoukanálový) |  | 03 | zákmity, PWM, UART, kvadratura A/B, I2C |

Dvoukanálový osciloskop je nutný v blocích 12 (signály A/B enkodéru) a 13 (SDA + SCL).
Pokud je jen jeden přístroj na laboratoř, měření se dělá společně jako demonstrace.

## Doplňkové moduly podle tématu

| Téma | Modul | Počet | Poznámka |
|---|---|---:|---|
| 02 | Pasivní / aktivní bzučák |  | rozlišit a označit, nepomíchat |
| 03 | Kondenzátor 100 nF (RC debounce) |  | |
| 07 | Fotorezistor, trimr, kondenzátor 10 µF |  | RC filtr PWM |
| 10 | Servo SG90 / MG996R |  | u MG996R vlastní napájení |
| 10, 11 | Joystick modul (2 osy + tlačítko) |  | |
| 11 | DC motor + H-můstek L298N / L9110 |  | zdroj 6–12 V, blokovací kondenzátor |
| 12 | Inkrementální enkodér (KY-040) |  | filtrační deska v `_archiv/3EA/enkoder/pcb_encoder_filter` |
| 13 | MPU6050 (I2C) |  | |
| 13 | DHT11 / DHT22 |  | |
| 13 | Modul na SPI (SD karta / displej) |  | stačí 1–2 ks na demonstraci SPI |
| 14 | LCD 16x2 s I2C převodníkem |  | adresa 0x27 nebo 0x3F – ověřit scannerem |
| 16 | Podle zadání projektů |  | ultrazvukový dálkoměr, relé, RTC modul… |

## Napájení

| Zdroj | Počet | Pro co |
|---|---:|---|
| Laboratorní zdroj / 5 V adaptér |  | servo (blok 10) |
| Zdroj 6–12 V |  | DC motor a H-můstek (blok 11) |

## Software

- Arduino IDE 2.x (nebo Arduino CLI) – na všech stanicích v laboratoři
- Ovladače USB-sériového převodníku (CH340 u klonů)
- Git + přístup na GitHub (bloky 01 a 15, průběžně)
- Knihovny: `Servo`, `Wire`, `SPI` (součást IDE), `LiquidCrystal_I2C`, `DHT sensor library`
- Volitelně: Wokwi / Tinkercad Circuits pro simulaci bez HW

## Co bývá problém

- Klony s CH340 potřebují ovladač – zkontrolovat před první hodinou.
- Servo a DC motor napájené z 5 V pinu Arduina resetují desku. Oddělený zdroj + společná GND.
- Pomíchané aktivní/pasivní bzučáky – označit.
- Adresa I2C převodníku LCD se u různých kusů liší (0x27 / 0x3F) – najít scannerem.
- Knihovna `Servo` obsazuje Timer1, tedy PWM na pinech 9 a 10 (souvislost s bloky 04 a 07).
