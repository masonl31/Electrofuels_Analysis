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

DK_CA_KBH         .   WOOD_MASS                        .   WOOD_GEN_FLOW                   .   WOOD_GEN_FLOW                   .  IONEONE      16.2
DK_CA_KBH         .   STRAW_MASS                       .   STRAW_GEN_FLOW                  .   STRAW_GEN_FLOW                  .  IONEONE      14.5
DK_CA_KBH         .   MUNI_WASTE_MASS                  .   MUNI_WASTE_GEN_FLOW             .   MUNI_WASTE_GEN_FLOW             .  IONEONE      14
DK_CA_KBH         .   WOOD_PELLETS_MASS                .   WOOD_PELLETS_GEN_FLOW           .   WOOD_PELLETS_GEN_FLOW           .  IONEONE      19.75
DK_CA_KBH         .   MANURE_AND_WETBIO_MASS           .   MANURE_AND_WETBIO_GEN_FLOW      .   MANURE_AND_WETBIO_GEN_FLOW      .  IONEONE      11.02




DK_CA_KBH          .    WOOD                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_FT                    .  IONEMANY      1
DK_CA_KBH          .    WOOD                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_SNG                   .  IONEMANY      1
DK_CA_KBH          .    WOOD                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_SYNGAS                .  IONEMANY      1
DK_CA_KBH          .    WOOD                           .    WOOD_GEN_FLOW                  .     WOOD_GJ_TG                    .  IONEMANY      1


DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_FT                    .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_SNG                   .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_SYNGAS                .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_TG                    .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_BIOGAS                .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_ET                    .  IONEMANY      1
DK_CA_KBH          .    STRAW                          .    STRAW_GEN_FLOW                 .     STRAW_GJ_BJ                    .  IONEMANY      1

DK_CA_KBH          .    WOOD_PELLETS                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_FT             .  IONEMANY      1
DK_CA_KBH          .    WOOD_PELLETS                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_SNG            .  IONEMANY      1
DK_CA_KBH          .    WOOD_PELLETS                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_SYNGAS         .  IONEMANY      1
DK_CA_KBH          .    WOOD_PELLETS                   .    WOOD_PELLETS_GEN_FLOW          .     WOOD_PELLETS_GJ_TG             .  IONEMANY      1

DK_CA_KBH          .    MUNI_WASTE                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_FT               .  IONEMANY      1
DK_CA_KBH          .    MUNI_WASTE                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_SNG              .  IONEMANY      1
DK_CA_KBH          .    MUNI_WASTE                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_SYNGAS           .  IONEMANY      1
DK_CA_KBH          .    MUNI_WASTE                     .    MUNI_WASTE_GEN_FLOW            .     MUNI_WASTE_GJ_TG               .  IONEMANY      1

DK_CA_KBH          .    MANURE_AND_WETBIO              .    MANURE_AND_WETBIO_GEN_FLOW     .     MANURE_AND_WETBIO_GJ_BG_Single .  IONEMANY      1
DK_CA_KBH          .    MANURE_AND_WETBIO              .    MANURE_AND_WETBIO_GEN_FLOW     .     MANURE_AND_WETBIO_GJ_BG_Mix    .  IONEMANY      1


DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_FT                     .     WOOD_GJ_FT                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_SNG                    .     WOOD_GJ_SNG                   .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_SYNGAS                 .     WOOD_GJ_SYNGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_GJ_TG                     .     WOOD_GJ_TG                    .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_FT                    .     STRAW_GJ_FT                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_SNG                   .     STRAW_GJ_SNG                   .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_SYNGAS                .     STRAW_GJ_SYNGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_TG                    .     STRAW_GJ_TG                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_BIOGAS                .     STRAW_GJ_BIOGAS                .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_ET                    .     STRAW_GJ_ET                    .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     STRAW_GJ_BJ                    .     STRAW_GJ_BJ                    .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_FT             .     WOOD_PELLETS_GJ_FT             .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_SNG            .     WOOD_PELLETS_GJ_SNG            .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_SYNGAS         .     WOOD_PELLETS_GJ_SYNGAS         .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     WOOD_PELLETS_GJ_TG             .     WOOD_PELLETS_GJ_TG             .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_FT               .     MUNI_WASTE_GJ_FT               .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_SNG              .     MUNI_WASTE_GJ_SNG              .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_SYNGAS           .     MUNI_WASTE_GJ_SYNGAS           .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MUNI_WASTE_GJ_TG               .     MUNI_WASTE_GJ_TG               .  IONEONE      1

DK_CA_KBH          . Linkstorage_Res      .     MANURE_AND_WETBIO_GJ_BG_Single .     MANURE_AND_WETBIO_GJ_BG_Single .  IONEONE      1
DK_CA_KBH          . Linkstorage_Res      .     MANURE_AND_WETBIO_GJ_BG_Mix    .     MANURE_AND_WETBIO_GJ_BG_Mix    .  IONEONE      1


*******************Biojet********************************

DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     BIOJETFLOW                   .  IONEONE       0.24
DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     BIOGASOLINEFLOW               .  IONEONE       0.24
DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     HEATFLOW                      .  IONEONE       0.21
DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     ELECFLOW                      .  IONEONE       0.03
*DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    BioJet_50                      .    STRAW_GJ_BJ                    .     OPERATIONCOST                 .  IONEONE       -10.47



*******************Ethanol********************************

DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     Ethanol_FLOW                  .  IONEONE       0.41
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     HEATFLOW                      .  IONEONE       0.25
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     ELECFLOW                      .  IONEONE       0.03
*DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    Ethanol_50                     .    STRAW_GJ_ET                    .     OPERATIONCOST                 .  IONEONE       -10.47






*******************FT_TG********************************
**
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     FT_TG_FLOW_WO                 .  IONEONE       0.70
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                     .     OPERATIONCOST                 .  IONEONE       -11.76



DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     FT_TG_FLOW_WP                 .  IONEONE       0.70
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT             .     OPERATIONCOST                 .  IONEONE       -14.03



DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     FT_TG_FLOW_ST                 .  IONEONE       0.70
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                    .     OPERATIONCOST                 .  IONEONE       -10.47





DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     FT_TG_FLOW_MW                 .  IONEONE       0.70
DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     OPERATIONCOST                 .  IONEONE       -0.770
*DK_CA_KBH          .    TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT               .     OPERATIONCOST                 .  IONEONE       2.49


DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_WO                  .     BIODIESELFLOW                 .  IMANYONE       1
DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_WP                  .     BIODIESELFLOW                 .  IMANYONE       1
DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_ST                  .     BIODIESELFLOW                 .  IMANYONE       1
DK_CA_KBH          .    Biodiesel_FT_SUM               .    FT_TG_FLOW_MW                  .     BIODIESELFLOW                 .  IMANYONE       1


*******************SNG********************************


**

DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     BIO_SNG_FLOW_WO               .  IONEONE       0.70
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                    .     OPERATIONCOST                 .  IONEONE       -11.76



DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     BIO_SNG_FLOW_WP               .  IONEONE       0.70
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG            .     OPERATIONCOST                 .  IONEONE       -14.03


DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     BIO_SNG_FLOW_ST               .  IONEONE       0.70
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                   .     OPERATIONCOST                 .  IONEONE       -10.47


DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     BIO_SNG_FLOW_MW               .  IONEONE       0.70
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     HEATFLOW                      .  IONEONE       0.20
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     OPERATIONCOST                 .  IONEONE       -0.770
*DK_CA_KBH          .    ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG              .     OPERATIONCOST                 .  IONEONE       2.49


DK_CA_KBH          .    BIO_SNG_SUM                    .    BIO_SNG_FLOW_WO                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    BIO_SNG_SUM                    .    BIO_SNG_FLOW_WP                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    BIO_SNG_SUM                    .    BIO_SNG_FLOW_ST                .     BIO_SNG_FLOW                  .  IMANYONE       1
DK_CA_KBH          .    BIO_SNG_SUM                    .    BIO_SNG_FLOW_MW                .     BIO_SNG_FLOW                  .  IMANYONE       1




DK_CA_KBH          .    BIO_SNG_OUT                   .    BIO_SNG_FLOW                    .     GASFLOW                       .  IONEMANY       1
DK_CA_KBH          .    BIO_SNG_OUT                   .    BIO_SNG_FLOW                    .     BIO_SNGCO2_FLOW               .  IONEMANY       1

*******************SYNGAS********************************

**

DK_CA_KBH          .    ThermGasific_SYNGAS_50_WO      .    WOOD_GJ_SYNGAS                 .     BIO_SYNGAS_FLOW_WO            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WO      .    WOOD_GJ_SYNGAS                 .     HEATFLOW                      .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WO      .    WOOD_GJ_SYNGAS                 .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WO      .    WOOD_GJ_SYNGAS                 .     OPERATIONCOST                 .  IONEONE       -11.707


DK_CA_KBH          .    ThermGasific_SYNGAS_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     BIO_SYNGAS_FLOW_WP            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     HEATFLOW                      .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SYNGAS_50_WP      .    WOOD_PELLETS_GJ_SYNGAS         .     OPERATIONCOST                 .  IONEONE       -13.977


DK_CA_KBH          .    ThermGasific_SYNGAS_50_ST      .    STRAW_GJ_SYNGAS                .     BIO_SYNGAS_FLOW_ST            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_SYNGAS_50_ST      .    STRAW_GJ_SYNGAS                .     HEATFLOW                      .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_SYNGAS_50_ST      .    STRAW_GJ_SYNGAS                .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SYNGAS_50_ST      .    STRAW_GJ_SYNGAS                .     OPERATIONCOST                 .  IONEONE       -10.417


DK_CA_KBH          .    ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     BIO_SYNGAS_FLOW_MW            .  IONEONE       0.85
DK_CA_KBH          .    ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     HEATFLOW                      .  IONEONE       0.05
DK_CA_KBH          .    ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     OPERATIONCOST                 .  IONEONE       -0.717
*DK_CA_KBH          .    ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS           .     OPERATIONCOST                 .  IONEONE       2.543


DK_CA_KBH          .    BIO_SYNGAS_GRID_IN             .    BIO_SYNGAS_FLOW_WO             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    BIO_SYNGAS_GRID_IN             .    BIO_SYNGAS_FLOW_WP             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    BIO_SYNGAS_GRID_IN             .    BIO_SYNGAS_FLOW_ST             .     BIO_SYNGAS_FLOW               .  IMANYONE      1
DK_CA_KBH          .    BIO_SYNGAS_GRID_IN             .    BIO_SYNGAS_FLOW_MW             .     BIO_SYNGAS_FLOW               .  IMANYONE      1


DK_CA_KBH          .    BIO_SYNGAS_GRID_OUT            .    BIO_SYNGAS_FLOW                .     BIO_SYNGAS_FLOW               .  IONEONE       1






*******************TG********************************

**

DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     BIO_TG_FLOW_WO                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     HEATFLOW                      .  IONEONE       0.15
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_WO                       .    WOOD_GJ_TG                     .     OPERATIONCOST                 .  IONEONE       -11.76


DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     BIO_TG_FLOW_WP                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     HEATFLOW                      .  IONEONE       0.15
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_WP                       .    WOOD_PELLETS_GJ_TG             .     OPERATIONCOST                 .  IONEONE       -14.03


DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     BIO_TG_FLOW_ST                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     HEATFLOW                      .  IONEONE       0.15
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_ST                       .    STRAW_GJ_TG                    .     OPERATIONCOST                 .  IONEONE       -10.47


DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     BIO_TG_FLOW_MW                .  IONEONE       0.75
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     HEATFLOW                      .  IONEONE       0.15
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     TARFLOW                       .  IONEONE       0.1
DK_CA_KBH          .    TG_50_MW                       .    MUNI_WASTE_GJ_TG               .     OPERATIONCOST                 .  IONEONE       -0.770
*DK_CA_KBH          .    TG_50_MW                      .    MUNI_WASTE_GJ_TG               .     OPERATIONCOST                 .  IONEONE        2.49


DK_CA_KBH          .    BIO_TG_GRID_IN                 .    BIO_TG_FLOW_WO                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    BIO_TG_GRID_IN                 .    BIO_TG_FLOW_WP                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    BIO_TG_GRID_IN                 .    BIO_TG_FLOW_ST                 .     BIO_TG_FLOW                   .  IMANYONE      1
DK_CA_KBH          .    BIO_TG_GRID_IN                 .    BIO_TG_FLOW_MW                 .     BIO_TG_FLOW                   .  IMANYONE      1


DK_CA_KBH          .    BIO_TG_GRID_OUT                .    BIO_TG_FLOW                    .     BIO_TG_FLOW                   .  IONEMANY       1
DK_CA_KBH          .    BIO_TG_GRID_OUT                .    BIO_TG_FLOW                    .     BIO_ME_FLOW                   .  IONEMANY      1



DK_CA_KBH                .   ProcEximTruck              .   WOOD_GEN_FLOW                   .   WOOD_GEN_FLOW                  .  IONEONE         1
DK_CA_KBH                .   ProcEximTruck              .   STRAW_GEN_FLOW                  .   STRAW_GEN_FLOW                 .  IONEONE         1
DK_CA_KBH                .   ProcEximTruck              .   MUNI_WASTE_GEN_FLOW             .   MUNI_WASTE_GEN_FLOW            .  IONEONE         1
DK_CA_KBH                .   ProcEximTruck              .   WOOD_PELLETS_GEN_FLOW           .   WOOD_PELLETS_GEN_FLOW          .  IONEONE         1
DK_CA_KBH                .   ProcEximTruck              .   MANURE_AND_WETBIO_GEN_FLOW      .   MANURE_AND_WETBIO_GEN_FLOW     .  IONEONE         1




*******************BIOGAS********************************


DK_CA_KBH          .    BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single  .     BIOGAS_MANURE_WB_1_FLOW      .  IONEONE       1

DK_CA_KBH          .    BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single  .     ELECFLOW                     .  IONEONE       -0.1
DK_CA_KBH          .    BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single  .     HEATFLOW                     .  IONEONE       -0.1



DK_CA_KBH          .    BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single .     Digestate_FLOW               .  IONEONE      0.00000017

DK_CA_KBH          .    BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single .     OPERATIONCOST                .  IONEONE       -8.017


DK_CA_KBH          .    BIOGAS_GRID_IN                 .    BIOGAS_MANURE_WB_1_FLOW        .     BIOGAS_FLOW                  .  IMANYONE      1



DK_CA_KBH          .    SumSTWB                        .    MANURE_AND_WETBIO_GJ_BG_Mix    .     MIX_FUEL_GJ                  .  IONEONE       1
DK_CA_KBH          .    SumSTWB                        .    STRAW_GJ_BIOGAS                .     MIX_FUEL_GJ                  .  IONEONE       1.5499
DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     BIOGAS_MIX_FLOW              .  IONEONE       1.375

DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                     .     ELECFLOW                     .  IONEONE       -0.05
DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                     .     HEATFLOW                     .  IONEONE       -0.05

DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     Digestate_FLOW               .  IONEONE       0.00000005
DK_CA_KBH          .    BiogasProd_mix                 .    MIX_FUEL_GJ                    .     OPERATIONCOST                .  IONEONE       -10.9

DK_CA_KBH          .    BIOGAS_GRID_IN                 .    BIOGAS_MIX_FLOW                 .     BIOGAS_FLOW                  .  IMANYONE      1




DK_CA_KBH          .    BIOGAS_GRID_OUT                .    BIOGAS_FLOW                    .     BIOGAS_FLOW                  .  IONEMANY      1

*Upgrading

DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     GASFLOW                      .  IONEONE       1
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     OPERATIONCOST                .  IONEONE       -0.001
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     ELECFLOW                     .  IONEONE       -0.053
DK_CA_KBH          .    BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                    .     HEATFLOW                     .  IONEONE       0.053

*******************HYDROGEN********************************
*Hydrogen part
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW                       .     HYDROGEN_FLOW                  .  IONEONE       0.8
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW                       .     HEATFLOW                       .  IONEONE       0.05
DK_CA_KBH          .    Electrolysis_H2Prod           .     ELECFLOW                       .     OPERATIONCOST                  .  IONEONE       -0.001

DK_CA_KBH          .    HYDROGEN_GRID_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_NoST             .  IONEMANY       1
DK_CA_KBH          .    HYDROGEN_GRID_OUT             .     HYDROGEN_FLOW_NoST             .     HYDROGEN_FLOW_OUT              .  IONEONE      1

*Hydrogen storage - Central (Large)
DK_CA_KBH          .    HYDROGEN_GRID_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_ST_Large         .  IONEMANY       1
DK_CA_KBH          .    Hydrogen_STO_Large            .     HYDROGEN_FLOW_ST_Large         .     HYDROGEN_FLOW_ST_Large         .  IONEONE       0.9
DK_CA_KBH          .    Hydrogen_STO_Large            .     HYDROGEN_FLOW_ST_Large         .     OPERATIONCOST                  .  IONEONE       -0.001
DK_CA_KBH          .    HYDROGEN_After_STO_Large      .     HYDROGEN_FLOW_ST_Large         .     HYDROGEN_FLOW_OUT              .  IONEONE      1

*Hydrogen storage - Decentral (Small)
DK_CA_KBH          .    HYDROGEN_GRID_IN              .     HYDROGEN_FLOW                  .     HYDROGEN_FLOW_ST_Small         .  IONEMANY       1
DK_CA_KBH          .    Hydrogen_STO_Small            .     HYDROGEN_FLOW_ST_Small         .     HYDROGEN_FLOW_ST_Small         .  IONEONE       0.9
DK_CA_KBH          .    Hydrogen_STO_Small            .     HYDROGEN_FLOW_ST_Small         .     OPERATIONCOST                  .  IONEONE       -0.001
DK_CA_KBH          .    HYDROGEN_After_STO_Small      .     HYDROGEN_FLOW_ST_Small         .     HYDROGEN_FLOW_OUT              .  IONEONE      1







DK_CA_KBH          .    HYDROGEN_Before_Use           .     HYDROGEN_FLOW_OUT               .     HYDROGEN_FLOW_USE              .  IMANYONE      1





DK_CA_KBH          .    HYDROGEN_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_GASIF_BSNG       .  IONEMANY      1
DK_CA_KBH          .    HYDROGEN_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_BIO_BIOGAS       .  IONEMANY      1
DK_CA_KBH          .    HYDROGEN_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_TG               .  IONEMANY      1
DK_CA_KBH          .    HYDROGEN_Use                  .     HYDROGEN_FLOW_USE              .     HYDROGEN_FLOW_ME               .  IONEMANY      1

*Methanation


DK_CA_KBH          .    Methanisation_Gasif_BSNG      .     HYDROGEN_FLOW_GASIF_BSNG       .     GASFLOW                        .  IONEONE       1.56
DK_CA_KBH          .    Methanisation_Gasif_BSNG      .     BIO_SNGCO2_FLOW                .     GASFLOW                        .  IONEONE       2
DK_CA_KBH          .    Methanisation_Gasif_BSNG      .     BIO_SNGCO2_FLOW                .     OPERATIONCOST                  .  IONEONE      -0.001



DK_CA_KBH          .    Methanisation_Bio_BioGas      .     HYDROGEN_FLOW_BIO_BIOGAS       .     GASFLOW                        .  IONEONE      2.34
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     GASFLOW                        .  IONEONE      1.5
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001



DK_CA_KBH          .    Methane_synthesis_TG_50       .     HYDROGEN_FLOW_TG               .     GASFLOW                        .  IONEONE       1.56
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     GASFLOW                        .  IONEONE       2
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001



DK_CA_KBH          .    Methanol_synthesis_TG_50      .     HYDROGEN_FLOW_ME               .     METHANOLFLOW                   .  IONEONE       4.45
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     METHANOLFLOW                   .  IONEONE       2
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     OPERATIONCOST                  .  IONEONE      -0.001


*If I wanna include excess heat from mathanisation processes
DK_CA_KBH          .    Methanisation_Gasif_BSNG      .     BIO_SNGCO2_FLOW                .     HEATFLOW                       .  IONEONE       0.17
DK_CA_KBH          .    Methanisation_Bio_BioGas      .     BIOGAS_FLOW                    .     HEATFLOW                       .  IONEONE      0.17
DK_CA_KBH          .    Methane_synthesis_TG_50       .     BIO_TG_FLOW                    .     HEATFLOW                       .  IONEONE       0.17
DK_CA_KBH          .    Methanol_synthesis_TG_50      .     BIO_ME_FLOW                    .     HEATFLOW                       .  IONEONE       0.17





***Power and heat generation to ElecBuffer and HeatBuffer

DK_CA_KBH          .    BioSyngasBuffer                .    BIO_SYNGAS_FLOW                .     BIO_SYNGAS_FLOW                .  IONEONE       1
DK_CA_KBH          .    Engine_SYNGAS_50               .    BIO_SYNGAS_FLOW                .     ELECFLOW                       .  IONEONE       0.42
DK_CA_KBH          .    Engine_SYNGAS_50               .    BIO_SYNGAS_FLOW                .     HEATFLOW                       .  IONEONE       0.50
DK_CA_KBH          .    Engine_SYNGAS_50               .    BIO_SYNGAS_FLOW                .     OPERATIONCOST                  .  IONEONE       -1.451



DK_CA_KBH          .    BiogasBuffer                   .    BIOGAS_FLOW                    .     BIOGAS_FLOW                    .  IONEONE       1
DK_CA_KBH          .    Engine_BIOGAS_50               .    BIOGAS_FLOW                    .     ELECFLOW                       .  IONEONE       0.45
DK_CA_KBH          .    Engine_BIOGAS_50               .    BIOGAS_FLOW                    .     HEATFLOW                       .  IONEONE       0.47
DK_CA_KBH          .    Engine_BIOGAS_50               .    BIOGAS_FLOW                    .     OPERATIONCOST                  .  IONEONE       -1.451







**RE-fuels

DK_CA_KBH          .    MethanolBuffer                 .    METHANOLFLOW                   .     METHANOLFLOW                   .  IONEMANY      1
DK_CA_KBH          .    BiodieselBuffer                .    BIODIESELFLOW                  .     BIODIESELFLOW                  .  IONEMANY      1
DK_CA_KBH          .    EthanolBuffer                  .    Ethanol_FLOW                   .     Ethanol_FLOW                   .  IONEMANY      1
DK_CA_KBH          .    BioGasolineBuffer              .    BIOGASOLINEFLOW                .     BIOGASOLINEFLOW                .  IONEMANY      1



DK_CA_KBH          .    Methanol_car_eff               .    METHANOLFLOW                   .     METHANOLFLOW                   .  IONEONE       1
DK_CA_KBH          .    Biodiesel_car_eff              .    BIODIESELFLOW                  .     BIODIESELFLOW                  .  IONEONE       1
DK_CA_KBH          .    Ethanol_car_eff                .    Ethanol_FLOW                   .     Ethanol_FLOW                   .  IONEONE       1
DK_CA_KBH          .    BioGasoline_car_eff            .    BIOGASOLINEFLOW                .     BIOGASOLINEFLOW                .  IONEONE       1

DK_CA_KBH          .    Passenger_RE_fuels_sum         .    METHANOLFLOW                   .     Passenger_RE_FUELS_FLOW        .  IMANYONE      1
DK_CA_KBH          .    Passenger_RE_fuels_sum         .    BIODIESELFLOW                  .     Passenger_RE_FUELS_FLOW        .  IMANYONE      1
DK_CA_KBH          .    Passenger_RE_fuels_sum         .    Ethanol_FLOW                   .     Passenger_RE_FUELS_FLOW        .  IMANYONE      1
DK_CA_KBH          .    Passenger_RE_fuels_sum         .    BIOGASOLINEFLOW                .     Passenger_RE_FUELS_FLOW        .  IMANYONE      1





DK_CA_KBH          .    Methanol_freight_eff           .    METHANOLFLOW                   .     METHANOLFLOW                   .  IONEONE       1
DK_CA_KBH          .    Biodiesel_freight_eff          .    BIODIESELFLOW                  .     BIODIESELFLOW                  .  IONEONE       1
DK_CA_KBH          .    Ethanol_freight_eff            .    Ethanol_FLOW                   .     Ethanol_FLOW                   .  IONEONE       1
DK_CA_KBH          .    BioGasoline_freight_eff        .    BIOGASOLINEFLOW                .     BIOGASOLINEFLOW                .  IONEONE       1



DK_CA_KBH          .    Freight_RE_fuels_sum           .    METHANOLFLOW                   .     Freight_RE_FUELS_FLOW          .  IMANYONE      1
DK_CA_KBH          .    Freight_RE_fuels_sum           .    BIODIESELFLOW                  .     Freight_RE_FUELS_FLOW          .  IMANYONE      1
DK_CA_KBH          .    Freight_RE_fuels_sum           .    Ethanol_FLOW                   .     Freight_RE_FUELS_FLOW          .  IMANYONE      1
DK_CA_KBH          .    Freight_RE_fuels_sum           .    BIOGASOLINEFLOW                .     Freight_RE_FUELS_FLOW          .  IMANYONE      1






/;



PROCINOUTFLOW(Y,AAA,PROC,IFLOWIN,IFLOWOUT,IPROCINOUTRELATION)=PROCINOUTFLOW_NotY('DK_CA_KBH',PROC,IFLOWIN,IFLOWOUT,IPROCINOUTRELATION);


*  Change in units for Electricity and Heat production flows from GJ to MWh:

PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'ELECFLOW',IPROCINOUTRELATION)/IOF3P6;
PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,IFLOWIN,'HEATFLOW',IPROCINOUTRELATION)/IOF3P6;
PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,'ELECFLOW',IFLOWOUT,IPROCINOUTRELATION)*IOF3P6;
PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION)$(PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION))=PROCINOUTFLOW(Y,IA,PROC,'HEATFLOW',IFLOWOUT,IPROCINOUTRELATION)*IOF3P6;



