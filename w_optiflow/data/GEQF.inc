*Last time modified (Amalia, 06-05-2015) (Raffaele, 20-06-2015)
*Updated values for NO,SE,FI & DE from Fjernvarmeanalyse - bilagsrapport (EA)
*Data for DK from FRIDA model
*Include use of Hazardous Waste for DK  - Data from FRIDA model
*Fossil fuels consumption is updated. For FI, NO and SE data from NETP. For Denmark no fossil fuels after 2035, and 2025 based on trends extrapolated
*from NETP using real actual consumption in 2012
*Biogas forced use has been implemented because the software did not use it at all

Parameter GEQF(YYY,CCCRRRAAA,FFF) Required fuel use (GJ) per year


/
*------------------------------------------------------
*DATA THAT ARE SCENARIO DEPENDANT
*------------------------------------------------------
*W I N D    E N E R G Y    S C E N A R I O





2050    .    DK_E          .    MUNI_WASTE    17852682
2050    .    DK_W          .    MUNI_WASTE    20428718


*2050    .    FINLAND       .    MUNI_WASTE    29000000
*2050    .    GERMANY       .    MUNI_WASTE    57600000
*2050    .    NORWAY        .    MUNI_WASTE    24275695
*2050    .    SWEDEN        .    MUNI_WASTE    56000000






$ontext
*Rasmus


*Compulsory use of biogas in Denmark

2020   .   DK_E_Rural    .    BIOGAS_net        365000
2025   .   DK_E_Rural    .    BIOGAS_net        365000
2030   .   DK_E_Rural    .    BIOGAS_net        365000
2020   .   DK_W_Rural    .    BIOGAS_net        4635000
2025   .   DK_W_Rural    .    BIOGAS_net        4635000
2030   .   DK_W_Rural    .    BIOGAS_net        4635000

2020   .   DENMARK    .    BIOGAS_EC_net        6000000
2025   .   DENMARK    .    BIOGAS_EC_net        12230000
2030   .   DENMARK    .    BIOGAS_EC_net        18470000
2035   .   DENMARK    .    BIOGAS_EC_net        24700000
2040   .   DENMARK    .    BIOGAS_EC_net        23870000
2045   .   DENMARK    .    BIOGAS_EC_net        23030000
2050   .   DENMARK    .    BIOGAS_EC_net        22020000



$offtext


$ontext

*B I O M A S S    S C E N A R I O
*Compulsory use of biogas  in Denmark

2020   .   DK_E_Rural    .    BIOGAS_net        365000
2025   .   DK_E_Rural    .    BIOGAS_net        365000
2030   .   DK_E_Rural    .    BIOGAS_net        365000
2020   .   DK_W_Rural    .    BIOGAS_net        4635000
2025   .   DK_W_Rural    .    BIOGAS_net        4635000
2030   .   DK_W_Rural    .    BIOGAS_net        4635000

2020   .   DENMARK    .    BIOGAS_EC_net        6000000
2025   .   DENMARK    .    BIOGAS_EC_net        9300000
2030   .   DENMARK    .    BIOGAS_EC_net        12600000
2035   .   DENMARK    .    BIOGAS_EC_net        15900000
2040   .   DENMARK    .    BIOGAS_EC_net        16000000
2045   .   DENMARK    .    BIOGAS_EC_net        16100000
2050   .   DENMARK    .    BIOGAS_EC_net        16200000

$offtext


*------------------------------------------------------
*DATA THAT ARE NOT SCENARIO DEPENDANT
*------------------------------------------------------

*Available Municipal Solid Waste for Incineration - data from FRIDA

$ontext

2014   .    DK_E    .    MUNI_WASTE    14930786
2020   .    DK_E    .    MUNI_WASTE    15792925
2025   .    DK_E    .    MUNI_WASTE    14913845
2030   .    DK_E    .    MUNI_WASTE    14578805
2035   .    DK_E    .    MUNI_WASTE    15247736
2040   .    DK_E    .    MUNI_WASTE    15958369
2045   .    DK_E    .    MUNI_WASTE    16824593

*2050   .    DK_E    .    MUNI_WASTE    17852682

2014   .    DK_W    .    MUNI_WASTE    17854860
2020   .    DK_W    .    MUNI_WASTE    18498716
2025   .    DK_W    .    MUNI_WASTE    17224389
2030   .    DK_W    .    MUNI_WASTE    16724144
2035   .    DK_W    .    MUNI_WASTE    17377630
2040   .    DK_W    .    MUNI_WASTE    18212433
2045   .    DK_W    .    MUNI_WASTE    19226856

*2050   .    DK_W    .    MUNI_WASTE    20428718



*2050   .    DK_E    .    MUNI_WASTE    14930786
*2050   .    DK_E    .    MUNI_WASTE    17852682
*2050   .    DK_W    .    MUNI_WASTE    17854860
*2050   .    DK_W    .    MUNI_WASTE    20428718

$offtext

$ontext
2014.DENMARK.HAZARDOUSWASTE   2.40487E+05
2020.DENMARK.HAZARDOUSWASTE   2.83116E+05
2025.DENMARK.HAZARDOUSWASTE   2.98454E+05
2030.DENMARK.HAZARDOUSWASTE   3.13100E+05
2035.DENMARK.HAZARDOUSWASTE   3.28753E+05
2040.DENMARK.HAZARDOUSWASTE   3.46574E+05
2045.DENMARK.HAZARDOUSWASTE   3.68287E+05
*2050.DENMARK.HAZARDOUSWASTE   3.94276E+05
$offtext



*Municipal Solid Waste for Incineration in the rest of Europe


$ontext
2014    .    FINLAND       .    MUNI_WASTE    25159042
2014    .    GERMANY       .    MUNI_WASTE    57600000
2014    .    NORWAY        .    MUNI_WASTE    14545173
2014    .    SWEDEN        .    MUNI_WASTE    48582978
2020    .    FINLAND       .    MUNI_WASTE    27186342
2020    .    GERMANY       .    MUNI_WASTE    57600000
2020    .    NORWAY        .    MUNI_WASTE    14545173
2020    .    SWEDEN        .    MUNI_WASTE    52497763
2025    .    FINLAND       .    MUNI_WASTE    29000000
2025    .    GERMANY       .    MUNI_WASTE    57600000
2025    .    NORWAY        .    MUNI_WASTE    19410434
2025    .    SWEDEN        .    MUNI_WASTE    56000000
2030    .    FINLAND       .    MUNI_WASTE    29000000
2030    .    GERMANY       .    MUNI_WASTE    57600000
2030    .    NORWAY        .    MUNI_WASTE    24275695
2030    .    SWEDEN        .    MUNI_WASTE    56000000
2035    .    FINLAND       .    MUNI_WASTE    29000000
2035    .    GERMANY       .    MUNI_WASTE    57600000
2035    .    NORWAY        .    MUNI_WASTE    24275695
2035    .    SWEDEN        .    MUNI_WASTE    56000000
2040    .    FINLAND       .    MUNI_WASTE    29000000
2040    .    GERMANY       .    MUNI_WASTE    57600000
2040    .    NORWAY        .    MUNI_WASTE    24275695
2040    .    SWEDEN        .    MUNI_WASTE    56000000
2045    .    FINLAND       .    MUNI_WASTE    29000000
2045    .    GERMANY       .    MUNI_WASTE    57600000
2045    .    NORWAY        .    MUNI_WASTE    24275695
2045    .    SWEDEN        .    MUNI_WASTE    56000000
2050    .    FINLAND       .    MUNI_WASTE    29000000
2050    .    GERMANY       .    MUNI_WASTE    57600000
2050    .    NORWAY        .    MUNI_WASTE    24275695
2050    .    SWEDEN        .    MUNI_WASTE    56000000


$offtext

$ontext


2014    .    SWEDEN        .    MUNI_WASTE    48582978
2020    .    SWEDEN        .    MUNI_WASTE    48582978
2025    .    SWEDEN        .    MUNI_WASTE    48582978
2030    .    SWEDEN        .    MUNI_WASTE    48582978
2035    .    SWEDEN        .    MUNI_WASTE    48582978
2040    .    SWEDEN        .    MUNI_WASTE    48582978
2045    .    SWEDEN        .    MUNI_WASTE    48582978
2050    .    SWEDEN        .    MUNI_WASTE    48582978

*2014    .    NORWAY        .    MUNI_WASTE    14545173
2020    .    NORWAY        .    MUNI_WASTE    14545173
2025    .    NORWAY        .    MUNI_WASTE    14545173
2030    .    NORWAY        .    MUNI_WASTE    14545173
*2035    .    NORWAY        .    MUNI_WASTE    14545173
2040    .    NORWAY        .    MUNI_WASTE    14545173
2045    .    NORWAY        .    MUNI_WASTE    14545173
*2050    .    NORWAY        .    MUNI_WASTE    14545173

2014    .    FINLAND       .    MUNI_WASTE    25159042
2020    .    FINLAND       .    MUNI_WASTE    25159042
2025    .    FINLAND       .    MUNI_WASTE    25159042
2030    .    FINLAND       .    MUNI_WASTE    25159042
2035    .    FINLAND       .    MUNI_WASTE    25159042
2040    .    FINLAND       .    MUNI_WASTE    25159042
2045    .    FINLAND       .    MUNI_WASTE    25159042
*2050    .    FINLAND       .    MUNI_WASTE    25159042

2014    .    GERMANY       .    MUNI_WASTE    57600000
2020    .    GERMANY       .    MUNI_WASTE    57600000
2025    .    GERMANY       .    MUNI_WASTE    57600000
2030    .    GERMANY       .    MUNI_WASTE    57600000
2035    .    GERMANY       .    MUNI_WASTE    57600000
2040    .    GERMANY       .    MUNI_WASTE    57600000
2045    .    GERMANY       .    MUNI_WASTE    57600000
2050    .    GERMANY       .    MUNI_WASTE    57600000

$offtext


/;

*GEQF(YYY,AAA,'Biogas_net')$(RRRAAA('DK_W',AAA) AND (NOT AAA('DK_W_Rural')))=1E-6;
*GEQF(YYY,AAA,'Biogas_net')$(RRRAAA('DK_E',AAA) AND (NOT AAA('DK_E_Rural')))=1E-6;