# 02 – Digitální výstupy: LED a bzučák

**Rozsah:** 2 h (1 dvouhodinovka)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – digitální výstupy
**Výsledky vzdělávání:** V5
**Učivo:** U4, U8, U17

## Návaznost na 2. ročník

Cykly, podmínky a konstanty žák zná. Nové je, že výstupem programu není text na obrazovce,
ale **napětí na pinu**, a že pin má omezený proud.

## Cíle tématu

Žák po probrání tématu:

- zapojí LED s předřadným rezistorem podle schématu a spočítá jeho hodnotu
- rozliší zapojení LED proti zemi a proti napájení (aktivní úroveň H / L)
- nastaví pin jako výstup a řídí jej (`pinMode`, `digitalWrite`)
- rozliší aktivní a pasivní bzučák a ví, čím se každý budí (`tone()`)
- ověří proud pinem měřením a zdůvodní, proč nesmí překročit mez

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Pin jako výstup, dvě napěťové úrovně, zatížitelnost pinu (20 mA typ., 40 mA abs. max). Výpočet předřadného rezistoru. Zapojení podle schématu na nepájivém poli. Aktivní vs. pasivní bzučák, `tone()` / `noTone()`. Měření proudu LED. | Zapojí a rozbliká tři LED podle schématu, rozezní bzučák. |

## Klíčové pojmy

digitální výstup, `pinMode`, `digitalWrite`, `HIGH` / `LOW`, předřadný rezistor,
úbytek napětí na LED, zatížitelnost pinu, aktivní / pasivní bzučák, `tone()`

## Navržené úlohy

1. **Semafor** – tři LED, sekvence jako na křižovatce (včetně žluté).
2. **Výpočet rezistoru** – pro červenou (2,0 V) a modrou (3,2 V) LED při 10 mA; zapojit obě a změřit skutečný proud.
3. **Bzučák** – krátké pípnutí po startu desky, potom melodie ze tří tónů.
4. **Běžící světlo** – pět LED, světlo běží tam a zpět (cyklus `for`, pole pinů).

## Ověření měřením (U17)

Multimetrem změřit napětí na pinu v obou stavech a proud LED. Porovnat s výpočtem
a vysvětlit rozdíl. Kdo má osciloskop, zobrazí průběh na pinu bzučáku.

## HW a SW

LED (červená, zelená, žlutá), rezistory 220 Ω / 1 kΩ, aktivní i pasivní bzučák,
nepájivé pole, drátky, multimetr.

## Starší podklady k tomuto tématu

- `3EA/zapinani_bzucaku_prikazem_z_pc/` – rozdělit: samotný bzučák sem, příkaz z PC do bloku 08

## Poznámky k výuce

<!-- Označit aktivní a pasivní bzučáky, jinak se pomíchají. -->
