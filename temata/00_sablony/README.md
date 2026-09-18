# Šablony

Odsud se kopíruje při zakládání nového tématu nebo nové hodiny.
Automaticky to udělá `nastroje/nove_tema.ps1`.

| Soubor | Kam se kopíruje | Na co je |
|---|---|---|
| `prezentace/prezentace.tex` | `temata/<tema>/prezentace/prezentace.tex` | Beamer prezentace k výkladu, PDF k promítání i k vytištění (`handout`). |
| `hodina.md` | `temata/<tema>/hodiny/hodina_NN.md` | Příprava na jednu vyučovací hodinu. |
| `uloha.md` | `temata/<tema>/ulohy/uloha_NN_nazev.md` | Zadání úlohy pro žáky – zdroj pro Moodle. |
| `uloha.tex` | `temata/<tema>/ulohy/uloha_NN_nazev.tex` | Totéž k vytištění na papír. |
| `moodle/tema_moodle.md` | `temata/<tema>/moodle/tema_moodle.md` | Text tématu do Moodle (stránka nebo kniha). |
| `moodle/otazky.gift` | `temata/<tema>/moodle/otazky.gift` | Banka otázek ve formátu GIFT k importu do Moodle. |
| `moodle/ukoly.md` | `temata/<tema>/moodle/ukoly.md` | Zadání úkolů v Moodle: termíny, formát odevzdání, hodnocení. |
| `kod/sablona_skici/sablona_skici.ino` | `temata/<tema>/kod/<nazev>/<nazev>.ino` | Kostra Arduino skici s hlavičkovým komentářem. |

## Pravidla

- Šablony samy se **nepřekládají ani nepoužívají ve výuce** – jsou to čisté vzory.
- Když se v šabloně něco zlepší, opravit to tady a při dalším tématu se to propíše dál.
- Placeholdery v Markdownu jsou v hranatých závorkách: `[NÁZEV TÉMATU]`.
- V LaTeXu jsou placeholdery ve francouzských uvozovkách: `«NÁZEV TÉMATU»`.
  Hranatá závorka by se v LaTeXu po `\\` nebo `\item` spletla s nepovinným
  argumentem a překlad by spadl – proto ten rozdíl.
- Obě šablony `prezentace.tex` i `uloha.tex` se přeloží i nevyplněné
  (XeLaTeX, bez chyb) – dá se tak hned ověřit, že TeX je nainstalovaný správně.
