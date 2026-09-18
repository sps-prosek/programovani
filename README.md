# Programování – 3. ročník (Mechatronika)

Podklady pro předmět **Programování** na SPŠ, elektrotechnické zaměření – obor Mechatronika
(26-41-M/01 Elektrotechnika, ŠVP Mechatronika, platnost od 1. 9. 2024).
Ve 3. ročníku se navazuje na základy jazyka C z 2. ročníku a programuje se mikrokontroler
na platformě **Arduino** (ATmega328P – UNO / Nano).

**Dotace podle ŠVP:** 2 h týdně, 64 h v ročníku. Plán počítá s **50 h náplně
(25 dvouhodinovek)**, zbytek je rezerva na odpadlé hodiny, testy a dokončení projektů.

## Kde co je

| Cesta | Obsah |
|---|---|
| `plan/` | ŠVP (`6_SVP_M_2024.pdf`), tematický plán, přehled vybavení, mapování starých podkladů na nová témata. |
| `temata/` | Vlastní učivo. Jedna složka = jeden tematický blok, uvnitř prezentace, hodiny, úlohy, kód, obrázky a Moodle. |
| `temata/00_sablony/` | Šablony: prezentace (Beamer), příprava na hodinu, zadání úlohy, podklady pro Moodle. |
| `spolecne/` | Věci sdílené napříč tématy – Beamer motiv SPŠ a preambule, loga školy, společné obrázky, ukázky kódu. |
| `nastroje/` | Pomocné skripty: založení struktury, nové téma, překlad prezentací, přesun archivu. |
| `_archiv/` | Staré podklady z předchozích let (`3EA/`, `vyuka/`). Zdroj, ze kterého se materiál postupně přenáší do `temata/`. |

## Tematické bloky

| # | Téma | Hodin |
|---|---|---:|
| 01 | HW platformy a vývojové prostředí | 4 |
| 02 | Digitální výstupy – LED a bzučák | 2 |
| 03 | Digitální vstupy – tlačítka, pull-up, zákmity | 4 |
| 04 | Časování bez `delay()` – `millis()` a časovače | 4 |
| 05 | Stavové automaty – cyklistická blikačka | 4 |
| 06 | Funkce a strukturování kódu | 2 |
| 07 | Analogové vstupy a PWM | 4 |
| 08 | Sériová linka (UART) | 2 |
| 09 | Pole a řetězce – parsování příkazů | 2 |
| 10 | Modelářské servo | 2 |
| 11 | DC motor a H-můstek | 2 |
| 12 | Přerušení a inkrementální enkodér | 4 |
| 13 | Sběrnice I2C a SPI, senzory | 4 |
| 14 | LCD displej | 2 |
| 15 | Vlastní knihovny a správa verzí | 2 |
| 16 | Závěrečný projekt | 6 |
| | **celkem** | **50** |

Rozvržení do období, mapování na výsledky vzdělávání a učivo ŠVP a kontrola pokrytí:
[`plan/tematicky_plan.md`](plan/tematicky_plan.md).

> Názvy složek zůstávají z první verze struktury (`01_uvod_arduino`, `09_pole_a_retezce`, …),
> i když se názvy témat upřesnily podle ŠVP. Číslování odpovídá plánu i oddílům v Moodle.

## Průřezové prvky

V každé praktické hodině: zapojení podle schématu, ověření zapojení měřením
(multimetr / osciloskop) a commit hotové úlohy do vlastního repozitáře.

## Jak přidat nové téma

```powershell
.\nastroje\nove_tema.ps1 -Cislo 17 -Slug nazev_tematu -Nazev "Název tématu"
```

Skript vytvoří složku s kompletní strukturou a předplněnými šablonami.

## Jak přeložit prezentaci

```powershell
.\nastroje\build_prezentace.ps1 temata\03_digitalni_vstupy\prezentace\prezentace.tex
```

Vyžaduje TeX Live nebo MiKTeX s `latexmk` a XeLaTeX. PDF zůstane vedle zdroje
pod názvem podle tématu – `PRG-03_digitalni_vstupy.pdf` – aby šlo rozeznat
i po nahrání do Moodle. Vzhled (logo školy, barvy, sazba kódu v C/Arduino)
řeší `spolecne/styl/` – viz [`spolecne/styl/README.md`](spolecne/styl/README.md).

## Konvence

- Názvy složek a souborů: **malými písmeny, bez diakritiky, podtržítka** místo mezer (kvůli Gitu, LaTeXu a Arduino IDE).
- Arduino skica musí být ve složce se stejným názvem jako soubor `.ino`.
- Prezentace, zadání i přípravy patří vždy do složky svého tématu, ne do sdíleného „koše“.
- Vygenerovaná PDF se do Gitu commitují (hodí se mít je po ruce), pomocné soubory LaTeXu ne – viz `.gitignore`.

## Kontakt

Jaroslav Bušek
[jaroslav.busek@sps-prosek.cz](mailto:jaroslav.busek@sps-prosek.cz)
