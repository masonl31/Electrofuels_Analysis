*Last time modified (Amalia, 02-06-2015)
PARAMETER DE(YYY,RRR) "Gross Annual electricity Demand (MWh)"
* Power grid loss differ depending of the country
* Germany: 6.4%, Finland: 6.1%, Norway: 8.9% & Sweden: 10.3% (References are the same than for DE.inc data)
* Grid loss in Denmark are the ones assumed by the Danish Energy Agency in their Energiscenarier report from 2014
*Data for Denmark : Energiscenarier frem 2035 and 2050 (ENS, 2014)
*Data for Norway, Sweden and Finland: Nordic Energy Technology Perspectives
*Data for Germany: Fjernvarmeanalyse - bilagsrapport
*                  MODELBEREGNINGER AF SCENARIER FOR FJERN-VARMENS UDVIKLING I FREMTIDENS ENERGISYSTEM
*                  by EA - Energy Analysis, 21 1 2014

/

*________________________________________________________________________
* D E N M A R K
*________________________________________________________________________



*W I N D    E N E R G Y    S C E N A R I O

*Electricity demand for transport

2014   .   DK_E_EV      0
2014   .   DK_W_EV      0
2020   .   DK_E_EV      390954
2020   .   DK_W_EV      583426
2025   .   DK_E_EV      716749
2025   .   DK_W_EV      1069615
2030   .   DK_E_EV      1042544
2030   .   DK_W_EV      1555804
2035   .   DK_E_EV      1368338
2035   .   DK_W_EV      2041993
2040   .   DK_E_EV      2519748
2040   .   DK_W_EV      3760259
2045   .   DK_E_EV      3671157
2045   .   DK_W_EV      5478525
2050   .   DK_E_EV      4822566
2050   .   DK_W_EV      7196791



*Electricity demand for process heat

2014   .   DK_E_Industry     0
2014   .   DK_W_Industry     0
2020   .   DK_E_Industry     58443
2020   .   DK_W_Industry     87215
2025   .   DK_E_Industry     107146
2025   .   DK_W_Industry     159895
2030   .   DK_E_Industry     155848
2030   .   DK_W_Industry     232575
2035   .   DK_E_Industry     204551
2035   .   DK_W_Industry     305254
2040   .   DK_E_Industry     419522
2040   .   DK_W_Industry     626059
2045   .   DK_E_Industry     634493
2045   .   DK_W_Industry     946863
2050   .   DK_E_Industry     849464
2050   .   DK_W_Industry     1267668


$ontext

*B I O M A S S    S C E N A R I O

*Electricity demand for transport

2014   .   DK_E_EV      0
2014   .   DK_W_EV      0
2020   .   DK_E_EV      91505
2020   .   DK_W_EV      136555
2025   .   DK_E_EV      167760
2025   .   DK_W_EV      250351
2030   .   DK_E_EV      244015
2030   .   DK_W_EV      364147
2035   .   DK_E_EV      320269
2035   .   DK_W_EV      477943
2040   .   DK_E_EV      423609
2040   .   DK_W_EV      632159
2045   .   DK_E_EV      526950
2045   .   DK_W_EV      786375
2050   .   DK_E_EV      630290
2050   .   DK_W_EV      940591


*Electricity demand for process heat

2014   .   DK_E_Industry     0
2014   .   DK_W_Industry     0
2020   .   DK_E_Industry     8369
2020   .   DK_W_Industry     12489
2025   .   DK_E_Industry     15342
2025   .   DK_W_Industry     22896
2030   .   DK_E_Industry     22316
2030   .   DK_W_Industry     33303
2035   .   DK_E_Industry     29290
2035   .   DK_W_Industry     43710
2040   .   DK_E_Industry     57717
2040   .   DK_W_Industry     86132
2045   .   DK_E_Industry     86144
2045   .   DK_W_Industry     128554
2050   .   DK_E_Industry     114571
2050   .   DK_W_Industry     170977


$offtext

* C L A S S I C    E L E C T R I C I T Y    D E M A N D - independent of the energy scenario modelled

2014   .   DK_E      13419025
2014   .   DK_W      20025420
2020   .   DK_E      13089835
2020   .   DK_W      19534164
2025   .   DK_E      12815510
2025   .   DK_W      19124784
2030   .   DK_E      12541184
2030   .   DK_W      18715404
2035   .   DK_E      12266859
2035   .   DK_W      18306025
2040   .   DK_E      12071712
2040   .   DK_W      18014803
2045   .   DK_E      11876564
2045   .   DK_W      17723581
2050   .   DK_E      11681416
2050   .   DK_W      17432359



*________________________________________________________________________
* R E S T    O F    T H E   C O U N T R I E S
*________________________________________________________________________

* C L A S S I C    E L E C T R I C I T Y    D E M A N D - independent of the energy scenario modelled

2014   .    DE_CS          456479234
2014   .    DE_NE          6717185
2014   .    DE_NW          57798659
2014   .    NO_M           11134702
2014   .    NO_N           11134702
2014   .    NO_O           21297921
2014   .    NO_S           49022584
2014   .    SE_M           75156576
2014   .    SE_N           20518445
2014   .    SE_S           19352624
2014   .    FI_R           65255441
2020   .    DE_CS          430356621
2020   .    DE_NE          6332786
2020   .    DE_NW          54491056
2020   .    NO_M           12025505
2020   .    NO_N           12025505
2020   .    NO_O           23001805
2020   .    NO_S           52944507
2020   .    SE_M           79644911
2020   .    SE_N           21743802
2020   .    SE_S           20508359
2020   .    FI_R           76571364
2025   .    DE_CS          419106942
2025   .    DE_NE          6167244
2025   .    DE_NW          53066640
2025   .    NO_M           11702658
2025   .    NO_N           11702658
2025   .    NO_O           22384280
2025   .    NO_S           51523115
2025   .    SE_M           77447078
2025   .    SE_N           21143773
2025   .    SE_S           19942423
2025   .    FI_R           71067494
2030   .    DE_CS          407857263
2030   .    DE_NE          6001703
2030   .    DE_NW          51642224
2030   .    NO_M           11379812
2030   .    NO_N           11379812
2030   .    NO_O           21766754
2030   .    NO_S           50101724
2030   .    SE_M           75249246
2030   .    SE_N           20543744
2030   .    SE_S           19376487
2030   .    FI_R           65563625
2035   .    DE_CS          395484142
2035   .    DE_NE          5819630
2035   .    DE_NW          50075560
2035   .    NO_M           11285802
2035   .    NO_N           11285802
2035   .    NO_O           21586938
2035   .    NO_S           49687831
2035   .    SE_M           74836914
2035   .    SE_N           20431174
2035   .    SE_S           19270312
2035   .    FI_R           64588925
2040   .    DE_CS          383111021
2040   .    DE_NE          5637557
2040   .    DE_NW          48508895
2040   .    NO_M           11191793
2040   .    NO_N           11191793
2040   .    NO_O           21407122
2040   .    NO_S           49273939
2040   .    SE_M           74424583
2040   .    SE_N           20318604
2040   .    SE_S           19164138
2040   .    FI_R           63614225
2045   .    DE_CS          378173458
2045   .    DE_NE          5564900
2045   .    DE_NW          47883709
2045   .    NO_M           11016136
2045   .    NO_N           11016136
2045   .    NO_O           21071133
2045   .    NO_S           48500573
2045   .    SE_M           73134873
2045   .    SE_N           19966501
2045   .    SE_S           18832041
2045   .    FI_R           63137586
2050   .    DE_CS          373235894
2050   .    DE_NE          5492243
2050   .    DE_NW          47258523
2050   .    NO_M           10840478
2050   .    NO_N           10840478
2050   .    NO_O           20735143
2050   .    NO_S           47727208
2050   .    SE_M           71845162
2050   .    SE_N           19614398
2050   .    SE_S           18499944
2050   .    FI_R           62660948


*Electricity demand for transport

2014   .    DE_CS_EV         0
2014   .    DE_NE_EV         0
2014   .    DE_NW_EV         0
2014   .    NO_M_EV          2764
2014   .    NO_N_EV          2764
2014   .    NO_O_EV          5287
2014   .    NO_S_EV          12169
2014   .    SE_M_EV          46458
2014   .    SE_N_EV          12684
2014   .    SE_S_EV          11963
2014   .    FI_R_EV          206374
2020   .    DE_CS_EV         3938209
2020   .    DE_NE_EV         57952
2020   .    DE_NW_EV         498650
2020   .    NO_M_EV          41457
2020   .    NO_N_EV          41457
2020   .    NO_O_EV          79297
2020   .    NO_S_EV          182523
2020   .    SE_M_EV          696879
2020   .    SE_N_EV          190254
2020   .    SE_S_EV          179444
2020   .    FI_R_EV          963929
2025   .    DE_CS_EV         10079534
2025   .    DE_NE_EV         148322
2025   .    DE_NW_EV         1276254
2025   .    NO_M_EV          120923
2025   .    NO_N_EV          120923
2025   .    NO_O_EV          231296
2025   .    NO_S_EV          532387
2025   .    SE_M_EV          1718292
2025   .    SE_N_EV          469110
2025   .    SE_S_EV          442456
2025   .    FI_R_EV          1771795
2030   .    DE_CS_EV         16220860
2030   .    DE_NE_EV         238693
2030   .    DE_NW_EV         2053859
2030   .    NO_M_EV          200389
2030   .    NO_N_EV          200389
2030   .    NO_O_EV          383295
2030   .    NO_S_EV          882251
2030   .    SE_M_EV          2739705
2030   .    SE_N_EV          747965
2030   .    SE_S_EV          705467
2030   .    FI_R_EV          2579660
2035   .    DE_CS_EV         24259682
2035   .    DE_NE_EV         356986
2035   .    DE_NW_EV         3071722
2035   .    NO_M_EV          313312
2035   .    NO_N_EV          313312
2035   .    NO_O_EV          599288
2035   .    NO_S_EV          1379414
2035   .    SE_M_EV          3957992
2035   .    SE_N_EV          1080569
2035   .    SE_S_EV          1019173
2035   .    FI_R_EV          3543239
2040   .    DE_CS_EV         32298505
2040   .    DE_NE_EV         475279
2040   .    DE_NW_EV         4089584
2040   .    NO_M_EV          426235
2040   .    NO_N_EV          426235
2040   .    NO_O_EV          815281
2040   .    NO_S_EV          1876576
2040   .    SE_M_EV          5176280
2040   .    SE_N_EV          1413172
2040   .    SE_S_EV          1332879
2040   .    FI_R_EV          4506818
2045   .    DE_CS_EV         39957664
2045   .    DE_NE_EV         587985
2045   .    DE_NW_EV         5059375
2045   .    NO_M_EV          540140
2045   .    NO_N_EV          540140
2045   .    NO_O_EV          1033153
2045   .    NO_S_EV          2378065
2045   .    SE_M_EV          6364600
2045   .    SE_N_EV          1737595
2045   .    SE_S_EV          1638868
2045   .    FI_R_EV          5446694
2050   .    DE_CS_EV         47616823
2050   .    DE_NE_EV         700691
2050   .    DE_NW_EV         6029165
2050   .    NO_M_EV          654045
2050   .    NO_N_EV          654045
2050   .    NO_O_EV          1251025
2050   .    NO_S_EV          2879553
2050   .    SE_M_EV          7552920
2050   .    SE_N_EV          2062017
2050   .    SE_S_EV          1944857
2050   .    FI_R_EV          6386571

/;
