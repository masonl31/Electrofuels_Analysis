SET  PROCKAPDATA(PROC,FLOW,IFLOWINOUT)    "Process data: capacity relative to FLOW and in/out direction ()"
/
CO2_PH                         .    ELECFLOW_GJ		 		 .   IFLOWINOUT_IN
CO2_Bio                        .    ELECFLOW_GJ			 	 .   IFLOWINOUT_IN
CO2_IND                        .    ELECFLOW_GJ			 	 .   IFLOWINOUT_IN


CO2_DAC                        .    CO2_FLOW_DAC			 .   IFLOWINOUT_OUT
CO2_Sto                        .    CO2_FLOW_STO                         .   IFLOWINOUT_IN
EMethanol_synthesis            .    EMETHANOLFLOW			 .   IFLOWINOUT_OUT
EMethanol_Upgrade              .    EME_DROPIN_FLOW			 .   IFLOWINOUT_OUT
E_FT			       .    E_FT_SUM_FLOW			 .   IFLOWINOUT_OUT
Ammonia_Synthesis	       .    AMMONIA_FLOW			 .   IFLOWINOUT_OUT
HTL_ST                         .    HTLFLOW_ST                           .   IFLOWINOUT_OUT
HTL_WO				.    HTLFLOW_WO                          .   IFLOWINOUT_OUT
HTL_WP                  	.    HTLFLOW_WP                          .   IFLOWINOUT_OUT


BioJet_50_ST                   .    STRAW_GJ_BJ                          .   IFLOWINOUT_IN
BioJet_50_WO                   .    WOOD_GJ_BJ                           .   IFLOWINOUT_IN
BioJet_50_WP                   .    WOOD_PELLETS_GJ_BJ                   .   IFLOWINOUT_IN

BioJet_50_ST_H2                .    STRAW_GJ_BJ_H2                       .   IFLOWINOUT_IN
BioJet_50_WO_H2                .    WOOD_GJ_BJ_H2                        .   IFLOWINOUT_IN
BioJet_50_WP_H2                .    WOOD_PELLETS_GJ_BJ_H2                .   IFLOWINOUT_IN


TG_FT_Biodiesel_50_WO          .    WOOD_GJ_FT                           .   IFLOWINOUT_IN
TG_FT_Biodiesel_50_WP          .    WOOD_PELLETS_GJ_FT                   .   IFLOWINOUT_IN
TG_FT_Biodiesel_50_ST          .    STRAW_GJ_FT                          .   IFLOWINOUT_IN

ThermGasific_SNG_50_WO         .    WOOD_GJ_SNG                          .   IFLOWINOUT_IN
ThermGasific_SNG_50_WP         .    WOOD_PELLETS_GJ_SNG                  .   IFLOWINOUT_IN
ThermGasific_SNG_50_ST         .    STRAW_GJ_SNG                         .   IFLOWINOUT_IN
ThermGasific_SNG_50_MW         .    MUNI_WASTE_GJ_SNG                    .   IFLOWINOUT_IN

ThermGasific_Syngas_50_WO      .    WOOD_GJ_SYNGAS                       .   IFLOWINOUT_IN
ThermGasific_Syngas_50_WP      .    WOOD_PELLETS_GJ_SYNGAS               .   IFLOWINOUT_IN
ThermGasific_Syngas_50_ST      .    STRAW_GJ_SYNGAS                      .   IFLOWINOUT_IN
ThermGasific_Syngas_50_MW      .    MUNI_WASTE_GJ_SYNGAS                 .   IFLOWINOUT_IN

TG_50_WO                       .    WOOD_GJ_TG                           .   IFLOWINOUT_IN
TG_50_WP                       .    WOOD_PELLETS_GJ_TG                   .   IFLOWINOUT_IN
TG_50_ST                       .    STRAW_GJ_TG                          .   IFLOWINOUT_IN
TG_50_MW                       .    MUNI_WASTE_GJ_TG                     .   IFLOWINOUT_IN

Ethanol_50                     .    STRAW_GJ_ET                          .   IFLOWINOUT_IN


*BiogasProd_single              .    MANURE_GJ_BG_Single                  .   IFLOWINOUT_IN
*BiogasProd_single              .    Biogas_MANURE_WB_1_FLOW              .   IFLOWINOUT_OUT
*BiogasProd_mix                 .    MIX_FUEL_GJ                          .   IFLOWINOUT_IN
*BiogasProd_mix                 .    BIOGAS_MIX_FLOW                      .   IFLOWINOUT_OUT





Straw_pre_BG                   .    STRAW_GJ_BIOGAS                      .   IFLOWINOUT_IN
Deep_Litter_pre_BG             .    DEEP_LITTER_GEN_FLOW                 .   IFLOWINOUT_IN
Food_Waste_pre_BG              .    FOOD_WASTE_GEN_FLOW                  .   IFLOWINOUT_IN
Nature_Area_pre_BG             .    NATURE_AREA_GEN_FLOW                 .   IFLOWINOUT_IN
Manure_tank                    .    MANURE_GEN_FLOW                      .   IFLOWINOUT_IN
*BiogasProd_mix                 .    MANURE_GEN_FLOW                     .   IFLOWINOUT_IN




Biogas_Grid_STO                .    BIOGAS_FLOW_STO                      .   IFLOWINOUT_IN

BiogasUpgr_BMETH_50            .    BIOGAS_FLOW                          .   IFLOWINOUT_IN


Electrolysis_H2Prod            .    ELECFLOW_GJ                          .   IFLOWINOUT_IN

Hydrogen_STO_Large             .    HYDROGEN_FLOW_ST_Large               .   IFLOWINOUT_IN
Hydrogen_STO_Small             .    HYDROGEN_FLOW_ST_Small               .   IFLOWINOUT_IN




Methanisation_Bio_BioGas       .    BIOGAS_FLOW                          .   IFLOWINOUT_IN
Methane_synthesis_TG_50        .    BIO_TG_FLOW                          .   IFLOWINOUT_IN
Methanol_synthesis_TG_50       .    BIO_ME_FLOW                          .   IFLOWINOUT_IN


*power&heat production using "raw" RE-gasses
Engine_Syngas_50               .    BIO_SYNGAS_FLOW                      .   IFLOWINOUT_IN
Engine_Biogas_50               .    BIOGAS_FLOW                          .   IFLOWINOUT_IN


/
;


