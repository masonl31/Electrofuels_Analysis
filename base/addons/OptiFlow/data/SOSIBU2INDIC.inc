
* NOTE: OVERLOADED AS SOSIBU2INDIC, SOSIBU2INDIC_AST and SOSIBU2INDIC_RST


**Version for Biowaste Seminar (October,2014): Biogenic emissions are not considered due to a lack of time. This must be considered subsequently (Amalia,19th October)
TABLE SOSIBU2INDIC(YYY,PROC,FLOW,FLOWINDIC) "Coefficients for transformation of VSOURCE, VSINK and VBUFFER flows to FLOWINDIC values"
                                                           OPERATIONCOST   GHGEMISSION_nonbio         GHGEMISSION_bio
*                                                         Cost (Money)    GHG emission (ton  CO2 equiv)



2014. Money_Buffer         . OPERATIONCOST                     1                   0.00                   0.00
2014. Money_Buffer_T       . OPERATIONCOST                     1                   0.00                   0.00
2014. GHG_Buffer           . GHGEMISSION_nonbio                0.00                1                      0.00
2014. GHGbio_Buffer        . GHGEMISSION_bio                   0.00                0.00                   1


*CO2 price for NG er 7.752
*NG price
*2014. GasBuffer            . GASFLOW                            6.31                0                      0.00

*NG price + CO2 cost
2014. GasBuffer            . GASFLOW                            14.062               0                      0.00

*half NG price + CO2 cost
*2014. GasBuffer            . GASFLOW                            10.907               0                      0.00


*double NG price + CO2 cost
*2014. GasBuffer            . GASFLOW                            20.37               0                      0.00


*2014. Digestate             . Digestate_FLOW                     8.84               0                      0.00




*2014. BioSyngasBuffer      . BIO_SYNGAS_FLOW                   3.88                0                      0.00
*2014. BiogasBuffer         . BIOGAS_FLOW                       3.88                0                      0.00
*2014. BioSyngasBuffer      . BIO_SYNGAS_FLOW                   0.88                0                      0.00
*2014. BiogasBuffer         . BIOGAS_FLOW                       0.88                0                      0.00





*2014. BiodieselBuffer       . BIODIESELFLOW                     18.6               0                      0.00
*2014. MethanolBuffer        . METHANOLFLOW                      18.6               0                      0.00
*2014. EthanolBuffer         . Ethanol_FLOW                      18.6               0                      0.00




$ontext

2014. WOOD                 . WOOD_GJ_SNG                       10.99               0.00                   0.00
2014. WOOD                 . WOOD_GJ_SYNGAS                    10.99               0.00                   0.00


2014. WOOD_PELLETS         . WOOD_PELLETS_GJ_SNG               13.26               0.00                   0.00
2014. WOOD_PELLETS         . WOOD_PELLETS_GJ_SYNGAS            13.26               0.00                   0.00


2014. STRAW                . STRAW_GJ_SNG                      9.70                0.00                   0.00
2014. STRAW                . STRAW_GJ_SYNGAS                   9.70                0.00                   0.00
2014. STRAW                . STRAW_GJ_BIOGAS                   9.70                0.00                   0.00


*2014. MUNI_WASTE           . MUNI_WASTE_GJ_SNG                 -3.26               0.00                   0.00
*2014. MUNI_WASTE           . MUNI_WASTE_GJ_SYNGAS              -3.26               0.00                   0.00
2014. MUNI_WASTE           . MUNI_WASTE_GJ_SNG                 0.0001              0.00                   0.00
2014. MUNI_WASTE           . MUNI_WASTE_GJ_SYNGAS              0.0001              0.00                   0.00


2014. MANURE_AND_WETBIO    . MANURE_AND_WETBIO_GJ_BG_Single     0.0001              0.00                   0.00
2014. MANURE_AND_WETBIO    . MANURE_AND_WETBIO_GJ_BG_Mix        0.0001              0.00                   0.00

$offtext










$ontext

2014. HouseHoldWasteGen.RESIDUALWASTEHH                           0               0                      0           !! Source
2014. IndustrialWasteGen.  INDUSTRY_MIXEDWASTE                    0               0                      0
2014. Money_Buffer     .OPERATIONCOST                             1               0.00                   0.00
2014.Money_Buffer_T     .OPERATIONCOST                            1               0.00                   0.00
2014.GHG_Buffer       .GHGEMISSION_nonbio                       0.00              1                      0.00
2014. GHGbio_Buffer    .GHGEMISSION_bio                         0.00              0.00                   1
2014. Bottom_ash   . ASH_MSW                                    0.00              0.00                   0.00

2014. GasBuffer        .GASFLOW                                 7.1089            -0.0568                0.00
2020. GasBuffer        .GASFLOW                                 4.8814            -0.0568                0.00
2025. GasBuffer        .GASFLOW                                 5.8764            -0.0568                0.00
2030. GasBuffer        .GASFLOW                                 6.8697            -0.0568                0.00
2035. GasBuffer        .GASFLOW                                 6.6859            -0.0568                0.00
2040. GasBuffer        .GASFLOW                                 6.5022            -0.0568                0.00
2045. GasBuffer        .GASFLOW                                 6.4346            -0.0568                0.00
2050. GasBuffer        .GASFLOW                                 6.3652            -0.0568                0.00

2014. DieselBuffer     .DIESELFLOW                              16.9549           -0.074                 0.00
2020. DieselBuffer     .DIESELFLOW                              10.2291           -0.074                 0.00
2025. DieselBuffer     .DIESELFLOW                              13.6648           -0.074                 0.00
2030. DieselBuffer     .DIESELFLOW                              17.0988           -0.074                 0.00
2035. DieselBuffer     .DIESELFLOW                              16.9549           -0.074                 0.00
2040. DieselBuffer     .DIESELFLOW                              16.8093           -0.074                 0.00
2045. DieselBuffer     .DIESELFLOW                              16.6654           -0.074                 0.00
2050. DieselBuffer     .DIESELFLOW                              16.5215           -0.074                 0.00


2014. Imported_RDF    .IMPORTEDRDFFLOW                           EPS                0.00                   0.00



$offtext


;




SOSIBU2INDIC(Y,PROC,FLOW,FLOWINDIC)$(SOSIBU2INDIC(Y,PROC,FLOW,FLOWINDIC)EQ 0) = SOSIBU2INDIC('2014',PROC,FLOW,FLOWINDIC);


