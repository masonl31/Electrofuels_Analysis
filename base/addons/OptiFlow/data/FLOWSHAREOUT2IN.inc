* Use EPS for the value 0. Entering 0 or nothing will be interpreted as 'not relevant'.


TABLE FLOWSHAREOUT2IN(YYY,AAA,IPROCFROM,IPROCTO,FLOW/*,SSS,TTT*/,ILOUPFXSET) "Bounds on shares of split outflow to PROC ()"

                                                                                                             ILOUPFX_LO  ILOUPFX_UP  ILOUPFX_FX


$ontext

2014   .  DK_CA_KBH    .    IndustryW_StorageMAX      .  RDF_Storage_Ind       .  INDUSTRY_MW_STOR                           0.5
2014   .  DK_CA_KBH    .    IndustryW_StorageMAX      .  MSW_IncinerationType  .  INDUSTRY_MW_nonSTOR


$offtext

;





* For convenience assigning same data to all other relevant areas (then overwriting where needed).
* However, note that areas that are exclusively for transit with respect to transport should not be part of this:


FLOWSHAREOUT2IN(Y,IA,IPROCFROM,IPROCTO,FLOW,ILOUPFXSET)$(ICA('DENMARK',IA) AND (NOT AAATRANSIT(IA)) AND FLOWFROMTOPROC(Y,IA,IPROCFROM,IPROCTO,FLOW)) = FLOWSHAREOUT2IN('2014','DK_CA_KBH',IPROCFROM,IPROCTO,FLOW,ILOUPFXSET);


