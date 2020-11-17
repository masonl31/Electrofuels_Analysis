* PARAMETER WAVE_VAR_T contains the description of seasonal and daily variation
* of the wave power production.
* Units: (see description above under DE_VAR_T)

* Data source:

PARAMETER  WAVE_VAR_T(AAA,SSS,TTT) 'Variation of the wave power generation'  /
*$if EXIST 'DK_W_wave.inc' $INCLUDE 'DK_W_wave.inc';              Hans temporary out
*$if not EXIST 'DK_W_wave.inc' $INCLUDE '..\data/DK_W_wave.inc'   Hans temporary out  
/;

* Wave power profile copied to other offshore areas.
WAVE_VAR_T(AAAOFFSHORE(IA),SSS,TTT)$(not sameas(AAAOFFSHORE,'DK_W_Offshore10')  and SUM(IGWAVE$(IAGK(IA,IGWAVE) or AGKN(IA,IGWAVE)),1))  = WAVE_VAR_T('DK_W_Offshore10',SSS,TTT);
