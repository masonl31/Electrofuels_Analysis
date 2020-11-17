SET APROCKAPNEW(AAA,PROC)     'Areas for possible location of new Proc or capacity expansion of existing Proc'
*This is stablished according to economy of scale, where large plants can only be located when heat demand is high

/

DK_CA_KBH              .       EMethanol_synthesis
DK_CA_KBH              .       EMethanol_Upgrade
DK_CA_KBH              .       E_FT
DK_CA_KBH              .       Ammonia_Synthesis
DK_CA_KBH              .       CO2_PH
DK_CA_KBH              .       CO2_IND
DK_CA_KBH              .       CO2_DAC
DK_CA_KBH              .       CO2_Bio
DK_CA_KBH              .       CO2_STO
DK_CA_KBH              .       CO2_Bio_Pot
DK_CA_KBH              .       HTL_ST
DK_CA_KBH              .       HTL_WO
DK_CA_KBH              .       HTL_WP

*DK_CA_Kal              .       EMethanol_synthesis
*DK_CA_Kal              .       EMethanol_Upgrade
*DK_CA_Kal              .       E_FT
*DK_CA_Kal              .       Ammonia_Synthesis
DK_CA_Kal              .       CO2_PH
DK_CA_Kal              .       CO2_IND
DK_CA_Kal              .       CO2_DAC
DK_CA_Kal              .       CO2_STO
DK_CA_Kal              .       CO2_Bio
DK_CA_Kal              .       CO2_Bio_Pot

DK_E_DTU               .       CO2_Bio
DK_E_DTU               .       CO2_Bio_Pot

DK_MAM_Slagelse        .       CO2_Bio
DK_MAM_Slagelse        .       CO2_Bio_Pot


DK_CA_KBH              .       TG_FT_Biodiesel_50_WO
DK_CA_KBH              .       TG_FT_Biodiesel_50_WP
DK_CA_KBH              .       TG_FT_Biodiesel_50_ST
*DK_CA_KBH              .       TG_FT_Biodiesel_50_MW

DK_CA_KBH              .       ThermGasific_SNG_50_WO
DK_CA_KBH              .       ThermGasific_SNG_50_WP
DK_CA_KBH              .       ThermGasific_SNG_50_ST
*DK_CA_KBH              .       ThermGasific_SNG_50_MW

DK_CA_KBH              .       TG_50_WO
DK_CA_KBH              .       TG_50_WP
DK_CA_KBH              .       TG_50_ST
*DK_CA_KBH              .       TG_50_MW

DK_CA_KBH              .       Methane_synthesis_TG_50
DK_CA_KBH              .       Methanol_synthesis_TG_50

DK_CA_KBH              .       Ethanol_50


DK_CA_KBH              .       BioJet_50_ST
DK_CA_KBH              .       BioJet_50_WO
DK_CA_KBH              .       BioJet_50_WP

DK_CA_KBH              .       BioJet_50_ST_H2
DK_CA_KBH              .       BioJet_50_WO_H2
DK_CA_KBH              .       BioJet_50_WP_H2

DK_CA_KBH              .       Electrolysis_H2Prod

DK_CA_KBH              .       Hydrogen_STO_Large
*DK_CA_KBH              .       Hydrogen_STO_Small



DK_CA_Kal              .       ThermGasific_SNG_50_WO
DK_CA_Kal              .       ThermGasific_SNG_50_WP
DK_CA_Kal              .       ThermGasific_SNG_50_ST
*DK_CA_Kal              .       ThermGasific_SNG_50_MW


DK_CA_Kal              .       TG_50_WO
DK_CA_Kal              .       TG_50_WP
DK_CA_Kal              .       TG_50_ST
*DK_CA_Kal              .       TG_50_MW


DK_CA_Kal              .       ThermGasific_Syngas_50_WO
DK_CA_Kal              .       ThermGasific_Syngas_50_WP
DK_CA_Kal              .       ThermGasific_Syngas_50_ST
*DK_CA_Kal              .       ThermGasific_Syngas_50_MW

*DK_CA_Kal              .       BiogasProd_single
*DK_CA_Kal              .       BiogasProd_mix
DK_CA_Kal              .       Straw_pre_BG
DK_CA_Kal              .       Deep_Litter_pre_BG
DK_CA_Kal              .       Food_Waste_pre_BG
DK_CA_Kal              .       Nature_Area_pre_BG
DK_CA_Kal              .       Manure_tank
*DK_CA_Kal              .       BiogasProd_mix


****TEST***
$ontext
DK_CA_KBH              .       Straw_pre_BG
DK_CA_KBH              .       Deep_Litter_pre_BG
DK_CA_KBH              .       Food_Waste_pre_BG
DK_CA_KBH              .       Nature_Area_pre_BG
DK_CA_KBH              .       Manure_tank
DK_CA_KBH              .       Biogas_Grid_STO
$offtext
***********

DK_CA_Kal              .       Biogas_Grid_STO

DK_CA_KBH              .       BiogasUpgr_BMETH_50
DK_CA_Kal              .       BiogasUpgr_BMETH_50

DK_CA_Kal              .       Electrolysis_H2Prod

DK_CA_Kal              .       Hydrogen_STO_Large
DK_CA_Kal              .       Hydrogen_STO_Small



DK_CA_Kal              .       Methane_synthesis_TG_50


DK_CA_Kal              .       Methanisation_Bio_BioGas




DK_CA_Kal              .       Ethanol_50



DK_MAM_Slagelse        .       ThermGasific_Syngas_50_WO
DK_MAM_Slagelse        .       ThermGasific_Syngas_50_WP
DK_MAM_Slagelse        .       ThermGasific_Syngas_50_ST
*DK_MAM_Slagelse        .       ThermGasific_Syngas_50_MW

*DK_MAM_Slagelse        .       BiogasProd_single
*DK_MAM_Slagelse        .       BiogasProd_mix
DK_MAM_Slagelse        .       Straw_pre_BG
DK_MAM_Slagelse        .       Deep_Litter_pre_BG
DK_MAM_Slagelse        .       Food_Waste_pre_BG
DK_MAM_Slagelse        .       Nature_Area_pre_BG
DK_MAM_Slagelse        .       Manure_tank
*DK_MAM_Slagelse        .       BiogasProd_mix



DK_MAM_Slagelse        .       Biogas_Grid_STO

DK_MAM_Slagelse        .       BiogasUpgr_BMETH_50

DK_MAM_Slagelse        .       Electrolysis_H2Prod

*DK_MAM_Slagelse         .       Hydrogen_STO_Large
DK_MAM_Slagelse        .       Hydrogen_STO_Small

DK_MAM_Slagelse        .       Methanisation_Bio_BioGas






DK_E_DTU               .       ThermGasific_Syngas_50_WO
DK_E_DTU               .       ThermGasific_Syngas_50_WP
DK_E_DTU               .       ThermGasific_Syngas_50_ST
*DK_E_DTU               .       ThermGasific_Syngas_50_MW

*DK_E_DTU               .       BiogasProd_single
*DK_E_DTU               .       BiogasProd_mix
DK_E_DTU               .       Straw_pre_BG
DK_E_DTU               .       Deep_Litter_pre_BG
DK_E_DTU               .       Food_Waste_pre_BG
DK_E_DTU               .       Nature_Area_pre_BG
DK_E_DTU               .       Manure_tank
*DK_E_DTU               .       BiogasProd_mix







DK_E_DTU               .       Biogas_Grid_STO

DK_E_DTU               .       BiogasUpgr_BMETH_50

DK_E_DTU               .       Electrolysis_H2Prod

*DK_E_DTU               .       Hydrogen_STO_Large
DK_E_DTU               .       Hydrogen_STO_Small

DK_E_DTU               .       Methanisation_Bio_BioGas


DK_CA_Kal              .       Engine_Syngas_50
DK_CA_Kal              .       Engine_Biogas_50


DK_MAM_Slagelse        .       Engine_Syngas_50
DK_MAM_Slagelse        .       Engine_Biogas_50


DK_E_DTU               .       Engine_Syngas_50
DK_E_DTU               .       Engine_Biogas_50

/
;

APROCKAPNEW('DK_CA_KBH',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);
APROCKAPNEW('DK_CA_Aarhus',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);
APROCKAPNEW('DK_CA_Odense',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);
APROCKAPNEW('DK_CA_Aal',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);
APROCKAPNEW('DK_CA_TVIS',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);
APROCKAPNEW('DK_CA_Esb',PROC)=APROCKAPNEW('DK_CA_KBH',PROC);

APROCKAPNEW('DK_CA_Hern',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_NrdOstSj',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_CA_Randers',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Holst',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Silk',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Hil',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Hjoerring',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Sndborg',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Viborg',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);
APROCKAPNEW('DK_MA_Horsens',PROC)=APROCKAPNEW('DK_CA_Kal',PROC);

APROCKAPNEW('DK_MAM_Nyk',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MA_Grenaa',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Frdhavn',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Naestved',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Thisted',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Nyborg',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Svend',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_CA_Roenne',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);
APROCKAPNEW('DK_MAM_Had',PROC)=APROCKAPNEW('DK_MAM_Slagelse',PROC);

APROCKAPNEW('DK_MAM_Aars',PROC)=APROCKAPNEW('DK_E_DTU',PROC);
APROCKAPNEW('DK_MAM_Hammel',PROC)=APROCKAPNEW('DK_E_DTU',PROC);
APROCKAPNEW('DK_MAM_Skagen',PROC)=APROCKAPNEW('DK_E_DTU',PROC);
APROCKAPNEW('DK_MAM_Hobro',PROC)=APROCKAPNEW('DK_E_DTU',PROC);
APROCKAPNEW('DK_CA_Aab',PROC)=APROCKAPNEW('DK_E_DTU',PROC);
APROCKAPNEW('DK_MAM_NrAlslev',PROC)=APROCKAPNEW('DK_E_DTU',PROC);

