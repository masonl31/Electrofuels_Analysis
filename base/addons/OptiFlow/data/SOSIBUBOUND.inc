!! NOTE: OVERLOADED AS SOSIBU, SOSIBU_AST and SOSIBU_RST ?
* Rules probably should be:
*   for any index combination at most one element in has values.
*   If there is a SOSIBUFLOW_VAR_T/SOSIBUBOUND_VAR_T then SOSIBUBOUND
*   (and only that, not _AST or _RST) has value for the corresponding index combination.
*   Code in the .gms file will then combine all to aone or a few ...

!! TODO: RECONSIERE: MAYBE THIS IS ONLY FOR SOURCE (E.G. ANNUAL VALUES OF WASTE GENERATED)  - IN THIS CASE, CAHNGE NAME
*It would be conveniant to have this parameter as a function of the year
* Convention for entering data:
*   Enter at most one data item for each PROC,
*   If nothing or 0 is entered then the default values corresponding to the declaration of the variable (positive, negative or free) apply.
*   If EPS is entered then the corresponding value will be zero (CHECK IT).
* The unit for the data may differ between (PROC,FLOW).

*Unit: Flow Units/year (as defined the model 17th June 2015)

                                                                                                         ILOUPFX_FX      ILOUPFX_LO      ILOUPFX_UP
2050    .       DK_CA_Aab       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       80667
2050    .       DK_CA_Aal       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       103004
2050    .       DK_CA_Aarhus    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       108638
2050    .       DK_CA_Esb       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       373308
2050    .       DK_CA_Hern      .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       243591
2050    .       DK_CA_Kal       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       47857
2050    .       DK_CA_KBH       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       31617
2050    .       DK_CA_Odense    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       134157
2050    .       DK_CA_Randers   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       32346
2050    .       DK_CA_Roenne    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       35660
2050    .       DK_CA_TVIS      .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_CA_Vestfrb   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_E_DTU        .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_MA_Grenaa    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       36854
2050    .       DK_MA_Hil       .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       9744
2050    .       DK_MA_Hjoerring .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       137803
2050    .       DK_MA_Holst     .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       182677
2050    .       DK_MA_Horsens   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       64693
2050    .       DK_MA_NrdOstSj  .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_MA_Silk      .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       37914
2050    .       DK_MA_Sndborg   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       153578
2050    .       DK_MA_Viborg    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       97304
2050    .       DK_MAM_Aars     .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       74370
2050    .       DK_MAM_Frdhavn  .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       32413
2050    .       DK_MAM_Had      .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       61246
2050    .       DK_MAM_Hammel   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_MAM_Hobro    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       101215
2050    .       DK_MAM_Naestved .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       29364
2050    .       DK_MAM_NrAlslev .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_MAM_Nyborg   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       16637
2050    .       DK_MAM_Nyk      .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       47857
2050    .       DK_MAM_Skagen   .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       EPS
2050    .       DK_MAM_Slagelse .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       26116
2050    .       DK_MAM_Svend    .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       30689
2050    .       DK_MAM_Thisted  .       MANURE_AND_WETBIO_GEN   .       MANURE_AND_WETBIO_GEN_FLOW       109699






2050    .       DK_CA_Aab       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      6183
2050    .       DK_CA_Aal       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      17744
2050    .       DK_CA_Aarhus    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      28478
2050    .       DK_CA_Esb       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      10702
2050    .       DK_CA_Hern      .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      11733
2050    .       DK_CA_Kal       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      14190
2050    .       DK_CA_KBH       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      93728
2050    .       DK_CA_Odense    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      24056
2050    .       DK_CA_Randers   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      6118
2050    .       DK_CA_Roenne    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      2558
2050    .       DK_CA_TVIS      .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      20255
2050    .       DK_CA_Vestfrb   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      7307
2050    .       DK_E_DTU        .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      3497
2050    .       DK_MA_Grenaa    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      2406
2050    .       DK_MA_Hil       .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      11603
2050    .       DK_MA_Hjoerring .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4163
2050    .       DK_MA_Holst     .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      9348
2050    .       DK_MA_Horsens   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      8355
2050    .       DK_MA_NrdOstSj  .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      7966
2050    .       DK_MA_Silk      .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      5689
2050    .       DK_MA_Sndborg   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4795
2050    .       DK_MA_Viborg    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      6000
2050    .       DK_MAM_Aars     .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      2387
2050    .       DK_MAM_Frdhavn  .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      3965
2050    .       DK_MAM_Had      .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      3563
2050    .       DK_MAM_Hammel   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      3001
2050    .       DK_MAM_Hobro    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4516
2050    .       DK_MAM_Naestved .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      10282
2050    .       DK_MAM_NrAlslev .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      EPS
2050    .       DK_MAM_Nyborg   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      1995
2050    .       DK_MAM_Nyk      .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      6636
2050    .       DK_MAM_Skagen   .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      EPS
2050    .       DK_MAM_Slagelse .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4876
2050    .       DK_MAM_Svend    .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4890
2050    .       DK_MAM_Thisted  .       MUNI_WASTE_GEN  .       MUNI_WASTE_GEN_FLOW                      4153






;







































































































































































































































