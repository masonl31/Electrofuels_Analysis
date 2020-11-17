
PARAMETER SOSIBUFLOW_VAR_T(AAA,PROC,FLOW,SSS,TTT) "Variation in some Source, Sink or Buffer Flows over the year"
/

/;


* Urban areas in Western Denmark use the DK_CA_Aarhus profile.


*WASTE GENERATION: data  in SOSIBUBOUND indicate that the value is on ton/h, therefore make a flat profile:

*SOSIBUFLOW_VAR_T(IA,'HouseHoldWasteGen','RESIDUALWASTEHH',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'IndustrialWasteGen','INDUSTRY_MIXEDWASTE',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T('UK_AAA','Imported_RDF','IMPORTEDRDFFLOW',S,T)=1;



SOSIBUFLOW_VAR_T(IA,'WOOD_GEN','WOOD_GEN_FLOW',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
SOSIBUFLOW_VAR_T(IA,'STRAW_GEN','STRAW_GEN_FLOW',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
SOSIBUFLOW_VAR_T(IA,'WOOD_PELLETS_GEN','WOOD_PELLETS_GEN_FLOW',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
SOSIBUFLOW_VAR_T(IA,'MUNI_WASTE_GEN','MUNI_WASTE_GEN_FLOW',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
SOSIBUFLOW_VAR_T(IA,'MANURE_AND_WETBIO_GEN','MANURE_AND_WETBIO_GEN_FLOW',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;




*SOSIBUFLOW_VAR_T(IA,'WOOD','WOOD_GJ_SNG',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'WOOD','WOOD_GJ_SYNGAS',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;



*SOSIBUFLOW_VAR_T(IA,'STRAW','STRAW_GJ_SNG',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'STRAW','STRAW_GJ_SYNGAS',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
**SOSIBUFLOW_VAR_T(IA,'STRAW','STRAW_GJ_BIOGAS',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;


*SOSIBUFLOW_VAR_T(IA,'WOOD_PELLETS','WOOD_PELLETS_GJ_SNG',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'WOOD_PELLETS','WOOD_PELLETS_GJ_SYNGAS',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;


*SOSIBUFLOW_VAR_T(IA,'MUNI_WASTE','MUNI_WASTE_GJ_SNG',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'MUNI_WASTE','MUNI_WASTE_GJ_SYNGAS',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;



*SOSIBUFLOW_VAR_T(IA,'MANURE_AND_WETBIO','MANURE_AND_WETBIO_GJ_BG_Single',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'MANURE_AND_WETBIO','MANURE_AND_WETBIO_GJ_BG_Mix',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;
*SOSIBUFLOW_VAR_T(IA,'MIX_FUEL','MIX_FUEL_GJ',S,T)$(AAAOPTIFLOW(IA) AND (not AAATRANSIT(IA))) = 1;











