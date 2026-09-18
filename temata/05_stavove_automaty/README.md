# 05 – Stavové automaty: cyklistická blikačka

**Rozsah:** 4 h (2 dvouhodinovky)
**Zařazení dle ŠVP:** *Elektronické obvody s mikroprocesorem* – digitální vstupy a výstupy, časovače
**Výsledky vzdělávání:** V4, V8 (příprava)
**Učivo:** U8, U10

## Návaznost na 2. ročník

Navazuje přímo na **vývojové diagramy a dekompozici problému** z úvodního bloku 2. ročníku
a na `switch` ze základů programování. Nová je myšlenka, že **stav programu je proměnná**
a chování se řídí podle ní.

## Cíle tématu

Žák po probrání tématu:

- nakreslí stavový diagram zadaného chování (stavy, přechody, podmínky přechodu)
- převede stavový diagram do kódu pomocí `switch` a proměnné stavu
- kombinuje stavový automat s neblokujícím časováním z bloku 04
- rozšíří hotový automat o další stav bez přepisování zbytku programu
- zdůvodní, proč je stavový automat čitelnější než vnořené podmínky

## Rozpis hodin

| Blok | Náplň | Výstup žáka |
|---|---|---|
| 1 | Stav, přechod, podmínka. Stavový diagram na tabuli. Zápis pomocí `enum` + `switch`. Přepínání režimů tlačítkem – blikačka s režimy 0/1. | Blikačka přepíná dva režimy tlačítkem. |
| 2 | Postupné rozšiřování na 3 a 4 režimy (vypnuto / trvale svítí / pomalu bliká / rychle bliká). Časování uvnitř stavu. Tabulka přechodů jako dokumentace. | Hotová cyklistická blikačka se čtyřmi režimy + stavový diagram v dokumentaci. |

## Klíčové pojmy

stav, stavový diagram, přechod, `enum`, `switch`, konečný automat,
vstupní / výstupní akce stavu, tabulka přechodů

## Navržené úlohy

1. **Cyklistická blikačka** – 4 režimy přepínané jedním tlačítkem, každý s vlastním časováním.
2. **Stavový diagram** – nejdřív nakreslit, teprve pak psát kód; diagram je součástí odevzdání.
3. **Přidání režimu** – rozšířit hotový automat o pátý režim (dvojblik) a změřit, kolik řádků bylo nutné změnit.
4. **Semafor s tlačítkem pro chodce** – automat s časovanými i podmíněnými přechody.

## Ověření měřením (U17)

Osciloskopem ověřit délky jednotlivých fází blikání v každém režimu.

## HW a SW

LED (více kusů), tlačítko, rezistory, osciloskop.

## Starší podklady k tomuto tématu

- `3EA/cyklisticka_blikacka/prepinani_rezimu/`
- `3EA/cyklisticka_blikacka/rezimy_s_prepinanim/`
- `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_rezim_0_1/` … `_0_1_2_3/` – postupné verze, dobré jako krokovaný výklad
- `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_a_blikanim/` – cílová verze úlohy

## Poznámky k výuce

<!-- Trvat na diagramu před kódem. Kdo začne kódem, skončí u vnořených ifů. -->
