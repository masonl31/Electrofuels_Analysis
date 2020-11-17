* Revision wrt ELEC, HEAT, GAS, buffers, (Linkstorage)
* - removed all that was originally commented out, see original at botton of file
* - assumed tht %quickandverydirty% is not yes, then removed accordingly
* - removed all original comments, see original at botton of file
* Real Changes:
* - Buffer nodes
* - Linkstorage nodes: observe, that they are NOT effecting ANYTHING here i this file, but they MUST be introduced in file FLOWFROMTOPROC.inc.

* The essential information is the same as in Sardiania paper PROCINOUTFLOW.inc
* Modification on additional information:
*   Index IPROCINOUTRELATION  added
*   VARIOUTSUM replaced by 1 (but may differ from 1)
*   VARIinSUM  replaced by 1 (but may differ from 1)
*   Reciprocal values permitted (Karsten request), entered a couple of places, not everywhere, seems to work

$ifi %rollback%==yes $goto olderversionstart

PARAMETER PROCINOUTFLOW_NotY(AAA,PROC,IFLOWIN,IFLOWOUT,IPROCINOUTRELATION)  "Relationship at PROC between coming (index 3) and leaving (index 4) FLOW; interior PROC only"
/
*DK_CA_KBH         .   ProcEximTruck                   .   WOOD_GEN_FLOW                    .   WOOD_GEN_FLOW                   .  IONEONE      1
DK_CA_KBH         .   ProcEximTruck                   .   STRAW_GEN_FLOW                   .   STRAW_GEN_FLOW                  .  IONEONE      1
DK_CA_KBH         .   ProcEximTruck                   .   MUNI_WASTE_GEN_FLOW              .   MUNI_WASTE_GEN_FLOW             .  IONEONE      1
*DK_CA_KBH         .   ProcEximTruck                   .   WOOD_PELLETS_GEN_FLOW            .   WOOD_PELLETS_GEN_FLOW           .  IONEONE      1
DK_CA_KBH         .   ProcEximTruck                   .   MANURE_GEN_FLOW                  .   MANURE_GEN_FLOW                 .  IONEONE      1
*multi_biogas
DK_CA_KBH         .   ProcEximTruck                   .   DEEP_LITTER_GEN_FLOW             .   DEEP_LITTER_GEN_FLOW            .  IONEONE      1
DK_CA_KBH         .   ProcEximTruck                   .   FOOD_WASTE_GEN_FLOW              .   FOOD_WASTE_GEN_FLOW             .  IONEONE      1
DK_CA_KBH         .   ProcEximTruck                   .   NATURE_AREA_GEN_FLOW             .   NATURE_AREA_GEN_FLOW            .  IONEONE      1


DK_CA_KBH         .   Wood_Mass                        .   WOOD_GEN_FLOW                   .   WOOD_GEN_FLOW                   .  IONEONE      16.2
DK_CA_KBH         .   Straw_Mass                       .   STRAW_GEN_FLOW                  .   STRAW_GEN_FLOW                  .  IONEONE      15
DK_CA_KBH         .   Muni_Waste_Mass                  .   MUNI_WASTE_GEN_FLOW             .   MUNI_WASTE_GEN_FLOW             .  IONEONE      14
DK_CA_KBH         .   Wood_Pellets_Mass                .   WOOD_PELLETS_GEN_FLOW           .   WOOD_PELLETS_GEN_FLOW           .  IONEONE      19.75
DK_CA_KBH         .   Manure_Mass                      .   MANURE_GEN_FLOW                 .   MANURE_GEN_FLOW                 .  IONEONE      1
*multi_biogas
DK_CA_KBH         .   Deep_Litter_Mass                 .   DEEP_LITTER_GEN_FLOW            .   DEEP_LITTER_GEN_FLOW            .  IONEONE      1
DK_CA_KBH         .   Food_Waste_Mass                  .   FOOD_WASTE_GEN_FLOW             .   FOOD_WASTE_GEN_FLOW             .  IONEONE      1
DK_CA_KBH         .   Nature_Area_Mass                 .   NATURE_AREA_GEN_FLOW            .   NATURE_AREA_GEN_FLOW            .  IONEONE      1


***********CO2**********************
DK_CA_KBH         .   CO2_PH                           .   CO2_SOURCE_FLOW_PH                .   CO2_FLOW_PH		       .  IONEONE      1
DK_CA_KBH         .   CO2_PH                           .   ELECFLOW_GJ                       .   CO2_FLOW_PH		       .  IONEONE      0.94231
DK_CA_KBH         .   CO2_PH                           .   CO2_SOURCE_FLOW_PH                .   OPERATIONCOST                 .  IONEONE      -30.2



DK_CA_KBH         .   CO2_Bio_Pot                       .   CO2_SOURCE_FLOW_BIO                .   CO2_SOURCE_FLOW_BIO         .  IONEMANY      1
DK_CA_KBH         .   CO2_Bio_Pot                       .   CO2_SOURCE_FLOW_BIO                .   CO2_SINK_FLOW_BIO	       .  IONEMANY      1

DK_CA_KBH         .   CO2_Bio                           .   CO2_SOURCE_FLOW_BIO                .   CO2_FLOW_BIO		       .  IONEONE      1
DK_CA_KBH         .   CO2_Bio                           .   ELECFLOW_GJ                        .   CO2_FLOW_BIO		       .  IONEONE      0.94231
DK_CA_KBH         .   CO2_Bio                           .   CO2_SOURCE_FLOW_BIO                .   OPERATIONCOST               .  IONEONE      -30.2


DK_CA_KBH         .   CO2_IND                          .   CO2_SOURCE_FLOW_IND               .   CO2_FLOW_IND		       .  IONEONE      1
DK_CA_KBH         .   CO2_IND                          .   ELECFLOW_GJ                       .   CO2_FLOW_IND		       .  IONEONE      11.111
DK_CA_KBH         .   CO2_IND                          .   HEATFLOW_GJ                       .   CO2_FLOW_IND		       .  IONEONE      0.29851
DK_CA_KBH         .   CO2_IND                          .   CO2_SOURCE_FLOW_IND               .   OPERATIONCOST                 .  IONEONE      -30.0175


DK_CA_KBH         .   CO2_DAC                          .   CO2_SOURCE_FLOW_DAC               .   CO2_FLOW_DAC		       .  IONEONE      1
DK_CA_KBH         .   CO2_DAC                          .   ELECFLOW_GJ                       .   CO2_FLOW_DAC		       .  IONEONE      1.53
DK_CA_KBH         .   CO2_DAC                          .   HEATFLOW_GJ                       .   CO2_FLOW_DAC		       .  IONEONE      0.25


DK_CA_KBH         .   CO2                              .   CO2_FLOW_PH                .   CO2_FLOW		       .  IMANYONE      1
DK_CA_KBH         .   CO2                              .   CO2_FLOW_IND               .   CO2_FLOW		       .  IMANYONE      1
DK_CA_KBH         .   CO2                              .   CO2_FLOW_DAC               .   CO2_FLOW		       .  IMANYONE      1
DK_CA_KBH         .   CO2                              .   CO2_FLOW_BIO               .   CO2_FLOW		       .  IMANYONE      1



*------------------Electricity------------------

*Electricity from Balmorel to OptiFlow
DK_CA_KBH         .  EL_Bal_to_Opti_Conv               .   ELECFLOW                        .   ELECFLOW_GJ                     .  IONEONE      3.6
DK_CA_KBH         .  EL_Bal_to_Opti_Conv               .   ELECFLOW                        .   OPERATIONCOST                   .  IONEONE      -12.96



DK_CA_KBH         .  EL_grid_tariff                    .   ELECFLOW_GJ                     .   ELECFLOW_GJ                     .  IONEONE      1
DK_CA_KBH         .  EL_grid_tariff                    .   ELECFLOW_GJ                     .   OPERATIONCOST                   .  IONEONE      EPS

DK_CA_KBH         .  ElecBuffer_GJ                     .   ELECFLOW_GJ                     .   ELECFLOW_GJ                     .  IONEMANY     1


*Electricity from OptiFlow to Balmorel
DK_CA_KBH        .  EL_Opti_to_Bal_Conv                .   ELECFLOW_GJ                     .   ELECFLOW                        .  IONEONE      0.2777778



*------------------Heat ------------------

*Heat from Balmorel to OptiFlow
DK_CA_KBH         .  Heat_Bal_to_Opti_Conv               .   HEATFLOW                        .   HEATFLOW_GJ                     .  IONEONE      3.6
DK_CA_KBH         .  Heat_Bal_to_Opti_Conv               .   HEATFLOW                        .   OPERATIONCOST                   .  IONEONE      -12.96

DK_CA_KBH         .  Heat_grid_tariff                    .   HEATFLOW_GJ                     .   HEATFLOW_GJ                     .  IONEONE      1
DK_CA_KBH         .  Heat_grid_tariff                    .   HEATFLOW_GJ                     .   OPERATIONCOST                   .  IONEONE      EPS

DK_CA_KBH         .  HeatBuffer_GJ                       .   HEATFLOW_GJ                     .   HEATFLOW_GJ                     .  IONEMANY     1


*Heat from OptiFlow to Balmorel
DK_CA_KBH        .  Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ                     .   HEATFLOW                        .  IONEONE      0.2777778






DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_FT                    .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_SNG                   .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_SYNGAS                .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_TG                    .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_BJ                    .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_BJ_H2                 .  IONEMANY      1
DK_CA_KBH          .    Wood                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_HTL                   .  IONEMANY      1

DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_FT                    .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_SNG                   .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_SYNGAS                .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_TG                    .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_BIOGAS                .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_ET                    .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_BJ                    .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_BJ_H2                 .  IONEMANY      1
DK_CA_KBH          .    Straw                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_HTL                   .  IONEMANY      1

DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_FT             .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_SNG            .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_SYNGAS         .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_TG             .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_BJ             .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_BJ_H2          .  IONEMANY      1
DK_CA_KBH          .    Wood_Pellets                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_HTL            .  IONEMANY      1

*DK_CA_KBH          .    Muni_Waste                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_FT               .  IONEMANY      1
DK_CA_KBH          .    Muni_Waste                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_SNG              .  IONEMANY      1
DK_CA_KBH          .    Muni_Waste                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_SYNGAS           .  IONEMANY      1
DK_CA_KBH          .    Muni_Waste                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_TG               .  IONEMANY      1


*multi_biogas
*DK_CA_KBH          .    Manure                        .    MANURE_GEN_FLOW                .     MANURE_GJ_BG_Single            .  IONEMANY      1
*DK_CA_KBH          .    Manure                        .    MANURE_GEN_FLOW                .     MANURE_GJ_BG_Mix               .  IONEMANY      1



*converting straw for biogas production back to mass instead of energy
DK_CA_KBH          .    Straw_Biogas                   .    STRAW_GJ_BIOGAS                .     STRAW_GJ_BIOGAS                .  IONEONE       0.0689655



DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_FT                     .     WOOD_GJ_FT                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_SNG                    .     WOOD_GJ_SNG                   .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_SYNGAS                 .     WOOD_GJ_SYNGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_TG                     .     WOOD_GJ_TG                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_BJ                     .     WOOD_GJ_BJ                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_BJ_H2                  .     WOOD_GJ_BJ_H2                 .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_HTL                    .     WOOD_GJ_HTL                   .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_FT                    .     STRAW_GJ_FT                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_SNG                   .     STRAW_GJ_SNG                   .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_SYNGAS                .     STRAW_GJ_SYNGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_TG                    .     STRAW_GJ_TG                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_BIOGAS                .     STRAW_GJ_BIOGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_ET                    .     STRAW_GJ_ET                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_BJ                    .     STRAW_GJ_BJ                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_BJ_H2                 .     STRAW_GJ_BJ_H2                 .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_HTL                   .     STRAW_GJ_HTL                   .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_FT             .     WOOD_PELLETS_GJ_FT             .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_SNG            .     WOOD_PELLETS_GJ_SNG            .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_SYNGAS         .     WOOD_PELLETS_GJ_SYNGAS         .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_TG             .     WOOD_PELLETS_GJ_TG             .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_BJ             .     WOOD_PELLETS_GJ_BJ             .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_BJ_H2          .     WOOD_PELLETS_GJ_BJ_H2          .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_HTL            .     WOOD_PELLETS_GJ_HTL            .  IONEONE      1

*DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_FT               .     MUNI_WASTE_GJ_FT               .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_SNG              .     MUNI_WASTE_GJ_SNG              .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_SYNGAS           .     MUNI_WASTE_GJ_SYNGAS           .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_TG               .     MUNI_WASTE_GJ_TG               .  IONEONE      1

*multi_biogas
*DK_CA_KBH          . Linkstorage_Res      .     MANURE_GJ_BG_Single           .     MANURE_GJ_BG_Single             .  IONEONE      1
*DK_CA_KBH          . Linkstorage_Res      .     MANURE_GJ_BG_Mix              .     MANURE_GJ_BG_Mix                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MANURE_GEN_FLOW                .     MANURE_GEN_FLOW                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     DEEP_LITTER_GEN_FLOW           .     DEEP_LITTER_GEN_FLOW           .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     FOOD_WASTE_GEN_FLOW            .     FOOD_WASTE_GEN_FLOW            .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     NATURE_AREA_GEN_FLOW           .     NATURE_AREA_GEN_FLOW           .  IONEONE      1

*------------------Biojet------------------

DK_CA_KBH          .    BioJet_50_ST                   .    STRAW_GJ_BJ                    .     BIOJETFLOW_ST                 .  IONEONE       0.40
DK_CA_KBH          .    BioJet_50_ST                   .    STRAW_GJ_BJ                    .     BIOGASOLINEFLOW_BJ_ST         .  IONEONE       0.168
DK_CA_KBH          .    BioJet_50_ST                   .    STRAW_GJ_BJ                    .     HEATFLOW_GJ                   .  IONEONE       0.21
DK_CA_KBH          .    BioJet_50_ST                   .    STRAW_GJ_BJ                    .     ELECFLOW_GJ                   .  IONEONE       0.036
DK_CA_KBH          .    BioJet_50_ST                   .    STRAW_GJ_BJ                    .     OPERATIONCOST                 .  IONEONE       -0.95

DK_CA_KBH          .    BioJet_50_WO                   .    WOOD_GJ_BJ                     .     BIOJETFLOW_WO                 .  IONEONE       0.40
DK_CA_KBH          .    BioJet_50_WO                   .    WOOD_GJ_BJ                     .     BIOGASOLINEFLOW_BJ_WO         .  IONEONE       0.168
DK_CA_KBH          .    BioJet_50_WO                   .    WOOD_GJ_BJ                     .     HEATFLOW_GJ                   .  IONEONE       0.21
DK_CA_KBH          .    BioJet_50_WO                   .    WOOD_GJ_BJ                     .     ELECFLOW_GJ                   .  IONEONE       0.036
DK_CA_KBH          .    BioJet_50_WO                   .    WOOD_GJ_BJ                     .     OPERATIONCOST                 .  IONEONE       -0.95

DK_CA_KBH          .    BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ             .     BIOJETFLOW_WP                 .  IONEONE       0.40
DK_CA_KBH          .    BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ             .     BIOGASOLINEFLOW_BJ_WP         .  IONEONE       0.168
DK_CA_KBH          .    BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ             .     HEATFLOW_GJ                   .  IONEONE       0.21
DK_CA_KBH          .    BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ             .     ELECFLOW_GJ                   .  IONEONE       0.036
DK_CA_KBH          .    BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ             .     OPERATIONCOST                 .  IONEONE       -0.95




DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_ST                  .     BIOJETFLOW                    .  IMANYONE       1
DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_WO                  .     BIOJETFLOW                    .  IMANYONE       1
DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_WP                  .     BIOJETFLOW                    .  IMANYONE       1


*------------------Ethanol------------------

DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     ETHANOL_FLOW                  .  IONEONE       0.41
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     HEATFLOW_GJ                   .  IONEONE       0.246
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     ELECFLOW_GJ                   .  IONEONE       0.03
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     OPERATIONCOST                 .  IONEONE       -0.95


*------------------FT_TG------------------
**
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     FT_TG_FLOW_WO                 .  IONEONE       0.39
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     BIOGASOLINEFLOW_FT_WO         .  IONEONE       0.17
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     HEATFLOW_GJ                   .  IONEONE       0.213
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     ELECFLOW_GJ                   .  IONEONE       0.03
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     TARFLOW                       .  IONEONE       0.001
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     OPERATIONCOST                 .  IONEONE       -0.95



DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     FT_TG_FLOW_WP                 .  IONEONE       0.39
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     BIOGASOLINEFLOW_FT_WP         .  IONEONE       0.17
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     HEATFLOW_GJ                   .  IONEONE       0.213
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     ELECFLOW_GJ                   .  IONEONE       0.03
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     TARFLOW                       .  IONEONE       0.001
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     OPERATIONCOST                 .  IONEONE       -0.95


DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     FT_TG_FLOW_ST                 .  IONEONE       0.39
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     BIOGASOLINEFLOW_FT_ST         .  IONEONE       0.17
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     HEATFLOW_GJ                   .  IONEONE       0.213
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     ELECFLOW_GJ                   .  IONEONE       0.03
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     TARFLOW                       .  IONEONE       0.001
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     OPERATIONCOST                 .  IONEONE       -0.95


*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     FT_TG_FLOW_MW                 .  IONEONE       0.39
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     BIOGASOLINEFLOW_FT_MW         .  IONEONE       0.17
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     HEATFLOW_GJ                   .  IONEONE       0.213
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     ELECFLOW_GJ                   .  IONEONE       0.03
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     TARFLOW                       .  IONEONE       0.01
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     OPERATIONCOST                 .  IONEONE       -0.95


DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_WO                  .     BIODIESELFLOW                 .  IMANYONE       1
DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_WP                  .     BIODIESELFLOW                 .  IMANYONE       1
DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_ST                  .     BIODIESELFLOW                 .  IMANYONE       1
*DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_MW                  .     BIODIESELFLOW                 .  IMANYONE       1


*------------------SNG------------------

DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     BIO_SNG_FLOW_WO               .  IONEONE       0.63
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     HEATFLOW_GJ                   .  IONEONE       0.35
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     ELECFLOW_GJ                   .  IONEONE       -0.09
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     TARFLOW                       .  IONEONE       0.01
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     OPERATIONCOST                 .  IONEONE       -0.7383


DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     BIO_SNG_FLOW_WP               .  IONEONE       0.63
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     HEATFLOW_GJ                   .  IONEONE       0.35
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     ELECFLOW_GJ                   .  IONEONE       -0.09
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     TARFLOW                       .  IONEONE       0.01
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     OPERATIONCOST                 .  IONEONE       -0.7383


DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     BIO_SNG_FLOW_ST               .  IONEONE       0.63
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     HEATFLOW_GJ                   .  IONEONE       0.35
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     ELECFLOW_GJ                   .  IONEONE       -0.09
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     TARFLOW                       .  IONEONE       0.01
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     OPERATIONCOST                 .  IONEONE       -0.7383


DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     BIO_SNG_FLOW_MW               .  IONEONE       0.63
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     HEATFLOW_GJ                   .  IONEONE       0.35
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     ELECFLOW_GJ                   .  IONEONE       -0.09
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     TARFLOW                       .  IONEONE       0.01
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     OPERATIONCOST                 .  IONEONE       -0.7383


DK_CA_KBH          .    Bio_SNG_SUM                    .    BIO_SNG_FLOW_WO                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    Bio_SNG_SUM                    .    BIO_SNG_FLOW_WP                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    Bio_SNG_SUM                    .    BIO_SNG_FLOW_ST                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    Bio_SNG_SUM                    .    BIO_SNG_FLOW_MW                .     BIO_SNG_FLOW                  .  IMANYONE       1

DK_CA_KBH          .    Bio_SNG_OUT                   .    BIO_SNG_FLOW                    .     GASFLOW                       .  IONEONE       1
*------------------SYNGAS------------------

DK_CA_KBH          .    ThermGasific_Syngas_50_WO      .    WOOD_GJ_SYNGAS                 .     BIO_SYNGAS_FLOW_WO            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_Syngas_50_WO      .    WOOD_GJ_SYNGAS                 .     HEATFLOW_GJ                   .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_Syngas_50_WO      .    WOOD_GJ_SYNGAS                 .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_Syngas_50_WO      .    WOOD_GJ_SYNGAS                 .     OPERATIONCOST                 .  IONEONE       -0.6846


DK_CA_KBH          .    ThermGasific_Syngas_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     BIO_SYNGAS_FLOW_WP            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_Syngas_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     HEATFLOW_GJ                   .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_Syngas_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_Syngas_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     OPERATIONCOST                 .  IONEONE       -0.6846


DK_CA_KBH          .    ThermGasific_Syngas_50_ST      .    STRAW_GJ_SYNGAS                .     BIO_SYNGAS_FLOW_ST            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_Syngas_50_ST      .    STRAW_GJ_SYNGAS                .     HEATFLOW_GJ                   .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_Syngas_50_ST      .    STRAW_GJ_SYNGAS                .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_Syngas_50_ST      .    STRAW_GJ_SYNGAS                .     OPERATIONCOST                 .  IONEONE       -0.6846


DK_CA_KBH          .    ThermGasific_Syngas_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     BIO_SYNGAS_FLOW_MW            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_Syngas_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     HEATFLOW_GJ                   .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_Syngas_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_Syngas_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     OPERATIONCOST                 .  IONEONE       -0.6846


DK_CA_KBH          .    Bio_Syngas_Grid_IN             .    BIO_SYNGAS_FLOW_WO             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    Bio_Syngas_Grid_IN             .    BIO_SYNGAS_FLOW_WP             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    Bio_Syngas_Grid_IN             .    BIO_SYNGAS_FLOW_ST             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    Bio_Syngas_Grid_IN             .    BIO_SYNGAS_FLOW_MW             .     BIO_SYNGAS_FLOW               .  IMANYONE      1


DK_CA_KBH          .    Bio_Syngas_Grid_OUT            .    BIO_SYNGAS_FLOW                .     BIO_SYNGAS_FLOW               .  IONEONE       1


*------------------TG------------------

DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     BIO_TG_FLOW_WO                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     HEATFLOW_GJ                   .  IONEONE       0.15
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     OPERATIONCOST                 .  IONEONE       -0.001


DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     BIO_TG_FLOW_WP                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     HEATFLOW_GJ                   .  IONEONE       0.15
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     OPERATIONCOST                 .  IONEONE       -0.001


DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     BIO_TG_FLOW_ST                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     HEATFLOW_GJ                   .  IONEONE       0.15
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     OPERATIONCOST                 .  IONEONE       -0.001


DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     BIO_TG_FLOW_MW                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     HEATFLOW_GJ                   .  IONEONE       0.15
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     OPERATIONCOST                 .  IONEONE       -0.001


DK_CA_KBH          .    Bio_TG_Grid_IN                 .    BIO_TG_FLOW_WO                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    Bio_TG_Grid_IN                 .    BIO_TG_FLOW_WP                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    Bio_TG_Grid_IN                 .    BIO_TG_FLOW_ST                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    Bio_TG_Grid_IN                 .    BIO_TG_FLOW_MW                 .     BIO_TG_FLOW                   .  IMANYONE      1


DK_CA_KBH          .    Bio_TG_Grid_OUT                .    BIO_TG_FLOW                    .     BIO_TG_FLOW                   .  IONEMANY       1
DK_CA_KBH          .    Bio_TG_Grid_OUT                .    BIO_TG_FLOW                    .     BIO_ME_FLOW                   .  IONEMANY      1


*------------------BIOGAS------------------

*------------------------------------------------------------------------
$ontext
DK_CA_KBH          .    BiogasProd_single              .    MANURE_GJ_BG_Single             .     BIOGAS_MANURE_WB_1_FLOW      .  IONEONE       0.613

DK_CA_KBH          .    BiogasProd_single              .    MANURE_GJ_BG_Single             .     ELECFLOW_GJ                  .  IONEONE       -0.0504
DK_CA_KBH          .    BiogasProd_single              .    MANURE_GJ_BG_Single             .     HEATFLOW_GJ                  .  IONEONE       -0.1197
DK_CA_KBH          .    BiogasProd_single              .    MANURE_GJ_BG_Single             .     Digestate_FLOW               .  IONEONE      0.971
DK_CA_KBH          .    BiogasProd_single              .    MANURE_GJ_BG_Single             .     OPERATIONCOST                .  IONEONE       -0.01


DK_CA_KBH          .    Biogas_Grid_SUM                 .    BIOGAS_MANURE_WB_1_FLOW       .     BIOGAS_FLOW_SUM              .  IMANYONE      1



DK_CA_KBH          .    SumSTWB                        .    MANURE_GJ_BG_Mix                .     MIX_FUEL_GJ                 .  IONEONE       1.189
DK_CA_KBH          .    SumSTWB                        .    STRAW_GJ_BIOGAS                 .     MIX_FUEL_GJ                 .  IONEONE       6.29


DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     BIOGAS_MIX_FLOW              .  IONEONE       1.98

DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     ELECFLOW_GJ                  .  IONEONE       -0.005
DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     HEATFLOW_GJ                  .  IONEONE       -0.005

*DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     ELECFLOW_GJ                  .  IONEONE       -0.1026
*DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     HEATFLOW_GJ                  .  IONEONE       -0.1124

DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     Digestate_FLOW               .  IONEONE       0.00000005
DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     OPERATIONCOST                .  IONEONE       -0.01
$offtext
*------------------------------------------------------------------------


DK_CA_KBH          .    Manure_tank                    .    MANURE_GEN_FLOW                .     MANURE_GEN_FLOW              .  IONEONE        0.4636
DK_CA_KBH          .    Straw_pre_BG                   .    STRAW_GJ_BIOGAS                .     STRAW_GJ_BIOGAS              .  IONEONE        8.4398
DK_CA_KBH          .    Deep_Litter_pre_BG             .    DEEP_LITTER_GEN_FLOW           .     DEEP_LITTER_GEN_FLOW         .  IONEONE        2.1204
DK_CA_KBH          .    Food_Waste_pre_BG              .    FOOD_WASTE_GEN_FLOW            .     FOOD_WASTE_GEN_FLOW          .  IONEONE        4.0964
DK_CA_KBH          .    Nature_Area_pre_BG             .    NATURE_AREA_GEN_FLOW           .     NATURE_AREA_GEN_FLOW         .  IONEONE        5.4530


DK_CA_KBH          .    Manure_tank                    .    MANURE_GEN_FLOW                .     OPERATIONCOST                .  IONEONE        -2.9
DK_CA_KBH          .    Straw_pre_BG                   .    STRAW_GJ_BIOGAS                .     OPERATIONCOST                .  IONEONE        -8.6
DK_CA_KBH          .    Deep_Litter_pre_BG             .    DEEP_LITTER_GEN_FLOW           .     OPERATIONCOST                .  IONEONE        -5.7
DK_CA_KBH          .    Food_Waste_pre_BG              .    FOOD_WASTE_GEN_FLOW            .     OPERATIONCOST                .  IONEONE        -5.4
DK_CA_KBH          .    Nature_Area_pre_BG             .    NATURE_AREA_GEN_FLOW           .     OPERATIONCOST                .  IONEONE        -8.6


DK_CA_KBH          .    BiogasProd_mix                 .    MANURE_GEN_FLOW                .     BIOGAS_MIX_FLOW              .  IMANYONE       1
DK_CA_KBH          .    BiogasProd_mix                 .    STRAW_GJ_BIOGAS                .     BIOGAS_MIX_FLOW              .  IMANYONE       1
DK_CA_KBH          .    BiogasProd_mix                 .    DEEP_LITTER_GEN_FLOW           .     BIOGAS_MIX_FLOW              .  IMANYONE       1
DK_CA_KBH          .    BiogasProd_mix                 .    FOOD_WASTE_GEN_FLOW            .     BIOGAS_MIX_FLOW              .  IMANYONE       1
DK_CA_KBH          .    BiogasProd_mix                 .    NATURE_AREA_GEN_FLOW           .     BIOGAS_MIX_FLOW              .  IMANYONE       1


DK_CA_KBH          .    Biogas_Grid_SUM                .    BIOGAS_MIX_FLOW                .     BIOGAS_FLOW_SUM              .  IONEONE      1


*DK_CA_KBH          .    Biogas_Grid_IN                 .    BIOGAS_FLOW_SUM                .     BIOGAS_FLOW_NoSTO            .  IONEMANY      1
*DK_CA_KBH          .    Biogas_Grid_NoSTO              .    BIOGAS_FLOW_NoSTO              .     BIOGAS_FLOW_OUT              .  IONEONE       1


*Biogas storage
DK_CA_KBH          .    Biogas_Grid_IN                 .    BIOGAS_FLOW_SUM                .     BIOGAS_FLOW_STO              .  IONEONE      1
DK_CA_KBH          .    Biogas_Grid_STO                .    BIOGAS_FLOW_STO                .     BIOGAS_FLOW_STO              .  IONEONE       1
*DK_CA_KBH          .    Biogas_Grid_STO                .    BIOGAS_FLOW_STO                .     OPERATIONCOST                .  IONEONE       -0.001
DK_CA_KBH          .    Biogas_Grid_After_STO          .    BIOGAS_FLOW_STO                .     BIOGAS_FLOW_OUT              .  IONEONE       1


DK_CA_KBH          .    Biogas_Grid_OUT                .    BIOGAS_FLOW_OUT                .     BIOGAS_FLOW                  .  IONEMANY      1

*Upgrading

DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     GASFLOW                      .  IONEONE       1
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     OPERATIONCOST                .  IONEONE       -0.001
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     ELECFLOW_GJ                  .  IONEONE       -0.053
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     HEATFLOW_GJ                  .  IONEONE       0.053
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     CO2_SOURCE_FLOW_BIO	      .  IONEONE       0.076


*------------------HYDROGEN------------------
*Hydrogen part
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW_GJ                    .     HYDROGEN_FLOW                  .  IONEONE       0.79
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW_GJ                    .     HEATFLOW_GJ                    .  IONEONE       0.00001
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW_GJ                    .     OPERATIONCOST                  .  IONEONE       -0.001

DK_CA_KBH          .    Hydrogen_Grid_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_NoST             .  IONEMANY       1
DK_CA_KBH          .    Hydrogen_Grid_OUT             .     HYDROGEN_FLOW_NoST             .     HYDROGEN_FLOW_OUT              .  IONEONE      1

*Hydrogen storage - Central (Large)
DK_CA_KBH          .    Hydrogen_Grid_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_ST_Large         .  IONEMANY       1
DK_CA_KBH          .    Hydrogen_STO_Large            .     HYDROGEN_FLOW_ST_Large         .     HYDROGEN_FLOW_ST_Large         .  IONEONE       0.9
DK_CA_KBH          .    Hydrogen_STO_Large            .     HYDROGEN_FLOW_ST_Large         .     OPERATIONCOST                  .  IONEONE       -0.001
DK_CA_KBH          .    Hydrogen_After_STO_Large      .     HYDROGEN_FLOW_ST_Large         .     HYDROGEN_FLOW_OUT              .  IONEONE      1

*Hydrogen storage - Decentral (Small)
DK_CA_KBH          .    Hydrogen_Grid_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_ST_Small         .  IONEMANY       1
DK_CA_KBH          .    Hydrogen_STO_Small            .     HYDROGEN_FLOW_ST_Small         .     HYDROGEN_FLOW_ST_Small         .  IONEONE       0.9
DK_CA_KBH          .    Hydrogen_STO_Small            .     HYDROGEN_FLOW_ST_Small         .     OPERATIONCOST                  .  IONEONE       -0.001
DK_CA_KBH          .    Hydrogen_After_STO_Small      .     HYDROGEN_FLOW_ST_Small         .     HYDROGEN_FLOW_OUT              .  IONEONE      1


DK_CA_KBH          .    Hydrogen_Before_Use           .     HYDROGEN_FLOW_OUT               .     HYDROGEN_FLOW_USE              .  IMANYONE      1


DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_BIO_BIOGAS       .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_TG               .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_ME               .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_BJ_H2_ST         .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_BJ_H2_WO         .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_BJ_H2_WP         .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_FT               .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_AS               .  IONEMANY      1
DK_CA_KBH          .    Hydrogen_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_EME              .  IONEMANY      1



************CO2*****************************
DK_CA_KBH          .    CO2_Grid_In              .     CO2_FLOW                  .     CO2_FLOW_NOSTO            .  IONEMANY     1
DK_CA_KBH          .    CO2_Grid_In              .     CO2_FLOW                  .     CO2_FLOW_STO              .  IONEMANY     1

DK_CA_KBH          .    CO2_Grid_Out             .     CO2_FLOW_NOSTO            .     CO2_FLOW_OUT              .  IONEONE      1

*CO2 Storage
DK_CA_KBH          .    CO2_Sto                  .     CO2_FLOW_STO              .     CO2_FLOW_STO              .  IONEONE      0.98
DK_CA_KBH          .    CO2_Sto                  .     ELECFLOW_GJ               .     CO2_FLOW_STO              .  IONEONE      2.334

DK_CA_KBH          .    CO2_After_Sto            .     CO2_FLOW_STO              .     CO2_FLOW_OUT              .  IONEONE      1


DK_CA_KBH          .    CO2_Before_Use           .     CO2_FLOW_OUT              .     CO2_FLOW_USE              .  IMANYONE     1


DK_CA_KBH          .   CO2_Use      	         .     CO2_FLOW_USE              .     CO2_FLOW_FT         	 .  IONEMANY     1
DK_CA_KBH          .   CO2_Use      	         .     CO2_FLOW_USE              .     CO2_FLOW_EME         	 .  IONEMANY     1



**************Methanation
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     HYDROGEN_FLOW_BIO_BIOGAS       .     GASFLOW                        .  IONEONE      2.48
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     GASFLOW                        .  IONEONE      1.5
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001



DK_CA_KBH          .    Methane_synthesis_TG_50       .     HYDROGEN_FLOW_TG               .     GASFLOW                        .  IONEONE       1.56
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     GASFLOW                        .  IONEONE       2
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001



DK_CA_KBH          .    Methanol_synthesis_TG_50      .     HYDROGEN_FLOW_ME               .     METHANOLFLOW                   .  IONEONE       2.5404
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     METHANOLFLOW                   .  IONEONE       1.1437
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     HEATFLOW_GJ                    .  IONEONE       0.108
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001


DK_CA_KBH          .    MethanolTotal		      .     METHANOLFLOW                 .     METHANOLFLOW                  .  IONEMANY       1
DK_CA_KBH          .    MethanolTotal		      .     METHANOLFLOW                 .     EMETHANOLFLOW_UPGRADE	     .  IONEMANY       1

*If I wanna include excess heat from mathanisation processes
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     HEATFLOW_GJ                    .  IONEONE      0.17
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     HEATFLOW_GJ                    .  IONEONE       0.17


*------------------Biojet_H2------------------

DK_CA_KBH          .    BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                 .     BIOJETFLOW_ST_H2              .  IONEONE       0.554
DK_CA_KBH          .    BioJet_50_ST_H2                .    HYDROGEN_FLOW_BJ_H2_ST         .     BIOJETFLOW_ST_H2              .  IONEONE       1.6294
DK_CA_KBH          .    BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                 .     BIOGASOLINEFLOW_BJ_ST_H2      .  IONEONE       0.232
DK_CA_KBH          .    BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                 .     HEATFLOW_GJ                   .  IONEONE       0.25
DK_CA_KBH          .    BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                 .     ELECFLOW_GJ                   .  IONEONE       0.034
DK_CA_KBH          .    BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                 .     OPERATIONCOST                 .  IONEONE       -0.95

DK_CA_KBH          .    BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                  .     BIOJETFLOW_WO_H2              .  IONEONE       0.554
DK_CA_KBH          .    BioJet_50_WO_H2                .    HYDROGEN_FLOW_BJ_H2_WO         .     BIOJETFLOW_WO_H2              .  IONEONE       1.6294
DK_CA_KBH          .    BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                  .     BIOGASOLINEFLOW_BJ_WO_H2      .  IONEONE       0.232
DK_CA_KBH          .    BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                  .     HEATFLOW_GJ                   .  IONEONE       0.25
DK_CA_KBH          .    BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                  .     ELECFLOW_GJ                   .  IONEONE       0.034
DK_CA_KBH          .    BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                  .     OPERATIONCOST                 .  IONEONE       -0.95

DK_CA_KBH          .    BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2          .     BIOJETFLOW_WP_H2              .  IONEONE       0.554
DK_CA_KBH          .    BioJet_50_WP_H2                .    HYDROGEN_FLOW_BJ_H2_WP         .     BIOJETFLOW_WP_H2              .  IONEONE       1.6294
DK_CA_KBH          .    BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2          .     BIOGASOLINEFLOW_BJ_WP_H2      .  IONEONE       0.232
DK_CA_KBH          .    BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2          .     HEATFLOW_GJ                   .  IONEONE       0.25
DK_CA_KBH          .    BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2          .     ELECFLOW_GJ                   .  IONEONE       0.034
DK_CA_KBH          .    BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2          .     OPERATIONCOST                 .  IONEONE       -0.95


DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_ST_H2               .     BIOJETFLOW                    .  IMANYONE       1
DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_WO_H2               .     BIOJETFLOW                    .  IMANYONE       1
DK_CA_KBH          .    BioJet_SUM                     .    BIOJETFLOW_WP_H2               .     BIOJETFLOW                    .  IMANYONE       1



DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_ST          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_WO          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_WP          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_FT_WO          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_FT_WP          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_FT_ST          .     BIOGASOLINEFLOW                .  IMANYONE       1
*DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_FT_MW          .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_ST_H2       .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_WO_H2       .     BIOGASOLINEFLOW                .  IMANYONE       1
DK_CA_KBH          .    BioGasoline_SUM                .    BIOGASOLINEFLOW_BJ_WP_H2       .     BIOGASOLINEFLOW                .  IMANYONE       1


***************EMETHANOL_SYNTHESIS*************************
DK_CA_KBH          .    EMethanol_Synthesis	 .     HYDROGEN_FLOW_EME               .     EMETHANOLFLOW		     .  IONEONE       1.186
DK_CA_KBH          .    EMethanol_Synthesis	 .     CO2_FLOW_EME         	       .     EMETHANOLFLOW		     .  IONEONE       14.5
DK_CA_KBH          .    EMethanol_Synthesis	 .     ELECFLOW_GJ            	       .     EMETHANOLFLOW		     .  IONEONE       2.7
*DK_CA_KBH          .    EMethanol_Synthesis	 .     HYDROGEN_FLOW_EME               .     OPERATIONCOST		     .  IONEONE       -0.001  


*DK_CA_KBH          .    EMethanolTotal		      .     EMETHANOLFLOW                 .     EMETHANOLFLOW                  .  IONEMANY       1
*DK_CA_KBH          .    EMethanolTotal		      .     EMETHANOLFLOW                 .     EMETHANOLFLOW_UPGRADE          .  IONEMANY       1

DK_CA_KBH          .    EMethanolTotal		      .     EMETHANOLFLOW                 .     EMETHANOLFLOW                  .  IONEMANY       1
DK_CA_KBH          .    EMethanolTotal		      .     EMETHANOLFLOW                 .     EMETHANOLFLOW_UPGRADE          .  IONEMANY       1


*******************EMethanol_Upgrade***************************

DK_CA_KBH          .    Methanol_Sum		      .     EMETHANOLFLOW_UPGRADE          .     EMETHANOLFLOW_UPGRADE          .  IMANYONE       1
DK_CA_KBH          .    Methanol_Sum		      .     EMETHANOLFLOW_UPGRADE          .     EMETHANOLFLOW_UPGRADE          .  IMANYONE       1

DK_CA_KBH          .    EMethanol_Upgrade	      .     EMETHANOLFLOW_UPGRADE          .     EME_DROPIN_FLOW                .  IONEONE       0.8
DK_CA_KBH          .    EMethanol_Upgrade	      .     EMETHANOLFLOW_UPGRADE          .     HEATFLOW_GJ			.  IONEONE       0.1
DK_CA_KBH          .    EMethanol_Upgrade	      .     EMETHANOLFLOW_UPGRADE          .     OPERATIONCOST			.  IONEONE       -0.001

DK_CA_KBH          .    EME_Upgrade_Sum        	      .     EME_DROPIN_FLOW		   .     EME_JET_FLOW		 	.  IONEONE       0.81
DK_CA_KBH          .    EME_Upgrade_Sum        	      .     EME_DROPIN_FLOW		   .     EME_GASOLINE_FLOW	 	.  IONEONE       0.1
DK_CA_KBH          .    EME_Upgrade_Sum        	      .     EME_DROPIN_FLOW		   .     EME_LPG_FLOW		 	.  IONEONE       0.09


***************E_FT*********************************
DK_CA_KBH          .    E_FT      	.     HYDROGEN_FLOW_FT                .     E_FT_SUM_FLOW			.  IONEONE       0.72
DK_CA_KBH          .    E_FT      	.     CO2_FLOW_FT                     .     E_FT_SUM_FLOW			.  IONEONE       13.8
DK_CA_KBH          .    E_FT      	.     ELECFLOW_GJ                     .     E_FT_SUM_FLOW			.  IONEONE       14.7
DK_CA_KBH          .    E_FT      	.     HEATFLOW_GJ		      .     E_FT_SUM_FLOW			.  IONEONE       -2.98
DK_CA_KBH          .    E_FT      	.     ELECFLOW_GJ            	      .     OPERATIONCOST		        .  IONEONE       -0.001  


DK_CA_KBH          .    E_FT_Sum           .     E_FT_SUM_FLOW			.     E_FT_JET_FLOW			.  IONEONE       0.254
DK_CA_KBH          .    E_FT_Sum           .     E_FT_SUM_FLOW			.     E_FT_DIESEL_FLOW			.  IONEONE       0.605
*DK_CA_KBH          .    E_FT_Sum           .     E_FT_SUM_FLOW			.     E_FT_NAPHTHA_FLOW			.  IONEONE       0.141


************AMMONIA**********************************
DK_CA_KBH          .    Nitrogen_Production  .     ELECFLOW_GJ                    .     NITROGEN_FLOW		.  IONEONE       5.555

DK_CA_KBH          .    Ammonia_Synthesis    .     NITROGEN_FLOW		  .     AMMONIA_FLOW		.  IONEONE       21.89
DK_CA_KBH          .    Ammonia_Synthesis    .     ELECFLOW_GJ                    .     AMMONIA_FLOW		.  IONEONE       14.08
DK_CA_KBH          .    Ammonia_Synthesis    .     HYDROGEN_FLOW_AS               .     AMMONIA_FLOW		.  IONEONE       0.843
DK_CA_KBH          .    Ammonia_Synthesis    .     ELECFLOW_GJ                    .     OPERATIONCOST           .  IONEONE       -0.001



*******************HTL********************************
DK_CA_KBH          .    HTL_ST                   .    STRAW_GJ_HTL                    .     HTLFLOW_ST                 .  IONEONE       0.856
DK_CA_KBH          .    HTL_ST                   .    ELECFLOW_GJ                     .     HTLFLOW_ST                 .  IONEONE       18.17
DK_CA_KBH          .    HTL_ST                   .    ELECFLOW_GJ                     .     OPERATIONCOST              .  IONEONE       -70.757

DK_CA_KBH          .    HTL_WO                   .    WOOD_GJ_HTL                     .     HTLFLOW_WO                 .  IONEONE       0.856
DK_CA_KBH          .    HTL_WO                   .    ELECFLOW_GJ                     .     HTLFLOW_WO                 .  IONEONE       18.17
DK_CA_KBH          .    HTL_WO                   .    ELECFLOW_GJ                     .     OPERATIONCOST              .  IONEONE       -70.757

DK_CA_KBH          .    HTL_WP                   .    WOOD_PELLETS_GJ_HTL             .     HTLFLOW_WP                 .  IONEONE       0.856
DK_CA_KBH          .    HTL_WP                   .    ELECFLOW_GJ                     .     HTLFLOW_WP                 .  IONEONE       18.17
DK_CA_KBH          .    HTL_WP                   .    ELECFLOW_GJ                     .     OPERATIONCOST              .  IONEONE       -70.757


DK_CA_KBH          .    HTL_Sum                     .    HTLFLOW_ST                  .     HTLFLOW                    .  IMANYONE       1
DK_CA_KBH          .    HTL_Sum                     .    HTLFLOW_WO                  .     HTLFLOW                    .  IMANYONE       1
DK_CA_KBH          .    HTL_Sum                     .    HTLFLOW_WP                  .     HTLFLOW                    .  IMANYONE       1


*Power and heat generation to ElecBuffer and HeatBuffer

DK_CA_KBH          .    BioSyngasBuffer                .    BIO_SYNGAS_FLOW                .     BIO_SYNGAS_FLOW                .  IONEONE       1
DK_CA_KBH          .    Engine_Syngas_50               .    BIO_SYNGAS_FLOW                .     ELECFLOW_GJ                    .  IONEONE       0.42
DK_CA_KBH          .    Engine_Syngas_50               .    BIO_SYNGAS_FLOW                .     HEATFLOW_GJ                    .  IONEONE       0.50
DK_CA_KBH          .    Engine_Syngas_50               .    BIO_SYNGAS_FLOW                .     OPERATIONCOST                  .  IONEONE       -1.451



DK_CA_KBH          .    BiogasBuffer                   .    BIOGAS_FLOW                    .     BIOGAS_FLOW                    .  IONEONE       1
DK_CA_KBH          .    Engine_Biogas_50               .    BIOGAS_FLOW                    .     ELECFLOW_GJ                    .  IONEONE       0.45
DK_CA_KBH          .    Engine_Biogas_50               .    BIOGAS_FLOW                    .     HEATFLOW_GJ                    .  IONEONE       0.47
DK_CA_KBH          .    Engine_Biogas_50               .    BIOGAS_FLOW                    .     OPERATIONCOST                  .  IONEONE       -1.451



**RE-fuels

DK_CA_KBH          .    AmmoniaBuffer	               .    AMMONIA_FLOW		   .     AMMONIA_FLOW			.  IONEONE       1
DK_CA_KBH          .    HTLBuffer		       .    HTLFLOW			   .     HTLFLOW		   	.  IONEONE       1

DK_CA_KBH          .    BioJetBuffer		       .    BIOJETFLOW	 		   .     BIOJETFLOW	 		.  IONEONE       1
DK_CA_KBH          .    EME_JetBuffer		       .    EME_JET_FLOW	 	   .     EME_JET_FLOW	 		.  IONEONE       1
DK_CA_KBH          .    E_FT_JetBuffer                 .    E_FT_JET_FLOW		   .     E_FT_JET_FLOW		   	.  IONEONE       1

DK_CA_KBH          .    BioGasolineBuffer              .    BIOGASOLINEFLOW		   .     BIOGASOLINEFLOW		.  IONEONE       1
DK_CA_KBH          .    MethanolBuffer                 .    METHANOLFLOW                   .     METHANOLFLOW                   .  IONEONE       1
DK_CA_KBH          .    EthanolBuffer                  .    ETHANOL_FLOW		   .     ETHANOL_FLOW			.  IONEONE       1
DK_CA_KBH          .    BiodieselBuffer                .    BIODIESELFLOW		   .     BIODIESELFLOW			.  IONEONE       1
DK_CA_KBH          .    E_FT_DieselBuffer              .    E_FT_DIESEL_FLOW		   .     E_FT_DIESEL_FLOW		.  IONEONE       1
DK_CA_KBH          .    EME_GasolineBuffer	       .    EME_GASOLINE_FLOW		   .     EME_GASOLINE_FLOW		.  IONEONE       1
DK_CA_KBH          .    EME_LPGBuffer		       .    EME_LPG_FLOW		   .     EME_LPG_FLOW			.  IONEONE       1
DK_CA_KBH          .    EMethanolBuffer		       .    EMETHANOLFLOW		   .     EMETHANOLFLOW			.  IONEONE       1


DK_CA_KBH          .    AmmoniaBuffer	               .    AMMONIA_FLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    HTLBuffer		       .    HTLFLOW			   .     OPERATIONCOST			.  IONEONE       -5

DK_CA_KBH          .    BioJetBuffer		       .    BIOJETFLOW	 		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    EME_JetBuffer		       .    EME_JET_FLOW	 	   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    E_FT_JetBuffer                 .    E_FT_JET_FLOW		   .     OPERATIONCOST			.  IONEONE       -5

DK_CA_KBH          .    BioGasolineBuffer              .    BIOGASOLINEFLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    MethanolBuffer                 .    METHANOLFLOW                   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    EthanolBuffer                  .    ETHANOL_FLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    BiodieselBuffer                .    BIODIESELFLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    E_FT_DieselBuffer              .    E_FT_DIESEL_FLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    EME_GasolineBuffer	       .    EME_GASOLINE_FLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    EME_LPGBuffer		       .    EME_LPG_FLOW		   .     OPERATIONCOST			.  IONEONE       -5
DK_CA_KBH          .    EMethanolBuffer		       .    EMETHANOLFLOW		   .     OPERATIONCOST			.  IONEONE       -5




DK_CA_KBH          .    Ammonia_Eff		       .    AMMONIA_FLOW		   .     AMMONIA_FLOW		   	.  IONEMANY       1
DK_CA_KBH          .    Ammonia_Eff		       .    AMMONIA_FLOW		   .     AMMONIA_FLOW_EXP	   	.  IONEMANY       1
DK_CA_KBH          .    HTL_Eff		       	       .    HTLFLOW			   .     HTLFLOW			.  IONEMANY       1
DK_CA_KBH          .    HTL_Eff		    	       .    HTLFLOW			   .     HTLFLOW_EXP		   	.  IONEMANY       1



DK_CA_KBH          .    Biojet_Eff		       .    BIOJETFLOW	 		   .     BIOJETFLOW	 		.  IONEMANY       1
DK_CA_KBH          .    Biojet_Eff		       .    BIOJETFLOW	 		   .     BIOJETFLOW_EXP	 		.  IONEMANY       1
DK_CA_KBH          .    EME_Jet_Eff		       .    EME_JET_FLOW	           .     EME_JET_FLOW			.  IONEMANY       1
DK_CA_KBH          .    EME_Jet_Eff		       .    EME_JET_FLOW	           .     EME_JET_FLOW_EXP	 	.  IONEMANY       1
DK_CA_KBH          .    E_FT_Jet_Eff		       .    E_FT_JET_FLOW	 	   .     E_FT_JET_FLOW		   	.  IONEMANY       1
DK_CA_KBH          .    E_FT_Jet_Eff		       .    E_FT_JET_FLOW		   .     E_FT_JET_FLOW_EXP		.  IONEMANY       1




DK_CA_KBH          .    BioGasoline_Eff                .    BIOGASOLINEFLOW		   .     BIOGASOLINEFLOW		.  IONEMANY       1
DK_CA_KBH          .    BioGasoline_Eff                .    BIOGASOLINEFLOW		   .     BIOGASOLINEFLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    Methanol_Eff                   .    METHANOLFLOW		   .     METHANOLFLOW			.  IONEMANY       1
DK_CA_KBH          .    Methanol_Eff                   .    METHANOLFLOW		   .     METHANOLFLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    Ethanol_Eff                    .    ETHANOL_FLOW		   .     ETHANOL_FLOW			.  IONEMANY       1
DK_CA_KBH          .    Ethanol_Eff                    .    ETHANOL_FLOW		   .     ETHANOL_FLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    Biodiesel_Eff                  .    BIODIESELFLOW	   	   .     BIODIESELFLOW			.  IONEMANY       1
DK_CA_KBH          .    Biodiesel_Eff                  .    BIODIESELFLOW		   .     BIODIESELFLOW_EXP		.  IONEMANY       1


DK_CA_KBH          .    E_FT_Diesel_Eff                .    E_FT_DIESEL_FLOW		   .     E_FT_DIESEL_FLOW		.  IONEMANY       1
DK_CA_KBH          .    E_FT_Diesel_Eff                .    E_FT_DIESEL_FLOW		   .     E_FT_DIESEL_FLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    EME_Gasoline_Eff               .    EME_GASOLINE_FLOW		   .     EME_GASOLINE_FLOW		.  IONEMANY       1
DK_CA_KBH          .    EME_Gasoline_Eff               .    EME_GASOLINE_FLOW		   .     EME_GASOLINE_FLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    EME_LPG_Eff                    .    EME_LPG_FLOW		   .     EME_LPG_FLOW			.  IONEMANY       1
DK_CA_KBH          .    EME_LPG_Eff                    .    EME_LPG_FLOW		   .     EME_LPG_FLOW_EXP		.  IONEMANY       1
DK_CA_KBH          .    EMethanol_Eff                  .    EMETHANOLFLOW	           .     EMETHANOLFLOW			.  IONEMANY       1
DK_CA_KBH          .    EMethanol_Eff                  .    EMETHANOLFLOW		   .     EMETHANOLFLOW_EXP		.  IONEMANY       1




*****SEA DEMAND************
DK_CA_KBH          .    Sea_fuels_sum	               .    AMMONIA_FLOW		   .     SEAFLOW			.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    HTLFLOW			   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    BIOGASOLINEFLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    METHANOLFLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    ETHANOL_FLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    BIODIESELFLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    E_FT_DIESEL_FLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    EME_GASOLINE_FLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    EME_LPG_FLOW		   .     SEAFLOW		   	.  IMANYONE       1
DK_CA_KBH          .    Sea_fuels_sum	               .    EMETHANOLFLOW		   .     SEAFLOW		   	.  IMANYONE       1

*****AIR DEMAND************
DK_CA_KBH          .    Air_fuels_sum	               .    BIOJETFLOW	 		   .     AIRFLOW			.  IMANYONE       1
DK_CA_KBH          .    Air_fuels_sum	               .    EME_JET_FLOW	 	   .     AIRFLOW			.  IMANYONE       1
DK_CA_KBH          .    Air_fuels_sum	               .    E_FT_JET_FLOW		   .     AIRFLOW			.  IMANYONE       1


*****ROAD DEMAND************
DK_CA_KBH          .    Road_fuels_sum	               .    BIOGASOLINEFLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    METHANOLFLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    ETHANOL_FLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    BIODIESELFLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    E_FT_DIESEL_FLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    EME_GASOLINE_FLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    EME_LPG_FLOW		   .     ROADFLOW			.  IMANYONE       1
DK_CA_KBH          .    Road_fuels_sum	               .    EMETHANOLFLOW		   .     ROADFLOW			.  IMANYONE       1


*Find the electricity cost

DK_CA_KBH          .    Electro                       .     ELECFLOW_GJ                    .     ELCOST_FLOW                    .  IONEONE       1
*DK_CA_KBH          .    Electro                       .     ELECFLOW_GJ                    .     OPERATIONCOST                  .  IONEONE       -1



* Other gas modelling
*DK_CA_KBH         .   ProcEximTruck                   .   OTHER_GAS_FLOW                   .   OTHER_GAS_FLOW                   .  IONEONE      1
DK_CA_KBH         .   Other_Gas_Proc                  .   OTHER_GAS_FLOW                   .   GASFLOW                          .  IONEONE      1
/;











PROCINOUTFLOW(Y,AAA,'ProcEximTruck','WOOD_GEN_FLOW','WOOD_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','WOOD_GEN_FLOW','WOOD_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','STRAW_GEN_FLOW','STRAW_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','STRAW_GEN_FLOW','STRAW_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','MUNI_WASTE_GEN_FLOW','MUNI_WASTE_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','MUNI_WASTE_GEN_FLOW','MUNI_WASTE_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','WOOD_PELLETS_GEN_FLOW','WOOD_PELLETS_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','WOOD_PELLETS_GEN_FLOW','WOOD_PELLETS_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','MANURE_GEN_FLOW','MANURE_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','MANURE_GEN_FLOW','MANURE_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','DEEP_LITTER_GEN_FLOW','DEEP_LITTER_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','DEEP_LITTER_GEN_FLOW','DEEP_LITTER_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','FOOD_WASTE_GEN_FLOW','FOOD_WASTE_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','FOOD_WASTE_GEN_FLOW','FOOD_WASTE_GEN_FLOW','IONEONE');
PROCINOUTFLOW(Y,AAA,'ProcEximTruck','NATURE_AREA_GEN_FLOW','NATURE_AREA_GEN_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','NATURE_AREA_GEN_FLOW','NATURE_AREA_GEN_FLOW','IONEONE');


*PROCINOUTFLOW(Y,AAA,'ProcEximTruck','OTHER_GAS_FLOW','OTHER_GAS_FLOW','IONEONE')$AAASOURCE(AAA)=PROCINOUTFLOW_NotY('DK_CA_KBH','ProcEximTruck','OTHER_GAS_FLOW','OTHER_GAS_FLOW','IONEONE');
















PROCINOUTFLOW(Y,AAA,PROC,IFLOWIN,IFLOWOUT,IPROCINOUTRELATION)=PROCINOUTFLOW_NotY('DK_CA_KBH',PROC,IFLOWIN,IFLOWOUT,IPROCINOUTRELATION);


*  Change in units for Electricity and Heat production flows from GJ to MWh:

*PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION)/IOF3P6;
*PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION)/IOF3P6;
*PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION)*IOF3P6;
*PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION)*IOF3P6;



