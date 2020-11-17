* THIS IS ON-THE-WAY TO TOPWASTEMARGINALS
* MODIFIED FROM PREVIOUS GUSS-MODEL . . . . . .  SEE THAT FOR ORIGINAL
* That original contains a number of refinements that are omitted for simplicity of development, may be reinserted later.

* Presently this file is $included from Balmorel.gms
* TODO: Find out, where to place it etc.
* The activation of the GUSS solve is from bb123.sim


$ifi not %useGUSS%==yes  $goto endofGUSSdictfile

* File bb_gussdict.inc to the Balmorel model.
* This file is part of the Balmorel model, version 3.03 -


* Check GAMS version number:
* GUSS was introduced in GAMS version 23.7, more was added from release 24.
* This code requires release 24 or later.
PUT LOGFILE "GAMS  version is " GAMSVERSION " GAMS release is " GAMSRELEASE "  (Message from file bbgussdict.inc.)"  /;
PUT LOGFILE "Using GAMS GUSS facilities" /;
IF((GAMSRELEASE LT 24),
   PUT LOGFILE   "This code requires GAMS release 24.0 or later to use the GAMS GUSS facilities. Quitting."/;
* No quitting code provided yet
);


*===============================================================================
*===============================================================================
*===============================================================================
$ontext
General comments on GUSS:
Description of purpose, documentation, examples see GAMS ...
 - .param. turn up as variables in lst
   Ex: with "IX3FX_T_Y   .  param   .  IX3FX_T_Ynew " in dict, the listing of QEEQ will contain a term IX3FX_T_Y_var(DK_W,S20,T001). This term was not declared, it was introduced in the model instance behind the back of you.
 - therefore eqns may appear nonliniear
   Ex: with "IFUELP_Y    .  param   .   IFUELP_Ynew " in dict, the listing of QOBJ will contain a term  (0)*IFUELP_Y_var(DK_E_Rural,FUELOIL). This term was not declared. Additionally, the model appears now to be non-linear, cf. the "(0)", nevertheless it is solved as a linear model.
 - sets can not be part of the update  : e.g. Balmorel QLIMCO2 equation can not have the first linie in the definition as previous: QLIMNOX(C)$(ILIM_NOX_Y(C) LT INF)..  changed to QLIMNOX(C).., meaning that it will always be generated
 - size of generated Balmorel model in trad and guss will differ (but results are identical)
 -
 - Note: difficult to debug: only one instance may be reported in lst i detail, e.g. with  eqnlisting and ..  As illustrated above, it also appears different.

* Opsamle data: GUSS-dokumentationen illustrerer opsamling i parametre, umiddelbart virker gdx ikke (men .log-filen taler om gdx, så gdx bruges nok internt). Korrektion: gdx virker her


Comments for Optiwaste
 - The scenarios calculated are as given in SET scenarios_E. This set has many elements (one for each combination of SSS, TTT and RRR).
   Hence the usual trick of limiting the scope of calculations (using S, T and IR) does not work (it only ensures that input data will differ between scenaions on only these indexes)
   It might therefore be a good idea to make a static subset of scenarios_E for use in dict
 - The solve statement for GUSS must be after assignment of internal parameters, i.e. essentially it must be within the bb123.sim file
 - The main loops in bb123.sim (over Y and IS3LOOPSET) are irrelevant, i.e., card(Y) must be 1, and option bb3 cannot be yes.

 - TODO: apparently there are a couple of solves executed (with SKIPBASECASE 1) before GUSS takes over - why? Message from GAMS:
         Reading parameter(s) from scenario dictionary
         >>  SKIPBASECASE 1
         *** Unknow option UPDATATYPE skipped

$offtext

* Output: ----------------------------------------------------------------------

* Solution headers
* The following solution status labels can be reported:
*   domusd iterusd objest nodusd modelstat numnopt
*   numinfes objval rescalc resderiv resin resout
*   resusd robj solvestat suminfes
SET SOLHEADERS "Solution status labels" /modelstat, solvestat, objval /;



/*
GUSS options (I think this is for version 24).
OptfileInit:  Option file number for the first solve
Optfile:      Option file number for subsequent solves
LogOption:    Determines amount of log output:
              0 - Moderate log (default)
              1 - Minimal log
              2 - Detailed log
SkipBaseCase: Switch for solving the base case (0 solves the base case)
UpdateType:   Scenario update mechanism:
              0 - Set everything to zero and apply changes (default)
              1 - Reestablish base case and apply changes
              2 - Build on top of last scenario and apply changes
RestartType:  Determines restart point for the scenarios
              0 - Restart from last solution (default)
              1 - Restart from solution of base case
              2 - Restart from input point
NoMatchLimit: Limit of unmatched scenario records (default 0)
*/
PARAMETER OPTIONSGUSS "Dict options for OptiWaste"
/ SKIPBASECASE 1
  UPDATATYPE 2
  LogOption 0
  NoMatchLimit 1E9   !!  NoMatchLimit is available from gams version 23.8 (April 2012), my above check requires 24.0
/;


* INPUT: PARAM, LOWER, UPPER, FIXED may be entered here if not placed elsewhere:

* OUTPUT: LEVEL AND MARGINAL:

PARAMETER VGE_TdotL_SCEN(scenarios_E,AAA,G,S,T)  "Electricity generation (MW), existing units";
PARAMETER VGF_TdotL_SCEN(scenarios_E,AAA,G,S,T)  "Fuel consumption rate (MW), existing units"
PARAMETER QEEQdotM_SCEN(scenarios_E,RRR,S,T)     "Electricity generation equals demand (MW) - marginals ()";

PARAMETER SOLSTATUS_SCEN(scenarios_E,SolHeaders) "Scenario status information for GUSS solutions";

SET BB1gussdict  "GUSS Dictionary for Balmorel Model BB1 - Here for Topwaste marginals"
/
* ------------------------------------------------------------------------------
* SCENARIO:
* ------------------------------------------------------------------------------
* Note that the third position must be "", nothing else
*   scenarios_E           . scenario .  ""
   scenariosused_E        . scenario .  ""
* ------------------------------------------------------------------------------
* OPTIONS:
* ------------------------------------------------------------------------------
  OPTIONSGUSS    . opt      .   SOLSTATUS_SCEN
* ------------------------------------------------------------------------------
* INPUT: PARAM, LOWER, UPPER, FIXED:
* ------------------------------------------------------------------------------
  IDE_T_Y           .  param   .   IDE_T_Y_SCEN
* ------------------------------------------------------------------------------
* OUTPUT: .LEVEL AND .MARGINAL:
* ------------------------------------------------------------------------------
  VGE_T            .  level   . VGE_TdotL_SCEN
  VGF_T            .  level   . VGF_TdotL_SCEN
*  VGH_T            .  level   . VGH_TdotL_SCEN
  QEEQ             . marginal . QEEQdotM_SCEN
/;

*===============================================================================
*===============================================================================
*===============================================================================

* Next is desirable not possible due to missing initailisation of IAGK, etc., done in bb123.sim
*SOLVE BALBASE1 USING LP MINIMIZING VOBJ Scenario BB1gussdict;


$label endofGUSSdictfile
