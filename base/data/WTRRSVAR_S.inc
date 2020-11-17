* PARAMETER WTRRSVAR_S contains the description of the seasonal variation of the
* amount of water inflow
* to the reservoirs for each installed MW capacity of hydropower with storage,
* Unit: (none)

* Observe: the table is specified directly in the present sheet.

* Data source:  Nordel

TABLE WTRRSVAR_S(AAA,SSS)  'Variation of the water inflow to reservoirs'
                 S01           S02           S03           S04           S05           S06           S07           S08
SE_N_Rural    870434        817799        757277        733767        822964        823203        834463        765678
NO_S_Rural   1450723       1362998       1262129       1222945       1371607       1372005       1390771       1276129

+                S09           S10           S11           S12           S13           S14           S15           S16
SE_N_Rural    853649        597501        557507        540084        464684        432662        430186        480870
NO_S_Rural   1422749        995835        929178        900140        774473        721103        716977        801451

+                S17           S18           S19           S20           S21           S22           S23           S24
SE_N_Rural    434677        520553        411666        688162        607012        330298        342297        219184
NO_S_Rural    724462        867588        686111       1146937       1011686        550496        570495        365307

+                S25           S26           S27           S28           S29           S30           S31           S32
SE_N_Rural    434041        296021        247570        375879        519256        488248        528843        560576
NO_S_Rural    723402        493369        412617        626466        865426        813747        881405        934294

+                S33           S34           S35           S36           S37           S38           S39           S40
SE_N_Rural    595472        491599        570678        588404        570755        582851        481280        569697
NO_S_Rural    992453        819332        951130        980673        951258        971418        802133        949495

+                S41           S42           S43           S44           S45           S46           S47           S48
SE_N_Rural    853638        783124        450189        825629        572255        598488        489413        528319
NO_S_Rural   1422729       1305206        750315       1376049        953758        997480        815688        880532

+                S49           S50           S51           S52
SE_N_Rural    566349        655690        810443        777368
NO_S_Rural    943915       1092817       1350738       1295614
;

WTRRSVAR_S(IA,SSS)$(WTRRSVAR_S(IA,SSS) EQ 0) = WTRRSVAR_S('NO_S_Rural',SSS) ;

