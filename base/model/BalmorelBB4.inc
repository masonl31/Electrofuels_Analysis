
Denne er senere redigeret under C:\$_HansC\Balmorel\BalmorelBB4\BB4_20141118. Brug den!

* Udgangspunkt i den, der kom fra BMM.

* Ændringer, søg Hans

* Hans: bemærk TODO ingen COMBTECH?
* Hans: søg decom. Der er to controls, DECOMP og DECOMPEFF, der mangler at få erklæringerne ind under  $ifi . Også i Balmorel.gms

*ICA1(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);     Hans   ?
*ICA2(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);
*ICA3(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);
*ICA4(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);
*ICA5(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);

* File BalmorelBB4.inc for handling the Balbase4 model in Balmorel.
* (Internal version id BC08)

* Hans ny: og se tilsvarende i bb4.sim
* Note: although not necessary there are a number of "$ifi %BB4%==yes" conditions,
* this is to make some of the differences relative to Balbase2 more visible.

*-------------------------------------------------------------------------------
*-------------------------------------------------------------------------------
* Declarations and inclusion of data files:
*-------------------------------------------------------------------------------
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
*---- User defined SETS and ACRONYMS needed for data entry: --------------------
*-------------------------------------------------------------------------------

* Declarations: ----------------------------------------------------------------

* SETS:
SET CCCRRRAAA         'All geographical entities (CCC + RRR + AAA)';
SET CCC(CCCRRRAAA)    'All Countries';
SET RRR(CCCRRRAAA)    'All regions';
SET AAA(CCCRRRAAA)    'All areas';
SET CCCRRR(CCC,RRR)   'Regions in countries';
SET RRRAAA(RRR,AAA)   'Areas in regions';
SET YYY               'All years';
SET SSS               'All seasons';
SET TTT               'All time periods';
SET GGG               'All generation technologies';
SET GDATASET          'Generation technology data';
SET FFF               'Fuels';
SET FDATASET          'Characteristics of fuels';
SET HYRSDATASET       'Characteristics of hydro reservoirs';
SET DF_QP             'Quantity and price information for elastic demands';
SET DEF               'Steps in elastic electricity demand';
SET DEF_D1(DEF)       'Downwards steps in elastic el. demand, relative data format';
SET DEF_U1(DEF)       'Upwards steps in elastic el. demand, relative data format';
SET DEF_D2(DEF)       'Downwards steps in elastic el. demand, absolute Money and MW-incremental data format';
SET DEF_U2(DEF)       'Upwards steps in elastic el. demand, absolute Money and MW-incremental data format';
SET DEF_D3(DEF)       'Downwards steps in elastic el. demand, absolute Money and fraction of nominal demand data format';
SET DEF_U3(DEF)       'Upwards steps in elastic el. demand, absolute Money and fraction of nominal demand data format';
SET DHF               'Steps in elastic heat demand';
SET DHF_D1(DHF)       'Downwards steps in elastic heat demand, relative data format';
SET DHF_U1(DHF)       'Upwards steps in elastic heat demand, relative data format';
SET DHF_D2(DHF)       'Downwards steps in elastic heat demand, absolute Money and MW-incremental data format';
SET DHF_U2(DHF)       'Upwards steps in elastic heat demand, absolute Money and MW-incremental data format';
SET DHF_D3(DHF)       'Downwards steps in elastic heat demand, absolute Money and fraction of nominal demand data format';
SET DHF_U3(DHF)       'Upwards steps in elastic heat demand, absolute Money and fraction of nominal demand data format';
SET MPOLSET           'Emission and other policy data';
SET C(CCC)            'Countries in the simulation';
SET G(GGG)            'Generation technologies in the simulation';
SET AGKN(AAA,GGG)     'Areas for possible location of new technologies';
SET Y(YYY)            'Years in the simulation';
SET S(SSS)            'Seasons in the simulation';
SET T(TTT)            'Time periods within the season in the simulation';
*SET DAYTYPE           'Types of days within the week, typically workdays/weekend';
SET TWORKDAY(TTT)     'Time segments, T, in workdays';
SET TWEEKEND(TTT)     'Time segments, T, in weekends';



*SET SCENARIO            'All scenarios';
*SET SCENARSIM(SCENARIO) 'Scenarios in simulation';

* ALIASES:
*ALIAS(SCENARSIM,SC);
* Internal set IGGGALIAS may be used in the $included data files:
ALIAS(GGG,IGGGALIAS);
* Set CCCRRRAAAALIAS may be used in the $included data files:
ALIAS(CCCRRRAAA,CCCRRRAAAALIAS);

* ACRONYMS:
* ACRONYMS for technology types
* Each of the following ACRONYMS symbolise a technology type,
* They correspond in a one-to-one way with the internal sets IGCND, IGBRP etc. below.
* They should generally not be changed.
* New technology types may be added only if also code specifying their properties are added.
ACRONYMS   GCND, GBPR, GEXT, GHOB, GETOH, GHSTO, GESTO, GHYRS, GHYRR, GWND, GSOLE, GSOLH, GWAVE, GHSTO_S;

* ACRONYMS for user defined fuels will be given in a $included file FFFACRONYMS.inc.


*-------------------------------------------------------------------------------
*----- Definitions of SETS and ACRONYMS that are given in the $included files:
*-------------------------------------------------------------------------------
* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%
* (see file balgams.opt):
%ONOFFDATALISTING%

SET CCCRRRAAA          'All geographical entities (CCC + RRR + AAA)' %semislash%
$if     EXIST '../data/CCCRRRAAA.inc' $INCLUDE      '../data/CCCRRRAAA.inc';
$if not EXIST '../data/CCCRRRAAA.inc' $INCLUDE '../../base/data/CCCRRRAAA.inc';
%semislash%;

SET CCC(CCCRRRAAA)       'All Countries' %semislash%
$if     EXIST '../data/CCC.inc' $INCLUDE      '../data/CCC.inc';
$if not EXIST '../data/CCC.inc' $INCLUDE '../../base/data/CCC.inc';
%semislash%;

SET RRR(CCCRRRAAA)       'All regions' %semislash%
$if     EXIST '../data/RRR.inc' $INCLUDE      '../data/RRR.inc';
$if not EXIST '../data/RRR.inc' $INCLUDE '../../base/data/RRR.inc';
%semislash%;

SET AAA(CCCRRRAAA)       'All areas' %semislash%
$if     EXIST '../data/AAA.inc' $INCLUDE      '../data/AAA.inc';
$if not EXIST '../data/AAA.inc' $INCLUDE '../../base/data/AAA.inc';
%semislash%;

SET CCCRRR(CCC,RRR)      'Regions in countries' %semislash%
$if     EXIST '../data/CCCRRR.inc' $INCLUDE      '../data/CCCRRR.inc';
$if not EXIST '../data/CCCRRR.inc' $INCLUDE '../../base/data/CCCRRR.inc';
%semislash%;

SET RRRAAA(RRR,AAA)      'Areas in regions' %semislash%
$if     EXIST '../data/RRRAAA.inc' $INCLUDE      '../data/RRRAAA.inc';
$if not EXIST '../data/RRRAAA.inc' $INCLUDE '../../base/data/RRRAAA.inc';
%semislash%;

SET YYY                'All years'  %semislash%
$if     EXIST '../data/YYY.inc' $INCLUDE      '../data/YYY.inc';
$if not EXIST '../data/YYY.inc' $INCLUDE '../../base/data/YYY.inc';
%semislash%;

SET SSS                'All seasons' %semislash%
$if     EXIST '../data/SSS.inc' $INCLUDE      '../data/SSS.inc';
$if not EXIST '../data/SSS.inc' $INCLUDE '../../base/data/SSS.inc';
%semislash%;

SET TTT                'All time periods' %semislash%
$if     EXIST '../data/TTT.inc' $INCLUDE      '../data/TTT.inc';
$if not EXIST '../data/TTT.inc' $INCLUDE '../../base/data/TTT.inc';
%semislash%;

SET GGG                'All generation technologies'   %semislash%
$if     EXIST '../data/GGG.inc' $INCLUDE      '../data/GGG.inc';
$if not EXIST '../data/GGG.inc' $INCLUDE '../../base/data/GGG.inc';
%semislash%;

SET GDATASET           'Generation technology data' %semislash%
$if     EXIST '../data/GDATASET.inc' $INCLUDE      '../data/GDATASET.inc';
$if not EXIST '../data/GDATASET.inc' $INCLUDE '../../base/data/GDATASET.inc';
%semislash%;

SET FFF                'Fuels'  %semislash%
$if     EXIST '../data/FFF.inc' $INCLUDE      '../data/FFF.inc';
$if not EXIST '../data/FFF.inc' $INCLUDE '../../base/data/FFF.inc';
%semislash%;

* ACRONYMS for fuels:
$ifi %semislash%=="/" ACRONYMS
$if     EXIST '../data/FFFACRONYM.inc' $INCLUDE      '../data/FFFACRONYM.inc';
$if not EXIST '../data/FFFACRONYM.inc' $INCLUDE '../../base/data/FFFACRONYM.inc';
;

SET FDATASET           'Characteristics of fuels ' %semislash%
$if     EXIST '../data/FDATASET.inc' $INCLUDE      '../data/FDATASET.inc';
$if not EXIST '../data/FDATASET.inc' $INCLUDE '../../base/data/FDATASET.inc';
%semislash%;

SET HYRSDATASET  'Characteristics of hydro reservoirs' %semislash%
$if     EXIST '../data/HYRSDATASET.inc' $INCLUDE      '../data/HYRSDATASET.inc';
$if not EXIST '../data/HYRSDATASET.inc' $INCLUDE '../../base/data/HYRSDATASET.inc';
%semislash%;

SET DF_QP  'Quantity and price information for elastic demands' %semislash%
$if     EXIST '../data/DF_QP.inc' $INCLUDE      '../data/DF_QP.inc';
$if not EXIST '../data/DF_QP.inc' $INCLUDE '../../base/data/DF_QP.inc';
%semislash%;

SET DEF  'Steps in elastic electricity demand'  %semislash%
$if     EXIST '../data/DEF.inc' $INCLUDE      '../data/DEF.inc';
$if not EXIST '../data/DEF.inc' $INCLUDE '../../base/data/DEF.inc';
%semislash%;

SET DEF_D1(DEF)   'Downwards steps in elastic el. demand, relative data format' %semislash%
$if     EXIST '../data/DEF_D1.inc' $INCLUDE      '../data/DEF_D1.inc';
$if not EXIST '../data/DEF_D1.inc' $INCLUDE '../../base/data/DEF_D1.inc';
%semislash%;

SET DEF_U1(DEF)   'Upwards steps in elastic el. demand, relative data format' %semislash%
$if     EXIST '../data/DEF_U1.inc' $INCLUDE      '../data/DEF_U1.inc';
$if not EXIST '../data/DEF_U1.inc' $INCLUDE '../../base/data/DEF_U1.inc';
%semislash%;

SET DEF_D2(DEF)   'Downwards steps in elastic el. demand, absolute Money and MW-incremental data format'%semislash%
$if     EXIST '../data/DEF_D2.inc' $INCLUDE      '../data/DEF_D2.inc';
$if not EXIST '../data/DEF_D2.inc' $INCLUDE '../../base/data/DEF_D2.inc';
%semislash%;

SET DEF_U2(DEF)   'Upwards steps in elastic el. demand, absolute Money and MW-incremental data format' %semislash%
$if     EXIST '../data/DEF_U2.inc' $INCLUDE      '../data/DEF_U2.inc';
$if not EXIST '../data/DEF_U2.inc' $INCLUDE '../../base/data/DEF_U2.inc';
%semislash%;

SET DEF_D3(DEF)   'Downwards steps in elastic el. demand, absolute Money and fraction of nominal demand data format' %semislash%
$if     EXIST '../data/DEF_D3.inc' $INCLUDE      '../data/DEF_D3.inc';
$if not EXIST '../data/DEF_D3.inc' $INCLUDE '../../base/data/DEF_D3.inc';
%semislash%;

SET DEF_U3(DEF)   'Upwards steps in elastic el. demand, absolute Money and fraction of nominal demand data format' %semislash%
$if     EXIST '../data/DEF_U3.inc' $INCLUDE      '../data/DEF_U3.inc';
$if not EXIST '../data/DEF_U3.inc' $INCLUDE '../../base/data/DEF_U3.inc';
%semislash%;

SET DHF  'Steps in elastic heat demand' %semislash%
$if     EXIST '../data/DHF.inc' $INCLUDE      '../data/DHF.inc';
$if not EXIST '../data/DHF.inc' $INCLUDE '../../base/data/DHF.inc';
%semislash%;

SET DHF_D1(DHF)    'Downwards steps in elastic heat demand, relative data format' %semislash%
$if     EXIST '../data/DHF_D1.inc' $INCLUDE      '../data/DHF_D1.inc';
$if not EXIST '../data/DHF_D1.inc' $INCLUDE '../../base/data/DHF_D1.inc';
%semislash%;

SET DHF_U1(DHF)    'Upwards steps in elastic heat demand, relative data format' %semislash%
$if     EXIST '../data/DHF_U1.inc' $INCLUDE      '../data/DHF_U1.inc';
$if not EXIST '../data/DHF_U1.inc' $INCLUDE '../../base/data/DHF_U1.inc';
%semislash%;

SET DHF_D2(DHF)    'Downwards steps in elastic heat demand, absolute Money and MW-incremental data format' %semislash%
$if     EXIST '../data/DHF_D2.inc' $INCLUDE      '../data/DHF_D2.inc';
$if not EXIST '../data/DHF_D2.inc' $INCLUDE '../../base/data/DHF_D2.inc';
%semislash%;

SET DHF_U2(DHF)    'Upwards steps in elastic heat demand, absolute Money and MW-incremental data format' %semislash%
$if     EXIST '../data/DHF_U2.inc' $INCLUDE      '../data/DHF_U2.inc';
$if not EXIST '../data/DHF_U2.inc' $INCLUDE '../../base/data/DHF_U2.inc';
%semislash%;

SET DHF_D3(DHF)    'Downwards steps in elastic heat demand, absolute Money and fraction of nominal demand data format' %semislash%
$if     EXIST '../data/DHF_D3.inc' $INCLUDE      '../data/DHF_D3.inc';
$if not EXIST '../data/DHF_D3.inc' $INCLUDE '../../base/data/DHF_D3.inc';
%semislash%;

SET DHF_U3(DHF)    'Upwards steps in elastic heat demand, absolute Money and fraction of nominal demand data format' %semislash%
$if     EXIST '../data/DHF_U3.inc' $INCLUDE      '../data/DHF_U3.inc';
$if not EXIST '../data/DHF_U3.inc' $INCLUDE '../../base/data/DHF_U3.inc';
%semislash%;

SET MPOLSET  'Emission and other policy data'   %semislash%
$if     EXIST '../data/MPOLSET.inc' $INCLUDE      '../data/MPOLSET.inc';
$if not EXIST '../data/MPOLSET.inc' $INCLUDE '../../base/data/MPOLSET.inc';
%semislash%;

SET C(CCC)    'Countries in the simulation'  %semislash%
$if     EXIST '../data/C.inc' $INCLUDE      '../data/C.inc';
$if not EXIST '../data/C.inc' $INCLUDE '../../base/data/C.inc';
%semislash%;

SET G(GGG)    'Generation technologies in the simulation'  %semislash%
$if     EXIST '../data/G.inc' $INCLUDE      '../data/G.inc';
$if not EXIST '../data/G.inc' $INCLUDE '../../base/data/G.inc';
%semislash%;

SET AGKN(AAA,GGG)   'Areas for possible location of new technologies'   %semislash%
$if     EXIST '../data/AGKN.inc' $INCLUDE      '../data/AGKN.inc';
$if not EXIST '../data/AGKN.inc' $INCLUDE '../../base/data/AGKN.inc';
%semislash%;

SET Y(YYY)    'Years in the simulation'   %semislash%
$if     EXIST '../data/Y.inc' $INCLUDE      '../data/Y.inc';
$if not EXIST '../data/Y.inc' $INCLUDE '../../base/data/Y.inc';
%semislash%;

SET S(SSS)    'Seasons in the simulation'   %semislash%
$if     EXIST '../data/S.inc' $INCLUDE      '../data/S.inc';
$if not EXIST '../data/S.inc' $INCLUDE '../../base/data/S.inc';
%semislash%;

SET T(TTT)    'Time periods within the season in the simulation'  %semislash%
$if     EXIST '../data/T.inc' $INCLUDE         '../data/T.inc';
$if not EXIST '../data/T.inc' $INCLUDE '../../base/data/T.inc';
%semislash%;

*SET DAYTYPE       'Types of days within the week, typically workdays/weekend' %semislash%
*$if     EXIST '../data/DAYTYPE.inc' $INCLUDE         '../data/DAYTYPE.inc';
*$if not EXIST '../data/DAYTYPE.inc' $INCLUDE '../../base/data/DAYTYPE.inc';
*%semislash%

SET TWORKDAY(TTT)   'Time segments, T, in workdays'  %semislash%
$if     EXIST '../data/TWORKDAY.inc' $INCLUDE         '../data/TWORKDAY.inc';
$if not EXIST '../data/TWORKDAY.inc' $INCLUDE '../../base/data/TWORKDAY.inc';
%semislash%

SET TWEEKEND(TTT)   'Time segments, T, in weekends'   %semislash%
$if     EXIST '../data/TWEEKEND.inc' $INCLUDE         '../data/TWEEKEND.inc';
$if not EXIST '../data/TWEEKEND.inc' $INCLUDE '../../base/data/TWEEKEND.inc';
%semislash%

SET ECONSET         'Set for econ'  %semislash%
$if     EXIST '../data/ECONSET.inc' $INCLUDE         '../data/ECONSET.inc';
$if not EXIST '../data/ECONSET.inc' $INCLUDE '../../base/data/ECONSET.inc';
%semislash%

SET ECONSETCATEGORY 'Set for econ'  %semislash%
$if     EXIST '../data/ECONSETCATEGORY.inc' $INCLUDE         '../data/ECONSETCATEGORY.inc';
$if not EXIST '../data/ECONSETCATEGORY.inc' $INCLUDE '../../base/data/ECONSETCATEGORY.inc';
%semislash%

$ifi not %X3V%==yes $goto X3V_label1

$if     EXIST '../data/X3VPLACE0.inc' $INCLUDE      '../data/X3VPLACE0.inc';
$if not EXIST '../data/X3VPLACE0.inc' $INCLUDE      '../../base/data/X3VPLACE0.inc';

$if     EXIST '../data/X3VPLACE.inc' $INCLUDE      '../data/X3VPLACE.inc';
$if not EXIST '../data/X3VPLACE.inc' $INCLUDE      '../../base/data/X3VPLACE.inc';

$if     EXIST '../data/X3VSTEP0.inc' $INCLUDE      '../data/X3VSTEP0.inc';
$if not EXIST '../data/X3VSTEP0.inc' $INCLUDE      '../../base/data/X3VSTEP0.inc';

$if     EXIST '../data/X3VSTEP.inc' $INCLUDE      '../data/X3VSTEP.inc';
$if not EXIST '../data/X3VSTEP.inc' $INCLUDE      '../../base/data/X3VSTEP.inc';

$if     EXIST '../data/X3VX.inc' $INCLUDE      '../data/X3VX.inc';
$if not EXIST '../data/X3VX.inc' $INCLUDE      '../../base/data/X3VX.inc';
*$ifi %X3V%==yes   $INCLUDE '../../base/addons/X3V/data/X3VSETS.inc';
$label X3V_label1

SET SCENARIO            'All scenarios'  %semislash%
$if     EXIST '../data/SCENARIO.inc' $INCLUDE         '../data/SCENARIO.inc';
$if not EXIST '../data/SCENARIO.inc' $INCLUDE '../../base/data/SCENARIO.inc';
%semislash%

SET SCENARSIM(SCENARIO) 'Scenarios in simulation'  %semislash%
$if     EXIST '../data/SCENARSIM.inc' $INCLUDE         '../data/SCENARSIM.inc';
$if not EXIST '../data/SCENARSIM.inc' $INCLUDE '../../base/data/SCENARSIM.inc';
%semislash%



* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%
* (see file balgams.opt):
%ONOFFCODELISTING%

*------------------------------------------------------------------------------
* Declaration of internal sets:
*------------------------------------------------------------------------------
* Internal sets and aliases in relation to geography.
* Note: although it is possible, you should generally not (i.e., don't!) use
* the following internal sets for data entry or data assignments
* (it may be impossible in future versions).
SET IR(RRR)            'Regions in the simulation';
SET IA(AAA)            'Areas in the simulation';
SET ICA(CCC,AAA)       'Assignment of areas to countries in the simulation';
* The simple way to limit the geographical scope of the model is to specify in the input data
* the set C as a proper subset of the set CCC,
* because the following mechanism will automatically exclude all regions
* and areas not in any country in C.
ICA(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);
IR(RRR) = YES$(SUM(C,CCCRRR(C,RRR)));
IA(AAA) = YES$(SUM(C,ICA(C,AAA)));

SET IS3(S)   'Present season simulated in balbase3';

SET AIND(AAA)  'Individual heating areas' //;
SET AAAOFFSHORE(AAA) 'Areas with offshore wind' //;

* Do not include individual heating areas if FV is not 'YES' in balopt.opt
$ifi not %FV%==yes IA(AIND)              =no;

*-------------------------------------------------------------------------------
*--- End: Definitions of SETS and ACRONYMS that are given in the $included files
*-------------------------------------------------------------------------------

*-------------------------------------------------------------------------------
*----- Definitions of ALIASES that are needed for data entry:
*-------------------------------------------------------------------------------


* Duplication of sets for describing electricity exchange between regions:
ALIAS (RRR,IRRRE,IRRRI);
ALIAS (IR,IRE,IRI);
* Duplication of sets for describing heat exchange between areas: /*varmetrans*/
ALIAS (AAA,IAAAE,IAAAI);
ALIAS (IA,IAE,IAI);
* Duplication of sets for fuel.
ALIAS (FFF,IFFFALIAS);

ALIAS(S,IS3LOOPSET);

* Duplication of sets for seasons and hours:
ALIAS (Y,IYALIAS);
ALIAS (S,ISALIAS);
ALIAS (T,ITALIAS);

*-------------------------------------------------------------------------------
*----- End: Definitions of ALIASES that are needed for data entry
*-------------------------------------------------------------------------------

*-------------------------------------------------------------------------------
*----- Any declarations and definitions of sets, aliases and acronyms for addon:
*-------------------------------------------------------------------------------


$ifi %COMBTECH%==yes
$if     EXIST '../data/ggcomb.inc' $INCLUDE         '../data/ggcomb.inc';
$ifi %COMBTECH%==yes
$if not EXIST '../data/ggcomb.inc' $INCLUDE '../../base/data/ggcomb.inc';

* Addon AGKNDISC: discrete size investment in technologies:
$ifi not %AGKNDISC%==yes  $goto label_AGKNDISC1

SET AGKNDISCAG(AAA,GGG)   'Areas for possible location of discrete capacity investments in technologies' %semislash%
$if     EXIST '../data/AGKNDISCAG.inc' $INCLUDE         '../data/AGKNDISCAG.inc';
$if not EXIST '../data/AGKNDISCAG.inc' $INCLUDE '../../base/data/AGKNDISCAG.inc';
%semislash%

SET AGKNDISCGSIZESET    'Set of possible sizes for discrete capacity investments in technologies' %semislash%
$if     EXIST '../data/AGKNDISCGSIZESET.inc' $INCLUDE         '../data/AGKNDISCGSIZESET.inc';
$if not EXIST '../data/AGKNDISCGSIZESET.inc' $INCLUDE '../../base/data/AGKNDISCGSIZESET.inc';
%semislash%

SET AGKNDISCGDATASET    'Technology investment data types for discrete capacity size investments' %semislash%
$if     EXIST '../data/AGKNDISCGDATASET.inc' $INCLUDE         '../data/AGKNDISCGDATASET.inc';
$if not EXIST '../data/AGKNDISCGDATASET.inc' $INCLUDE '../../base/data/AGKNDISCGDATASET.inc';
%semislash%

PARAMETER AGKNDISCGDATA(GGG,AGKNDISCGSIZESET,AGKNDISCGDATASET) 'Technology investment data for discrete capacity size investments' %semislash%
$if     EXIST '../data/AGKNDISCGDATA.inc' $INCLUDE         '../data/AGKNDISCGDATA.inc';
$if not EXIST '../data/AGKNDISCGDATA.inc' $INCLUDE '../../base/data/AGKNDISCGDATA.inc';
%semislash%

$label label_AGKNDISC1
* End: Addon AGKNDISC: discrete size investment in technologies.

$ifi not %HYRSBB123%==none    $include "..\..\base\addons\hyrsbb123\hyrsbb123internals.inc";
*-------------------------------------------------------------------------------
* End: Any declarations and definitions of sets, aliases and acronyms for addon
*-------------------------------------------------------------------------------




*-------------------------------------------------------------------------------
* The choice of model made in the balopt.opt fil is checked here,
* and basic sets concerning time within the year are reconstructed accordingly if needed:

*-------------------------------------------------------------------------------




*-------------------------------------------------------------------------------
*----- Any internal sets for addon to be placed here: --------------------------


$ifi %H2%==yes $include '../../base/addons/hydrogen/H2G.inc';

*----- End: Any internal sets for addon to be placed here: ---------------------
*-------------------------------------------------------------------------------



*------------------------------------------------------------------------------
* End: Declaration of internal sets
*------------------------------------------------------------------------------



*------------------------------------------------------------------------------
* Declaration and definition of numerical data: PARAMETERS and SCALARS:
*------------------------------------------------------------------------------


*------------------------------------------------------------------------------
*---- Technology data: ---------------------------------------------------------
*------------------------------------------------------------------------------
PARAMETER GDATA(GGG,GDATASET)    'Technologies characteristics' %semislash%
* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFDATALISTING%
$if     EXIST '../data/gdata.inc' $INCLUDE         '../data/gdata.inc';
$if not EXIST '../data/gdata.inc' $INCLUDE '../../base/data/gdata.inc';
%ONOFFCODELISTING%



*-------------------------------------------------------------------------------
* Definitions of internal sets relative to technologies,

* The following are convenient internal subsets of generation technologies:

SET IGCND(G)               'Condensing technologies';
SET IGBPR(G)               'Back pressure technologies';
SET IGEXT(G)               'Extraction technologies';
SET IGHOB(G)               'Heat-only boilers';
SET IGETOH(G)              'Electric heaters, heatpumps, electrolysis plants';
SET IGHSTO(G)              'Heat seasonal storage technologies';
SET IGHSTO_S(G)            'Long-time heat seasonal storage technologies';
SET IGHSTOALL(G)           'All heat seasonal storage technologies';
SET IGESTO(G)              'Electricity seasonal storage technologies';
SET IGHYRS(G)              'Hydropower with reservoir';
SET IGHYRR(G)              'Hydropower run-of-river no reservoir';
SET IGWND(G)               'Wind power technologies';
SET IGSOLE(G)              'Solar electrical power technologies';
SET IGSOLH(G)              'Solar heat technologies';
SET IGWAVE(G)              'Wave power technologies';
SET IGHH(G)                'Technologies generating heat-only';
SET IGHHNOSTO(G)           'Technologies generating heat-only, except storage';
SET IGNOTETOH(G)           'Technologies excluding electric heaters, heat pumps,electrolysis plants';
SET IGKH(G)                'Technologies with capacity specified on heat';
SET IGKHNOSTO(G)           'Technologies with capacity specified on heat, except storage';
SET IGKE(G)                'Technologies with capacity specified on electricity';
SET IGKENOSTO(G)           'Technologies with capacity specified on electricity, except storage';
SET IGDISPATCH(G)          'Dispatchable technologies';
SET IGEE(G)                'Technologies generating electricity only';
SET IGEENOSTO(G)           'Technologies generating electricity only, except storage';
SET IGKKNOWN(G)            'Technoloies for which the capacity is specified by the user';
SET IGKFIND(G)             'Technologies for which the capacity is found by algorithm';
SET IGEH(G)                'Technologies generating electricity and heat';
SET IGE(G)                 'Technologies generating electricity';
SET IGH(G)                 'Technologies generating heat';

* The following sets are special, and may be deleted/changed in future versions.
*SET IGNUC(G)               'Nuclear power technologies';
*SET IG2LEVEL(G)            'Slowly regulating technologies, level change only between weekday/weekend';
*SET IGEBASE(G)             'Power plants capable of supplying base load';
*SET IGERES(G)              'Power plants capable of supplying short term reserve';
* The following sets concern combination technologies.

* The following describes the main applications for the subsets:
*
* The sets:
* IGNUC,IGCND,IGBPR,IGEXT,IGHOB,IGETOH,IGHSTO,IGESTO,IGHYRS,IGHYRR,IGWND,IGSOLE,IGSOLH, IGWAVE
* are directly extracted from GDATA(G,'GDTYPE') and are used to reference
* technology types.
*
* IGHH and IGEE are used in the balance equations and for output control.
*
* IGHHNOSTO and IGEENOSTO is not currently used for anything.
*
* IGNOTETOH is used for O&M cost in the objective function, in the balance
* equation, in heat storage balance equations and in various output functions.
*
* IGKH and IGKE are used for capacity restrictions and for certain output files.
*
* IGKHNOSTO and IGKENOSTO are used for output.
*
* IGDISPATCH is used capacity restrictions and output.
*
* IGKKNOWN is used to exclude investment options.
*
* IGKFIND is used to single out investment options.
*
* IGEH is used for CHP specific taxes.
*
* IGE and IGH are used all over.


* The sets are defined based on information in PARAMETER GDATA.

* The specifications of technology type 'GDTYPE' in GDATA may use an acronym or a number.
* Under most circumstances an acronym is preferable, the list is given above.
* If an acroym can not be used, use the numbers consistently as seen below.

   IGCND(G)    = YES$((GDATA(G,'GDTYPE') EQ 1)  OR (GDATA(G,'GDTYPE') EQ GCND));
   IGBPR(G)    = YES$((GDATA(G,'GDTYPE') EQ 2)  OR (GDATA(G,'GDTYPE') EQ GBPR));
   IGEXT(G)    = YES$((GDATA(G,'GDTYPE') EQ 3)  OR (GDATA(G,'GDTYPE') EQ GEXT));
   IGHOB(G)    = YES$((GDATA(G,'GDTYPE') EQ 4)  OR (GDATA(G,'GDTYPE') EQ GHOB));
   IGETOH(G)   = YES$((GDATA(G,'GDTYPE') EQ 5)  OR (GDATA(G,'GDTYPE') EQ GETOH));
   IGHSTO(G)   = YES$((GDATA(G,'GDTYPE') EQ 6)  OR (GDATA(G,'GDTYPE') EQ GHSTO));
   IGESTO(G)   = YES$((GDATA(G,'GDTYPE') EQ 7)  OR (GDATA(G,'GDTYPE') EQ GESTO));
   IGHYRS(G)   = YES$((GDATA(G,'GDTYPE') EQ 8)  OR (GDATA(G,'GDTYPE') EQ GHYRS));
   IGHYRR(G)   = YES$((GDATA(G,'GDTYPE') EQ 9)  OR (GDATA(G,'GDTYPE') EQ GHYRR));
   IGWND(G)    = YES$((GDATA(G,'GDTYPE') EQ 10) OR (GDATA(G,'GDTYPE') EQ GWND));
   IGSOLE(G)   = YES$((GDATA(G,'GDTYPE') EQ 11) OR (GDATA(G,'GDTYPE') EQ GSOLE));
   IGSOLH(G)   = YES$((GDATA(G,'GDTYPE') EQ 12) OR (GDATA(G,'GDTYPE') EQ GSOLH));
   IGWAVE(G)   = YES$((GDATA(G,'GDTYPE') EQ 22) OR (GDATA(G,'GDTYPE') EQ GWAVE));
   IGHSTO_S(G) = YES$((GDATA(G,'GDTYPE') EQ 23) OR (GDATA(G,'GDTYPE') EQ GHSTO_S));

   IGHHNOSTO(G) = NO;   IGHHNOSTO(IGHOB)   = YES;  IGHHNOSTO(IGSOLH)= YES;

   IGHSTOALL(G) =       +IGHSTO(G)
                        +IGHSTO_S(G);

   IGHH(G)      =       IGHHNOSTO(G)
                       +IGHSTOALL(G);

   IGNOTETOH(G)= NOT IGETOH(G);

   IGDISPATCH(G)    =   IGCND(G)
                         +IGBPR(G)
                         +IGEXT(G)
                         +IGHOB(G)
                         +IGESTO(G)
                         +IGHSTO(G)
                         +IGHSTO_S(G)
                         +IGETOH(G)
                         +IGHYRS(G);

   IGEE(G)          =   IGCND(G)
                         +IGHYRS(G)
                         +IGHYRR(G)
                         +IGWND(G)
                         +IGSOLE(G)
                         +IGWAVE(G)
                         +IGESTO(G);

   IGEENOSTO(G)     =   IGCND(G)
                         +IGHYRS(G)
                         +IGHYRR(G)
                         +IGWND(G)
                         +IGSOLE(G)
                         +IGWAVE(G);

   IGKHNOSTO(G)     =   IGETOH(G)
                         +IGHHNOSTO(G);

   IGKH(G)          =     IGKHNOSTO(G)
                         +IGHSTOALL(G);

   IGKE(G)          =   IGCND(G)
                         +IGBPR(G)
                         +IGEXT(G)
                         +IGESTO(G)
                         +IGHYRS(G)
                         +IGHYRR(G)
                         +IGWND(G)
                         +IGSOLE(G)
                         +IGWAVE(G);

   IGKENOSTO(G)     =   IGKE(G)
                         -IGESTO(G);

   IGKKNOWN(G) = YES$(GDATA(G,'GDKVARIABL') EQ 0);
   IGKFIND(G) = NOT IGKKNOWN(G);

   IGEH(G) = IGBPR(G)+IGEXT(G)+IGETOH(G);
   IGE(G)=IGEE(G)+IGEH(G);
   IGH(G)=IGHH(G)+IGEH(G);

/* Hans ud
* Rev.3.01: The following definitions are not standardised in Balmorel
* (and may be deleted/changed in future versions),
* the user must supply data and code as desired:
   IGNUC(G)    = YES$((GDATA(G,'GDFUEL') EQ 1) OR (GDATA(G,'GDFUEL') EQ NUCLEAR));
   IG2LEVEL(G) = IGNUC(G);
* Hans:
   IGEBASE(IGE)=YES$(((GDATA(IGE,'GDFUEL') = FUEL_NATGAS) or (GDATA(IGE,'GDFUEL') = FUEL_COAL) or (GDATA(IGE,'GDFUEL') =FUEL_WOOD)) and (IGEXT(IGE) or IGCND(IGE)));
IGERES(G)=yes$(IGCND(G) or IGBPR(G) or IGEXT(G) or IGHYRS(G));
* End: Rev.3.01: The following definitions are not standardised in Balmorel.
*/



*-------------------------------------------------------------------------------
*----- Any internal sets assignments for addon to be placed here: --------------
*-------------------------------------------------------------------------------
* NOTE: When making new generation technology types. Some add-ons may already
* be using values of GDATA(G,'GDTYPE'). Check addons referenced here to maximize
* consistency and avoid conflicts. It is encouraged to avoid using the '-' set
* operator and instead use the '+' operator for compound assignments.

$ifi %COMBTECH%==yes   SET IGCOMB1(G)              'Combination technologies, primary';
$ifi %COMBTECH%==yes   SET IGCOMB2(G)              'Combination technologies, secondary with primary in G';
$ifi %COMBTECH%==yes   SET GGCOMB(GGG,IGGGALIAS)   'Combination techologies in the same combination';
$ifi %COMBTECH%==yes   IGCOMB1(G) =no;
$ifi %COMBTECH%==yes   IGCOMB2(G) =no;
$ifi %COMBTECH%==yes   $include '../../base/addons/combtech/combGassign.inc';
*

$ifi %H2%==yes $include '../../base/addons/hydrogen/H2Gassign.inc';
*---- Unit commitment --------------------------------------------------------------

$ifi %UnitComm%==yes $include '../../base/addons/unitcommitment/datadecl.inc';



$ifi %POLICIES%==yes  $ifi exist 'pol_sets.inc' $INCLUDE 'pol_sets.inc';
$ifi %POLICIES%==yes  $ifi not exist 'pol_sets.inc' $INCLUDE '../../base/addons/Policies/pol_sets.inc';

$ifi %SYSTEMCONST%==yes  $ifi exist 'sets_syscon.inc' $INCLUDE 'sets_syscon.inc';
$ifi %SYSTEMCONST%==yes  $ifi not exist 'sets_syscon.inc' $INCLUDE '../../base/addons/SystemConst/sets_syscon.inc';
*-------------------------------------------------------------------------------
*----- End: Any internal sets assignments for addon to be placed here ----------
*-------------------------------------------------------------------------------



*-------------------------------------------------------------------------------
*---- End: Technology data -----------------------------------------------------
*-------------------------------------------------------------------------------







*-------------------------------------------------------------------------------
*---- Annually specified generation capacities: --------------------------------
*-------------------------------------------------------------------------------

* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFDATALISTING%

PARAMETER GKFX(YYY,AAA,GGG)    'Capacity of existing generation technologies (MW)' %semislash%
$if     EXIST '../data/gkfx.inc' $INCLUDE      '../data/gkfx.inc';
$if not EXIST '../data/gkfx.inc' $INCLUDE '../../base/data/gkfx.inc';
%semislash%;

$ifi %MR%==yes $include '../../base/addons/gas/GKFX-MR.inc';



* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFCODELISTING%

*-------------------------------------------------------------------------------
*---- End: Annually specified generation capacities ----------------------------
*-------------------------------------------------------------------------------

SET IAGK(AAA,G) 'Technologies with exogenous capacity in a simulation year';
* Add all technologies with positive generation capacity within a simulation year.
IAGK(IA,G)$(SUM(Y,GKFX(Y,IA,G)))=yes;
$ifi %COMBTECH%==yes IAGK(IA,IGCOMB2)$SUM(IGCOMB1$(IAGK(IA,IGCOMB1) and GGCOMB(IGCOMB1,IGCOMB2)),1)=yes;



*-------------------------------------------------------------------------------
*---- Geographically specific values: -----------------------------------------
*-------------------------------------------------------------------------------




PARAMETER YVALUE(YYY)                  'Numerical value of the years labels';
PARAMETER FDATA(FFF,FDATASET)          'Fuel specific values';
PARAMETER IRESDE(RRR)                  'Reserve requirements attributable to demand (%)';
PARAMETER IRESWI(RRR)                  'Reserve requirements attributable to wind';

PARAMETER FMAXINVEST(CCC,FFF)          'Maximum investment (MW) by fuel type for each year simulated';
PARAMETER GROWTHCAP(C,GGG)             'Maximum model generated capacity increase (MW) from one year to the next';

PARAMETER DISLOSS_E(RRR)               'Loss in electricity distribution (fraction)';
PARAMETER DISLOSS_H(AAA)               'Loss in heat distribution (fraction)';
PARAMETER DISCOST_E(RRR)               'Cost of electricity distribution (Money/MWh)';
PARAMETER DISCOST_H(AAA)               'Cost of heat distribution (Money/MWh)';
PARAMETER FKPOT(CCCRRRAAA,FFF)         'Fuel potential restriction by geography (MW)';
PARAMETER FGEMIN(CCCRRRAAA,FFF)        'Minimum electricity generation by fuel (MWh)';
PARAMETER FGEMAX(CCCRRRAAA,FFF)        'Maximum electricity generation by fuel (MWh)';
$ifi %GMINF_DOL%==CCCRRRAAA_FFF         PARAMETER GMINF(CCCRRRAAA,FFF)             'Minimum fuel use (GJ) per year';
$ifi %GMINF_DOL%==YYY_CCCRRRAAA_FFF     PARAMETER GMINF(YYY,CCCRRRAAA,FFF)         'Minimum fuel use (GJ) per year';
$ifi %GMAXF_DOL%==CCCRRRAAA_FFF         PARAMETER GMAXF(CCCRRRAAA,FFF)             'Maximum fuel use (GJ) per year';
$ifi %GMAXF_DOL%==YYY_CCCRRRAAA_FFF     PARAMETER GMAXF(YYY,CCCRRRAAA,FFF)         'Maximum fuel use (GJ) per year';
$ifi %GEQF_DOL%== CCCRRRAAA_FFF         PARAMETER GEQF(CCCRRRAAA,FFF)              'Required fuel use (GJ) per year';
$ifi %GEQF_DOL%== YYY_CCCRRRAAA_FFF     PARAMETER GEQF(YYY,CCCRRRAAA,FFF)          'Required fuel use (GJ) per year';
PARAMETER WTRRSFLH(AAA)                'Full load hours for hydro reservoir plants (hours)';
PARAMETER WTRRRFLH(AAA)                'Full load hours for hydro run-of-river plants (hours)';
PARAMETER WNDFLH(AAA)                  'Full load hours for wind power (hours)';
PARAMETER SOLEFLH(AAA)                 'Full load hours for solarE power (hours)';
PARAMETER SOLHFLH(AAA)                 'Full load hours for solarH power (hours)';
PARAMETER WAVEFLH(AAA)                 'Full load hours for wave power'
PARAMETER HYRSDATA(AAA,HYRSDATASET,SSS)'Data for hydro with storage';
PARAMETER TAX_FHO(YYY,AAA,G)           'Fuel taxes on heat-only units';
PARAMETER TAX_FHO_C(FFF,CCC)           'Fuel taxes on heat-only units';
PARAMETER TAX_GH(YYY,AAA,G)            'Heat taxes on generation units';
PARAMETER TAX_FCHP_C(FFF,CCC)          'Fuel taxes on CHP units';
PARAMETER TAX_HHO_C(FFF,CCC)           'Fuel taxes on HO units';
PARAMETER TAX_F(FFF,CCC)               'Fuel taxes for heat and electricity production (Money/GJ)';
PARAMETER TAX_DE(CCC)                  'Consumers tax on electricity consumption (Money/MWh)';
PARAMETER TAX_DH(CCC)                  'Consumers tax on heat consumption (Money/MWh)';
PARAMETER ANNUITYC(CCC)                'Transforms investment to annual payment (fraction)';
PARAMETER GINVCOST(AAA,GGG)            'Investment cost for new technology (MMoney/MW)';
PARAMETER GOMVCOST(AAA,GGG)            'Variable operating and maintenance costs (Money/MWh)';
PARAMETER GOMFCOST(AAA,GGG)            'Annual fixed operating costs (kMoney/MW)';
PARAMETER GEFFDERATE(AAA,GGG)          'Reduction in fuel efficiency (fraction)';
PARAMETER DEFP_BASE(RRR)               'Nominal annual average consumer electricity price (Money/MWh)';
PARAMETER DHFP_BASE(AAA)               'Nominal annual average consumer heat price (Money/MWh)';

PARAMETER OHEATECON(YYY,CCC,RRR,AAA,GGG,ECONSET,ECONSETCATEGORY)         'Parameter for econ';


PARAMETER DE(YYY,RRR)                  'Annual electricity consumption (MWh)';
PARAMETER DH(YYY,AAA)                  'Annual heat consumption (MWh)';
*---- Transmission data: -------------------------------------------------------
PARAMETER XKINI(YYY,IRRRE,IRRRI)       'Initial transmission capacity between regions (MW)';
PARAMETER XINVCOST(IRRRE,IRRRI)        'Investment cost in new transmission capacity (Money/MW)';
PARAMETER XCOST(IRRRE,IRRRI)           'Transmission cost between regions (Money/MWh)';
PARAMETER XLOSS(IRRRE,IRRRI)           'Transmission loss between regions (fraction)';
$ifi %XKDERATE_DOL%==IRRRE_IRRRI          PARAMETER XKDERATE(IRRRE,IRRRI)         'Transmission capacity derating (fraction)';
$ifi %XKDERATE_DOL%==IRRRE_IRRRI_SSS      PARAMETER XKDERATE(IRRRE,IRRRI,SSS)     'Transmission capacity derating (fraction)';
$ifi %XKDERATE_DOL%==IRRRE_IRRRI_SSS_TTT  PARAMETER XKDERATE(IRRRE,IRRRI,SSS,TTT) 'Transmission capacity derating (fraction)';

*---- Third regions:
PARAMETER X3FX(YYY,RRR)                'Annual net electricity export to third regions';
$ifi %X3V%==yes PARAMETER X3VPIM(YYY,RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)    'Price (Money/MWh) of price dependent imported electricity';
$ifi %X3V%==yes PARAMETER X3VPEX(YYY,RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)    'Price (Money/MWh) of price dependent exported electricity';
$ifi %X3V%==yes PARAMETER X3VQIM(RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)        'Limit (MW) on price dependent electricity import';
$ifi %X3V%==yes PARAMETER X3VQEX(RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)        'Limit (MW) on price dependent electricity export';
* Fuel prices: -----------------------------------------------------------------

PARAMETER M_POL(YYY,MPOLSET,CCC)                   'Emission policy data';
*  Time:
PARAMETER WEIGHT_S(SSS)                            'Weight (relative length) of each season';
PARAMETER WEIGHT_T(TTT)                            'Weight (relative length) of each time period';
$ifi %GKDERATE_DOL%==AAA_GGG_SSS_TTT               PARAMETER GKDERATE(AAA,GGG,SSS,TTT)     'Reduction in capacity';
$ifi %GKDERATE_DOL%==AAA_GGG_SSS                   PARAMETER GKDERATE(AAA,GGG,SSS)         'Reduction in capacity';
PARAMETER DE_VAR_T(RRR,SSS,TTT)                    'Variation in electricity demand';
PARAMETER DH_VAR_T(AAA,SSS,TTT)                    'Variation in heat demand';
PARAMETER WTRRSVAR_S(AAA,SSS)                      'Variation of the water inflow to reservoirs';
PARAMETER WTRRRVAR_T(AAA,SSS,TTT)                  'Variation of generation of hydro run-of-river';
PARAMETER WND_VAR_T(AAA,SSS,TTT)                   'Variation of the wind generation';
PARAMETER SOLE_VAR_T(AAA,SSS,TTT)                  'Variation of the solar generation';
PARAMETER WAVE_VAR_T(AAA,SSS,TTT)                  'Variation of the wave generation'
PARAMETER X3FX_VAR_T(RRR,SSS,TTT)                  'Variation in fixed exchange with 3. region';
PARAMETER HYPPROFILS(AAA,SSS)                      'Hydro with storage seasonal price profile';
PARAMETER DEF_STEPS(RRR,SSS,TTT,DF_QP,DEF)         'Elastic electricity demands';
$ifi %DEFPCALIB%==yes PARAMETER DEFP_CALIB(RRR,SSS,TTT)  'Calibrate the price side of electricity demand';
PARAMETER DHF_STEPS(AAA,SSS,TTT,DF_QP,DHF)         'Elastic heat demands';
$ifi %DHFPCALIB%==yes PARAMETER DHFP_CALIB(AAA,SSS,TTT)  'Calibrate the price side of heat demand';
$ifi %YIELDREQUIREMENT%==yes  PARAMETER YIELDREQ(GGG) 'Differentiates yield requirements for different technologies';

SCALAR PENALTYQ  'Penalty on violation of equation';


* Data for handling of annual hydro constraints in BB3, to be saved by BB1/BB2 and used by BB3:
PARAMETER HYRSG(YYY,AAA,SSS)        'Water (hydro) generation quantity of the seasons to be transferred to model Balbase3 (MWh)';
PARAMETER VHYRS_SL(Y,AAA,SSS)       'To be saved for comparison with BB1/BB2 solution value for VHYRS_S.L (initial letter is V although declared as a parameter) (MWh)'
PARAMETER WATERVAL(YYY,AAA,SSS)     'Water value (in input Money) to be transferred to model Balbase3 (input-Money/MWh)';

* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFDATALISTING%

PARAMETER YVALUE(YYY)   'Numerical value of the years labels'  %semislash%
$if     EXIST '../data/YVALUE.inc' $INCLUDE      '../data/YVALUE.inc';
$if not EXIST '../data/YVALUE.inc' $INCLUDE '../../base/data/YVALUE.inc';
%semislash%;

PARAMETER FDATA(FFF,FDATASET)    'Fuel specific values'  %semislash%
$if     EXIST '../data/FDATA.inc' $INCLUDE      '../data/FDATA.inc';
$if not EXIST '../data/FDATA.inc' $INCLUDE '../../base/data/FDATA.inc';
%semislash%;

* The two specifications of fuel type 'FDACRONYM' and 'FDNB', have relative merits.
* Under most circumstances 'FDACRONYM' is preferable, and it is used internally in the GAMS code.
* Under these circumstances assign no value for 'FDNB'.
* If 'FDACRONYM' can not be used, use 'FDNB'.
* Always subsitute 'FDACRONYM' values by 'FDNB' values if the latter are non-zero:
FDATA(FFF,'FDACRONYM')$(NOT FDATA(FFF,'FDACRONYM')) = FDATA(FFF,'FDNB');

PARAMETER FMAXINVEST(CCC,FFF)   'Maximum investment (MW) by fuel type for each year simulated'    %semislash%
$if     EXIST '../data/FMAXINVEST.inc' $INCLUDE      '../data/FMAXINVEST.inc';
$if not EXIST '../data/FMAXINVEST.inc' $INCLUDE '../../base/data/FMAXINVEST.inc';
%semislash%;


PARAMETER GROWTHCAP(C,GGG)    'Maximum model generated capacity increase (MW) from one year to the next'   %semislash%
$if     EXIST '../data/GROWTHCAP.inc' $INCLUDE      '../data/GROWTHCAP.inc';
$if not EXIST '../data/GROWTHCAP.inc' $INCLUDE '../../base/data/GROWTHCAP.inc';
%semislash%;

PARAMETER DISLOSS_E(RRR)    'Loss in electricity distribution (fraction)'   %semislash%
$if     EXIST '../data/DISLOSS_E.inc' $INCLUDE      '../data/DISLOSS_E.inc';
$if not EXIST '../data/DISLOSS_E.inc' $INCLUDE '../../base/data/DISLOSS_E.inc';
%semislash%;

PARAMETER DISLOSS_H(AAA)    'Loss in heat distribution (fraction)'  %semislash%
$if     EXIST '../data/DISLOSS_H.inc' $INCLUDE      '../data/DISLOSS_H.inc';
$if not EXIST '../data/DISLOSS_H.inc' $INCLUDE '../../base/data/DISLOSS_H.inc';
%semislash%;

PARAMETER DISCOST_E(RRR)    'Cost of electricity distribution (Money/MWh)'  %semislash%
$if     EXIST '../data/DISCOST_E.inc' $INCLUDE      '../data/DISCOST_E.inc';
$if not EXIST '../data/DISCOST_E.inc' $INCLUDE '../../base/data/DISCOST_E.inc';
%semislash%;

PARAMETER DISCOST_H(AAA)    'Cost of heat distribution (Money/MWh)'     %semislash%
$if     EXIST '../data/DISCOST_H.inc' $INCLUDE      '../data/DISCOST_H.inc';
$if not EXIST '../data/DISCOST_H.inc' $INCLUDE '../../base/data/DISCOST_H.inc';
%semislash%;

PARAMETER FKPOT(CCCRRRAAA,FFF)    'Fuel potential restricted by geography (MW)'   %semislash%
$if     EXIST '../data/FKPOT.inc' $INCLUDE      '../data/FKPOT.inc';
$if not EXIST '../data/FKPOT.inc' $INCLUDE '../../base/data/FKPOT.inc';
%semislash%;


PARAMETER FGEMIN(CCCRRRAAA,FFF)    'Minimum electricity generation by fuel (MWh)'  %semislash%
$if     EXIST '../data/FGEMIN.inc' $INCLUDE      '../data/FGEMIN.inc';
$if not EXIST '../data/FGEMIN.inc' $INCLUDE '../../base/data/FGEMIN.inc';
%semislash%;

PARAMETER FGEMAX(CCCRRRAAA,FFF)     'Maximum electricity generation by fuel (MWh)'   %semislash%
$if     EXIST '../data/FGEMAX.inc' $INCLUDE      '../data/FGEMAX.inc';
$if not EXIST '../data/FGEMAX.inc' $INCLUDE '../../base/data/FGEMAX.inc';
%semislash%;

$ifi %GMINF_DOL%==CCCRRRAAA_FFF      PARAMETER GMINF(CCCRRRAAA,FFF)             'Minimum fuel use (GJ) per year' %semislash%
$ifi %GMINF_DOL%==YYY_CCCRRRAAA_FFF  PARAMETER GMINF(YYY,CCCRRRAAA,FFF)         'Minimum fuel use (GJ) per year' %semislash%
$if     EXIST '../data/GMINF.inc' $INCLUDE      '../data/GMINF.inc';
$if not EXIST '../data/GMINF.inc' $INCLUDE '../../base/data/GMINF.inc';
%semislash%;

$ifi %GMAXF_DOL%==CCCRRRAAA_FFF      PARAMETER GMAXF(CCCRRRAAA,FFF)             'Maximum fuel use (GJ) per year' %semislash%
$ifi %GMAXF_DOL%==YYY_CCCRRRAAA_FFF  PARAMETER GMAXF(YYY,CCCRRRAAA,FFF)         'Maximum fuel use (GJ) per year' %semislash%
$if     EXIST '../data/GMAXF.inc' $INCLUDE      '../data/GMAXF.inc';
$if not EXIST '../data/GMAXF.inc' $INCLUDE '../../base/data/GMAXF.inc';
%semislash%;

$ifi %GEQF_DOL%==CCCRRRAAA_FFF       PARAMETER GEQF(CCCRRRAAA,FFF)              'Required fuel use (GJ) per year' %semislash%
$ifi %GEQF_DOL%== YYY_CCCRRRAAA_FFF  PARAMETER GEQF(YYY,CCCRRRAAA,FFF)          'Required fuel use (GJ) per year' %semislash%
$if     EXIST '../data/GEQF.inc' $INCLUDE      '../data/GEQF.inc';
$if not EXIST '../data/GEQF.inc' $INCLUDE '../../base/data/GEQF.inc';
%semislash%;

* Maximum capacity at new technologies
PARAMETER GKNMAX(YYY,AAA,GGG)   'Maximum capacity at new technologies (MW)'  %semislash%
$if     EXIST '../data/GKNMAX.inc' $INCLUDE      '../data/GKNMAX.inc';
$if not EXIST '../data/GKNMAX.inc' $INCLUDE '../../base/data/GKNMAX.inc';
%semislash%;


PARAMETER WTRRSFLH(AAA)    'Full load hours for hydro reservoir plants (hours)'  %semislash%
$if     EXIST '../data/WTRRSFLH.inc' $INCLUDE      '../data/WTRRSFLH.inc';
$if not EXIST '../data/WTRRSFLH.inc' $INCLUDE '../../base/data/WTRRSFLH.inc';
%semislash%;

PARAMETER WTRRRFLH(AAA)    'Full load hours for hydro run-of-river plants (hours)'  %semislash%
$if     EXIST '../data/WTRRRFLH.inc' $INCLUDE      '../data/WTRRRFLH.inc';
$if not EXIST '../data/WTRRRFLH.inc' $INCLUDE '../../base/data/WTRRRFLH.inc';
%semislash%;

PARAMETER WNDFLH(AAA)    'Full load hours for wind power (hours)'  %semislash%
$if     EXIST '../data/WNDFLH.inc' $INCLUDE      '../data/WNDFLH.inc';
$if not EXIST '../data/WNDFLH.inc' $INCLUDE '../../base/data/WNDFLH.inc';
%semislash%;

PARAMETER SOLEFLH(AAA)    'Full load hours for solar power (hours)'  %semislash%
$if     EXIST '../data/SOLEFLH.inc' $INCLUDE      '../data/SOLEFLH.inc';
$if not EXIST '../data/SOLEFLH.inc' $INCLUDE '../../base/data/SOLEFLH.inc';
%semislash%;


PARAMETER SOLHFLH(AAA)    'Full load hours for solar power (hours)'  %semislash%
$if     EXIST '../data/SOLHFLH.inc' $INCLUDE      '../data/SOLHFLH.inc';
$if not EXIST '../data/SOLHFLH.inc' $INCLUDE '../../base/data/SOLHFLH.inc';
%semislash%;

PARAMETER WAVEFLH(AAA)    'Full load hours for wave power (hours)'  %semislash%
$if     EXIST '../data/WAVEFLH.inc' $INCLUDE      '../data/WAVEFLH.inc';
$if not EXIST '../data/WAVEFLH.inc' $INCLUDE '../../base/data/WAVEFLH.inc';
%semislash%;

PARAMETER HYRSDATA(AAA,HYRSDATASET,SSS)    'Data for hydro with storage'  %semislash%
$if     EXIST '../data/HYRSDATA.inc' $INCLUDE         '../data/HYRSDATA.inc';
$if not EXIST '../data/HYRSDATA.inc' $INCLUDE '../../base/data/HYRSDATA.inc';
%semislash%;

PARAMETER TAX_GF(YYY,AAA,G)    'Fuel taxes on heat-only units'  %semislash%
$if     EXIST '../data/TAX_GF.inc' $INCLUDE      '../data/TAX_GF.inc';
$if not EXIST '../data/TAX_GF.inc' $INCLUDE '../../base/data/TAX_GF.inc';
%semislash%;

PARAMETER TAX_GE(YYY,AAA,G)    'Electricity taxes on generation units and subsidies(-) (EURO 90/MWh)'  %semislash%
$if     EXIST '../data/TAX_GE.inc' $INCLUDE      '../data/TAX_GE.inc';
$if not EXIST '../data/TAX_GE.inc' $INCLUDE '../../base/data/TAX_GE.inc';
%semislash%;

PARAMETER TAX_GH(YYY,AAA,G)    'Heat taxes on generation units'   %semislash%
$if     EXIST '../data/TAX_GH.inc' $INCLUDE      '../data/TAX_GH.inc';
$if not EXIST '../data/TAX_GH.inc' $INCLUDE '../../base/data/TAX_GH.inc';
%semislash%;

PARAMETER TAX_KN(YYY,AAA,G)    'Tax (neg. subsidy) for investment in electricity generation (mEUR90/MW)'  %semislash%
$if     EXIST '../data/TAX_KN.inc' $INCLUDE      '../data/TAX_KN.inc';
$if not EXIST '../data/TAX_KN.inc' $INCLUDE '../../base/data/TAX_KN.inc';
%semislash%;
PARAMETER TAX_F(FFF,CCC)   'Fuel taxes for heat and electricity production (Money/GJ)'  %semislash%
$if     EXIST '../data/TAX_F.inc' $INCLUDE      '../data/TAX_F.inc';
$if not EXIST '../data/TAX_F.inc' $INCLUDE '../../base/data/TAX_F.inc';
%semislash%;

PARAMETER TAX_DE(CCC)    'Consumers tax on electricity consumption (Money/MWh)'  %semislash%
$if     EXIST '../data/TAX_DE.inc' $INCLUDE      '../data/TAX_DE.inc';
$if not EXIST '../data/TAX_DE.inc' $INCLUDE '../../base/data/TAX_DE.inc';
%semislash%;

PARAMETER TAX_DH(CCC)    'Consumers tax on heat consumption (Money/MWh)'  %semislash%
$if     EXIST '../data/TAX_DH.inc' $INCLUDE      '../data/TAX_DH.inc';
$if not EXIST '../data/TAX_DH.inc' $INCLUDE '../../base/data/TAX_DH.inc';
%semislash%;



PARAMETER ANNUITYC(CCC)   'Transforms investment to annual payment (fraction)'  %semislash%
$if     EXIST '../data/ANNUITYC.inc' $INCLUDE         '../data/ANNUITYC.inc';
$if not EXIST '../data/ANNUITYC.inc' $INCLUDE '../../base/data/ANNUITYC.inc';
%semislash%;

PARAMETER GINVCOST(AAA,GGG)    'Investment cost for new technology (MMoney/MW)'  %semislash%
$if     EXIST '../data/GINVCOST.inc' $INCLUDE         '../data/GINVCOST.inc';
$if not EXIST '../data/GINVCOST.inc' $INCLUDE '../../base/data/GINVCOST.inc';
%semislash%;

PARAMETER GOMVCOST(AAA,GGG)    'Variable operating and maintenance costs (Money/MWh)'  %semislash%
$if     EXIST '../data/GOMVCOST.inc' $INCLUDE         '../data/GOMVCOST.inc';
$if not EXIST '../data/GOMVCOST.inc' $INCLUDE '../../base/data/GOMVCOST.inc';
%semislash%;

PARAMETER GOMFCOST(AAA,GGG)    'Annual fixed operating costs (kMoney/MW)'  %semislash%
$if     EXIST '../data/GOMFCOST.inc' $INCLUDE         '../data/GOMFCOST.inc';
$if not EXIST '../data/GOMFCOST.inc' $INCLUDE '../../base/data/GOMFCOST.inc';
%semislash%;

PARAMETER GEFFDERATE(AAA,GGG)    'Reduction in fuel efficiency (fraction)'  %semislash%
$if     EXIST '../data/GEFFDERATE.inc' $INCLUDE         '../data/GEFFDERATE.inc';
$if not EXIST '../data/GEFFDERATE.inc' $INCLUDE '../../base/data/GEFFDERATE.inc';
%semislash%;
* For GEFFDERATE input data a 0 or an empty entry is interpreted to mean 1, therefore:
*GEFFDERATE(IA,G)$(GEFFDERATE(IA,G) EQ 0) = 1;

PARAMETER DEFP_BASE(RRR)    'Nominal annual average consumer electricity price (Money/MWh)'  %semislash%
$if     EXIST '../data/DEFP_BASE.inc' $INCLUDE         '../data/DEFP_BASE.inc';
$if not EXIST '../data/DEFP_BASE.inc' $INCLUDE '../../base/data/DEFP_BASE.inc';
%semislash%;

PARAMETER DHFP_BASE(AAA)    'Nominal annual average consumer heat price (Money/MWh)'  %semislash%
$if     EXIST '../data/DHFP_BASE.inc' $INCLUDE         '../data/DHFP_BASE.inc';
$if not EXIST '../data/DHFP_BASE.inc' $INCLUDE '../../base/data/DHFP_BASE.inc';
%semislash%;



*-------------------------------------------------------------------------------
*---- End: Geographically specific values --------------------------------------
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
*---- Annual electricity demand : ---------------------------------------------
*-------------------------------------------------------------------------------
PARAMETER DE(YYY,RRR)    'Annual electricity consumption (MWh)' %semislash%
$if     EXIST '../data/de.inc' $INCLUDE         '../data/de.inc';
$if not EXIST '../data/de.inc' $INCLUDE '../../base/data/de.inc';
%semislash%;


*-------------------------------------------------------------------------------
*---- Annual heat demand: -----------------------------------------------------
*-------------------------------------------------------------------------------
PARAMETER DH(YYY,AAA)    'Annual heat consumption (MWh)'  %semislash%
$if     EXIST '../data/dh.inc' $INCLUDE         '../data/dh.inc';
$if not EXIST '../data/dh.inc' $INCLUDE '../../base/data/dh.inc';
%semislash%;



*-------------------------------------------------------------------------------
*---- Transmission data: ------------------------------------------------------
*-------------------------------------------------------------------------------

PARAMETER XKINI(YYY,IRRRE,IRRRI)  'Initial transmission capacity between regions (MW)'   %semislash%
$if     EXIST '../data/XKINI.inc' $INCLUDE      '../data/XKINI.inc';
$if not EXIST '../data/XKINI.inc' $INCLUDE '../../base/data/XKINI.inc';
%semislash%;

PARAMETER XINVCOST(IRRRE,IRRRI)   'Investment cost in new transmission capacity (Money/MW)'    %semislash%
$if     EXIST '../data/XINVCOST.inc' $INCLUDE      '../data/XINVCOST.inc';
$if not EXIST '../data/XINVCOST.inc' $INCLUDE '../../base/data/XINVCOST.inc';
%semislash%;

PARAMETER XCOST(IRRRE,IRRRI)      'Transmission cost between regions (Money/MWh)'   %semislash%
$if     EXIST '../data/XCOST.inc' $INCLUDE      '../data/XCOST.inc';
$if not EXIST '../data/XCOST.inc' $INCLUDE '../../base/data/XCOST.inc';
%semislash%;

PARAMETER XLOSS(IRRRE,IRRRI)      'Transmission loss between regions (fraction)'  %semislash%
$if     EXIST '../data/XLOSS.inc' $INCLUDE         '../data/XLOSS.inc';
$if not EXIST '../data/XLOSS.inc' $INCLUDE '../../base/data/XLOSS.inc';
%semislash%;

$ifi %XKDERATE_DOL%==IRRRE_IRRRI          PARAMETER XKDERATE(IRRRE,IRRRI)         'Transmission capacity derating (fraction)'  %semislash%
$ifi %XKDERATE_DOL%==IRRRE_IRRRI_SSS_TTT  PARAMETER XKDERATE(IRRRE,IRRRI,SSS,TTT) 'Transmission capacity derating (fraction)'  %semislash%
$if     EXIST '../data/XKDERATE.inc' $INCLUDE         '../data/XKDERATE.inc';
$if not EXIST '../data/XKDERATE.inc' $INCLUDE '../../base/data/XKDERATE.inc';
%semislash%;

PARAMETER XMAXINV(IRRRE,IRRRI)   'Max investment in transmission capacity between two regions for each simulated year(each 5th year)'  %semislash%
$if     EXIST '../data/XMAXINV.inc' $INCLUDE         '../data/XMAXINV.inc';
$if not EXIST '../data/XMAXINV.inc' $INCLUDE '../../base/data/XMAXINV.inc';
%semislash%;


*-------------------------------------------------------------------------------
*---- Exchange with third countries: ------------------------------------------
*-------------------------------------------------------------------------------
* Fixed profile:
PARAMETER X3FX(YYY,RRR)    'Annual net electricity export to third regions'  %semislash%
$if     EXIST '../data/X3FX.inc' $INCLUDE      '../data/X3FX.inc';
$if not EXIST '../data/X3FX.inc' $INCLUDE '../../base/data/X3FX.inc';
%semislash%;


$ifi not %X3V%==yes $goto X3V_label3
*-------------------------------------------------------------------------------
* Price-dependant electricity exchange to places outside the simulated area
*-------------------------------------------------------------------------------

* Price (Money/MWh) for the price dependent electricity exchange.
* It will be assumed that prices should be positive.
* For import the prices should be increasing with ord(X3VSTEP0),
* for export the prices should be decreasing with ord(X3VSTEP0).


PARAMETER X3VPIM(YYY,RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)   'Price (Money/MWh) of price dependent imported electricity'  %semislash%
$if     EXIST '../data/X3VPIM.inc' $INCLUDE      '../data/X3VPIM.inc';
$if not EXIST '../data/X3VPIM.inc' $INCLUDE '../../base/data/X3VPIM.inc';
%semislash%;


PARAMETER X3VPEX(YYY,RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)   'Price (Money/MWh) of price dependent exported electricity'  %semislash%
$if     EXIST '../data/X3VPEX.inc' $INCLUDE      '../data/X3VPEX.inc';
$if not EXIST '../data/X3VPEX.inc' $INCLUDE '../../base/data/X3VPEX.inc';
%semislash%;


* Maximum quantity (MW) of price dependent electricity exchange per time segment:
PARAMETER X3VQIM(RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)   'Limit (MW) on price dependent electricity import'  %semislash%
$if     EXIST '../data/X3VQIM.inc' $INCLUDE      '../data/X3VQIM.inc';
$if not EXIST '../data/X3VQIM.inc' $INCLUDE '../../base/data/X3VQIM.inc';
%semislash%;


PARAMETER X3VQEX(RRR,X3VPLACE0,X3VSTEP0,SSS,TTT)   'Limit (MW) on price dependent electricity export'  %semislash%
$if     EXIST '../data/X3VQEX.inc' $INCLUDE      '../data/X3VQEX.inc';
$if not EXIST '../data/X3VQEX.inc' $INCLUDE '../../base/data/X3VQEX.inc';
%semislash%;

$label X3V_label3

*-------------------------------------------------------------------------------
* Annually specified fuel prices: ---------------------------------------------
*-------------------------------------------------------------------------------

PARAMETER FUELPRICE(YYY,AAA,FFF)                   'Fuel prices (Money/GJ)'   %semislash%
$if     EXIST '../data/FUELPRICE.inc' $INCLUDE      '../data/FUELPRICE.inc';
$if not EXIST '../data/FUELPRICE.inc' $INCLUDE '../../base/data/FUELPRICE.inc';
%semislash%;


*-------------------------------------------------------------------------------
*---- Emission policy data: ---------------------------------------------------
*-------------------------------------------------------------------------------

PARAMETER M_POL(YYY,MPOLSET,CCC)    'Emission policy data'   %semislash%
$if     EXIST '../data/m_pol.inc' $INCLUDE         '../data/m_pol.inc';
$if not EXIST '../data/m_pol.inc' $INCLUDE '../../base/data/m_pol.inc';
%semislash%;

*-------------------------------------------------------------------------------
*---- Seasonal and daily variations: ------------------------------------------
*-------------------------------------------------------------------------------


* DISSE FILER INDHOLDER NaSTEN ALLESAMMEN KODE, CONDITIONALS, ETC! Skal revideres!

PARAMETER WEIGHT_S(SSS)                            'Weight (relative length) of each season'    %semislash%
$if     EXIST '../data/WEIGHT_S.inc' $INCLUDE      '../data/WEIGHT_S.inc';
$if not EXIST '../data/WEIGHT_S.inc' $INCLUDE '../../base/data/WEIGHT_S.inc';
%semislash%;

PARAMETER WEIGHT_T(TTT)                            'Weight (relative length) of each time period'   %semislash%
$if     EXIST '../data/WEIGHT_T.inc' $INCLUDE      '../data/WEIGHT_T.inc';
$if not EXIST '../data/WEIGHT_T.inc' $INCLUDE '../../base/data/WEIGHT_T.inc';
%semislash%;


$ifi %GKDERATE_DOL%==AAA_GGG_SSS_TTT  PARAMETER GKDERATE(AAA,GGG,SSS,TTT)     'Reduction in capacity' %semislash%
$ifi %GKDERATE_DOL%==AAA_GGG_SSS      PARAMETER GKDERATE(AAA,GGG,SSS)         'Reduction in capacity' %semislash%
$if     EXIST '../data/GKDERATE.inc' $INCLUDE      '../data/GKDERATE.inc';
$if not EXIST '../data/GKDERATE.inc' $INCLUDE '../../base/data/GKDERATE.inc';
%semislash%;

PARAMETER DE_VAR_T(RRR,SSS,TTT)                    'Variation in electricity demand'   %semislash%
$if     EXIST '../data/DE_VAR_T.inc' $INCLUDE      '../data/DE_VAR_T.inc';
$if not EXIST '../data/DE_VAR_T.inc' $INCLUDE '../../base/data/DE_VAR_T.inc';
%semislash%;

PARAMETER DH_VAR_T(AAA,SSS,TTT)                    'Variation in heat demand'   %semislash%
$if     EXIST '../data/DH_VAR_T.inc' $INCLUDE      '../data/DH_VAR_T.inc';
$if not EXIST '../data/DH_VAR_T.inc' $INCLUDE '../../base/data/DH_VAR_T.inc';
%semislash%;

PARAMETER WTRRSVAR_S(AAA,SSS)                      'Variation of the water inflow to reservoirs'   %semislash%
$if     EXIST '../data/WTRRSVAR_S.inc' $INCLUDE      '../data/WTRRSVAR_S.inc';
$if not EXIST '../data/WTRRSVAR_S.inc' $INCLUDE '../../base/data/WTRRSVAR_S.inc';
%semislash%;

PARAMETER WTRRRVAR_T(AAA,SSS,TTT)                  'Variation of generation of hydro run-of-river'    %semislash%
$if     EXIST '../data/WTRRRVAR_T.inc' $INCLUDE      '../data/WTRRRVAR_T.inc';
$if not EXIST '../data/WTRRRVAR_T.inc' $INCLUDE '../../base/data/WTRRRVAR_T.inc';
%semislash%;

PARAMETER WND_VAR_T(AAA,SSS,TTT)                   'Variation of the wind generation'    %semislash%
$if     EXIST '../data/WND_VAR_T.inc' $INCLUDE      '../data/WND_VAR_T.inc';
$if not EXIST '../data/WND_VAR_T.inc' $INCLUDE '../../base/data/WND_VAR_T.inc';
%semislash%;

PARAMETER SOLE_VAR_T(AAA,SSS,TTT)                  'Variation of the solarE generation'   %semislash%
$if     EXIST '../data/SOLE_VAR_T.inc' $INCLUDE      '../data/SOLE_VAR_T.inc';
$if not EXIST '../data/SOLE_VAR_T.inc' $INCLUDE '../../base/data/SOLE_VAR_T.inc';
%semislash%;


PARAMETER SOLH_VAR_T(AAA,SSS,TTT)                  'Variation of the solarH generation'   %semislash%
$if     EXIST '../data/SOLH_VAR_T.inc' $INCLUDE      '../data/SOLH_VAR_T.inc';
$if not EXIST '../data/SOLH_VAR_T.inc' $INCLUDE '../../base/data/SOLH_VAR_T.inc';
%semislash%;

PARAMETER WAVE_VAR_T(AAA,SSS,TTT)                  'Variation of the solarH generation'   %semislash%
$if     EXIST '../data/WAVE_VAR_T.inc' $INCLUDE      '../data/WAVE_VAR_T.inc';
$if not EXIST '../data/WAVE_VAR_T.inc' $INCLUDE '../../base/data/WAVE_VAR_T.inc';
%semislash%;

PARAMETER X3FX_VAR_T(RRR,SSS,TTT)                  'Variation in fixed exchange with 3. region'   %semislash%
$if     EXIST '../data/X3FX_VAR_T.inc' $INCLUDE      '../data/X3FX_VAR_T.inc';
$if not EXIST '../data/X3FX_VAR_T.inc' $INCLUDE '../../base/data/X3FX_VAR_T.inc';
%semislash%;

PARAMETER HYPPROFILS(AAA,SSS)                      'Hydro with storage seasonal price profile'   %semislash%
$if     EXIST '../data/HYPPROFILS.inc' $INCLUDE      '../data/HYPPROFILS.inc';
$if not EXIST '../data/HYPPROFILS.inc' $INCLUDE '../../base/data/HYPPROFILS.inc';
%semislash%;

PARAMETER DEF_STEPS(RRR,SSS,TTT,DF_QP,DEF)         'Elastic electricity demands'   %semislash%
$if     EXIST '../data/DEF_STEPS.inc' $INCLUDE      '../data/DEF_STEPS.inc';
$if not EXIST '../data/DEF_STEPS.inc' $INCLUDE '../../base/data/DEF_STEPS.inc';
%semislash%;

$ifi %DEFPCALIB%==yes PARAMETER DEFP_CALIB(RRR,SSS,TTT)                  'Calibrate the price side of electricity demand'   %semislash%
$ifi %DEFPCALIB%==yes $if     EXIST '../data/DEFP_CALIB.inc' $INCLUDE      '../data/DEFP_CALIB.inc';
$ifi %DEFPCALIB%==yes $if not EXIST '../data/DEFP_CALIB.inc' $INCLUDE '../../base/data/DEFP_CALIB.inc';
$ifi %DEFPCALIB%==yes %semislash%;

PARAMETER DHF_STEPS(AAA,SSS,TTT,DF_QP,DHF)         'Elastic heat demands'   %semislash%
$if     EXIST '../data/DHF_STEPS.inc' $INCLUDE      '../data/DHF_STEPS.inc';
$if not EXIST '../data/DHF_STEPS.inc' $INCLUDE '../../base/data/DHF_STEPS.inc';
%semislash%;

$ifi %DHFPCALIB%==yes PARAMETER DHFP_CALIB(AAA,SSS,TTT)                  'Calibrate the price side of heat demand'   %semislash%
$ifi %DHFPCALIB%==yes $if     EXIST '../data/DHFP_CALIB.inc' $INCLUDE      '../data/DHFP_CALIB.inc';
$ifi %DHFPCALIB%==yes $if not EXIST '../data/DHFP_CALIB.inc' $INCLUDE '../../base/data/DHFP_CALIB.inc';
$ifi %DHFPCALIB%==yes %semislash%;


$ifi %bb3%==yes WEIGHT_T(T)=1;


$ifi %YIELDREQUIREMENT%==yes  PARAMETER YIELDREQ(GGG)  'Differentiates yield requirements for different technologies'   %semislash%
$ifi %YIELDREQUIREMENT%==yes  $if     EXIST '../data/YIELDREQ.inc' $INCLUDE      '../data/YIELDREQ.inc';
$ifi %YIELDREQUIREMENT%==yes  $if not EXIST '../data/YIELDREQ.inc' $INCLUDE '../../base/data/YIELDREQ.inc';
$ifi %YIELDREQUIREMENT%==yes  %semislash%;
* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFCODELISTING%

*-------------------------------------------------------------------------------
*---- Investments: --------------------------------------------------------------
*-------------------------------------------------------------------------------

* Investments made in BB2 are loaded automatically in non BB2 simulations
* conditioned by the ADDINVEST global variable (see balopt.opt).
* The parameter declaration is not conditional as it is used also when saving
* investments in a BB2 simulation conditioned by the MAKEINVEST global variable.

PARAMETER GKVACCDECOM(Y,AAA,G)   'Investments in generation technology by BB2 up to and including year Y with subtraction of decommissioning';
PARAMETER GKVACC(Y,AAA,G)        'Investments in generation technology by BB2 up to and including year Y without subtraction of decommissioning';
PARAMETER GVKGN(YYY,AAA,G)       'Investments in generation technology by BB2 in year Y';
PARAMETER XKACC(Y,IRRRE,IRRRI)   'Investments in electricity transmission by BB2 up to and including year Y';

$ifi %ADDINVEST%==yes execute_load '../../base/data/GKVACCDECOM.gdx', GKVACCDECOM;
$ifi %ADDINVEST%==yes execute_load '../../base/data/GKVACC.gdx', GKVACC;
$ifi %ADDINVEST%==yes execute_load '../../base/data/GVKGN.gdx', GVKGN;
$ifi %ADDINVEST%==yes execute_load '../../base/data/XKACC.gdx', XKACC;



*-------------------------------------------------------------------------------
*---- Miscellaneous ------------------------------------------------------------
*-------------------------------------------------------------------------------

* SCALAR OMONEY specifies output currency name and its exchange rate to input currency.
* Example of declaration:  'SCALAR OMONEY "EUR07" / 1.389 /;'.
* Since the text string holding the output currency is part of the declaration,
* the declaration is not given here in Balmorel.gms but in the included file.
* (For this reason you can not here apply the 'Semislash-idea'.)

$if     EXIST '../data/OMONEY.inc' $INCLUDE         '../data/OMONEY.inc';
$if not EXIST '../data/OMONEY.inc' $INCLUDE '../../base/data/OMONEY.inc';

* Include a case identification, if it exists.
* Note: the scalar OCASEID must not be declared here, only in an included file,
* or, if not found, in print1.inc; therefore this $include must come before $include of print1.inc.
* If using BUI, the file '../data/OCASEID.inc' will be provided by BUI.
*$if     EXIST '../data/OCASEID.inc' $INCLUDE      '../data/OCASEID.inc';


*-------------------------------------------------------------------------------
*----- Any parameters for addon to be placed here: -----------------------------
*-------------------------------------------------------------------------------
* These add-on data pertain to natural gas.
$ifi %GAS%==yes $INCLUDE '../../base/addons/gas/gasdata.inc';
$ifi %CAES%==yes $INCLUDE '../../base/addons/CAES/CAESdata.inc';
$ifi %X3V%==yes $INCLUDE '../../base/addons/x3v/data/x3vdata.inc';
$ifi %H2%==yes $INCLUDE '../../base/addons/Hydrogen/H2data.inc';
$ifi %NAP%==yes $INCLUDE '../../base/addons/NAP/NAPdata.inc';
* These add-on data pertain to transport technology(KHED).
$ifi %TSP%==yes  $INCLUDE '../../base/addons/Transport/TSPParameters.inc';
$ifi %HEATTRANS%==yes $if     EXIST '../data/htrans.inc' $INCLUDE         '../data/htrans.inc';
$ifi %HEATTRANS%==yes $if not EXIST '../data/htrans.inc' $INCLUDE '../../base/data/htrans.inc';

$ifi %POLICIES%==yes   $if exist 'POLREQ.inc' $INCLUDE 'POLREQ.inc';
$ifi %POLICIES%==yes   $if not exist 'POLREQ.inc' $INCLUDE '../../base/addons/policies/data/POLREQ.inc';

$ifi %SYSTEMCONST%==yes   $if exist 'BASELOADSERVICE.inc' $INCLUDE 'BASELOADSERVICE.inc';
$ifi %SYSTEMCONST%==yes   $if not exist 'BASELOADSERVICE.inc' $INCLUDE '../../base/addons/SystemConst/data/BASELOADSERVICE.inc';
* This file (if exists) contains:
* PARAMETER XHKINI(IAAAE,IAAAI)    'Initial heat transmission capacity between regions'
* PARAMETER XHINVCOST(IAAAE,IAAAI) 'Investment cost in new heat transmission cap'
* PARAMETER XHCOST(IAAAE,IAAAI)    'Heat transmission cost between countries'
* PARAMETER XHLOSS(IAAAE,IAAAI)    'Heat transmission loss between regions'


* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFDATALISTING%


SCALAR PENALTYQ  'Penalty on violation of equation'  %semislash%
$if     EXIST '../data/PENALTYQ.inc' $INCLUDE      '../data/PENALTYQ.inc';
$if not EXIST '../data/PENALTYQ.inc' $INCLUDE '../../base/data/PENALTYQ.inc';
%semislash%;

$ifi %BB4%==yes SET SIMYEARS '"Card(SIMYEARS) specifies the number of years in each Balbase4 model"'; /* Hans: BB4 er da ikke et addon!- flyt  */
$ifi %BB4%==yes ALIAS(SIMYEARS, SIMYEARS3)     /* Hans: hvorfor ikke SIMYEARS4 ? eller ISIMYEARS4 */
$ifi %BB4%==yes PARAMETER SIMDELTA(SIMYEARS) 'The number of years between two consequtive years in a BB4 model';
$ifi not %BB4%==yes $goto label_BB4_1      /* Hans: rodet  */
$if     EXIST '../data/SIMYEARS.inc' $INCLUDE         '../data/SIMYEARS.inc';
$if not EXIST '../data/SIMYEARS.inc' $INCLUDE '../../base/data/SIMYEARS.inc';
$if     EXIST '../data/SIMDELTA.inc' $INCLUDE         '../data/SIMDELTA.inc';
$if not EXIST '../data/SIMDELTA.inc' $INCLUDE '../../base/data/SIMDELTA.inc';
$label label_BB4_1
* Printing of data to the list file controlled by %ONOFFDATALISTING% and %ONOFFCODELISTING%:
%ONOFFCODELISTING%


*-------------------------------------------------------------------------------
*----- End: Any parameters for addon to be placed here -------------------------
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
* End: Declaration and definition of numerical data: PARAMETERS and SCALARS
*-------------------------------------------------------------------------------
DE_VAR_T(RRR,SSS,TTT)$(not IR(RRR)) = 0;
DE_VAR_T(RRR,SSS,TTT)$(not IR(RRR)) = 0;
DH_VAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;
X3FX_VAR_T(RRR,SSS,TTT)$(not IR(RRR)) = 0;
WND_VAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;
SOLE_VAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;
SOLE_VAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;
WAVE_VAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;
WTRRRVAR_T(AAA,SSS,TTT)$(not IA(AAA)) = 0;

*-------------------------------------------------------------------------------
* Declaration and definition of internal sets, aliases and parameters:
*-------------------------------------------------------------------------------


* Aliases relative to time:
ALIAS (Y,IYALIAS);

ALIAS (S,ISALIAS);
ALIAS (T,ITALIAS);
$ifi %BB4%==yes ALIAS (Y,IYALIAS44);    /* Hans: der er da ikke brug for så mange alias til Y? og harmoniser navnene */
$ifi %BB4%==yes  ALIAS (Y,YALIAS);      /* Denne findes jo allerde ovenfor (dvs., stantadr balmorel) */
$ifi %BB4%==yes ALIAS (Y,Y402);
$ifi %BB4%==yes ALIAS (Y,Y403);


$ifi %BB4%==yes SET IY411(Y)                'IY411 The years in current Balbase4 model';
$ifi %BB4%==yes SET IY410(Y)                'IY410 The years in the current Balbase4 model except the last year' ;
$ifi %BB4%==yes SET IY401(Y)                'IY401 The years in the current Balbase4 model except the first year' ;
$ifi %BB4%==yes SET IY4FIRST(Y)             "The first year the current Balbase4 model";
$ifi %BB4%==yes PARAMETER IY4REMAINY(Y)     "The number of remaining years the current Balbase4 model"; /* Hans  */

PARAMETER IGKFXYMAX(AAA,G) "The maximum over years in Y of exogenously specified capacity (MW)" ;

* Aliases relative to fuel:
ALIAS (FFF,IFFFALIAS);


* Internal sets and aliases in relation to geography.
* Note: although it is possible, you should generally not (i.e., don't!) use
* the following internal sets for data entry or data assignments
* (it may be impossible in future versions).
SET IR(RRR)            'Regions in the simulation';
SET IA(AAA)            'Areas in the simulation';
SET ICA(CCC,AAA)       'Assignment of areas to countries in the simulation';
ALIAS (IR,IRE,IRI);
ALIAS (IA,IAE,IAI);

* The simple way to limit the geographical scope of the model is to specify in the input data
* the set C as a proper subset of the set CCC,
* because the following mechanism will automatically exclude all regions
* and areas not in any country in C.
ICA(CCC,AAA) = YES$(SUM(RRR$ (RRRAAA(RRR,AAA) AND CCCRRR(CCC,RRR)),1) GT 0);
IR(RRR) = YES$(SUM(C,CCCRRR(C,RRR)));
IA(AAA) = YES$(SUM(C,ICA(C,AAA)));


*-------------------------------------------------------------------------------
* Application of default data:
*-------------------------------------------------------------------------------

* GOMVCOST, GOMFCOST and GINVCOST are given the default values in GDATA unless otherwise specified in data file:
GOMVCOST(IA,G)$((NOT GOMVCOST(IA,G)) AND (SUM(Y,GKFX(Y,IA,G)) OR AGKN(IA,G))) = GDATA(G,'GDOMVCOST0');
GOMFCOST(IA,G)$((NOT GOMFCOST(IA,G)) AND (SUM(Y,GKFX(Y,IA,G)) OR AGKN(IA,G))) = GDATA(G,'GDOMFCOST0');
GINVCOST(IA,G)$((NOT GINVCOST(IA,G)) AND (SUM(Y,GKFX(Y,IA,G)) OR AGKN(IA,G))) = GDATA(G,'GDINVCOST0');

*-------------------------------------------------------------------------------
* End of: Application of default data
*-------------------------------------------------------------------------------


* Time aggregation:
$ifi %timeaggr%==yes  $include '../../base/addons/TimeAggregation/timeaggr.inc';

* This file contains initialisations of printing of log and error messages:
$INCLUDE '../../base/logerror/logerinc/error1.inc';



* --- Internal sets in relation to time: ---------------------------------------
*SET IS3(S)   'Present season simulated in balbase3';
*ALIAS(S,IS3LOOPSET);

* The following relates technology and fuel:
SET IGF(GGG,FFF)   'Relation between technology type and fuel type';

* Internal scalars:

* Convenient Factors, typically relating Output and Input:
SCALAR IOF1000    'Multiplier 1000'       /1000/;
SCALAR IOF1000000 'Multiplier 1000000'    /1000000/;
SCALAR IOF0001    'Multiplier 0.001'      /0.001/;
SCALAR IOF0000001 'Multiplier 0.000001'   /0.000001/;
SCALAR IOF3P6     'Multiplier 3.6'        /3.6/;
SCALAR IOF24      'Multiplier 24'         /24/;
SCALAR IOF8760    'Multiplier 8760'       /8760/;
SCALAR IOF8784    'Multiplier 8784'       /8784/;
SCALAR IOF365     'Multiplier 365'        /365/;
SCALAR IOF05      'Multiplier 0.5'        /0.5/;
SCALAR IOF1_      'Multiplier 1 (special, to disappear in future versions'  /1/;
* Scalars for occational use, their meaning will be context dependent :
SCALAR ISCALAR1 '(Context dependent)';
SCALAR ISCALAR2 '(Context dependent)';
SCALAR ISCALAR3 '(Context dependent)';
SCALAR ISCALAR4 '(Context dependent)';

*------------------------------------------------------------------------------
* Internal sets:


SET IAGK_Y(YYY,AAA,G)   'Area, technology with positive capacity current simulation year';
SET IXKN(IRRRE,IRRRI)   'Pair of regions that may get new transmission capacity';

* Specification of where new endogenous generation capacity may be located:

SET IAGKN(YYY,AAA,G) 'Area, technology where technology may be invested based on AGKN and implicit constraints ';
* Initialisation: equal to AGKN:
IAGKN(Y,IA,G)=AGKN(IA,G);

* No investment in secondary combination technologies:
$ifi %COMBTECH%==yes    IAGKN(IA,IGCOMB2)=NO;

SET IPLUSMINUS "Violation of equation"  /IPLUS Violation of equation upwards, IMINUS  Violation of equation downwards/;
* Note: When placed on the left hand side of the equation
* the sign to the IMINUS and IPLUS terms should be - and +, respectively.
* This way the sign and the name will be intuitively consistent in equation listings.


*------------------------------------------------------------------------------
* Internal parameters and settings:
*------------------------------------------------------------------------------


* Set GDCV value to one for IGBPR and IGHOB units so that their fuel consumption
* can be found using the same formula as for IGCND and IGEXT:
GDATA(IGBPR,'GDCV') = 1;
GDATA(IGHOB,'GDCV') = 1;

* Specifying the relation between technology type and fuel type in IGF:

IGF(G,FFF)=YES$(GDATA(G,'GDFUEL') EQ FDATA(FFF,'FDACRONYM'));
IGF(G,FFF)=YES$(GDATA(G,'GDFUEL') EQ FDATA(FFF,'FDNB'));   /* This assignent line may in future versions become invalid, only fuels Acronyms will remain supported. */
IGF(G,FFF)$(GDATA(G,'GDFUEL') EQ FDATA(FFF,'FDACRONYM'))=YES;

PARAMETER IGKDERATE(AAA,G,S,T)     'Reduction in capacity';

* The following parameters contain information about CO2 and SO2 emission
* from technology G based on the fuel used and its emission data:

PARAMETER   IM_CO2(G)  'CO2 emission coefficient for fuel';
PARAMETER   IM_SO2(G)  'SO2 emission coefficient for fuel';
PARAMETER   IM_N2O(G)  'NO2 emission coefficient for fuel';

LOOP(FFF,
     IM_CO2(G)$IGF(G,FFF) = FDATA(FFF,'FDCO2');
     IM_SO2(G)$IGF(G,FFF) =
             FDATA(FFF,'FDSO2')$(GDATA(G,'GDDESO2') EQ 0) +
            (FDATA(FFF,'FDSO2')*(1-GDATA(G,'GDDESO2')))$(GDATA(G,'GDDESO2') GT 0);
     IM_N2O(G)$IGF(G,FFF) = FDATA(FFF,'FDN2O');
    );



* Further declarations relative to variations:
* Parameters holding the total weight in the (arbitrary) units of the weights
* used in input for each season and time period.
* To be used in calculations below.


PARAMETER IWEIGHSUMS          'Weight of the time of each season in S';
PARAMETER IWEIGHSUMT          'Weight of the time of each time period in T ';

* The (arbitrary) units used in the input are converted to days and hours,
* respectively. Note that IHOURSIN24 is given in hours.

PARAMETER IDAYSIN_S(SSS)      'Days in each season';         /* Note: to disappear in later versions, do not use */
PARAMETER IHOURSIN24(T)       'Hours in each time segment';  /* Note: to disappear in later versions, do not use */
PARAMETER IHOURSINST(SSS,T)   'Length of time segment (hours)';

* Annual amounts as expressed in the units of the weights and demands used
* in input in the file var.inc:

PARAMETER IDE_SUMST(RRR)      'Annual amount of electricity demand';
PARAMETER IDH_SUMST(AAA)      'Annual amount of heat demand';
PARAMETER IX3FXSUMST(RRR)     'Annual amount of electricity exported to third countries';

* Sums for finding the wind and solar generated electricity generation
* as expressed in the units of the weights and demands used in input:

PARAMETER IWND_SUMST(AAA)  'Annual amount of wind generated electricity';
PARAMETER ISOLESUMST(AAA)  'Annual amount of solar generated electricity';
PARAMETER ISOLHSUMST(AAA)  'Annual amount of solar generated heat';
PARAMETER IWAVESUMST(AAA)  'Annual amount of wave generated electricity';
PARAMETER IWTRRSSUM(AAA)   'Annual amount of hydro from reservoirs generated electricity';
PARAMETER IWTRRRSUM(AAA)   'Annual amount of hydro-run-of-river generated electricity';

*-------------------------------------------------------------------------------
* Set the time weights depending on the model:
*-------------------------------------------------------------------------------
* To guard against division-by-zero and other errors make sure that the following sums do not have inappropriate values:
$ifi %BB1%==yes    IWEIGHSUMS = SUM(S, WEIGHT_S(S));
$ifi %BB1%==yes    IWEIGHSUMT = SUM(T, WEIGHT_T(T));
$ifi %BB1%==yes    IDAYSIN_S(S)  = IOF365*WEIGHT_S(S) / IWEIGHSUMS;
$ifi %BB1%==yes    IHOURSIN24(T) = IOF24* WEIGHT_T(T) / IWEIGHSUMT;
$ifi %BB1%==yes    IHOURSINST(S,T)=IDAYSIN_S(S)*IHOURSIN24(T);
$ifi %BB1%==yes    IDE_SUMST(IR) = SUM((S,T), IHOURSINST(S,T)*DE_VAR_T(IR,S,T));
$ifi %BB1%==yes    IDH_SUMST(IA) = SUM((S,T), IHOURSINST(S,T)*DH_VAR_T(IA,S,T));
$ifi %BB1%==yes    IX3FXSUMST(IR) = SUM((S,T), IHOURSINST(S,T)*X3FX_VAR_T(IR,S,T));
$ifi %BB1%==yes    IWND_SUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WND_VAR_T(IA,S,T));
$ifi %BB1%==yes    ISOLESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLE_VAR_T(IA,S,T));
$ifi %BB1%==yes    ISOLHSUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLH_VAR_T(IA,S,T));
$ifi %BB1%==yes    IWAVESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WAVE_VAR_T(IA,S,T));
$ifi %BB1%==yes    IWTRRRSUM(IA)=SUM((S,T), IHOURSINST(S,T)*WTRRRVAR_T(IA,S,T));
$ifi %BB1%==yes    IWTRRSSUM(IA)=SUM(S, IDAYSIN_S(S) * WTRRSVAR_S(IA,S));

$ifi %BB2%==yes    IWEIGHSUMS = SUM(S, WEIGHT_S(S));
$ifi %BB2%==yes    IWEIGHSUMT = SUM(T, WEIGHT_T(T));
$ifi %BB2%==yes    IDAYSIN_S(S)  = IOF365*WEIGHT_S(S) / IWEIGHSUMS;
$ifi %BB2%==yes    IHOURSIN24(T) = IOF24* WEIGHT_T(T) / IWEIGHSUMT;
$ifi %BB2%==yes    IHOURSINST(S,T)=IDAYSIN_S(S)*IHOURSIN24(T);
$ifi %BB2%==yes    IDE_SUMST(IR) = SUM((S,T), IHOURSINST(S,T)*DE_VAR_T(IR,S,T));
$ifi %BB2%==yes    IDH_SUMST(IA) = SUM((S,T), IHOURSINST(S,T)*DH_VAR_T(IA,S,T));
$ifi %BB2%==yes    IX3FXSUMST(IR) = SUM((S,T), IHOURSINST(S,T)*X3FX_VAR_T(IR,S,T));
$ifi %BB2%==yes    IWND_SUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WND_VAR_T(IA,S,T));
$ifi %BB2%==yes    ISOLESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLE_VAR_T(IA,S,T));
$ifi %BB2%==yes    ISOLHSUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLH_VAR_T(IA,S,T));
$ifi %BB2%==yes    IWAVESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WAVE_VAR_T(IA,S,T));
$ifi %BB2%==yes    IWTRRRSUM(IA)=SUM((S,T), IHOURSINST(S,T)*WTRRRVAR_T(IA,S,T));
$ifi %BB2%==yes    IWTRRSSUM(IA)=SUM(S, IDAYSIN_S(S) * WTRRSVAR_S(IA,S));

$ifi %BB3%==yes    IWEIGHSUMS = SUM(SSS, WEIGHT_S(SSS));
$ifi %BB3%==yes    IWEIGHSUMT = SUM(T, WEIGHT_T(T));
$ifi %BB3%==yes    IDAYSIN_S(SSS)  = IOF365*WEIGHT_S(SSS) / IWEIGHSUMS;
$ifi %BB3%==yes    IHOURSIN24(T) = IOF24* WEIGHT_T(T) / IWEIGHSUMT;
$ifi %BB3%==yes    IHOURSINST(SSS,T)=IDAYSIN_S(SSS)*IHOURSIN24(T);
$ifi %BB3%==yes    IDE_SUMST(IR) = SUM((SSS,T), IHOURSINST(SSS,T)*DE_VAR_T(IR,SSS,T));
$ifi %BB3%==yes    IDH_SUMST(IA) = SUM((SSS,T), IHOURSINST(SSS,T)*DH_VAR_T(IA,SSS,T));
$ifi %BB3%==yes    IX3FXSUMST(IR) = SUM((SSS,T), IHOURSINST(SSS,T)*X3FX_VAR_T(IR,SSS,T));
$ifi %BB3%==yes    IWND_SUMST(IA)=SUM((SSS,T), IHOURSINST(SSS,T)*WND_VAR_T(IA,SSS,T));
$ifi %BB3%==yes    ISOLESUMST(IA)=SUM((SSS,T), IHOURSINST(SSS,T)*SOLE_VAR_T(IA,SSS,T));
$ifi %BB3%==yes    ISOLHSUMST(IA)=SUM((SSS,T), IHOURSINST(SSS,T)*SOLH_VAR_T(IA,SSS,T));
$ifi %BB3%==yes    IWAVESUMST(IA)=SUM((SSS,T), IHOURSINST(SSS,T)*WAVE_VAR_T(IA,SSS,T));
$ifi %BB3%==yes    IWTRRRSUM(IA)=SUM((SSS,T), IHOURSINST(SSS,T)*WTRRRVAR_T(IA,SSS,T));
$ifi %BB3%==yes    IWTRRSSUM(IA)=SUM(SSS, IDAYSIN_S(SSS) * WTRRSVAR_S(IA,SSS));


$ifi %BB4%==yes    IWEIGHSUMS = SUM(S, WEIGHT_S(S));
$ifi %BB4%==yes    IWEIGHSUMT = SUM(T, WEIGHT_T(T));
$ifi %BB4%==yes    IDAYSIN_S(SSS)  = IOF365*WEIGHT_S(SSS) / IWEIGHSUMS;
$ifi %BB4%==yes    IHOURSIN24(T) = IOF24* WEIGHT_T(T) / IWEIGHSUMT;
$ifi %BB4%==yes    IHOURSINST(S,T)=IDAYSIN_S(S)*IHOURSIN24(T);
$ifi %BB4%==yes    IDE_SUMST(IR) = SUM((S,T), IHOURSINST(S,T)*DE_VAR_T(IR,S,T));
$ifi %BB4%==yes    IDH_SUMST(IA) = SUM((S,T), IHOURSINST(S,T)*DH_VAR_T(IA,S,T));
$ifi %BB4%==yes    IX3FXSUMST(IR) = SUM((S,T), IHOURSINST(S,T)*X3FX_VAR_T(IR,S,T));
$ifi %BB4%==yes    IWND_SUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WND_VAR_T(IA,S,T));
$ifi %BB4%==yes    ISOLESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLE_VAR_T(IA,S,T));
$ifi %BB4%==yes    IWAVESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WAVE_VAR_T(IA,S,T));
$ifi %BB4%==yes    ISOLHSUMST(IA)=SUM((S,T), IHOURSINST(S,T)*SOLH_VAR_T(IA,S,T));
$ifi %BB4%==yes    IWAVESUMST(IA)=SUM((S,T), IHOURSINST(S,T)*WAVE_VAR_T(IA,S,T));
$ifi %BB4%==yes    IWTRRRSUM(IA)=SUM((S,T), IHOURSINST(S,T)*WTRRRVAR_T(IA,S,T));
$ifi %BB4%==yes    IWTRRSSUM(IA)=SUM(S, IDAYSIN_S(S) * WTRRSVAR_S(IA,S));


*-------------------------------------------------------------------------------
* End of: Set the time weights depending on the model
*-------------------------------------------------------------------------------


* PARAMETER IDEFP_T holds the price levels of individual steps
* in the electricity demand function, transformed to be comparable with
* production costs (including fuel taxes) by subtraction of taxes
* and distribution costs.

* Unit: Money/MWh.


PARAMETER IDEFP_T(RRR,SSS,TTT,DEF)    'Prices on elastic electricity demand steps (Money/MWh)';

IDEFP_T(IR,S,T,DEF_D1) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_D1)*DEFP_BASE(IR)
- SUM(C$CCCRRR(C,IR),TAX_DE(C)) - DISCOST_E(IR)
$ifi %DEFPCALIB%==yes  + DEFP_CALIB(IR,S,T)
;

IDEFP_T(IR,S,T,DEF_U1) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_U1)*DEFP_BASE(IR)
- SUM(C$CCCRRR(C,IR),TAX_DE(C)) - DISCOST_E(IR)
$ifi %DEFPCALIB%==yes  + DEFP_CALIB(IR,S,T)
;

IDEFP_T(IR,S,T,DEF_D2) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_D2);

IDEFP_T(IR,S,T,DEF_U2) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_U2);

IDEFP_T(IR,S,T,DEF_D3) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_D3);

IDEFP_T(IR,S,T,DEF_U3) = DEF_STEPS(IR,S,T,'DF_PRICE',DEF_U3);

* PARAMETER IDHFP_T holds the price levels of individual steps
* in the electricity demand function, transformed to be comparable with
* production costs (including fuel taxes) by subtraction of consumer taxes
* and distribution costs.

* Unit: Money/MWh.


PARAMETER IDHFP_T(AAA,SSS,TTT,DHF)   'Prices on elastic heat demand steps (Money/MWh)';

IDHFP_T(IA,S,T,DHF)$(DHF_D1(DHF)+DHF_U1(DHF)+DHF_D2(DHF)+DHF_U2(DHF)+DHF_D2(DHF)+DHF_U2(DHF))=
   DHF_STEPS(IA,S,T,'DF_PRICE',DHF)*DHFP_BASE(IA) - SUM(C$ICA(C,IA),TAX_DH(C)) - DISCOST_H(IA)
$ifi %DHFPCALIB%==yes  + DHFP_CALIB(IA,S,T)
;


* Demand of electricity (MW) and heat (MW) current simulation year:
PARAMETER IDE_T_Y(Y,RRR,S,T)       'Electricity demand (MW) time segment (S,T)   current simulation year',
          IDH_T_Y(Y,AAA,S,T)      'Heat demand (MW) time segment (S,T) current simulation year';
* Generation capacity (MW) at the beginning of current simulation year,
* specified by GKFX and by accumulated endogeneous investments, respectively:
PARAMETER IGKFX_Y(YYY,AAA,GGG)     'Externally given generation capacity in year Y (MW)',
          IGKFX_Y_1(YYY,AAA,GGG)   'Externally given generation capacity in year -1 (MW)',
          IGKVACCTOY(YYY,AAA,G)    'Internally given generation capacity at beginning of year (MW)(cumulative investments minus decommissioning)',
*          IGKVACCTOYNODECOM(G,AAA)'Cumulative investments in generation capacity at beginning of year',
          IGKVACCEOY(YYY,AAA,G)    'Internally given generation capacity at end of year (MW)(cumulative investments minus decommissioning)';


* Emission policy data during current simulation year:
PARAMETER ITAX_CO2_Y(Y,C) 'Tax on CO2 (Money/t)' ,
          ITAX_SO2_Y(Y,C)'Tax on SO2 (Money/t)',
          ITAX_NOX_Y(Y,C)'Tax on NOX (Money/kg)';
PARAMETER ILIM_CO2_Y(Y,C) 'CO2 emission limit',
          ILIM_SO2_Y(Y,C)'SO2 emission limit',
          ILIM_NOX_Y(Y,C)'NOX emission limit';

* Transmission capacity (MW) between regions RE (exporting) and  RI (importing)
* at the beginning of current simulation year:
PARAMETER IXKINI_Y(Y,IRRRE,IRRRI)    'Externally given transmission capacity between regions at beginning of year (MW)',
          IXKVACCTOY(Y,IRRRE,IRRRI) 'Internally given transmission capacity at beginning of year (MW)(cumulative investments)';

* Possibilities for new transmission lines:

IXKN(IRE,IRI) = NO;


* Fixed exchange with third countries (MW) current simulation year:
PARAMETER IX3FX_T_Y(Y,RRR,S,T) 'Export to third countries for each time segment (MW)';


* Fuel price for current simulation year:
PARAMETER IFUELP_Y(Y,AAA,FFF) 'Fuel price in the year simulated';


* Inflow in areas each season:
* The following is used in balbase1.sim and balbase2.sim
PARAMETER IHYINF_S(AAA,SSS)  'Water inflow to hydro reservoirs in areas in each season (MWh/MW)';

* In BB3 one of the following parameters are used to control the use of hydro:
PARAMETER IHYFXRW(RRR,SSS)   'Water quantity to be transferred to model Balbase3 (MWh)' ;
* OR the following is used. Conditioned by %WATERVAL%
PARAMETER IWATERVAL(AAA,SSS)   'Water price (value) to be transferred to model Balbase3 (Money/MWh)' ;




PARAMETER IGROWTHCAP(C,G)        'Limit on growth of technology dependant on years between optimisation';


PARAMETER IGKNMAX_Y(YYY,AAA,G)   'Maximum capacity at new technologies (MW)';

*-------------------------------------------------------------------------------
*----- Any internal sets and parameters for addon to be placed here: -----------
*-------------------------------------------------------------------------------
* Internals for GAS moved up just above calculation of weights and dump of
* input data.
* These internal parameters pertain to hydrogen technologies.
$ifi %H2%==yes $include '../../base/addons/Hydrogen/H2InternalParameters.inc';
* These internal parameters pertain to natural gas.
$ifi %GAS%==yes $include '../../base/addons/gas/gasinternal.inc';
* These internal parameters pertain to price sensitivy electricity exchange with
* third countries.
$ifi %X3V%==yes $include '../../base/addons/x3v/model/x3vinternal.inc';
* These internal parameters and sets pertain to heat transmission.
$if %heattrans% == yes $include '../../base/addons/heattrans/model/htinternal.inc';

$ifi %AGKNDISC%==yes   $include '../../base/addons/agkndisc/agkndiscinternal.inc';

*-------------------------------------------------------------------------------
*----- End: Any internal sets and parameters for addon to be placed here -------
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
* End: Internal parameters and settings
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
* Possibly write input data, prepare output file possibilities:
*-------------------------------------------------------------------------------

* The following file contains definitions of logical file names
* and the associated names of files that may be used for printout of simulation results.
* It also contains various definitions that are useful for the production and layout of the output.

* Prepare some printing possibilities:
$INCLUDE '../../base/output/printout/printinc/print1.inc';

* Overview of input data in text format (see the description at the top of the file inputout):
$ifi %inputdatatxt%== yes        $INCLUDE '../../base/output/printout/printinc/inputout.inc';
$ifi %inputdatatxt%== yesnosolve $INCLUDE '../../base/output/printout/printinc/inputout.inc';
$ifi %inputdatatxt%== yesnosolve $goto ENDOFMODEL
* Unload input data to gdx file:
* Note that the execute_unload command will also identify variables and equations
$ifi %INPUTDATA2GDX%==yes execute_unload '"%relpathInputdata2GDX%INPUTDATAOUT.gdx"';
* Transfer inputdata a seperate Access file (only possible if %INPUTDATA2GDX%==yes):
$ifi %INPUTDATAGDX2MDB%==yes execute '=GDX2ACCESS "%relpathInputdata2GDX%INPUTDATAOUT.gdx"';
* Transfer to Excel, read the identifiers to be transferred from file inputdatagdx2xls.txt (only possible if %INPUTDATA2GDX%==yes):
* Note: presently not working (the relevant data is not set i file inputdatagdx2xls.txt):
* NOTWORKING (i.e. you MUST have '$setglobal INPUTDATAGDX2XLS'): Note:  GAMS version 22.7 and later have better support for this....
*$ifi %INPUTDATAGDX2XLS%==yes  execute  "GDXXRW.EXE Input=%relpathInputdata2GDX%INPUTDATAOUT.gdx  Output=%relpathInputdata2GDX%INPUTDATAOUT.xls  @%relpathModel%inputdatagdx2xls.txt";


*-------------------------------------------------------------------------------
* End: Possibly write input data, prepare output file possibilities
*-------------------------------------------------------------------------------



$ifi %REShareE%==yes $include '../addons/REShareE/demodata/RESEdata.inc';
$ifi %REShareE%==yes $include '../addons/REShareE/RESEintrn.inc';
$ifi %REShareE%==yes file REShareEPrt4 / '../printout/RESEprt4.out' /;

*$ifi %REShareEH%==yes $include '../addons/REShareEH/demodata/RESEHdata.inc';
*$ifi %REShareEH%==yes $include '../addons/REShareEH/RESEHintrn.inc';
*$ifi %REShareEH%==yes file REShareEHPrt4 / '../printout/RESEHprt4.out' /;

$ifi %REShareEH%==yes
$if     EXIST '../data/RESEHDATA.inc' $INCLUDE         '../data/RESEHDATA.inc';
$ifi %REShareEH%==yes
$if not EXIST '../data/RESEHDATA.inc' $INCLUDE '../../base/data/RESEHDATA.inc';
$ifi %REShareEH%==yes $include '../../base/addons/REShareEH/RESEHintrn.inc';
$ifi %REShareEH%==yes file REShareEHPrt4 / '../printout/RESEHprt4.out' /;

*------------------------------

* A number of input data IDs contain more information than is actually used with the set-up of the model.
* To reduce use of memory space and to reduce further processing and storage of unused data
* some of the larger data IDs are here reduced by resetting unused data items to default values.

DE_VAR_T(RRR,SSS,TTT)$((NOT IR(RRR)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
DH_VAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
WND_VAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
SOLE_VAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
SOLH_VAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
WTRRSVAR_S(AAA,SSS)$((NOT IA(AAA)) OR (NOT S(SSS))) = 0;
WTRRRVAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
WAVE_VAR_T(AAA,SSS,TTT)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
X3FX_VAR_T(RRR,SSS,TTT)$((NOT IR(RRR)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
DEF_STEPS(RRR,SSS,TTT,DF_QP,DEF)$((NOT IR(RRR)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
DEF_STEPS(IR,S,T,DF_QP,DEF)$((NOT DEF_D1(DEF) AND (NOT DEF_D2(DEF)) AND (NOT DEF_D3(DEF)) AND (NOT DEF_U1(DEF)) AND (NOT DEF_U2(DEF)) AND (NOT DEF_U3(DEF)))) = 0;
DHF_STEPS(AAA,SSS,TTT,DF_QP,DHF)$((NOT IA(AAA)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
DHF_STEPS(IA,S,T,DF_QP,DHF)$((NOT DHF_D1(DHF) AND (NOT DHF_D2(DHF)) AND (NOT DHF_D3(DHF)) AND (NOT DHF_U1(DHF)) AND (NOT DHF_U2(DHF)) AND (NOT DHF_U3(DHF)))) = 0;
*GKDERATE(AAA,GGG,SSS)$((NOT IA(AAA)) OR (NOT G(GGG)) OR (NOT S(SSS))) = 0;
$ifi %GKDERATE_DOL%==AAA_GGG_SSS_TTT     GKDERATE(AAA,GGG,SSS,TTT)$((NOT IA(AAA)) OR (NOT G(GGG)) OR (NOT S(SSS)) OR (NOT T(TTT))) = 0;
$ifi %GKDERATE_DOL%==AAA_GGG_SSS         GKDERATE(AAA,GGG,SSS)$((NOT IA(AAA)) OR (NOT G(GGG)) OR (NOT S(SSS))) = 0;
GKNMAX(YYY,AAA,GGG)$((NOT Y(YYY)) OR (NOT IA(AAA))) = 0;

$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_LIGNITE   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_FUELOIL   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_LIGHTOIL  )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_ORIMULSION)=yes;
$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_SHALE     )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGCND)$(GDATA(IGCND,'GDFUEL') EQ FUEL_PEAT      )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_NATGAS   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_COAL      )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_LIGNITE   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_FUELOIL   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_LIGHTOIL  )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_ORIMULSION)=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_SHALE     )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGEXT)$(GDATA(IGEXT,'GDFUEL') EQ FUEL_PEAT      )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_NATGAS   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_COAL      )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_LIGNITE   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_FUELOIL   )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_LIGHTOIL  )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_ORIMULSION)=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_SHALE     )=yes;
$ifi %DECOMP%==yes IGDECOMP(IGBPR)$(GDATA(IGBPR,'GDFUEL') EQ FUEL_PEAT      )=yes;

* $ifi %DECOMP%==yes IGDECOMP(IGWND)$(not SUM((YYY,AAAOFFSHORE), GKFX(YYY,AAAOFFSHORE,IGWND)))=yes;
$ifi %DECOMP%==yes GKFX(YYY,AAA,IGDECOMP)$((ICA('Sweden',AAA) or ICA('Norway',AAA) or ICA('Finland',AAA) or ICA('Germany',AAA)) and ord(YYY) GT SUM(YYYALIAS$(DECOMPYEAR(YYYALIAS)), ord(YYYALIAS)))
$ifi %DECOMP%==yes                = GKFX(YYY,AAA,IGDECOMP)*(1-ANNUALDECOMP)**(ord(YYY) - SUM(YYYALIAS$(DECOMPYEAR(YYYALIAS)), ord(YYYALIAS)));


* Unload input data to gdx and possibly MDB files.
* Note that this is a compile time operation, such that only the 'direct' data
* definitions (and no assignments) are reflected:
execute_unload '%relpathModel%..\output\temp\1INPUT.gdx';

*------------------------------

* Begin BB4 group
SCALAR ORD_YALIAS "The ord() (relative to Y) of the first year of the present Balmbase4 model"; /* Hans : stavefejl Balmbase4; og bør vel starte med 'I' */
SCALAR YVALUE_YALIAS "";          /* Hans :  bør vel starte med 'I' */
*BB4: parameter used to store all investments.
PARAMETER IVGKN(Y,AAA,GGG) "Accumulated capacity (MW) at the beginning of the first year in model Balbase4" ;
PARAMETER IGKVACCTOT(Y,AAA,G) " ";
PARAMETER IVXKN(Y,IRRRE,IRRRI)   " ";
$ifi %BB4%==yes PARAMETER SIMWEIGHT(SIMYEARS);  /* hANS denne kan udgå!  */
$ifi %BB4%==yes PARAMETER ORD_IY(SIMYEARS) "The ord of the years Y over which the present Balbase4 model is formulated";  /* hANS ny tekst, og  denne bør omdøbes!  */
* End BB4 group

*-------------------------------------------------------------------------------
*  Declaration of VARIABLES:
*-------------------------------------------------------------------------------


FREE     VARIABLE VOBJ                           'Objective function value (MMoney)';
POSITIVE VARIABLE VGE_T(Y,AAA,G,S,T)               'Electricity generation (MW), existing units';
POSITIVE VARIABLE VGEN_T(Y,AAA,G,S,T)              'Electricity generation (MW), new units';
POSITIVE VARIABLE VGH_T(Y,AAA,G,S,T)               'Heat generation (MW), existing units';
POSITIVE VARIABLE VX_T(Y,IRRRE,IRRRI,S,T)          'Electricity export from region IRRRE to IRRRI (MW)';
POSITIVE VARIABLE VGHN_T(Y,AAA,G,S,T)              'Heat generation (MW), new units';
POSITIVE VARIABLE VGKN(YYY,AAA,G)                   'New generation capacity (MW)';
POSITIVE VARIABLE VXKN(Y,IRRRE,IRRRI)              'New electricity transmission capacity (MW)';
POSITIVE VARIABLE VDECOM(YYY,AAA,G)                 'Decommissioned capacity(MW)';
POSITIVE VARIABLE VDEF_T(Y,RRR,S,T,DEF)            'Flexible electricity demands (MW)';
POSITIVE VARIABLE VDHF_T(Y,AAA,S,T,DHF)            'Flexible heat demands (MW)';
POSITIVE VARIABLE VGHYPMS_T(Y,AAA,S,T)             'Contents of pumped hydro storage (MWh)';
POSITIVE VARIABLE VHYRS_S(Y,AAA,S)                 'Hydro energy equivalent at the start of the season (MWh)';
POSITIVE VARIABLE VESTOLOADT(Y,AAA,S,T)            'Loading of electricity storage (MW)';
POSITIVE VARIABLE VHSTOLOADT(Y,AAA,S,T)            'Loading of heat storage (MW)';
POSITIVE VARIABLE VESTOVOLT(Y,AAA,S,T)             'Electricity storage contents at beginning of time segment (MWh)';
POSITIVE VARIABLE VHSTOVOLT(Y,AAA,S,T)             'Heat storage contents at beginning of time segment (MWh)';
POSITIVE VARIABLE VQEEQ(Y,RRR,S,T,IPLUSMINUS)      'Feasibility in electricity generation equals demand equation QEEQ';
POSITIVE VARIABLE VQHEQ(Y,AAA,S,T,IPLUSMINUS)      'Feasibility in heat balance QHEQ';
POSITIVE VARIABLE VQESTOVOLT(Y,AAA,S,T,IPLUSMINUS) 'Feasibility in electricity storage equation QESTOVOLT';
POSITIVE VARIABLE VQHSTOVOLT(Y,AAA,S,T,IPLUSMINUS) 'Feasibility in heat storage equation VQHSTOVOLT';
POSITIVE VARIABLE VQHYRSSEQ(Y,AAA,S,IPLUSMINUS)    'Feasibility of QHYRSSEQ';
*POSITIVE VARIABLE VGE2LEVEL(Y,AAA,G,S,DAYTYPE)     'Average load of slowly regulating production (MW)';
* Exclusively for Balbase4:
$ifi %BB4%==yes   POSITIVE VARIABLE VGKVACCTOY(Y,AAA,G)               'Accumulated endogenous investment (not considering decommissioning) (MW)'
$ifi %BB4%==yes   POSITIVE VARIABLE VGKVACCTOT(Y,AAA,G)               'Accumulated endogenous investment minus decommissioning (MW)'
$ifi %BB4%==yes   POSITIVE VARIABLE VXKINI_Y(Y,IRRRE,IRRRI)           'BB4 - (MW)'
$ifi %BB4%==yes   POSITIVE VARIABLE VGKNINT(Y,AAA,G)                  'BB4 - (MW)'
$ifi %BB4%==yes   POSITIVE VARIABLE VXKNINT(Y,IRRRE,IRRRI)            'BB4 - (MW)'

* Hans: skal skrive pænere - og ikke alle variabler er faktisk i brug!
$ifi %BB4%==yes   POSITIVE VARIABLE VQGKVACCTOY(Y,AAA,G,SIMYEARS,IPLUSMINUS)      'Feasibility in new capacity constraint 1'
$ifi %BB4%==yes   POSITIVE VARIABLE VQGKVACCTOT(Y,AAA,G,SIMYEARS,IPLUSMINUS)      'Feasibility in new capacity constraint 2'
$ifi %BB4%==yes   POSITIVE VARIABLE VQEGKUP(AAA,G,S,T,IPLUSMINUS)              'Feasibility in capacity constraint on electricity'
$ifi %BB4%==yes   POSITIVE VARIABLE VQHGKUP(AAA,G,S,T,IPLUSMINUS)              'Feasibility in capacity constraint on heat'
$ifi %BB4%==yes   POSITIVE VARIABLE VQEGKCOMB1UP(AAA,G,S,T,IPLUSMINUS)         'Feasibility in capacity constraint on electricity'
$ifi %BB4%==yes   POSITIVE VARIABLE VQEGKCOMB2UP(AAA,G,S,T,IPLUSMINUS)         'Feasibility in capacity constraint on electricity combination'
$ifi %BB4%==yes   POSITIVE VARIABLE VQHGKCOMB1UP(AAA,G,S,T,IPLUSMINUS)         'Feasibility in capacity constraint on heat'
$ifi %BB4%==yes   POSITIVE VARIABLE VQHGKCOMB2UP(AAA,G,G,Y,S,T,IPLUSMINUS)        'Feasibility in capacity constraint on heat combination'
$ifi %BB4%==yes   POSITIVE VARIABLE VQHYRRDISP(AAA,G,S,T,IPLUSMINUS)           'Feasibility in Hydro run on river can not be dispatched'
$ifi %BB4%==yes   POSITIVE VARIABLE VQWNDDISP(AAA,G,S,T,IPLUSMINUS)            'Feasibility in wind power can not be dispatched'
$ifi %BB4%==yes   POSITIVE VARIABLE VQSOLDISP(AAA,G,S,T,IPLUSMINUS)            'Feasibility in sol can not be dispatched'
$ifi %BB4%==yes   POSITIVE VARIABLE VQXKN(Y,IRRRE,IRRRI,SIMYEARS,IPLUSMINUS)      'Feasibility in new transmission investment - NOT IMPLEMENTED PRESENTLYT'
$ifi %BB4%==yes   POSITIVE VARIABLE VQVGKNINT(AAA, G, Y, SIMYEARS,IPLUSMINUS)     'Feasibility in - NOT IMPLEMENTED PRESENTLYT '
$ifi %BB4%==yes   POSITIVE VARIABLE VQVXKNINT(IRRRE,IRRRI,Y, SIMYEARS,IPLUSMINUS) 'Feasibility in - NOT IMPLEMENTED PRESENTLYT '
*-------------------------------------------------------------------------------
*----- Any variables for addon to be placed here: ------------------------------
*-------------------------------------------------------------------------------
* These add-on variables pertain to natural gas.
$ifi %GAS%==yes $include '../../base/addons/gas/gasvariables.inc';
* This file includes:
* [list equations]
* These add-on variables pertain to compressed air energy storage.
$ifi %CAES%==yes $INCLUDE '../../base/addons/CAES/CAESvariables.inc';
* These add-on variables pertain to hydrogen technology.
$ifi %H2%==yes $include '../../base/addons/Hydrogen/H2variables.inc';
* These add-on variables pertain to transport technology (KHED)
$ifi %TSP%==yes $include '../../base/addons/Transport/TSPVariables.inc';
* These add-on vairables pertain to price sensitive electricity exchange with
* third countries.
$ifi %X3V%==yes $include '../../base/addons/x3v/model/x3vvariables.inc';
* These add-on vairables pertain heat transmission
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htvariables.inc';

$ifi %AGKNDISC%==yes  $include '../../base/addons/agkndisc/agkndiscvariables.inc';


*-------------------------------------------------------------------------------
*----- End: Any variables for addon to be placed here: -------------------------
*-------------------------------------------------------------------------------

* Note that intervals for variables may be set later (as .lo, .up  and/or .fx).

*-------------------------------------------------------------------------------
*  End: Declaration of VARIABLES
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
*  Declaration and definition of EQUATIONS:
*-------------------------------------------------------------------------------

* Equation declarations:

EQUATIONS
   QOBJ                     'Objective function'
   QEEQ(Y,RRR,S,T)          'Electricity generation equals demand'
   QHEQ(Y,AAA,S,T)          'Heat generation equals demand'
   QGCBGBPR(Y,AAA,G,S,T)    'CHP generation (back pressure) limited by Cb-line'
   QGCBGEXT(Y,AAA,G,S,T)    'CHP generation (extraction) limited by Cb-line'
   QGCVGEXT(Y,AAA,G,S,T)    'CHP generation (extraction) limited by Cv-line'
   QGGETOH(Y,AAA,G,S,T)     'Electric heat generation'
   QGNCBGBPR(Y,AAA,G,S,T)   'CHP generation (back pressure) Cb-line, new'
   QGNCBGEXT(Y,AAA,G,S,T)   'CHP generation (extraction) Cb-line, new'
   QGNCVGEXT(Y,AAA,G,S,T)   'CHP generation (extraction) Cv-line, new'
   QGNGETOH(Y,AAA,G,S,T)    'Electric heat generation, new'
*   QGE2LEVEL(Y,AAA,G,S,T)   'Variation on slowly regulated technologies'
   QGEKNT(Y,AAA,G,S,T)      'Generation on new electricity cap, limited by cap'
   QGHKNT(Y,AAA,G,S,T)      'Generation on new IGHH cap, limited by cap'
   QGKNHYRR(Y,AAA,G,S,T)    'Generation on new hydro-ror limited by cap and water'
   QGKNWND(Y,AAA,G,S,T)     'Generation on new windpower limited by cap and wind'
   QGKNSOLE(Y,AAA,G,S,T)    'Generation on new solarpower limited by cap and sun'
   QGKNSOLH(Y,AAA,G,S,T)    'Generation on new solarheat limited by cap and sun'
   QHYRSSEQ(Y,AAA,S)        'Hydropower with reservoir seasonal energy constraint'
   QHYMINRS(AAA,G,S)       'Hydropower reservoir - minimum level'
   QHYMAXRS(AAA,G,S)       'Hydropower reservoir - maximum level'
   QHYMING(Y,AAA,S,T)       'Regulated and unregulated hydropower production lower than capacity'
   QESTOVOLT(Y,AAA,S,T)     'Electricty storage dynamic equation (MWh)'
   QESTOLOADT(Y,AAA,S,T)    'Electricity storage loading less than heat production (MW)'
   QHSTOVOLT(Y,AAA,S,T)     'Heat storage dynamic equation (MWh)'
   QHSTOLOADT(Y,AAA,S,T)    'Heat storage loading less than heat production (MW)'
   QHSTOLOADTLIM(Y,AAA,S,T) 'Upper limit to heat storage loading (MW)'
   QESTOLOADTLIM(Y,AAA,S,T) 'Upper limit to electricity storage loading (MW)'
   QHSTOVOLTLIM(Y,AAA,S,T)  'Heat storage capacity limit (MWh)'
   QESTOVOLTLIM(Y,AAA,S,T)  'Electricity storage capacity limit (MWh)'
   QKFUELC(C,FFF)          'Total capacity using fuel FFF is limited in country'
   QKFUELR(RRR,FFF)        'Total capacity using fuel FFF is limited in region'
   QKFUELA(AAA,FFF)        'Total capacity using fuel FFF is limited in area'
   QGMINFUELC(Y,C,FFF)      'Minimum electricity generation by fuel per country'
   QGMAXFUELC(Y,C,FFF)      'Maximum electricity generation by fuel per country'
   QGMINFUELR(Y,RRR,FFF)    'Minimum electricity generation by fuel per region'
   QGMAXFUELR(Y,RRR,FFF)    'Maximum electricity generation by fuel per region'
   QGMINFUELA(Y,AAA,FFF)    'Minimum electricity generation by fuel per area'
   QGMAXFUELA(Y,AAA,FFF)    'Maximum electricity generation by fuel per area'
   QGMINCF(Y,C,FFF)         'Minimum fuel usage per country constraint'
   QGMAXCF(Y,C,FFF)         'Maximum fuel usage per country constraint'
   QGEQCF(Y,C,FFF)          'Required fuel usage per country constraint'
   QGMINRF(Y,RRR,FFF)       'Minimum fuel usage per region constraint'
   QGMAXRF(Y,RRR,FFF)       'Maximum fuel usage per region constraint'
   QGEQRF(Y,RRR,FFF)        'Required fuel usage per region constraint'
   QGMINAF(Y,AAA,FFF)       'Minimum fuel usage per area constraint'
   QGMAXAF(Y,AAA,FFF)       'Maximum fuel usage per area constraint'
   QGEQAF(Y,AAA,FFF)        'Required fuel usage per area constraint'
   QXK(Y,IRRRE,IRRRI,S,T)   'Transmission capacity constraint'
   QLIMCO2(Y,C)             'Limit on annual CO2-emission'
   QLIMSO2(Y,C)             'Limit on annual SO2 emission'
   QLIMNOX(Y,C)             'Limit on annual NOx emission'
   QHYFXRW(Y,RRR,S)         'Hydro with reservoir available for this region and season (MWh)'
   QHYFXCW(Y,C,S)           'Hydro with reservoir available for this country and season (MWh)'
   QBASELOAD(C,S,T)        'Minimum production for baseload service providers (MW)'
*   QRESDE(Y,RRR,S,T)        'Reserve requirement proportional with demand (MW)'
*   QRESWI(Y,RRR,S,T)        'Reserve requirement proportional with wind power (MW)'
   QMAXINVEST(Y,C,FFF)      'Maximal investment by country and fuel during one simulated year (MW)'
   QGMAXINVEST2(Y,C,G)      'Maximum model generated capacity increase from one year to the next (MW)'

*Balbase4: ---------------------------------------------------------------------  Hans: forklaringerne nedenfor skal da skrives pænere! Og ikke alle egns er i brug
$ifi %BB4%==yes   QGKVACCTOY(Y,AAA,G,SIMYEARS)      'new capacity constraint 1'
$ifi %BB4%==yes   QGKVACCTOT(Y,AAA,G,SIMYEARS)      'new capacity constraint 2'
$ifi %BB4%==yes   QEGKUP(Y,AAA,G,S,T)              'capacity constraint on electricity'
$ifi %BB4%==yes   QHGKUP(Y,AAA,G,S,T)              'capacity constraint on heat'
$ifi %BB4%==yes   QEGKCOMB1UP(Y,AAA,G,S,T)         'capacity constraint on electricity'
$ifi %BB4%==yes   QEGKCOMB2UP(Y,AAA,G,S,T)         'capacity constraint on electricity combination'
$ifi %BB4%==yes   QHGKCOMB1UP(Y,AAA,G,S,T)         'capacity constraint on heat'
$ifi %BB4%==yes   QHGKCOMB2UP(AAA,G,G,Y,S,T)        'capacity constraint on heat combination'
$ifi %BB4%==yes   QHYRRDISP(Y,AAA,G,S,T)           'Hydro run on river can not be dispatched'
$ifi %BB4%==yes   QWNDDISP(Y,AAA,G,S,T)            'wind power can not be dispatched'
$ifi %BB4%==yes   QSOLEDISP(Y,AAA,G,S,T)           'solE can not be dispatched'
$ifi %BB4%==yes   QSOLHDISP(Y,AAA,G,S,T)           'solH can not be dispatched'
$ifi %BB4%==yes   QXKN(Y,IRRRE,IRRRI,SIMYEARS)      'new transmission investment  - NOT IMPLEMENTED PRESENTLYT'
$ifi %BB4%==yes   QVGKNINT(AAA, G, Y, SIMYEARS)     ' - NOT IMPLEMENTED PRESENTLYT'
$ifi %BB4%==yes   QVXKNINT(IRRRE,IRRRI,Y, SIMYEARS) ' - NOT IMPLEMENTED PRESENTLYT'


*-------------------------------------------------------------------------------
*----- Any equations declarations for addon to be placed here: -----------------
*-------------------------------------------------------------------------------


$ifi %DECOMPEFF%==yes   QGEKOT(Y,AAA,G,S,T)      'Generation on old electricity capacity, limited by capacity';
$ifi %DECOMPEFF%==yes   QGHKOT(Y,AAA,G,S,T)      'Generation on old electricity capacity, limited by capacity';

$ifi %DECOMPEFF%==yes   QGKOHYRR(Y,AAA,G,S,T)    'Generation on old hydro-ror limited by cap and water';
$ifi %DECOMPEFF%==yes   QGKOWND(Y,AAA,G,S,T)     'Generation on old windpower limited by cap and wind';
$ifi %DECOMPEFF%==yes   QGKOSOLE(Y,AAA,G,S,T)    'Generation on old solarpower limited by cap and sun';

$ifi %REShareE%==yes QREShareE(CCCREShareE)    'Minimum share of electricity production from renewable electricity';
$ifi %REShareEH%==yes QREShareEH(CCCREShareEH) 'Minimum share of electricity and heat production from renewable electricity';

$ifi %AGKNDISC%==yes QAGKNDISC01(Y,AAA,G)         'At most one of the specified discrete capacity size investments is chosen (Addon AGKNDISC)';
$ifi %AGKNDISC%==yes QAGKNDISCCONT(Y,AAA,G)       'The invested capacity must be one of the specified sizes or zero (MW) (Addon AGKNDISC)';

*-------------------------------------------------------------------------------
*----- End: Any equations declarations for addon to be placed here -------------
*-------------------------------------------------------------------------------
;


* Equation definitions:
*----- The objective function QOBJ: --------------------------------------------
QOBJ ..

   VOBJ =E=

$ifi %BB4%==yes  SUM((Y, SIMYEARS)$(IY411(Y) AND ORD(Y) = ORD_IY(SIMYEARS)),


*IOF0000001*(Note: in final version there will be no factor, because scaling of the equation is used.
IOF1_*(


* Cost of fuel consumption during the year:

     SUM((IAGK_Y(Y,IA,IGE),FFF)$IGF(IGE,FFF),
                 IFUELP_Y(Y,IA,FFF) * IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))


    +SUM((IAGK_Y(Y,IA,IGH),FFF)$IGF(IGH,FFF),
                 IFUELP_Y(Y,IA,FFF) * IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))


    +SUM((IAGKN(Y,IA,IGE),FFF)$IGF(IGE,FFF),
                 IFUELP_Y(Y,IA,FFF) * IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM((IAGKN(Y,IA,IGH),FFF)$IGF(IGH,FFF),
                 IFUELP_Y(Y,IA,FFF) * IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))




* Operation and maintainance cost:

   + SUM(IAGK_Y(Y,IA,IGE), GOMVCOST(IA,IGE) * SUM((IS3,T), IHOURSINST(IS3,T)*
     VGE_T(Y,IA,IGE,IS3,T)))

   + SUM(IAGK_Y(Y,IA,IGNOTETOH(IGH)), GOMVCOST(IA,IGNOTETOH) * SUM((IS3,T), IHOURSINST(IS3,T)*
     GDATA(IGNOTETOH,'GDCV')*(VGH_T(Y,IA,IGNOTETOH,IS3,T))))

   + SUM(IAGKN(Y,IA,IGE), GOMVCOST(IA,IGE) * SUM((IS3,T), IHOURSINST(IS3,T)*
     VGEN_T(Y,IA,IGE,IS3,T)))

   + SUM(IAGKN(Y,IA,IGNOTETOH(IGH)), GOMVCOST(IA,IGNOTETOH) * SUM((IS3,T), IHOURSINST(IS3,T)*
     GDATA(IGNOTETOH,'GDCV')*(VGHN_T(Y,IA,IGNOTETOH,IS3,T))))

$ifi not %DECOMPEFF%==yes + IOF1000*(SUM(IAGK_Y(Y,IA,G),(IGKVACCTOY(Y,IA,G) + IGKFX_Y(Y,IA,G))*GOMFCOST(IA,G)))
$ifi %DECOMPEFF%==yes     + IOF1000*(SUM(IAGK_Y(Y,IA,G),(IGKVACCTOY(Y,IA,G) + IGKFX_Y(Y,IA,G) - VDECOM(Y,IA,G))*GOMFCOST(IA,G)))

   + IOF1000*(SUM((IAGKN(Y,IA,G))$IY411(Y),VGKN(Y,IA,G)*GOMFCOST(IA,G)*    IY4REMAINY(Y)      ))    /* Hans2   $IY411(Y)  og  IY4REMAINY(Y) og ud med noget   */
*   + IOF1000*(SUM(IAGKN(Y,IA,G),VGKN(Y,IA,G)*GOMFCOST(IA,G)))                                                      /* Hans2    */

*   + IOF1000*(SUM((IAGKN(Y,IA,G))$IY411(Y),VGKN(Y,IA,G)*GOMFCOST(IA,G)*(SUM(Y402$(IY411(Y402) AND (ORD(Y)<=ORD(Y402))),1))))       /* Hans1 tilføjet $IY411(Y)  */
*   + IOF1000*(SUM(IAGKN(Y,IA,G)$IY411(Y),VGKN(Y,IA,G)*GOMFCOST(IA,G)))                                                    /* Hans1 tilføjet $IY411(Y)  */
* Oprindelig:
*    + IOF1000*(SUM((IAGKN(Y,IA,G)),VGKN(Y,IA,G)*GOMFCOST(IA,G)*(SUM(Y402$(IY411(Y402) AND (ORD(Y)<=ORD(Y402))),1))))
*   + IOF1000*(SUM(IAGKN(Y,IA,G),VGKN(Y,IA,G)*GOMFCOST(IA,G)))

*  Hydro with storage seasonal price profile:

   + SUM(IAGK_Y(Y,IA,IGHYRS), SUM((IS3,T), HYPPROFILS(IA,IS3)* IHOURSINST(IS3,T)
     * VGE_T(Y,IA,IGHYRS,IS3,T)))

   + SUM(IAGKN(Y,IA,IGHYRS), SUM((IS3,T), HYPPROFILS(IA,IS3)* IHOURSINST(IS3,T)
     * VGEN_T(Y,IA,IGHYRS,IS3,T)))

$ifi not %bb3%==yes $goto not_waterval
$ifi not %WATERVAL%==yes $goto not_waterval
   + SUM(IAGK_Y(Y,IA,IGHYRS),SUM((IS3,T), IWATERVAL(IA,IS3)* IHOURSINST(IS3,T)
     * VGE_T(Y,IA,IGHYRS,IS3,T)))

   + SUM(IAGKN(Y,IA,IGHYRS), SUM((IS3,T), IWATERVAL(IA,IS3)* IHOURSINST(IS3,T)
     * VGEN_T(Y,IA,IGHYRS,IS3,T)))
$label not_waterval



*$goto objsnyder3

* Transmission cost:

   + SUM((IRE,IRI)$(IXKINI_Y(Y,IRE,IRI) OR IXKN(IRE,IRI) OR IXKN(IRI,IRE)),
       SUM((IS3,T), IHOURSINST(IS3,T) * (VX_T(Y,IRE,IRI,IS3,T) * XCOST(IRE,IRI))))

* Investment costs, new generation and storage capacity:

    + IOF1000000*(SUM((IAGKN(Y,IA,G))$IY411(Y), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))*     IY4REMAINY(Y)     ))      /* Hans2    */
*    + IOF1000000*(SUM((IAGKN(Y,IA,G))$IY411(Y), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))))                                                       /* Hans2     */

*    + IOF1000000*(SUM((IAGKN(Y,IA,G))$IY411(Y), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))*(SUM(Y402$(IY411(Y402) AND (ORD(Y)<=ORD(Y402))),1))))   /* Hans1 tilføjet $IY411(Y)  */
*    + IOF1000000*(SUM((IAGKN(Y,IA,G))$IY411(Y), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))))                                                       /* Hans1 tilføjet $IY411(Y)  */

*    + IOF1000000*(SUM((IAGKN(Y,IA,G)), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))*(SUM(Y402$(IY411(Y402) AND (ORD(Y)<=ORD(Y402))),1))))   /* Hans tilføjet $IY411(Y)  */
*    + IOF1000000*(SUM((IAGKN(Y,IA,G)), VGKN(Y,IA,G)*GINVCOST(IA,G)*(SUM(C$ICA(C,IA),ANNUITYC(C)))))                                                       /* Hans tilføjet $IY411(Y)  */

$ifi %AGKNDISC%==yes  $include '../../base/addons/agkndisc/agkndiscaddobj.inc';

* Investment costs, new transmission capacity
* (the average of the annuities for the two countries in question
* is used for international transmission):

    + SUM((IRE,IRI)$(IXKN(IRI,IRE) OR IXKN(IRE,IRI)), VXKN(Y,IRE,IRI)*XINVCOST(IRE,IRI)*
      (IOF05*(SUM(C$CCCRRR(C,IRE),ANNUITYC(C))+SUM(C$CCCRRR(C,IRI),ANNUITYC(C)))))


* Emission taxes

    + SUM(C, SUM(IAGK_Y(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGE)*IOF0001) *
      IOF3P6 *VGE_T(Y,IA,IGE,IS3,T) /(GDATA(IGE,'GDFE') * (1-GEFFDERATE(IA,IGE)))) * (ITAX_CO2_Y(Y,C))))

    + SUM(C, SUM(IAGK_Y(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGH)*IOF0001) *
      IOF3P6 *GDATA(IGH,'GDCV')* VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))))*(ITAX_CO2_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGE)*IOF0001) *
      IOF3P6 * VGEN_T(Y,IA,IGE,IS3,T) / (GDATA(IGE,'GDFE') * (1-GEFFDERATE(IA,IGE))) ) * (ITAX_CO2_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGH)*IOF0001) *
      IOF3P6 *GDATA(IGH,'GDCV')* VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))))*(ITAX_CO2_Y(Y,C))))

    + SUM(C, SUM(IAGK_Y(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGE)*IOF0001) *
      IOF3P6 *VGE_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * (1-GEFFDERATE(IA,IGE))))*(ITAX_SO2_Y(Y,C))))

    + SUM(C, SUM(IAGK_Y(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGH)*IOF0001) *
      IOF3P6 *GDATA(IGH,'GDCV')* VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))))*(ITAX_SO2_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGE)*IOF0001) *
      IOF3P6 * VGEN_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')*(1-GEFFDERATE(IA,IGE))))*(ITAX_SO2_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGH)*IOF0001) *
      IOF3P6*GDATA(IGH,'GDCV')* VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))))*(ITAX_SO2_Y(Y,C))))

    + SUM(C, SUM(IAGK_Y(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T)*(GDATA(IGE,'GDNOX')*IOF0000001)*
      IOF3P6 * VGE_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')*(1-GEFFDERATE(IA,IGE))))*(ITAX_NOX_Y(Y,C))))

    + SUM(C, SUM(IAGK_Y(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T)*(GDATA(IGH,'GDNOX')*IOF0000001)*
      IOF3P6 *GDATA(IGH,'GDCV')* VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))) )*(ITAX_NOX_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T)*(GDATA(IGE,'GDNOX')*IOF0000001)*
      IOF3P6 * VGEN_T(Y,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')*(1-GEFFDERATE(IA,IGE))))*(ITAX_NOX_Y(Y,C))))

    + SUM(C, SUM(IAGKN(Y,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T)*(GDATA(IGH,'GDNOX')*IOF0000001)*
      IOF3P6 *GDATA(IGH,'GDCV')* VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH))))*(ITAX_NOX_Y(Y,C))))

* Fuel taxes

    + SUM((C,FFF,IS3,T), SUM(IAGK_Y(Y,IA,IGE)
      $(IGF(IGE,FFF) AND ICA(C,IA)),
      IHOURSINST(IS3,T) * TAX_F(FFF,C) * IOF3P6 *
      (VGE_T(Y,IA,IGE,IS3,T) / (GDATA(IGE,'GDFE') * (1-GEFFDERATE(IA,IGE))))))

   + SUM((C,FFF,IS3,T), SUM(IAGK_Y(Y,IA,IGH)
      $(IGF(IGH,FFF) AND ICA(C,IA)),
      IHOURSINST(IS3,T) * TAX_F(FFF,C) * IOF3P6 *
      GDATA(IGH,'GDCV')* VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') *(1- GEFFDERATE(IA,IGH)))))

    + SUM((C,FFF,IS3,T), SUM(IAGKN(Y,IA,IGE)
      $(IGF(IGE,FFF) AND ICA(C,IA)),
      IHOURSINST(IS3,T) * TAX_F(FFF,C) * IOF3P6 *
      (VGEN_T(Y,IA,IGE,IS3,T) / (GDATA(IGE,'GDFE') * (1-GEFFDERATE(IA,IGE))))))

   + SUM((C,FFF,IS3,T), SUM(IAGKN(Y,IA,IGH)
      $(IGF(IGH,FFF) AND ICA(C,IA)),
      IHOURSINST(IS3,T) * TAX_F(FFF,C) * IOF3P6 *
      GDATA(IGH,'GDCV')*VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))

* More fuel taxes on technology types.
$ONTEXT  Not completely implemented yet - kept as appetizer.
   + SUM((Y,IA,IGH,IS3,T)$(IAGK_Y(Y,IA,IGH) and (IGHOB(IGH) or IGETOH(IGH))),
      TAX_FHO(Y,IA,IGH)*IHOURSINST(IS3,T)  * IOF3P6 * GDATA(IGH,'GDCV')* VGH_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * (1-GEFFDERATE(IA,IGH))))
   + SUM((Y,IA,IGH,IS3,T)$(IAGKN(Y,IA,IGH) and (IGHOB(IGH) or IGETOH(IGH))),
      TAX_FHO(Y,IA,IGH)*IHOURSINST(IS3,T)  * IOF3P6 *  VGHN_T(Y,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * (1-GEFFDERATE(IA,IGH))))
* Heat generation taxes.
   + SUM((Y,IA,IGH,IS3,T)$(IAGK_Y(Y,IA,IGH) and TAX_GH(Y,IA,IGH)),
      TAX_GH(Y,IA,IGH)*IOF3P6*VGH_T(Y,IA,IGH,IS3,T)*IHOURSINST(IS3,T))
   + SUM((Y,IA,IGH,IS3,T)$(IAGKN(Y,IA,IGH) and TAX_GH(Y,IA,IGH)),
      TAX_GH(Y,IA,IGH)*IOF3P6*VGHN_T(Y,IA,IGH,IS3,T)*IHOURSINST(IS3,T))
$OFFTEXT
* Changes in consumers' utility relative to electricity consumption:

   + SUM(IR,
     SUM((IS3,T), IHOURSINST(IS3,T)
     * (SUM(DEF_D1, VDEF_T(Y,IR,IS3,T,DEF_D1)* IDEFP_T(IR,IS3,T,DEF_D1)  )
     +  SUM(DEF_D2, VDEF_T(Y,IR,IS3,T,DEF_D2)* IDEFP_T(IR,IS3,T,DEF_D2)  )
     +  SUM(DEF_D3, VDEF_T(Y,IR,IS3,T,DEF_D3)* IDEFP_T(IR,IS3,T,DEF_D3)  )
     )

     )
     )

   - SUM(IR,
     SUM((IS3,T), IHOURSINST(IS3,T)
     * (SUM(DEF_U1, VDEF_T(Y,IR,IS3,T,DEF_U1)* IDEFP_T(IR,IS3,T,DEF_U1)  )
     +  SUM(DEF_U2, VDEF_T(Y,IR,IS3,T,DEF_U2)* IDEFP_T(IR,IS3,T,DEF_U2)  )
     +  SUM(DEF_U3, VDEF_T(Y,IR,IS3,T,DEF_U3)* IDEFP_T(IR,IS3,T,DEF_U3)  )))
     )

* Changes in consumers' utility relative to heat consumption:

   + SUM(IA,
     SUM((IS3,T), IHOURSINST(IS3,T)
     * (SUM(DHF_D1, VDHF_T(Y,IA,IS3,T,DHF_D1)* IDHFP_T(IA,IS3,T,DHF_D1)  )
     +  SUM(DHF_D2, VDHF_T(Y,IA,IS3,T,DHF_D2)* IDHFP_T(IA,IS3,T,DHF_D2)  )
     +  SUM(DHF_D3, VDHF_T(Y,IA,IS3,T,DHF_D3)* IDHFP_T(IA,IS3,T,DHF_D3)  )))
      )

   - SUM(IA,
     SUM((IS3,T), IHOURSINST(IS3,T)
     * (SUM(DHF_U1, VDHF_T(Y,IA,IS3,T,DHF_U1)* IDHFP_T(IA,IS3,T,DHF_U1)  )
     +  SUM(DHF_D2, VDHF_T(Y,IA,IS3,T,DHF_D2)* IDHFP_T(IA,IS3,T,DHF_D2)  )
     +  SUM(DHF_D3, VDHF_T(Y,IA,IS3,T,DHF_D3)* IDHFP_T(IA,IS3,T,DHF_D3)  )))
     )
$label  objsnyder3

* Infeasibility penalties:
   + PENALTYQ*(
$ifi %BB1%==yes    +SUM((IA,IS3)$SUM(IGHYRS,IAGK_Y(IA,IGHYRS)),(VQHYRSSEQ(IA,IS3,'IMINUS')+VQHYRSSEQ(IA,IS3,'IPLUS')))
$ifi %BB2%==yes    +SUM((IA,IS3)$SUM(IGHYRS,IAGK_Y(IA,IGHYRS)),(VQHYRSSEQ(IA,IS3,'IMINUS')+VQHYRSSEQ(IA,IS3,'IPLUS')))
$ifi %BB4%==yes    +SUM((IA,IS3)$SUM(IGHYRS,IAGK_Y(Y,IA,IGHYRS)),(VQHYRSSEQ(Y,IA,IS3,'IMINUS')+VQHYRSSEQ(Y,IA,IS3,'IPLUS')))
               +SUM((IA,IS3,T)$SUM(IGHSTO, IAGK_Y(Y,IA,IGHSTO) or IAGKN(Y,IA,IGHSTO)),(VQHSTOVOLT(Y,IA,IS3,T,'IMINUS')+VQHSTOVOLT(Y,IA,IS3,T,'IPLUS')))
               +SUM((IA,IS3,T)$SUM(IGESTO, IAGK_Y(Y,IA,IGESTO) or IAGKN(Y,IA,IGESTO)),(VQESTOVOLT(Y,IA,IS3,T,'IMINUS')+VQESTOVOLT(Y,IA,IS3,T,'IPLUS')))
               +SUM((IR,IS3,T),(VQEEQ(Y,IR,IS3,T,'IMINUS')+VQEEQ(Y,IR,IS3,T,'IPLUS')))
               +SUM((IA,IS3,T)$IDH_SUMST(IA),(VQHEQ(Y,IA,IS3,T,'IMINUS')+VQHEQ(Y,IA,IS3,T,'IPLUS')))
/*   Not implemented yet - not crusial - but TODO
$ifi %BB4%==yes   +SUM((Y41,IA,G,SIMYEARS),VQGKVACCTOY(Y,AAA,G,SIMYEARS,'IPLUS')+VQGKVACCTOY(Y,AAA,G,SIMYEARS,'IMINUS'))
$ifi %BB4%==yes   VQGKVACCTOT(Y,AAA,G,SIMYEARS,IPLUSMINUS)  TODO
$ifi %BB4%==yes   VQEGKUP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQHGKUP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQEGKCOMB1UP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQEGKCOMB2UP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQHGKCOMB1UP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQHGKCOMB2UP(AAA,G,G,Y,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQHYRRDISP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQWNDDISP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQSOLDISP(AAA,G,S,T,IPLUSMINUS)
$ifi %BB4%==yes   VQXKN(Y,IRRRE,IRRRI,SIMYEARS,IPLUSMINUS)
$ifi %BB4%==yes   VQVGKNINT(AAA, G, Y, SIMYEARS,IPLUSMINUS)
$ifi %BB4%==yes   VQVXKNINT(IRRRE,IRRRI,Y, SIMYEARS,IPLUSMINUS)   TODO
*/
              )

* Add-on objective function contributions
* This file containts the gas induced additions to the objective function.
$ifi %GAS%==yes $include '../../base/addons/gas/gascosts.inc'
* LARS:  X3V obj  moved to a file.
$ifi %X3V%==yes $include '../../base/addons/x3v/model/x3vobj.inc';
* This file contains hydrogen induced additions to the objective function.
$ifi %H2%==yes $include '../../base/addons/Hydrogen/H2costs.inc'
* This file contains NAP induced additions to the objective function.
$ifi %NAP%==yes $include '../../base/addons/NAP/NAPobj.inc';
* This file contains transport induced additions to the objective function (KHED)
$ifi %TSP%==yes $include '../../base/addons/Transport/TSPObj.inc'
* This file contains Heat transmission induced additions to the objective function.
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htcosts.inc';

* LARS20071029: Experimentation. Case specifc costs. These costs are not a part
* of the core model, nor any add-on module. Create a file in the project
* dirrectory and it will be included automatically.
$if EXIST 'casecosts.inc' $INCLUDE 'casecosts.inc';




)
$ifi %BB4%==yes )
;
*----- End: The objective function QOBJ ----------------------------------------



*--------------------------Balance equations for electricity and heat ----------

QEEQ(IY411,IR,IS3,T) ..

      SUM(IA$RRRAAA(IR,IA), SUM(IGE$((IAGK_Y(IY411,IA,IGE) /*OR (IAGKN(IY411,IA,IGE) AND NOT IY4FIRST(IY411))*/) AND IGNOTETOH(IGE)),VGE_T(IY411,IA,IGE,IS3,T))) /* Hans */
    - SUM(IA$RRRAAA(IR,IA), SUM(IGETOH$(IAGK_Y(IY411,IA,IGETOH) /*OR (IAGKN(IY411,IA,IGETOH) AND NOT IY4FIRST(IY411))*/), VGE_T(IY411,IA,IGETOH,IS3,T)  ))  /* Hans */

*      SUM(IA$RRRAAA(IR,IA), SUM(IGE$((IAGK_Y(IY411,IA,IGE) OR (IAGKN(IY411,IA,IGE) AND NOT IY4FIRST(IY411))) AND IGNOTETOH(IGE)),VGE_T(IY411,IA,IGE,IS3,T)))
*    - SUM(IA$RRRAAA(IR,IA), SUM(IGETOH$(IAGK_Y(IY411,IA,IGETOH) OR (IAGKN(IY411,IA,IGETOH) AND NOT IY4FIRST(IY411))), VGE_T(IY411,IA,IGETOH,IS3,T)  ))

    + SUM(IAGKN(IY411,IA,IGE)$((RRRAAA(IR,IA)) AND IGNOTETOH(IGE)), VGEN_T(IY411,IA,IGE,IS3,T))
    - SUM(IAGKN(IY411,IA,IGE)$((RRRAAA(IR,IA)) AND IGETOH(IGE)), VGEN_T(IY411,IA,IGE,IS3,T))
     + SUM(IRE$(IXKINI_Y(IY411,IRE,IR) OR IXKN(IRE,IR) OR IXKN(IR,IRE)), VX_T(IY411,IRE,IR,IS3,T)*(1-XLOSS(IRE,IR)))
    - SUM(IA$(RRRAAA(IR,IA) AND sum(IGESTO,IAGK_Y(IY411,IA,IGESTO))),VESTOLOADT(IY411,IA,IS3,T))
$ifi %X3V%==yes + SUM(X3VPLACE$X3VX(IR,X3VPLACE),SUM(X3VSTEP,VX3VIM_T(IR,X3VPLACE,X3VSTEP,IS3,T)))
$ifi %H2%==yes - SUM(IAGK_Y(IA,IGETOH2)$RRRAAA(IR,IA), VGE_T(IA,IGETOH2,IS3,T))
$ifi %H2%==yes - SUM(IAGKN(IA,IGETOH2)$RRRAAA(IR,IA), VGEN_T(IA,IGETOH2,IS3,T))
* This file contains transport induced additions to the balance equation(KHED)
$ifi %TSP%==yes $include '../../base/addons/Transport/TSPQEEQ.inc'
    =E=
      IX3FX_T_Y(IY411,IR,IS3,T)
    + (   (IDE_T_Y(IY411,IR,IS3,T)

         + SUM(DEF_U1,VDEF_T(IY411,IR,IS3,T,DEF_U1) )
         - SUM(DEF_D1,VDEF_T(IY411,IR,IS3,T,DEF_D1) )
         + SUM(DEF_U2,VDEF_T(IY411,IR,IS3,T,DEF_U2) )
         - SUM(DEF_D2,VDEF_T(IY411,IR,IS3,T,DEF_D2) )
         + SUM(DEF_U3,VDEF_T(IY411,IR,IS3,T,DEF_U3) )
         - SUM(DEF_D3,VDEF_T(IY411,IR,IS3,T,DEF_D3) )
          )/(1-DISLOSS_E(IR)))
      + SUM(IRI$(IXKINI_Y(IY411,IR,IRI) OR IXKN(IR,IRI) OR IXKN(IRI,IR)),VX_T(IY411,IR,IRI,IS3,T))
$ifi %GAS%==yes + SUM((STORE,STORETYPE)$RRRAAA(IR,STORE),VINJ(STORE,STORETYPE,IS3,T)*GSTOREDATA(STORETYPE,'ELECT'))
$ifi %CAES%==yes + SUM((IA,IGCAES)$((IAGK_Y(IA,IGCAES) or IAGKN(IA,IGCAES)) and RRRAAA(IR,IA)), VCAESCOMPRESS(IA,IGCAES,IS3,T)/CAESDATA(IGCAES,'CompEff'))
$ifi %X3V%==yes + SUM(X3VPLACE$X3VX(IR,X3VPLACE),SUM(X3VSTEP,VX3VEX_T(IR,X3VPLACE,X3VSTEP,IS3,T)))
      - VQEEQ(IY411,IR,IS3,T,'IMINUS') + VQEEQ(IY411,IR,IS3,T,'IPLUS')
 ;


QHEQ(IY411,IA,IS3,T)$(IDH_SUMST(IA) NE 0) ..
* new:  findes også nedenfor! derfor ud       Hans
*   + SUM(IGBPR$IAGKN(IY411,IA,IGBPR),VGHN_T(IY411,IA,IGBPR,IS3,T))
*   + SUM(IGEXT$IAGKN(IY411,IA,IGEXT),VGHN_T(IY411,IA,IGEXT,IS3,T))
*   + SUM(IGHH$IAGKN(IY411,IA,IGHH),VGHN_T(IY411,IA,IGHH,IS3,T))
*   + SUM(IGETOH$IAGKN(IY411,IA,IGETOH),VGHN_T(IY411,IA,IGETOH,IS3,T))


*   + SUM(IGBPR$(IAGK_Y(IY411,IA,IGBPR) /*OR (IAGKN(IY411,IA,IGBPR) AND NOT IY4FIRST(IY411))*/),VGH_T(IY411,IA,IGBPR,IS3,T))  /* Hans */
   + SUM(IGBPR$(IAGK_Y(IY411,IA,IGBPR) OR (IAGKN(IY411,IA,IGBPR) AND NOT IY4FIRST(IY411))),VGH_T(IY411,IA,IGBPR,IS3,T))
   + SUM(IGBPR$IAGKN(IY411,IA,IGBPR),VGHN_T(IY411,IA,IGBPR,IS3,T))
*   + SUM(IGEXT$(IAGK_Y(IY411,IA,IGEXT) /*OR (IAGKN(IY411,IA,IGEXT) AND NOT IY4FIRST(IY411))*/),VGH_T(IY411,IA,IGEXT,IS3,T))    /* Hans */
   + SUM(IGEXT$(IAGK_Y(IY411,IA,IGEXT) OR (IAGKN(IY411,IA,IGEXT) AND NOT IY4FIRST(IY411))),VGH_T(IY411,IA,IGEXT,IS3,T))
   + SUM(IGEXT$IAGKN(IY411,IA,IGEXT),VGHN_T(IY411,IA,IGEXT,IS3,T))
*   + SUM(IGHH$(IAGK_Y(IY411,IA,IGHH) /*OR (IAGKN(IY411,IA,IGHH) AND NOT IY4FIRST(IY411))*/),VGH_T(IY411,IA,IGHH,IS3,T))      /* Hans */
   + SUM(IGHH$(IAGK_Y(IY411,IA,IGHH) OR (IAGKN(IY411,IA,IGHH) AND NOT IY4FIRST(IY411))),VGH_T(IY411,IA,IGHH,IS3,T))
   + SUM(IGHH$IAGKN(IY411,IA,IGHH),VGHN_T(IY411,IA,IGHH,IS3,T))


*   + SUM(IGETOH$(IAGK_Y(IY411,IA,IGETOH) /*OR (IAGKN(IY411,IA,IGETOH) AND NOT IY4FIRST(IY411))*/),VGH_T(IY411,IA,IGETOH,IS3,T))   /* Hans */
   + SUM(IGETOH$(IAGK_Y(IY411,IA,IGETOH) OR (IAGKN(IY411,IA,IGETOH) AND NOT IY4FIRST(IY411))),VGH_T(IY411,IA,IGETOH,IS3,T))
   + SUM(IGETOH$IAGKN(IY411,IA,IGETOH),VGHN_T(IY411,IA,IGETOH,IS3,T))
   + SUM(IGESTO$IAGK_Y(IY411,IA,IGESTO),VGE_T(IY411,IA,IGESTO,IS3,T)/GDATA(IGESTO,'GDCB'))     /* Hans? hvorfor anderledes? ingen inveseteringer? */
   - VHSTOLOADT(IY411,IA,IS3,T)$SUM(IGHSTO$(IAGK_Y(IY411,IA,IGHSTO) or IAGKN(IY411,IA,IGHSTO)),1)      /* Hans? hvorfor anderledes? ingen inveseteringer?*/
    =E=
     (IDH_T_Y(IY411,IA,IS3,T)
        + SUM(DHF_U1,VDHF_T(IY411,IA,IS3,T,DHF_U1) )
        - SUM(DHF_D1,VDHF_T(IY411,IA,IS3,T,DHF_D1) )
        + SUM(DHF_U2,VDHF_T(IY411,IA,IS3,T,DHF_U2) )
        - SUM(DHF_D2,VDHF_T(IY411,IA,IS3,T,DHF_D2) )
        + SUM(DHF_U3,VDHF_T(IY411,IA,IS3,T,DHF_U3) )
        - SUM(DHF_D3,VDHF_T(IY411,IA,IS3,T,DHF_D3) )

         )/(1-DISLOSS_H(IA))
* Adds heat transmission if selected in the gas add-on
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htheatbalance.inc';
        - VQHEQ(IY411,IA,IS3,T,'IMINUS') + VQHEQ(IY411,IA,IS3,T,'IPLUS')
;

*------ Generation technologies' electricity/heat operating area: --------------

* Back pressure units:

QGCBGBPR(IAGK_Y(IY411,IA,IGBPR),IS3,T) ..
      VGE_T(IY411,IA,IGBPR,IS3,T) =E= VGH_T(IY411,IA,IGBPR,IS3,T) * GDATA(IGBPR,'GDCB');


QGNCBGBPR(IAGKN(IY411,IA,IGBPR),IS3,T) ..
      VGEN_T(IY411,IA,IGBPR,IS3,T) =E= VGHN_T(IY411,IA,IGBPR,IS3,T) * GDATA(IGBPR,'GDCB');


* Extraction units:

QGCBGEXT(IAGK_Y(IY411,IA,IGEXT),IS3,T) ..
   VGE_T(IY411,IA,IGEXT,IS3,T) =G= VGH_T(IY411,IA,IGEXT,IS3,T) * GDATA(IGEXT,'GDCB');


QGCVGEXT(IAGK_Y(IY411,IA,IGEXT),IS3,T)$
$ifi not %COMBTECH%==yes  1 ..
$ifi     %COMBTECH%==yes  (NOT IGCOMB2(IGEXT)) ..
* This will have a value if not a combination technology
     (IGKVACCTOY(IY411,IA,IGEXT)+IGKFX_Y(IY411,IA,IGEXT))*GKDERATE(IA,IGEXT,IS3)
         - VGH_T(IY411,IA,IGEXT,IS3,T) * GDATA(IGEXT,'GDCV')
$ifi %COMBTECH%==yes  * This will have a value in case of a combination technology.
$ifi %COMBTECH%==yes    + SUM(IGCOMB2$GGCOMB(IGEXT,IGCOMB2), VGH_T(IY411,IA,IGCOMB2,IS3,T) * GDATA(IGCOMB2,'GDCV'))$IGCOMB1(IGEXT)
    =G=
   VGE_T(IY411,IA,IGEXT,IS3,T)
$ifi %COMBTECH%==yes  * Add secondary generation if combination technologies are used
$ifi %COMBTECH%==yes  + SUM(IGCOMB2$GGCOMB(IGEXT,IGCOMB2), VGE_T(IY411,IA,IGCOMB2,IS3,T))$IGCOMB1(IGEXT)
;

QGNCBGEXT(IAGKN(IY411,IA,IGEXT),IS3,T) ..
   VGEN_T(IY411,IA,IGEXT,IS3,T) =G= VGHN_T(IY411,IA,IGEXT,IS3,T) * GDATA(IGEXT,'GDCB') ;


QGNCVGEXT(IAGKN(IY411,IA,IGEXT),IS3,T)$
$ifi not %COMBTECH%==yes  1 ..
$ifi     %COMBTECH%==yes  (NOT IGCOMB2(IGEXT)) ..

         VGKN(IY411,IA,IGEXT)*GKDERATE(IA,IGEXT,IS3)
       - VGHN_T(IY411,IA,IGEXT,IS3,T) * GDATA(IGEXT,'GDCV')
$ifi %COMBTECH%==yes  * This will have a value in case of a combination technology.
$ifi %COMBTECH%==yes         + SUM(IGCOMB2$GGCOMB(IGEXT,IGCOMB2), VGHN_T(IY411,IA,IGCOMB2,IS3,T) * GDATA(IGCOMB2,'GDCV'))$IGCOMB1(IGEXT)
    =G=
   VGEN_T(IY411,IA,IGEXT,IS3,T)
$ifi %COMBTECH%==yes  * Add secondary generation if combination technologies are used
$ifi %COMBTECH%==yes     + SUM(IGCOMB2$GGCOMB(IGEXT,IGCOMB2), VGEN_T(IY411,IA,IGCOMB2,IS3,T))$IGCOMB1(IGEXT)
;
* Electric heat pumps:

QGGETOH(IAGK_Y(IY411,IA,IGETOH),IS3,T) ..
       VGE_T(IY411,IA,IGETOH,IS3,T) =E= VGH_T(IY411,IA,IGETOH,IS3,T) / GDATA(IGETOH,'GDFE');

QGNGETOH(IAGKN(IY411,IA,IGETOH),IS3,T) ..
       VGEN_T(IY411,IA,IGETOH,IS3,T) =E= VGHN_T(IY411,IA,IGETOH,IS3,T) / GDATA(IGETOH,'GDFE');




*--------- Dispatchable generation technologies' operating area: ---------------

* Generation on new capacity is constrained by the capacity,
* modified by GKDERATE:

QGEKNT(IAGKN(IY411,IA,IGKE),IS3,T)$(IGDISPATCH(IGKE) AND
$ifi not %COMBTECH%==yes  1) ..
$ifi     %COMBTECH%==yes  (NOT IGCOMB2(IGKE))) ..
  VGKN(IY411,IA,IGKE)*GKDERATE(IA,IGKE,IS3)/(1$(not IGESTO(IGKE)) + GDATA(IGKE,'GDSTOHUNLD')$IGESTO(IGKE))
    =G=
  VGEN_T(IY411,IA,IGKE,IS3,T)
$ifi %COMBTECH%==yes  * Add secondary generation if combination technologies are used
$ifi %COMBTECH%==yes    + SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGEN_T(%IA_IGKEf%IGCOMB2,IS3,T))$IGCOMB1(IGDISPATCH)
;


* Note: does not presently include COMBTECH.
QGHKNT(IAGKN(IY411,IA,IGKH),IS3,T)$IGDISPATCH(IGKH)..
  VGKN(IY411,IA,IGKH)*GKDERATE(IA,IGKH,IS3)/(1$(not IGHSTO(IGKH) or IGHSTO_S(IGKH)) + GDATA(IGKH,'GDSTOHUNLD')$IGHSTO(IGKH))
     =G=
  VGHN_T(IY411,IA,IGKH,IS3,T)
;


$ifi %DECOMPEFF%==yes QGEKOT(IAGK_Y(IA,IGDISPATCH(IGE)),IS3,T) ..
$ifi %DECOMPEFF%==yes  (IGKFX_Y(IGDISPATCH,IA) + IGKVACCTOY(IGDISPATCH,IA)-VDECOM(IA,IGDISPATCH))*GKDERATE(IA,IGDISPATCH,IS3)
$ifi %DECOMPEFF%==yes     =G=
$ifi %DECOMPEFF%==yes  VGE_T(IA,IGDISPATCH,IS3,T)
$ifi %DECOMPEFF%==yes ;

* Rev. 3.01: missing GSOLH, to be added.
$ifi %DECOMPEFF%==yes QGHKOT(IAGK_Y(IA,IGKH),IS3,T) ..
$ifi %DECOMPEFF%==yes  (IGKFX_Y(IGKH,IA) + IGKVACCTOY(IGKH,IA)-VDECOM(IA,IGKH))*GKDERATE(IA,IGKH,IS3)
$ifi %DECOMPEFF%==yes     =G=
$ifi %DECOMPEFF%==yes  VGH_T(IA,IGKH,IS3,T)
$ifi %DECOMPEFF%==yes ;


*-------------- New hydro run-of-river: cannot be dispatched: ------------------


QGKNHYRR(IAGKN(IY411,IA,IGHYRR),IS3,T)$IWTRRRSUM(IA)..
 WTRRRFLH(IA) * VGKN(IAGKN) * WTRRRVAR_T(IA,IS3,T) / IWTRRRSUM(IA)
   =E=
   VGEN_T(IY411,IA,IGHYRR,IS3,T)

$ifi %DECOMPEFF%==yes QGKOHYRR(IAGK_Y(IA,IGHYRR),IS3,T)..
$ifi %DECOMPEFF%==yes  WTRRRFLH(IA) * (IGKFX_Y(IGHYRR,IA) + IGKVACCTOY(IGHYRR,IA)-VDECOM(IA,IGHYRR)) * WTRRRVAR_T(IA,IS3,T) / IWTRRRSUM(IA)
$ifi %DECOMPEFF%==yes    =E=
$ifi %DECOMPEFF%==yes  VGE_T(IY411,IA,IGHYRR,IS3,T)
;

*-------------- New windpower: cannot be dispatched: ---------------------------


QGKNWND(IAGKN(IY411,IA,IGWND),IS3,T)$IWND_SUMST(IA)..
 WNDFLH(IA) * VGKN(IY411,IA,IGWND) * WND_VAR_T(IA,IS3,T) / IWND_SUMST(IA)
$ifi     %WNDSHUTDOWN%==yes =G=
$ifi not %WNDSHUTDOWN%==yes =E=
  VGEN_T(IY411,IA,IGWND,IS3,T);

$ifi %DECOMPEFF%==yes QGKOWND(IAGK_Y(IA,IGWND),IS3,T)$IWND_SUMST(IA)..
$ifi %DECOMPEFF%==yes  WNDFLH(IA) * (IGKFX_Y(IGWND,IA) + IGKVACCTOY(IGWND,IA)-VDECOM(IA,IGWND)) * WND_VAR_T(IA,IS3,T) / IWND_SUMST(IA)
$ifi %DECOMPEFF%==yes    =G=
$ifi %DECOMPEFF%==yes   VGE_T(%IA_IGWND_IS3_T%);


*-------------- New solar power and heat: cannot be dispatched: ----------------
QGKNSOLE(IAGKN(IY411,IA,IGSOLE),IS3,T)$ISOLESUMST(IA)..
SOLEFLH(IA) * VGKN(IY411,IA,IGSOLE) * SOLE_VAR_T(IA,IS3,T) / ISOLESUMST(IA)
 =E=
VGEN_T(IY411,IA,IGSOLE,IS3,T);


QGKNSOLH(IAGKN(IY411,IA,IGSOLH),IS3,T)$ISOLHSUMST(IA)..
SOLHFLH(IA) * VGKN(IY411,IA,IGSOLH) * SOLH_VAR_T(IA,IS3,T) / ISOLHSUMST(IA)
 =E=
VGHN_T(IY411,IA,IGSOLH,IS3,T);


$ifi %DECOMPEFF%==yes QGKOSOLE(IAGK_Y(IA,IGSOLE),IS3,T)..
$ifi %DECOMPEFF%==yes SOLEFLH(IA) * (IGKFX_Y(IGSOLE,IA) + IGKVACCTOY(IGSOLE,IA)-VDECOM(IA,IGSOLE)) * SOLE_VAR_T(IA,IS3,T) / ISOLESUMST(IA)
$ifi %DECOMPEFF%==yes  =E=
$ifi %DECOMPEFF%==yes VGE_T(IY411,IA,IGSOLE,IS3,T);


*-------------- Hydropower with reservoirs: ------------------------------------
*
* Hydro reservoir content - dynamic seasonal equation

QHYRSSEQ(IY411,IA,S)$SUM(IGHYRS,IAGK_Y(IY411,IA,IGHYRS))..
      VHYRS_S(IY411,IA,S)
      + SUM(IGHYRS$IAGK_Y(IY411,IA,IGHYRS),
        IHYINF_S(IA,S) * (IGKVACCTOY(IY411,IA,IGHYRS)+IGKFX_Y(IY411,IA,IGHYRS))
        -SUM(T,IHOURSINST(S,T)*(VGE_T(IY411,IA,IGHYRS,S,T))))
      + SUM(IGHYRS$IAGKN(IY411,IA,IGHYRS),
        IHYINF_S(IA,S) * VGKN(IY411,IA,IGHYRS)
        -SUM(T,IHOURSINST(S,T)*(VGEN_T(IY411,IA,IGHYRS,S,T))))

      - VQHYRSSEQ(IY411,IA,S,'IMINUS') + VQHYRSSEQ(IY411,IA,S,'IPLUS')

      =G=  VHYRS_S(IY411,IA,S++1);

* Regulated and unregulated hydropower production lower than capacity

QHYMING(IY411,IA,IS3,T)$SUM(IGHYRS,IAGK_Y(IY411,IA,IGHYRS))..
      SUM(IGHYRS$IAGK_Y(IY411,IA,IGHYRS),VGE_T(IY411,IA,IGHYRS,IS3,T))
      + SUM(IGHYRS$IAGKN(IY411,IA,IGHYRS),VGEN_T(IY411,IA,IGHYRS,IS3,T))
      + SUM(IGHYRR$IAGK_Y(IY411,IA,IGHYRR),VGE_T(IY411,IA,IGHYRR,IS3,T))
      + SUM(IGHYRR$IAGKN(IY411,IA,IGHYRR),VGEN_T(IY411,IA,IGHYRR,IS3,T))
      =L=
      SUM(IGHYRS$IAGK_Y(IY411,IA,IGHYRS),(IGKVACCTOY(IY411,IA,IGHYRS)+IGKFX_Y(IY411,IA,IGHYRS))*GKDERATE(IA,IGHYRS,IS3))
      + SUM(IGHYRS$IAGKN(IY411,IA,IGHYRS),VGKN(IY411,IA,IGHYRS))
      ;

*------------ Short term heat and electricity storages:-------------------------


QESTOVOLT(IY411,IA,S,T)$(SUM(IGESTO, IAGK_Y(IY411,IA,IGESTO)+IAGKN(IY411,IA,IGESTO)) AND IS3(S))..
    VESTOVOLT(IY411,IA,S,T++1) =E= VESTOVOLT(IY411,IA,S,T)
  + IHOURSINST(S,T)*(VESTOLOADT(IY411,IA,S,T)*SUM(IGESTO$IAGK_Y(IY411,IA,IGESTO),GDATA(IGESTO,'GDFE'))
  - SUM(IGESTO$IAGK_Y(IY411,IA,IGESTO), VGE_T(IY411,IA,IGESTO,S,T))
  - SUM(IGESTO$IAGKN(IY411,IA,IGESTO),VGEN_T(IY411,IA,IGESTO,S,T))
  )
  - VQESTOVOLT(IY411,IA,S,T,'IPLUS') + VQESTOVOLT(IY411,IA,S,T,'IMINUS')
;

QESTOLOADT(IY411,IA,IS3,T)$SUM(IGESTO, IAGK_Y(IY411,IA,IGESTO)+IAGKN(IY411,IA,IGESTO))..
* LARS20070814: This equation is believed to be superfluous, as storage loading is
* restricted to be less than generation minus demand and net exports in the
* electrcity balance equation.
* However, until this is certain, the equation is maintained.
* There is also the possibility that the equation should restrict loading of
* electricity storages to use electricity from local generation units.
      SUM(IGE$(IGNOTETOH(IGE) AND IAGK_Y(IY411,IA,IGE)), VGE_T(IY411,IA,IGE,IS3,T))
     +SUM(IGE$(IGNOTETOH(IGE) AND IAGKN(IY411,IA,IGE)), VGEN_T(IY411,IA,IGE,IS3,T))
           - SUM(IGETOH$IAGK_Y(IY411,IA,IGETOH), VGE_T(IY411,IA,IGETOH,IS3,T))
           - SUM(IGETOH$IAGKN(IY411,IA,IGETOH), VGEN_T(IY411,IA,IGETOH,IS3,T))
   =G=
      VESTOLOADT(IY411,IA,IS3,T)
;

QHSTOVOLT(IY411,IA,S,T)$(SUM(IGHSTO, IAGK_Y(IY411,IA,IGHSTO)+IAGKN(IY411,IA,IGHSTO)) AND IS3(S))..
    VHSTOVOLT(IY411,IA,S,T)
  + IHOURSINST(S,T)* (VHSTOLOADT(IY411,IA,S,T)
  - SUM(IGHSTO$IAGK_Y(IY411,IA,IGHSTO), VGH_T(IY411,IA,IGHSTO,S,T))
  - SUM(IGHSTO$IAGKN(IY411,IA,IGHSTO), VGHN_T(IY411,IA,IGHSTO,S,T))
  )
    =E=       VHSTOVOLT(IY411,IA,S,T++1)
  - VQHSTOVOLT(IY411,IA,S,T,'IPLUS') + VQHSTOVOLT(IY411,IA,S,T,'IMINUS')
;


QHSTOLOADT(IY411,IA,IS3,T)$SUM(IGHSTO, IAGK_Y(IY411,IA,IGHSTO)+IAGKN(IY411,IA,IGHSTO))..
* This equation is believed to be superfluous, as storage loading is
* restricted to be less than generation minus demand in the heat balance equation.
* However, until this is certain, the equation is maintained.
   SUM(IGH$IAGK_Y(IY411,IA,IGH), VGH_T(IY411,IA,IGH,IS3,T))
  +SUM(IGH$IAGKN(IY411,IA,IGH), VGHN_T(IY411,IA,IGH,IS3,T))
         =G=
   VHSTOLOADT(IY411,IA,IS3,T)
;

* The following constraints replace simple bounds in bb123.sim, when
* investments in storage facilities are allowed. They pertain only to BB2 and to
* areas with an option to invest in storage facilities. Simple bounds cover all
* other situations.

QHSTOLOADTLIM(IY411,IA,IS3,T)$SUM(IGHSTO,IAGKN(IY411,IA,IGHSTO)) ..
* Existing or accumulated capacity
   SUM(IGHSTO$IAGK_Y(IY411,IA,IGHSTO),  (IGKFX_Y(IY411,IA,IGHSTO)+IGKVACCTOY(IY411,IA,IGHSTO))/GDATA(IGHSTO,'GDSTOHLOAD')
   )
* New investments
   +SUM(IGHSTO$IAGKN(IY411,IA,IGHSTO),   VGKN(IY411,IA,IGHSTO)/GDATA(IGHSTO,'GDSTOHLOAD')
   )
         =G=
   VHSTOLOADT(IY411,IA,IS3,T)
;

QESTOLOADTLIM(IY411,IA,IS3,T)$SUM(IGESTO,IAGKN(IY411,IA,IGESTO)) ..
* Existing or accumulated capacity
   SUM(IGESTO$IAGK_Y(IY411,IA,IGESTO),  (IGKFX_Y(IY411,IA,IGESTO)+IGKVACCTOY(IY411,IA,IGESTO))/GDATA(IGESTO,'GDSTOHLOAD')
   )
* New investments
   +SUM(IGESTO$IAGKN(IY411,IA,IGESTO),  VGKN(IY411,IA,IGESTO)/GDATA(IGESTO,'GDSTOHLOAD')   )
         =G=
   VESTOLOADT(IY411,IA,IS3,T)
;

* Storage contents does not exceed upper limit (MWh):
QHSTOVOLTLIM(IY411,IA,IS3,T)$SUM(IGHSTO,IAGKN(IY411,IA,IGHSTO)) ..
* Existing or accumulated capacity
  SUM(IGHSTO$IAGK_Y(IY411,IA,IGHSTO),   IGKFX_Y(IY411,IA,IGHSTO)+IGKVACCTOY(IY411,IA,IGHSTO)     )
* New investments
  +SUM(IGHSTO$IAGKN(IY411,IA,IGHSTO),   VGKN(IY411,IA,IGHSTO)
   )
         =G=
  VHSTOVOLT(IY411,IA,IS3,T)
;

QESTOVOLTLIM(IY411,IA,IS3,T)$SUM(IGESTO,IAGKN(IY411,IA,IGESTO)) ..
* Existing or accumulated capacity
  SUM(IGESTO$IAGK_Y(IY411,IA,IGESTO),  IGKFX_Y(IY411,IA,IGESTO)+IGKVACCTOY(IY411,IA,IGESTO)      )
* New investments
  +SUM(IGESTO$IAGKN(IY411,IA,IGESTO),  VGKN(IY411,IA,IGESTO)   )
         =G=
  VESTOVOLT(IY411,IA,IS3,T)
;

*---------- Maximal installable capacity per fuel type is restricted (MW): ----

QKFUELC(C,FFF)$FKPOT(C,FFF) ..
      SUM(IAGK_Y(IY4FIRST,IA,G)$(IGF(G,FFF) AND ICA(C,IA)), IGKVACCTOY(IY4FIRST,IA,G))
    + SUM(IAGK_Y(IY4FIRST,IA,G)$(IGF(G,FFF) AND ICA(C,IA)), IGKFXYMAX(IA,G))
    + SUM(IAGKN(IY411,IA,G)$(IGF(G,FFF) AND ICA(C,IA)),     VGKN(IY411,IA,G))
         =L=  FKPOT(C,FFF);

QKFUELR(IR,FFF)$FKPOT(IR,FFF)..

      SUM(IAGK_Y(IY4FIRST,IA,G)$(IGF(G,FFF) AND RRRAAA(IR,IA)), IGKVACCTOY(IY4FIRST,IA,G))
      + SUM(IAGK_Y(IY4FIRST,IA,G)$(IGF(G,FFF) AND RRRAAA(IR,IA)), IGKFXYMAX(IA,G))
      + SUM(IAGKN(IY411,IA,G)$(IGF(G,FFF) AND RRRAAA(IR,IA)),   VGKN(IY411,IA,G))
        =L=  FKPOT(IR,FFF);


QKFUELA(IA,FFF)$FKPOT(IA,FFF) ..
        SUM(IAGK_Y(IY4FIRST,IA,G)$IGF(G,FFF),  IGKVACCTOY(IY4FIRST,IA,G))
      + SUM(IAGK_Y(IY4FIRST,IA,G)$IGF(G,FFF), IGKFXYMAX(IA,G))
      + SUM(IAGKN(IY411,IA,G)$IGF(G,FFF),   VGKN(IY411,IA,G))
        =L=  FKPOT(IA,FFF);

* Electricity generation constraints by fuel (in energy), country

QGMINFUELC(IY411,C,FFF)$FGEMIN(C,FFF)..
     SUM((IA,IS3,T)$ICA(C,IA), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),  IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IA,IS3,T)$ICA(C,IA), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),   IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
     =G= FGEMIN(C,FFF);

QGMAXFUELC(IY411,C,FFF)$FGEMAX(C,FFF)..
    FGEMAX(C,FFF)
     =G=
     SUM((IA,IS3,T)$ICA(C,IA), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),   IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IA,IS3,T)$ICA(C,IA), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),    IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
;
* Electricity generation constraints by fuel (in energy), region
QGMINFUELR(IY411,IR,FFF)$FGEMIN(IR,FFF)..
     SUM((IA,IS3,T)$RRRAAA(IR,IA), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),  IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IA,IS3,T)$RRRAAA(IR,IA), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),   IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
     =G= FGEMIN(IR,FFF);

QGMAXFUELR(IY411,IR,FFF)$FGEMAX(IR,FFF)..
    FGEMAX(IR,FFF)
     =G=
     SUM((IA,IS3,T)$RRRAAA(IR,IA), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),  IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IA,IS3,T)$RRRAAA(IR,IA), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),   IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
;

* Electricity generation constraints by fuel (in energy), area

QGMINFUELA(IY411,IA,FFF)$FGEMIN(IA,FFF)..
     SUM((IS3,T), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),  IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IS3,T), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),   IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
     =G= FGEMIN(IA,FFF);

QGMAXFUELA(IY411,IA,FFF)$FGEMAX(IA,FFF)..
    FGEMAX(IA,FFF)
     =G=
     SUM((IS3,T), SUM(G$(IGF(G,FFF) AND IAGK_Y(IY411,IA,G)),   IHOURSINST(IS3,T) * VGE_T(IY411,IA,G,IS3,T)))
   + SUM((IS3,T), SUM(G$(IGF(G,FFF) AND IAGKN(IY411,IA,G)),    IHOURSINST(IS3,T) * VGEN_T(IY411,IA,G,IS3,T)))
;

* Fuel use constraints (in energy), area

QGMINAF(IY411,IA,FFF)$GMINF(IA,FFF)..
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))
    =G= GMINF(IA,FFF);

QGMAXAF(IY411,IA,FFF)$GMAXF(IA,FFF)..
    GMAXF(IA,FFF)
         =G=
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))
;


QGEQAF(IY411,IA,FFF)$GEQF(IA,FFF)..
    GEQF(IA,FFF)
   =E=
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* (1-GEFFDERATE(IA,IGE)))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*(1-GEFFDERATE(IA,IGH)))))
   ;

* Fuel use constraints (in energy), region

QGMINRF(IY411,IR,FFF)$GMINF(IR,FFF)..
    SUM(IA$RRRAAA(IR,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    )
    =G= GMINF(IR,FFF);

QGMAXRF(IY411,IR,FFF)$GMAXF(IR,FFF)..
    GMAXF(IR,FFF)
         =G=
    SUM(IA$RRRAAA(IR,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    );


QGEQRF(IY411,IR,FFF)$GEQF(IR,FFF)..
    GEQF(IR,FFF)
   =E=
    SUM(IA$RRRAAA(IR,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    );

* Fuel use constraints (in energy), country

QGMINCF(IY411,C,FFF)$GMINF(C,FFF)..
    SUM(IA$ICA(C,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    )
    =G= GMINF(C,FFF);

QGMAXCF(IY411,C,FFF)$GMAXF(C,FFF)..
    GMAXF(C,FFF)
         =G=
    SUM(IA$ICA(C,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    );


QGEQCF(IY411,C,FFF)$GEQF(C,FFF)..
    GEQF(C,FFF)
   =E=
    SUM(IA$ICA(C,IA),
    SUM(IGE$(IAGK_Y(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGK_Y(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))

    +SUM(IGE$(IAGKN(IY411,IA,IGE) AND IGF(IGE,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    +SUM(IGH$(IAGKN(IY411,IA,IGH) AND IGF(IGH,FFF)),
                 IOF3P6 * SUM((IS3,T), IHOURSINST(IS3,T) *
                 GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE')*GEFFDERATE(IA,IGH))))
    );



*----------- Transmission (MW):------------------------------------------------

* Electricity transmission is limited by transmission capacity:

QXK(IY411,IRE,IRI,IS3,T)$(IXKINI_Y(IY411,IRE,IRI) OR IXKN(IRI,IRE) OR IXKN(IRE,IRI))..
     XKDERATE(IRE,IRI)*(
       IXKINI_Y(IY411,IRE,IRI)+IXKVACCTOY(IY411,IRE,IRI)
     + VXKN(IY411,IRE,IRI)$(IXKN(IRE,IRI) OR IXKN(IRI,IRE))+ VXKN(IY411,IRI,IRE)$(IXKN(IRE,IRI) OR IXKN(IRI,IRE))
     )
     =G=  VX_T(IY411,IRE,IRI,IS3,T);

*------------ Emissions: ------------------------------------------------------

QLIMCO2(IY411,C)$(ILIM_CO2_Y(IY411,C) LT INF)..

      SUM(IAGK_Y(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGE) * IOF0001) *
      IOF3P6 * VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE')* GEFFDERATE(IA,IGE))))

    + SUM(IAGK_Y(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGH) * IOF0001) *
      IOF3P6 * GDATA(IGH,'GDCV')*VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))

    + SUM(IAGKN(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGE) * IOF0001) *
      IOF3P6 * VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * GEFFDERATE(IA,IGE))))

    + SUM(IAGKN(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_CO2(IGH) * IOF0001) *
      IOF3P6 * GDATA(IGH,'GDCV')*VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))

      =L= ILIM_CO2_Y(IY411,C) ;


QLIMSO2(IY411,C)$(ILIM_SO2_Y(IY411,C) LT INF)..

      SUM(IAGK_Y(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGE) * IOF0001) *
      IOF3P6 * VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * GEFFDERATE(IA,IGE))))

    + SUM(IAGK_Y(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGH) * IOF0001) *
      IOF3P6 * GDATA(IGH,'GDCV') * VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))

    + SUM(IAGKN(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGE) * IOF0001) *
      IOF3P6 * VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * GEFFDERATE(IA,IGE))))

    + SUM(IAGKN(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (IM_SO2(IGH) * IOF0001) *
      IOF3P6 * GDATA(IGH,'GDCV') * VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))


      =L= ILIM_SO2_Y(IY411,C) ;


QLIMNOX(IY411,C)$(ILIM_NOX_Y(IY411,C) LT INF)..

     SUM(IAGK_Y(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (GDATA(IGE,'GDNOX') * IOF0000001) *
     IOF3P6 * VGE_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * GEFFDERATE(IA,IGE))))

   + SUM(IAGK_Y(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (GDATA(IGH,'GDNOX') * IOF0000001) *
     IOF3P6 * GDATA(IGH,'GDCV') * VGH_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))

   + SUM(IAGKN(IY411,IA,IGE)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (GDATA(IGE,'GDNOX') * IOF0000001) *
     IOF3P6 * VGEN_T(IY411,IA,IGE,IS3,T)/(GDATA(IGE,'GDFE') * GEFFDERATE(IA,IGE))))

   + SUM(IAGKN(IY411,IA,IGH)$ICA(C,IA), SUM((IS3,T), IHOURSINST(IS3,T) * (GDATA(IGH,'GDNOX') * IOF0000001) *
     IOF3P6 * GDATA(IGH,'GDCV') * VGHN_T(IY411,IA,IGH,IS3,T)/(GDATA(IGH,'GDFE') * GEFFDERATE(IA,IGH))))

      =L= ILIM_NOX_Y(IY411,C) ;


*QGE2LEVEL(IY411,IA,IGE,IS3,T)$(IG2LEVEL(IGE) AND IAGK_Y(IY411,IA,IGE))..
*       VGE2LEVEL(IY411,IA,IGE,IS3,'WORKDAY')$TWORKDAY(T)
*     + VGE2LEVEL(IY411,IA,IGE,IS3,'WEEKEND')$TWEEKEND(T) =E= VGE_T(IY411,IA,IGE,IS3,T);

* Reserve requirement attributed to electricity demand.


/*QRESDE(IY411,IR,IS3,T)$IRESDE(IR) ..
      SUM(IAGK_Y(IY411,IA,IGERES)$((RRRAAA(IR,IA)) AND IGNOTETOH(IGERES)), VGE_T.UP(IY411,IA,IGERES,IS3,T)-VGE_T(IY411,IA,IGERES,IS3,T))
    + SUM(IAGKN(IY411,IA,IGERES)$((RRRAAA(IR,IA)) AND IGNOTETOH(IGERES)), VGKN(IY411,IA,IGERES)*GKDERATE(IA,IGERES,IS3)-VGEN_T(IY411,IA,IGERES,IS3,T))
         =G=
    +IRESDE(IR)*(   (IDE_T_Y(IY411,IR,IS3,T)
         + SUM(DEF_U1,VDEF_T(IY411,IR,IS3,T,DEF_U1) )
         - SUM(DEF_D1,VDEF_T(IY411,IR,IS3,T,DEF_D1) )
         + SUM(DEF_U2,VDEF_T(IY411,IR,IS3,T,DEF_U2) )
         - SUM(DEF_D2,VDEF_T(IY411,IR,IS3,T,DEF_D2) )
         + SUM(DEF_U3,VDEF_T(IY411,IR,IS3,T,DEF_U3) )
         - SUM(DEF_D3,VDEF_T(IY411,IR,IS3,T,DEF_D3) )
          )/(1-DISLOSS_E(IR)))
;*/


/** Reserve requirement attributed to wind.
QRESWI(IY411,IR,IS3,T)$IRESWI(IR) ..
      SUM(IAGK_Y(IY411,IA,IGERES)$((RRRAAA(IR,IA)) AND IGNOTETOH(IGERES)), VGE_T.UP(IY411,IA,IGERES,IS3,T)-VGE_T(IY411,IA,IGERES,IS3,T))
    + SUM(IAGKN(IY411,IA,IGERES)$((RRRAAA(IR,IA)) AND IGNOTETOH(IGERES)), VGKN(IY411,IA,IGERES)*GKDERATE(IA,IGERES,IS3)-VGEN_T(IY411,IA,IGERES,IS3,T))
         =G=
    +IRESWI(IR)*(
          SUM(IAGK_Y(IY411,IA,IGWND)$RRRAAA(IR,IA),VGE_T(IAGK_Y,IS3,T))
         +SUM(IAGKN(IY411,IA,IGWND)$RRRAAA(IR,IA),VGEN_T(IAGKN,IS3,T))
         );*/


QMAXINVEST(IY411,C,FFF)$(FMAXINVEST(C,FFF) > 0) ..
         FMAXINVEST(C,FFF)
 =G=
         SUM((IAGKN(IY411,IA,G))$(ICA(C,IA) and IGF(G,FFF)), VGKN(IY411,IA,G))
;


QGMAXINVEST2(IY411,C,IGKFIND)$GROWTHCAP(C,IGKFIND)..
   SUM(IA$(IAGKN(IY411,IA,IGKFIND) AND ICA(C,IA)),VGKN(IY411,IA,IGKFIND))
   =L=
   SUM(IA$(IAGKN(IY411,IA,IGKFIND) AND ICA(C,IA)),
    (IGKFX_Y_1(IY411,IA,IGKFIND)-IGKFX_Y(IY411,IA,IGKFIND)+IGKVACCEOY(IY411,IA,IGKFIND)-IGKVACCTOY(IY411,IA,IGKFIND)))
   +IGROWTHCAP(C,IGKFIND);



*------ Begin equations used only in balbase3 ----------------------------------
$ifi not %BB3%==yes $goto label_bb3_1
QHYFXRW(IY411,IR,IS3)$(IHYFXRW(IR,IS3) GT 0)..
        IHYFXRW(IR,IS3)
 =G=
       SUM((IA,IGHYRS)$(RRRAAA(IR,IA) AND (IAGK_Y(IY411,IA,IGHYRS))),
       SUM(T,IHOURSINST(IS3,T)*VGE_T(IY411,IA,IGHYRS,IS3,T)))
     + SUM((IA,IGHYRR)$(RRRAAA(IR,IA) AND (IAGK_Y(IY411,IA,IGHYRR))),
       SUM(T,IHOURSINST(IS3,T)*VGE_T(IY411,IA,IGHYRR,IS3,T)))
     ;

QHYFXCW(IY411,C,IS3)$(SUM(IR$CCCRRR(C,IR),IHYFXRW(IR,IS3)) GT 0)..
       SUM((IA,IGHYRS)$(ICA(C,IA) AND (IAGK_Y(IY411,IA,IGHYRS))),
       SUM(T,IHOURSINST(IS3,T)*VGE_T(IY411,IA,IGHYRS,IS3,T)))
      + SUM((IA,IGHYRR)$(ICA(C,IA) AND (IAGK_Y(IY411,IA,IGHYRR))),
       SUM(T,IHOURSINST(IS3,T)*VGE_T(IY411,IA,IGHYRR,IS3,T)))
       =L= SUM(IR$CCCRRR(C,IR),IHYFXRW(IR,IS3));
$label  label_bb3_1
*------ End equations used only in Balbase3 ------------------------------------

*------ Equations for use only in Balbase4: ------------------------------------

$ifi not %BB4%==yes $goto label_BB4_2
*-------------------------------------------------------------------------------
*--------- Total generation capacity increase between two consecutive model years is found for each technology --
*-------------------------------------------------------------------------------
* Note: IYALIAS44 is aliased with Y. IY411 holds all year in model. IY410 holds all year in model except the last one. Y402 is aliased with Y.
QGKVACCTOT(IYALIAS44,IA,IGKFIND,SIMYEARS)$(IY410(IYALIAS44) AND ORD(IYALIAS44) = ORD_IY(SIMYEARS) )..

   SUM(Y402$(IY411(Y402) AND ORD(Y402) = ORD_IY(SIMYEARS+1)), VGKVACCTOT(Y402,IA,IGKFIND))

  =E=

  VGKVACCTOT(IYALIAS44,IA,IGKFIND) + VGKN(IYALIAS44,IA,IGKFIND)
;


*-------------------------------------------------------------------------------
*--------- New generation capacity is removed when lifetime years have passed --
*-------------------------------------------------------------------------------
*BB4:
* Note: IYALIAS44 is aliased with Y. IY411 holds all year in model. IY410 holds all year in model except the last one. Y402 and Y403 are aliased with Y.
QGKVACCTOY(IYALIAS44,IA,IGKFIND,SIMYEARS)$(IY410(IYALIAS44) AND ORD(IYALIAS44) = ORD_IY(SIMYEARS) )..

      SUM(Y402$(IY411(Y402) AND ORD(Y402) = ORD_IY(SIMYEARS+1)), VGKVACCTOY(Y402,IA,IGKFIND))

     =E=
      VGKVACCTOT(IYALIAS44,IA,IGKFIND) + VGKN(IYALIAS44,IA,IGKFIND) -
     SUM(Y402$( YVALUE(Y402) <=  ( SUM(Y403$(ORD(Y403) = ORD_IY(SIMYEARS+1)),YVALUE(Y403))  -    GDATA(IGKFIND, 'GDLIFETIME')    ) ),
             IVGKN(Y402,IA,IGKFIND)$(YVALUE(Y402) LT YVALUE_YALIAS) +
             VGKN(Y402,IA,IGKFIND)$(YVALUE(Y402) GE YVALUE_YALIAS)
        )
;
*-------------------------------------------------------------------------------
*---------- Capacity constraint existing technologies --------------------------
*-------------------------------------------------------------------------------
*BB4:
/*     Hans: indført IY401: skulle være ækvivalent, men elegantere; begrænset til IGDISPATCH
QEGKUP(IYALIAS44,IA,IGKE,S,T)$(IY411(IYALIAS44) AND ( ORD(IYALIAS44) <> ORD_YALIAS ) AND (IAGK_Y(IYALIAS44,IA,IGKE) OR IAGKN(IYALIAS44,IA,IGKE))   )..

        VGE_T(IYALIAS44,IA,IGKE,S,T) =L=
         (VGKVACCTOY(IYALIAS44,IA,IGKE) + IGKFX_Y(IYALIAS44,IA,IGKE))*GKDERATE(IA,IGKE,S)
;
*/

QEGKUP(IY401,IA,IGDISPATCH(IGKE),S,T)$(IAGK_Y(IY401,IA,IGKE) OR IAGKN(IY401,IA,IGKE))..

        VGE_T(IY401,IA,IGKE,S,T) =L=
         (VGKVACCTOY(IY401,IA,IGKE) + IGKFX_Y(IY401,IA,IGKE))*GKDERATE(IA,IGKE,S)
;



/*     Hans: indført IY401: skulle være ækvivalent, men elegantere; begrænset til IGDISPATCH
QHGKUP(IYALIAS44,IA,IGKH,S,T)$(IY411(IYALIAS44) AND ( ORD(IYALIAS44) <> ORD_YALIAS ) AND (IAGK_Y(IYALIAS44,IA,IGKH) OR IAGKN(IYALIAS44,IA,IGKH)) )..

        VGH_T(IYALIAS44,IA,IGKH,S,T) =L=
         (VGKVACCTOY(IYALIAS44,IA,IGKH) + IGKFX_Y(IYALIAS44,IA,IGKH))*GKDERATE(IA,IGKH,S)
; */

QHGKUP(IY401,IA,IGDISPATCH(IGKH),S,T)$(IAGK_Y(IY401,IA,IGKH) OR IAGKN(IY401,IA,IGKH)) ..

        VGH_T(IY401,IA,IGKH,S,T) =L=
         (VGKVACCTOY(IY401,IA,IGKH) + IGKFX_Y(IY401,IA,IGKH))*GKDERATE(IA,IGKH,S)
;


*-------------------------------------------------------------------------------
* Existing  hydro-run-of-river, windpower and solarpower can not be dispatched
*-------------------------------------------------------------------------------

*---- Generation existing capacity, hydro-run-of-river technologies ------------
*BB4:
QHYRRDISP(IY401,IA,IGHYRR,S,T)$((IAGK_Y(IY401,IA,IGHYRR) OR IAGKN(IY401,IA,IGHYRR)) AND IWTRRRSUM(IA))..

          VGE_T(IY401,IA,IGHYRR,S,T) =E=
         (WTRRRFLH(IA) * (VGKVACCTOY(IY401,ia,IGHYRR) + IGKFX_Y(IY401,IA,IGHYRR))
                                         * WTRRRVAR_T(IA,S,T) /* *GKDERATE(IA,IGHYRR,S) */ ) / IWTRRRSUM(IA)      /* Hans  - se nedenfor */
;
                                       /*  */
*---- Generation on existing capacity, windpower technologies ------------------
* Hans : slettet  "*GKDERATE(IA,IGWND,S)" , jfr også bemærkningerne i BB4.sim, og den måde, .fx er sat op på FOR WND, ETC
* Hans: i øvrigt vel behov for at får gennemtænkt dette: man kan vel argumentere, at GKDEREATE er relevant for dispatchable techs,
* mens for non-disp techs er den irrelevant, fordi her kommer produktionsstørrelserne fra helt andre kilder (prognoseprogrammer, f.eks.), hvor der meget bedre kan tages højde for gkderate-agtige ting.
* Et argument for at bevare ghkderate ved non-disp techs kunne være, at det given en fleksibilitet (valgmulighed) i relation til forudsætnigner om oprindelse af data.
* Men bevares den, skal man i hvert fald tænke nøje over, hvilke data, der indsættes i gkderate.
* I øvrigt er der rigtigt mange data i gkderate...

*BB4:
QWNDDISP(IY401,IA,IGWND,S,T)$((IAGK_Y(IY401,IA,IGWND) OR IAGKN(IY401,IA,IGWND)) AND IWND_SUMST(IA))..

         VGE_T(IY401,IA,IGWND,S,T) =E=
         (WNDFLH(IA) * (VGKVACCTOY(IY401,IA,IGWND) + IGKFX_Y(IY401,IA,IGWND))
                                          * WND_VAR_T(IA,S,T)/* *GKDERATE(IA,IGWND,S) */ ) / IWND_SUMST(IA)    /* Hans */
;


*---- Generation on existing capacity, solarpower technologies -----------------
*BB4:
QSOLEDISP(IY401,IA,IGSOLE,S,T)$((IAGK_Y(IY401,IA,IGSOLE) OR IAGKN(IY401,IA,IGSOLE)) AND ISOLESUMST(IA))..

         VGE_T(IY401,IA,IGSOLE,S,T) =E=
         (SOLEFLH(IA) * (VGKVACCTOY(IY401,IA,IGSOLE) + IGKFX_Y(IY401,IA,IGSOLE))
                                          * SOLE_VAR_T(IA,S,T) /* *GKDERATE(IA,IGSOLE,S) */ ) / ISOLESUMST(IA)        /* Hans */
;


*BB4:
QSOLHDISP(IY401,IA,IGSOLH,S,T)$((IAGK_Y(IY401,IA,IGSOLH) OR IAGKN(IY401,IA,IGSOLH)) AND ISOLHSUMST(IA))..

         VGE_T(IY401,IA,IGSOLH,S,T) =E=
         (SOLHFLH(IA) * (VGKVACCTOY(IY401,IA,IGSOLH) + IGKFX_Y(IY401,IA,IGSOLH))
                                        * SOLH_VAR_T(IA,S,T) /* *GKDERATE(IA,IGSOLH,S) */ ) / ISOLHSUMST(IA)          /* Hans */
;


*---- Transfer information on new transmission capacity to next year -----------

*BB4:
QXKN(IYALIAS44,IRE,IRI,SIMYEARS)$(IY410(IYALIAS44) AND ORD(IYALIAS44) = ORD_IY(SIMYEARS))..

        SUM(Y402$(IY411(Y402) AND ORD(Y402) = ORD_IY(SIMYEARS+1)), VXKINI_Y(Y402,IRE,IRI) ) =E= VXKINI_Y(IYALIAS44,IRE,IRI) + VXKN(IYALIAS44,IRE,IRI)
                                 + VXKN(IYALIAS44,IRI,IRE)
;



$ontext
*-------------------------------------------------------------------------------
*---------- capacity constraints existing combination technologies -------------
*-------------------------------------------------------------------------------
*BB4:
QEGKCOMB1UP(IYALIAS44,IA,IGCOMB1,S,T)$( IGKE(IGCOMB1) AND IY411(Y) AND ( ORD(Y) <> ORD_YALIAS ) AND (IAGK_Y(IYALIAS44,IA,IGCOMB1) OR IAGKN_Y(IYALIAS44,IA,IGCOMB1))    )..

         VGE_T(IA,IGCOMB1,Y,IST) =L=
         (VGKVACCTOY(IGCOMB1,IA,Y) + IGKFX_Y(IGCOMB1,IA,Y))*GKDERATE(IGCOMB1,IA,S)*GDATA(IGCOMB1,'GDCOMBSK')
;


QEGKCOMB2UP(IA,IGCOMB1,IGCOMB2,Y,IST(S,T))$(IGKE(IGCOMB1) AND GGCOMB(IGCOMB1,IGCOMB2) AND IY411(Y) AND ( ORD(Y) <> ORD_YALIAS )  AND (IAGK_Y(IA,IGCOMB1,Y) OR IAGKN_Y(IA,IGCOMB1,Y))   )..

         VGE_T(IA,IGCOMB2,Y,IST) =L=
         (VGKVACCTOY(IGCOMB1,IA,Y) + IGKFX_Y(IGCOMB1,IA,Y))*GKDERATE(IGCOMB1,IA,S)*GDATA(IGCOMB2,'GDCOMBSK')
;

QHGKCOMB1UP(IA,IGCOMB1,Y,IST(S,T))$(IGKH(IGCOMB1) AND IY(Y) AND ( ORD(Y) <> ORD_YALIAS )   )..

         VGH_T(IA,IGCOMB1,Y,IST) =L=
         (VGKVACCTOY(IGCOMB1,IA,Y) + IGKFX_Y(IGCOMB1,IA,Y))*GKDERATE(IGCOMB1,IA,S)*GDATA(IGCOMB1,'GDCOMBSK')
;

QHGKCOMB2UP(IA,IGCOMB1,IGCOMB2,Y,IST(S,T))$(IGKE(IGCOMB1) AND GGCOMB(IGCOMB1,IGCOMB2) AND IY(Y) AND ( ORD(Y) <> ORD_YALIAS )  )..

         VGH_T(IA,IGCOMB2,Y,IST)$(IGKH(IGCOMB1) AND GGCOMB(IGCOMB1,IGCOMB2)) =L=
         (VGKVACCTOY(IGCOMB1,IA,Y) + IGKFX_Y(IGCOMB1,IA,Y))*GKDERATE(IGCOMB1,IA,S)*GDATA(IGCOMB2,'GDCOMBSK')
;
$offtext
*------ End equations for use only in Balbase4 ---------------------------------
$label label_BB4_2

*-------------------------------------------------------------------------------
*----- Any equations for addon to be placed here: ------------------------------
*-------------------------------------------------------------------------------

* These add-on equations pertain to combination technologies.
$ifi %COMBTECH%==yes $include '../../base/addons/combtech/combEQ.inc';
* This file includes:
*EQUATIONS
*   QECOMBGLK(AAA,G,S,T)   'Combination technology, sum of production limit, electricity'
*   QECOMBSLO(AAA,G,S,T)   'Combination technology, minimum share of total production, electricity'
*   QECOMBSUP(AAA,G,S,T)   'Combination technology, maximum share of total production, electricity'
*   QHCOMBGLK(AAA,G,S,T)   'Combination technology, sum of production limit, heat'
*   QHCOMBSLO(AAA,G,S,T)   'Combination technology, minimum share of total production, heat'
*   QHCOMBSUP(AAA,G,S,T)   'Combination technology, maximum share of total production, heat'
*   QNECOMBGLK(AAA,G,S,T)  'New combination technology, sum of production limit, electricity'
*   QNECOMBSLO(AAA,G,S,T)  'New combination technology, minimum share of total production, electricity'
*   QNECOMBSUP(AAA,G,S,T)  'New combination technology, maximum share of total production, electricity'
*   QNHCOMBGLK(AAA,G,S,T)  'New combination technology, sum of production limit, heat'
*   QNHCOMBSLO(AAA,G,S,T)  'New combination technology, minimum share of total production, heat'
*   QNHCOMBSUP(AAA,G,S,T)  'New combination technology, maximum share of total production, heat';

* These add-on equations pertain to price sensitive electricity exchange with
* third countries.
$ifi %X3V%==yes $include '../../base/addons/x3v/model/x3veq.inc';

* These add-on equations pertain to natural gas.
$ifi %GAS%==yes $include '../../base/addons/gas/gasequations.inc';
* This file includes:
* [list equations]
$ifi %CAES%==yes $INCLUDE '../../base/addons/CAES/CAESequations.inc';

* These add-on equations pertain to hydrogen.
$ifi %H2%==yes $include '../../base/addons/Hydrogen/H2equations.inc';

* These add-on equations pertain to transport(KHED)
$ifi %TSP%==yes $INCLUDE '../../base/addons/Transport/TSPEquations.inc';

* These add-on equations pertain to targets for wind power.
$ifi not %WINDTARGET%==yes $goto end_windtarget_eq
$ifi EXIST 'wndtargetdata.inc' $include 'wndtargetdata.inc';
$ifi not EXIST 'wndtargetdata.inc'$INCLUDE '../../base/addons/windtarget/wndtargetdata.inc';
$INCLUDE '../../base/addons/windtarget/windequations.inc';
$label end_windtarget_eq

* These add-on equations pertain to heat transmission.
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htequations.inc';

* These add-on equations pertain to targets for renewables.
$ifi %RENEWTARGET%==yes $INCLUDE '../../base/addons/renewtarget/renewdata.inc';
$ifi %RENEWTARGET%==yes $INCLUDE '../../base/addons/renewtarget/reneweqn.inc';

* These add-on equations pertain to capping fossil fuel consumption.
$ifi %FOSSILTARGET%==yes $INCLUDE '../../base/addons/fossiltarget/fossildata.inc';
$ifi %FOSSILTARGET%==yes $INCLUDE '../../base/addons/fossiltarget/fossileqn.inc';

$ifi %REShareE%==yes $include  '../../base/addons/REShareE/RESEeqns.inc';
$ifi %REShareEH%==yes $include '../../base/addons/REShareEH/RESEHeqns.inc';

$ifi %AGKNDISC%==yes  $include  '../../base/addons/AGKNDISC/AGKNDISCequations.inc';

*-------------------------------------------------------------------------------
*----- End: Any equations for addon to be placed here. -------------------------
*-------------------------------------------------------------------------------



*-------------------------------------------------------------------------------
*  End: Declaration and definition of EQUATIONS
*-------------------------------------------------------------------------------



*-------------------------------------------------------------------------------
* Definition of the models:
*-------------------------------------------------------------------------------

/*
Hans: denne bør da tages helt ud af koden:
MODEL BALBASE2  'Balmorel model with endogeneous investments'
/
*--- Objective function --------------------------------------------------------
                                QOBJ
*--- Balance equations ---------------------------------------------------------
                                QEEQ
                                QHEQ
*--- Feasible generation region ------------------------------------------------
                                QGCBGBPR
                                QGCBGEXT
                                QGCVGEXT
                                QGGETOH
                                QGNCBGBPR
                                QGNCBGEXT
                                QGNCVGEXT
                                QGNGETOH
$ifi %BASELOADSERVICE%==yes     QRESWI
$ifi %BASELOADSERVICE%==yes     QRESDE
*--- Generation capacities -----------------------------------------------------
                                QGEKNT
                                QGHKNT
                                QGKNWND
                                QGKNHYRR
                                QGKNSOLE
                                QGKNSOLH
*--- Storage restrictions ------------------------------------------------------

                                QHYRSSEQ
                                QESTOVOLT
                                QESTOLOADT
                                QHSTOVOLT
                                QHSTOLOADT
                                QHSTOLOADTLIM
                                QESTOLOADTLIM
                                QHSTOVOLTLIM
                                QESTOVOLTLIM

*--- Transmission capacity -----------------------------------------------------
                                QXK
*--- Fuel capacity restrictions ------------------------------------------------
                                QKFUELC
                                QKFUELR
                                QKFUELA

*--- Electricity generation restrictions by fuel -------------------------------
                                QGMINFUELC
                                QGMAXFUELC
                                QGMINFUELR
                                QGMAXFUELR
                                QGMINFUELA
                                QGMAXFUELA
*--- Fuel consumption restrictions ---------------------------------------------
                                QGMINCF
                                QGMAXCF
                                QGEQCF
                                QGMINRF
                                QGMAXRF
                                QGEQRF
                                QGMINAF
                                QGMAXAF
                                QGEQAF
*--- Emissions restrictions ----------------------------------------------------
                                QLIMCO2
                                QLIMSO2
                                QLIMNOX
*--- Operational restrictions --------------------------------------------------
                                QGE2LEVEL

*----- Any equations for addon to be placed here: ------------------------------
* These add-on equations pertain to transport(KHED)
$ifi %TSP%==yes $INCLUDE '../../base/addons/Transport/TSPbb1.inc';
*--- Capacity restrictions for decommisioning ----------------------------------
$ifi %DECOMPEFF%==yes           QGEKOT
$ifi %DECOMPEFF%==yes           QGHKOT
$ifi %DECOMPEFF%==yes           QGKOHYRR
$ifi %DECOMPEFF%==yes           QGKOWND
$ifi %DECOMPEFF%==yes           QGKOSOLE
*--- Investment restricitions --------------------------------------------------
$ifi %BASELOADSERVICE%==yes     QMAXINVEST
$ifi %X3VfxQ%==yes              QX3VBAL
$ifi %WINDTARGET%==yes $include '../../base/addons/windtarget/wndtargetbb12.inc';
$ifi %COMBTECH%==yes $include '../../base/addons/combtech/combbb2.inc';
$ifi %GAS%==yes $INCLUDE '../../base/addons/gas/gasbb2.inc';
$ifi %CAES%==yes $INCLUDE '../../base/addons/CAES/CAESbb2.inc';
$ifi %H2%==yes $INCLUDE '../../base/addons/Hydrogen/H2bb1.inc'
$ifi %FOSSILTARGET%==yes QFOSSILTARGET
$ifi %RENEWTARGET%==yes QRENEW
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htbb1.inc';
$ifi %REShareE%==yes QREShareE
$ifi %REShareEH%==yes QREShareEH

$ifi %AGKNDISC%==yes  QAGKNDISCCONT
$ifi %AGKNDISC%==yes  QAGKNDISC01

*----- End: Any equations for addon to be placed here. -------------------------
/;

*/


MODEL BALBASE4  'Balmorel model with endogeneous investments'
/
*--- Objective function --------------------------------------------------------
                                QOBJ
*--- Balance equations ---------------------------------------------------------
                                QEEQ
                                QHEQ
*--- Feasible generation region ------------------------------------------------
                                QGCBGBPR
                                QGCBGEXT
                                QGCVGEXT
                                QGGETOH
                                QGNCBGBPR
                                QGNCBGEXT
                                QGNCVGEXT
                                QGNGETOH

*--- Generation capacities -----------------------------------------------------
                                QGEKNT
                                QGHKNT
                                QGKNWND
                                QGKNHYRR
                                QGKNSOLE
                                QGKNSOLH

*--- Storage restrictions ------------------------------------------------------
                                QHYRSSEQ
                                QESTOVOLT
                                QESTOLOADT
                                QHSTOVOLT
                                QHSTOLOADT
                                QHSTOLOADTLIM
                                QESTOLOADTLIM
                                QHSTOVOLTLIM
                                QESTOVOLTLIM


*--- Transmission capacity -----------------------------------------------------
                                QXK
*--- Fuel capacity restrictions ------------------------------------------------
                                QKFUELC
                                QKFUELR
                                QKFUELA

*--- Electricity generation restrictions by fuel -------------------------------
                                QGMINFUELC
                                QGMAXFUELC
                                QGMINFUELR
                                QGMAXFUELR
                                QGMINFUELA
                                QGMAXFUELA
*--- Fuel consumption restrictions ---------------------------------------------
                                QGMINCF
                                QGMAXCF
                                QGEQCF
                                QGMINRF
                                QGMAXRF
                                QGEQRF
                                QGMINAF
                                QGMAXAF
                                QGEQAF
*--- Emissions restrictions ----------------------------------------------------
                                QLIMCO2
                                QLIMSO2
                                QLIMNOX
*--- Operational restrictions --------------------------------------------------
*                                QGE2LEVEL

*----- Any equations for addon to be placed here: ------------------------------
*--- Capacity restrictions for decommisioning ----------------------------------
$ifi %DECOMPEFF%==yes           QGEKOT
$ifi %DECOMPEFF%==yes           QGHKOT
$ifi %DECOMPEFF%==yes           QGKOHYRR
$ifi %DECOMPEFF%==yes           QGKOWND
$ifi %DECOMPEFF%==yes           QGKOSOLE
*--- Investment restricitions --------------------------------------------------
                                QMAXINVEST
$ifi %X3VfxQ%==yes              QX3VBAL
$ifi %WINDTARGET%==yes $include '../../base/addons/windtarget/wndtargetbb12.inc';
$ifi %COMBTECH%==yes $include '../../base/addons/combtech/combbb2.inc';
$ifi %GAS%==yes $INCLUDE '../../base/addons/gas/gasbb2.inc';
$ifi %CAES%==yes $INCLUDE '../../base/addons/CAES/CAESbb2.inc';
$ifi %H2%==yes $INCLUDE '../../base/addons/Hydrogen/H2bb1.inc'
$ifi %FOSSILTARGET%==yes QFOSSILTARGET
$ifi %RENEWTARGET%==yes QRENEW
$ifi %HEATTRANS%==yes $include '../../base/addons/heattrans/model/htbb1.inc';
$ifi %REShareE%==yes QREShareE
$ifi %REShareEH%==yes QREShareEH


$ifi %BB4%==yes QGKVACCTOY
$ifi %BB4%==yes QGKVACCTOT
$ifi %BB4%==yes    QEGKUP
$ifi %BB4%==yes    QHGKUP
*   QEGKCOMB1UP(AAA,G,S,T)         'capacity constraint on electricity'   Hans: hvad, er disse med eller hvad? COMBTECH helt ude?
*   QEGKCOMB2UP(AAA,G,S,T)          'capacity constraint on electricity combination'
*   QHGKCOMB1UP(AAA,G,S,T)         'capacity constraint on heat'
*   QHGKCOMB2UP(AAA,G,G,Y,S,T)       'capacity constraint on heat combination'
$ifi %BB4%==yes    QHYRRDISP
$ifi %BB4%==yes    QWNDDISP
$ifi %BB4%==yes    QSOLEDISP
$ifi %BB4%==yes    QSOLHDISP
$ifi %BB4%==yes    QXKN

$ifi %AGKNDISC%==yes  QAGKNDISCCONT
$ifi %AGKNDISC%==yes  QAGKNDISC01


 /;


* Scale the model: only equation QOBJ is really badly scaled:   Hans: Hov: går multiplikatoren den rigtige vej? skulle det ikke være  IOF0000001  ? Og hvad med BB1, BB2, BB3?
BALBASE4.SCALEOPT=1;
QOBJ.SCALE=IOF1000000;

*-------------------------------------------------------------------------------
*----- Any further models to be defined here:
*-------------------------------------------------------------------------------


*-------------------------------------------------------------------------------
*----- End: Any further models to be defined here
*-------------------------------------------------------------------------------

*-------------------------------------------------------------------------------
*----- End of definition of models ---------------------------------------------
*-------------------------------------------------------------------------------


* The input data are subject to a certain control for 'reasonable' values.
* The errors are checked by the code in the files ERRORx.INC

$INCLUDE '../../base/logerror/logerinc/error2.inc';
$ifi %COMBTECH%==yes  $INCLUDE  '../../base/addons/combtech/comberr2.inc';
$ifi %BB4%==yes       $INCLUDE  '../../base/addons/BB4/errorBB4.inc';


* The following file contains definitions of a number of temporary parameters
* and sets that may be used for printout of simulation results.
$ifi %PRINTFILES%==yes $INCLUDE '../../base/output/printout/printinc/print2.inc';

* The following file contains file and parameter definitions for the economic
* output module.
$ifi %ECONOMIC%==yes $INCLUDE '../../base/processing/economic/eco_def.inc';


*-------------------------------------------------------------------------------
* Control of formats for variable and equation listing:   VIRKER IKKE , ØV!          Hans: HVAD MED DETTE??
$ifi not %displaylistformat% == yes $goto label_Notdisplaylistformat
OPTION QOBJ:8:0:1;
OPTION QEEQ:8:0:1;
OPTION QHEQ:8:0:1;
/*
QGCBGBPR(Y,AAA,G,S,T)    'CHP generation (back pressure) limited by Cb-line'
QGCBGEXT(Y,AAA,G,S,T)    'CHP generation (extraction) limited by Cb-line'
QGCVGEXT(Y,AAA,G,S,T)    'CHP generation (extraction) limited by Cv-line'
QGGETOH(Y,AAA,G,S,T)     'Electric heat generation'
QGNCBGBPR(Y,AAA,G,S,T)   'CHP generation (back pressure) Cb-line, new'
QGNCBGEXT(Y,AAA,G,S,T)   'CHP generation (extraction) Cb-line, new'
QGNCVGEXT(Y,AAA,G,S,T)   'CHP generation (extraction) Cv-line, new'
QGNGETOH(Y,AAA,G,S,T)    'Electric heat generation, new'
QGE2LEVEL(Y,AAA,G,S,T)   'Variation on slowly regulated technologies'
QGEKNT(Y,AAA,G,S,T)      'Generation on new electricity cap, limited by cap'
QGHKNT(Y,AAA,G,S,T)      'Generation on new IGHH cap, limited by cap'
QGKNHYRR(Y,AAA,G,S,T)    'Generation on new hydro-ror limited by cap and water'
QGKNWND(Y,AAA,G,S,T)     'Generation on new windpower limited by cap and wind'
QGKNSOLE(Y,AAA,G,S,T)    'Generation on new solarpower limited by cap and sun'
QGKNSOLH(Y,AAA,G,S,T)    'Generation on new solarheat limited by cap and sun'
QHYRSSEQ(Y,AAA,S)        'Hydropower with reservoir seasonal energy constraint'
QHYMINRS(AAA,G,S)       'Hydropower reservoir - minimum level'
QHYMAXRS(AAA,G,S)       'Hydropower reservoir - maximum level'
QHYMING(Y,AAA,S,T)       'Regulated and unregulated hydropower production lower than capacity'
QESTOVOLT(Y,AAA,S,T)     'Electricty storage dynamic equation (MWh)'
QESTOLOADT(Y,AAA,S,T)    'Electricity storage loading less than heat production (MW)'
QHSTOVOLT(Y,AAA,S,T)     'Heat storage dynamic equation (MWh)'
QHSTOLOADT(Y,AAA,S,T)    'Heat storage loading less than heat production (MW)'
QHSTOLOADTLIM(Y,AAA,S,T) 'Upper limit to heat storage loading (MW)'
QESTOLOADTLIM(Y,AAA,S,T) 'Upper limit to electricity storage loading (MW)'
QHSTOVOLTLIM(Y,AAA,S,T)  'Heat storage capacity limit (MWh)'
QESTOVOLTLIM(Y,AAA,S,T)  'Electricity storage capacity limit (MWh)'
QKFUELC(C,FFF)          'Total capacity using fuel FFF is limited in country'
QKFUELR(RRR,FFF)        'Total capacity using fuel FFF is limited in region'
QKFUELA(AAA,FFF)        'Total capacity using fuel FFF is limited in area'
QGMINFUELC(Y,C,FFF)      'Minimum electricity generation by fuel per country'
QGMAXFUELC(Y,C,FFF)      'Maximum electricity generation by fuel per country'
QGMINFUELR(Y,RRR,FFF)    'Minimum electricity generation by fuel per region'
QGMAXFUELR(Y,RRR,FFF)    'Maximum electricity generation by fuel per region'
QGMINFUELA(Y,AAA,FFF)    'Minimum electricity generation by fuel per area'
QGMAXFUELA(Y,AAA,FFF)    'Maximum electricity generation by fuel per area'
QGMINCF(Y,C,FFF)         'Minimum fuel usage per country constraint'
QGMAXCF(Y,C,FFF)         'Maximum fuel usage per country constraint'
QGEQCF(Y,C,FFF)          'Required fuel usage per country constraint'
QGMINRF(Y,RRR,FFF)       'Minimum fuel usage per region constraint'
QGMAXRF(Y,RRR,FFF)       'Maximum fuel usage per region constraint'
QGEQRF(Y,RRR,FFF)        'Required fuel usage per region constraint'
QGMINAF(Y,AAA,FFF)       'Minimum fuel usage per area constraint'
QGMAXAF(Y,AAA,FFF)       'Maximum fuel usage per area constraint'
QGEQAF(Y,AAA,FFF)        'Required fuel usage per area constraint'
QXK(Y,IRRRE,IRRRI,S,T)   'Transmission capacity constraint'
QLIMCO2(Y,C)             'Limit on annual CO2-emission'
QLIMSO2(Y,C)             'Limit on annual SO2 emission'
QLIMNOX(Y,C)             'Limit on annual NOx emission'
QHYFXRW(Y,RRR,S)         'Hydro with reservoir available for this region and season (MWh)'
QHYFXCW(Y,C,S)           'Hydro with reservoir available for this country and season (MWh)'
QBASELOAD(C,S,T)        'Minimum production for baseload service providers (MW)'
QRESDE(Y,RRR,S,T)        'Reserve requirement proportional with demand (MW)'
QRESWI(Y,RRR,S,T)        'Reserve requirement proportional with wind power (MW)'
QMAXINVEST(Y,C,FFF)      'Maximal investment by country and fuel during one simulated year (MW)'
QGMAXINVEST2(Y,C,G)      'Maximum model generated capacity increase from one year to the next (MW)'

*Balbase4: ---------------------------------------------------------------------
$ifi %BB4%==yes   QGKVACCTOY(Y,AAA,G,SIMYEARS)      'new capacity constraint 1'
$ifi %BB4%==yes   QGKVACCTOT(Y,AAA,G,SIMYEARS)      'new capacity constraint 2'
$ifi %BB4%==yes   QEGKUP(Y,AAA,G,S,T)              'capacity constraint on electricity'
$ifi %BB4%==yes   QHGKUP(Y,AAA,G,S,T)              'capacity constraint on heat'
$ifi %BB4%==yes   QEGKCOMB1UP(Y,AAA,G,S,T)         'capacity constraint on electricity'
$ifi %BB4%==yes   QEGKCOMB2UP(Y,AAA,G,S,T)         'capacity constraint on electricity combination'
$ifi %BB4%==yes   QHGKCOMB1UP(Y,AAA,G,S,T)         'capacity constraint on heat'
$ifi %BB4%==yes   QHGKCOMB2UP(AAA,G,G,Y,S,T)        'capacity constraint on heat combination'
$ifi %BB4%==yes   QHYRRDISP(Y,AAA,G,S,T)           'Hydro run on river can not be dispatched'
$ifi %BB4%==yes   QWNDDISP(Y,AAA,G,S,T)            'wind power can not be dispatched'
$ifi %BB4%==yes   QSOLEDISP(Y,AAA,G,S,T)           'solE can not be dispatched'
$ifi %BB4%==yes   QSOLHDISP(Y,AAA,G,S,T)           'solH can not be dispatched'
$ifi %BB4%==yes   QXKN(Y,IRRRE,IRRRI,SIMYEARS)      'new transmission investment'
$ifi %BB4%==yes   QVGKNINT(AAA, G, Y, SIMYEARS)     ''
$ifi %BB4%==yes   QVXKNINT(IRRRE,IRRRI,Y, SIMYEARS) ''
*/
$label label_Notdisplaylistformat
*-------------------------------------------------------------------------------
*-------------------------------------------------------------------------------
$ifi %CREATETIME%==yes $INCLUDE '../../base/model/createtime.inc';
$ifi %CREATETIME%==yes $goto ENDOFMODEL
* Here the model to be solved/simulated is included:

$ifi %bb1%==yes
$if EXIST 'bb123.sim' $INCLUDE 'bb123.sim';
$ifi %bb1%==yes
$if not EXIST 'bb123.sim' $INCLUDE '../../base/model/bb123.sim';

$ifi %bb2%==yes
$if EXIST 'bb123.sim' $INCLUDE 'bb123.sim';
$ifi %bb2%==yes
$if not EXIST 'bb123.sim' $INCLUDE '../../base/model/bb123.sim';

$ifi %bb3%==yes
$if EXIST 'bb123.sim' $INCLUDE 'bb123.sim';
$ifi %bb3%==yes
$if not EXIST 'bb123.sim' $INCLUDE '../../base/model/bb123.sim';


$ifi %bb4%==yes $INCLUDE '../../base/addons/BB4/BB4overview.inc';
$ifi %bb4%==yes $if EXIST 'bb4.sim' $INCLUDE 'bb4.sim';
$ifi %bb4%==yes $if not EXIST 'bb4.sim' $INCLUDE '../../base/model/bb4.sim';



*--- Results which can be transfered between simulations are placed here: ------
$ifi %bb1%==yes execute_unload  '../../base/data/HYFXRW.gdx',HYFXRW;
$ifi %bb1%==yes execute_unload  '../../base/data/WATERVAL.gdx',WATERVAL;
$ifi %bb2%==yes execute_unload  '../../base/data/HYFXRW.gdx',HYFXRW;
$ifi %bb2%==yes execute_unload  '../../base/data/WATERVAL.gdx',WATERVAL;


$ifi %MAKEINVEST%==yes execute_unload '../../base/data/GKVACC.gdx', GKVACC;
$ifi %MAKEINVEST%==yes execute_unload '../../base/data/GKVACCDECOM.gdx', GKVACCDECOM;
$ifi %MAKEINVEST%==yes execute_unload '../../base/data/GVKGN.gdx', GVKGN;
$ifi %MAKEINVEST%==yes execute_unload '../../base/data/XKACC.gdx', XKACC;


$ifi %H2%==yes execute_unload '../../base/addons/Hydrogen/H2STOVOL_START.gdx',H2STOVOL_START;
$ifi %GAS%==yes $INCLUDE '../../base/addons/gas/gasgdx.inc';
$ifi %X3V%==yes $INCLUDE '../../base/addons/x3v/model/x3vgdx.inc';
*--- End: Results which can be transfered between simulations are placed here --


*--- Results collection and comparison -----------------------------------------
* Merge simulation years:
$ifi %MERGESAVEPOINTRESULTS%==yes  execute "gdxmerge %relpathModel%..\output\temp\*.gdx";

* Rename merged.gdx to case identification.
* LARS20080916: Currently no facility for merging cases, however the final GDX and MDB are made
* as though this were an option.
*$ifi %GDXMERGESIMYEARS%==yes  execute "move merged.gdx %relpathGDXsimyears%%CASEID%.gdx";
$ifi %MERGESAVEPOINTRESULTS%==yes  execute "move merged.gdx %CASEID%.gdx";
$ifi %MERGESAVEPOINTRESULTS%==yes  execute "gdxmerge %CASEID%.gdx";
$ifi %MERGESAVEPOINTRESULTS%==yes  execute "move merged.gdx %relpathoutput%%CASEID%-Results.gdx";
$ifi %MERGESAVEPOINTRESULTS%==yes  execute "move %CASEID%.gdx %relpathoutput%%CASEID%.gdx";
$ifi %MERGEDSAVEPOINTRESULTS2MDB%==yes execute '=gdx2access %relpathoutput%%CASEID%-Results.gdx';


$ifi %comparewithbase%==yes   putclose  fileCOMPAREWITHBASEbat 'move  ' '%relpathModel%''..\..\output\BASE.gdx '  '%relpathoutput%BASE.gdx';

* Make an MS Access database from comparison results file.
* Irrelevant $ifi %MAKEACCESS%==yes execute '=gdx2access %CASEID%-COMPARE.gdx';
*--- End: Results collection and comparison ------------------------------------
$ifi %INPUTDATA2GDX%==yes execute 'move "%relpathModel%..\output\temp\1INPUT.gdx" "%relpathInputdata2GDX%INPUTDATAOUT.gdx"';
* Transfer inputdata a seperate Access file:
$ifi %INPUTDATAGDX2MDB%==yes execute "=GDX2ACCESS %relpathInputdata2GDX%INPUTDATAOUT.gdx";
* Transfer to Excel, read the identifiers to be transferred from file inputdatagdx2xls.txt:
* Note: presently not working (the relevant data is not set i file inputdatagdx2xls.txt):
* NOTWORKING (i.e. you MUST have '$setglobal INPUTDATAGDX2XLS'): Note:  GAMS version 22.7 and later have better support for this....
$ifi %INPUTDATAGDX2XLS%==yes  execute  "GDXXRW.EXE Input=%relpathInputdata2GDX%INPUTDATAOUT.gdx  Output=%relpathInputdata2GDX%INPUTDATAOUT.xls  @%relpathModel%inputdatagdx2xls.txt";



*----- End of model:------------------------------------------------------------
$label ENDOFMODEL
*----- End of model ------------------------------------------------------------



