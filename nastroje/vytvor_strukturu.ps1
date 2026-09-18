<#
.SYNOPSIS
  Dotvoří prázdné podsložky ve všech tematických blocích.

.DESCRIPTION
  V každé složce temata/NN_* vytvoří podsložky prezentace, hodiny, ulohy, kod,
  obrazky a moodle. Do každé prázdné složky vloží .gitkeep, aby ji Git udržel.
  Skript je idempotentní – nic nepřepisuje, jen doplňuje chybějící.

.EXAMPLE
  .\nastroje\vytvor_strukturu.ps1
#>

$koren = Split-Path -Parent $PSScriptRoot
$podslozky = @('prezentace', 'hodiny', 'ulohy', 'kod', 'obrazky', 'moodle')

Write-Host "Koren repozitare: $koren`n"

# --- tematicke bloky ------------------------------------------------------
$temata = Get-ChildItem -Path (Join-Path $koren 'temata') -Directory |
          Where-Object { $_.Name -match '^\d\d_' -and $_.Name -ne '00_sablony' }

foreach ($tema in $temata) {
    foreach ($p in $podslozky) {
        $cesta = Join-Path $tema.FullName $p
        if (-not (Test-Path $cesta)) {
            New-Item -ItemType Directory -Path $cesta | Out-Null
            Write-Host "  + $($tema.Name)\$p"
        }
        $keep = Join-Path $cesta '.gitkeep'
        if (-not (Get-ChildItem -Path $cesta -Force | Where-Object { $_.Name -ne '.gitkeep' })) {
            if (-not (Test-Path $keep)) { New-Item -ItemType File -Path $keep | Out-Null }
        }
    }
}

# --- ostatni slozky -------------------------------------------------------
$dalsi = @('_archiv', 'spolecne\obrazky', 'spolecne\snippety', 'spolecne\styl\loga')
foreach ($d in $dalsi) {
    $cesta = Join-Path $koren $d
    if (-not (Test-Path $cesta)) {
        New-Item -ItemType Directory -Path $cesta | Out-Null
        Write-Host "  + $d"
    }
    $keep = Join-Path $cesta '.gitkeep'
    if (-not (Get-ChildItem -Path $cesta -Force | Where-Object { $_.Name -ne '.gitkeep' })) {
        if (-not (Test-Path $keep)) { New-Item -ItemType File -Path $keep | Out-Null }
    }
}

Write-Host "`nHotovo. Struktura je kompletni."
