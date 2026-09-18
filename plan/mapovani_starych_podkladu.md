# Mapování starých podkladů na nová témata

Původní obsah repozitáře (`3EA/` a `vyuka/`) se skriptem `nastroje/presun_archiv.ps1`
přesune do `_archiv/`. Tato tabulka říká, kam který kus patří v nové struktuře.
Cíl je `temata/<téma>/kod/`, u obrázků `temata/<téma>/obrazky/`.

| Původní cesta (nyní v `_archiv/`) | Téma | Poznámka |
|---|---|---|
| `3EA/init/` | 01 | Kostra skici, základ pro první hodinu. |
| `3EA/zapinani_bzucaku_prikazem_z_pc/` | 02 + 08 | Bzučák do 02, příkaz z PC do 08. Rozdělit na dvě skici. |
| `3EA/nabezna_hrana/` | 03 | |
| `3EA/nabezna_hrana_s_funkci/` | 03 → 06 | Použít v 06 jako příklad refaktoringu do funkce. |
| `3EA/tlacitko/debounce/` | 03 | Včetně `README.MD` a `wiring.png` → `obrazky/`. |
| `3EA/cyklisticka_blikacka/rezimy/` | 04 | Výchozí verze bez přepínání. |
| `3EA/cyklisticka_blikacka/prepinani_rezimu/` | 05 | |
| `3EA/cyklisticka_blikacka/rezimy_s_prepinanim/` | 05 | |
| `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_rezim_0_1/` | 05 | Postupné verze – dobré jako krokovaný výklad. |
| `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_rezim_0_1_2/` | 05 | |
| `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_rezim_0_1_2_3/` | 05 | |
| `3EA/cyklisticka_blikacka/rezimy_s_prepinanim_a_blikanim/` | 05 | Cílová verze úlohy. |
| `3EA/uart/ovladani_led_pres_uart/` | 08 | |
| `3EA/uart/pouziti_stringu/` | 08 | |
| `3EA/uart/pole_znaku/` | 09 | |
| `3EA/uart/pocitani_znaku_ve_vete/` | 09 | |
| `3EA/uart/scitani_jednocifernych_cisel/` | 09 | |
| `vyuka/sériová linka/Morseovka/` | 08 | Přejmenovat bez diakritiky: `seriova_linka` → skica `morseovka`. |
| `3EA/servo/ovladani_serva_joystickem/` | 10 | |
| `vyuka/servo/servo_s_joystickem/` | 10 | Duplikát předchozího – ponechat jednu verzi. |
| `vyuka/servo/servo_s_krokovanim/` | 10 | |
| `3EA/servo/ovladani_serva_mpu6050_bez_vypoctu_uhlu/` | 13 | Potřebuje 10 i 13. |
| `vyuka/servo/servo_s_MPU6050/` | 13 | |
| `3EA/dc_motor/dc_motor_ovladany_joystickem/` | 11 | `muj_motor.h` navíc do 15. |
| `3EA/dc_motor/dc_motor_ovladany_joystickem_s_knihovnou/` | 11 + 15 | `motor.h` je hlavní ukázka pro 15. |
| `vyuka/H můstek/h_mustek_s_potenciometrem/` | 11 | Přejmenovat `h_mustek`. |
| `3EA/enkoder/enkoder_bez_preruseni/` | 12 | `CW.JPG`, `CCW.JPG` → `obrazky/`, `README.MD` je základ výkladu. |
| `3EA/enkoder/enkoder_s_preruseni/` | 12 | |
| `3EA/enkoder/pcb_encoder_filter/` | 12 | KiCad projekt – nechat v archivu, v tématu jen odkaz a obrázek schématu. |
| `3EA/zrychleni/jednoduche_cteni_senzoru_po_i2c/` | 13 | |
| `3EA/zrychleni/filtrace_mereneho_zrychleni/` | 13 | |
| `vyuka/DHT11/dht11_a_lcd_displej/` | 13 + 14 | |
| `vyuka/LCD displej/lcd_displej_s_tlacitkem/` | 14 | |
| `vyuka/LCD displej/lcd_displej_s_tlacitkem_pomoci_funkci/` | 14 → 06 | Dobrá ukázka rozdělení do funkcí. |
| `vyuka/LCD displej/lcd_displej_s_enkoderem/` | 14 | Potřebuje 12. |
| `vyuka/LCD displej/vizualizace_hlasitosti/` | 07 + 14 | Bargraf na LCD z analogového vstupu. |

## Postup přenosu

1. Spustit `nastroje/presun_archiv.ps1` (přesune `3EA/` a `vyuka/` do `_archiv/`).
2. Téma po tématu: zkopírovat skicu do `temata/<téma>/kod/`, přejmenovat bez diakritiky,
   projít kód (komentáře česky, jednotné názvy pinů) a doplnit hlavičkový komentář.
3. Obrázky a README z původní složky rozdělit do `obrazky/` a do textu prezentace.
4. V `README.md` tématu odškrtnout přenesené položky v sekci „Starší podklady“.

Archiv se nemaže – zůstává jako záloha, dokud nejsou všechna témata přenesená.
