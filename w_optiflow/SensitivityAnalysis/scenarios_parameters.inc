* ------------------------------------------------------------------------------
*Scen_HeatBiorefinery_minus50/Scen_HeatBiorefinery_minus100    "Available excess heat from biorefineries is decreased, e.g. due to location of them abroad"
*Scen_FastNuclearPhaseOut                                      "Faster nuclear phase-out"
* ------------------------------------------------------------------------------

PARAMETER GKFX_Scenario(scenarios,YYY,AAA,GGG) 'Update in capacities in for excess heat from biorefineries and nuclear capacity for some scenarios'
/
*W I N D    E N E R G Y    S C E N A R I O
Scen_HeatBiorefinery_minus50    .    2025   .   DK_E_Large       .   Biofuel_SURPLUS_H    11.7
Scen_HeatBiorefinery_minus50    .    2025   .   DK_W_Large       .   Biofuel_SURPLUS_H    11.7
Scen_HeatBiorefinery_minus50    .    2030   .   DK_E_Large       .   Biofuel_SURPLUS_H    22.1
Scen_HeatBiorefinery_minus50    .    2030   .   DK_W_Large       .   Biofuel_SURPLUS_H    24.5
Scen_HeatBiorefinery_minus50    .    2035   .   DK_E_Large       .   Biofuel_SURPLUS_H    32.3
Scen_HeatBiorefinery_minus50    .    2035   .   DK_W_Large       .   Biofuel_SURPLUS_H    37.7
Scen_HeatBiorefinery_minus50    .    2040   .   DK_E_Large       .   Biofuel_SURPLUS_H    65.0
Scen_HeatBiorefinery_minus50    .    2040   .   DK_E_Medium      .   Biofuel_SURPLUS_H    2.2
Scen_HeatBiorefinery_minus50    .    2040   .   DK_W_Large       .   Biofuel_SURPLUS_H    74.5
Scen_HeatBiorefinery_minus50    .    2040   .   DK_W_Medium      .   Biofuel_SURPLUS_H    2.7
Scen_HeatBiorefinery_minus50    .    2045   .   DK_E_Large       .   Biofuel_SURPLUS_H    96.8
Scen_HeatBiorefinery_minus50    .    2045   .   DK_E_Medium      .   Biofuel_SURPLUS_H    5.3
Scen_HeatBiorefinery_minus50    .    2045   .   DK_W_Large       .   Biofuel_SURPLUS_H    109.9
Scen_HeatBiorefinery_minus50    .    2045   .   DK_W_Medium      .   Biofuel_SURPLUS_H    6.6
Scen_HeatBiorefinery_minus50    .    2050   .   DK_E_Large       .   Biofuel_SURPLUS_H    128.5
Scen_HeatBiorefinery_minus50    .    2050   .   DK_E_Medium      .   Biofuel_SURPLUS_H    8.7
Scen_HeatBiorefinery_minus50    .    2050   .   DK_W_Large       .   Biofuel_SURPLUS_H    144.9
Scen_HeatBiorefinery_minus50    .    2050   .   DK_W_Medium      .   Biofuel_SURPLUS_H    10.8


Scen_HeatBiorefinery_minus100    .    2025   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2025   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2030   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2030   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2035   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2035   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2040   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2040   .   DK_E_Medium      .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2040   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2040   .   DK_W_Medium      .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2045   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2045   .   DK_E_Medium      .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2045   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2045   .   DK_W_Medium      .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2050   .   DK_E_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2050   .   DK_E_Medium      .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2050   .   DK_W_Large       .   Biofuel_SURPLUS_H   EPS
Scen_HeatBiorefinery_minus100    .    2050   .   DK_W_Medium      .   Biofuel_SURPLUS_H   EPS

*Nuclear Capacity
Scen_FastNuclearPhaseOut    .    2014    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            2750
Scen_FastNuclearPhaseOut    .    2020    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            4350
Scen_FastNuclearPhaseOut    .    2025    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            4350
Scen_FastNuclearPhaseOut    .    2030    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            3855
Scen_FastNuclearPhaseOut    .    2035    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            3855
Scen_FastNuclearPhaseOut    .    2040    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            2480
Scen_FastNuclearPhaseOut    .    2045    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            2480
Scen_FastNuclearPhaseOut    .    2050    .    FI_R_Rural        .    FI_R_Rural_NU-C8-NU            1600

Scen_FastNuclearPhaseOut    .    2014    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            9568
Scen_FastNuclearPhaseOut    .    2020    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            9568
Scen_FastNuclearPhaseOut    .    2025    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            6727
Scen_FastNuclearPhaseOut    .    2030    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            6727
Scen_FastNuclearPhaseOut    .    2035    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            EPS
Scen_FastNuclearPhaseOut    .    2040    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            EPS
Scen_FastNuclearPhaseOut    .    2045    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            EPS
Scen_FastNuclearPhaseOut    .    2050    .    SE_M_Rural        .    SE_M_Rural_NU-C8-NU            EPS
/;

PARAMETER IGKFX_Y_Scenario(scenarios,AAA,GGG) 'Installed exogenous capacity in the year of simulation';
LOOP(Y,IGKFX_Y_Scenario(scenarios,IA,G)=GKFX_Scenario(scenarios,Y,IA,G););

PARAMETER IGKFXYMAX_Scenario(scenarios,AAA,GGG) 'Maximum Installed exogenous capacity in the year of simulation';
IGKFXYMAX_Scenario(scenarios,IA,G)$(IGKFX_Y_Scenario(scenarios,IA,G))=IGKFX_Y_Scenario(scenarios,IA,G);

* ------------------------------------------------------------------------------
*Scen_WPprice_plus25/Scen_WPprice_minus25    "Wood Pellet price is 25% higher/lower than in the BASE scenario"
* ------------------------------------------------------------------------------
PARAMETER FUELPRICE_Scenario(scenarios,YYY,AAA,FFF) 'Fuel price change for the different scenarios'
/
Scen_WPprice_plus25    .    2014        .        DK_CA_Kbh        .        WOOD_PELLETS      6.469
Scen_WPprice_plus25    .    2020        .        DK_CA_Kbh        .        WOOD_PELLETS      6.420
Scen_WPprice_plus25    .    2025        .        DK_CA_Kbh        .        WOOD_PELLETS      7.165
Scen_WPprice_plus25    .    2030        .        DK_CA_Kbh        .        WOOD_PELLETS      7.909
Scen_WPprice_plus25    .    2035        .        DK_CA_Kbh        .        WOOD_PELLETS      8.575
Scen_WPprice_plus25    .    2040        .        DK_CA_Kbh        .        WOOD_PELLETS      9.240
Scen_WPprice_plus25    .    2045        .        DK_CA_Kbh        .        WOOD_PELLETS      9.444
Scen_WPprice_plus25    .    2050        .        DK_CA_Kbh        .        WOOD_PELLETS      9.649

Scen_WPprice_minus25    .    2014        .        DK_CA_Kbh        .        WOOD_PELLETS      3.881
Scen_WPprice_minus25    .    2020        .        DK_CA_Kbh        .        WOOD_PELLETS      3.852
Scen_WPprice_minus25    .    2025        .        DK_CA_Kbh        .        WOOD_PELLETS      4.299
Scen_WPprice_minus25    .    2030        .        DK_CA_Kbh        .        WOOD_PELLETS      4.745
Scen_WPprice_minus25    .    2035        .        DK_CA_Kbh        .        WOOD_PELLETS      5.145
Scen_WPprice_minus25    .    2040        .        DK_CA_Kbh        .        WOOD_PELLETS      5.544
Scen_WPprice_minus25    .    2045        .        DK_CA_Kbh        .        WOOD_PELLETS      5.666
Scen_WPprice_minus25    .    2050        .        DK_CA_Kbh        .        WOOD_PELLETS      5.789
/;
FUELPRICE_Scenario(scenarios,Y,IA,FFF)$(FUELPRICE_Scenario(scenarios,Y,'DK_CA_Kbh',FFF))=FUELPRICE_Scenario(scenarios,Y,'DK_CA_Kbh',FFF);

PARAMETER IFUELP_Y_Scenario(scenarios,AAA,FFF) 'Fuel price for the different scenarios in the year of simulation';
LOOP(Y,IFUELP_Y_Scenario(scenarios,IA,FFF)=FUELPRICE_Scenario(scenarios,Y,IA,FFF););


* ------------------------------------------------------------------------------
*Scen_XKRATE_DK_75/Scen_XKRATE_DK_50    "Decrease of the available capacity for transmission in DK"
* ------------------------------------------------------------------------------

PARAMETER IXKRATE_Scenario(scenarios,IRRRE,IRRRI,SSS,TTT) 'Availability of transmission lines in Denmark';

IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_E','DE_NE',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_E','SE_S',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DE_NE','DK_E',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','SE_S','DK_E',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_W','DE_CS',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_W','DE_NW',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_W','NO_S',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DK_W','SE_M',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DE_CS','DK_W',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','DE_NW','DK_W',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','NO_S','DK_W',S,T)=0.75;
IXKRATE_Scenario('Scen_XKRATE_DK_75','SE_M','DK_W',S,T)=0.75;

IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_E','DE_NE',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_E','SE_S',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DE_NE','DK_E',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','SE_S','DK_E',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_W','DE_CS',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_W','DE_NW',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_W','NO_S',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DK_W','SE_M',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DE_CS','DK_W',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','DE_NW','DK_W',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','NO_S','DK_W',S,T)=0.5;
IXKRATE_Scenario('Scen_XKRATE_DK_50','SE_M','DK_W',S,T)=0.5;

* ------------------------------------------------------------------------------
*Scen_XMAXINV_minus50/Scen_XMAXINV_minus100 "Limit investments in transmission capacity"
* ------------------------------------------------------------------------------
Parameter XMAXINV_Scenario(scenarios,IYALIAS,YYY,IRRRE,IRRRI) 'Maximum investment in transmission capacity for the different scenarios';
XMAXINV_Scenario('Scen_XMAXINV_minus50',IYALIAS,Y,IRE,IRI)$(XMAXINV(IYALIAS,Y,IRE,IRI))=0.5*XMAXINV(IYALIAS,Y,IRE,IRI);
XMAXINV_Scenario('Scen_XMAXINV_minus100',IYALIAS,Y,IRE,IRI)$(XMAXINV(IYALIAS,Y,IRE,IRI))=Eps;

Parameter IXMAXINV_Y_Scenario(scenarios,IYALIAS,IRRRE,IRRRI) 'Maximum investment in transmission capacity in the current simulation year for the different scenarios';
LOOP(Y,IXMAXINV_Y_Scenario(scenarios,IYALIAS,IRE,IRI)=XMAXINV_Scenario(scenarios,IYALIAS,Y,IRE,IRI););

* ------------------------------------------------------------------------------
*Scen_CAPEX_WND_high/Scen_CAPEX_WND_low    "CAPEX of wind turbines in their high/low range of uncertainty"
* ------------------------------------------------------------------------------

Parameter GDATA_Scenario(scenarios,GGG,GDATASET) 'Changes in CAPEX of wind turbines for the different scenarios';
GDATA_Scenario('Scen_CAPEX_WND_high',IGWNDON,'GDINVCOST0')=1.15*GDATA(IGWNDON,'GDINVCOST0');
GDATA_Scenario('Scen_CAPEX_WND_high',IGWNDOFF,'GDINVCOST0')=1.22*GDATA(IGWNDOFF,'GDINVCOST0');
GDATA_Scenario('Scen_CAPEX_WND_low',IGWNDON,'GDINVCOST0')=0.85*GDATA(IGWNDON,'GDINVCOST0');
GDATA_Scenario('Scen_CAPEX_WND_low',IGWNDOFF,'GDINVCOST0')=0.78*GDATA(IGWNDOFF,'GDINVCOST0');

Parameter GINVCOST_Scenario(scenarios,AAA,GGG) ' Changes in investment costs for the different scenarios';
GINVCOST_Scenario(scenarios,IA,G)$((SUM(Y,GKFX(Y,IA,G)) OR AGKN(IA,G)) AND GDATA_Scenario(scenarios,G,'GDINVCOST0'))= GDATA_Scenario(scenarios,G,'GDINVCOST0');

* ------------------------------------------------------------------------------
*Scen_WNDFLH_high/Scen_WNDFLH_low    "Full load hours of operation of wind turbines in DK are 10% higher/lower than the average"
* ------------------------------------------------------------------------------

Parameter WNDFLH_Scenarios(scenarios,AAA) 'Change of the full load hours of operation of wind turbines in the different scenarios';
WNDFLH_Scenarios('Scen_WNDFLH_high',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=1.1*WNDFLH(IA);
WNDFLH_Scenarios('Scen_WNDFLH_low',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=0.90*WNDFLH(IA);


* ------------------------------------------------------------------------------
*Scen_SOLFLH_high/Scen_SOLFLH_low    "Full load hours of operation of PV and solar collectors in DK  are 10% higher/lower than the average"
* ------------------------------------------------------------------------------

Parameter SOLEFLH_Scenarios(scenarios,AAA) 'Change of the full load hours of operation of PV in the different scenarios';
SOLEFLH_Scenarios('Scen_SOLFLH_high',IA)$(SUM(IGSOLE,IAGK_Y(IA,IGSOLE)+IAGKN(IA,IGSOLE)) AND ICA('DENMARK',IA))=1.1*SOLEFLH(IA);
SOLEFLH_Scenarios('Scen_SOLFLH_low',IA)$(SUM(IGSOLE,IAGK_Y(IA,IGSOLE)+IAGKN(IA,IGSOLE)) AND ICA('DENMARK',IA))=0.90*SOLEFLH(IA);

Parameter SOLHFLH_Scenarios(scenarios,AAA) 'Change of the full load hours of operation of PV in the different scenarios';
SOLHFLH_Scenarios('Scen_SOLFLH_high',IA)$(SUM(IGSOLH,IAGK_Y(IA,IGSOLH)+IAGKN(IA,IGSOLH)) AND ICA('DENMARK',IA))=1.1*SOLHFLH(IA);
SOLHFLH_Scenarios('Scen_SOLFLH_low',IA)$(SUM(IGSOLH,IAGK_Y(IA,IGSOLH)+IAGKN(IA,IGSOLH)) AND ICA('DENMARK',IA))=0.90*SOLHFLH(IA);

* ------------------------------------------------------------------------------
*Scen_HYDRO_high/Scen_HYDRO_low       "Availability of hydropower is 33% higher/lower for run of river and 20% higher/lower for dams"
* ------------------------------------------------------------------------------

Parameter WTRRRFLH_Scenarios(scenarios,AAA) 'Change of the full load hours of operation of run-of-river in the different scenarios';
WTRRRFLH_Scenarios('Scen_HYDRO_high',IA)$(SUM(IGHYRR,IAGK_Y(IA,IGHYRR)+IAGKN(IA,IGHYRR)))=1.33*WTRRRFLH(IA);
WTRRRFLH_Scenarios('Scen_HYDRO_low',IA)$(SUM(IGHYRR,IAGK_Y(IA,IGHYRR)+IAGKN(IA,IGHYRR)))=0.67*WTRRRFLH(IA);

Parameter WTRRSFLH_Scenarios(scenarios,AAA) 'Change of the full load hours of operation of hydropower with reservoirs in the different scenarios';
WTRRSFLH_Scenarios('Scen_HYDRO_high',IA)$(SUM(IGHYRS,IAGK_Y(IA,IGHYRS)+IAGKN(IA,IGHYRS)))=1.2*WTRRSFLH(IA);
WTRRSFLH_Scenarios('Scen_HYDRO_low',IA)$(SUM(IGHYRS,IAGK_Y(IA,IGHYRS)+IAGKN(IA,IGHYRS)))=0.80*WTRRSFLH(IA);

Parameter IHYINF_S_Scenarios 'Internal parameter for hydropower plants with reservoir';
IHYINF_S_Scenarios(scenarios,IA,S)= ((WTRRSFLH_Scenarios(scenarios,IA) * WTRRSVAR_S(IA,S) * (IOF365*WEIGHT_S(S)/IWEIGHSUMS)) / IWTRRSSUM(IA))$IWTRRSSUM(IA);

$ontext
*B I O M A S S    S C E N A R I O
Scen_HeatBiorefinery_minus50    .    2025   .   DK_E_Large       .   Biofuel_SURPLUS_H    24.4
Scen_HeatBiorefinery_minus50    .    2025   .   DK_W_Large       .   Biofuel_SURPLUS_H    24.4
Scen_HeatBiorefinery_minus50    .    2030   .   DK_E_Large       .   Biofuel_SURPLUS_H    46.4
Scen_HeatBiorefinery_minus50    .    2030   .   DK_W_Large       .   Biofuel_SURPLUS_H    51.4
Scen_HeatBiorefinery_minus50    .    2035   .   DK_E_Large       .   Biofuel_SURPLUS_H    67.6
Scen_HeatBiorefinery_minus50    .    2035   .   DK_W_Large       .   Biofuel_SURPLUS_H    79.0
Scen_HeatBiorefinery_minus50    .    2040   .   DK_E_Large       .   Biofuel_SURPLUS_H    132.1
Scen_HeatBiorefinery_minus50    .    2040   .   DK_E_Medium      .   Biofuel_SURPLUS_H    4.4
Scen_HeatBiorefinery_minus50    .    2040   .   DK_W_Large       .   Biofuel_SURPLUS_H    151.3
Scen_HeatBiorefinery_minus50    .    2040   .   DK_W_Medium      .   Biofuel_SURPLUS_H    5.5
Scen_HeatBiorefinery_minus50    .    2045   .   DK_E_Large       .   Biofuel_SURPLUS_H    194.7
Scen_HeatBiorefinery_minus50    .    2045   .   DK_E_Medium      .   Biofuel_SURPLUS_H    10.7
Scen_HeatBiorefinery_minus50    .    2045   .   DK_W_Large       .   Biofuel_SURPLUS_H    221.2
Scen_HeatBiorefinery_minus50    .    2045   .   DK_W_Medium      .   Biofuel_SURPLUS_H    13.3
Scen_HeatBiorefinery_minus50    .    2050   .   DK_E_Large       .   Biofuel_SURPLUS_H    257.3
Scen_HeatBiorefinery_minus50    .    2050   .   DK_E_Medium      .   Biofuel_SURPLUS_H    17.4
Scen_HeatBiorefinery_minus50    .    2050   .   DK_W_Large       .   Biofuel_SURPLUS_H    290.2
Scen_HeatBiorefinery_minus50    .    2050   .   DK_W_Medium      .   Biofuel_SURPLUS_H    21.6
$offtext

