* Ranamed from GEFFDERATE,
TABLE GEFFRATE(AAA,GGG) "Reduction in fuel efficiency (fraction)"
               DK_E_Rural_WI
DK_CA_Kal      1

;

GEFFRATE(IA,G)$((IAGK(IA,G) or AGKN(IA,G)) and GEFFRATE(IA,G) EQ 0) = 1;
