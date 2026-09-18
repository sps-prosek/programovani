# 16 – Závěrečný projekt

**Rozsah:** 6 h (3 dvouhodinovky) + rezerva na dokončení a obhajoby
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – komplexní projekty
**Výsledky vzdělávání:** V8 (a ověření V2–V7)
**Učivo:** U4, U16, U17

## Návaznost

Projekt je souhrnem celého ročníku: zapojení podle schématu, stavový automat, neblokující
časování, alespoň jedna periferie na sběrnici, rozdělení do funkcí nebo vlastní knihovny,
ověření měřením a vedení v gitu. Navazuje také na dekompozici problému ze 2. ročníku –
žák poprvé řeší zadání, které nelze napsat na jeden zátah.

## Cíle tématu

Žák po probrání tématu:

- rozloží zadání na dílčí funkční celky a naplánuje pořadí jejich realizace
- nakreslí blokové schéma zařízení a schéma zapojení, podle kterého pak staví
- postupně realizuje a průběžně ověřuje jednotlivé části (ne „všechno naráz na konci“)
- odladí zařízení a naměřením doloží, že funguje podle zadání
- zdokumentuje projekt (README, schéma, popis ovládání) a obhájí své řešení

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Zadání a výběr tématu, požadavky na projekt, kritéria hodnocení. Dekompozice, blokové schéma, seznam součástek, stavový diagram. Založení repozitáře. | Schválené zadání + blokové schéma + rozvrh práce. |
| 2 | Realizace: zapojení podle schématu, kostra programu, postupné zprovoznění částí. Průběžná kontrola a měření. | Funkční jádro zařízení, alespoň dvě části zprovozněné a commitnuté. |
| 3 | Dokončení, ladění, měření, dokumentace. Obhajoba – předvedení funkce a zodpovězení otázek. | Funkční zařízení + dokumentace + obhajoba. |

## Požadavky na projekt

Zařízení musí obsahovat:

- alespoň **dva vstupy** (tlačítko, potenciometr, senzor, enkodér)
- alespoň **dva výstupy** (LED, bzučák, servo, motor, displej)
- **stavový automat** nebo jiné zdůvodněné řízení běhu programu
- **neblokující časování** – žádné `delay()` v hlavní smyčce
- alespoň **jednu periferii na sběrnici** (I2C, SPI nebo UART)
- rozdělení do **funkcí nebo vlastní knihovny**
- **schéma zapojení** a **dokumentaci** v repozitáři

## Náměty na zadání

1. Meteostanice – teplota a vlhkost na LCD, zápis extrémů, výstraha při překročení mezí.
2. Parkovací asistent – měření vzdálenosti, bzučák s proměnnou frekvencí, LED bargraf.
3. Řízení pohonu – DC motor s enkodérem, zadávání otáček, zobrazení skutečné hodnoty.
4. Kuchyňská minutka – enkodér pro nastavení, LCD, zvuková signalizace, stavový automat.
5. Bezpečnostní hlídač – náklon z MPU6050, alarm, odblokování kódem přes sériovou linku.
6. Semafor s chodeckým tlačítkem – plnohodnotný automat, noční režim, ladění časů po UART.
7. Dávkovač / mixér – servo nebo motor, zadání dávky, počítání cyklů, uložení do EEPROM.

## Ověření měřením (U17)

Součástí obhajoby je alespoň jedno měření, které doloží funkci zařízení: průběh signálu
na osciloskopu, proudový odběr, doba reakce nebo přesnost časování. Naměřená hodnota
patří do dokumentace.

## Hodnocení projektu

| Kritérium | Váha |
|---|---:|
| Funkčnost podle zadání | 40 % |
| Zapojení a jeho ověření měřením | 15 % |
| Kvalita a čitelnost kódu (struktura, funkce/knihovna, neblokující běh) | 20 % |
| Dokumentace a historie v gitu | 15 % |
| Obhajoba | 10 % |

## Poznámky k výuce

<!-- Zadání schvalovat na první hodině a odmítat příliš rozsáhlá – lepší menší a dokončené. -->
