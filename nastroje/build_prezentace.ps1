<#
.SYNOPSIS
  Přeloží prezentaci (nebo všechny prezentace) do PDF.

.DESCRIPTION
  Volá latexmk s XeLaTeXem. Bez parametru přeloží všechny prezentace
  ve všech tématech (mimo šablony).

  Výsledek se pojmenuje podle tématu: `PRG-<slozka_tematu>.pdf`
  (např. `PRG-03_digitalni_vstupy.pdf`). Díky tomu jde PDF rozeznat
  i mimo strukturu složek -- typicky po nahrání do Moodle nebo na USB,
  kde by se jinak všechny jmenovaly `prezentace.pdf`. Handout dostane
  navíc příponu `_handout`.

.PARAMETER Cesta
  Konkrétní .tex soubor k přeložení.

.PARAMETER Handout
  Přeloží variantu bez postupného odkrývání (na tisk).

.EXAMPLE
  .\nastroje\build_prezentace.ps1
  .\nastroje\build_prezentace.ps1 temata\03_digitalni_vstupy\prezentace\prezentace.tex
  .\nastroje\build_prezentace.ps1 temata\03_digitalni_vstupy\prezentace\prezentace.tex -Handout
#>
param(
    [string]$Cesta,
    [switch]$Handout
)

$koren = Split-Path -Parent $PSScriptRoot

if (-not (Get-Command latexmk -ErrorAction SilentlyContinue)) {
    Write-Host "latexmk nenalezen. Nainstaluj TeX Live nebo MiKTeX." -ForegroundColor Red
    exit 1
}

if ($Cesta) {
    $soubory = @(Get-Item (Join-Path $koren $Cesta) -ErrorAction Stop)
} else {
    $soubory = Get-ChildItem -Path (Join-Path $koren 'temata') -Recurse -Filter 'prezentace.tex' |
               Where-Object { $_.FullName -notmatch '00_sablony' }
}

$volby = @('-xelatex', '-interaction=nonstopmode', '-halt-on-error')
if ($Handout) { $volby += '-usepretex=\PassOptionsToClass{handout}{beamer}' }

# Nazev vysledneho PDF odvodit ze slozky tematu: temata\<tema>\prezentace\
# -> PRG-<tema>.pdf. Kdyz prezentace lezi jinde, zustane puvodni nazev.
function Get-NazevVystupu {
    param([System.IO.FileInfo]$Soubor)

    $slozkaPrezentace = $Soubor.DirectoryName
    $nazevSlozky = Split-Path -Path $slozkaPrezentace -Leaf
    if ($nazevSlozky -ne 'prezentace') {
        return $null
    }

    $tema = Split-Path -Path (Split-Path -Path $slozkaPrezentace -Parent) -Leaf
    $pripona = if ($Handout) { '_handout' } else { '' }
    return "PRG-$tema$pripona.pdf"
}

foreach ($f in $soubory) {
    Write-Host "`n=== $($f.FullName.Substring($koren.Length+1)) ===" -ForegroundColor Cyan
    Push-Location $f.DirectoryName
    latexmk @volby $f.Name
    if ($LASTEXITCODE -eq 0) {
        latexmk -c $f.Name | Out-Null      # uklid pomocnych souboru

        $vystup = Get-NazevVystupu -Soubor $f
        if ($vystup) {
            Move-Item -LiteralPath "$($f.BaseName).pdf" -Destination $vystup -Force
            Write-Host "OK -> $vystup" -ForegroundColor Green
        } else {
            Write-Warning "Prezentace nelezi v 'temata\<tema>\prezentace' - nechavam '$($f.BaseName).pdf'."
            Write-Host "OK -> $($f.BaseName).pdf" -ForegroundColor Green
        }
    } else {
        Write-Host "CHYBA pri prekladu - podivej se do $($f.BaseName).log" -ForegroundColor Red
    }
    Pop-Location
}
