Parameter EPrice_RST_scen(scenarios,RRR,SSS,TTT)  'Electricity price per hour at a regional level (�2015/MWh)';
Parameter HPrice_AST_scen(scenarios,AAA,SSS,TTT)'Heat price per hour at an area level (�2015/MWh)';
Parameter EDemand_RST_scen(scenarios,EDemand_type,RRR,SSS,TTT) 'Elecitricity Demand at a regional level at a given time ST (MW)';
Parameter Edemand_CST_scen(scenarios,EDemand_type,CCC,SSS,TTT) 'Elecitricity Demand at a country level at a given time ST(MW)';
Parameter Edemand_R_scen(scenarios,EDemand_type,RRR) 'Annual Elecitricity Demand at a regional level (PJ/year)';
Parameter Edemand_C_scen(scenarios,EDemand_type,CCC) 'Annual Elecitricity Demand at a country level (PJ/year)';
Parameter Hdemand_AST_scen(scenarios,AAA,SSS,TTT) 'Heat Demand at an area level at a given time ST (MW)';
Parameter EPrice_R_scen(scenarios,RRR) 'Weighted average electricity price by consumption quantity per year at a regional level (� 2015/MWh)';
Parameter EPrice_CST_scen(scenarios,CCC,SSS,TTT) 'Weighted average electricity price by consumption quantity at a country level (� 2015/MWh)';
Parameter EPrice_C_scen(scenarios,CCC) 'Weighted average electricity price by consumption quantity per year at a country level (� 2015/MWh)';
Parameter HPrice_AS_scen(scenarios,AAA,SSS) 'Weighted average heat price by consumption quantity per week at an area level (� 2015/MWh)';
Parameter HPrice_A_scen(scenarios,AAA) 'Weighted average heat price by consumption quantity per year at an area level (� 2015/MWh)';
Parameter EProduction_RST_scen(scenarios,RRR,TECHTYPE,SSS,TTT) 'Electricity production at a regional level at a given time ST (MW)';
Parameter ETrade_RST_scen(scenarios,RRR,ELECTRADE,SSS,TTT) 'Electricity trade at a regional level at a given time ST (MW)';
Parameter Eproduction_CST_scen(scenarios,CCC,TECHTYPE,SSS,TTT) 'Electricity production at a country level at a given time ST (MW)';
Parameter ETrade_CST_scen(scenarios,CCC,ELECTRADE,SSS,TTT) 'Electricity trade at a country level at a given time ST (MW)';
Parameter Eproduction_R_scen(scenarios,RRR,TECHTYPE) 'Annual electricity production at a regional level (PJ/year)';
Parameter Eproduction_C_scen(scenarios,CCC,TECHTYPE) 'Annual electricity production at a country level (PJ/year)';
Parameter ETrade_R_scen(scenarios,RRR,ELECTRADE) 'Annual electricity trade at a regional level (PJ/year)';
Parameter ETrade_C_scen(scenarios,CCC,ELECTRADE) 'Annual electricity trade at a country level (PJ/year)';
Parameter Hproduction_AST_scen(scenarios,AAA,TECHTYPE,SSS,TTT) 'Heat production at an area level at a given time ST (MW)';
Parameter Hproduction_AS_scen(scenarios,AAA,TECHTYPE,SSS) 'Heat production at an area level per week (MWh)';
Parameter Hproduction_A_scen(scenarios,AAA,TECHTYPE) 'Annual heat production at an area level (PJ/year)';
Parameter Hproduction_CST_scen(scenarios,CCC,TECHTYPE,SSS,TTT) 'Heat production at a country level per week (MWh)';
Parameter Hproduction_CS_scen(scenarios,CCC,TECHTYPE,SSS) 'Heat production at a country level per week (MWh)';
Parameter Hproduction_C_scen(scenarios,CCC,TECHTYPE) 'Annual heat production at a country level (PJ/year)';
Parameter FuelConsumption_C_scen(scenarios,CCC,TECHTYPE)  'Annual fuel consumption at a country level per technology type (PJ/year)';
Parameter FuelConsumption_TOTAL_scen(scenarios,TECHTYPE)  'Annual fuel consumption in all the simulated countries per technology type (PJ/year)';
Parameter Elec_Capacity_scen(scenarios,CCC,CAPACITIES,TECHTYPE) 'Installed capacity for electricity production (MWelectricity)';
Parameter Heat_Capacity_scen(scenarios,CCC,CAPACITIES,TECHTYPE) 'Installed capacity for heat production (MWheat)';


EPrice_RST_scen(scenarios,IR,S,T)=MQEEQ_s(scenarios,IR,S,T)*MONEYCONVERT/IHOURSINST(S,T);

HPrice_AST_scen(scenarios,IA,S,T)=MQHEQ_s(scenarios,IA,S,T)*MONEYCONVERT/IHOURSINST(S,T);

EDemand_RST_scen(scenarios,"classic",IR,S,T)$(NOT (RETRANS(IR) OR RINDUS(IR)))=IDE_T_Y(IR,S,T);

EDemand_RST_scen(scenarios,"transport",IR,S,T)=SUM(RETRANS$IXKINI_Y(IR,RETRANS),IDE_T_Y(RETRANS,S,T));

EDemand_RST_scen(scenarios,"individual heating",IR,S,T)=SUM(IAGK_Y(IA,IGE)$((RRRAAA(IR,IA) AND (AINDHEAT(IA))) AND IGETOH(IGE)), LVGE_T_s(scenarios,IA,IGE,S,T))
                                        +SUM(IAGKN(IA,IGE)$((RRRAAA(IR,IA) AND (AINDHEAT(IA))) AND IGETOH(IGE)), LVGEN_T_s(scenarios,IA,IGE,S,T));

EDemand_RST_scen(scenarios,"process heating",IR,S,T)=SUM(RINDUS$IXKINI_Y(IR,RINDUS),IDE_T_Y(RINDUS,S,T));

EDemand_RST_scen(scenarios,"DH",IR,S,T)=SUM(IAGK_Y(IA,IGE)$((RRRAAA(IR,IA) AND (NOT AINDHEAT(IA))) AND IGETOH(IGE)), LVGE_T_s(scenarios,IA,IGE,S,T))
                        +SUM(IAGKN(IA,IGE)$((RRRAAA(IR,IA) AND (NOT AINDHEAT(IA))) AND IGETOH(IGE)), LVGEN_T_s(scenarios,IA,IGE,S,T));
$ifi %H2%==yes  EDemand_RST_scen(scenarios,"H2",IR,S,T)=SUM(IAGK_Y(IA,IGETOH2)$(RRRAAA(IR,IA)), LVGE_T_s(scenarios,IA,IGETOH2,S,T))+SUM(IAGKN(IA,IGETOH2)$(RRRAAA(IR,IA)), LVGEN_T_s(scenarios,IA,IGETOH2,S,T));

Edemand_CST_scen(scenarios,EDemand_type,C,S,T)=SUM(IR$CCCRRR(C,IR),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T));

Edemand_R_scen(scenarios,EDemand_type,IR)=SUM((S,T),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T)*IHOURSINST(S,T))*IOF0000001*IOF3P6;

Edemand_C_scen(scenarios,EDemand_type,C)=SUM((S,T),EDemand_CST_scen(scenarios,EDemand_type,C,S,T)*IHOURSINST(S,T))*IOF0000001*IOF3P6;

Hdemand_AST_scen(scenarios,IA,S,T)$(NOT AINDHEAT(IA))=IDH_T_Y(IA,S,T);

EPrice_R_scen(scenarios,IR)$(SUM((EDemand_type,S,T),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T)*IHOURSINST(S,T)))=SUM((EDemand_type,S,T),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T)*IHOURSINST(S,T)*EPrice_RST_scen(scenarios,IR,S,T))/SUM((EDemand_type,S,T),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T)*IHOURSINST(S,T));

EPrice_CST_scen(scenarios,C,S,T)=SUM((EDemand_type,IR)$CCCRRR(C,IR),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T)*EPrice_RST_scen(scenarios,IR,S,T))/SUM((EDemand_type,IR)$CCCRRR(C,IR),EDemand_RST_scen(scenarios,EDemand_type,IR,S,T));

EPrice_C_scen(scenarios,C)=SUM((EDemand_type,S,T),EDemand_CST_scen(scenarios,EDemand_type,C,S,T)*IHOURSINST(S,T)*EPrice_CST_scen(scenarios,C,S,T))/SUM((EDemand_type,S,T),EDemand_CST_scen(scenarios,EDemand_type,C,S,T)*IHOURSINST(S,T));

HPrice_AS_scen(scenarios,IA,S)$(SUM(T,Hdemand_AST_scen(scenarios,IA,S,T)))=SUM(T,HPrice_AST_scen(scenarios,IA,S,T)*Hdemand_AST_scen(scenarios,IA,S,T)*IHOURSINST(S,T))/SUM(T,Hdemand_AST_scen(scenarios,IA,S,T)*IHOURSINST(S,T));

HPrice_A_scen(scenarios,IA)$(SUM((S,T),Hdemand_AST_scen(scenarios,IA,S,T)))=SUM((S,T),HPrice_AST_scen(scenarios,IA,S,T)*Hdemand_AST_scen(scenarios,IA,S,T)*IHOURSINST(S,T))/SUM((S,T),Hdemand_AST_scen(scenarios,IA,S,T)*IHOURSINST(S,T));

EProduction_RST_scen(scenarios,IR,TECHTYPE,S,T)= SUM(IAGK_Y(IA,IGE)$((RRRAAA(IR,IA) AND (NOT AAAOFFSHORE(IA))) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE)), LVGE_T_s(scenarios,IA,IGE,S,T))
                                 +SUM(IAGKN(IA,IGE)$((RRRAAA(IR,IA) AND (NOT AAAOFFSHORE(IA))) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE)), LVGEN_T_s(scenarios,IA,IGE,S,T))
                                 +SUM(RRROFFSHORE$IXKINI_Y(RRROFFSHORE,IR),(SUM(IAGK_Y(IA,IGE)$((RRRAAA(RRROFFSHORE,IA) AND (AAAOFFSHORE(IA))) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE)), LVGE_T_s(scenarios,IA,IGE,S,T)))*(1-XLOSS(RRROFFSHORE,IR)))
                                 +SUM(RRROFFSHORE$IXKINI_Y(RRROFFSHORE,IR),(SUM(IAGKN(IA,IGE)$((RRRAAA(RRROFFSHORE,IA) AND (AAAOFFSHORE(IA))) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE)), LVGEN_T_s(scenarios,IA,IGE,S,T)))*(1-XLOSS(RRROFFSHORE,IR)));

ETrade_RST_scen(scenarios,IR,"Import",S,T)$((NOT RETRANS(IR)) AND (NOT RINDUS(IR)))=SUM(IRE$((IXKINI_Y(IRE,IR) OR IXKN(IRE,IR) OR IXKN(IR,IRE)) AND (NOT RRROFFSHORE(IRE))), LVX_T_s(scenarios,IRE,IR,S,T)*(1-XLOSS(IRE,IR)));

ETrade_RST_scen(scenarios,IR,"Export",S,T)$(NOT RRROFFSHORE(IR))= SUM(IRI$((IXKINI_Y(IR,IRI) OR IXKN(IR,IRI) OR IXKN(IRI,IR)) AND ((NOT RETRANS(IRI)) AND (NOT RINDUS(IRI)))),LVX_T_s(scenarios,IR,IRI,S,T));

ETrade_RST_scen(scenarios,IR,"Net Export",S,T)=ETrade_RST_scen(scenarios,IR,"Export",S,T)-ETrade_RST_scen(scenarios,IR,"Import",S,T);

Eproduction_CST_scen(scenarios,C,TECHTYPE,S,T)=SUM(IR$CCCRRR(C,IR),EProduction_RST_scen(scenarios,IR,TECHTYPE,S,T));

ETrade_CST_scen(scenarios,C,"Import",S,T)=SUM((IR,IRE)$(CCCRRR(C,IR) AND (NOT CCCRRR(C,IRE))AND (IXKINI_Y(IRE,IR) OR IXKN(IR,IRE) OR IXKN(IRE,IR)) AND (IXKINI_Y(IRE,IR) NE INF)), LVX_T_s(scenarios,IRE,IR,S,T)*(1-XLOSS(IRE,IR)));
ETrade_CST_scen(scenarios,C,"Export",S,T)=SUM((IR,IRI)$(CCCRRR(C,IR) AND (NOT CCCRRR(C,IRI))AND (IXKINI_Y(IR,IRI) OR IXKN(IRI,IR) OR IXKN(IR,IRI)) AND (IXKINI_Y(IR,IRI) NE INF)), LVX_T_s(scenarios,IR,IRI,S,T));
ETrade_CST_scen(scenarios,C,"Net Export",S,T)=ETrade_CST_scen(scenarios,C,"Export",S,T)-ETrade_CST_scen(scenarios,C,"Import",S,T);

EProduction_R_scen(scenarios,IR,TECHTYPE)=(SUM((S,T),EProduction_RST_scen(scenarios,IR,TECHTYPE,S,T)*IHOURSINST(S,T)))*IOF0000001*IOF3P6;

EProduction_C_scen(scenarios,C,TECHTYPE)= (SUM((S,T),EProduction_CST_scen(scenarios,C,TECHTYPE,S,T)*IHOURSINST(S,T)))*IOF0000001*IOF3P6;

ETrade_R_scen(scenarios,IR,ELECTRADE)=(SUM((S,T),ETrade_RST_scen(scenarios,IR,ELECTRADE,S,T)*IHOURSINST(S,T)))*IOF0000001*IOF3P6;

ETrade_C_scen(scenarios,C,ELECTRADE)=(SUM((S,T),ETrade_CST_scen(scenarios,C,ELECTRADE,S,T)*IHOURSINST(S,T)))*IOF0000001*IOF3P6;

EProduction_RST_scen(scenarios,IR,"Net Trade",S,T)=-ETrade_RST_scen(scenarios,IR,"Net Export",S,T);
Eproduction_CST_scen(scenarios,C,"Net Trade",S,T)=-ETrade_CST_scen(scenarios,C,"Net Export",S,T);

Hproduction_AST_scen(scenarios,IA,TECHTYPE,S,T)$(NOT AINDHEAT(IA))=
                                  SUM(IGBPR$(IAGK_Y(IA,IGBPR) AND GTECHTYPE(IGBPR,TECHTYPE)),LVGH_T_s(scenarios,IA,IGBPR,S,T))
                                + SUM(IGBPR$(IAGKN(IA,IGBPR) AND GTECHTYPE(IGBPR,TECHTYPE)),LVGHN_T_s(scenarios,IA,IGBPR,S,T))
                                + SUM(IGEXT$(IAGK_Y(IA,IGEXT) AND GTECHTYPE(IGEXT,TECHTYPE)),LVGH_T_s(scenarios,IA,IGEXT,S,T))
                                + SUM(IGEXT$(IAGKN(IA,IGEXT) AND GTECHTYPE(IGEXT,TECHTYPE)),LVGHN_T_s(scenarios,IA,IGEXT,S,T))
                                + SUM(IGHH$(IAGK_Y(IA,IGHH) AND GTECHTYPE(IGHH,TECHTYPE)),LVGH_T_s(scenarios,IA,IGHH,S,T))
                                + SUM(IGHH$(IAGKN(IA,IGHH) AND GTECHTYPE(IGHH,TECHTYPE)),LVGHN_T_s(scenarios,IA,IGHH,S,T))
                                + SUM(IGETOH$(IAGK_Y(IA,IGETOH) AND GTECHTYPE(IGETOH,TECHTYPE)),LVGH_T_s(scenarios,IA,IGETOH,S,T))
                                + SUM(IGETOH$(IAGKN(IA,IGETOH) AND GTECHTYPE(IGETOH,TECHTYPE)),LVGHN_T_s(scenarios,IA,IGETOH,S,T))
$ifi %H2%==yes                  +SUM(IGETOH2$(IAGK_Y(IA,IGETOH2) AND GTECHTYPE(IGETOH2,TECHTYPE)), LVGH_T_s(scenarios,IA,IGETOH2,S,T))
$ifi %H2%==yes                  +SUM(IGETOH2$(IAGKN(IA,IGETOH2) AND GTECHTYPE(IGETOH2,TECHTYPE)), LVGHN_T_s(scenarios,IA,IGETOH2,S,T))
;

Hproduction_AST_scen(scenarios,IA,"Heat to Storage",S,T)=LVHSTOLOADT_s(scenarios,IA,S,T)$SUM(IGHSTO$(IAGK_Y(IA,IGHSTO) or IAGKN(IA,IGHSTO)),1);
Hproduction_AST_scen(scenarios,IA,"Heat cool down",S,T)=LVCOOLDOWN_s(scenarios,IA,S,T);

Hproduction_AS_scen(scenarios,IA,TECHTYPE,S)=SUM(T,Hproduction_AST_scen(scenarios,IA,TECHTYPE,S,T)*WEIGHT_T(T)*SUM(TTT,WEIGHT_T(TTT))/IWEIGHSUMT);

Hproduction_A_scen(scenarios,IA,TECHTYPE)=(SUM((S,T),Hproduction_AST_scen(scenarios,IA,TECHTYPE,S,T)*IHOURSINST(S,T)))*IOF0000001*IOF3P6;

Hproduction_CST_scen(scenarios,C,TECHTYPE,S,T)=SUM(IA$ICA(C,IA),Hproduction_AST_scen(scenarios,IA,TECHTYPE,S,T));

Hproduction_CS_scen(scenarios,C,TECHTYPE,S)=SUM(IA$ICA(C,IA),Hproduction_AS_scen(scenarios,IA,TECHTYPE,S));

Hproduction_C_scen(scenarios,C,TECHTYPE)=SUM(IA$ICA(C,IA),Hproduction_A_scen(scenarios,IA,TECHTYPE));

FuelConsumption_C_scen(scenarios,C,TECHTYPE)=SUM((IA,G,S,T)$(ICA(C,IA) AND GTECHTYPE(G,TECHTYPE)),IHOURSINST(S,T)*(LVGF_T_s(scenarios,IA,G,S,T)+LVGFN_T_s(scenarios,IA,G,S,T)))*IOF0000001*IOF3P6;

FuelConsumption_TOTAL_scen(scenarios,TECHTYPE)=SUM(C,FuelConsumption_C_scen(scenarios,C,TECHTYPE));

Elec_Capacity_scen(scenarios,C,'New',TECHTYPE)=SUM((IA,IGE)$(ICA(C,IA) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE)),LVGKN_s(scenarios,IA,IGE));

Elec_Capacity_scen(scenarios,C,'Existing',TECHTYPE)=SUM((IA,IGE)$(ICA(C,IA) AND IGNOTETOH(IGE) AND GTECHTYPE(IGE,TECHTYPE) AND IAGK_Y(IA,IGE)),IGKFX_Y(IA,IGE));

Elec_Capacity_scen(scenarios,C,'TOTAL',TECHTYPE)=Elec_Capacity_scen(scenarios,C,'New',TECHTYPE)+Elec_Capacity_scen(scenarios,C,'Existing',TECHTYPE);

Heat_Capacity_scen(scenarios,C,'New',TECHTYPE)=SUM(IA$(ICA(C,IA) AND (NOT AINDHEAT(IA))),
SUM(IGBPR$GTECHTYPE(IGBPR,TECHTYPE),LVGKN_s(scenarios,IA,IGBPR)/GDATA(IGBPR,'GDCB'))
+SUM(IGEXT$GTECHTYPE(IGEXT,TECHTYPE),LVGKN_s(scenarios,IA,IGEXT)/GDATA(IGEXT,'GDCB'))
+SUM(IGHHNOSTO$GTECHTYPE(IGHHNOSTO,TECHTYPE),LVGKN_s(scenarios,IA,IGHHNOSTO ))
+SUM(IGETOH$GTECHTYPE(IGETOH,TECHTYPE),LVGKN_s(scenarios,IA,IGETOH)));

Heat_Capacity_scen(scenarios,C,'Existing',TECHTYPE)=SUM(IA$(ICA(C,IA) AND (NOT AINDHEAT(IA))),
SUM(IGBPR$(GTECHTYPE(IGBPR,TECHTYPE) AND IAGK_Y(IA,IGBPR)),IGKFX_Y(IA,IGBPR)/GDATA(IGBPR,'GDCB'))
+SUM(IGEXT$(GTECHTYPE(IGEXT,TECHTYPE) AND IAGK_Y(IA,IGEXT)),IGKFX_Y(IA,IGEXT)/GDATA(IGEXT,'GDCB'))
+SUM(IGHHNOSTO$(GTECHTYPE(IGHHNOSTO,TECHTYPE) AND IAGK_Y(IA,IGHHNOSTO)),IGKFX_Y(IA,IGHHNOSTO ))
+SUM(IGETOH$(GTECHTYPE(IGETOH,TECHTYPE) AND IAGK_Y(IA,IGETOH)),IGKFX_Y(IA,IGETOH)));

Heat_Capacity_scen(scenarios,C,'TOTAL',TECHTYPE)=Heat_Capacity_scen(scenarios,C,'New',TECHTYPE)+Heat_Capacity_scen(scenarios,C,'Existing',TECHTYPE);


execute_unload "ScenarioResultsGUSS.gdx"  EPrice_RST_scen, HPrice_AST_scen, EDemand_RST_scen, Edemand_CST_scen, Edemand_R_scen, Edemand_C_scen, Hdemand_AST_scen, EPrice_R_scen, EPrice_CST_scen, EPrice_C_scen, HPrice_AS_scen,
HPrice_A_scen, EProduction_RST_scen, ETrade_RST_scen, Eproduction_CST_scen, ETrade_CST_scen, Eproduction_R_scen, Eproduction_C_scen, ETrade_R_scen, ETrade_C_scen, Hproduction_AST_scen, Hproduction_AS_scen,
Hproduction_A_scen, Hproduction_CST_scen, Hproduction_CS_scen, Hproduction_C_scen, FuelConsumption_C_scen, FuelConsumption_TOTAL_scen, Elec_Capacity_scen, Heat_Capacity_scen, WNDFLH_Scenarios, LVGKN_s, MVGKN_s, LVOBJ_s, SOLSTATUS_SCEN;
