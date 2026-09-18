# 11 – DC motor a H-můstek

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – analogové výstupy, možnosti připojení periférií
**Výsledky vzdělávání:** V5
**Učivo:** U4, U9, U13, U17

## Návaznost na předchozí bloky

Přímo navazuje na PWM (blok 07) a na oddělené napájení z bloku 10. Je to nejbližší
bod dotyku s ostatními předměty oboru Mechatronika – výkonová elektronika a pohony.

## Cíle tématu

Žák po probrání tématu:

- vysvětlí funkci H-můstku a jak se jím mění směr otáčení
- zapojí modul L298N / L9110 podle schématu, včetně napájení a společné země
- řídí otáčky PWM a směr dvojicí logických signálů
- popíše, proč nelze motor připojit přímo na pin, a co dělá zpětná dioda
- ošetří rozběh a zastavení (rampa) a vysvětlí, proč skokové reverzování škodí

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | DC motor, odběr, rušení, jiskření na komutátoru. H-můstek: 4 spínače, směr, brzda, volnoběh. Modul L298N/L9110 – piny IN1/IN2/ENA. PWM na ENA. Potenciometr jako zadavač otáček a směru. Zpětné diody, blokovací kondenzátor. | Motor mění otáčky i směr podle potenciometru; v klidové poloze stojí. |

## Klíčové pojmy

DC motor, H-můstek, L298N / L9110, směr otáčení, brzdění, PWM řízení otáček,
zpětná dioda, rušení, blokovací kondenzátor, oddělené napájení, společná zem

## Navržené úlohy

1. **Otáčky a směr** – potenciometr ve středu = stop, doleva/doprava = směr a rychlost.
2. **Rampa** – po stisku tlačítka motor plynule zrychlí na plné otáčky za 2 s a stejně zastaví.
3. **Ochrana proti překlopení** – zakázat okamžitou reverzaci: nejdřív zastavit, pak měnit směr.
4. **Joystick** – řízení motoru joystickem s mrtvým pásmem (spojení s blokem 10).

## Ověření měřením (U17)

Osciloskopem změřit napětí na motoru při různé střídě. Multimetrem změřit rozběhový
a jmenovitý proud a porovnat s dovoleným proudem modulu. Ukázat na osciloskopu zákmity
při jiskření a vliv blokovacího kondenzátoru.

## HW a SW

DC motor, modul L298N nebo L9110, zdroj 6–12 V, potenciometr / joystick, multimetr, osciloskop.

## Starší podklady k tomuto tématu

- `3EA/dc_motor/dc_motor_ovladany_joystickem/`
- `3EA/dc_motor/dc_motor_ovladany_joystickem_s_knihovnou/` – `motor.h` je hlavní ukázka pro blok 15
- `vyuka/H můstek/h_mustek_s_potenciometrem/` – přejmenovat na `h_mustek`

## Poznámky k výuce

<!-- Bezpečnost: motor mechanicky upevnit, jinak sjede ze stolu i s drátky. -->
