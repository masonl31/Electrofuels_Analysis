Parameter BOUND_SCEN_IGKE_T(scenarios,AAA,GGG,SSS,TTT) 'Generation of existing plants is restricted by the electrical capacity';
BOUND_SCEN_IGKE_T(scenarios,IA,IGKE,S,T)$IAGK_Y(IA,IGKE)=(IGKVACCTOY(IA,IGKE) + IGKFX_Y_Scenario(scenarios,IA,IGKE))*(IGKRATE(IA,IGKE,S,T));

Parameter BOUND_SCEN_IGKH_T(scenarios,AAA,GGG,SSS,TTT) 'Generation of existing plants is restricted by the heat capacity';
BOUND_SCEN_IGKH_T(scenarios,IA,IGKH,S,T)$IAGK_Y(IA,IGKH)=(IGKVACCTOY(IA,IGKH) + IGKFX_Y_Scenario(scenarios,IA,IGKH))*(IGKRATE(IA,IGKH,S,T));

