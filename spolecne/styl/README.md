# Styl a sdílená preambule

Vzhled všech prezentací předmětu. Mění se **jen tady** – všechny prezentace
se pak přeloží s novým stylem.

| Soubor | Co v něm je |
|---|---|
| `beamerthemeSPSProsek.sty` | Vlastní Beamer motiv: pozadí, logo, titulní slide, patička s verzí, prostředí `keyframe`, sazba kódu v C/Arduino. |
| `preambule.tex` | Načte motiv, nastaví češtinu a písma, metadata předmětu a makra (`\kod`, `\pozor`, `\kodSoubor`, …). |
| `loga/` | Logo školy ve vektorovém PDF (viz [`loga/README.md`](loga/README.md)). |

Motiv je převzatý ze šablony předmětů ZPG a SNT na Fakultě strojní ČVUT
(repozitář `software-tools-for-technical-calculations`,
`utils/presentation-template/beamerthemeCVUT.sty`). Zachovává stejné
rozvržení – poměr 16 : 9, patičku s verzí a číslem slidu, prostředí
`keyframe`, volitelné řádky `headlineA/B/C` – a mění značku a barvy na SPŠ
na Proseku. Navíc přidává sazbu zdrojového kódu, protože v tomto předmětu
je kódu podstatně víc.

## Použití v prezentaci

```latex
\documentclass[12pt,aspectratio=169]{beamer}
\input{../../../spolecne/styl/preambule}
```

Cesta počítá s tím, že prezentace leží v `temata/<tema>/prezentace/`.
Hotová kostra je v `temata/00_sablony/prezentace/prezentace.tex`.

## Překlad

Kvůli `fontspec` je potřeba **XeLaTeX**:

```powershell
.\nastroje\build_prezentace.ps1 temata\03_digitalni_vstupy\prezentace\prezentace.tex
```

Skript volá `latexmk -xelatex` a výsledek pojmenuje `PRG-<tema>.pdf`.
Ručně totéž svede `latexmk -xelatex prezentace.tex`.

Motiv nevyžaduje žádné externí fonty ani balík `metropolis` – stačí běžná
instalace MiKTeXu nebo TeX Live. Přeloží se i pdfLaTeXem (preambule na něj
má záložní větev), ale výchozí a otestovaná cesta je XeLaTeX.

## Typy slidů

Běžný slide je obyčejný `frame`. Navíc jsou k dispozici:

```latex
% slide s červeným pruhem vlevo – pro cíle na začátku a shrnutí na konci
\begin{keyframe}{Co dnes zvládneme}
  ...
\end{keyframe}

% totéž, ale uvnitř může být výpis kódu
\begin{keyframefragile}{Co si zapamatovat}
  ...
\end{keyframefragile}
```

`\section{Teorie}` vloží předělový slide s názvem části. Když je v dané
prezentaci nechcete, napište za `\input{...preambule}` řádek
`\SPSSectionSlidesOff`.

Volitelný text v horní liště (např. název tématu na každém slidu):

```latex
\renewcommand{\headlineA}{Téma 3 -- Digitální vstupy}
```

## Sazba kódu

Výpisy sází balík `listings`. Výchozí styl `arduino` je nastavený globálně,
takže stačí:

```latex
\begin{frame}[fragile]{Blikání LED}   % POZOR: frame musí být [fragile]
\begin{lstlisting}
void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(500);
}
\end{lstlisting}
\end{frame}
```

| Co | Jak |
|---|---|
| kód s číslovanými řádky | výchozí styl `arduino` |
| krátký útržek bez čísel | `\begin{lstlisting}[style=arduino_bez_cisel]` |
| výstup ze sériového monitoru | `\begin{vystup} … \end{vystup}` |
| kód uvnitř věty | `\kod{digitalWrite(LED, HIGH);}` |
| celá skica ze souboru | `\kodSoubor{../kod/blikani/blikani.ino}` |
| část souboru | `\kodSouborRadky{../kod/blikani/blikani.ino}{1}{20}` |
| zvýraznění úseku ve výpisu | `(*@\zvyrazni{millis()}@*)` uvnitř kódu |

Vkládání přímo ze souboru (`\kodSoubor`, `\kodSouborRadky`) je lepší než
kopírovat kód do slidu – prezentace se pak nikdy nerozejde s tím, co žáci
skutečně mají.

### Velikost písma v kódu

Výchozí je `\footnotesize`. Když se dlouhá ukázka na slide nevejde:

```latex
\renewcommand{\SPSCodeSize}{\scriptsize}   % jen v dané prezentaci,
                                           % za \input{...preambule}
```

Globálně se totéž změní v `beamerthemeSPSProsek.sty` u `\providecommand{\SPSCodeSize}`.
Lepší než zmenšovat písmo je ale ukázku rozdělit na dva slidy nebo vložit
jen podstatné řádky pomocí `\kodSouborRadky`.

## Barvy

Definované centrálně v motivu, dají se použít i ve vlastním obsahu slidů
(`\textcolor{SPSRed}{...}`):

| Barva | Kde se bere | K čemu |
|---|---|---|
| `SPSRed` (#ED1C24) | písmeno „P“ v logu | zvýraznění, `\pozor`, odrážky, pruh u `keyframe` |
| `SPSGrey` (#8E9194) | znak „SPŠ“ v logu | čísla řádků, doplňkový text |
| `SPSDark` (#231F20) | tmavá varianta loga | titulní slide, nadpisy |
| `SPSAnthracite` (#393536) | nápis „na Proseku“ | záhlaví bloků |
| `SPSLight` (#F2F2F2) | – | pozadí bloků a výstupů |

Starší česká jména `akcent`, `skolaSeda` a `skolaModra` zůstávají platná
(jsou to aliasy na `SPSRed`, `SPSGrey` a `SPSDark`), aby se už napsané
slidy nemusely přepisovat.

## Verze v patičce

Motiv vkládá do paty každého slidu drobným písmem datum a čas posledního
překladu („Verze: 18. 9. 2026, 04:33“). Při promítání je tak hned vidět,
jak stará je verze PDF. Nic se nenastavuje ručně; vlastní popisek lze
vynutit před `\begin{document}`:

```latex
\renewcommand{\SPSVersionStamp}{Verze pro maturitní ročník 2026/27}
```
