SET  PROCKAPDATA(PROC,FLOW,IFLOWINOUT)    "Process data: capacity relative to FLOW and in/out direction ()"
/




TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                           .   IFLOWINOUT_IN
TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT                   .   IFLOWINOUT_IN
TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                          .   IFLOWINOUT_IN
TG_FT_Biodiesel_50_MW          .    MUNI_WASTE_GJ_FT                     .   IFLOWINOUT_IN




ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                          .   IFLOWINOUT_IN
ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG                  .   IFLOWINOUT_IN
ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                         .   IFLOWINOUT_IN
ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG                    .   IFLOWINOUT_IN

ThermGasific_SYNGAS_50_WO      .    WOOD_GJ_SYNGAS                       .   IFLOWINOUT_IN
ThermGasific_SYNGAS_50_WP      .    WOOD_PELLETS_GJ_SYNGAS               .   IFLOWINOUT_IN
ThermGasific_SYNGAS_50_ST      .    STRAW_GJ_SYNGAS                      .   IFLOWINOUT_IN
ThermGasific_SYNGAS_50_MW      .    MUNI_WASTE_GJ_SYNGAS                 .   IFLOWINOUT_IN


TG_50_WO                       .    WOOD_GJ_SYNGAS                       .   IFLOWINOUT_IN
TG_50_WP                       .    WOOD_PELLETS_GJ_SYNGAS               .   IFLOWINOUT_IN
TG_50_ST                       .    STRAW_GJ_SYNGAS                      .   IFLOWINOUT_IN
TG_50_MW                       .    MUNI_WASTE_GJ_SYNGAS                 .   IFLOWINOUT_IN

Ethanol_50                     .    STRAW_GJ_ET                          .   IFLOWINOUT_IN



BiogasProd_single              .    MANURE_AND_WETBIO_GJ_BG_Single       .   IFLOWINOUT_IN

BiogasProd_mix                 .    MIX_FUEL_GJ                          .   IFLOWINOUT_IN



BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                          .   IFLOWINOUT_IN


Electrolysis_H2Prod            .    ELECFLOW                             .   IFLOWINOUT_IN

Hydrogen_STO_Large             .    HYDROGEN_FLOW_ST_Large               .   IFLOWINOUT_IN
Hydrogen_STO_Small             .    HYDROGEN_FLOW_ST_Small               .   IFLOWINOUT_IN



Methanisation_Gasif_BSNG       .    BIO_SNGCO2_FLOW                      .   IFLOWINOUT_IN
Methanisation_Bio_BioGas       .    BIOGAS_FLOW                          .   IFLOWINOUT_IN
Methane_synthesis_TG_50        .    BIO_TG_FLOW                          .   IFLOWINOUT_IN
Methanol_synthesis_TG_50       .    BIO_ME_FLOW                          .   IFLOWINOUT_IN


*power and heat production using "raw" RE-gasses
Engine_SYNGAS_50               .    BIO_SYNGAS_FLOW                      .   IFLOWINOUT_IN
Engine_BIOGAS_50               .    BIOGAS_FLOW                          .   IFLOWINOUT_IN


/
;


