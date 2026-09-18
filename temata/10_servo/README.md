# 10 – Modelářské servo

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – analogové výstupy, možnosti připojení periférií
**Výsledky vzdělávání:** V5
**Učivo:** U4, U9, U13

## Návaznost na 2. ročník a na předchozí bloky

Navazuje na PWM (blok 07) a na neblokující časování (blok 04). Poprvé se objevuje
**akční člen s vlastní spotřebou** – tím se otevírá téma odděleného napájení a společné země,
které pokračuje v bloku 11.

## Cíle tématu

Žák po probrání tématu:

- popíše řídicí signál modelářského serva (perioda 20 ms, šířka pulzu 1–2 ms) a odliší jej od PWM pro jas LED
- připojí servo podle schématu, včetně odděleného napájení a společné země
- použije knihovnu `Servo` (`attach`, `write`, `writeMicroseconds`) a vysvětlí, co dělá uvnitř
- najde krajní polohy konkrétního kusu serva a omezí rozsah, aby nedrhlo
- ovládá polohu serva potenciometrem nebo joystickem plynule a bez `delay()`

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Stavba serva (motor, převodovka, potenciometr, regulátor). Řídicí signál, měření na osciloskopu. Knihovna `Servo` a kolize s Timerem1 / `analogWrite` na pinech 9 a 10. Napájení: proč SG90 z 5 V pinu resetuje desku. Joystick jako dva analogové vstupy + tlačítko. | Servo sleduje polohu potenciometru / joysticku; pohyb je plynulý a bez zákmitů. |

## Klíčové pojmy

modelářské servo, šířka pulzu, perioda 20 ms, `Servo.attach/write/writeMicroseconds`,
krajní polohy, oddělené napájení, společná zem, joystick, mrtvé pásmo (dead zone)

## Navržené úlohy

1. **Servo potenciometrem** – poloha 0–180° podle potenciometru.
2. **Servo joystickem** – s mrtvým pásmem kolem středu, aby servo v klidu nekmitalo.
3. **Krokování** – tlačítky posouvat po 10°, meze hlídat softwarově.
4. **Plynulý přejezd** – po stisku tlačítka servo přejede z 0° na 180° za 3 s, program mezitím dál reaguje.

## Ověření měřením (U17)

Osciloskopem změřit šířku pulzu pro `write(0)`, `write(90)` a `write(180)` a ověřit periodu.
Multimetrem změřit proudový odběr serva naprázdno a při zatížení.

## HW a SW

Servo SG90 (u MG996R vlastní zdroj), potenciometr nebo joystick modul, externí 5 V zdroj,
osciloskop, multimetr. Knihovna `Servo` (součást IDE).

## Starší podklady k tomuto tématu

- `3EA/servo/ovladani_serva_joystickem/`
- `vyuka/servo/servo_s_joystickem/` – duplikát, ponechat jednu verzi
- `vyuka/servo/servo_s_krokovanim/`

## Poznámky k výuce

<!-- Servo napájené z desky resetuje Arduino v půlce hodiny. Oddělený zdroj připravit dopředu. -->
