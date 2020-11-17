!! TODO: OVERLOADED AS SOSIBU2INDIC, SOSIBU2INDIC_AST and SOSIBU2INDIC_RST ?

* todo: should use an annual value plus a profile to over the year, rather tahn this - this will be in next version :)
*


TABLE SOSIBUBOUND_AST(AAA,PROC,FLOW,SSS,TTT,iLOUPFXSET) "Bounds on Source, Sink and Buffer Process Flows - (S,T) values"
* Convention for entering data:
*   Enter at most one data item for each PROC,
*   If nothing or 0 is entered then the default values corresponding to the declaration of the variable (positive, negative or free) apply.
*   If EPS is entered then the corresponding value will be zero.
* The unit for the data may differ between PROC.

                                                    !! I think I reget this - not is use this moment
                                                            iLOUPFX_LO  iLOUPFX_UP   iLOUPFX_FX
*DK_CA_Aab .HouseHoldWasteGen .RESIDUALWASTEHH .S01 .T001                                                !! 1         !! if a flat profile for the year, just make sure that reasonal value is such that their sum equals the annual value
*DK_CA_Aab .ManureCows        .MANURE          .S01 .T001                                                !!  2



;

* The easy way:
SOSIBUBOUND_AST(AAA,PROC,FLOW,SSS,TTT,iLOUPFXSET) = SOSIBUBOUND_AST(AAA,PROC,FLOW,'S01','T001',iLOUPFXSET);


SOSIBUBOUND_AST('UK_AAA',PROC,FLOW,SSS,TTT,iLOUPFXSET) = NO;





      /*   revideres efter indførelse af index AAA, FLOW OG SSS, men virkede før det.
* Test: only Source, Sink and Buffer Processes can be entered:
LOOP(IPROCINTERIOR$SUM(iLOUPFXSET, ABS(SOSIBUBOUND(IPROCINTERIOR,iLOUPFXSET)) GT 0),
   DISPLAY "Error: in SOSIBUBOUND - values should be entered only for Source, Sink of Buffer Processes.";
);
* Test: enter at most one data item for each PROC:
LOOP(PROC$(NOT IPROCINTERIOR(PROC)),
  IF((SUM(iLOUPFXSET$SOSIBUBOUND(PROC,iLOUPFXSET),1) GT 1),
    DISPLAY "Error: in SOSIBUBOUND - at most one data item should be entered for each PROC.";
  );
);   */

