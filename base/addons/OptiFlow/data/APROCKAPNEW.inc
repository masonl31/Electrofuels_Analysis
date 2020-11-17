SET APROCKAPNEW(AAA,PROC)     'Areas for possible location of new Proc or capacity expansion of existing Proc'
*This is stablished according to economy of scale, where large plants can only be located when heat demand is high

/

DK_CA_KBH              .       TG_FT_Biodiesel_50_WO
DK_CA_KBH              .       TG_FT_Biodiesel_50_WP
DK_CA_KBH              .       TG_FT_Biodiesel_50_ST
DK_CA_KBH              .       TG_FT_Biodiesel_50_MW

DK_CA_KBH              .       ThermGasific_SNG_50_WO
DK_CA_KBH              .       ThermGasific_SNG_50_WP
DK_CA_KBH              .       ThermGasific_SNG_50_ST
DK_CA_KBH              .       ThermGasific_SNG_50_MW

DK_CA_KBH              .       TG_50_WO
DK_CA_KBH              .       TG_50_WP
DK_CA_KBH              .       TG_50_ST
DK_CA_KBH              .       TG_50_MW

DK_CA_KBH              .       Methanisation_Gasif_BSNG
DK_CA_KBH              .       Methane_synthesis_TG_50
DK_CA_KBH              .       Methanol_synthesis_TG_50

DK_CA_KBH              .       Ethanol_50


DK_CA_KBH              .       BioJet_50

DK_CA_KBH              .       Electrolysis_H2Prod

DK_CA_KBH              .       Hydrogen_STO_Large
*DK_CA_KBH              .       Hydrogen_STO_Small



DK_CA_Kal              .       ThermGasific_SNG_50_WO
DK_CA_Kal              .       ThermGasific_SNG_50_WP
DK_CA_Kal              .       ThermGasific_SNG_50_ST
DK_CA_Kal              .       ThermGasific_SNG_50_MW


DK_CA_Kal              .       TG_50_WO
DK_CA_Kal              .       TG_50_WP
DK_CA_Kal              .       TG_50_ST
DK_CA_Kal              .       TG_50_MW


DK_CA_Kal              .       ThermGasific_SYNGAS_50_WO
DK_CA_Kal              .       ThermGasific_SYNGAS_50_WP
DK_CA_Kal              .       ThermGasific_SYNGAS_50_ST
DK_CA_Kal              .       ThermGasific_SYNGAS_50_MW

DK_CA_Kal              .       BiogasProd_single
DK_CA_Kal              .       BiogasProd_mix

DK_CA_Kal              .       BiogasUpgr_BMETH_50

DK_CA_Kal              .       Electrolysis_H2Prod

DK_CA_Kal              .       Hydrogen_STO_Large
DK_CA_Kal              .       Hydrogen_STO_Small


DK_CA_Kal              .       Methanisation_Gasif_BSNG
DK_CA_Kal              .       Methane_synthesis_TG_50
*DK_CA_Kal              .       Methanol_synthesis_TG_50

DK_CA_Kal              .       Methanisation_Bio_BioGas




DK_CA_Kal              .       Ethanol_50



DK_MAM_Slagelse        .       ThermGasific_SYNGAS_50_WO
DK_MAM_Slagelse        .       ThermGasific_SYNGAS_50_WP
DK_MAM_Slagelse        .       ThermGasific_SYNGAS_50_ST
DK_MAM_Slagelse        .       ThermGasific_SYNGAS_50_MW

DK_MAM_Slagelse        .       BiogasProd_single
DK_MAM_Slagelse        .       BiogasProd_mix

DK_MAM_Slagelse        .       BiogasUpgr_BMETH_50

DK_MAM_Slagelse        .       Electrolysis_H2Prod

*DK_MAM_Slagelse         .       Hydrogen_STO_Large
DK_MAM_Slagelse        .       Hydrogen_STO_Small

DK_MAM_Slagelse        .       Methanisation_Bio_BioGas






DK_E_DTU               .       ThermGasific_SYNGAS_50_WO
DK_E_DTU               .       ThermGasific_SYNGAS_50_WP
DK_E_DTU               .       ThermGasific_SYNGAS_50_ST
DK_E_DTU               .       ThermGasific_SYNGAS_50_MW

DK_E_DTU               .       BiogasProd_single
DK_E_DTU               .       BiogasProd_mix

DK_E_DTU               .       BiogasUpgr_BMETH_50

DK_E_DTU               .       Electrolysis_H2Prod

*DK_E_DTU               .       Hydrogen_STO_Large
DK_E_DTU               .       Hydrogen_STO_Small

DK_E_DTU               .       Methanisation_Bio_BioGas


DK_CA_Kal              .       Engine_SYNGAS_50
DK_CA_Kal              .       Engine_BIOGAS_50


DK_MAM_Slagelse        .       Engine_SYNGAS_50
DK_MAM_Slagelse        .       Engine_BIOGAS_50


DK_E_DTU               .       Engine_SYNGAS_50
DK_E_DTU               .       Engine_BIOGAS_50

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

