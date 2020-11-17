*Code created for running different scenarios (Amalia, 05-09-2016)

*Call the balmorel mode, which will be solved through a loop in order to calculate all the marginal values
$include Balmorel.gms


* Turn off the listing of the input file */
$offlisting

* Turn off the listing and cross-reference of the symbols used */
$offsymxref offsymlist

Option solprint=off;
Option sysout=off;


*step 1 - setup scenarios

Set scenarios  'Scenarios for calculation of marginal values of electricity' %semislash%
$if     EXIST '../GateFees/scenarios.inc' $INCLUDE      '../GateFees/scenarios.inc';
$if not EXIST '../GateFees/scenarios.inc' $INCLUDE '../../base/GateFees/scenarios.inc';
%semislash%;


*Change of the parameters for the different scenarios
$if     EXIST '../GateFees/scenarios_parameters.inc' $INCLUDE      '../GateFees/scenarios_parameters.inc';
$if not EXIST '../GateFees/scenarios_parameters.inc' $INCLUDE '../../base/GateFees/scenarios_parameters.inc';


*step 2 save data
$if     EXIST '../GateFees/saved_data.inc' $INCLUDE      '../GateFees/saved_data.inc';
$if not EXIST '../GateFees/saved_data.inc' $INCLUDE '../../base/GateFees/saved_data.inc';




$if     EXIST '../GateFees/Loop_parameters_output.inc' $INCLUDE      '../GateFees/Loop_parameters_output.inc';
$if not EXIST '../GateFees/Loop_parameters_output.inc' $INCLUDE '../../base/GateFees/Loop_parameters_output.inc';

*/BASE,GF-m100,GF-m90,GF-m80,GF-m70,GF-m60, GF-m50,GF-m40,GF-m30,GF-m20, GF_m10, GF_0, GF_P10,GF_P20,GF_P30,GF_P40,GF_P50,GF_P60,GF_P70,GF_P80,GF_P90,GF_P100,GF_P150,GF_P200,GF_P300/;

SET scenariosrunning(scenarios) /BASE,GF_P300/;

loop(scenarios$scenariosrunning(scenarios),


*step 3 reestablish data to base level
ISOSIBU2INDIC('Imported_RDF','IMPORTEDRDFFLOW','OPERATIONCOST')=sav_ISOSIBU2INDIC('Imported_RDF','IMPORTEDRDFFLOW','OPERATIONCOST');
IEQFLOW_Y('UK_AAA','Imported_RDF','IMPORTEDRDFFLOW')=sav_IEQFLOW_Y('UK_AAA','Imported_RDF','IMPORTEDRDFFLOW');


*step 4 change data to levels needed in scenario
ISOSIBU2INDIC('Imported_RDF','IMPORTEDRDFFLOW','OPERATIONCOST')$(ISOSIBU2INDIC_Scenario(scenarios,'Imported_RDF','IMPORTEDRDFFLOW','OPERATIONCOST'))=ISOSIBU2INDIC_Scenario(scenarios,'Imported_RDF','IMPORTEDRDFFLOW','OPERATIONCOST');
IEQFLOW_Y('UK_AAA','Imported_RDF','IMPORTEDRDFFLOW')$(IEQFLOW_Y_Scenario(scenarios,'UK_AAA','Imported_RDF','IMPORTEDRDFFLOW'))=IEQFLOW_Y_Scenario(scenarios,'UK_AAA','Imported_RDF','IMPORTEDRDFFLOW');


*Update bounds


*step 5 -- solve model

BALBASE2.OptFile=1;
SOLVE BALBASE2 USING MIP MINIMIZING VOBJ
;

$if     EXIST '../GateFees/OutputFile_Loop.inc' $INCLUDE      '../GateFees/OutputFile_Loop.inc';
$if not EXIST '../GateFees/OutputFile_Loop.inc' $INCLUDE '../../base/GateFees/OutputFile_Loop.inc';




*step 6 cross scenario report writing

$if     EXIST '../GateFees/Loop_output.inc' $INCLUDE      '../GateFees/Loop_output.inc';
$if not EXIST '../GateFees/Loop_output.inc' $INCLUDE '../../base/GateFees/Loop_output.inc';




*step 7 end of loop
    );

*step 8 Create a Report
*step 9 compute and display final results



execute_unload "GateFeesResults.gdx"
EPrice_CST_scen,
EPrice_C_scen,
EPrice_R_scen,
HPrice_AS_scen,
HPrice_A_scen,
HPrice_C_scen,
Eproduction_CST_scen,
ETrade_CST_scen,
EProduction_C_scen,
ETrade_C_scen,
Edemand_CST_scen,
Edemand_C_scen,
Hdemand_AST_scen,
Hproduction_AST_scen,
Hproduction_AS_scen,
Hproduction_A_scen,
Hproduction_CST_scen,
Hproduction_CS_scen,
Hproduction_C_scen,
FuelConsumption_C_scen,
FuelConsumption_TOTAL_scen,
Elec_Capacity_scen,
Heat_Capacity_scen,
VOBJ_scen,
VGKN_scen,
WASTEIMPORTED_scen,
INCINERATION_CAPACITY_scen,
INCINERATION_CAPACITY_DK_scen,
INCINERATION_FLOWS_scen,
INCINERATION_FLOWS_S_scen,
INCINERATION_FLOWS_Y_scen,
INCINERATION_FLOWS_C_scen,
INCINERATION_FLOWS_S_C_scen,
INCINERATION_FLOWS_Y_C_scen,
INCINERATION_FLOWS_TOTAL_scen,
INCINERATION_FLOWS_S_TOTAL_scen,
INCINERATION_FLOWS_Y_TOTAL_scen,
INCINERATION_FLOWS_Y_UNITS_scen,
INCINERATION_FLOWS_Y_UNITS_C_scen,
INCINERATION_FLOWS_Y_UNITS_TOTAL_scen,
WASTETRANSPORT_scen,
WASTE_TDISTANCE_scen,
LCOT_A_scen,
LCOT_DK_scen,
LCOT_DK_AV_scen,
LCOT_DK_TOTAL_scen,
SOSIBU2INDIC_scen,
VPROCKAPDEC_U_scen,
FUEL_TOTAL_DIFFERENCE,
FUEL_C_DIFFERENCE,
FUEL_TOTAL_DIFFERENCE_WI,
FUEL_C_DIFFERENCE_WI,
SOCIOEC_WASTEIMPORT,
SOCIOEC_WASTEIMPORT_NOGF,
EARNINGS_DIFFERENCE
sav_ISOSIBU2INDIC
sav_IEQFLOW_Y
WASTE_GATEFEE_scen
;

*End of the Balmorel scenario file

