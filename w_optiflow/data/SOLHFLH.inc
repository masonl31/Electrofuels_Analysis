*Last time modified (Amalia, 07-05-2015)
*THis parameter was expressed before a scalar between m2 and MWh of solar thermal, now it expresses the real full load hours of operation
PARAMETER  SOLHFLH(AAA) "Full load hours for solar heat (hours)"


/
*DK_E_MedSmall                   1073
*DK_W_MedSmall                   1010

FI_R_Decen                      962
FI_R_Rural                      962

NO_M_Rural                      870
NO_N_Rural                      894
NO_O_Rural                      1044
NO_S_Rural                      1044

SE_M_Rural                      965
SE_N_Rural                      947
SE_S_Rural                      1000

DE_CS_A1                        1073
DE_NE_A1                        1073
DE_NW_A1                        1073


$ontext
DK_CA_KBH                       1700
DK_CA_Aarhus                    1700
DK_CA_Odense                    1700
DK_CA_Aal                       1700
DK_CA_TVIS                      1700
DK_CA_Esb                       1700
DK_CA_Hern                      1700
DK_CA_Kal                       1700
DK_MA_NrdOstSj                  1700
DK_CA_Randers                   1700
DK_MA_Holst                     1700
DK_MA_Silk                      1700
DK_MA_Hil                       1700
DK_MA_Hjoerring                 1700
DK_MA_Sndborg                   1700
DK_MA_Viborg                    1700
DK_MA_Horsens                   1700
DK_MAM_Nyk                      1700
DK_MA_Grenaa                    1700
DK_MAM_Frdhavn                  1700
DK_MAM_Naestved                 1700
DK_MAM_Thisted                  1700
DK_MAM_Slagelse                 1700
DK_MAM_Nyborg                   1700
DK_MAM_Svend                    1700
DK_CA_Roenne                    1700
DK_MAM_Had                      1700
DK_MAM_Aars                     1700
DK_MAM_Hammel                   1700
DK_E_DTU                        1700
DK_MAM_Skagen                   1700
DK_MAM_Hobro                    1700
DK_CA_Aab                       1700
DK_MAM_NrAlslev                 1700
$offtext


/;

SOLHFLH(AAA)$(SOLHFLH(AAA)=0 and RRRAAA('DK_W',AAA)AND SUM((Y,G)$(GDATA(G,'GDTYPE') EQ GSOLH),(AGKN(AAA,G) OR GKFX(Y,AAA,G)))) = 850;
SOLHFLH(AAA)$(SOLHFLH(AAA)=0 and RRRAAA('DK_E',AAA)AND SUM((Y,G)$(GDATA(G,'GDTYPE') EQ GSOLH),(AGKN(AAA,G) OR GKFX(Y,AAA,G)))) = 850;



