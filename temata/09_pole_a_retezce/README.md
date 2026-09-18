# 09 – Pole a řetězce: parsování příkazů

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – komunikační sběrnice, rozdělení paměti
**Výsledky vzdělávání:** V4
**Učivo:** U7, U12

## Návaznost na 2. ročník

Pole (i vícerozměrná), ukazatele a práce s pamětí jsou probrané. **Neopakujeme je** – blok
ukazuje, jak se tytéž prostředky chovají v 2 kB SRAM: proč se nepoužívá `String`,
proč se nealokuje dynamicky a jak se textové konstanty dostanou do Flash (`F()`, `PROGMEM`).

## Cíle tématu

Žák po probrání tématu:

- složí přijaté znaky do pole `char` zakončeného nulou a pozná konec příkazu
- rozloží příkaz na část a parametr (`funkce hodnota`) bez použití třídy `String`
- převede text na číslo (`atoi`, `strtol`) a ošetří neplatný vstup
- vysvětlí, proč `String` v dlouho běžícím programu vede k fragmentaci SRAM
- přesune textové konstanty do Flash pomocí `F()` a odůvodní to výpisem využití paměti

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Buffer přijatých znaků, ukončovací znak, přetečení bufferu. `strcmp`, `strtok`, `atoi`. `String` vs. `char[]` – ukázka úbytku volné SRAM. `F()` a `PROGMEM`, výpis volné paměti. | Deska rozumí příkazům typu `led 1`, `pwm 128`, `stav` a na neznámý příkaz odpoví chybou. |

## Klíčové pojmy

pole `char`, ukončovací nula, buffer, přetečení bufferu, `strcmp`, `strtok`, `atoi`,
`String` a fragmentace haldy, SRAM vs. Flash, `F()`, `PROGMEM`

## Navržené úlohy

1. **Příkazová řádka zařízení** – příkazy `led on`, `led off`, `pwm <0-255>`, `stav`; neznámý příkaz → `ERR`.
2. **Počítání znaků ve větě** – načíst větu a spočítat znaky, slova a samohlásky.
3. **Součet čísel z příkazu** – `soucet 12 30` vrátí `42`; ošetřit chybný vstup.
4. **Paměťový test** – tentýž program s `String` a s `char[]`, porovnat volnou SRAM.

## HW a SW

Arduino UNO/Nano, sériový monitor. Bez dalšího HW.

## Starší podklady k tomuto tématu

- `3EA/uart/pole_znaku/`
- `3EA/uart/pocitani_znaku_ve_vete/`
- `3EA/uart/scitani_jednocifernych_cisel/` – rozšířit na víceciferná
- `3EA/uart/pouziti_stringu/` – použít jako odstrašující příklad při porovnání paměti

## Poznámky k výuce

<!-- Pole a ukazatele NEVYKLÁDAT znovu, jen připomenout. Těžiště je v omezené paměti. -->
