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
$if     EXIST '../SensitivityAnalysis/scenarios.inc' $INCLUDE      '../SensitivityAnalysis/scenarios.inc';
$if not EXIST '../SensitivityAnalysis/scenarios.inc' $INCLUDE '../../base/SensitivityAnalysis/scenarios.inc';
%semislash%;

*Change of the parameters for the different scenarios
$if     EXIST '../SensitivityAnalysis/scenarios_parameters_GUSS.inc' $INCLUDE      '../SensitivityAnalysis/scenarios_parameters_GUSS.inc';
$if not EXIST '../SensitivityAnalysis/scenarios_parameters_GUSS.inc' $INCLUDE '../../base/SensitivityAnalysis/scenarios_parameters_GUSS.inc';

*Update bounds
$if     EXIST '../SensitivityAnalysis/Bounds.inc' $INCLUDE      '../SensitivityAnalysis/Bounds.inc';
$if not EXIST '../SensitivityAnalysis/Bounds.inc' $INCLUDE '../../base/SensitivityAnalysis/Bounds.inc';



Set SolHeaders solution headers / modelstat, solvestat, objval /;
Parameter OPTIONSGUSS
/
UpdateType   1
RestartType  1
*Optfile      1
SolveEmpty   10000
NoMatchLimit 100000000
/;

Parameter SOLSTATUS_SCEN(scenarios,SolHeaders) Solution status report;

Parameter MQEEQ_s(scenarios,RRR,S,T);
Parameter MQHEQ_s(scenarios,AAA,S,T);
Parameter LVGE_T_s(scenarios,AAA,G,S,T);
Parameter LVGEN_T_s(scenarios,AAA,G,S,T);
Parameter LVGH_T_s(scenarios,AAA,G,S,T);
Parameter LVGHN_T_s(scenarios,AAA,G,S,T);
Parameter LVGF_T_s(scenarios,AAA,G,S,T);
Parameter LVGFN_T_s(scenarios,AAA,G,S,T);
Parameter LVX_T_s(scenarios,IRRRE,IRRRI,S,T);
Parameter LVHSTOLOADT_s(scenarios,AAA,S,T);
Parameter LVCOOLDOWN_s(scenarios,AAA,S,T);
Parameter LVGKN_s(scenarios,AAA,G);
Parameter MVGKN_s(scenarios,AAA,G);
Parameter LVOBJ_s(scenarios);

*===============================================================================
*===============================================================================
*===============================================================================


Set BalmorelGussDict
/
* ------------------------------------------------------------------------------
* SCENARIO:
* ------------------------------------------------------------------------------
scenarios      . scenario.  ''
* ------------------------------------------------------------------------------
* OPTIONS:
* ------------------------------------------------------------------------------
OPTIONSGUSS    . opt.       SOLSTATUS_SCEN
* ------------------------------------------------------------------------------
* INPUT: PARAMATER CHANGES
* ------------------------------------------------------------------------------
IGKFX_Y        . param.     IGKFX_Y_Scenario
IGKFXYMAX      . param.     IGKFXYMAX_Scenario
WNDFLH         . param.     WNDFLH_Scenarios
SOLEFLH        . param.     SOLEFLH_Scenarios
SOLHFLH        . param.     SOLHFLH_Scenarios
WTRRRFLH       . param.     WTRRRFLH_Scenarios
WTRRSFLH       . param.     WTRRSFLH_Scenarios
IHYINF_S       . param.     IHYINF_S_Scenarios
IFUELP_Y       . param.     IFUELP_Y_Scenario
IXKRATE        . param.     IXKRATE_Scenario
IXMAXINV_Y     . param.     IXMAXINV_Y_Scenario
GINVCOST       . param.     GINVCOST_Scenario

* ------------------------------------------------------------------------------
* INPUT: BOUNDS CHANGES  - LOWER, UPPER, FIXXED
* ------------------------------------------------------------------------------
VGE_T          . upper.     BOUND_SCEN_IGKE_T
VGH_T          . upper.     BOUND_SCEN_IGKH_T
* ------------------------------------------------------------------------------
* OUTPUT: .LEVEL AND .MARGINAL:
* ------------------------------------------------------------------------------
VOBJ           . level.     LVOBJ_s
VGE_T          . level.     LVGE_T_s
VGEN_T         . level.     LVGEN_T_s
VGH_T          . level.     LVGH_T_s
VGHN_T         . level.     LVGHN_T_s
VGF_T          . level.     LVGF_T_s
VGFN_T         . level.     LVGFN_T_s
VX_T           . level.     LVX_T_s
VHSTOLOADT     . level.     LVHSTOLOADT_s
VCOOLDOWN      . level.     LVCOOLDOWN_s
VGKN           . level.     LVGKN_s
VGKN           . marginal.  MVGKN_s
QEEQ           . marginal.  MQEEQ_s
QHEQ           . marginal.  MQHEQ_s
/;

*===============================================================================
*===============================================================================
*===============================================================================
IFUELP_Y(AAA,FFF)=0;


*Solve model
$ifi NOT %UnitComm%==yes $goto notunit
$ifi not %UnitRMIP%==yes
$ifi %bb1%==yes  SOLVE BALBASE1 USING MIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi not %UnitRMIP%==yes
$ifi %bb2%==yes  SOLVE BALBASE2 USING MIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi not %UnitRMIP%==yes
$ifi %bb3%==yes  SOLVE BALBASE3 USING MIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi %UnitRMIP%==yes
$ifi %bb1%==yes  SOLVE BALBASE1 USING RMIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi %UnitRMIP%==yes
$ifi %bb2%==yes  SOLVE BALBASE2 USING RMIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi %UnitRMIP%==yes
$ifi %bb3%==yes  SOLVE BALBASE3 USING RMIP MINIMIZING VOBJ scenario BalmorelGussDict;
$goto YESunit

$label notunit
$ifi %bb1%==yes SOLVE BALBASE1 USING LP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi not %bb2%==yes $goto not_bb2;
$ifi %SOLVEMIP%==yes SOLVE BALBASE2 USING MIP MINIMIZING VOBJ scenario BalmorelGussDict;
$ifi not %SOLVEMIP%==yes SOLVE BALBASE2 MINIMIZING VOBJ USING LP scenario BalmorelGussDict;
$label not_bb2;
$ifi %bb3%==yes  SOLVE BALBASE3 USING LP MINIMIZING VOBJ scenario BalmorelGussDict;
$LABEL YESunit
;


*step 6 cross scenario report writing

$if     EXIST '../SensitivityAnalysis/SensitivityAnalysis_output.inc' $INCLUDE      '../SensitivityAnalysis/SensitivityAnalysis_output.inc';
$if not EXIST '../SensitivityAnalysis/SensitivityAnalysis_output.inc' $INCLUDE '../../base/SensitivityAnalysis/SensitivityAnalysis_output.inc';



*End of the Balmorel scenario file

