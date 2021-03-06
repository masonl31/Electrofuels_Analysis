TABLE PROCDATA(PROC,PROCDATASET)    "Process data"


*                                  MEuro/GJ/h                                                         Euro/GJ/h
                                   PROCINVCOST   PROCKAPVARIABLE    PROCFROMYEAR   PROCLIFETIME     PROCFIXCOST                    /*  PROCVARCOST           */
HTL_ST                          	0.305             1              2012            25             17500
HTL_WO                          	0.305             1              2012            25             17500
HTL_WP                          	0.305             1              2012            25             17500
CO2_DAC                             	1.717		  1              2012            25             68678
CO2_IND                             	0.446		  1              2012            25             11915
CO2_PH                              	0.446		  1              2012            25             11915
CO2_Bio                              	0.446		  1              2012            25             11915


EMethanol_synthesis                     0.1527            1              2012            20             5316
EMethanol_Upgrade                       0.0813            1              2012            20             3252
E_FT			                0.13668           1              2012            25             5467
Ammonia_Synthesis	                0.1944            1              2012            20             7777
CO2_Sto                             	1.521		  1              2012            20             30435

ThermGasific_SNG_50_WO                  0.414             1              2012            20             11260                      /*  0.7383                */
ThermGasific_SNG_50_WP                  0.414             1              2012            20             11260                      /*  0.7383                */
ThermGasific_SNG_50_ST                  0.414             1              2012            20             11260                      /*  0.7383                */
ThermGasific_SNG_50_MW                  0.414             1              2012            20             11260                      /*  0.7383                */

ThermGasific_Syngas_50_WO               0.283             1              2012            20             5556                       /*  0.6846                */
ThermGasific_Syngas_50_WP               0.283             1              2012            20             5556                       /*  0.6846                */
ThermGasific_Syngas_50_ST               0.283             1              2012            20             5556                       /*  0.6846                */
ThermGasific_Syngas_50_MW               0.283             1              2012            20             5556                       /*  0.6846                */

TG_50_WO                                0.175             1              2012            20             7010                       /*  0.9530   TJEK         */
TG_50_WP                                0.175             1              2012            20             7010                       /*  0.9530   TJEK         */
TG_50_ST                                0.175             1              2012            20             7010                       /*  0.9530   TJEK         */
TG_50_MW                                0.175             1              2012            20             7010                       /*  0.9530   TJEK         */

TG_FT_Biodiesel_50_WO                   0.526             1              2012            20             14840                      /*  0.9530                */
TG_FT_Biodiesel_50_WP                   0.526             1              2012            20             14840                      /*  0.9530                */
TG_FT_Biodiesel_50_ST                   0.526             1              2012            20             14840                      /*  0.9530                */
*TG_FT_Biodiesel_50_MW                   0.526             1              2012            20             14840                      /*  0.9530                */


Ethanol_50                             0.2466             1              2012            20             18942


BioJet_50_ST                          0.39715             1              2012            20             11855
BioJet_50_WO                          0.39715             1              2012            20             11855
BioJet_50_WP                          0.39715             1              2012            20             11855


BioJet_50_ST_H2                       0.39715             1              2012            20             11855
BioJet_50_WO_H2                       0.39715             1              2012            20             11855
BioJet_50_WP_H2                       0.39715             1              2012            20             11855



*BiogasProd_single                      0.395             1              2012            20             7170
*BiogasProd_mix                         0.307             1              2012            20             2812
*BiogasProd_mix                         0.420             1              2012            20             0.001
*BiogasProd_mix                         0.307             1              2012            20             2812


Straw_pre_BG                       0.000042               1              2012            20              0.001
Deep_Litter_pre_BG                 0.0000153              1              2012            20              0.001
Food_Waste_pre_BG                  0.0000049              1              2012            20              0.001
Nature_Area_pre_BG                 0.0000293              1              2012            20              0.001
Manure_tank                        0.0000323              1              2012            20              0.001
*BiogasProd_mix                     0.0000323               1              2012            20              2.9





BiogasUpgr_BMETH_50                     0.0953            1              2012            20             2389

Methanisation_Bio_Biogas                0.137             1              2012            20             6837
Methane_synthesis_TG_50                 0.137             1              2012            20             6837
Methanol_synthesis_TG_50                0.049             1              2012            20             1467


Electrolysis_H2Prod                     0.095             1              2012            20             2871
*Electrolysis_H2Prod                     0.285             1              2012            20             8613


Hydrogen_STO_Large                  0.096396           1              2012            20             4446.149
Hydrogen_STO_Small                  0.172265           1              2012            20             7946.308

BIOGAS_GRID_STO                     0.0059085           1              2012            20             59.085



*BIO_syngas_STO                          0.07              1              2012            20             80
*GasGrid_STO_BNG                         0.00001           1              2012            20             0.0001






Engine_Syngas_50                        0.394             1              2012            20             5803
Engine_Biogas_50                        0.394             1              2012            20             5803

;

*PROCDATA(PROC,'PROCINVCOST')=PROCDATA(PROC,'PROCINVCOST');
