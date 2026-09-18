# Loga školy

Oficiální logo SPŠ na Proseku připravené pro sazbu v LaTeXu.

**Zdroj:** <https://github.com/sps-prosek/sps-prosek-logo> (licence GPL-3.0).
Originály jsou SVG; soubory zde jsou z nich převedené do PDF, protože
vektorové PDF umí `\includegraphics` vložit přímo, bez konverze při každém
překladu a bez ztráty ostrosti při promítání.

| Soubor | Varianta | Kde se používá |
|---|---|---|
| `logo-s-nazvem-barevne.pdf` | znak + „Střední průmyslová škola na Proseku“, barevně | pravý horní roh každého slidu |
| `logo-s-nazvem-bile.pdf` | totéž bíle | titulní slide (tmavé pozadí) |
| `logo-znak-barevne.pdf` | jen znak „SPŠ / na Proseku“, barevně | volné použití (plakát, zadání úlohy) |
| `logo-znak-bile.pdf` | jen znak, bíle | volné použití na tmavém podkladu |
| `logo-znak-vodoznak.pdf` | jen znak, tmavě šedě | jemný vodoznak v rohu titulního slidu |

Loga vkládá motiv `spolecne/styl/beamerthemeSPSProsek.sty` sám, v běžné
prezentaci se na ně tedy neodkazuje ručně.

## Velikost loga

Logo má být vidět, ale nemá ukrajovat místo obsahu – hlavně dlouhým výpisům
kódu. Výchozí šířky se dají přepsat před `\begin{document}`:

```latex
\renewcommand{\SPSLogoWidth}{0.15\paperwidth}       % logo na běžném slidu
\renewcommand{\SPSTitleLogoWidth}{0.34\paperwidth}  % logo na titulním slidu
```

## Pravidla

- Logo nikdy nedeformovat – `\includegraphics` vždy s `keepaspectratio`
  a jen s jedním rozměrem (šířka **nebo** výška).
- Barevná varianta patří na světlé pozadí, bílá na tmavé; nemíchat.
- Když se logo v repozitáři změní, stačí vyměnit PDF v této složce,
  do prezentací se to propíše samo.
