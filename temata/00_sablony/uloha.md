# Úloha [NN] – [NÁZEV ÚLOHY]

**Téma:** [NN – název bloku] · **Obtížnost:** [základní / rozšiřující] · **Odhad času:** [30 min]

## Zadání

[Popis úlohy z pohledu chování zařízení – co má zařízení dělat, ne jak to naprogramovat.
Formulovat tak, aby bylo jednoznačně poznat, kdy je úloha hotová.]

## Co má být splněno

- [ ] [požadavek 1 – ověřitelný]
- [ ] [požadavek 2]
- [ ] [požadavek 3]
- [ ] Kód je opatřen hlavičkovým komentářem (jméno, úloha, datum) a komentáři u klíčových řádků.

## Zapojení

![Schéma zapojení](../obrazky/uloha_NN_zapojeni.png)

| Součástka | Pin Arduina | Poznámka |
|---|---|---|
| [LED] | [D9] | [+ rezistor 220 Ω na GND] |

## Kostra kódu

```cpp
// Úloha NN – [název]
// Autor:
// Datum:

const uint8_t PIN_[NAZEV] = [x];

void setup() {
  // TODO
}

void loop() {
  // TODO
}
```

## Nápověda

<details>
<summary>Nevím, jak začít</summary>

[Postupné navedení: rozděl si úlohu na …, nejdřív zkus …]
</details>

## Hodnocení

| Kritérium | Body |
|---|---:|
| Zařízení funguje podle zadání | 5 |
| Kód je čitelný (názvy, komentáře, rozdělení do funkcí) | 3 |
| Bez `delay()` tam, kde by blokoval reakci | 2 |
| **Celkem** | **10** |

## Rozšíření pro rychlejší

[Nepovinné zadání navíc.]

## Odevzdání

Soubor `.ino` (případně celou složku skici jako `.zip`) nahraj do Moodle,
úkol **[název úkolu]**, termín **[datum]**.
