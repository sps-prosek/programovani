# Moodle – jak podklady dostat do kurzu

Struktura v Moodle kopíruje `temata/` – jeden **oddíl kurzu = jedno téma**.

## Obsah oddílu (doporučený a stále stejný)

1. **Popisek** – název tématu a v jedné větě, co se v něm naučí.
2. **Stránka / Kniha „Výklad“** – obsah z `tema_moodle.md`.
3. **Soubor „Prezentace (PDF)“** – `../prezentace/prezentace.pdf`.
4. **Složka „Ukázkový kód“** – skici z `../kod/` zabalené do `.zip`.
5. **Úkol** pro každou úlohu – zadání z `../ulohy/uloha_NN_*.md`, nastavení z `ukoly.md`.
6. **Test** – otázky z `otazky.gift`.

## Import textu

`tema_moodle.md` je Markdown. Do Moodle:

- **Stránka:** v editoru přepnout na Markdown (pokud je povolen), jinak vložit jako HTML.
  Převod: `pandoc tema_moodle.md -o tema_moodle.html`
- **Kniha:** každý nadpis úrovně `##` = jedna kapitola knihy.

## Import otázek

1. Kurz → *Banka otázek* → *Import*.
2. Formát souboru: **GIFT format**.
3. Nahrát `otazky.gift`, zvolit kategorii podle tématu (např. „03 – Digitální vstupy“).
4. Test pak plnit náhodnými otázkami z kategorie.

## Konvence pojmenování v kurzu

- Oddíl: `03 – Digitální vstupy (tlačítka, zákmity)`
- Úkol: `Ú03.1 – Počítadlo stisků`
- Test: `T03 – Digitální vstupy`
- Kategorie otázek: `Programování 3 / 03 Digitální vstupy`

Číslování drží soulad s repozitářem, takže se v Moodle i na disku hledá stejně.
