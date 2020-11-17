
SET EDemand_type /classic, transport, "individual heating", "process heating", DH, H2/;


SET TECHTYPE  'Type of technologies for calculation of marginals' %semislash%
$if     EXIST '../data/TECHTYPE.inc' $INCLUDE      '../data/TECHTYPE.inc';
$if not EXIST '../data/TECHTYPE.inc' $INCLUDE '../../base/data/TECHTYPE.inc';
%semislash%;

SET GTECHTYPE(GGG,TECHTYPE) 'Type of technology aggrupated'%semislash%
$if     EXIST '../data/GTECHTYPE.inc' $INCLUDE      '../data/GTECHTYPE.inc';
$if not EXIST '../data/GTECHTYPE.inc' $INCLUDE '../../base/data/GTECHTYPE.inc';
%semislash%;

SET ELECTRADE /Import, Export, "Net Export"/;


SET RRROFFSHORE(RRR);
RRROFFSHORE(IR)$SUM(IA,RRRAAA(IR,IA)$AAAOFFSHORE(IA))=YES;
RRROFFSHORE("DK_E")=NO;
RRROFFSHORE("DK_W")=NO;
RRROFFSHORE("DK_KF")=NO;
RRROFFSHORE("DE_KF")=NO;

SET CAPACITIES /New, Existing, TOTAL/;

Parameter EPrice_RST(RRR,SSS,TTT)  'Electricity price per hour at a regional level - cost of producing one unit more of electricity for own consumption or for export (€ 2015/MWh)';
Parameter HPrice_AST(AAA,SSS,TTT)'Heat price per hour at an area level - cost of producing one unit more of heat(€ 2015/MWh)';
Parameter WASTEIMPORTED(C) 'Million tons of waste imported';
Parameter INCINERATION_CAPACITY(AAA,PROC) 'Installed incineration capacity in Denmark per Area in the year of simulation (ton/h)';
Parameter INCINERATION_CAPACITY_DK(PROC) 'Total installed incineration capacity in Denmark in the year of simulation (ton/h)';
$if     EXIST '../addons/OptiFlow/data/INCIN_OUTPUTDATA.inc' $INCLUDE         '../addons/OptiFlow/data/INCIN_OUTPUTDATA.inc';
$if not EXIST '../addons/OptiFlow/data/INCIN_OUTPUTDATA.inc' $INCLUDE '../../base/addons/OptiFlow/data/INCIN_OUTPUTDATA.inc';
PARAMETER INCINERATION_FLOWS(AAA,PROC,FLOW,INCIN_TYPEFLOW,S,T) 'Incineration input and outputs at an S,T level, same units as flows';
Parameter INCINERATION_FLOWS_S(AAA,PROC,FLOW,INCIN_TYPEFLOW,S) 'Incineration input and outputs at an S level, same units as flows';
Parameter INCINERATION_FLOWS_Y(AAA,PROC,FLOW,INCIN_TYPEFLOW) 'Incineration input and outputs per year, same units as flows';
Parameter INCINERATION_FLOWS_Y_UNITS(AAA,PROC,FLOW,INCIN_TYPEFLOW) 'Incineration input and outputs per year, Mill. tons - PJ - PJ';
PARAMETER INCINERATION_FLOWS_C(CCC,PROC,FLOW,INCIN_TYPEFLOW,S,T) 'Incineration input and outputs at an S,T level in DENMARK, same units as flows';
PARAMETER INCINERATION_FLOWS_S_C(CCC,PROC,FLOW,INCIN_TYPEFLOW,S) 'Incineration input and outputs at an S level in DENMARK, same units as flows';
PARAMETER INCINERATION_FLOWS_Y_C(CCC,PROC,FLOW,INCIN_TYPEFLOW) 'Incineration input and outputs per year in DENMARK, same units as flows';
Parameter INCINERATION_FLOWS_Y_UNITS_C(CCC,PROC,FLOW,INCIN_TYPEFLOW) 'Incineration input and outputs per year in DENMARK, Mill. tons - PJ - PJ';
PARAMETER INCINERATION_FLOWS_TOTAL(CCC,INCIN_TYPEFLOW,S,T) 'Incineration input and outputs at an S,T level in DENMARK, same units as flows';
PARAMETER INCINERATION_FLOWS_S_TOTAL(CCC,INCIN_TYPEFLOW,S) 'Incineration input and outputs at an S level in DENMARK, same units as flows';
PARAMETER INCINERATION_FLOWS_Y_TOTAL(CCC,INCIN_TYPEFLOW) 'Incineration input and outputs per year in DENMARK, same units as flows';
Parameter INCINERATION_FLOWS_Y_UNITS_TOTAL(CCC,INCIN_TYPEFLOW) 'Incineration input and outputs per year in DENMARK, Mill. tons - PJ - PJ';
PARAMETER WASTETRANSPORT 'Total amount of waste transported during the year of simulations by truck(TON*KM)';
PARAMETER WASTE_TDISTANCE 'Average transport distance domestic waste is transported thorughout all the year(KM)';
PARAMETER WASTE_TDISTANCEALL 'Average transport distance domestic waste is transported thorughout all the year(KM)';
SET MSWTECHTYPE(PROC,TECHTYPE) 'PROC in OptiFlow and type of technology in Balmorel for linking of output files';
$if     EXIST '../addons/OptiFlow/data/MSWTECHTYPE.inc' $INCLUDE         '../addons/OptiFlow/data/MSWTECHTYPE.inc';
$if not EXIST '../addons/OptiFlow/data/MSWTECHTYPE.inc' $INCLUDE '../../base/addons/OptiFlow/data/MSWTECHTYPE.inc';
SET COSTSET /'Expenses', 'Earnings','Earnings_Elec', 'Earnings_Heat', 'Balance'/;
PARAMETER LCOT_A(AAA,PROC,COSTSET) ' Levelised cost of treatment on average since the waste enters a specific incineration plant in the year of simulation (€/ton)';
PARAMETER LCOT_DK(PROC,COSTSET) ' Levelised cost of treatment on average since the waste enters a specific type of incineration plant in the year of simulation (€/ton)';
PARAMETER LCOT_DK_AV(COSTSET) ' Levelised cost of treatment on average in the year of simulation (€/ton)';
PARAMETER LCOT_DK_TOTAL(COSTSET) ' Economic balance of waste incineration in the year of simulation (Mill. €)';

Parameter EDemand_RST(EDemand_type,RRR,SSS,TTT) 'Electricity Demand (MW)';
Parameter Edemand_CST(EDemand_type,CCC,SSS,TTT) 'Electricity Demand (MW)';
Parameter Edemand_R(EDemand_type,RRR) 'Electricity Demand (PJ/year)';
Parameter Edemand_C(EDemand_type,CCC) 'Electricity Demand (PJ/year)';
Parameter Hdemand_AST(AAA,SSS,TTT) 'District Heating Demand (MW)';
Parameter EPrice_R(RRR) 'Weighted average electricity price by consumption quantity per year at a regional level (€ 2015/MWh)';
Parameter EPrice_CST(CCC,SSS,TTT) 'Weighted average electricity price by consumption quantity at a country level(€ 2015/MWh)';
Parameter EPrice_C(CCC) 'Weighted average electricity price by consumption quantity per year at a country level (€ 2015/MWh)';
Parameter HPrice_AS(AAA,SSS) 'Weighted average heat price by consumption quantity per week at an area level (€ 2015/MWh)';
Parameter HPrice_A(AAA) 'Weighted average heat price by consumption quantity per year at an area level (€ 2015/MWh)';
Parameter HPrice_C(CCC) 'Weighted average heat price by consumption quantity per year at an country level (€ 2015/MWh)';
Parameter EProduction_RST(RRR,TECHTYPE,SSS,TTT) 'Electricity production at a regional level (MW)';
Parameter ETrade_RST(RRR,ELECTRADE,SSS,TTT) 'Electricity trade at a regional level (MW)';
Parameter Eproduction_CST(CCC,TECHTYPE,SSS,TTT) 'Electricity production at a country level (MW)';
Parameter ETrade_CST(CCC,ELECTRADE,SSS,TTT) 'Electricity trade at a country level (MW)';
Parameter Eproduction_R(RRR,TECHTYPE) 'Electricity production at a regional level (PJ/year)';
Parameter Eproduction_C(CCC,TECHTYPE) 'Electricity production at a country level (PJ/year)';
Parameter ETrade_R(RRR,ELECTRADE) 'Electricity trade at a regional level (PJ/year)';
Parameter ETrade_C(CCC,ELECTRADE) 'Electricity trade at a regional level (PJ/year)';
Parameter Hproduction_AST(AAA,TECHTYPE,SSS,TTT) 'Heat production at an area level (MW)';
Parameter Hproduction_AS(AAA,TECHTYPE,SSS) 'Heat production at an area level per week (MWh)';
Parameter Hproduction_A(AAA,TECHTYPE) 'Heat production at an area level per year (PJ/year)';
Parameter Hproduction_CST(CCC,TECHTYPE,SSS,TTT) 'Heat production at a country level (MW)';
Parameter Hproduction_CS(CCC,TECHTYPE,SSS) 'Heat production at a country level per week (MWh)';
Parameter Hproduction_C(CCC,TECHTYPE) 'Heat production at a country level per year (PJ/year)';
Parameter FuelConsumption_C(CCC,TECHTYPE)  'Fuel Consumption at a country level per type of technology (PJ/year)';
Parameter FuelConsumption_TOTAL(TECHTYPE)  'Fuel Consumption in all the simulated countryes per type of technology (PJ/year)';
Parameter Elec_Capacity(CCC,CAPACITIES,TECHTYPE) 'Installed capacity for electricity production (MW)';
Parameter Heat_Capacity(CCC,CAPACITIES,TECHTYPE) 'Installed capacity for heat production (MW)';
Scalar WASTE_GATEFEE 'Gate fee of the waste';

Parameter EPrice_CST_scen(scenarios,CCC,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter EPrice_C_scen(scenarios,CCC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter EPrice_R_scen(scenarios,RRR)  'Comparative summary-go to single parameter gdx file to check units';
Parameter HPrice_AS_scen(scenarios,AAA,SSS)  'Comparative summary-go to single parameter gdx file to check units';
Parameter HPrice_A_scen(scenarios,AAA)  'Comparative summary-go to single parameter gdx file to check units';
Parameter HPrice_C_scen(scenarios,CCC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Eproduction_CST_scen(scenarios,CCC,TECHTYPE,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter ETrade_CST_scen(scenarios,CCC,ELECTRADE,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter EProduction_C_scen(scenarios,CCC,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter ETrade_C_scen(scenarios,CCC,ELECTRADE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Edemand_CST_scen(scenarios,EDemand_type,CCC,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Edemand_C_scen(scenarios,EDemand_type,CCC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hdemand_AST_scen(scenarios,AAA,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_AST_scen(scenarios,AAA,TECHTYPE,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_AS_scen(scenarios,AAA,TECHTYPE,SSS)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_A_scen(scenarios,AAA,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_CST_scen(scenarios,CCC,TECHTYPE,SSS,TTT)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_CS_scen(scenarios,CCC,TECHTYPE,SSS)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Hproduction_C_scen(scenarios,CCC,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter FuelConsumption_C_scen(scenarios,CCC,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter FuelConsumption_TOTAL_scen(scenarios,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Elec_Capacity_scen(scenarios,CCC,CAPACITIES,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter Heat_Capacity_scen(scenarios,CCC,CAPACITIES,TECHTYPE)  'Comparative summary-go to single parameter gdx file to check units';
Parameter VOBJ_scen(scenarios)  'Comparative summary-go to single parameter gdx file to check units';
Parameter VGKN_scen(scenarios,AAA,G)  'Comparative summary-go to single parameter gdx file to check units';
Parameter VGKN_scen_M(scenarios,AAA,G) 'Comparative summary, units are the same than the VOBJ';
Parameter WASTEIMPORTED_scen(scenarios,C)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_CAPACITY_scen(scenarios,AAA,PROC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_CAPACITY_DK_scen(scenarios,PROC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_scen(scenarios,AAA,PROC,FLOW,INCIN_TYPEFLOW,S,T)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_S_scen(scenarios,AAA,PROC,FLOW,INCIN_TYPEFLOW,S)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_scen(scenarios,AAA,PROC,FLOW,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_C_scen(scenarios,CCC,PROC,FLOW,INCIN_TYPEFLOW,S,T)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_S_C_scen(scenarios,CCC,PROC,FLOW,INCIN_TYPEFLOW,S)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_C_scen(scenarios,CCC,PROC,FLOW,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_TOTAL_scen(scenarios,CCC,INCIN_TYPEFLOW,S,T)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_S_TOTAL_scen(scenarios,CCC,INCIN_TYPEFLOW,S)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_TOTAL_scen(scenarios,CCC,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_UNITS_scen(scenarios,AAA,PROC,FLOW,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_UNITS_C_scen(scenarios,CCC,PROC,FLOW,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter INCINERATION_FLOWS_Y_UNITS_TOTAL_scen(scenarios,CCC,INCIN_TYPEFLOW)  'Comparative summary-go to single parameter gdx file to check units';
Parameter WASTETRANSPORT_scen(scenarios)  'Comparative summary-go to single parameter gdx file to check units';
Parameter WASTE_TDISTANCE_scen(scenarios)  'Comparative summary-go to single parameter gdx file to check units';
Parameter LCOT_A_scen(scenarios,AAA,PROC,COSTSET)  'Comparative summary-go to single parameter gdx file to check units';
Parameter LCOT_DK_scen(scenarios,PROC,COSTSET)  'Comparative summary-go to single parameter gdx file to check units';
Parameter LCOT_DK_AV_scen(scenarios,COSTSET)  'Comparative summary-go to single parameter gdx file to check units';
Parameter LCOT_DK_TOTAL_scen(scenarios,COSTSET)  'Comparative summary-go to single parameter gdx file to check units';
Parameter SOSIBU2INDIC_scen(scenarios,PROC,FLOW,FLOWINDIC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter VPROCKAPDEC_U_scen(scenarios,AAA,PROC)  'Comparative summary-go to single parameter gdx file to check units';
Parameter WASTE_GATEFEE_scen(scenarios)  'Comparative summary-go to single parameter gdx file to check units';

Parameter FUEL_TOTAL_DIFFERENCE(scenarios,TECHTYPE) 'PJ/year';
Parameter FUEL_C_DIFFERENCE(scenarios,C,TECHTYPE) 'PJ/year';
Parameter FUEL_TOTAL_DIFFERENCE_WI(scenarios,C,TECHTYPE)  'GJ/ton';
Parameter FUEL_C_DIFFERENCE_WI(scenarios,C,TECHTYPE) 'GJ/ton';

Parameter SOCIOEC_WASTEIMPORT(scenarios,C)  '€15/ton';
Parameter SOCIOEC_WASTEIMPORT_NOGF(scenarios,C) '€15/ton';
Parameter EARNINGS_DIFFERENCE(scenarios,C,COSTSET) '€15/ton';
