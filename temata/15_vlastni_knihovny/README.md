# 15 – Vlastní knihovny a správa verzí

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – vytváření knihoven, systémy správy verzí
**Výsledky vzdělávání:** V6, V7
**Učivo:** U14, U15

## Návaznost na 2. ročník

Vlastní knihovnu funkcí a makra preprocesoru má žák probrané ve 2. ročníku. Tady se to
převádí na **formát knihovny pro Arduino** (`.h` + `.cpp`, případně třída) a doplňuje se
**správa verzí** – zavedená už v bloku 01, tady systematicky před závěrečným projektem.

## Cíle tématu

Žák po probrání tématu:

- rozdělí program do `.h` a `.cpp`, použije hlavičkovou stráž (`#pragma once` / `#ifndef`)
- rozhodne, co patří do veřejného rozhraní knihovny a co zůstane skryté
- vloží knihovnu do skici, případně ji nainstaluje jako knihovnu Arduino IDE (`library.properties`)
- napíše ke knihovně krátké README a ukázkovou skicu (`examples/`)
- vede projekt v gitu: `status`, `add`, `commit`, `log`, `diff`, `.gitignore`, větev, návrat k dřívější verzi

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Z funkcí (blok 06) ke knihovně: `.h` + `.cpp`, stráž hlavičky, veřejné vs. interní. Ukázka na `motor.h` z bloku 11. Struktura knihovny pro Arduino IDE, `library.properties`, `examples/`. Git v praxi: co commitovat a co ne, srozumitelná zpráva commitu, návrat ke starší verzi, větev pro experiment. | Vlastní knihovna `motor` / `blikac` použitá ve dvou různých skicách; repozitář s historií a `.gitignore`. |

## Klíčové pojmy

hlavičkový soubor `.h`, implementace `.cpp`, `#pragma once`, hlavičková stráž, rozhraní vs. implementace,
`library.properties`, `examples/`, git: `add`, `commit`, `log`, `diff`, `.gitignore`, větev

## Navržené úlohy

1. **Knihovna motoru** – převést `motor.h` z bloku 11 na knihovnu s `.h` a `.cpp` a použít ji ve dvou úlohách.
2. **Knihovna blikače** – neblokující blikání z bloku 04 zabalené do knihovny s rozhraním `zacni(perioda)`, `obsluz()`.
3. **Historie** – zanést do programu chybu, commitnout, najít ji v `diff` a vrátit se k funkční verzi.
4. **Příprava projektu** – založit repozitář závěrečného projektu s README a prvním commitem.

## HW a SW

Beze změny podle zvolené knihovny (motor / LED). Git, GitHub účet.

## Starší podklady k tomuto tématu

- `3EA/dc_motor/dc_motor_ovladany_joystickem_s_knihovnou/` – `motor.h` je hlavní ukázka
- `3EA/dc_motor/dc_motor_ovladany_joystickem/` – `muj_motor.h` jako první, jednodušší verze

## Poznámky k výuce

<!-- Blok zařadit těsně před projekt – žák si rovnou založí repozitář projektu. -->
