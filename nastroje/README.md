# Nástroje

Pomocné skripty pro PowerShell (Windows). Spouštět z korene repozitáře.

| Skript | Co dělá | Kdy |
|---|---|---|
| `vytvor_strukturu.ps1` | Dotvoří prázdné podsložky (`prezentace`, `hodiny`, `ulohy`, `kod`, `obrazky`, `moodle`) ve všech tématech. Idempotentní. | Jednou na začátku, pak po přidání tématu ručně. |
| `presun_archiv.ps1` | Přesune `3EA/` a `vyuka/` do `_archiv/` pomocí `git mv`. | Jednou, po kontrole suchého běhu. |
| `nove_tema.ps1` | Založí nový tematický blok předplněný ze šablon. | Při přidání tématu. |
| `build_prezentace.ps1` | Přeloží prezentace do PDF (latexmk + XeLaTeX); výsledek pojmenuje `PRG-<tema>.pdf`. | Před hodinou / po úpravě slidů. |

## První spuštění

```powershell
# 1) dotvorit strukturu
.\nastroje\vytvor_strukturu.ps1

# 2) podivat se, co by presun archivu udelal
.\nastroje\presun_archiv.ps1

# 3) kdyz to vypada dobre, provest
.\nastroje\presun_archiv.ps1 -Provest
git status
git commit -m "Nova struktura podkladu, presun starych materialu do _archiv"
```

## Když PowerShell odmítne skript spustit

```powershell
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
```

Platí jen pro dané okno PowerShellu, nic v systému nemění.

## Předpoklady

- **Git** – kvůli `git mv` v `presun_archiv.ps1`
- **TeX Live** nebo **MiKTeX** s `latexmk` a `xelatex` – kvůli `build_prezentace.ps1`.
  Nic dalšího instalovat netřeba: vlastní motiv v `spolecne/styl/` si vystačí
  se standardními balíky (`beamer`, `listings`, `tikz`, `fontspec`)
- **Pandoc** (volitelně) – převod Markdownu pro Moodle
