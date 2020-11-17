Parameter BOUND_SCEN_WND_T(scenarios,AAA,GGG,SSS,TTT) 'Bound of parameters for wind turbines';
BOUND_SCEN_WND_T(scenarios,IA,IGWND,S,T)$IAGK_Y(IA,IGWND)=((WNDFLH_Scenarios(scenarios,IA) * (IGKVACCTOY(IA,IGWND) + IGKFX_Y(IA,IGWND))   * WND_VAR_T(IA,S,T)) / IWND_SUMST(IA))$IWND_SUMST(IA);

