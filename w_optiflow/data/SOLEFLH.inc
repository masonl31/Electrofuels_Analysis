PARAMETER  SOLEFLH(AAA) "Full load hours for solar power (hours)"
/


DE_CS_A1                        1261
DE_NE_A1                        1105
DE_NW_A1                        1100

DK_E_Large                      1073
DK_E_Medium                     1073
DK_E_MedSmall                   1073
DK_E_Rural                      1073
DK_E_Small                      1073
DK_W_Large                      1010
DK_W_Medium                     1010
DK_W_MedSmall                   1010
DK_W_Rural                      1010
DK_W_Small                      1010

FI_R_Decen                      962
FI_R_Rural                      962
FI_R_Urban                      962

NO_M_Rural                      870
NO_N_Rural                      894
NO_O_Rural                      1044
NO_S_Rural                      1044

SE_M_Rural                      965
SE_M_Urban                      965
SE_N_Rural                      947
SE_S_Rural                      1003


DK_E_PV-20_29                   1030
DK_W_PV-20_29                   1031

FI_R_PV-20_29                   844
*DE_CS_PV-20_29                  1333
DE_CS_PV-20_29                  1170
DE_NE_PV-20_29                  1000
DE_NW_PV-20_29                  1000
NO_N_PV-20_29                   749
NO_M_PV-20_29                   875
NO_S_PV-20_29                   900
NO_O_PV-20_29                   900
SE_N_PV-20_29                   900
SE_M_PV-20_29                   954
SE_S_PV-20_29                   958



DK_E_PV-30_49                   1064
DK_W_PV-30_49                   1065

FI_R_PV-30_49                   872
*DE_CS_PV-30_49                  1333
DE_CS_PV-30_49                  1170
DE_NE_PV-30_49                  1025
DE_NW_PV-30_49                  1025
NO_N_PV-30_49                   775
NO_M_PV-30_49                   900
NO_S_PV-30_49                   925
NO_O_PV-30_49                   925
SE_N_PV-30_49                   950
SE_M_PV-30_49                   975
SE_S_PV-30_49                   978




DK_E_PV-50                      1098
DK_W_PV-50                      1099

FI_R_PV-50                      900
*DE_CS_PV-50                     1420
DE_CS_PV-50                     1170
DE_NE_PV-50                     1050
DE_NW_PV-50                     1050
NO_N_PV-50                      800
NO_M_PV-50                      900
NO_S_PV-50                      950
NO_O_PV-50                      950
SE_N_PV-50                      950
SE_M_PV-50                      1016
SE_S_PV-50                      1020








$ontext
DE_CS_A1                        1261
DE_NE_A1                        1105
DE_NW_A1                        1100

DK_E_Large                      1073
DK_E_Medium                     1073
DK_E_MedSmall                   1073
DK_E_Rural                      1073
DK_E_Small                      1073
DK_W_Large                      1010
DK_W_Medium                     1010
DK_W_MedSmall                   1010
DK_W_Rural                      1010
DK_W_Small                      1010

FI_R_Decen                      962
FI_R_Rural                      962
FI_R_Urban                      962

NO_M_Rural                      870
NO_N_Rural                      894
NO_O_Rural                      1044
NO_S_Rural                      1044

SE_M_Rural                      965
SE_M_Urban                      965
SE_N_Rural                      947
SE_S_Rural                      1003

*DK_E_PV-20_29                   1457
*DK_W_PV-20_29                   1457
DK_E_PV-20_29                   1134
DK_W_PV-20_29                   1067

*FI_R_PV-20_29                   1017
FI_R_PV-20_29                   900
DE_CS_PV-20_29                  1333
DE_NE_PV-20_29                  1168
DE_NW_PV-20_29                  1162
NO_N_PV-20_29                   945
NO_M_PV-20_29                   919
*NO_S_PV-20_29                   1103
*NO_O_PV-20_29                   1103
NO_S_PV-20_29                   1000
NO_O_PV-20_29                   1000

*SE_N_PV-20_29                   950
SE_N_PV-20_29                   1001
SE_M_PV-20_29                   1020
SE_S_PV-20_29                   1060


*DK_E_PV-30_49                   1504
*DK_W_PV-30_49                   1504
DK_E_PV-30_49                   1171
DK_W_PV-30_49                   1102

*FI_R_PV-30_49                   1050
FI_R_PV-30_49                   950
DE_CS_PV-30_49                  1376
DE_NE_PV-30_49                  1206
DE_NW_PV-30_49                  1200
NO_N_PV-30_49                   975
NO_M_PV-30_49                   949
*NO_S_PV-30_49                   1139
*NO_O_PV-30_49                   1139
NO_S_PV-30_49                   1050
NO_O_PV-30_49                   1050

SE_N_PV-30_49                   950
*SE_N_PV-30_49                   1033
SE_M_PV-30_49                   1053
SE_S_PV-30_49                   1094



*DK_E_PV-50                      1552
*DK_W_PV-50                      1452
DK_E_PV-50                      1208
DK_W_PV-50                      1137



*FI_R_PV-50                      1083
FI_R_PV-50                      950
DE_CS_PV-50                     1420
DE_NE_PV-50                     1244
DE_NW_PV-50                     1238
NO_N_PV-50                      1007
NO_M_PV-50                      979
*NO_S_PV-50                      1175
*NO_O_PV-50                      1175
NO_S_PV-50                      1100
NO_O_PV-50                      1100

SE_N_PV-50                      950
*SE_N_PV-50                      1066
SE_M_PV-50                      1086
SE_S_PV-50                      1129


$offtext

/;


SOLEFLH(AAA)$(SOLEFLH(AAA)=0 and RRRAAA('DK_W',AAA)AND SUM((Y,G)$(GDATA(G,'GDTYPE') EQ GSOLE),(AGKN(AAA,G) OR GKFX(Y,AAA,G)))) = SOLEFLH('DK_W_Large');
SOLEFLH(AAA)$(SOLEFLH(AAA)=0 and RRRAAA('DK_E',AAA)AND SUM((Y,G)$(GDATA(G,'GDTYPE') EQ GSOLE),(AGKN(AAA,G) OR GKFX(Y,AAA,G)))) = SOLEFLH('DK_E_Large');







































































































