
PARAMETER SOSIBU2INDIC_AST(AAA,PROC,FLOW,FLOWINDIC,SSS,TTT) "Coefficients for transformation of VSOURCE, VSINK and VBUFFER flows to FLOWINDIC values"
/
*DK_CA_Aab  .HeatBuffer .HEATFLOW . OPERATIONCOST       . S01.T001  15      !! dummy values

/;
*SOSIBU2INDIC_AST(IA,PROC,FLOW,FLOWINDIC,S,T) =  SOSIBU2INDIC_AST(IA,PROC,FLOW,FLOWINDIC,'S01','T001') * ( 3 + COS((ORD(T)-1)*2*PI /CARD(T)));  !! JUST TO ILLUSTRATE A VARIATION