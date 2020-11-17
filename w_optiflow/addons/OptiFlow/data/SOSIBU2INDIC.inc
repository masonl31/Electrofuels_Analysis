
* NOTE: OVERLOADED AS SOSIBU2INDIC, SOSIBU2INDIC_AST and SOSIBU2INDIC_RST


**Version for Biowaste Seminar (October,2014): Biogenic emissions are not considered due to a lack of time. This must be considered subsequently (Amalia,19th October)
TABLE SOSIBU2INDIC(YYY,PROC,FLOW,FLOWINDIC) "Coefficients for transformation of VSOURCE, VSINK and VBUFFER flows to FLOWINDIC values"
                                                                     OPERATIONCOST   GHGEMISSION_nonbio         GHGEMISSION_bio
*                                                                    Cost (Money)    GHG emission (ton  CO2 equiv)

2014.  AmmoniaBuffer_Exp     	   . AMMONIA_FLOW_EXP			10                      0		      	      0.00
2014.  HTLBuffer_Exp         	   . HTLFLOW_EXP			3                      0		      	      0.00

2014.  BioJetBuffer_Exp            . BIOJETFLOW_EXP			2.5                     0		      	      0.00
2014.  E_FT_JetBuffer_Exp          . E_FT_JET_FLOW_EXP		   	14.3                    0		      	      0.00
2014.  EME_JetBuffer_Exp           . EME_JET_FLOW_EXP	           	14.3                    0		      	      0.00

2014.  BioGasolineBuffer_Exp       . BIOGASOLINEFLOW_EXP		14.9                    0		      	      0.00
2014.  MethanolBuffer_Exp          . METHANOLFLOW_EXP			10                      0		      	      0.00
2014.  EthanolBuffer_Exp           . ETHANOL_FLOW_EXP			1.6                     0		      	      0.00
2014.  BiodieselBuffer_Exp         . BIODIESELFLOW_EXP			1.3                     0		      	      0.00

2014.  E_FT_DieselBuffer_Exp       . E_FT_DIESEL_FLOW_EXP		14.7                    0		      	      0.00
2014.  EME_GasolineBuffer_Exp	   . EME_GASOLINE_FLOW_EXP		14.9                    0		      	      0.00
2014.  EME_LPGBuffer_Exp	   . EME_LPG_FLOW_EXP			16.1                    0		      	      0.00
2014.  EMethanolBuffer_Exp	   . EMETHANOLFLOW_EXP			10                      0		      	      0.00




2014. CO2_Source_PH            .   CO2_SOURCE_FLOW_PH                EPS                0                      0.00
2014. CO2_Source_IND           .   CO2_SOURCE_FLOW_IND               EPS                0                      0.00
2014. CO2_Source_DAC           .   CO2_SOURCE_FLOW_DAC               EPS                0                      0.00


2014. BioLiquid_Import     .   BIOLIQUIDFLOW_IMPORT                   -55               0                        0.00



2014. DieselBuffer     .DIESELFLOW                                      16.9549           -0.074                 0.00
*2020. DieselBuffer     .DIESELFLOW                                      10.2291           -0.074                 0.00
*2025. DieselBuffer     .DIESELFLOW                                      13.6648           -0.074                 0.00
*2030. DieselBuffer     .DIESELFLOW                                      17.0988           -0.074                 0.00
*2035. DieselBuffer     .DIESELFLOW                                      16.9549           -0.074                 0.00
*2040. DieselBuffer     .DIESELFLOW                                      16.8093           -0.074                 0.00
*2045. DieselBuffer     .DIESELFLOW                                      16.6654           -0.074                 0.00
2050. DieselBuffer     .DIESELFLOW                                      16.5215           -0.074                 0.00



2014. Money_Buffer         . OPERATIONCOST                             1                   0.00                   0.00
2014. Money_Buffer_T       . OPERATIONCOST                             1                   0.00                   0.00
2014. GHG_Buffer           . GHGEMISSION_nonbio                        0.00                1                      0.00
2014. GHGbio_Buffer        . GHGEMISSION_bio                           0.00                0.00                   1


2014. Muni_Waste_Gen           .   MUNI_WASTE_GEN_FLOW                -10.78               0                      0.00



*Source - Analyseforudsætninger 2018
*Prices - EUR/ton - oonversion using ton/GJ, e.g wood - 16.2, straw 15.0, wood pellets 19.75
2014. Wood_Gen                 .   WOOD_GEN_FLOW                      -128                 0                      0.00
2014. Wood_Pellets_Gen         .   WOOD_PELLETS_GEN_FLOW              -193.6               0                      0.00
2014. Straw_Gen                .   STRAW_GEN_FLOW                     -102.0                0                      0.00

***Scenario 500% increase in price
*2014. Wood_Gen                 .   WOOD_GEN_FLOW                      -999                 0                      0.00
*2014. Wood_Pellets_Gen         .   WOOD_PELLETS_GEN_FLOW              -999                 0                      0.00
*2014. Straw_Gen                .   STRAW_GEN_FLOW                     -510                 0                      0.00

***Scenario 10% decrease in price
*2014. Wood_Gen                 .   WOOD_GEN_FLOW                      -115.2                0                      0.00
*2014. Wood_Pellets_Gen         .   WOOD_PELLETS_GEN_FLOW              -174.24               0                      0.00
*2014. Straw_Gen                .   STRAW_GEN_FLOW                     -91.8                 0                      0.00



*4km = 0.81, 7km = 1.33, 10km = 1.91, 14km = 2.49 (Ida PhD, p. 110/95)
*14 km
*2014. Manure_Gen               .   MANURE_GEN_FLOW                    -2.49                0                      0.00
*2014. Manure_Gen               .   MANURE_GEN_FLOW                    -1.33                0                      0.00
*2014. Manure_Gen               .   MANURE_GEN_FLOW                   -0.81               0                      0.00
2014. Manure_Gen               .   MANURE_GEN_FLOW                   -0.0001               0                      0.00

* 10km = 3.44, 20km = 5.39, 30km = 7.56, 40km = 9.76 (Ida PhD, p. 145/130)

*2014. Deep_Litter_Gen         .   DEEP_LITTER_GEN_FLOW                -5.39                0                      0.00
*2014. Deep_Litter_Gen         .   DEEP_LITTER_GEN_FLOW                -3.44                0                      0.00
2014. Deep_Litter_Gen         .   DEEP_LITTER_GEN_FLOW                -0.0001                0                      0.00

*2014. Straw_Gen              .   STRAW_GEN_FLOW                     -67.38               0                      0.00


2014. Food_Waste_Gen         .   FOOD_WASTE_GEN_FLOW                 -32.7                0                      0.00
2014. Nature_Area_Gen        .   NATURE_AREA_GEN_FLOW                -38.66               0                      0.00


*Conversion, Manure = 0.4636; Straw (Biogas) = 8.4398; Deep Litter = 2.1204; Food_Waste = 4.0964; Nature Area = 5.4530

;




SOSIBU2INDIC(Y,PROC,FLOW,FLOWINDIC)$(SOSIBU2INDIC(Y,PROC,FLOW,FLOWINDIC)EQ 0) = SOSIBU2INDIC('2014',PROC,FLOW,FLOWINDIC);


