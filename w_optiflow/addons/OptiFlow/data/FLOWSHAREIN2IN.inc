PARAMETER FLOWSHAREIN2IN(YYY,AAA,PROC,IFLOWIN,IFLOWIN2,ILOUPFXSET) "Relationship between two input flows (U1/U2) - units of flow 1 divided by units of flow 2"

/


2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   DEEP_LITTER_GEN_FLOW       . ILOUPFX_LO    0.8746
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   STRAW_GJ_BIOGAS            . ILOUPFX_LO    1.043674
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   FOOD_WASTE_GEN_FLOW        . ILOUPFX_LO    0.5335
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   NATURE_AREA_GEN_FLOW       . ILOUPFX_LO    1.6153


$ontext
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   DEEP_LITTER_GEN_FLOW       . ILOUPFX_LO    0.49586
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   STRAW_GJ_BIOGAS            . ILOUPFX_LO    0.59131
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   FOOD_WASTE_GEN_FLOW        . ILOUPFX_LO    0.401248
2014 .    DK_CA_KBH      .   BiogasProd_mix     .   MANURE_GEN_FLOW                           .   NATURE_AREA_GEN_FLOW       . ILOUPFX_LO    0.568963
$offtext


*2014 .    DK_CA_KBH      .   Methanisation_Bio_BioGas     .   BIOGAS_FLOW                    .   HYDROGEN_FLOW_BIO_BIOGAS       . ILOUPFX_FX    1.56
*2014 .    DK_CA_KBH      .   Methane_synthesis_TG_50      .   BIO_TG_FLOW                    .   HYDROGEN_FLOW_TG               . ILOUPFX_FX    0.78
*2014 .    DK_CA_KBH      .   Methanol_synthesis_TG_50     .   BIO_ME_FLOW                    .   HYDROGEN_FLOW_ME               . ILOUPFX_FX    2.2258
*2014 .    DK_CA_KBH      .   Methanol_synthesis_TG_50     .   BIO_ME_FLOW                   .   HYDROGEN_FLOW_ME               . ILOUPFX_FX    0.78


*2014 .    DK_CA_KBH      .   SumSTWB                      .  MANURE_GJ_BG_Mix                .   STRAW_GJ_BIOGAS                . ILOUPFX_FX    1.5499




/
;



FLOWSHAREIN2IN(Y,AAA,PROC,IFLOWIN,IFLOWIN2,ILOUPFXSET)$( FLOWSHAREIN2IN(Y,AAA,PROC,IFLOWIN,IFLOWIN2,ILOUPFXSET)EQ 0) =  FLOWSHAREIN2IN('2014','DK_CA_KBH',PROC,IFLOWIN,IFLOWIN2,ILOUPFXSET);
