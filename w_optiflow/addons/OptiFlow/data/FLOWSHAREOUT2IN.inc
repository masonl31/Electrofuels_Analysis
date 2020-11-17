* Use EPS for the value 0. Entering 0 or nothing will be interpreted as 'not relevant'.


TABLE FLOWSHAREOUT2IN(YYY,AAA,IPROCFROM,IPROCTO,FLOW/*,SSS,TTT*/,ILOUPFXSET) "Bounds on shares of split outflow to PROC ()"

                                                                                                                 ILOUPFX_LO  ILOUPFX_UP  ILOUPFX_FX
2014   .  DK_CA_KBH    .    Manure_tank               .  BiogasProd_mix        .  MANURE_GEN_FLOW                   0.8
*2014   .  DK_CA_KBH    .    Deep_Litter_pre_BG        .  BiogasProd_mix        .  DEEP_LITTER_GEN_FLOW                          0.66
*2014   .  DK_CA_KBH    .    STRAW_pre_BG              .  BiogasProd_mix        .  STRAW_GJ_BIOGAS                               0.81
*2014   .  DK_CA_KBH    .    FOOD_WASTE_pre_BG         .  BiogasProd_mix        .  FOOD_WASTE_GEN_FLOW                           0.7
*2014   .  DK_CA_KBH    .    NATURE_AREA_pre_BG        .  BiogasProd_mix        .  NATURE_AREA_GEN_FLOW                          0.7





$ontext

2014   .  DK_CA_KBH    .    IndustryW_StorageMAX      .  RDF_Storage_Ind       .  INDUSTRY_MW_STOR                                0.5
2014   .  DK_CA_KBH    .    IndustryW_StorageMAX      .  MSW_IncinerationType  .  INDUSTRY_MW_nonSTOR


$offtext

;





* For convenience assigning same data to all other relevant areas (then overwriting where needed).
* However, note that areas that are exclusively for transit with respect to transport should not be part of this:




FLOWSHAREOUT2IN(Y,AAA,IPROCFROM,IPROCTO,FLOW,ILOUPFXSET)$( FLOWSHAREOUT2IN(Y,AAA,IPROCFROM,IPROCTO,FLOW,ILOUPFXSET)EQ 0) = FLOWSHAREOUT2IN('2014','DK_CA_KBH',IPROCFROM,IPROCTO,FLOW,ILOUPFXSET);
*FLOWSHAREOUT2IN(Y,IA,IPROCFROM,IPROCTO,FLOW,ILOUPFXSET)$(ICA('DENMARK',IA) AND (NOT AAATRANSIT(IA)) AND FLOWFROMTOPROC(Y,IA,IPROCFROM,IPROCTO,FLOW)) = FLOWSHAREOUT2IN('2014','DK_CA_KBH',IPROCFROM,IPROCTO,FLOW,ILOUPFXSET);


