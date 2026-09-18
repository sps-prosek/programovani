<#
.SYNOPSIS
  Přesune staré podklady (3EA/, vyuka/) do _archiv/.

.DESCRIPTION
  Používá "git mv", takže se zachová historie. Bez -Provest jen vypíše,
  co by se stalo (suchý běh).

.PARAMETER Provest
  Skutečně provede přesun. Bez tohoto přepínače se nic nemění.

.EXAMPLE
  .\nastroje\presun_archiv.ps1            # jen vypis, nic se nemeni
  .\nastroje\presun_archiv.ps1 -Provest   # provede presun
#>
param([switch]$Provest)

$koren = Split-Path -Parent $PSScriptRoot
Push-Location $koren

$archiv = Join-Path $koren '_archiv'
$kPresunu = @('3EA', 'vyuka')

if (-not $Provest) {
    Write-Host "SUCHY BEH - nic se nemeni. Pro provedeni pridej -Provest.`n" -ForegroundColor Yellow
}

if (-not (Test-Path $archiv)) {
    Write-Host "vytvorit slozku: _archiv"
    if ($Provest) { New-Item -ItemType Directory -Path $archiv | Out-Null }
}

foreach ($slozka in $kPresunu) {
    $zdroj = Join-Path $koren $slozka
    if (-not (Test-Path $zdroj)) {
        Write-Host "preskoceno (neexistuje): $slozka" -ForegroundColor DarkGray
        continue
    }
    $cil = Join-Path $archiv $slozka
    if (Test-Path $cil) {
        Write-Host "PRESKOCENO - v _archiv jiz existuje: $slozka" -ForegroundColor Red
        continue
    }
    Write-Host "presunout: $slozka  ->  _archiv\$slozka"
    if ($Provest) {
        git mv -- "$slozka" "_archiv/$slozka"
        if ($LASTEXITCODE -ne 0) {
            Write-Host "  git mv selhal, zkousim Move-Item" -ForegroundColor Yellow
            Move-Item -LiteralPath $zdroj -Destination $cil
        }
    }
}

if ($Provest) {
    Write-Host "`nHotovo. Zkontroluj 'git status' a pak commitni:" -ForegroundColor Green
    Write-Host "  git commit -m `"Presun starych podkladu do _archiv`""
    Write-Host "`nMapovani stary obsah -> nova temata je v plan\mapovani_starych_podkladu.md"
}

Pop-Location
