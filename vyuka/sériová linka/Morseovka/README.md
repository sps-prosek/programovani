* Zadání

Naprogramujte Arduino Uno tak, aby pomocí vestěvěné LED na pinu 13 bylo schopné vysílat Morseův kód zaslaný přes sériovou linku z PC. Komunikace mezi PC a Arduinem UNO bude probíhat na baudové rychlosti 19200 baud/s. Morseův kód se bude zasílat pomocí znaku "-" (pomlčka) a "." (tečka). Jiné znaky budou ignorovány. Časování Morseová kódu je následující. Tečka svítí 1 jednotku a pomlčka 3 jednotky, přičemž mezi každou tečkou a pomlčkou je LED zhasnutá 1 jednotku. Jednotka trvá 100 ms. Pro časování není povoleno používat funkci delay(). Během blikání bude příjem dalších znaků ignorován. Po dokončení blikání zaslaného kódu bude do PC přes sériovou linku zaslána zpráva "Přenos byl dokončen.". Maximální počet zaslaných znaků je 6. Každá sekvence teček a pomlček je zakončena lomítkem "/".

Například pro zaslanou zprávu "--.-/" bude LED blikat v následující sekvenci: 300 ms ON > 100 ms OFF > 300 ms ON > 100 ms OFF > 100 ms ON > 100 ms OFF > 300 ms ON > 100 ms OFF.
