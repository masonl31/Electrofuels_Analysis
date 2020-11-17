Parameter WNDFLH_Original(AAA);
$if     EXIST '../data/WNDFLH_Original.inc' $INCLUDE      '../data/WNDFLH_Original.inc';
$if not EXIST '../data/WNDFLH_Original.inc' $INCLUDE '../../base/data/WNDFLH_Original.inc';


Parameter WNDFLH_Scenarios(scenarios,AAA) 'Change of the parameters value in the different scenarios';
WNDFLH_Scenarios('Scenario_1',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=1.05*WNDFLH_Original(IA);
WNDFLH_Scenarios('Scenario_2',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=1.1*WNDFLH_Original(IA);
WNDFLH_Scenarios('Scenario_3',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=0.95*WNDFLH_Original(IA);
WNDFLH_Scenarios('Scenario_4',IA)$(SUM(IGWND,IAGK_Y(IA,IGWND)+IAGKN(IA,IGWND)) AND ICA('DENMARK',IA))=0.90*WNDFLH_Original(IA);

Parameter IDE_T_Y_scen(scenarios,RRR,SSS,TTT);
IDE_T_Y_scen('scenario_1','DK_E','S04','T059')=1600;
IDE_T_Y_scen('scenario_2','DK_E','S04','T060')=1600;
IDE_T_Y_scen('scenario_3','DK_E','S04','T061')=1600;
IDE_T_Y_scen('scenario_4','DK_E','S04','T062')=1600;