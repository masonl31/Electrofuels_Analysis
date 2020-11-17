* Note: if a flow entered in a line here in FLOWFROMTOPROC does not have corresponding information in PROCINOUTFLOW
* then the variable VPROCESFLOW corresponding to that line will be unrestricted, which is an error.


SET FLOWFROMTOPROC_A(AAA,IPROCFROM,IPROCTO,FLOW)
/


*DK_CA_KBH                .  Wood_Gen                         .   ProcEximTruck                        .   WOOD_GEN_FLOW
DK_CA_KBH                .  Straw_Gen                        .   ProcEximTruck                        .   STRAW_GEN_FLOW
DK_CA_KBH                .  Muni_Waste_Gen                   .   ProcEximTruck                        .   MUNI_WASTE_GEN_FLOW
*DK_CA_KBH                .  Wood_Pellets_Gen                 .   ProcEximTruck                        .   WOOD_PELLETS_GEN_FLOW
DK_CA_KBH                .  Manure_Gen                       .   ProcEximTruck                        .   MANURE_GEN_FLOW
*multi_biogas
DK_CA_KBH                .  Deep_Litter_Gen                  .   ProcEximTruck                        .   DEEP_LITTER_GEN_FLOW
DK_CA_KBH                .  Food_Waste_Gen                   .   ProcEximTruck                        .   FOOD_WASTE_GEN_FLOW
DK_CA_KBH                .  Nature_Area_Gen                  .   ProcEximTruck                        .   NATURE_AREA_GEN_FLOW


*DK_CA_KBH                .   ProcEximTruck                   .   Wood_Mass                            .   WOOD_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   Straw_Mass                           .   STRAW_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   Muni_Waste_Mass                      .   MUNI_WASTE_GEN_FLOW
*DK_CA_KBH                .   ProcEximTruck                   .   Wood_Pellets_Mass                    .   WOOD_PELLETS_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   Manure_Mass                          .   MANURE_GEN_FLOW
*multi_biogas
DK_CA_KBH                .   ProcEximTruck                   .   Deep_Litter_Mass                     .   DEEP_LITTER_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   Food_Waste_Mass                      .   FOOD_WASTE_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   Nature_Area_Mass                     .   NATURE_AREA_GEN_FLOW



DK_CA_KBH                .  Wood_Gen                         .   Wood_Mass                            .   WOOD_GEN_FLOW  
DK_CA_KBH                .  Wood_Pellets_Gen                 .   Wood_Pellets_Mass                    .   WOOD_PELLETS_GEN_FLOW

DK_CA_KBH                .   Wood_Mass                       .   Wood                                 .   WOOD_GEN_FLOW
DK_CA_KBH                .   Straw_Mass                      .   Straw                                .   STRAW_GEN_FLOW
DK_CA_KBH                .   Muni_Waste_Mass                 .   Muni_Waste                          .   MUNI_WASTE_GEN_FLOW
DK_CA_KBH                .   Wood_Pellets_Mass               .   Wood_Pellets                         .   WOOD_PELLETS_GEN_FLOW
*DK_CA_KBH                .   Manure_Mass                     .   Manure                               .   MANURE_GEN_FLOW
*multi_biogas



**********CO2***********************************
DK_CA_KBH                .  CO2_Source_PH                      .   CO2_PH                                  .   CO2_SOURCE_FLOW_PH
DK_CA_KBH                .  ElecBuffer_GJ                      .   CO2_PH	                           .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                     .   CO2_PH	                           .   OPERATIONCOST


DK_CA_KBH                .  CO2_Source_IND                     .   CO2_IND                                 .   CO2_SOURCE_FLOW_IND
DK_CA_KBH                .  ElecBuffer_GJ                      .   CO2_IND	                           .   ELECFLOW_GJ
DK_CA_KBH                .  HeatBuffer_GJ                      .   CO2_IND	                           .   HEATFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                     .   CO2_IND	                           .   OPERATIONCOST

DK_CA_KBH                .  CO2_Source_DAC                     .   CO2_DAC                                 .   CO2_SOURCE_FLOW_DAC
DK_CA_KBH                .  ElecBuffer_GJ                      .   CO2_DAC	                           .   ELECFLOW_GJ
DK_CA_KBH                .  HeatBuffer_GJ                      .   CO2_DAC	                           .   HEATFLOW_GJ

DK_CA_KBH                .  CO2_Bio_Pot	                       .   CO2_Bio	                           .   CO2_SOURCE_FLOW_BIO
DK_CA_KBH                .  CO2_Bio_Pot	                       .   CO2_Sink	                           .   CO2_SINK_FLOW_BIO

DK_CA_KBH                .  ElecBuffer_GJ                      .   CO2_Bio	                           .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                     .   CO2_Bio	                           .   OPERATIONCOST

DK_CA_KBH                .  CO2_PH                             .   CO2                                     .   CO2_FLOW_PH
DK_CA_KBH                .  CO2_IND                            .   CO2                                     .   CO2_FLOW_IND
DK_CA_KBH                .  CO2_DAC                            .   CO2                                     .   CO2_FLOW_DAC
DK_CA_KBH                .  CO2_BIO                            .   CO2                                     .   CO2_FLOW_BIO


*------------------Electricity------------------

*Electricity from Balmorel to OptiFlow
DK_CA_KBH                .  ElecBuffer                       .   EL_Bal_to_Opti_Conv                  .   ELECFLOW
DK_CA_KBH                .  Money_buffer_T                   .   EL_Bal_to_Opti_Conv                  .   OPERATIONCOST

DK_CA_KBH                .  EL_Bal_to_Opti_Conv              .   EL_grid_tariff                       .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   EL_grid_tariff                       .   OPERATIONCOST

DK_CA_KBH                .  EL_grid_tariff                   .   ElecBuffer_GJ                        .   ELECFLOW_GJ


*Electricity from OptiFlow to Balmorel
DK_CA_KBH                .  EL_Opti_to_Bal_Conv              .   ElecBuffer                           .   ELECFLOW



*------------------Heat------------------

*Heat from Balmorel to OptiFlow
DK_CA_KBH                .  HeatBuffer                       .   Heat_Bal_to_Opti_Conv                .   HEATFLOW
DK_CA_KBH                .  Money_buffer_T                   .   Heat_Bal_to_Opti_Conv                .   OPERATIONCOST

DK_CA_KBH                .  Heat_Bal_to_Opti_Conv            .   Heat_grid_tariff                     .   HEATFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   Heat_grid_tariff                     .   OPERATIONCOST

DK_CA_KBH                .  Heat_grid_tariff                 .   HeatBuffer_GJ                        .   HEATFLOW_GJ


*Heat from OptiFlow to Balmorel
DK_CA_KBH                .  Heat_Opti_to_Bal_Conv            .   HeatBuffer                           .   HEATFLOW








*------------------BioJET------------------

DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_BJ
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_ST                         .   STRAW_GJ_BJ
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_ST                         .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_ST                     .   BioJet_SUM                           .   BIOJETFLOW_ST
DK_CA_KBH                .  BioJet_50_ST                     .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_ST
DK_CA_KBH                .  BioJet_50_ST                     .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_ST                     .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_BJ
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_WO                         .   WOOD_GJ_BJ
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_WO                         .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_WO                     .   BioJet_SUM                           .   BIOJETFLOW_WO
DK_CA_KBH                .  BioJet_50_WO                     .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_WO
DK_CA_KBH                .  BioJet_50_WO                     .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_WO                     .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_BJ
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_WP                         .   WOOD_PELLETS_GJ_BJ
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_WP                         .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_WP                     .   BioJet_SUM                           .   BIOJETFLOW_WP
DK_CA_KBH                .  BioJet_50_WP                     .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_WP
DK_CA_KBH                .  BioJet_50_WP                     .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_WP                     .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


*DK_CA_KBH                .  BioJet_SUM                       .   BioJetBuffer                         .   BIOJETFLOW




*------------------Ethanol------------------

DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_ET
DK_CA_KBH                .  Linkstorage_Res                  .   Ethanol_50                           .   STRAW_GJ_ET
DK_CA_KBH                .  Money_buffer_T                   .   Ethanol_50                           .   OPERATIONCOST
DK_CA_KBH                .  Ethanol_50                       .   EthanolBuffer                        .   ETHANOL_FLOW
DK_CA_KBH                .  Ethanol_50                       .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Ethanol_50                       .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ

*------------------FT_TG------------------

DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_WO                .   WOOD_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_WO                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_WO
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_FT_WO
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_WP                .   WOOD_PELLETS_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_WP                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_WP
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_FT_WP
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_ST                .   STRAW_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_ST                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_ST
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_FT_ST
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   Tar                                  .   TARFLOW
**
*DK_CA_KBH                .  Muni_Waste                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_FT
*DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_MW                .   MUNI_WASTE_GJ_FT
*DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_MW                .   OPERATIONCOST
*DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_MW
*DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_FT_MW
*DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
*DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ
*DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   Tar                                  .   TARFLOW


DK_CA_KBH                .  Biodiesel_FT_SUM                 .   BiodieselBuffer                      .   BIODIESELFLOW

*------------------SNG------------------
DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_WO               .   WOOD_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_WO               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   Bio_SNG_SUM                          .   BIO_SNG_FLOW_WO
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ElecBuffer_GJ                    .   ThermGasific_SNG_50_WO               .   ELECFLOW_GJ
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   Tar                                  .   TARFLOW

**
DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_WP               .   WOOD_PELLETS_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_WP               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   Bio_SNG_SUM                          .   BIO_SNG_FLOW_WP
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ElecBuffer_GJ                    .   ThermGasific_SNG_50_WP               .   ELECFLOW_GJ
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_ST               .   STRAW_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_ST               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   Bio_SNG_SUM                          .   BIO_SNG_FLOW_ST
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ElecBuffer_GJ                    .   ThermGasific_SNG_50_ST               .   ELECFLOW_GJ
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Muni_Waste                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_MW               .   MUNI_WASTE_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_MW               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   Bio_SNG_SUM                          .   BIO_SNG_FLOW_MW
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ElecBuffer_GJ                    .   ThermGasific_SNG_50_MW               .   ELECFLOW_GJ
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   Tar                                  .   TARFLOW


DK_CA_KBH                .  BIO_SNG_SUM                      .   BIO_SNG_OUT                          .   BIO_SNG_FLOW

DK_CA_KBH                .  BIO_SNG_OUT                      .   GasBuffer                            .   GASFLOW




*------------------SYNGAS------------------

DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_Syngas_50_WO            .   WOOD_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_Syngas_50_WO            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_Syngas_50_WO        .   Bio_Syngas_Grid_IN                   .   BIO_SYNGAS_FLOW_WO
DK_CA_KBH                .  ThermGasific_Syngas_50_WO        .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ThermGasific_Syngas_50_WO        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_Syngas_50_WP            .   WOOD_PELLETS_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_Syngas_50_WP            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_Syngas_50_WP        .   Bio_Syngas_Grid_IN                   .   BIO_SYNGAS_FLOW_WP
DK_CA_KBH                .  ThermGasific_Syngas_50_WP        .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ThermGasific_Syngas_50_WP        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_Syngas_50_ST            .   STRAW_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_Syngas_50_ST            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_Syngas_50_ST        .   Bio_Syngas_Grid_IN                   .   BIO_SYNGAS_FLOW_ST
DK_CA_KBH                .  ThermGasific_Syngas_50_ST        .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ThermGasific_Syngas_50_ST        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Muni_Waste                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_Syngas_50_MW            .   MUNI_WASTE_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_Syngas_50_MW            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_Syngas_50_MW        .   Bio_Syngas_Grid_IN                   .   BIO_SYNGAS_FLOW_MW
DK_CA_KBH                .  ThermGasific_Syngas_50_MW        .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  ThermGasific_Syngas_50_MW        .   Tar                                  .   TARFLOW

DK_CA_KBH                .  Bio_Syngas_Grid_IN               .   Bio_Syngas_Grid_OUT                  .   BIO_SYNGAS_FLOW
DK_CA_KBH                .  Bio_Syngas_Grid_OUT              .   BioSyngasBuffer                      .   BIO_SYNGAS_FLOW



*------------------TG------------------
DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_WO                             .   WOOD_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_WO                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_WO                         .   Bio_TG_Grid_IN                       .   BIO_TG_FLOW_WO
DK_CA_KBH                .  TG_50_WO                         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_50_WO                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_WP                             .   WOOD_PELLETS_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_WP                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_WP                         .   Bio_TG_Grid_IN                       .   BIO_TG_FLOW_WP
DK_CA_KBH                .  TG_50_WP                         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_50_WP                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_ST                             .   STRAW_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_ST                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_ST                         .   Bio_TG_Grid_IN                       .   BIO_TG_FLOW_ST
DK_CA_KBH                .  TG_50_ST                         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_50_ST                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  Muni_Waste                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_MW                             .   MUNI_WASTE_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_MW                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_MW                         .   Bio_TG_Grid_IN                       .   BIO_TG_FLOW_MW
DK_CA_KBH                .  TG_50_MW                         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  TG_50_MW                         .   Tar                                  .   TARFLOW

DK_CA_KBH                .  Bio_TG_Grid_IN                   .   Bio_TG_Grid_OUT                      .   BIO_TG_FLOW



*------------------BIOGAS------------------



*------------------------------------------------------------------------------------------
$ontext

*BIOGAS from single input plant
DK_CA_KBH                .  Manure                           .   BiogasProd_single                    .   MANURE_GJ_BG_Single
DK_CA_KBH                .  Money_buffer_T                   .   BiogasProd_single                    .   OPERATIONCOST
DK_CA_KBH                .  BiogasProd_single                .   Biogas_Grid_SUM                      .   BIOGAS_MANURE_WB_1_FLOW
DK_CA_KBH                .  BiogasProd_single                .   Digestate                            .   Digestate_FLOW


DK_CA_KBH                .  ElecBuffer_GJ                    .   BiogasProd_single                    .   ELECFLOW_GJ
DK_CA_KBH                .  HeatBuffer_GJ                    .   BiogasProd_single                    .   HEATFLOW_GJ



*BIOGAS from mix plant
DK_CA_KBH                .  Manure_and_Wetbio                .   Linkstorage_Res                       .   MANURE_GJ_BG_Mix
DK_CA_KBH                .  Linkstorage_Res                  .   SumSTWB                               .   MANURE_GJ_BG_Mix

DK_CA_KBH                .  Straw                            .   Straw_Biogas                          .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Straw_Biogas                     .   Linkstorage_Res                       .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Linkstorage_Res                  .   SumSTWB                               .   STRAW_GJ_BIOGAS

DK_CA_KBH                .  SumSTWB                          .   BiogasProd_mix                        .   MIX_FUEL_GJ
DK_CA_KBH                .  Money_buffer_T                   .   BiogasProd_mix                        .   OPERATIONCOST
DK_CA_KBH                .  BiogasProd_mix                   .   Biogas_Grid_SUM                       .   BIOGAS_MIX_FLOW
DK_CA_KBH                .  BiogasProd_mix                   .   Digestate                             .   Digestate_FLOW

DK_CA_KBH                .  ElecBuffer_GJ                    .   BiogasProd_mix                        .   ELECFLOW_GJ
DK_CA_KBH                .  HeatBuffer_GJ                    .   BiogasProd_mix                        .   HEATFLOW_GJ
$offtext
*------------------------------------------------------------------------

DK_CA_KBH                .  Straw                            .   Straw_Biogas                          .   STRAW_GJ_BIOGAS

DK_CA_KBH                .  Manure_Mass                      .   Linkstorage_Res                       .   MANURE_GEN_FLOW
DK_CA_KBH                .  Straw_Biogas                     .   Linkstorage_Res                       .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Deep_Litter_Mass                 .   Linkstorage_Res                       .   DEEP_LITTER_GEN_FLOW
DK_CA_KBH                .  Food_Waste_Mass                  .   Linkstorage_Res                       .   FOOD_WASTE_GEN_FLOW
DK_CA_KBH                .  Nature_Area_Mass                 .   Linkstorage_Res                       .   NATURE_AREA_GEN_FLOW



DK_CA_KBH                .  Linkstorage_Res                  .   Manure_tank                           .   MANURE_GEN_FLOW
DK_CA_KBH                .  Linkstorage_Res                  .   Straw_pre_BG                          .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Linkstorage_Res                  .   Deep_Litter_pre_BG                    .   DEEP_LITTER_GEN_FLOW
DK_CA_KBH                .  Linkstorage_Res                  .   Food_Waste_pre_BG                     .   FOOD_WASTE_GEN_FLOW
DK_CA_KBH                .  Linkstorage_Res                  .   Nature_Area_pre_BG                    .   NATURE_AREA_GEN_FLOW




DK_CA_KBH                .  Money_buffer_T                   .   Manure_tank                           .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   Straw_pre_BG                          .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   Deep_Litter_pre_BG                    .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   Food_Waste_pre_BG                     .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   Nature_Area_pre_BG                    .   OPERATIONCOST





DK_CA_KBH                .  Manure_tank                      .   BiogasProd_mix                        .   MANURE_GEN_FLOW
DK_CA_KBH                .  Straw_pre_BG                     .   BiogasProd_mix                        .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Deep_Litter_pre_BG               .   BiogasProd_mix                        .   DEEP_LITTER_GEN_FLOW
DK_CA_KBH                .  Food_Waste_pre_BG                .   BiogasProd_mix                        .   FOOD_WASTE_GEN_FLOW
DK_CA_KBH                .  Nature_Area_pre_BG               .   BiogasProd_mix                        .   NATURE_AREA_GEN_FLOW



DK_CA_KBH                .  BiogasProd_mix                   .   Biogas_Grid_SUM                       .   BIOGAS_MIX_FLOW



DK_CA_KBH                .  Biogas_Grid_SUM                  .   Biogas_Grid_IN                        .   BIOGAS_FLOW_SUM



*DK_CA_KBH                .  Biogas_Grid_IN                   .   Biogas_Grid_NoSTO                     .   BIOGAS_FLOW_NoSTO
*DK_CA_KBH                .  Biogas_Grid_NoSTO                .   Biogas_Grid_OUT                       .   BIOGAS_FLOW_OUT

*Biogas Storage
DK_CA_KBH                .  Biogas_Grid_IN                   .   Biogas_Grid_STO                      .   BIOGAS_FLOW_STO
DK_CA_KBH                .  Biogas_Grid_STO                  .   Biogas_Grid_After_STO                .   BIOGAS_FLOW_STO
DK_CA_KBH                .  Biogas_Grid_After_STO            .   Biogas_Grid_OUT                      .   BIOGAS_FLOW_OUT



DK_CA_KBH                .  Biogas_Grid_OUT                  .   BiogasBuffer                         .   BIOGAS_FLOW







*Upgrading
DK_CA_KBH                .  Biogas_Grid_OUT                  .   BiogasUpgr_BMETH_50                  .   BIOGAS_FLOW
DK_CA_KBH                .  BiogasUpgr_BMETH_50              .   GasBuffer                            .   GASFLOW
DK_CA_KBH                .  Money_buffer_T                   .   BiogasUpgr_BMETH_50                  .   OPERATIONCOST
DK_CA_KBH                .  ElecBuffer_GJ                    .   BiogasUpgr_BMETH_50                  .   ELECFLOW_GJ
DK_CA_KBH                .  BiogasUpgr_BMETH_50              .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BiogasUpgr_BMETH_50              .   CO2_Bio_Pot		              .   CO2_SOURCE_FLOW_BIO

*------------------HYDROGEN------------------
*Hydrogen part
DK_CA_KBH                .  ElecBuffer_GJ                    .   Electrolysis_H2Prod                  .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   Electrolysis_H2Prod                  .   OPERATIONCOST
DK_CA_KBH                .  Electrolysis_H2Prod              .   Hydrogen_GRID_IN                     .   HYDROGEN_FLOW
DK_CA_KBH                .  Electrolysis_H2Prod              .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Hydrogen_GRID_IN                 .   Hydrogen_GRID_OUT                    .   HYDROGEN_FLOW_NoST
DK_CA_KBH                .  Hydrogen_GRID_OUT                .   HYDROGEN_Before_Use                  .   HYDROGEN_FLOW_OUT


*Hydrogen storage - Central (Large)
DK_CA_KBH                .  Hydrogen_Grid_IN                 .   Hydrogen_STO_Large                   .   HYDROGEN_FLOW_ST_Large
DK_CA_KBH                .  Money_buffer_T                   .   Hydrogen_STO_Large                   .   OPERATIONCOST
DK_CA_KBH                .  Hydrogen_STO_Large               .   HYDROGEN_After_STO_Large             .   HYDROGEN_FLOW_ST_Large
DK_CA_KBH                .  Hydrogen_After_STO_Large         .   HYDROGEN_Before_Use                  .   HYDROGEN_FLOW_OUT

*Hydrogen storage - Decentral (Small)
DK_CA_KBH                .  Hydrogen_Grid_IN                 .   Hydrogen_STO_Small                   .   HYDROGEN_FLOW_ST_Small
DK_CA_KBH                .  Money_buffer_T                   .   Hydrogen_STO_Small                   .   OPERATIONCOST
DK_CA_KBH                .  Hydrogen_STO_Small               .   Hydrogen_After_STO_Small             .   HYDROGEN_FLOW_ST_Small
DK_CA_KBH                .  Hydrogen_After_STO_Small         .   Hydrogen_Before_Use                  .   HYDROGEN_FLOW_OUT



DK_CA_KBH                .  Hydrogen_Before_Use              .   Hydrogen_Use                         .   HYDROGEN_FLOW_USE

DK_CA_KBH                .  Hydrogen_Use                     .   Methanisation_Bio_BioGas             .   HYDROGEN_FLOW_BIO_BIOGAS
DK_CA_KBH                .  Hydrogen_Use                     .   Methane_synthesis_TG_50              .   HYDROGEN_FLOW_TG
DK_CA_KBH                .  Hydrogen_Use                     .   Methanol_synthesis_TG_50             .   HYDROGEN_FLOW_ME


************CO2********************************************
DK_CA_KBH                .  CO2                         .   CO2_Grid_In                     .   CO2_FLOW
DK_CA_KBH                .  CO2_Grid_In                 .   CO2_Grid_Out                    .   CO2_FLOW_NOSTO
DK_CA_KBH                .  CO2_Grid_Out                .   CO2_Before_Use                  .   CO2_FLOW_OUT


***********CO2_Storage*************************************
DK_CA_KBH                .  CO2_Grid_In                 .   CO2_Sto                   .   CO2_FLOW_STO
DK_CA_KBH                .  ElecBuffer_GJ               .   CO2_Sto	              .   ELECFLOW_GJ

DK_CA_KBH                .  CO2_Sto                     .   CO2_After_Sto             .   CO2_FLOW_STO
DK_CA_KBH                .  CO2_After_Sto               .   CO2_Before_Use            .   CO2_FLOW_OUT

DK_CA_KBH                .  CO2_Before_Use              .   CO2_Use                   .   CO2_FLOW_USE



*Methanation
DK_CA_KBH                .  Biogas_Grid_OUT                  .   Methanisation_Bio_BioGas             .   BIOGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methanisation_Bio_BioGas             .   OPERATIONCOST
DK_CA_KBH                .  Methanisation_Bio_BioGas         .   GasBuffer                            .   GASFLOW


DK_CA_KBH                .  Bio_TG_Grid_OUT                  .   Methane_synthesis_TG_50               .   BIO_TG_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methane_synthesis_TG_50               .   OPERATIONCOST
DK_CA_KBH                .  Methane_synthesis_TG_50          .   GasBuffer                             .   GASFLOW


DK_CA_KBH                .  Bio_TG_Grid_OUT                  .   Methanol_synthesis_TG_50              .   BIO_ME_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methanol_synthesis_TG_50              .   OPERATIONCOST
*DK_CA_KBH                .  Methanol_synthesis_TG_50        .   MethanolBuffer                        .   METHANOLFLOW


DK_CA_KBH                .  Methanol_synthesis_TG_50         .   MethanolTotal                         .   METHANOLFLOW

DK_CA_KBH                .  MethanolTotal                    .   MethanolBuffer			       .   METHANOLFLOW


*If I wanna include excess heat from mathanisation processes
DK_CA_KBH                .  Methanisation_Bio_BioGas         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Methane_synthesis_TG_50          .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Methanol_synthesis_TG_50         .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ

*------------------BioJET------------------

DK_CA_KBH                .  Hydrogen_Use                     .   BioJet_50_ST_H2                      .   HYDROGEN_FLOW_BJ_H2_ST
DK_CA_KBH                .  Hydrogen_Use                     .   BioJet_50_WO_H2                      .   HYDROGEN_FLOW_BJ_H2_WO
DK_CA_KBH                .  Hydrogen_Use                     .   BioJet_50_WP_H2                      .   HYDROGEN_FLOW_BJ_H2_WP


DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_BJ_H2
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_ST_H2                      .   STRAW_GJ_BJ_H2
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_ST_H2                      .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_ST_H2                  .   BioJet_SUM                           .   BIOJETFLOW_ST_H2
DK_CA_KBH                .  BioJet_50_ST_H2                  .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_ST_H2
DK_CA_KBH                .  BioJet_50_ST_H2                  .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_ST_H2                  .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


DK_CA_KBH                .  Wood                             .   Linkstorage_Res                      .   WOOD_GJ_BJ_H2
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_WO_H2                      .   WOOD_GJ_BJ_H2
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_WO_H2                      .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_WO_H2                  .   BioJet_SUM                           .   BIOJETFLOW_WO_H2
DK_CA_KBH                .  BioJet_50_WO_H2                  .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_WO_H2
DK_CA_KBH                .  BioJet_50_WO_H2                  .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_WO_H2                  .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_BJ_H2
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50_WP_H2                      .   WOOD_PELLETS_GJ_BJ_H2
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50_WP_H2                      .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50_WP_H2                  .   BioJet_SUM                           .   BIOJETFLOW_WP_H2
DK_CA_KBH                .  BioJet_50_WP_H2                  .   BioGasoline_SUM                      .   BIOGASOLINEFLOW_BJ_WP_H2
DK_CA_KBH                .  BioJet_50_WP_H2                  .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  BioJet_50_WP_H2                  .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ


DK_CA_KBH                .  BioJet_SUM                       .   BioJetBuffer                         .   BIOJETFLOW
DK_CA_KBH                .  BioGasoline_SUM                  .   BioGasolineBuffer                    .   BIOGASOLINEFLOW

***************EMETHANOL_SYNTHESIS*************************
DK_CA_KBH                .  CO2_Use                  	     .   EMethanol_synthesis              	.   CO2_FLOW_EME
DK_CA_KBH                .  Hydrogen_Use                     .   EMethanol_synthesis                    .   HYDROGEN_FLOW_EME
DK_CA_KBH                .  ElecBuffer_GJ                    .   EMethanol_synthesis                    .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   EMethanol_synthesis                    .   OPERATIONCOST

DK_CA_KBH                .  EMethanol_synthesis              .   EMethanolTotal                         .   EMETHANOLFLOW

DK_CA_KBH                .  EMethanolTotal                   .   EMethanolBuffer			.   EMETHANOLFLOW


*******************EMethanol_Upgrade***************************
DK_CA_KBH                .  MethanolTotal			.   Methanol_Sum		        .   EMETHANOLFLOW_UPGRADE
DK_CA_KBH                .  EMethanolTotal			.   Methanol_Sum		        .   EMETHANOLFLOW_UPGRADE


DK_CA_KBH                .  Methanol_Sum		        .   EMethanol_Upgrade			.   EMETHANOLFLOW_UPGRADE

*DK_CA_KBH                .  EMethanolTotal			.   EMethanol_Upgrade			.   EMETHANOLFLOW_UPGRADE
*DK_CA_KBH                .  Money_buffer_T                      .   EMethanol_Upgrade			.   OPERATIONCOST

DK_CA_KBH                .  EMethanol_Upgrade			.   EME_Upgrade_Sum			.   EME_DROPIN_FLOW
DK_CA_KBH                .  EMethanol_Upgrade			.   Heat_Opti_to_Bal_Conv               .   HEATFLOW_GJ

DK_CA_KBH                .  EME_Upgrade_Sum			.   EME_JetBuffer			.   EME_JET_FLOW	 
DK_CA_KBH                .  EME_Upgrade_Sum			.   EME_GasolineBuffer			.   EME_GASOLINE_FLOW
DK_CA_KBH                .  EME_Upgrade_Sum			.   EME_LPGBuffer			.   EME_LPG_FLOW


***************E_FT*********************************
DK_CA_KBH                .  CO2_Use                  	     .   E_FT			                .   CO2_FLOW_FT
DK_CA_KBH                .  Hydrogen_Use                     .   E_FT                                   .   HYDROGEN_FLOW_FT
DK_CA_KBH                .  ElecBuffer_GJ                    .   E_FT                                   .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   E_FT                                   .   OPERATIONCOST


DK_CA_KBH                .  E_FT                  	     .   E_FT_Sum	                        .   E_FT_SUM_FLOW
DK_CA_KBH                .  E_FT                  	     .   Heat_Opti_to_Bal_Conv                  .   HEATFLOW_GJ

DK_CA_KBH                .  E_FT_Sum                      .   E_FT_JetBuffer		       		.   E_FT_JET_FLOW
DK_CA_KBH                .  E_FT_Sum                      .   E_FT_DieselBuffer                		.   E_FT_DIESEL_FLOW
*DK_CA_KBH                .  E_FT_Sum                  	  .   E_FT_NaphthaBuffer	       		.   E_FT_NAPHTHA_FLOW


*******************AMMONIA****************************
DK_CA_KBH                .  ElecBuffer_GJ                    .   Nitrogen_Production			.   ELECFLOW_GJ

DK_CA_KBH                .  Nitrogen_Production              .   Ammonia_Synthesis			.   NITROGEN_FLOW
DK_CA_KBH                .  ElecBuffer_GJ                    .   Ammonia_Synthesis			.   ELECFLOW_GJ
DK_CA_KBH                .  Hydrogen_Use                     .   Ammonia_Synthesis			.   HYDROGEN_FLOW_AS
DK_CA_KBH                .  Money_buffer_T                   .   Ammonia_Synthesis			.   OPERATIONCOST

DK_CA_KBH                .  Ammonia_Synthesis		     .   AmmoniaBuffer				.   AMMONIA_FLOW


*******************HTL******************************

DK_CA_KBH                .  Straw                            .   Linkstorage_Res                      .   STRAW_GJ_HTL
DK_CA_KBH                .  Linkstorage_Res                  .   HTL_ST                               .   STRAW_GJ_HTL
DK_CA_KBH                .  ElecBuffer_GJ                    .   HTL_ST                               .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   HTL_ST                               .   OPERATIONCOST
DK_CA_KBH                .  HTL_ST                           .   HTL_Sum                              .   HTLFLOW_ST

DK_CA_KBH                .  Wood			     .   Linkstorage_Res                      .   WOOD_GJ_HTL
DK_CA_KBH                .  Linkstorage_Res                  .   HTL_WO                               .   WOOD_GJ_HTL
DK_CA_KBH                .  ElecBuffer_GJ                    .   HTL_WO                               .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   HTL_WO                               .   OPERATIONCOST
DK_CA_KBH                .  HTL_WO                           .   HTL_Sum                              .   HTLFLOW_WO

DK_CA_KBH                .  Wood_Pellets                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_HTL
DK_CA_KBH                .  Linkstorage_Res                  .   HTL_WP                               .   WOOD_PELLETS_GJ_HTL
DK_CA_KBH                .  ElecBuffer_GJ                    .   HTL_WP                               .   ELECFLOW_GJ
DK_CA_KBH                .  Money_buffer_T                   .   HTL_WP                               .   OPERATIONCOST
DK_CA_KBH                .  HTL_WP                           .   HTL_Sum                              .   HTLFLOW_WP


DK_CA_KBH                .  HTL_Sum                          .   HTLBuffer                            .   HTLFLOW


**************************CHP engine******************************
*Using "raw" gasses
*Engine_SYNGAS_50
DK_CA_KBH                .  BioSyngasBuffer                  .   Engine_Syngas_50                     .   BIO_SYNGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Engine_Syngas_50                     .   OPERATIONCOST
DK_CA_KBH                .  Engine_Syngas_50                 .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Engine_Syngas_50                 .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ

*Engine_BIOGAS_50
DK_CA_KBH                .  BiogasBuffer                     .   Engine_Biogas_50                     .   BIOGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Engine_Biogas_50                     .   OPERATIONCOST
DK_CA_KBH                .  Engine_Biogas_50                 .   Heat_Opti_to_Bal_Conv                .   HEATFLOW_GJ
DK_CA_KBH                .  Engine_Biogas_50                 .   EL_Opti_to_Bal_Conv                  .   ELECFLOW_GJ





****************BUFFERS****************

DK_CA_KBH                .  Money_buffer_T                   .   AmmoniaBuffer                    .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   HTLBuffer                        .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   BioJetBuffer                     .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   E_FT_JetBuffer                   .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   EME_JetBuffer		     	  .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   BioGasolineBuffer                .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   MethanolBuffer                   .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   EthanolBuffer                    .   OPERATIONCOST

DK_CA_KBH                .  Money_buffer_T                   .   BiodieselBuffer                  .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   E_FT_DieselBuffer                .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   EME_GasolineBuffer	          .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   EME_LPGBuffer		     	  .   OPERATIONCOST
DK_CA_KBH                .  Money_buffer_T                   .   EMethanolBuffer		  .   OPERATIONCOST


****************SEA********************

DK_CA_KBH                .  AmmoniaBuffer                   .   Ammonia_Eff                       .   AMMONIA_FLOW
DK_CA_KBH                .  Ammonia_Eff                     .   Sea_fuels_sum                     .   AMMONIA_FLOW
DK_CA_KBH                .  Ammonia_Eff                     .   AmmoniaBuffer_Exp                 .   AMMONIA_FLOW_EXP


DK_CA_KBH                .  HTLBuffer                   .   HTL_Eff                       .   HTLFLOW
DK_CA_KBH                .  HTL_Eff                     .   Sea_fuels_sum                 .   HTLFLOW
DK_CA_KBH                .  HTL_Eff                     .   HTLBuffer_Exp                 .   HTLFLOW_EXP


DK_CA_KBH                .  Sea_fuels_sum                   .   SeaBuffer                         .   SEAFLOW


***************AIR*********************

DK_CA_KBH                .  BioJetBuffer                   .   BioJet_Eff                       .   BIOJETFLOW	 
DK_CA_KBH                .  BioJet_Eff                     .   Air_fuels_sum                    .   BIOJETFLOW	 
DK_CA_KBH                .  BioJet_Eff                     .   BioJetBuffer_Exp                 .   BIOJETFLOW_EXP	 

DK_CA_KBH                .  E_FT_JetBuffer              .   E_FT_Jet_Eff                  .   E_FT_JET_FLOW		   
DK_CA_KBH                .  E_FT_Jet_Eff                .   Air_fuels_sum                 .   E_FT_JET_FLOW		   
DK_CA_KBH                .  E_FT_Jet_Eff                .   E_FT_JetBuffer_Exp            .   E_FT_JET_FLOW_EXP		   

DK_CA_KBH                .  EME_JetBuffer	       .   EME_Jet_Eff		         .   EME_JET_FLOW	           
DK_CA_KBH                .  EME_Jet_Eff		       .   Air_fuels_sum                 .   EME_JET_FLOW	           
DK_CA_KBH                .  EME_Jet_Eff		       .   EME_JetBuffer_Exp             .   EME_JET_FLOW_EXP	           

DK_CA_KBH                .  Air_fuels_sum                    .   AirBuffer                         .   AIRFLOW


***************ROAD*********************


DK_CA_KBH                .  BioGasolineBuffer              .   BioGasoline_Eff                    .   BIOGASOLINEFLOW
DK_CA_KBH                .  BioGasoline_Eff                .   Road_fuels_sum                     .   BIOGASOLINEFLOW
DK_CA_KBH                .  BioGasoline_Eff                .   Sea_fuels_sum                      .   BIOGASOLINEFLOW
DK_CA_KBH                .  BioGasoline_Eff                .   BioGasolineBuffer_Exp              .   BIOGASOLINEFLOW_EXP

DK_CA_KBH                .  MethanolBuffer                 .   Methanol_Eff                       .   METHANOLFLOW
DK_CA_KBH                .  Methanol_Eff                   .   Road_fuels_sum                     .   METHANOLFLOW
DK_CA_KBH                .  Methanol_Eff                   .   Sea_fuels_sum                      .   METHANOLFLOW
DK_CA_KBH                .  Methanol_Eff                   .   MethanolBuffer_Exp                 .   METHANOLFLOW_EXP

DK_CA_KBH                .  EthanolBuffer                  .   Ethanol_Eff                        .   ETHANOL_FLOW
DK_CA_KBH                .  Ethanol_Eff                    .   Road_fuels_sum                     .   ETHANOL_FLOW
DK_CA_KBH                .  Ethanol_Eff                    .   Sea_fuels_sum                      .   ETHANOL_FLOW
DK_CA_KBH                .  Ethanol_Eff                    .   EthanolBuffer_Exp                  .   ETHANOL_FLOW_EXP

DK_CA_KBH                .  BiodieselBuffer                .   Biodiesel_Eff                      .   BIODIESELFLOW
DK_CA_KBH                .  Biodiesel_Eff                  .   Road_fuels_sum                     .   BIODIESELFLOW
DK_CA_KBH                .  Biodiesel_Eff                  .   Sea_fuels_sum                      .   BIODIESELFLOW
DK_CA_KBH                .  Biodiesel_Eff                  .   BiodieselBuffer_Exp                .   BIODIESELFLOW_EXP



DK_CA_KBH                .  E_FT_DieselBuffer              .   E_FT_Diesel_Eff                    .   E_FT_DIESEL_FLOW
DK_CA_KBH                .  E_FT_Diesel_Eff                .   Road_fuels_sum                     .   E_FT_DIESEL_FLOW
DK_CA_KBH                .  E_FT_Diesel_Eff                .   Sea_fuels_sum                      .   E_FT_DIESEL_FLOW
DK_CA_KBH                .  E_FT_Diesel_Eff                .   E_FT_DieselBuffer_Exp              .   E_FT_DIESEL_FLOW_EXP

DK_CA_KBH                .  EME_GasolineBuffer	           .   EME_Gasoline_Eff                   .   EME_GASOLINE_FLOW
DK_CA_KBH                .  EME_Gasoline_Eff               .   Road_fuels_sum                     .   EME_GASOLINE_FLOW
DK_CA_KBH                .  EME_Gasoline_Eff               .   Sea_fuels_sum                      .   EME_GASOLINE_FLOW
DK_CA_KBH                .  EME_Gasoline_Eff               .   EME_GasolineBuffer_Exp	          .   EME_GASOLINE_FLOW_EXP

DK_CA_KBH                .  EME_LPGBuffer		   .   EME_LPG_Eff               	  .   EME_LPG_FLOW
DK_CA_KBH                .  EME_LPG_Eff               	   .   Road_fuels_sum                     .   EME_LPG_FLOW
DK_CA_KBH                .  EME_LPG_Eff               	   .   Sea_fuels_sum                      .   EME_LPG_FLOW
DK_CA_KBH                .  EME_LPG_Eff               	   .   EME_LPGBuffer_Exp		  .   EME_LPG_FLOW_EXP

DK_CA_KBH                .  EMethanolBuffer		   .   EMethanol_Eff               	  .   EMETHANOLFLOW
DK_CA_KBH                .  EMethanol_Eff                  .   Road_fuels_sum                     .   EMETHANOLFLOW
DK_CA_KBH                .  EMethanol_Eff                  .   Sea_fuels_sum                      .   EMETHANOLFLOW
DK_CA_KBH                .  EMethanol_Eff                  .   EMethanolBuffer_Exp		  .   EMETHANOLFLOW_EXP



DK_CA_KBH                .  Road_fuels_sum                   .   RoadBuffer                         .   ROADFLOW


*Find the electricity cost
DK_CA_KBH                .  ElecBuffer_GJ                    .   Electro                              .   ELECFLOW_GJ
*DK_CA_KBH                .  Money_buffer_T                   .   Electro                              .   OPERATIONCOST
DK_CA_KBH                .  Electro                          .   ElectroBuffer                        .   ELCOST_FLOW



*Other_gas Modelling gas production from other sources e.g swedeges slugde



DK_CA_KBH                .  Other_Gas_Gen                 .   Other_Gas_Proc                        .   OTHER_GAS_FLOW

DK_CA_KBH                .  Other_Gas_Proc                .   GasBuffer                             .   GASFLOW











/;


*FLOWFROMTOPROC(Y,AAA,IPROCFROM,IPROCTO,FLOW)$(FLOWFROMTOPROC_A(AAA,IPROCFROM,IPROCTO,FLOW))=FLOWFROMTOPROC_A(AAA,IPROCFROM,IPROCTO,FLOW);



FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC_A('DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC_A('DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC_A('DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC_A('DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);



FLOWFROMTOPROC(Y,'DK_CA_Aarhus',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Odense',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Aal',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_TVIS',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Esb',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_KBH',IPROCFROM,IPROCTO,FLOW);

FLOWFROMTOPROC(Y,'DK_CA_Hern',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_NrdOstSj',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Randers',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Holst',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Silk',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Hil',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Hjoerring',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Sndborg',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Viborg',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Horsens',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_CA_Kal',IPROCFROM,IPROCTO,FLOW);

FLOWFROMTOPROC(Y,'DK_MAM_Nyk',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MA_Grenaa',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Frdhavn',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Naestved',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Thisted',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Nyborg',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Svend',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Roenne',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Had',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_MAM_Slagelse',IPROCFROM,IPROCTO,FLOW);

FLOWFROMTOPROC(Y,'DK_MAM_Aars',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Hammel',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Skagen',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_Hobro',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_CA_Aab',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);
FLOWFROMTOPROC(Y,'DK_MAM_NrAlslev',IPROCFROM,IPROCTO,FLOW)=FLOWFROMTOPROC(Y,'DK_E_DTU',IPROCFROM,IPROCTO,FLOW);









FLOWFROMTOPROC(Y,AAA,'Wood_Gen','ProcEximTruck','WOOD_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Wood_Gen','ProcEximTruck','WOOD_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Straw_Gen','ProcEximTruck','STRAW_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Straw_Gen','ProcEximTruck','STRAW_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Muni_Waste_Gen','ProcEximTruck','MUNI_WASTE_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Muni_Waste_Gen','ProcEximTruck','MUNI_WASTE_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Wood_Pellets_Gen','ProcEximTruck','WOOD_PELLETS_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Wood_Pellets_Gen','ProcEximTruck','WOOD_PELLETS_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Manure_Gen','ProcEximTruck','MANURE_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Manure_Gen','ProcEximTruck','MANURE_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Deep_Litter_Gen','ProcEximTruck','DEEP_LITTER_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Deep_Litter_Gen','ProcEximTruck','DEEP_LITTER_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Food_Waste_Gen','ProcEximTruck','FOOD_WASTE_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Food_Waste_Gen','ProcEximTruck','FOOD_WASTE_GEN_FLOW');
FLOWFROMTOPROC(Y,AAA,'Nature_Area_Gen','ProcEximTruck','NATURE_AREA_GEN_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Nature_Area_Gen','ProcEximTruck','NATURE_AREA_GEN_FLOW');

*FLOWFROMTOPROC(Y,AAA,'Other_Gas_Gen','ProcEximTruck','OTHER_GAS_FLOW')$AAASOURCE(AAA)=FLOWFROMTOPROC(Y,'DK_CA_KBH','Other_Gas_Gen','ProcEximTruck','OTHER_GAS_FLOW');



