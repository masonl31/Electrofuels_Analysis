* Note: if a flow entered in a line here in FLOWFROMTOPROC does not have corresponding information in PROCINOUTFLOW
* then the variable VPROCESFLOW corresponding to that line will be unrestricted, which is an error.


SET FLOWFROMTOPROC_A(AAA,IPROCFROM,IPROCTO,FLOW)
/

DK_CA_KBH                .  WOOD_GEN                         .   ProcEximTruck                        .   WOOD_GEN_FLOW
DK_CA_KBH                .  STRAW_GEN                        .   ProcEximTruck                        .   STRAW_GEN_FLOW
DK_CA_KBH                .  MUNI_WASTE_GEN                   .   ProcEximTruck                        .   MUNI_WASTE_GEN_FLOW
DK_CA_KBH                .  WOOD_PELLETS_GEN                 .   ProcEximTruck                        .   WOOD_PELLETS_GEN_FLOW
DK_CA_KBH                .  MANURE_AND_WETBIO_GEN            .   ProcEximTruck                        .   MANURE_AND_WETBIO_GEN_FLOW

DK_CA_KBH                .   ProcEximTruck                   .   WOOD_MASS                            .   WOOD_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   STRAW_MASS                           .   STRAW_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   MUNI_WASTE_MASS                      .   MUNI_WASTE_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   WOOD_PELLETS_MASS                    .   WOOD_PELLETS_GEN_FLOW
DK_CA_KBH                .   ProcEximTruck                   .   MANURE_AND_WETBIO_MASS               .   MANURE_AND_WETBIO_GEN_FLOW


DK_CA_KBH                .   WOOD_MASS                       .   WOOD                                 .   WOOD_GEN_FLOW
DK_CA_KBH                .   STRAW_MASS                      .   STRAW                                .   STRAW_GEN_FLOW
DK_CA_KBH                .   MUNI_WASTE_MASS                 .   MUNI_WASTE                           .   MUNI_WASTE_GEN_FLOW
DK_CA_KBH                .   WOOD_PELLETS_MASS               .   WOOD_PELLETS                         .   WOOD_PELLETS_GEN_FLOW
DK_CA_KBH                .   MANURE_AND_WETBIO_MASS          .   MANURE_AND_WETBIO                    .   MANURE_AND_WETBIO_GEN_FLOW


*******************BioJET******************************

DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_BJ
DK_CA_KBH                .  Linkstorage_Res                  .   BioJet_50                            .   STRAW_GJ_BJ
DK_CA_KBH                .  Money_buffer_T                   .   BioJet_50                            .   OPERATIONCOST
DK_CA_KBH                .  BioJet_50                        .   BioJetBuffer                         .   BIOJETFLOW
DK_CA_KBH                .  BioJet_50                        .   BioGasolineBuffer                    .   BIOGASOLINEFLOW
DK_CA_KBH                .  BioJet_50                        .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  BioJet_50                        .   ElecBuffer                           .   ELECFLOW


*******************Ethanol******************************

DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_ET
DK_CA_KBH                .  Linkstorage_Res                  .   Ethanol_50                           .   STRAW_GJ_ET
DK_CA_KBH                .  Money_buffer_T                   .   Ethanol_50                           .   OPERATIONCOST
DK_CA_KBH                .  Ethanol_50                       .   EthanolBuffer                        .   Ethanol_FLOW
DK_CA_KBH                .  Ethanol_50                       .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  Ethanol_50                       .   ElecBuffer                           .   ELECFLOW

*******************FT_TG********************************

DK_CA_KBH                .  WOOD                             .   Linkstorage_Res                      .   WOOD_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_WO                .   WOOD_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_WO                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_WO
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_FT_Biodiesel_50_WO            .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  WOOD_PELLETS                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_WP                .   WOOD_PELLETS_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_WP                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_WP
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_FT_Biodiesel_50_WP            .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_ST                .   STRAW_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_ST                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_ST
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_FT_Biodiesel_50_ST            .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  MUNI_WASTE                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_FT
DK_CA_KBH                .  Linkstorage_Res                  .   TG_FT_Biodiesel_50_MW                .   MUNI_WASTE_GJ_FT
DK_CA_KBH                .  Money_buffer_T                   .   TG_FT_Biodiesel_50_MW                .   OPERATIONCOST
DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   Biodiesel_FT_SUM                     .   FT_TG_FLOW_MW
DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_FT_Biodiesel_50_MW            .   Tar                                  .   TARFLOW


DK_CA_KBH                .  Biodiesel_FT_SUM                 .   BiodieselBuffer                      .   BIODIESELFLOW

*******************SNG********************************
DK_CA_KBH                .  WOOD                             .   Linkstorage_Res                      .   WOOD_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_WO               .   WOOD_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_WO               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   BIO_SNG_SUM                          .   BIO_SNG_FLOW_WO
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SNG_50_WO           .   Tar                                  .   TARFLOW

**
DK_CA_KBH                .  WOOD_PELLETS                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_WP               .   WOOD_PELLETS_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_WP               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   BIO_SNG_SUM                          .   BIO_SNG_FLOW_WP
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SNG_50_WP           .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_ST               .   STRAW_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_ST               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   BIO_SNG_SUM                          .   BIO_SNG_FLOW_ST
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SNG_50_ST           .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  MUNI_WASTE                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_SNG
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SNG_50_MW               .   MUNI_WASTE_GJ_SNG
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SNG_50_MW               .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   BIO_SNG_SUM                          .   BIO_SNG_FLOW_MW
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SNG_50_MW           .   Tar                                  .   TARFLOW


DK_CA_KBH                .  BIO_SNG_SUM                      .   BIO_SNG_OUT                            .   BIO_SNG_FLOW

DK_CA_KBH                .  BIO_SNG_OUT                      .   GasBuffer                            .   GASFLOW




*******************SYNGAS********************************

DK_CA_KBH                .  WOOD                             .   Linkstorage_Res                      .   WOOD_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SYNGAS_50_WO            .   WOOD_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SYNGAS_50_WO            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WO        .   BIO_SYNGAS_GRID_IN                   .   BIO_SYNGAS_FLOW_WO
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WO        .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WO        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  WOOD_PELLETS                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SYNGAS_50_WP            .   WOOD_PELLETS_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SYNGAS_50_WP            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WP        .   BIO_SYNGAS_GRID_IN                   .   BIO_SYNGAS_FLOW_WP
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WP        .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SYNGAS_50_WP        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SYNGAS_50_ST            .   STRAW_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SYNGAS_50_ST            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SYNGAS_50_ST        .   BIO_SYNGAS_GRID_IN                   .   BIO_SYNGAS_FLOW_ST
DK_CA_KBH                .  ThermGasific_SYNGAS_50_ST        .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SYNGAS_50_ST        .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  MUNI_WASTE                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_SYNGAS
DK_CA_KBH                .  Linkstorage_Res                  .   ThermGasific_SYNGAS_50_MW            .   MUNI_WASTE_GJ_SYNGAS
DK_CA_KBH                .  Money_buffer_T                   .   ThermGasific_SYNGAS_50_MW            .   OPERATIONCOST
DK_CA_KBH                .  ThermGasific_SYNGAS_50_MW        .   BIO_SYNGAS_GRID_IN                   .   BIO_SYNGAS_FLOW_MW
DK_CA_KBH                .  ThermGasific_SYNGAS_50_MW        .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  ThermGasific_SYNGAS_50_MW        .   Tar                                  .   TARFLOW
DK_CA_KBH                .  BIO_SYNGAS_GRID_IN               .   BIO_SYNGAS_GRID_OUT                  .   BIO_SYNGAS_FLOW
DK_CA_KBH                .  BIO_SYNGAS_GRID_OUT              .   BioSyngasBuffer                      .   BIO_SYNGAS_FLOW



*******************TG********************************
DK_CA_KBH                .  WOOD                             .   Linkstorage_Res                      .   WOOD_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_WO                             .   WOOD_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_WO                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_WO                         .   BIO_TG_GRID_IN                       .   BIO_TG_FLOW_WO
DK_CA_KBH                .  TG_50_WO                         .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_50_WO                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  WOOD_PELLETS                     .   Linkstorage_Res                      .   WOOD_PELLETS_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_WP                             .   WOOD_PELLETS_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_WP                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_WP                         .   BIO_TG_GRID_IN                       .   BIO_TG_FLOW_WP
DK_CA_KBH                .  TG_50_WP                         .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_50_WP                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                      .   STRAW_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_ST                             .   STRAW_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_ST                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_ST                         .   BIO_TG_GRID_IN                       .   BIO_TG_FLOW_ST
DK_CA_KBH                .  TG_50_ST                         .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_50_ST                         .   Tar                                  .   TARFLOW
**
DK_CA_KBH                .  MUNI_WASTE                       .   Linkstorage_Res                      .   MUNI_WASTE_GJ_TG
DK_CA_KBH                .  Linkstorage_Res                  .   TG_50_MW                             .   MUNI_WASTE_GJ_TG
DK_CA_KBH                .  Money_buffer_T                   .   TG_50_MW                             .   OPERATIONCOST
DK_CA_KBH                .  TG_50_MW                         .   BIO_TG_GRID_IN                       .   BIO_TG_FLOW_MW
DK_CA_KBH                .  TG_50_MW                         .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  TG_50_MW                         .   Tar                                  .   TARFLOW

DK_CA_KBH                .  BIO_TG_GRID_IN                   .   BIO_TG_GRID_OUT                      .   BIO_TG_FLOW

*******************BIOGAS********************************
*BIOGAS from single input plant
DK_CA_KBH                .  MANURE_AND_WETBIO                .   BiogasProd_single                    .   MANURE_AND_WETBIO_GJ_BG_Single
DK_CA_KBH                .  Money_buffer_T                   .   BiogasProd_single                    .   OPERATIONCOST
DK_CA_KBH                .  BiogasProd_single                .   BIOGAS_GRID_IN                       .   BIOGAS_MANURE_WB_1_FLOW
DK_CA_KBH                .  BiogasProd_single                .   Digestate                            .   Digestate_FLOW


DK_CA_KBH                .  ElecBuffer                       .   BiogasProd_single                    .   ELECFLOW
DK_CA_KBH                .  HeatBuffer                       .   BiogasProd_single                    .   HEATFLOW



*BIOGAS from mix plant
DK_CA_KBH                .  MANURE_AND_WETBIO                .   Linkstorage_Res                       .   MANURE_AND_WETBIO_GJ_BG_Mix
DK_CA_KBH                .  Linkstorage_Res                  .   SumSTWB                               .   MANURE_AND_WETBIO_GJ_BG_Mix

DK_CA_KBH                .  STRAW                            .   Linkstorage_Res                       .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  Linkstorage_Res                  .   SumSTWB                               .   STRAW_GJ_BIOGAS
DK_CA_KBH                .  SumSTWB                          .   BiogasProd_mix                        .   MIX_FUEL_GJ
DK_CA_KBH                .  Money_buffer_T                   .   BiogasProd_mix                        .   OPERATIONCOST
DK_CA_KBH                .  BiogasProd_mix                   .   BIOGAS_GRID_IN                        .   BIOGAS_MIX_FLOW
DK_CA_KBH                .  BiogasProd_mix                   .   Digestate                             .   Digestate_FLOW

DK_CA_KBH                .  ElecBuffer                       .   BiogasProd_mix                        .   ELECFLOW
DK_CA_KBH                .  HeatBuffer                       .   BiogasProd_mix                        .   HEATFLOW


DK_CA_KBH                .  BIOGAS_GRID_IN                   .   BIOGAS_GRID_OUT                      .   BIOGAS_FLOW
DK_CA_KBH                .  BIOGAS_GRID_OUT                  .   BiogasBuffer                         .   BIOGAS_FLOW

*Upgrading
DK_CA_KBH                .  BIOGAS_GRID_OUT                  .   BiogasUpgr_BMETH_50                  .   BIOGAS_FLOW
DK_CA_KBH                .  BiogasUpgr_BMETH_50              .   GasBuffer                            .   GASFLOW
DK_CA_KBH                .  Money_buffer_T                   .   BiogasUpgr_BMETH_50                  .   OPERATIONCOST
DK_CA_KBH                .  ElecBuffer                       .   BiogasUpgr_BMETH_50                  .   ELECFLOW
DK_CA_KBH                .  BiogasUpgr_BMETH_50              .   HeatBuffer                           .   HEATFLOW

*******************HYDROGEN********************************
*Hydrogen part
DK_CA_KBH                .  ElecBuffer                       .   Electrolysis_H2Prod                  .   ELECFLOW
DK_CA_KBH                .  Money_buffer_T                   .   Electrolysis_H2Prod                  .   OPERATIONCOST
DK_CA_KBH                .  Electrolysis_H2Prod              .   Hydrogen_GRID_IN                     .   HYDROGEN_FLOW
DK_CA_KBH                .  Electrolysis_H2Prod              .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  Hydrogen_GRID_IN                 .   Hydrogen_GRID_OUT                    .   HYDROGEN_FLOW_NoST
DK_CA_KBH                .  Hydrogen_GRID_OUT                .   HYDROGEN_Before_Use                  .   HYDROGEN_FLOW_OUT


*Hydrogen storage - Central (Large)
DK_CA_KBH                .  Hydrogen_GRID_IN                 .   Hydrogen_STO_Large                   .   HYDROGEN_FLOW_ST_Large
DK_CA_KBH                .  Money_buffer_T                   .   Hydrogen_STO_Large                   .   OPERATIONCOST
DK_CA_KBH                .  Hydrogen_STO_Large               .   HYDROGEN_After_STO_Large             .   HYDROGEN_FLOW_ST_Large
DK_CA_KBH                .  Hydrogen_After_STO_Large         .   HYDROGEN_Before_Use                  .   HYDROGEN_FLOW_OUT

*Hydrogen storage - Decentral (Small)
DK_CA_KBH                .  Hydrogen_GRID_IN                 .   Hydrogen_STO_Small                   .   HYDROGEN_FLOW_ST_Small
DK_CA_KBH                .  Money_buffer_T                   .   Hydrogen_STO_Small                   .   OPERATIONCOST
DK_CA_KBH                .  Hydrogen_STO_Small               .   HYDROGEN_After_STO_Small             .   HYDROGEN_FLOW_ST_Small
DK_CA_KBH                .  Hydrogen_After_STO_Small         .   HYDROGEN_Before_Use                  .   HYDROGEN_FLOW_OUT








DK_CA_KBH                .  Hydrogen_Before_Use              .   HYDROGEN_Use                         .   HYDROGEN_FLOW_USE

DK_CA_KBH                .  HYDROGEN_Use                     .   Methanisation_Gasif_BSNG             .   HYDROGEN_FLOW_GASIF_BSNG
DK_CA_KBH                .  HYDROGEN_Use                     .   Methanisation_Bio_BioGas             .   HYDROGEN_FLOW_BIO_BIOGAS
DK_CA_KBH                .  HYDROGEN_Use                     .   Methane_synthesis_TG_50              .   HYDROGEN_FLOW_TG
DK_CA_KBH                .  HYDROGEN_Use                     .   Methanol_synthesis_TG_50             .   HYDROGEN_FLOW_ME





*Methanation
DK_CA_KBH                .  BIO_SNG_OUT                      .   Methanisation_Gasif_BSNG             .   BIO_SNGCO2_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methanisation_Gasif_BSNG             .   OPERATIONCOST
DK_CA_KBH                .  Methanisation_Gasif_BSNG         .   GasBuffer                            .   GASFLOW


DK_CA_KBH                .  BIOGAS_GRID_OUT                  .   Methanisation_Bio_BioGas             .   BIOGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methanisation_Bio_BioGas             .   OPERATIONCOST
DK_CA_KBH                .  Methanisation_Bio_BioGas         .   GasBuffer                            .   GASFLOW


DK_CA_KBH                .  BIO_TG_GRID_OUT                  .   Methane_synthesis_TG_50               .   BIO_TG_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methane_synthesis_TG_50               .   OPERATIONCOST
DK_CA_KBH                .  Methane_synthesis_TG_50          .   GasBuffer                             .   GASFLOW

DK_CA_KBH                .  BIO_TG_GRID_OUT                  .   Methanol_synthesis_TG_50              .   BIO_ME_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Methanol_synthesis_TG_50              .   OPERATIONCOST
DK_CA_KBH                .  Methanol_synthesis_TG_50         .   MethanolBuffer                        .   METHANOLFLOW



*If I wanna include excess heat from mathanisation processes
DK_CA_KBH                .  Methanisation_Gasif_BSNG         .   HeatBuffer                            .   HEATFLOW
DK_CA_KBH                .  Methanisation_Bio_BioGas         .   HeatBuffer                            .   HEATFLOW
DK_CA_KBH                .  Methane_synthesis_TG_50          .   HeatBuffer                            .   HEATFLOW
DK_CA_KBH                .  Methanol_synthesis_TG_50         .   HeatBuffer                            .   HEATFLOW






*****************************************


*CHP engine
*Using "raw" gasses
*Engine_SYNGAS_50
DK_CA_KBH                .  BioSyngasBuffer                  .   Engine_SYNGAS_50                     .   BIO_SYNGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Engine_SYNGAS_50                     .   OPERATIONCOST
DK_CA_KBH                .  Engine_SYNGAS_50                 .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  Engine_SYNGAS_50                 .   ElecBuffer                           .   ELECFLOW

*Engine_BIOGAS_50
DK_CA_KBH                .  BiogasBuffer                     .   Engine_BIOGAS_50                     .   BIOGAS_FLOW
DK_CA_KBH                .  Money_buffer_T                   .   Engine_BIOGAS_50                     .   OPERATIONCOST
DK_CA_KBH                .  Engine_BIOGAS_50                 .   HeatBuffer                           .   HEATFLOW
DK_CA_KBH                .  Engine_BIOGAS_50                 .   ElecBuffer                           .   ELECFLOW



*RE-fuels


DK_CA_KBH                .  MethanolBuffer                   .   Methanol_car_eff                     .   METHANOLFLOW
DK_CA_KBH                .  EthanolBuffer                    .   Ethanol_car_eff                      .   ETHANOL_FLOW
DK_CA_KBH                .  BiodieselBuffer                  .   Biodiesel_car_eff                    .   BIODIESELFLOW
DK_CA_KBH                .  BioGasolineBuffer                .   BioGasoline_car_eff                  .   BIOGASOLINEFLOW


DK_CA_KBH                .  Methanol_car_eff                 .   Passenger_RE_fuels_sum               .   METHANOLFLOW
DK_CA_KBH                .  Ethanol_car_eff                  .   Passenger_RE_fuels_sum               .   ETHANOL_FLOW
DK_CA_KBH                .  Biodiesel_car_eff                .   Passenger_RE_fuels_sum               .   BIODIESELFLOW
DK_CA_KBH                .  BioGasoline_car_eff              .   Passenger_RE_fuels_sum               .   BIOGASOLINEFLOW


DK_CA_KBH                .  Passenger_RE_fuels_sum           .   Passenger_RE_fuels_Buffer            .   Passenger_RE_FUELS_FLOW



DK_CA_KBH                .  MethanolBuffer                   .   Methanol_freight_eff                 .   METHANOLFLOW
DK_CA_KBH                .  EthanolBuffer                    .   Ethanol_freight_eff                  .   ETHANOL_FLOW
DK_CA_KBH                .  BiodieselBuffer                  .   Biodiesel_freight_eff                .   BIODIESELFLOW
DK_CA_KBH                .  BioGasolineBuffer                .   BioGasoline_freight_eff              .   BIOGASOLINEFLOW


DK_CA_KBH                .  Methanol_freight_eff             .   Freight_RE_fuels_sum                 .   METHANOLFLOW
DK_CA_KBH                .  Ethanol_freight_eff              .   Freight_RE_fuels_sum                 .   ETHANOL_FLOW
DK_CA_KBH                .  Biodiesel_freight_eff            .   Freight_RE_fuels_sum                 .   BIODIESELFLOW
DK_CA_KBH                .  BioGasoline_freight_eff          .   Freight_RE_fuels_sum                 .   BIOGASOLINEFLOW


DK_CA_KBH                .  Freight_RE_fuels_sum             .   Freight_RE_fuels_Buffer              .   Freight_RE_FUELS_FLOW








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
