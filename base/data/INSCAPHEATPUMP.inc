PARAMETER INSCAPHEATPUMP(YYY,AAA) 'Maximum installed capacity of heat pumps (MW)';



INSCAPHEATPUMP(YYY,'DK_CA_KBH')=(smax((S,T),((DH(YYY,'DK_CA_KBH')*DH_VAR_T('DK_CA_KBH',S,T))/IDH_SUMST('DK_CA_KBH'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Aarhus')=(smax((S,T),((DH(YYY,'DK_CA_Aarhus')*DH_VAR_T('DK_CA_Aarhus',S,T))/IDH_SUMST('DK_CA_Aarhus'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Odense')=(smax((S,T),((DH(YYY,'DK_CA_Odense')*DH_VAR_T('DK_CA_Odense',S,T))/IDH_SUMST('DK_CA_Odense'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Aal')=(smax((S,T),((DH(YYY,'DK_CA_Aal')*DH_VAR_T('DK_CA_Aal',S,T))/IDH_SUMST('DK_CA_Aal'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_TVIS')=(smax((S,T),((DH(YYY,'DK_CA_TVIS')*DH_VAR_T('DK_CA_TVIS',S,T))/IDH_SUMST('DK_CA_TVIS'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Esb')=(smax((S,T),((DH(YYY,'DK_CA_Esb')*DH_VAR_T('DK_CA_Esb',S,T))/IDH_SUMST('DK_CA_Esb'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Hern')=(smax((S,T),((DH(YYY,'DK_CA_Hern')*DH_VAR_T('DK_CA_Hern',S,T))/IDH_SUMST('DK_CA_Hern'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Kal')=(smax((S,T),((DH(YYY,'DK_CA_Kal')*DH_VAR_T('DK_CA_Kal',S,T))/IDH_SUMST('DK_CA_Kal'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_NrdOstSj')=(smax((S,T),((DH(YYY,'DK_MA_NrdOstSj')*DH_VAR_T('DK_MA_NrdOstSj',S,T))/IDH_SUMST('DK_MA_NrdOstSj'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_CA_Randers')=(smax((S,T),((DH(YYY,'DK_CA_Randers')*DH_VAR_T('DK_CA_Randers',S,T))/IDH_SUMST('DK_CA_Randers'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Holst')=(smax((S,T),((DH(YYY,'DK_MA_Holst')*DH_VAR_T('DK_MA_Holst',S,T))/IDH_SUMST('DK_MA_Holst'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Silk')=(smax((S,T),((DH(YYY,'DK_MA_Silk')*DH_VAR_T('DK_MA_Silk',S,T))/IDH_SUMST('DK_MA_Silk'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Hil')=(smax((S,T),((DH(YYY,'DK_MA_Hil')*DH_VAR_T('DK_MA_Hil',S,T))/IDH_SUMST('DK_MA_Hil'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Hjoerring')=(smax((S,T),((DH(YYY,'DK_MA_Hjoerring')*DH_VAR_T('DK_MA_Hjoerring',S,T))/IDH_SUMST('DK_MA_Hjoerring'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Sndborg')=(smax((S,T),((DH(YYY,'DK_MA_Sndborg')*DH_VAR_T('DK_MA_Sndborg',S,T))/IDH_SUMST('DK_MA_Sndborg'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Viborg')=(smax((S,T),((DH(YYY,'DK_MA_Viborg')*DH_VAR_T('DK_MA_Viborg',S,T))/IDH_SUMST('DK_MA_Viborg'))))*0.1;
INSCAPHEATPUMP(YYY,'DK_MA_Horsens')=(smax((S,T),((DH(YYY,'DK_MA_Horsens')*DH_VAR_T('DK_MA_Horsens',S,T))/IDH_SUMST('DK_MA_Horsens'))))*0.1;

 