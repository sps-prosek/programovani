<#
.SYNOPSIS
  Založí nový tematický blok z šablon.

.EXAMPLE
  .\nastroje\nove_tema.ps1 -Cislo 17 -Slug rtc_hodiny -Nazev "Hodiny reálného času (RTC)" -Hodin 4
#>
param(
    [Parameter(Mandatory=$true)][int]$Cislo,
    [Parameter(Mandatory=$true)][string]$Slug,
    [Parameter(Mandatory=$true)][string]$Nazev,
    [int]$Hodin = 4
)

$koren = Split-Path -Parent $PSScriptRoot
$num = '{0:D2}' -f $Cislo
$nazevSlozky = "${num}_${Slug}"
$tema = Join-Path $koren "temata\$nazevSlozky"
$sablony = Join-Path $koren 'temata\00_sablony'

if (Test-Path $tema) {
    Write-Host "Slozka jiz existuje: temata\$nazevSlozky" -ForegroundColor Red
    exit 1
}

foreach ($p in @('prezentace','hodiny','ulohy','kod','obrazky','moodle')) {
    New-Item -ItemType Directory -Path (Join-Path $tema $p) -Force | Out-Null
}

# prezentace
Copy-Item (Join-Path $sablony 'prezentace\prezentace.tex') (Join-Path $tema 'prezentace\prezentace.tex')
Copy-Item (Join-Path $sablony 'prezentace\latexmkrc')      (Join-Path $tema 'prezentace\latexmkrc')

# prvni hodina a prvni uloha
Copy-Item (Join-Path $sablony 'hodina.md') (Join-Path $tema 'hodiny\hodina_01.md')
Copy-Item (Join-Path $sablony 'uloha.md')  (Join-Path $tema "ulohy\uloha_01_${Slug}.md")
Copy-Item (Join-Path $sablony 'uloha.tex') (Join-Path $tema "ulohy\uloha_01_${Slug}.tex")

# moodle
Copy-Item (Join-Path $sablony 'moodle\tema_moodle.md') (Join-Path $tema 'moodle\tema_moodle.md')
Copy-Item (Join-Path $sablony 'moodle\otazky.gift')    (Join-Path $tema 'moodle\otazky.gift')
Copy-Item (Join-Path $sablony 'moodle\ukoly.md')       (Join-Path $tema 'moodle\ukoly.md')

# kostra skici
$kod = Join-Path $tema "kod\${Slug}"
New-Item -ItemType Directory -Path $kod -Force | Out-Null
Copy-Item (Join-Path $sablony 'kod\sablona_skici\sablona_skici.ino') (Join-Path $kod "${Slug}.ino")

New-Item -ItemType File -Path (Join-Path $tema 'obrazky\.gitkeep') -Force | Out-Null

# README tematu
$readme = @"
# $num – $Nazev

**Rozsah:** $Hodin vyučovacích hodin

## Cíle tématu

Žák po probrání tématu:

- [cíl 1]
- [cíl 2]

## Obsah

- [pojem 1]
- [pojem 2]

## Obsah složky

| Složka | Co do ní patří |
|---|---|
| ``prezentace/`` | Zdroj LaTeX/Beamer prezentace a vygenerované PDF. |
| ``hodiny/`` | Přípravy na jednotlivé hodiny. |
| ``ulohy/`` | Zadání úloh pro žáky. |
| ``kod/`` | Arduino skici – jedna podsložka na skicu. |
| ``obrazky/`` | Schémata zapojení, fotky, snímky osciloskopu. |
| ``moodle/`` | Text tématu, banka otázek, popis úkolů. |

## Navržené úlohy

1. [úloha]

## Poznámky k výuce

<!-- Co žákům dělalo problém, co příště udělat jinak. -->
"@
Set-Content -Path (Join-Path $tema 'README.md') -Value $readme -Encoding UTF8

Write-Host "Vytvoreno: temata\$nazevSlozky" -ForegroundColor Green
Write-Host "Nezapomen doplnit radek do plan\tematicky_plan.md"
