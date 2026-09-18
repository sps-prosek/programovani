# Šablona Moodle kurzu – Programování 3. ročník

Odvozeno ze struktury kurzu **2EA Programování (2025/2026)**, který je z obou
záloh výrazně propracovanější. Cílem je, aby žák přecházející z 2. do 3. ročníku
našel stejné rozložení a stejné ikony.

---

## Celkové rozvržení kurzu

Formát: **tematické oddíly**, sbalitelné. Pořadí oddílů:

```
0  🏛️ Úvod do předmětu PRG        (organizace, hodnocení, osnova, kontakt)
1  👨‍💻 Zdrojové kódy                (odkaz na GitHub repozitář)
2  🧩 Domácí úkoly                 (přehled + jednotlivé úkoly)
3  🧠 Samostatná práce             (práce psané v hodině)
4  🎓 Závěrečný projekt
5  📅 Termíny a testy              (všechny Moodle testy na jednom místě)
6  📌 01 Úvod do Arduina a vývojového prostředí
7  📌 02 Digitální výstupy
8  📌 03 Digitální vstupy, pull-up/pull-down, zákmity
...                                (dále podle tematického plánu)
21 📌 16 Závěrečný projekt
```

Tematické oddíly začínají na indexu 6 a číslují se **stejně jako složky
v repozitáři** (`temata/03_digitalni_vstupy/` ↔ oddíl `📌 03 …`).

---

## Šablona tematického oddílu

Každý oddíl `📌 NN Název` obsahuje přesně tyto položky, v tomto pořadí:

| # | Typ aktivity | Název | Obsah |
|---|---|---|---|
| 1 | Popisek (label) | `📋Přehled` | HTML karty „Co se naučíte po absolvování tohoto tématu" – 4–6 dlaždic, každá má nadpis a 2 věty |
| 2 | Soubor (resource) | `📽️Prezentace` | PDF export Beameru z `temata/NN_slug/prezentace/` |
| 3 | Soubor (resource) | `👨‍💻Zdrojové kódy k prezentaci` | ZIP skic z `temata/NN_slug/kod/` |
| 4 | Stránka (page) | `📚Zdroje informací k tématu` | tabulka odkazů: online tutoriály (CZ/EN, štítek úrovně) + skripta a PDF |
| 5 | Stránka (page) | `🔑Důležité otázky k zapamatování` | rozklikávací Q&A, 10–20 otázek |
| 6 | Test (quiz) | `T NN – název tématu` | otázky z kategorie `Programování 3 / NN …` |
| 7 | Úkol (assign) | `✍️ÚNN.1 – název úlohy` | samostatná práce s procentní rubrikou |
| 8 | Fórum | `Otázky ke tématu` | volitelné, jen u náročnějších témat |
| 9 | Stránka (page) | `🔗Odkaz na prezentaci (pro vyučujícího)` | skrytá, odkaz na zdroj prezentace |

Položky 2, 3, 8 jsou volitelné podle toho, co pro téma existuje.

### Emoji konvence (z 2EA – zachovat)

| Emoji | Význam |
|---|---|
| 📋 | přehled / co se naučíte |
| 📽️ | prezentace |
| 👨‍💻 | zdrojové kódy |
| 📚 | zdroje informací |
| 🔑 | otázky k zapamatování |
| ✍️ | úkol k odevzdání |
| 📝 | termíny, stav odevzdání |
| 📌 | tematický oddíl |
| 🔗 | odkaz |
| ⭐ | hodnocení |

---

## Číslování a názvy (soulad s repozitářem)

| Objekt | Vzor | Příklad |
|---|---|---|
| oddíl kurzu | `📌 NN Název tématu` | `📌 03 Digitální vstupy` |
| test | `T NN – název` | `T03 – digitální vstupy` |
| souhrnný Moodle test | `✍️N. Moodle test: 3EA sX, (T: 01, 02, 03) – DD.MM.RRRR` | |
| varianta bez Safe Exam | tentýž název + ` – NSEB` | |
| úkol / samostatná práce | `✍️ÚNN.M – název` | `✍️Ú03.2 – LED ovládaná jedním tlačítkem` |
| domácí úkol | `✍️N. Název úlohy` | `✍️3. Morseův kód` |
| kategorie otázek | `Programování 3 / NN Název` | `Programování 3 / 08 Sériová linka` |
| skupina/pololetí v názvu testu | `3EA s1`, `3EA s2` | dělené skupiny |

Podsložky kategorií otázek pro varianty (jako v 3EA: `servo`, `H-můstek`,
`krokový motor` uvnitř většího tématu) – ano, pomáhá při náhodném výběru.

---

## Oddíl 0 – Úvod do předmětu

| Aktivita | Název | Poznámka |
|---|---|---|
| label | `📋Přehled` | co předmět je a na co navazuje |
| label | `📞Kontakt` | |
| page | `🗂️Organizace předmětu` | |
| page | `⭐Hodnocení a způsob zakončení` | klasifikační prostředky + stupnice |
| page | `📜Práva a povinnosti žáka` | |
| page | `🔗Zdroje a návody` | Arduino IDE, ovladače CH340, Tinkercad |
| page | `🗺️Osnova předmětu` | tematické okruhy s ikonami, text „Co se naučíte" |
| page | `Zpětná vazba 3EA sX` | dotazník na konci pololetí |
| qbank | `3EA shared question bank` | sdílená banka otázek |

Ve 2EA je stránka **Hodnocení a způsob zakončení** oddělená od **Podmínek
klasifikace** (které jsou v 3EA). Sjednotit do jedné stránky `⭐Hodnocení`
obsahující klasifikační prostředky (bodové váhy) i procentní stupnici.

---

## Oddíl 2 – Domácí úkoly

- `📝Stav & zadání domácích úkolů` – jedna přehledová stránka s tabulkou
  (číslo, název, téma, termín s1, termín s2, stav).
- Každý úkol jako samostatný `assign`, soubor `.ino` nebo `.txt`.
- Do každého zadání povinná pasáž (převzato z 2EA):

  > Domácí úkoly jsou povinné. Kdo úkol neodevzdá nebo jej odevzdá po termínu,
  > bude hodnocen známkou nedostatečnou. Pokud byste s jakýmkoli úkolem měli
  > problém, neváhejte mi napsat a společně to vyřešíme.

- A povinný požadavek na kvalitu kódu:

  > Zdrojový kód musí splňovat správné náležitosti kódu (správné pojmenování
  > proměnných, okomentování kódu a správné odsazení).

- Pro 3. ročník doplnit: **zapojení** (piny nebo fotografie/schéma) a
  **zákaz `delay()`**, kde se to hodí.

---

## Struktura zadání úlohy (převzato z 3EA)

```
Zadání
  <1–2 věty co program dělá>
  <odstavec s přesným popisem chování, konkrétní piny, časy, meze>
  <ošetření hraničních stavů>

Pomůcky
  - PC s Arduino IDE
  - Arduino UNO, USB kabel
  - <součástky>

Hodnocení
  - XX % … <dílčí funkce 1>
  - XX % … <dílčí funkce 2>
  ...          (součet 100 %)
```

Rubrika má 3–7 položek. Nejnižší položka nikdy pod 10 %.

---

## Šablona stránky „🔑Důležité otázky k zapamatování"

HTML s rozklikávacími `<details>`:

```html
<h3>📝 Otázky k zapamatování – «název tématu»</h3>
<p>Rozklikněte jednotlivé otázky pro zobrazení odpovědi.</p>

<details>
  <summary><strong>1.</strong> «otázka»</summary>
  <p>«odpověď – 1 až 3 věty, případně krátká ukázka kódu»</p>
</details>
```

10–20 otázek na téma. Formulace otázek mají odpovídat tomu, co se ptám
u ústního zkoušení – tato stránka je zároveň seznam zkouškových otázek.

> **Pozor:** ve 2EA se do odpovědí propsaly artefakty typu `【39†03_UvodC.pdf】`
> a zmizely názvy knihoven v `<stdio.h>` (spolkly se jako HTML tag).
> Při psaní nových stránek psát `&lt;stdio.h&gt;`.

---

## Šablona stránky „📚Zdroje informací k tématu"

Dvě sekce: **💻 Online tutoriály** a **📄 Skripta & PDF**.
Každá položka = karta s názvem, jednou větou popisu a štítky `CZ`/`EN`
a typem (`Základy`, `Tutoriál`, `Reference`, `PDF`).

Osvědčené zdroje z 2EA: W3Schools, ITnetwork.cz, GeeksforGeeks,
skripta ZČU / FEL ČVUT / UK. Pro 3. ročník přidat:
arduino.cc/reference, datasheet ATmega328P, Wokwi, Tinkercad Circuits.

---

## Testy

- Každé téma má **krátký test** `T NN` (10–15 bodů, formativní).
- Po skupině témat **souhrnný Moodle test** s uvedenými tématy v názvu.
- Vždy vyrábět **dvě verze**: se Safe Exam Browser a `– NSEB` bez něj
  (v 2EA i 3EA je to standard, funguje jako záloha při technických potížích).
- Testy pro obě dělené skupiny zvlášť (`s1`, `s2`) s vlastními termíny.
- Otázky brát z kategorií, ne jednotlivě – umožní náhodný výběr a varianty.

**Typy otázek, které se osvědčily a vyplatí se je vyrábět:**
`calculated` (ADC: napětí ↔ dílky – nekonečně variant),
`ddimageortext` (zapojení pull-up/pull-down, části desky, typy rotorů),
`ddwtos` (doplňování kódu – inicializace přerušení, `analogWrite` s potenciometrem),
`essay` (zadání programu s rubrikou – používá se jako samostatná práce v hodině).

---

## Hodnocení – návrh pro 3EA

| Prostředek | Body | Poznámka |
|---|---:|---|
| opakovací (kontrolní) test | 50 | 1–2× za pololetí |
| ústní zkoušení | 30–40 | otázky = stránka `🔑Důležité otázky` |
| samostatná práce (programování) | 20–30 | essay úloha v Moodle, hodnoceno rubrikou |
| test k tématu | 10–15 | |
| domácí úkol | 10–15 | |
| doplňující klasifikace | 5 | aktivita, dobrovolné úlohy |
| závěrečný projekt | 50 | funkčnost, dokumentace, obhajoba |

Stupnice po 7,5 %: 1 (100–92,5), 1− (92,5–85), 2 (85–77,5), 2− (77,5–70),
3 (70–62,5), 3− (62,5–55), 4 (55–47,5), 4− (47,5–40), 5 (pod 40).

---

## Postup založení kurzu

1. Vytvořit prázdný kurz `E-PRG-3EA` (2026/2027), formát tematický, sbalitelné oddíly.
2. Naimportovat **banku otázek** ze zálohy `zaloha-moodle2-course-389-...mbz`
   (import kurzu → pouze banka otázek), přejmenovat kategorie na `Programování 3 / NN …`.
3. Naimportovat vybrané **essay úlohy** ze staré banky jako základ samostatných prací.
4. Založit oddíly 0–5 podle výše uvedené kostry, texty převzít z 2EA
   (organizace, hodnocení, práva a povinnosti) a upravit na Arduino.
5. Pro každé téma vytvořit oddíl podle šablony. Prázdné položky založit hned
   jako skryté – kostra kurzu má stát od začátku, plní se průběžně.
6. Udržovat soulad názvů s repozitářem (`temata/NN_slug/moodle/`).
