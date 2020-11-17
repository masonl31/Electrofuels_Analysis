PARAMETER DH2(YYY,CCCRRRAAA)  'Yearly demand for hydrogen at a Regional level(MWh of H2)'

/

$ontext

*------------------------------------------------------
*DATA THAT ARE SCENARIO DEPENDANT
*------------------------------------------------------
*W I N D    E N E R G Y    S C E N A R I O

*Hydrogen consumption for upgrading of BIOGAS in rural areas
*Demand is estimated according to the biogas potential for DK and
*assuming in East and West the same % of biogas is upgraded through methanation

2014   .   DK_E_Rural       0
2014   .   DK_W_Rural       0
2020   .   DK_E_Rural       34806
2020   .   DK_W_Rural       462426
2025   .   DK_E_Rural       63811
2025   .   DK_W_Rural       847780
2030   .   DK_E_Rural       92817
2030   .   DK_W_Rural       1233135
2035   .   DK_E_Rural       121822
2035   .   DK_W_Rural       1618490
2040   .   DK_E_Rural       228982
2040   .   DK_W_Rural       3042189
2045   .   DK_E_Rural       336142
2045   .   DK_W_Rural       4465889
2050   .   DK_E_Rural       443302
2050   .   DK_W_Rural       5889589


*Hydrogen consumption for biorefineries. Biorefinery distribution is exogenously given, following the indications of the FV modellen

2025   .   DK_CA_KBH               480177
2025   .   DK_CA_Odense            134167
2025   .   DK_CA_TVIS              91798
2025   .   DK_CA_Aal               91798
2025   .   DK_CA_Aarhus            162413
2030   .   DK_CA_KBH               911219
2030   .   DK_CA_Odense            276939
2030   .   DK_CA_TVIS              192071
2030   .   DK_CA_Aal               196537
2030   .   DK_CA_Aarhus            343940
2035   .   DK_CA_KBH               1327835
2035   .   DK_CA_Odense            426279
2035   .   DK_CA_TVIS              298885
2035   .   DK_CA_Aal               298885
2035   .   DK_CA_Aarhus            529174
2040   .   DK_CA_Esb               156190
2040   .   DK_CA_Hern              101863
2040   .   DK_CA_KAL               81490
2040   .   DK_CA_KBH               2465087
2040   .   DK_CA_Odense            733414
2040   .   DK_CA_TVIS              509315
2040   .   DK_CA_Aal               516106
2040   .   DK_CA_Aarhus            909977
2045   .   DK_CA_Esb               360922
2045   .   DK_CA_Hern              243230
2045   .   DK_CA_KAL               196153
2045   .   DK_CA_KBH               3569992
2045   .   DK_CA_Odense            1019998
2045   .   DK_CA_TVIS              706152
2045   .   DK_CA_Aal               713998
2045   .   DK_CA_Aarhus            1255382
2050   .   DK_CA_Esb               588804
2050   .   DK_CA_Hern              392536
2050   .   DK_CA_KAL               315736
2050   .   DK_CA_KBH               4676301
2050   .   DK_CA_Odense            1288543
2050   .   DK_CA_TVIS              896007
2050   .   DK_CA_Aal               904540
2050   .   DK_CA_Aarhus            1595745

*------------------------------------------------------
*DATA THAT ARE NOT SCENARIO DEPENDANT
*------------------------------------------------------

2014   .    DE_CS         0
2014   .    DE_NE         0
2014   .    DE_NW         0
2014   .    NO_M          0
2014   .    NO_N          0
2014   .    NO_O          0
2014   .    NO_S          0
2014   .    SE_M          0
2014   .    SE_N          0
2014   .    SE_S          0
2014   .    FI_R          0
2020   .    DE_CS         256651
2020   .    DE_NE         3777
2020   .    DE_NW         32497
2020   .    NO_M          6613
2020   .    NO_N          6613
2020   .    NO_O          12650
2020   .    NO_S          29117
2020   .    SE_M          95805
2020   .    SE_N          26156
2020   .    SE_S          24669
2020   .    FI_R          83805
2025   .    DE_CS         522973
2025   .    DE_NE         7696
2025   .    DE_NW         66218
2025   .    NO_M          10617
2025   .    NO_N          10617
2025   .    NO_O          20307
2025   .    NO_S          46742
2025   .    SE_M          148001
2025   .    SE_N          40406
2025   .    SE_S          38110
2025   .    FI_R          125939
2030   .    DE_CS         789295
2030   .    DE_NE         11615
2030   .    DE_NW         99939
2030   .    NO_M          14620
2030   .    NO_N          14620
2030   .    NO_O          27964
2030   .    NO_S          64366
2030   .    SE_M          200196
2030   .    SE_N          54655
2030   .    SE_S          51550
2030   .    FI_R          168073
2035   .    DE_CS         764709
2035   .    DE_NE         11253
2035   .    DE_NW         96826
2035   .    NO_M          24127
2035   .    NO_N          24127
2035   .    NO_O          46148
2035   .    NO_S          106222
2035   .    SE_M          193907
2035   .    SE_N          52938
2035   .    SE_S          49931
2035   .    FI_R          162793
2040   .    DE_CS         740123
2040   .    DE_NE         10891
2040   .    DE_NW         93713
2040   .    NO_M          33634
2040   .    NO_N          33634
2040   .    NO_O          64333
2040   .    NO_S          148078
2040   .    SE_M          187618
2040   .    SE_N          51221
2040   .    SE_S          48311
2040   .    FI_R          157513
2045   .    DE_CS         629423
2045   .    DE_NE         9262
2045   .    DE_NW         79697
2045   .    NO_M          54793
2045   .    NO_N          54793
2045   .    NO_O          104806
2045   .    NO_S          241238
2045   .    SE_M          108554
2045   .    SE_N          29636
2045   .    SE_S          27952
2045   .    FI_R          123797
2050   .    DE_CS         518723
2050   .    DE_NE         7633
2050   .    DE_NW         65680
2050   .    NO_M          75953
2050   .    NO_N          75953
2050   .    NO_O          145280
2050   .    NO_S          334398
2050   .    SE_M          29489
2050   .    SE_N          8051
2050   .    SE_S          7593
2050   .    FI_R          90081

$offtext

/;
















