* File Var2001.inc

* This file is part of the Balmorel model.

* User: LB

* File modified and saved:


* HANS 20150206: simplified in order to use full (S,T)=(SSS,TTT) (otherwise GAMS dies). CREATETIME set as no. Search "/*" and "Hans20150206".
* Idea: keep full (SSS,TTT) info, but avoid assignments, thus, to be used, assignments will have to be added in code.
* Results are in C:\$_HansC\Balmorel\Fjernvarmemodellen\base\model\results\1INPUT_YYYsmallST.gdx  and  C:\$_HansC\Balmorel\Fjernvarmemodellen\base\model\results\1INPUT_2001_reducedgeographyFullSSSTTT.gdx.
* Original file exists as: var2001 - original.inc.

*------------------------------------------------------------------------------

* PARAMETER WEIGHT_S reflects how much of the year each season represents
* expressed relatively between the seasons.
* Units: (none).

* One way of doing it is to state the number of days in each season
* (should sum up to 365). Another is to give percentages (summing up to 100).

Parameter WEIGHT_S(SSS)  'Weight of each season';
* Each season is 168 hours. These values are overwriten if using the automatic time aggregation option (by setting $Setglobal timeaggr yes in balopt.opt), or if using BB3.
WEIGHT_S(SSS)=168;

* PARAMETER WEIGHT_T reflects how much of the day year each time period
* represents expressed relatively between the time periods.
* Units: (none).

* Like above one way of doing it is to state the number of hours of a day that
* each period represents (sums up to 24).
* Alternatively it can be stated in percentage (summing up to 100).


PARAMETER WEIGHT_T(TTT)  'Weight of each time period';

WEIGHT_T(TTT) = 1;

* PARAMETER GKDERATE contains a possibility to represent planned outages.
* It works through the parameter GKDERATE.
* It permits to take out units in one or more season (whole seasons only).
* If unit 'G' in area 'A' is planned out in season 'S' then let GKDERATE('G','A','S')=0.
* If unit 'G' in area 'A' is not planned out in season 'S' then let GKDERATE('G','A','S')
* attain 1 minus the stochastic FOR value (typically this will be 0.9 or 0.95).

/*
TABLE GKDERATE_S(AAA,GGG,SSS)  'Reduction in capacity'
                                                S01       S02       S03       S04       S05       S06       S07       S08       S09       S10       S11       S12
*DK_E_Rural.DK_E_Rural_ST-E8-ORs                 0.99      0.94      0.91      0.73      0.46      0.42      0.29      0.7       0.85      0.96      0.98      0.98
*Surplus heat capacities derated to enable constant production the whole year, while keeping the right annual production according to Energiproducenttællingen
DK_CA_Esb.DK_CA_Esb_SurpHeat_FF                 0         0         0         0         0         0         0         0         0         0         0         0
DK_CA_TVIS.DK_CA_TVIS_SurpHeat_FF               0.56      0.56      0.56      0.56      0.56      0.56      0.56      0.56      0.56      0.56      0.56      0.56
DK_CA_Aal.DK_CA_Aal_SurpHeat_FF                 0.37      0.37      0.37      0.37      0.37      0.37      0.37      0.37      0.37      0.37      0.37      0.37
DK_MAM_Hobro.DK_MAM_Hobro_SurpHeat_FF           0         0         0         0         0         0         0         0         0         0         0         0
DK_MAM_Nyborg.DK_MAM_Nyborg_SurpHeat_FF         0.71      0.71      0.71      0.71      0.71      0.71      0.71      0.71      0.71      0.71      0.71      0.71
DK_MAM_Skagen.DK_MAM_Skagen_SurpHeat_FF         0.10      0.10      0.10      0.10      0.10      0.10      0.10      0.10      0.10      0.10      0.10      0.10
DK_SA_E_WO_HO.DK_SA_SurpHeat_FF                 0         0         0         0         0         0         0         0         0         0         0         0
DK_SA_W_EB.DK_SA_SurpHeat_FF                    0         0         0         0         0         0         0         0         0         0         0         0
DK_SA_W_NG_CHP.DK_SA_SurpHeat_FF                0.12      0.12      0.12      0.12      0.12      0.12      0.12      0.12      0.12      0.12      0.12      0.12
DK_SA_W_NG_HO.DK_SA_SurpHeat_FF                 0.32      0.32      0.32      0.32      0.32      0.32      0.32      0.32      0.32      0.32      0.32      0.32
DK_SA_W_WO_HO.DK_SA_SurpHeat_FF                 0.09      0.09      0.09      0.09      0.09      0.09      0.09      0.09      0.09      0.09      0.09      0.09
;

* Seson values are copied to all time steps
GKDERATE(IA,G,SSS,TTT)$GKDERATE_S(IA,G,'S01')=GKDERATE_S(IA,G,'S01');
* Unless other values are assigned in the TABLE above,
* a default value 0.90 is used and assigned below:

GKDERATE(IA,G,SSS,TTT)$(not GKDERATE(IA,G,SSS,TTT) and (not IGWND(G)) and (AGKN(IA,G) or IAGK(IA,G)))= 0.90        ;

$include '../../%COREDATAFOLDER%/data/gkderateweek.inc';

* hans__ overwrite! :
* PEME 02082004 HER SÆTTES GKDERATE LIG MED GKDERATEW
  LOOP(IR,
     LOOP((IA,IGE)$(RRRAAA(IR,IA) and (AGKN(IA,IGE) or IAGK(IA,IGE))),
          GKDERATE(IA,IGE,SSS,TTT)$(not GKDERATE_S(IA,IGE,SSS) and GKDERATEW(SSS,IR) and (not IGWND(IGE)) and (AGKN(IA,IGE) or IAGK(IA,IGE)))= GKDERATEW(SSS,IR);
     );
  );

GKDERATE(AIND(IA),G,SSS,TTT)$(IAGK(AIND,G) or AGKN(AIND,G))=1;

* Lars: Scaling of GKDERATE of Nuclear power to ensure correct nuclear production:
GKDERATE('FI_R_Rural',IGNUC,SSS,TTT)$IAGK('FI_R_Rural',IGNUC)=GKDERATE('FI_R_Rural','FI_R_Rural_NU-C8-NU',SSS,TTT) * 8230/6767 ;
GKDERATE('SE_M_Rural',IGNUC,SSS,TTT)$IAGK('SE_M_Rural',IGNUC)=GKDERATE('SE_M_Rural','SE_M_Rural_NU-C8-NU',SSS,TTT) * 7249/6755 ;
GKDERATE('SE_S_Rural',IGNUC,SSS,TTT)$IAGK('SE_S_Rural',IGNUC)=GKDERATE('SE_S_Rural','SE_S_Rural_NU-C8-NU',SSS,TTT) * 7249/6755 ;

* LPB: Scaling of GKDERATE of Nuclear power for Russia based on data from Alex from 2006/2008
* LB: Removed to attain balance.
*GKDERATE(AAA,'KOL_NUC_PP_COND-NU',SSS,TTT)$(RRRAAA('RU_KOL',AAA)) =GKDERATE(AAA,'KOL_NUC_PP_COND-NU',SSS,TTT)$(RRRAAA('RU_KOL',AAA))*0.68;
*GKDERATE(AAA,'LEN_NUC_PP-NU',SSS,TTT)$(RRRAAA('RU_STP',AAA)) =GKDERATE(AAA,'LEN_NUC_PP-NU',SSS,TTT)$(RRRAAA('RU_STP',AAA))*0.65;

*/


* PARAMETER DE_VAR_T contains the description of seasonal and daily variation
* of the electricity demand
* Units: (see below).


* The values in the tables DE_VAR_T, DH_VAR_T, WND_VAR_T, SOLE_VAR_T, SOLH_VAR_T, WAVE_VAR_T, X3FX_VAR_T
* may be specified relatively
* (i.e. the values for each day do not have to sum up to something specific,
* only the relative values are important).
* One way to do this is by specifying each season/time period value
* as a percentage of the yearly maximum power load.
* Another option is to specify the MW-loads for each combinations.

PARAMETER DE_VAR_T(RRR,SSS,TTT) /
* Using profiles from 2001
$include '../../%COREDATAFOLDER%/data/var2001/DK-FB-F-SJ-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/DK-FB-F-JY-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/FI-FB-F-FI-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/NO-FB-F-NO-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/SE-FB-F-SE_S-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/SE-FB-F-SE_M-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/SE-FB-F-SE_N-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/DE_CS-FB-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/EE_R_07.inc';
$include '../../%COREDATAFOLDER%/data/var2001/LV_R_07.inc';
$include '../../%COREDATAFOLDER%/data/var2001/LT_R_07.inc';
$include '../../%COREDATAFOLDER%/data/var2001/DK_E_Industry_DE.inc';

$include '../../%COREDATAFOLDER%/data/var2001/EV_PROFILE_FjvAn.inc';
/;

/*
* Electricity consumption in Norway uses the same profile for all regions
DE_VAR_T('NO_N',SSS,TTT)=DE_VAR_T('NO_S',SSS,TTT);
DE_VAR_T('NO_M',SSS,TTT)=DE_VAR_T('NO_S',SSS,TTT);
DE_VAR_T('NO_O',SSS,TTT)=DE_VAR_T('NO_S',SSS,TTT);

DE_VAR_T('DE_NW',SSS,TTT) =    DE_VAR_T('DE_CS',SSS,TTT)  ;
DE_VAR_T('DE_NE',SSS,TTT) =    DE_VAR_T('DE_CS',SSS,TTT)  ;

* Electricity demand variation, Poland
DE_VAR_T('PL_NW',SSS,TTT) =    DE_VAR_T('FI_R',SSS,TTT)  ;
DE_VAR_T('PL_W',SSS,TTT) =    DE_VAR_T('FI_R',SSS,TTT)  ;
DE_VAR_T('PL_S',SSS,TTT) =    DE_VAR_T('FI_R',SSS,TTT)  ;
DE_VAR_T('PL_Central',SSS,TTT) =    DE_VAR_T('FI_R',SSS,TTT)  ;
DE_VAR_T('PL_SE',SSS,TTT) =    DE_VAR_T('FI_R',SSS,TTT)  ;

* Electricity demand variation, Russia
DE_VAR_T('RU_KAR',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_KOL',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_PSK',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_KAL',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_ARK',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_STP',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_NOV',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;
DE_VAR_T('RU_KOM',SSS,TTT) =    DE_VAR_T('EE_R',SSS,TTT)  ;

DE_VAR_T('BLR_BLR',SSS,TTT)  = DE_VAR_T('DK_E',SSS,TTT) ;

DE_VAR_T('DK_E_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('DK_W_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('FI_R_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('SE_N_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('SE_M_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('SE_S_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('NO_S_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('NO_O_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('NO_N_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('NO_M_Industry',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('DE_CS_Industry',SSS,TTT)  = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('DE_NE_Industry',SSS,TTT)  = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DE_VAR_T('DE_NW_Industry',SSS,TTT)  = DE_VAR_T('DK_E_Industry',SSS,TTT) ;

*$include '../../%COREDATAFOLDER%/data/DE_PROFIL_STROEM2025.inc'
*DE_VAR_T(RRR,SSS,TTT)$DE_PROFIL_STROEM2025(SSS,TTT,RRR) = DE_PROFIL_STROEM2025(SSS,TTT,RRR);

* AL BASREC EV profiles same for all regions

DE_VAR_T('DK_W_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('SE_N_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('SE_M_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('SE_S_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('NO_S_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('NO_O_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('NO_N_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('NO_M_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('DE_CS_EV     ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('DE_NE_EV     ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('DE_NW_EV     ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('FI_R_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('LT_R_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('EE_R_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('LV_R_EV      ',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;
DE_VAR_T('PL_Central_EV',SSS,TTT)   = DE_VAR_T('DK_E_EV',SSS,TTT) ;

*/

* PARAMETER DH_VAR_T contains the description of seasonal and daily variation
* of the heat demand.
* Units: (see description above under DE_VAR_T).

* ------------------------------------------------------------------------------

PARAMETER   DH_VAR_T(AAA,SSS,TTT) /
* Using profiles from 2001
$if EXIST 'SouthAfrica_WG_wnd.inc' $include 'SouthAfrica_WG_wnd.inc';
$include '../../%COREDATAFOLDER%/data/var2001/Elkraft-KV-Decentral-DK_CA_Kal.inc'
$include '../../%COREDATAFOLDER%/data/var2001/Eltra-KV-Decentral-DK_CA_Aab.inc'
$include '../../%COREDATAFOLDER%/data/var2001/Eltra-KV-Central-DK_CA_Aarhus.inc'
$include '../../%COREDATAFOLDER%/data/var2001/FI-HC-01.inc'
$include '../../%COREDATAFOLDER%/data/var2001/svenskvarme01.inc'
* New heat profiles for Estonia on 240908 and 200210
$include '../../%COREDATAFOLDER%/data/var2001/Baltic-heat.inc'
$include '../../%COREDATAFOLDER%/data/var2001/EE_R_narva_DH_VAR_T.inc'
$include '../../%COREDATAFOLDER%/data/var2001/EE_R_Tartu_DH_VAR_T.inc'
$include '../../%COREDATAFOLDER%/data/var2001/EE_R_Ahtme_DH_VAR_T.inc'
$include '../../%COREDATAFOLDER%/data/var2001/EE_R_Industry_S_DH_VAR_T.inc'
* Process heat profile for business areas
*$include '../../%COREDATAFOLDER%/data/var2001/DK_E_Industry_DH.inc'

* -------------------- Greater Copenhagen -------------------------------------*
$include '../../%COREDATAFOLDER%/data/var2001/Elkraft-KV-Central-DK_CA_Kbh.inc'
* -----------------------------------------------------------------------------*
/;

/*
* Urban areas in Western Denmark use the DK_CA_Aarhus profile.
DH_VAR_T('DK_CA_Aal',SSS,TTT)=DH_VAR_T('DK_CA_Aarhus',SSS,TTT);
DH_VAR_T('DK_CA_TVIS',SSS,TTT)=DH_VAR_T('DK_CA_Aarhus',SSS,TTT);
DH_VAR_T('DK_CA_Odense',SSS,TTT)=DH_VAR_T('DK_CA_Aarhus',SSS,TTT);

* Decentralised and individual areas in Western Denmark use the DK_W_Rural profile.
DH_VAR_T(AAA,SSS,TTT)$(DH_VAR_T(AAA,SSS,TTT)=0 and RRRAAA('DK_W',AAA)) = DH_VAR_T('DK_CA_Aab',SSS,TTT);

* Decentralised and individual areas in Eastern Denmark use the DK_CA_Kal profile.
DH_VAR_T(AAA,SSS,TTT)$(DH_VAR_T(AAA,SSS,TTT)=0 and RRRAAA('DK_E',AAA)) = DH_VAR_T('DK_CA_Kal',SSS,TTT);

* Industrial heat consumption assumed to have the same profile as industrial electricity consumption
DH_VAR_T('DK_E_Industry_A',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;
DH_VAR_T('DK_W_Industry_A',SSS,TTT)   = DE_VAR_T('DK_E_Industry',SSS,TTT) ;

* Finnish heat profile copied to all Finnish areas.
DH_VAR_T(IA,SSS,TTT)$(ICA('Finland',IA) and not sameas(IA,'FI_R_Rural')) = DH_VAR_T('FI_R_Rural',SSS,TTT);

* Swedish heat profile copied to areas without profiles.
DH_VAR_T('SE_N_Bio',SSS,TTT)= DH_VAR_T('SE_N_Rural',SSS,TTT);
DH_VAR_T('SE_M_Bio',SSS,TTT)= DH_VAR_T('SE_M_Rural',SSS,TTT);
DH_VAR_T('SE_S_Bio',SSS,TTT)= DH_VAR_T('SE_S_Rural',SSS,TTT);

*DH_VAR_T('SE_N_Offshore',SSS,TTT)= DH_VAR_T('SE_N_Rural',SSS,TTT);
*DH_VAR_T('SE_M_Offshore',SSS,TTT)= DH_VAR_T('SE_M_Rural',SSS,TTT);
*DH_VAR_T('SE_S_Offshore',SSS,TTT)= DH_VAR_T('SE_S_Rural',SSS,TTT);

* The areas in Norway without their own heat demand profiles get the profile of DK_E_Rural.
DH_VAR_T(IA,SSS,TTT)$ICA('Norway',IA)=DH_VAR_T('DK_CA_Kal',SSS,TTT);

* German heat profiles copied from Eastdanish profile.
DH_VAR_T(IA,SSS,TTT)$ICA('Germany',IA)=DH_VAR_T('DK_CA_Kal',SSS,TTT);

* TEP
DH_VAR_T('LV_R_RigaR'   ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LV_R_BigC'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LV_R_SmlC'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LV_R_Pulp'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_VilU'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_KauU'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_KlaU'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_MazU'    ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_CHPLU'   ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_CHPSR'   ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('EE_R_Rural'   ,SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('EE_R_Tallinn' ,SSS,TTT) = DH_VAR_T('EE_R_Narva',SSS,TTT);
DH_VAR_T('EE_R_Parnu'   ,SSS,TTT) = DH_VAR_T('EE_R_Tartu',SSS,TTT);
*DH_VAR_T('EE_R_Offshore',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
*DH_VAR_T('LV_R_Offshore',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
*DH_VAR_T('LT_R_Offshore',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('LT_R_Panevezys',SSS,TTT)= DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('EE_R_Narva_ShaleLim',SSS,TTT)= DH_VAR_T('EE_R_Narva',SSS,TTT);

* POLAND
DH_VAR_T('PL_POMO_Gdan',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_POMO_Slup',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_ZACH_Szcz',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_ZACH_Kosz',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LUBU_Gorz',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LUBU_Ziel',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_WIEL_Pozn',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_WIEL_Koni',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_WIEL_Kali',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_WIEL_Lesz',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_WARM_all',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_PODL_all',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MAZO_Wars',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MAZO_Ostr',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MAZO_Rado',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MAZO_Ciec',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_KUJA_Bydg',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_KUJA_Grud',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_DOLN_Wroc',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_DOLN_Legn',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_DOLN_Jele',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_DOLN_Walb',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LODZ_Lodz',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LODZ_Sier',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LODZ_Piot',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LODZ_Skie',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LUBE_Lubl',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_LUBE_Pula',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SWIE_Kiel',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SWIE_Sand',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_OPOL_Opol',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_OPOL_Nysa',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Kato',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Rybn',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Biel',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Tych',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Byto',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Gliw',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_SLAS_Sosn',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MALO_Krak',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MALO_Oswi',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_MALO_NwyS',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_PODK_Rzes',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('PL_PODK_Prze',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('Auto1_U',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('Auto2_U',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('Auto3_U',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('Auto4_U',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('Auto5_U',SSS,TTT)=DH_VAR_T('EE_R_Urban',SSS,TTT);

*RUSSIA
DH_VAR_T('RU_KAR_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_3',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_4',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_5',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOL_6',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_PSK_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_PSK_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KAL_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_ARK_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_ARK_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_ARK_3',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_ARK_4',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_STP_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_STP_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_STP_3',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_NOV_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_NOV_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_1',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_2',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_3',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_4',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_5',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);
DH_VAR_T('RU_KOM_6',SSS,TTT) = DH_VAR_T('EE_R_Urban',SSS,TTT);


* Electric heating areas
DE_VAR_T('DK_E_EHP',SSS,TTT)   =  DH_VAR_T('DK_CA_Kbh',SSS,TTT);
DE_VAR_T('DK_W_EHP',SSS,TTT)   =  DH_VAR_T('DK_CA_Aarhus',SSS,TTT);
DE_VAR_T('FI_R_EHP',SSS,TTT)   =  DH_VAR_T('FI_R_Urban',SSS,TTT);
DE_VAR_T('SE_N_EHP',SSS,TTT)   =  DH_VAR_T('SE_N_Rural',SSS,TTT);
DE_VAR_T('SE_M_EHP',SSS,TTT)   =  DH_VAR_T('SE_M_Urban',SSS,TTT);
DE_VAR_T('SE_S_EHP',SSS,TTT)   =  DH_VAR_T('SE_S_Rural',SSS,TTT);
DE_VAR_T('NO_S_EHP',SSS,TTT)   =  DH_VAR_T('NO_S_Rural',SSS,TTT);
DE_VAR_T('NO_O_EHP',SSS,TTT)   =  DH_VAR_T('NO_O_Rural',SSS,TTT);
DE_VAR_T('NO_N_EHP',SSS,TTT)   =  DH_VAR_T('NO_N_Rural',SSS,TTT);
DE_VAR_T('NO_M_EHP',SSS,TTT)   =  DH_VAR_T('NO_M_Rural',SSS,TTT);
DE_VAR_T('DE_CS_EHP',SSS,TTT)  =  DH_VAR_T('DE_CS_A1',SSS,TTT)  ;
DE_VAR_T('DE_NE_EHP',SSS,TTT)  =  DH_VAR_T('DE_NE_A1',SSS,TTT)  ;
DE_VAR_T('DE_NW_EHP',SSS,TTT)  =  DH_VAR_T('DE_NW_A1',SSS,TTT)  ;

*/



*-------------------------------------------------------------------------------
* PARAMETER WTRRSVAR_S contains the description of the seasonal variation of the
* amount of water inflow
* to the reservoirs for each installed MW capacity of hydropower with storage,
* Unit: (none)

* Observe: the table is specified directly in the present sheet.

* Data source:  Nordel

TABLE WTRRSVAR_S(AAA,SSS)  'Variation of the water inflow to reservoirs'
                 S01           S02           S03           S04           S05           S06           S07           S08
SE_N_Rural    870434        817799        757277        733767        822964        823203        834463        765678
NO_S_Rural   1450723       1362998       1262129       1222945       1371607       1372005       1390771       1276129

+                S09           S10           S11           S12           S13           S14           S15           S16
SE_N_Rural    853649        597501        557507        540084        464684        432662        430186        480870
NO_S_Rural   1422749        995835        929178        900140        774473        721103        716977        801451

+                S17           S18           S19           S20           S21           S22           S23           S24
SE_N_Rural    434677        520553        411666        688162        607012        330298        342297        219184
NO_S_Rural    724462        867588        686111       1146937       1011686        550496        570495        365307

+                S25           S26           S27           S28           S29           S30           S31           S32
SE_N_Rural    434041        296021        247570        375879        519256        488248        528843        560576
NO_S_Rural    723402        493369        412617        626466        865426        813747        881405        934294

+                S33           S34           S35           S36           S37           S38           S39           S40
SE_N_Rural    595472        491599        570678        588404        570755        582851        481280        569697
NO_S_Rural    992453        819332        951130        980673        951258        971418        802133        949495

+                S41           S42           S43           S44           S45           S46           S47           S48
SE_N_Rural    853638        783124        450189        825629        572255        598488        489413        528319
NO_S_Rural   1422729       1305206        750315       1376049        953758        997480        815688        880532

+                S49           S50           S51           S52
SE_N_Rural    566349        655690        810443        777368
NO_S_Rural    943915       1092817       1350738       1295614
;

WTRRSVAR_S(IA,SSS)$(WTRRSVAR_S(IA,SSS) EQ 0) = WTRRSVAR_S('NO_S_Rural',SSS) ;

TABLE WTRRRVAR_T(AAA,SSS,TTT)  'Variation of generation of hydro run-of-river'
                          T001
DK_CA_Kbh.S01             1
;

WTRRRVAR_T(IA,SSS,TTT)$WTRRRFLH(IA) = 1 ;

$include '../../%COREDATAFOLDER%/data/var2001/Baltic-WTRRRVAR_T.inc';

WTRRRVAR_T(IA,SSS,TTT)$WTRRRFLH(IA)  = MAIKENS_RR(SSS,TTT,'LT_R_KauU');
WTRRRVAR_T(IA,SSS,TTT)$SAMEAS(IA,'LV_R_SmlC') = MAIKENS_RR(SSS,TTT,'LV_R_SmlC');

* ------------------------------------------------------------------------------

* PARAMETER WND_VAR_T contains the description of seasonal and daily variation
* of the wind power production.
* Units: (see description above under DE_VAR_T).

* Data source:

PARAMETER WND_VAR_T(AAA,SSS,TTT) /
$include '../../base/data/var2001/DK_CA_Kbh_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_CA_Aarhus_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Rural_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_A1_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_A1_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_A1_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore20_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore35_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_CS_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NE_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DE_NW_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_N_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_M_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Onshore50_LCI_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Offshore10_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Offshore20_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Offshore35_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_E_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/DK_W_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/FI_R_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_N_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_M_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/NO_S_Offshore50_WND_VAR_T.inc';
$include '../../base/data/var2001/SE_S_Offshore50_WND_VAR_T.inc';
/;

$include '../../%COREDATAFOLDER%/data/WND_VAR_T2.inc';

/*
* Profiler der mangler:
WND_VAR_T('DK_E_Offshore00',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
WND_VAR_T('DK_W_Offshore00',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);

*Kreigers Flak
WND_VAR_T('DK_KF_A',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
WND_VAR_T('DE_KF_A',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);

WND_VAR_T('SE_N_Offshore10',SSS,TTT)=WND_VAR_T('SE_S_Offshore10',SSS,TTT);
WND_VAR_T('SE_M_Offshore10',SSS,TTT)=WND_VAR_T('SE_S_Offshore10',SSS,TTT);
WND_VAR_T('SE_N_Offshore20',SSS,TTT)=WND_VAR_T('SE_S_Offshore20',SSS,TTT);
WND_VAR_T('SE_M_Offshore20',SSS,TTT)=WND_VAR_T('SE_S_Offshore20',SSS,TTT);
WND_VAR_T('SE_N_Offshore35',SSS,TTT)=WND_VAR_T('SE_S_Offshore35',SSS,TTT);
WND_VAR_T('SE_M_Offshore35',SSS,TTT)=WND_VAR_T('SE_S_Offshore35',SSS,TTT);
WND_VAR_T('SE_N_Offshore50',SSS,TTT)=WND_VAR_T('SE_S_Offshore50',SSS,TTT);
WND_VAR_T('SE_M_Offshore50',SSS,TTT)=WND_VAR_T('SE_S_Offshore50',SSS,TTT);

WND_VAR_T('DE_NE_Offshore10',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
WND_VAR_T('DE_NE_Offshore20',SSS,TTT)=WND_VAR_T('DK_E_Offshore20',SSS,TTT);
WND_VAR_T('DE_NE_Offshore35',SSS,TTT)=WND_VAR_T('DK_E_Offshore35',SSS,TTT);
WND_VAR_T('DE_NE_Offshore50',SSS,TTT)=WND_VAR_T('DK_E_Offshore50',SSS,TTT);

WND_VAR_T('DE_NW_Offshore10',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DE_NW_Offshore20',SSS,TTT)=WND_VAR_T('DK_W_Offshore20',SSS,TTT);
WND_VAR_T('DE_NW_Offshore35',SSS,TTT)=WND_VAR_T('DK_W_Offshore35',SSS,TTT);
WND_VAR_T('DE_NW_Offshore50',SSS,TTT)=WND_VAR_T('DK_W_Offshore50',SSS,TTT);

* Near offshore områder har samme profiler som normale offshore områder.
WND_VAR_T('DK_E_nearOffshore20',SSS,TTT)=WND_VAR_T('DK_E_Offshore20',SSS,TTT);
WND_VAR_T('DK_W_nearOffshore20',SSS,TTT)=WND_VAR_T('DK_W_Offshore20',SSS,TTT);
WND_VAR_T('FI_R_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_Offshore20',SSS,TTT);
WND_VAR_T('DE_NE_nearOffshore20',SSS,TTT)=WND_VAR_T('DE_NE_Offshore20',SSS,TTT);
WND_VAR_T('DE_NW_nearOffshore20',SSS,TTT)=WND_VAR_T('DE_NW_Offshore20',SSS,TTT);
WND_VAR_T('NO_N_nearOffshore20',SSS,TTT)=WND_VAR_T('NO_N_Offshore20',SSS,TTT);
WND_VAR_T('NO_M_nearOffshore20',SSS,TTT)=WND_VAR_T('NO_M_Offshore20',SSS,TTT);
WND_VAR_T('NO_S_nearOffshore20',SSS,TTT)=WND_VAR_T('NO_S_Offshore20',SSS,TTT);
WND_VAR_T('SE_N_nearOffshore20',SSS,TTT)=WND_VAR_T('SE_N_Offshore20',SSS,TTT);
WND_VAR_T('SE_M_nearOffshore20',SSS,TTT)=WND_VAR_T('SE_M_Offshore20',SSS,TTT);
WND_VAR_T('SE_S_nearOffshore20',SSS,TTT)=WND_VAR_T('SE_S_Offshore20',SSS,TTT);

WND_VAR_T('DK_E_nearOffshore35',SSS,TTT)=WND_VAR_T('DK_E_Offshore35',SSS,TTT);
WND_VAR_T('DK_W_nearOffshore35',SSS,TTT)=WND_VAR_T('DK_W_Offshore35',SSS,TTT);
WND_VAR_T('FI_R_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_Offshore35',SSS,TTT);
WND_VAR_T('DE_NE_nearOffshore35',SSS,TTT)=WND_VAR_T('DE_NE_Offshore35',SSS,TTT);
WND_VAR_T('DE_NW_nearOffshore35',SSS,TTT)=WND_VAR_T('DE_NW_Offshore35',SSS,TTT);
WND_VAR_T('NO_N_nearOffshore35',SSS,TTT)=WND_VAR_T('NO_N_Offshore35',SSS,TTT);
WND_VAR_T('NO_M_nearOffshore35',SSS,TTT)=WND_VAR_T('NO_M_Offshore35',SSS,TTT);
WND_VAR_T('NO_S_nearOffshore35',SSS,TTT)=WND_VAR_T('NO_S_Offshore35',SSS,TTT);
WND_VAR_T('SE_N_nearOffshore35',SSS,TTT)=WND_VAR_T('SE_N_Offshore35',SSS,TTT);
WND_VAR_T('SE_M_nearOffshore35',SSS,TTT)=WND_VAR_T('SE_M_Offshore35',SSS,TTT);
WND_VAR_T('SE_S_nearOffshore35',SSS,TTT)=WND_VAR_T('SE_S_Offshore35',SSS,TTT);

WND_VAR_T('DK_E_nearOffshore50',SSS,TTT)=WND_VAR_T('DK_E_Offshore50',SSS,TTT);
WND_VAR_T('DK_W_nearOffshore50',SSS,TTT)=WND_VAR_T('DK_W_Offshore50',SSS,TTT);
WND_VAR_T('FI_R_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_Offshore50',SSS,TTT);
WND_VAR_T('DE_NE_nearOffshore50',SSS,TTT)=WND_VAR_T('DE_NE_Offshore50',SSS,TTT);
WND_VAR_T('DE_NW_nearOffshore50',SSS,TTT)=WND_VAR_T('DE_NW_Offshore50',SSS,TTT);
WND_VAR_T('NO_N_nearOffshore50',SSS,TTT)=WND_VAR_T('NO_N_Offshore50',SSS,TTT);
WND_VAR_T('NO_M_nearOffshore50',SSS,TTT)=WND_VAR_T('NO_M_Offshore50',SSS,TTT);
WND_VAR_T('NO_S_nearOffshore50',SSS,TTT)=WND_VAR_T('NO_S_Offshore50',SSS,TTT);
WND_VAR_T('SE_N_nearOffshore50',SSS,TTT)=WND_VAR_T('SE_N_Offshore50',SSS,TTT);
WND_VAR_T('SE_M_nearOffshore50',SSS,TTT)=WND_VAR_T('SE_M_Offshore50',SSS,TTT);
WND_VAR_T('SE_S_nearOffshore50',SSS,TTT)=WND_VAR_T('SE_S_Offshore50',SSS,TTT);

* Far offshore områder har samme profiler som normale offshore områder.
WND_VAR_T('DK_E_farOffshore20',SSS,TTT)=WND_VAR_T('DK_E_Offshore20',SSS,TTT);
WND_VAR_T('DK_W_farOffshore20',SSS,TTT)=WND_VAR_T('DK_W_Offshore20',SSS,TTT);
WND_VAR_T('FI_R_farOffshore20',SSS,TTT)=WND_VAR_T('FI_R_Offshore20',SSS,TTT);
WND_VAR_T('DE_NE_farOffshore20',SSS,TTT)=WND_VAR_T('DE_NE_Offshore20',SSS,TTT);
WND_VAR_T('DE_NW_farOffshore20',SSS,TTT)=WND_VAR_T('DE_NW_Offshore20',SSS,TTT);
WND_VAR_T('NO_N_farOffshore20',SSS,TTT)=WND_VAR_T('NO_N_Offshore20',SSS,TTT);
WND_VAR_T('NO_M_farOffshore20',SSS,TTT)=WND_VAR_T('NO_M_Offshore20',SSS,TTT);
WND_VAR_T('NO_S_farOffshore20',SSS,TTT)=WND_VAR_T('NO_S_Offshore20',SSS,TTT);
WND_VAR_T('SE_N_farOffshore20',SSS,TTT)=WND_VAR_T('SE_N_Offshore20',SSS,TTT);
WND_VAR_T('SE_M_farOffshore20',SSS,TTT)=WND_VAR_T('SE_M_Offshore20',SSS,TTT);
WND_VAR_T('SE_S_farOffshore20',SSS,TTT)=WND_VAR_T('SE_S_Offshore20',SSS,TTT);

WND_VAR_T('DK_E_farOffshore35',SSS,TTT)=WND_VAR_T('DK_E_Offshore35',SSS,TTT);
WND_VAR_T('DK_W_farOffshore35',SSS,TTT)=WND_VAR_T('DK_W_Offshore35',SSS,TTT);
WND_VAR_T('FI_R_farOffshore35',SSS,TTT)=WND_VAR_T('FI_R_Offshore35',SSS,TTT);
WND_VAR_T('DE_NE_farOffshore35',SSS,TTT)=WND_VAR_T('DE_NE_Offshore35',SSS,TTT);
WND_VAR_T('DE_NW_farOffshore35',SSS,TTT)=WND_VAR_T('DE_NW_Offshore35',SSS,TTT);
WND_VAR_T('NO_N_farOffshore35',SSS,TTT)=WND_VAR_T('NO_N_Offshore35',SSS,TTT);
WND_VAR_T('NO_M_farOffshore35',SSS,TTT)=WND_VAR_T('NO_M_Offshore35',SSS,TTT);
WND_VAR_T('NO_S_farOffshore35',SSS,TTT)=WND_VAR_T('NO_S_Offshore35',SSS,TTT);
WND_VAR_T('SE_N_farOffshore35',SSS,TTT)=WND_VAR_T('SE_N_Offshore35',SSS,TTT);
WND_VAR_T('SE_M_farOffshore35',SSS,TTT)=WND_VAR_T('SE_M_Offshore35',SSS,TTT);
WND_VAR_T('SE_S_farOffshore35',SSS,TTT)=WND_VAR_T('SE_S_Offshore35',SSS,TTT);

WND_VAR_T('DK_E_farOffshore50',SSS,TTT)=WND_VAR_T('DK_E_Offshore50',SSS,TTT);
WND_VAR_T('DK_W_farOffshore50',SSS,TTT)=WND_VAR_T('DK_W_Offshore50',SSS,TTT);
WND_VAR_T('FI_R_farOffshore50',SSS,TTT)=WND_VAR_T('FI_R_Offshore50',SSS,TTT);
WND_VAR_T('DE_NE_farOffshore50',SSS,TTT)=WND_VAR_T('DE_NE_Offshore50',SSS,TTT);
WND_VAR_T('DE_NW_farOffshore50',SSS,TTT)=WND_VAR_T('DE_NW_Offshore50',SSS,TTT);
WND_VAR_T('NO_N_farOffshore50',SSS,TTT)=WND_VAR_T('NO_N_Offshore50',SSS,TTT);
WND_VAR_T('NO_M_farOffshore50',SSS,TTT)=WND_VAR_T('NO_M_Offshore50',SSS,TTT);
WND_VAR_T('NO_S_farOffshore50',SSS,TTT)=WND_VAR_T('NO_S_Offshore50',SSS,TTT);
WND_VAR_T('SE_N_farOffshore50',SSS,TTT)=WND_VAR_T('SE_N_Offshore50',SSS,TTT);
WND_VAR_T('SE_M_farOffshore50',SSS,TTT)=WND_VAR_T('SE_M_Offshore50',SSS,TTT);
WND_VAR_T('SE_S_farOffshore50',SSS,TTT)=WND_VAR_T('SE_S_Offshore50',SSS,TTT);

*For Baltikum og Polen anvendes finske profiler
WND_VAR_T('RU_NOV_Onshore20      ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore20      ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('EE_R_Onshore20     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('LV_R_Onshore20     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('LT_R_Onshore20     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('PL_R_Onshore20     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20     ',SSS,TTT);
WND_VAR_T('RU_NOV_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('EE_R_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('LV_R_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('LT_R_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('PL_R_Onshore35     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35     ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('RU_NOV_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('EE_R_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('LV_R_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('LT_R_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('PL_R_Onshore50     ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50     ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('RU_NOV_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('EE_R_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('LV_R_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('LT_R_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('PL_R_Onshore20_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore20_LCI ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('RU_NOV_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('EE_R_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('LV_R_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('LT_R_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('PL_R_Onshore35_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore35_LCI ',SSS,TTT);
WND_VAR_T('RU_KAL_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('RU_NOV_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('EE_R_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('LV_R_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('LT_R_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('PL_R_Onshore50_LCI ',SSS,TTT)=WND_VAR_T('FI_R_Onshore50_LCI ',SSS,TTT);
WND_VAR_T('RU_KAL_Offshore10    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore10    ',SSS,TTT);
WND_VAR_T('EE_R_Offshore10    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore10    ',SSS,TTT);
WND_VAR_T('LV_R_Offshore10    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore10    ',SSS,TTT);
WND_VAR_T('LT_R_Offshore10    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore10    ',SSS,TTT);
WND_VAR_T('PL_R_Offshore10    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore10    ',SSS,TTT);
WND_VAR_T('RU_KAL_Offshore20    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore20    ',SSS,TTT);
WND_VAR_T('EE_R_Offshore20    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore20    ',SSS,TTT);
WND_VAR_T('LV_R_Offshore20    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore20    ',SSS,TTT);
WND_VAR_T('LT_R_Offshore20    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore20    ',SSS,TTT);
WND_VAR_T('PL_R_Offshore20    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore20    ',SSS,TTT);
WND_VAR_T('RU_KAL_Offshore35    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore35    ',SSS,TTT);
WND_VAR_T('EE_R_Offshore35    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore35    ',SSS,TTT);
WND_VAR_T('LV_R_Offshore35    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore35    ',SSS,TTT);
WND_VAR_T('LT_R_Offshore35    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore35    ',SSS,TTT);
WND_VAR_T('PL_R_Offshore35    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore35    ',SSS,TTT);
WND_VAR_T('RU_KAL_Offshore50    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore50    ',SSS,TTT);
WND_VAR_T('EE_R_Offshore50    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore50    ',SSS,TTT);
WND_VAR_T('LV_R_Offshore50    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore50    ',SSS,TTT);
WND_VAR_T('LT_R_Offshore50    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore50    ',SSS,TTT);
WND_VAR_T('PL_R_Offshore50    ',SSS,TTT)=WND_VAR_T('FI_R_Offshore50    ',SSS,TTT);
WND_VAR_T('RU_KAL_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore20',SSS,TTT);
WND_VAR_T('EE_R_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore20',SSS,TTT);
WND_VAR_T('LV_R_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore20',SSS,TTT);
WND_VAR_T('LT_R_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore20',SSS,TTT);
WND_VAR_T('PL_R_nearOffshore20',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore20',SSS,TTT);
WND_VAR_T('RU_KAL_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore35',SSS,TTT);
WND_VAR_T('EE_R_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore35',SSS,TTT);
WND_VAR_T('LV_R_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore35',SSS,TTT);
WND_VAR_T('LT_R_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore35',SSS,TTT);
WND_VAR_T('PL_R_nearOffshore35',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore35',SSS,TTT);
WND_VAR_T('RU_KAL_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('SE_S_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('EE_R_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('LV_R_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('LT_R_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('PL_R_nearOffshore50',SSS,TTT)=WND_VAR_T('FI_R_nearOffshore50',SSS,TTT);
WND_VAR_T('RU_KAL_farOffshore20 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore20 ',SSS,TTT);
WND_VAR_T('EE_R_farOffshore20 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore20 ',SSS,TTT);
WND_VAR_T('LV_R_farOffshore20 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore20 ',SSS,TTT);
WND_VAR_T('LT_R_farOffshore20 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore20 ',SSS,TTT);
WND_VAR_T('PL_R_farOffshore20 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore20 ',SSS,TTT);
WND_VAR_T('RU_KAL_farOffshore35 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore35 ',SSS,TTT);
WND_VAR_T('EE_R_farOffshore35 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore35 ',SSS,TTT);
WND_VAR_T('LV_R_farOffshore35 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore35 ',SSS,TTT);
WND_VAR_T('LT_R_farOffshore35 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore35 ',SSS,TTT);
WND_VAR_T('PL_R_farOffshore35 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore35 ',SSS,TTT);
WND_VAR_T('RU_KAL_farOffshore50 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore50 ',SSS,TTT);
WND_VAR_T('EE_R_farOffshore50 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore50 ',SSS,TTT);
WND_VAR_T('LV_R_farOffshore50 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore50 ',SSS,TTT);
WND_VAR_T('LT_R_farOffshore50 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore50 ',SSS,TTT);
WND_VAR_T('PL_R_farOffshore50 ',SSS,TTT)=WND_VAR_T('FI_R_farOffshore50 ',SSS,TTT);

*/

$ontext
WND_VAR_T('DK_W_DJUR',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DK_W_HORNS',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DK_W_LAESOE',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DK_W_JAMMER',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DK_W_RINGK',SSS,TTT)=WND_VAR_T('DK_W_Offshore10',SSS,TTT);
WND_VAR_T('DK_E_KRIEGER',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
WND_VAR_T('DK_E_ROENNE',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
WND_VAR_T('DK_E_MIDDEL',SSS,TTT)=WND_VAR_T('DK_E_Offshore10',SSS,TTT);
$offtext

/*
$ifi not %biofuel%==yes $goto notbiofuel
DE_VAR_T('DK_E_bf',SSS,TTT)  = WND_VAR_T('DK_E_Offshore10',SSS,TTT) ;
DE_VAR_T('DK_W_bf',SSS,TTT)  = WND_VAR_T('DK_E_Offshore10',SSS,TTT) ;
*Heat demand for biofuel production has the same profile as electricity demand
*DH_VAR_T('DK_E_bf_A',SSS,TTT)= DE_VAR_T('DK_E_bf',SSS,TTT);
*DH_VAR_T('DK_W_bf_A',SSS,TTT)= DE_VAR_T('DK_W_bf',SSS,TTT);
* Biofuel-areas. No specific profile
DH_VAR_T('DK_W_bf_A',SSS,TTT) = 1;
DH_VAR_T('DK_E_bf_A',SSS,TTT) = 1;
$label notbiofuel
*/

* PARAMETER WND_SPEED_T contains the description of seasonal and daily variation
* of the wind power wind .
* Units: m/s.

* Data source:
PARAMETER WND_SPEED_T(AAA,SSS,TTT) 'Wind speeds given in meters per second' /
$include '../../%COREDATAFOLDER%/data/windspeed_region1.inc';
/;
/*
WND_SPEED_T(IA,SSS,T)$(SUM((Y,IGWND),GKFX(Y,IA,IGWND)) OR SUM(IGWND,AGKN(IA,IGWND)))
    =WND_SPEED_T('DE_NE_Offshore10',SSS,T);
*/
PARAMETER WND_SPEED_POWER_T(AAA,GGG,SSS,TTT) 'Wind power based on wind speed variation and power curve parameters';
* Hans20150206: this next line added:
WND_SPEED_POWER_T(AAA,GGG,S,T) = 0;
/*
WND_SPEED_POWER_T(IA,IGWND,SSS,TTT)$(GWNDDATA(IGWND,'Expo_scale') AND WND_SPEED_T(IA,SSS,TTT) AND (SUM(Y,GKFX(Y,IA,IGWND)) OR AGKN(IA,IGWND)))=
    1/(1+GWNDDATA(IGWND,'Expo_scale')*exp(-GWNDDATA(IGWND,'Growth_rate')*(WND_SPEED_T(IA,SSS,TTT)-GWNDDATA(IGWND,'Max_growth'))))**(1/GWNDDATA(IGWND,'Root'));
*/

* PARAMETER SOLE_VAR_T contains the description of seasonal and daily variation
* of the solar power production.
* Units: (see description above under DE_VAR_T)

* Data source:

* The input data are checked for reasonable values. See the files ERROR*.inc'.

* Tysk solCELLEprofil baseret på profil modtaget fra Risø til rapporten "Comparative assessment of hydrogen storage
* and international electricity trade for a Danish energy system with wind power and hydrogen/fuel cell technologies"

PARAMETER  SOLE_VAR_T(AAA,SSS,TTT) 'Variation of the solar electricity generation'  /
$include   '../../%COREDATAFOLDER%/data/PV50herz_var.inc'
/;

/*
* Copy solar profil to all areas where solar power is or can be installed.
SOLE_VAR_T(IA,SSS,TTT)$(not sameas(IA,'DE_CS_A1') and SUM(IGSOLE$(IAGK(IA,IGSOLE) or AGKN(IA,IGSOLE)),1)) = SOLE_VAR_T('DE_CS_A1',SSS,TTT)
*/

PARAMETER  SOLH_VAR_T(AAA,SSS,TTT) 'Variation of the solar generation'  /
$include   '../../%COREDATAFOLDER%/data/DK_CA_Kbh-04-sol.inc';
/;

/*
SOLH_VAR_T(IA,SSS,TTT) $((NOT SAMEAS(IA,'DK_CA_Kbh')) and (not AAAOFFSHORE(IA)) and SUM(IGSOLH$(IAGK(IA,IGSOLH) or AGKN(IA,IGSOLH)),1)) = SOLH_VAR_T('DK_CA_Kbh',SSS,TTT);
*/

* PARAMETER WAVE_VAR_T contains the description of seasonal and daily variation
* of the wave power production.
* Units: (see description above under DE_VAR_T)

* Data source:

PARAMETER  WAVE_VAR_T(AAA,SSS,TTT) 'Variation of the wave power generation'  /
$if EXIST 'DK_W_wave.inc' $INCLUDE 'DK_W_wave.inc';
$if not EXIST 'DK_W_wave.inc' $INCLUDE '../../%COREDATAFOLDER%/data/DK_W_wave.inc'
/;

* Wave power profile copied to other offshore areas.
WAVE_VAR_T(AAAOFFSHORE(IA),SSS,TTT)$(not sameas(AAAOFFSHORE,'DK_W_Offshore10')  and SUM(IGWAVE$(IAGK(IA,IGWAVE) or AGKN(IA,IGWAVE)),1))  = WAVE_VAR_T('DK_W_Offshore10',SSS,TTT);

*------ Start: From VPH ------
* ------------------------------------------------------------------------------
PARAMETER GEQF_S(CCCRRRAAA,FFF,SSS) 'Seasonal variation in fuel consumption requirements'
/
DENMARK.MUNI_WASTE_CPH.S01    0
/;

* ------------------------------------------------------------------------------
PARAMETER GMAXF_S(CCCRRRAAA,FFF,SSS) 'Seasonal variation in fuel consumption requirements'
/
DENMARK.MUNI_WASTE_CPH.S01 0
/;

* ------------------------------------------------------------------------------
PARAMETER GMINF_S(CCCRRRAAA,FFF,SSS) 'Seasonal variation in fuel consumption requirements'
/
DENMARK.MUNI_WASTE_CPH.S01  0
/;

*------ End: From VPH ------

* PARAMETER X3FX_VAR_T contains the description of seasonal and daily variation
* in the fixed exchange with third regions.
* Units: (see description above under DE_VAR_T)

* Data source:

* The input data are checked for reasonable values. See the file CHECK.inc'.

* A positive number indicates net export from the region in the set TR,
* a negative number indicates net import to the region in the set TR
* for the given time segment (S,T).
* The values are seen from the country in the set TC,
* i.e., any losses are disregarded.
* Observe that an error will be produced if a net export is specified
* which is not consistent with the values in TABLE X3FX_VAR_T.

PARAMETER  X3FX_VAR_T(RRR,SSS,TTT) /
*$include   '../../%COREDATAFOLDER%/data/var2001/DK-UT-U-SJ_3C-01.inc'
*$include   '../../%COREDATAFOLDER%/data/var2001/DK-UT-U-JY_3C-01.inc'
$include   '../../%COREDATAFOLDER%/data/var2001/FI-UT-U-FI_3C-01.inc'
*$include   '../../%COREDATAFOLDER%/data/var2001/NO-UT-U-NO_3C-01.inc'
*$include   '../../%COREDATAFOLDER%/data/var2001/SE-UT-U-SE_3C-01.inc'
/;

* LARS: 20091201 Add these (or better data) if using Baltic states but not Russia. Also, add data to X3.inc
*X3FX_VAR_T(IR,SSS,TTT)$SAMEAS(IR,'EE_R') =DE_VAR_T('FI_R',SSS,TTT)  ;
*X3FX_VAR_T(IR,SSS,TTT)$SAMEAS(IR,'LV_R') =DE_VAR_T('FI_R',SSS,TTT)  ;
*X3FX_VAR_T(IR,SSS,TTT)$SAMEAS(IR,'LT_R') =DE_VAR_T('FI_R',SSS,TTT)  ;

* The following parameter is used for enforcing a seasonal price profile
* on hydro power with storage.
* Only relative values count.
* Units: EUR90/MWh.
* Source: Based on monthly average spot prices from www.nordpool.no, and converted from Norwegian crowns to Euro90 based on Eurostat statistics.

TABLE HYPPROFILS(AAA,SSS)  'Hydro with storage seasonal price profile'
            S01                S02                S03                S04                S05                S06                S07                S08                S09                S10                S11                S12                S13                S14                S15                S16                S17                S18                S19                S20                S21                S22                S23                S24                S25                S26                S27                S28                S29                S30                S31                S32                S33                S34                S35                S36                S37                S38                S39                S40                S41                S42                S43                S44                S45                S46                S47                S48                S49                S50                S51                S52
*1996
*NO_S_Rural  0                  0                  0                  0                  6.573714672        6.573714672        6.573714672        6.573714672        4.380375549        4.380375549        4.380375549        4.380375549        4.380375549        5.775372846        5.775372846        5.775372846        5.775372846        7.514917668        7.514917668        7.514917668        7.514917668        7.514917668        6.793258675        6.793258675        6.793258675        6.793258675        5.619906279        5.619906279        5.619906279        5.619906279        11.61272223        11.61272223        11.61272223        11.61272223        11.61272223        14.63486622        14.63486622        14.63486622        14.63486622        10.3710906         10.3710906         10.3710906         10.3710906         3.851999313        3.851999313        3.851999313        3.851999313        3.851999313        4.532690766        4.532690766        4.532690766        4.532690766
*1997
*NO_S_Rural  13.06460605        13.06460605        13.06460605        13.06460605        7.160649131        7.160649131        7.160649131        7.160649131        3.750854457        3.750854457        3.750854457        3.750854457        3.750854457        3.586009372        3.586009372        3.586009372        3.586009372        2.405513758        2.405513758        2.405513758        2.405513758        2.405513758        2.184120741        2.184120741        2.184120741        2.184120741        0                  0                  0                  0                  4.404071031        4.404071031        4.404071031        4.404071031        4.404071031        1.401999862        1.401999862        1.401999862        1.401999862        4.085958416        4.085958416        4.085958416        4.085958416        7.163130567        7.163130567        7.163130567        7.163130567        7.163130567        8.719329084        8.719329084        8.719329084        8.719329084
*1998
*NO_S_Rural  10.90320595        10.90320595        10.90320595        10.90320595        9.327806394        9.327806394        9.327806394        9.327806394        7.679778506        7.679778506        7.679778506        7.679778506        7.679778506        6.846035569        6.846035569        6.846035569        6.846035569        5.390132186        5.390132186        5.390132186        5.390132186        5.390132186        6.493749637        6.493749637        6.493749637        6.493749637        1.468891705        1.468891705        1.468891705        1.468891705        0                  0                  0                  0                  0                  2.670914239        2.670914239        2.670914239        2.670914239        5.444081042        5.444081042        5.444081042        5.444081042        8.927603602        8.927603602        8.927603602        8.927603602        8.927603602        9.736152938        9.736152938        9.736152938        9.736152938
*1999
*NO_S_Rural  6.905044532        6.905044532        6.905044532        6.905044532        5.791887556        5.791887556        5.791887556        5.791887556        3.684829282        3.684829282        3.684829282        3.684829282        3.684829282        1.96730772         1.96730772         1.96730772         1.96730772         2.477015226        2.477015226        2.477015226        2.477015226        2.477015226        1.376188309        1.376188309        1.376188309        1.376188309        0                  0                  0                  0                  4.164782753        4.164782753        4.164782753        4.164782753        4.164782753        6.349581071        6.349581071        6.349581071        6.349581071        6.560889788        6.560889788        6.560889788        6.560889788        5.686639506        5.686639506        5.686639506        5.686639506        5.686639506        7.141157869        7.141157869        7.141157869        7.141157869
*2000
*NO_S_Rural  7.604980819        7.604980819        7.604980819        7.604980819        5.010687189        5.010687189        5.010687189        5.010687189        4.164328661        4.164328661        4.164328661        4.164328661        4.164328661        4.997072491        4.997072491        4.997072491        4.997072491        2.48505365         2.48505365         2.48505365         2.48505365         2.48505365         3.269085913        3.269085913        3.269085913        3.269085913        0                  0                  0                  0                  2.610731655        2.610731655        2.610731655        2.610731655        2.610731655        5.915854053        5.915854053        5.915854053        5.915854053        6.835348453        6.835348453        6.835348453        6.835348453        7.840493681        7.840493681        7.840493681        7.840493681        7.840493681        8.185919508        8.185919508        8.185919508        8.185919508
*2001
*NO_S_Rural  1.461352058        1.461352058        1.461352058        1.461352058        6.435677383        6.435677383        6.435677383        6.435677383        5.425787469        5.425787469        5.425787469        5.425787469        5.425787469        5.749330431        5.749330431        5.749330431        5.749330431        3.700006117        3.700006117        3.700006117        3.700006117        3.700006117        4.45225916         4.45225916         4.45225916         4.45225916         2.540829576        2.540829576        2.540829576        2.540829576        1.782674729        1.782674729        1.782674729        1.782674729        1.782674729        1.32908212         1.32908212         1.32908212         1.32908212         0                  0                  0                  0                  1.574122916        1.574122916        1.574122916        1.574122916        1.574122916        3.351446848        3.351446848        3.351446848        3.351446848
*2002
*NO_S_Rural  7.349475615        7.349475615        7.349475615        7.349475615        3.995834813        3.995834813        3.995834813        3.995834813        2.643606145        2.643606145        2.643606145        2.643606145        2.643606145        1.637215824        1.637215824        1.637215824        1.637215824        0                  0                  0                  0                  0                  0.637761431        0.637761431        0.637761431        0.637761431        0.102296388        0.102296388        0.102296388        0.102296388        3.293730671        3.293730671        3.293730671        3.293730671        3.293730671        6.145798353        6.145798353        6.145798353        6.145798353        10.63455422        10.63455422        10.63455422        10.63455422        18.60786278        18.60786278        18.60786278        18.60786278        18.60786278        39.5644072         39.5644072         39.5644072         39.5644072
*2003
*NO_S_Rural  29.05596309        29.05596309        29.05596309        29.05596309        14.57531351        14.57531351        14.57531351        14.57531351        9.741590931        9.741590931        9.741590931        9.741590931        9.741590931        4.060920285        4.060920285        4.060920285        4.060920285        2.722327373        2.722327373        2.722327373        2.722327373        2.722327373        0                  0                  0                  0                  2.452939652        2.452939652        2.452939652        2.452939652        6.33086939         6.33086939         6.33086939         6.33086939         6.33086939         5.659718254        5.659718254        5.659718254        5.659718254        7.837446528        7.837446528        7.837446528        7.837446528        8.591748411        8.591748411        8.591748411        8.591748411        8.591748411        4.821870204        4.821870204        4.821870204        4.821870204
*2004
*NO_S_Rural  3.223609372        3.223609372        3.223609372        3.223609372        2.530191244        2.530191244        2.530191244        2.530191244        3.252308251        3.252308251        3.252308251        3.252308251        3.252308251        2.351931117        2.351931117        2.351931117        2.351931117        1.408458268        1.408458268        1.408458268        1.408458268        1.408458268        4.678600294        4.678600294        4.678600294        4.678600294        2.284157477        2.284157477        2.284157477        2.284157477        5.275429634        5.275429634        5.275429634        5.275429634        5.275429634        2.604140859        2.604140859        2.604140859        2.604140859        1.384949406        1.384949406        1.384949406        1.384949406        2.203870942        2.203870942        2.203870942        2.203870942        2.203870942        0                  0                  0                  0
*2005
*NO_S_Rural  0                  0                  0                  0                  1.753291451        1.753291451        1.753291451        1.753291451        4.617692904        4.617692904        4.617692904        4.617692904        4.617692904        5.516440904        5.516440904        5.516440904        5.516440904        5.397183574        5.397183574        5.397183574        5.397183574        5.397183574        1.61423983         1.61423983         1.61423983         1.61423983         3.478006224        3.478006224        3.478006224        3.478006224        5.005164338        5.005164338        5.005164338        5.005164338        5.005164338        3.563373139        3.563373139        3.563373139        3.563373139        5.555443436        5.555443436        5.555443436        5.555443436        4.392310834        4.392310834        4.392310834        4.392310834        4.392310834        7.447990548        7.447990548        7.447990548        7.447990548
*2006
*NO_S_Rural  4.403989874        4.403989874        4.403989874        4.403989874        6.631048055        6.631048055        6.631048055        6.631048055        12.52486591        12.52486591        12.52486591        12.52486591        12.52486591        11.53022655        11.53022655        11.53022655        11.53022655        1.753971295        1.753971295        1.753971295        1.753971295        1.753971295        6.279888177        6.279888177        6.279888177        6.279888177        10.36958708        10.36958708        10.36958708        10.36958708        22.31845375        22.31845375        22.31845375        22.31845375        22.31845375        21.78341469        21.78341469        21.78341469        21.78341469        15.31597142        15.31597142        15.31597142        15.31597142        9.719868978        9.719868978        9.719868978        9.719868978        9.719868978        0                  0                  0                  0
*Average
*NO_S_Rural  5.05960118         5.05960118         5.05960118         5.05960118         3.769953365        3.769953365        3.769953365        3.769953365        3.04994579         3.04994579         3.04994579         3.04994579         3.04994579         2.336477157        2.336477157        2.336477157        2.336477157        0.630724067        0.630724067        0.630724067        0.630724067        0.630724067        0.860230708        0.860230708        0.860230708        0.860230708        0                  0                  0                  0                  3.498365073        3.498365073        3.498365073        3.498365073        3.498365073        3.976557135        3.976557135        3.976557135        3.976557135        4.155374448        4.155374448        4.155374448        4.155374448        4.567548832        4.567548832        4.567548832        4.567548832        4.567548832        5.925850054        5.925850054        5.925850054        5.925850054
* LB20120410: Moved zero so that hydro will be used if available, in spite of price calibration.
NO_S_Rural  -0.87              -0.87              -0.87              -0.87              -2.16              -2.16              -2.16              -2.16              -2.88              -2.88              -2.88              -2.88              -2.88              -3.59              -3.59              -3.59              -3.59              -5.30              -5.30              -5.30              -5.30              -5.30              -5.07              -5.07              -5.07              -5.07              -5.93              -5.93              -5.93              -5.93              -2.43              -2.43              -2.43              -2.43              -2.43              -1.95              -1.95              -1.95              -1.95              -1.77              -1.77              -1.77              -1.77              -1.36              -1.36              -1.36              -1.36              -1.36              0.00               0.00               0.00               0.00
;

HYPPROFILS(IA,SSS)=HYPPROFILS('NO_S_Rural',SSS);


* PARAMETER DEF_STEPS describes the elastic electricity demands
* in relative terms, by quantifying the steps.
* Unit: (none).

* Quantities are specified relative to 1.0.
* Thus, with e.q. quantity values of 1.04 and 1.03 for DEF_D2 and DEF_D1,
* respectively, this means that the first step in decrease of demand
* has a magnitude of 3% of demand in a base year
* and the second step has a magnitude of 1%, adding up to 4%.
* With e.q. price values of 0.98 and 0.95 for DEF_U1 and DEF_U2,
* respectively, this means that the first step increase of demand
* corresponds to a price of 98% of nominal and the second step
* corresponds to a price of 95% of nominal.
* Observe that the sequence of quantities should be increasing and the
* sequence of price numbers should be decreasing.

* Do not change the values in DEF_DINF!

* Data source:

TABLE DEF_STEPS(RRR,SSS,TTT,DF_QP,DEF)  'Elastic electricity demands'
                                    DEF_D1_9     DEF_D1_8     DEF_D1_7     DEF_D1_6     DEF_D1_5     DEF_D1_4     DEF_D1_3     DEF_D1_2     DEF_D1_1
DK_E.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1

/*
DK_W.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
EE_R.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
FI_R.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_CS.S01.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NE.S01.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NW.S01.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LV_R.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LT_R.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_N.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_M.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_S.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_O.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_NW.S01.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_W.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_Central.S01.T001.DF_QUANT           0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_SE.S01.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_S.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAR.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KOL.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_PSK.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAL.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_ARK.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_STP.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_NOV.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KOM.S01.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_N.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_M.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_S.S01.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_E.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_W.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
EE_R.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
FI_R.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_CS.S01.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NE.S01.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NW.S01.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LV_R.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LT_R.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_N.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_M.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_S.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_O.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_NW.S01.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_W.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_Central.S01.T002.DF_QUANT           0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_SE.S01.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_S.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_N.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_M.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_S.S01.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_E.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_W.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
EE_R.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
FI_R.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_CS.S02.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NE.S02.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NW.S02.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LV_R.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LT_R.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_N.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_M.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_S.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_O.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_NW.S02.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_W.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_Central.S02.T001.DF_QUANT           0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_SE.S02.T001.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_S.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAR.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KOL.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_PSK.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAL.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_ARK.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_STP.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_NOV.S02.T001.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_N.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_M.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_S.S02.T001.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_E.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DK_W.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
EE_R.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
FI_R.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_CS.S02.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NE.S02.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
DE_NW.S02.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LV_R.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
LT_R.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_N.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_M.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_S.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
NO_O.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_NW.S02.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_W.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_Central.S02.T002.DF_QUANT           0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_SE.S02.T002.DF_QUANT                0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
PL_S.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAR.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KOL.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_PSK.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_KAL.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_ARK.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_STP.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
RU_NOV.S02.T002.DF_QUANT               0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_N.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_M.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
SE_S.S02.T002.DF_QUANT                 0.82         0.84         0.88         0.92         0.96         0.98         0.99         0.995        1
*/
DK_E.S01.T001.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
/*
DK_W.S01.T001.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
EE_R.S01.T001.DF_PRICE                 2.7063       2.3887       1.9051       1.5329       1.2436       1.1164       1.0568       1.0279       1
FI_R.S01.T001.DF_PRICE                 2.4167       2.1642       1.77         1.4592       1.2118       1.1017       1.0497       1.0245       1
DE_CS.S01.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NE.S01.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NW.S01.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
LV_R.S01.T001.DF_PRICE                 2.9223       2.554        2.0027       1.5853       1.2658       1.1266       1.0616       1.0303       1
LT_R.S01.T001.DF_PRICE                 2.9183       2.551        2.0009       1.5843       1.2654       1.1264       1.0616       1.0302       1
NO_N.S01.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_M.S01.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_S.S01.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_O.S01.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
PL_NW.S01.T001.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_W.S01.T001.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_Central.S01.T001.DF_PRICE           2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_SE.S01.T001.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_S.S01.T001.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
RU_KAR.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KOL.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_PSK.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KAL.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_ARK.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_STP.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_NOV.S01.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
SE_N.S01.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_M.S01.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_S.S01.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
DK_E.S01.T002.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
DK_W.S01.T002.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
EE_R.S01.T002.DF_PRICE                 2.7063       2.3887       1.9051       1.5329       1.2436       1.1164       1.0568       1.0279       1
FI_R.S01.T002.DF_PRICE                 2.4167       2.1642       1.77         1.4592       1.2118       1.1017       1.0497       1.0245       1
DE_CS.S01.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NE.S01.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NW.S01.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
LV_R.S01.T002.DF_PRICE                 2.9223       2.554        2.0027       1.5853       1.2658       1.1266       1.0616       1.0303       1
LT_R.S01.T002.DF_PRICE                 2.9183       2.551        2.0009       1.5843       1.2654       1.1264       1.0616       1.0302       1
NO_N.S01.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_M.S01.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_S.S01.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_O.S01.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
PL_NW.S01.T002.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_W.S01.T002.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_Central.S01.T002.DF_PRICE           2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_SE.S01.T002.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_S.S01.T002.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
RU_KAR.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KOL.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_PSK.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KAL.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_ARK.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_STP.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_NOV.S01.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
SE_N.S01.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_M.S01.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_S.S01.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
DK_E.S02.T001.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
DK_W.S02.T001.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
EE_R.S02.T001.DF_PRICE                 2.7063       2.3887       1.9051       1.5329       1.2436       1.1164       1.0568       1.0279       1
FI_R.S02.T001.DF_PRICE                 2.4167       2.1642       1.77         1.4592       1.2118       1.1017       1.0497       1.0245       1
DE_CS.S02.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NE.S02.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NW.S02.T001.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
LV_R.S02.T001.DF_PRICE                 2.9223       2.554        2.0027       1.5853       1.2658       1.1266       1.0616       1.0303       1
LT_R.S02.T001.DF_PRICE                 2.9183       2.551        2.0009       1.5843       1.2654       1.1264       1.0616       1.0302       1
NO_N.S02.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_M.S02.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_S.S02.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_O.S02.T001.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
PL_NW.S02.T001.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_W.S02.T001.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_Central.S02.T001.DF_PRICE           2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_SE.S02.T001.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_S.S02.T001.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
RU_KAR.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KOL.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_PSK.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KAL.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_ARK.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_STP.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_NOV.S02.T001.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
SE_N.S02.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_M.S02.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_S.S02.T001.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
DK_E.S02.T002.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
DK_W.S02.T002.DF_PRICE                 12.654       9.11         5.2276       3.0564       1.8184       1.3637       1.1705       1.0817       1
EE_R.S02.T002.DF_PRICE                 2.7063       2.3887       1.9051       1.5329       1.2436       1.1164       1.0568       1.0279       1
FI_R.S02.T002.DF_PRICE                 2.4167       2.1642       1.77         1.4592       1.2118       1.1017       1.0497       1.0245       1
DE_CS.S02.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NE.S02.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
DE_NW.S02.T002.DF_PRICE                3.4177       2.9272       2.2176       1.698        1.3129       1.148        1.0718       1.0352       1
LV_R.S02.T002.DF_PRICE                 2.9223       2.554        2.0027       1.5853       1.2658       1.1266       1.0616       1.0303       1
LT_R.S02.T002.DF_PRICE                 2.9183       2.551        2.0009       1.5843       1.2654       1.1264       1.0616       1.0302       1
NO_N.S02.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_M.S02.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_S.S02.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
NO_O.S02.T002.DF_PRICE                 2.4353       2.1788       1.7789       1.4641       1.2139       1.1027       1.0502       1.0247       1
PL_NW.S02.T002.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_W.S02.T002.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_Central.S02.T002.DF_PRICE           2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_SE.S02.T002.DF_PRICE                2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
PL_S.S02.T002.DF_PRICE                 2.4301       2.1747       1.7764       1.4627       1.2133       1.1024       1.0501       1.0247       1
RU_KAR.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KOL.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_PSK.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_KAL.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_ARK.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_STP.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
RU_NOV.S02.T002.DF_PRICE               2.436        2.1793       1.7792       1.4643       1.214        1.1027       1.0502       1.0247       1
SE_N.S02.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_M.S02.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1
SE_S.S02.T002.DF_PRICE                 2.5463       2.2651       1.8312       1.4928       1.2263       1.1084       1.053        1.0261       1

+                                DEF_U1_1     DEF_U1_2     DEF_U1_3     DEF_U1_4     DEF_U1_5     DEF_U1_6     DEF_U1_7     DEF_U1_8     DEF_U1_9
DK_E.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_W.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
EE_R.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
FI_R.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_CS.S01.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NE.S01.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NW.S01.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LV_R.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LT_R.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_N.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_M.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_S.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_O.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_NW.S01.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_W.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_Central.S01.T001.DF_QUANT     1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_SE.S01.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_S.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAR.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KOL.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_PSK.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAL.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_ARK.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_STP.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_NOV.S01.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_N.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_M.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_S.S01.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_E.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_W.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
EE_R.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
FI_R.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_CS.S01.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NE.S01.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NW.S01.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LV_R.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LT_R.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_N.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_M.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_S.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_O.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_NW.S01.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_W.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_Central.S01.T002.DF_QUANT     1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_SE.S01.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_S.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAR.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KOL.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_PSK.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAL.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_ARK.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_STP.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_NOV.S01.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_N.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_M.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_S.S01.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_E.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_W.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
EE_R.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
FI_R.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_CS.S02.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NE.S02.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NW.S02.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LV_R.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LT_R.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_N.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_M.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_S.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_O.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_NW.S02.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_W.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_Central.S02.T001.DF_QUANT     1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_SE.S02.T001.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_S.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAR.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KOL.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_PSK.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAL.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_ARK.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_STP.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_NOV.S02.T001.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_N.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_M.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_S.S02.T001.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_E.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_W.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
EE_R.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
FI_R.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_CS.S02.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NE.S02.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DE_NW.S02.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LV_R.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
LT_R.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_N.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_M.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_S.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
NO_O.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_NW.S02.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_W.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_Central.S02.T002.DF_QUANT     1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_SE.S02.T002.DF_QUANT          1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
PL_S.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAR.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KOL.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_PSK.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_KAL.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_ARK.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_STP.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
RU_NOV.S02.T002.DF_QUANT         1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_N.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_M.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
SE_S.S02.T002.DF_QUANT           1.0001       1.005        1.01         1.02         1.04         1.08         1.12         1.16         1.2
DK_E.S01.T001.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
DK_W.S01.T001.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
EE_R.S01.T001.DF_PRICE           1            0.9721       0.9451       0.8928       0.7951       0.6243       0.4952       0.3964       0.3201
FI_R.S01.T001.DF_PRICE           1            0.9755       0.9517       0.9056       0.8186       0.6643       0.5438       0.4486       0.3728
DE_CS.S01.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NE.S01.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NW.S01.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
LV_R.S01.T001.DF_PRICE           1            0.9697       0.9405       0.8841       0.7791       0.5976       0.4636       0.3633       0.2874
LT_R.S01.T001.DF_PRICE           1            0.9698       0.9406       0.8843       0.7794       0.5981       0.4641       0.3639       0.288
NO_N.S01.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_M.S01.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_S.S01.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_O.S01.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
PL_NW.S01.T001.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_W.S01.T001.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_Central.S01.T001.DF_PRICE     1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_SE.S01.T001.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_S.S01.T001.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
RU_KAR.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KOL.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_PSK.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KAL.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_ARK.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_STP.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_NOV.S01.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
SE_N.S01.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_M.S01.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_S.S01.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
DK_E.S01.T002.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
DK_W.S01.T002.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
EE_R.S01.T002.DF_PRICE           1            0.9721       0.9451       0.8928       0.7951       0.6243       0.4952       0.3964       0.3201
FI_R.S01.T002.DF_PRICE           1            0.9755       0.9517       0.9056       0.8186       0.6643       0.5438       0.4486       0.3728
DE_CS.S01.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NE.S01.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NW.S01.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
LV_R.S01.T002.DF_PRICE           1            0.9697       0.9405       0.8841       0.7791       0.5976       0.4636       0.3633       0.2874
LT_R.S01.T002.DF_PRICE           1            0.9698       0.9406       0.8843       0.7794       0.5981       0.4641       0.3639       0.288
NO_N.S01.T002.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_M.S01.T002.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_S.S01.T002.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_O.S01.T002.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
PL_NW.S01.T002.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_W.S01.T002.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_Central.S01.T002.DF_PRICE     1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_SE.S01.T002.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_S.S01.T002.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
RU_KAR.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KOL.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_PSK.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KAL.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_ARK.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_STP.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_NOV.S01.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
SE_N.S01.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_M.S01.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_S.S01.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
DK_E.S02.T001.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
DK_W.S02.T001.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
EE_R.S02.T001.DF_PRICE           1            0.9721       0.9451       0.8928       0.7951       0.6243       0.4952       0.3964       0.3201
FI_R.S02.T001.DF_PRICE           1            0.9755       0.9517       0.9056       0.8186       0.6643       0.5438       0.4486       0.3728
DE_CS.S02.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NE.S02.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NW.S02.T001.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
LV_R.S02.T001.DF_PRICE           1            0.9697       0.9405       0.8841       0.7791       0.5976       0.4636       0.3633       0.2874
LT_R.S02.T001.DF_PRICE           1            0.9698       0.9406       0.8843       0.7794       0.5981       0.4641       0.3639       0.288
NO_N.S02.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_M.S02.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_S.S02.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
NO_O.S02.T001.DF_PRICE           1            0.9753       0.9513       0.9047       0.817        0.6616       0.5404       0.445        0.3691
PL_NW.S02.T001.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_W.S02.T001.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_Central.S02.T001.DF_PRICE     1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_SE.S02.T001.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_S.S02.T001.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
RU_KAR.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KOL.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_PSK.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KAL.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_ARK.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_STP.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_NOV.S02.T001.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
SE_N.S02.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_M.S02.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_S.S02.T001.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
DK_E.S02.T002.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
DK_W.S02.T002.DF_PRICE           1            0.9183       0.8437       0.7072       0.4806       0.1786       0.0705       0.0294       0.0128
EE_R.S02.T002.DF_PRICE           1            0.9721       0.9451       0.8928       0.7951       0.6243       0.4952       0.3964       0.3201
FI_R.S02.T002.DF_PRICE           1            0.9755       0.9517       0.9056       0.8186       0.6643       0.5438       0.4486       0.3728
DE_CS.S02.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NE.S02.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
DE_NW.S02.T002.DF_PRICE          1            0.9648       0.931        0.8661       0.7466       0.5445       0.4025       0.3013       0.2282
LV_R.S02.T002.DF_PRICE           1            0.9697       0.9405       0.8841       0.7791       0.5976       0.4636       0.3633       0.2874
LT_R.S02.T002.DF_PRICE           1            0.9698       0.9406       0.8843       0.7794       0.5981       0.4641       0.3639       0.288
NO_N.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
NO_M.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
NO_S.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
NO_O.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
PL_NW.S02.T002.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_W.S02.T002.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_Central.S02.T002.DF_PRICE     1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_SE.S02.T002.DF_PRICE          1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
PL_S.S02.T002.DF_PRICE           1            0.9753       0.9514       0.9049       0.8174       0.6623       0.5413       0.446        0.3701
RU_KAR.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KOL.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_PSK.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_KAL.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_ARK.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_STP.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
RU_NOV.S02.T002.DF_PRICE         1            0.9753       0.9513       0.9047       0.8169       0.6615       0.5403       0.4448       0.3689
SE_N.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_M.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478
SE_S.S02.T002.DF_PRICE           1            0.9739       0.9487       0.8997       0.8077       0.6457       0.521        0.424        0.3478


+

                            DEF_D2_9     DEF_D2_8     DEF_D2_7     DEF_D2_6     DEF_D2_5     DEF_D2_4     DEF_D2_3     DEF_D2_2     DEF_D2_1
DK_E.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_W.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
EE_R.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
FI_R.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DE_CS.S01.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NE.S01.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NW.S01.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
LV_R.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
LT_R.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_N.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_M.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_S.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_O.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_NW.S01.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_W.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_Central.S01.T001.DF_QUANT    50           40           30           20           10           5            3            2            1
PL_SE.S01.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_S.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
RU_KAR.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KOL.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_PSK.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KAL.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_ARK.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_STP.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_NOV.S01.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
SE_N.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_M.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_S.S01.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_E.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_W.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
EE_R.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
FI_R.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DE_CS.S01.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NE.S01.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NW.S01.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
LV_R.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
LT_R.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_N.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_M.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_S.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_O.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_NW.S01.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_W.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_Central.S01.T002.DF_QUANT    50           40           30           20           10           5            3            2            1
PL_SE.S01.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_S.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
RU_KAR.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KOL.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_PSK.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KAL.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_ARK.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_STP.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_NOV.S01.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
SE_N.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_M.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_S.S01.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_E.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_W.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
EE_R.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
FI_R.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DE_CS.S02.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NE.S02.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NW.S02.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
LV_R.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
LT_R.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_N.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_M.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_S.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_O.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_NW.S02.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_W.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_Central.S02.T001.DF_QUANT    50           40           30           20           10           5            3            2            1
PL_SE.S02.T001.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_S.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
RU_KAR.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KOL.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_PSK.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KAL.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_ARK.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_STP.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_NOV.S02.T001.DF_QUANT        50           40           30           20           10           5            3            2            1
SE_N.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_M.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_S.S02.T001.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_E.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_W.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
EE_R.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
FI_R.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DE_CS.S02.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NE.S02.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
DE_NW.S02.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
LV_R.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
LT_R.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_N.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_M.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_S.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
NO_O.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_NW.S02.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_W.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
PL_Central.S02.T002.DF_QUANT    50           40           30           20           10           5            3            2            1
PL_SE.S02.T002.DF_QUANT         50           40           30           20           10           5            3            2            1
PL_S.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
RU_KAR.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KOL.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_PSK.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_KAL.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_ARK.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_STP.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
RU_NOV.S02.T002.DF_QUANT        50           40           30           20           10           5            3            2            1
SE_N.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_M.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
SE_S.S02.T002.DF_QUANT          50           40           30           20           10           5            3            2            1
DK_E.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_W.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
EE_R.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
FI_R.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DE_CS.S01.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NE.S01.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NW.S01.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
LV_R.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
LT_R.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_N.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_M.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_S.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_O.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_NW.S01.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_W.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_Central.S01.T001.DF_PRICE    1000         500          400          300          200          100          50           25           1
PL_SE.S01.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_S.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
RU_KAR.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KOL.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_PSK.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KAL.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_ARK.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_STP.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_NOV.S01.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
SE_N.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_M.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_S.S01.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_E.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_W.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
EE_R.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
FI_R.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
DE_CS.S01.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NE.S01.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NW.S01.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
LV_R.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
LT_R.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_N.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_M.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_S.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_O.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_NW.S01.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_W.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_Central.S01.T002.DF_PRICE    1000         500          400          300          200          100          50           25           1
PL_SE.S01.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_S.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
RU_KAR.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KOL.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_PSK.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KAL.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_ARK.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_STP.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_NOV.S01.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
SE_N.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_M.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_S.S01.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_E.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_W.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
EE_R.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
FI_R.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DE_CS.S02.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NE.S02.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NW.S02.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
LV_R.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
LT_R.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_N.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_M.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_S.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_O.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_NW.S02.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_W.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_Central.S02.T001.DF_PRICE    1000         500          400          300          200          100          50           25           1
PL_SE.S02.T001.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_S.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
RU_KAR.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KOL.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_PSK.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KAL.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_ARK.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_STP.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_NOV.S02.T001.DF_PRICE        1000         500          400          300          200          100          50           25           1
SE_N.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_M.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_S.S02.T001.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_E.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
DK_W.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
EE_R.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
FI_R.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
DE_CS.S02.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NE.S02.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
DE_NW.S02.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
LV_R.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
LT_R.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_N.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_M.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_S.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
NO_O.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_NW.S02.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_W.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
PL_Central.S02.T002.DF_PRICE    1000         500          400          300          200          100          50           25           1
PL_SE.S02.T002.DF_PRICE         1000         500          400          300          200          100          50           25           1
PL_S.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
RU_KAR.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KOL.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_PSK.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_KAL.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_ARK.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_STP.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
RU_NOV.S02.T002.DF_PRICE        1000         500          400          300          200          100          50           25           1
SE_N.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_M.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1
SE_S.S02.T002.DF_PRICE          1000         500          400          300          200          100          50           25           1


+
                                DEF_U2_1     DEF_U2_2     DEF_U2_3     DEF_U2_4     DEF_U2_5     DEF_U2_6     DEF_U2_7     DEF_U2_8     DEF_U2_9
DK_E.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_W.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
EE_R.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
FI_R.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DE_CS.S01.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NE.S01.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NW.S01.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
LV_R.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
LT_R.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_N.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_M.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_S.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_O.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_NW.S01.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_W.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_Central.S01.T001.DF_QUANT        1            2            3            4            5            10           20           30           40
PL_SE.S01.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_S.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
RU_KAR.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KOL.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_PSK.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KAL.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_ARK.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_STP.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_NOV.S01.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
SE_N.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_M.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_S.S01.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_E.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_W.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
EE_R.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
FI_R.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DE_CS.S01.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NE.S01.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NW.S01.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
LV_R.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
LT_R.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_N.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_M.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_S.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_O.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_NW.S01.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_W.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_Central.S01.T002.DF_QUANT        1            2            3            4            5            10           20           30           40
PL_SE.S01.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_S.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
RU_KAR.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KOL.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_PSK.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KAL.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_ARK.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_STP.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_NOV.S01.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
SE_N.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_M.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_S.S01.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_E.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_W.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
EE_R.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
FI_R.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DE_CS.S02.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NE.S02.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NW.S02.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
LV_R.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
LT_R.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_N.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_M.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_S.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_O.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_NW.S02.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_W.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_Central.S02.T001.DF_QUANT        1            2            3            4            5            10           20           30           40
PL_SE.S02.T001.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_S.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
RU_KAR.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KOL.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_PSK.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KAL.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_ARK.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_STP.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_NOV.S02.T001.DF_QUANT            1            2            3            4            5            10           20           30           40
SE_N.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_M.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_S.S02.T001.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_E.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_W.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
EE_R.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
FI_R.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DE_CS.S02.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NE.S02.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
DE_NW.S02.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
LV_R.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
LT_R.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_N.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_M.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_S.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
NO_O.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_NW.S02.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_W.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
PL_Central.S02.T002.DF_QUANT        1            2            3            4            5            10           20           30           40
PL_SE.S02.T002.DF_QUANT             1            2            3            4            5            10           20           30           40
PL_S.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
RU_KAR.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KOL.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_PSK.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_KAL.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_ARK.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_STP.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
RU_NOV.S02.T002.DF_QUANT            1            2            3            4            5            10           20           30           40
SE_N.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_M.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
SE_S.S02.T002.DF_QUANT              1            2            3            4            5            10           20           30           40
DK_E.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_W.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
EE_R.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
FI_R.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_CS.S01.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NE.S01.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NW.S01.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LV_R.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LT_R.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_N.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_M.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_S.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_O.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_NW.S01.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_W.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_Central.S01.T001.DF_PRICE        1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_SE.S01.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_S.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAR.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KOL.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_PSK.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAL.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_ARK.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_STP.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_NOV.S01.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_N.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_M.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_S.S01.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_E.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_W.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
EE_R.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
FI_R.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_CS.S01.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NE.S01.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NW.S01.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LV_R.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LT_R.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_N.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_M.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_S.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_O.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_NW.S01.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_W.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_Central.S01.T002.DF_PRICE        1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_SE.S01.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_S.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAR.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KOL.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_PSK.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAL.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_ARK.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_STP.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_NOV.S01.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_N.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_M.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_S.S01.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_E.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_W.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
EE_R.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
FI_R.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_CS.S02.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NE.S02.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NW.S02.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LV_R.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LT_R.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_N.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_M.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_S.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_O.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_NW.S02.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_W.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_Central.S02.T001.DF_PRICE        1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_SE.S02.T001.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_S.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAR.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KOL.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_PSK.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAL.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_ARK.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_STP.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_NOV.S02.T001.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_N.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_M.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_S.S02.T001.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_E.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DK_W.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
EE_R.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
FI_R.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_CS.S02.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NE.S02.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
DE_NW.S02.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LV_R.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
LT_R.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_N.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_M.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_S.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
NO_O.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_NW.S02.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_W.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_Central.S02.T002.DF_PRICE        1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_SE.S02.T002.DF_PRICE             1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
PL_S.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAR.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KOL.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_PSK.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_KAL.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_ARK.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_STP.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
RU_NOV.S02.T002.DF_PRICE            1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_N.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_M.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
SE_S.S02.T002.DF_PRICE              1            0.5          0.25         0.1          0.05         0.01         0.005        0.001        0.0005
*/
;

/*
* LARS20070920: Changed index in assignment from S and T to SSS and TTT to ensure that timeaggr.inc does not fail
* See info on the Global timeaggr function in the balopt.opt file.
DEF_STEPS(IR,SSS,TTT,DF_QP,DEF_U1)$(DEF_STEPS(IR,SSS,TTT,DF_QP,DEF_U1) EQ 0) = DEF_STEPS(IR,'S01','T001',DF_QP,DEF_U1);
DEF_STEPS(IR,SSS,TTT,DF_QP,DEF_D1)$(DEF_STEPS(IR,SSS,TTT,DF_QP,DEF_D1) EQ 0) = DEF_STEPS(IR,'S01','T001',DF_QP,DEF_D1);
*/

* PARAMETER DEFP_CALIB is used to calibrate the price side of the electricity demand
* function in order to get demand consistent for a base year.
* Unit: EUR90/MWh.


* PARAMETER DHF_STEPS describes the elastic electricity demands
* in relative terms, by quantifying the steps. Compare PARAMETER DEF_STEPS.
* Unit: (none).
TABLE  DHF_STEPS(AAA,SSS,TTT,DF_QP,DHF)  'Elastic heat demands'
                                   DHF_D_9       DHF_D_8       DHF_D_7       DHF_D_6       DHF_D_5       DHF_D_4       DHF_D_3       DHF_D_2       DHF_D_1
$ontext
DK_CA_Kbh.S01.T001.DF_QUANT        0.8200        0.8400        0.8800        0.9200        0.9600        0.9800        0.9900        0.9995        1.0000
DK_CA_Aarhus.S01.T001.DF_QUANT        0.8200        0.8400        0.8800        0.9200        0.9600        0.9800        0.9900        0.9995        1.0000
DK_CA_Kbh.S01.T001.DF_PRICE        3.0893        2.6698        2.0589        1.6087        1.2731        1.1289        1.0621        1.0031        1.0000
DK_CA_Aarhus.S01.T001.DF_PRICE        3.0893        2.6698        2.0589        1.6087        1.2731        1.1289        1.0621        1.0031        1.0000
+
                                  DHF_U_1        DHF_U_2       DHF_U_3       DHF_U_4       DHF_U_5       DHF_U_6       DHF_U_7       DHF_U_8       DHF_U_9
DK_CA_Kbh.S01.T001.DF_QUANT        1.0000        1.0005        1.0100        1.0200        1.0400        1.0800        1.1200        1.1600        1.2000
DK_CA_Aarhus.S01.T001.DF_QUANT        1.0000        1.0005        1.0100        1.0200        1.0400        1.0800        1.1200        1.1600        1.2000
DK_CA_Kbh.S01.T001.DF_PRICE        1.0000        0.9969        0.9384        0.8813        0.7760        0.5971        0.4702        0.3789        0.3123
DK_CA_Aarhus.S01.T001.DF_PRICE        1.0000        0.9969        0.9384        0.8813        0.7760        0.5971        0.4702        0.3789        0.3123
$offtext
;


* PARAMETER DEFP_CALIB is used to calibrate the price side
* of the electricity demand function
* in order to get consumptions consistent for a base year.
* Unit: Money/MWh.
* Table DEFP_CALIB was created in Balmorel version 2.14 Alpha (november 2007)
* 12/14/09 21:54:07

TABLE DEFP_CALIB(RRR,SSS,TTT)
                        T001        T002        T003        T004        T005        T006        T007
DK_E.S01                0           0           0           0           0           0           0
;





* PARAMETER DHFP_CALIB is used to calibrate the price side
* of the heat demand function
* in order to get consumptions consistent for a base year.
* Unit: Money/MWh.
* Table DHFP_CALIB was created in Balmorel version 2.14 Alpha (november 2007)
* 12/14/09 21:54:07

* NOTE: The calibration code for heat has not been made,
* because presently heat demand is assumed inelastic.

TABLE DHFP_CALIB(AAA,SSS,TTT)

                        T001        T002        T003        T004        T005        T006        T007
DK_CA_Kbh.S01           0           0           0           0           0           0           0
;
