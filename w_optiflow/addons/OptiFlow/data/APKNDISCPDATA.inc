PARAMETER APKNDISCPDATA(PROC,APKNDISCPSIZESET,APKNDISCPDATASET) "Investment data for discrete Process capacity size investments (addon apkndisc)"
* Note that the units are (U/h) and (MMoney), not (U/h) and (MMoney/[U/h]).
*                                                      !! Not implemented    Not implemented
                         APNDISCSIZE  APKNDISCINVCOST  !! APKNDISCOMFCOST    APKNDISCOMVCOST
* Unit::                      (U/h)   (MMoney)         !!  (kMoney/[U/h])       (Money/U)




APKNDISCPSIZE_10
APKNDISCPSIZE_30
APKNDISCPSIZE_100
APKNDISCPSIZE_300
APKNDISCPSIZE_1000
APKNDISCPSIZE_3000

* Special for test
APKNDISCPSIZE_1201        1201            -66055
APKNDISCPSIZE_3603        3603           -198165




/*
With present data I get the following new investments WITHOUT discrete size investments addon APKNdisc:
----  93552 VARIABLE VPROCKAPNEW.L  New capacity (/h)
                    WasteincinCHP_35   BiogasCHP   Boiler-WO    Engine-NG
2010.DK_CA_KBH          3601.640        137.233     423.781     423.781
I therefore think that interesting values for testing with discrete size investments APKNdisc are:
  on WasteincinCHP_35: 1201 (should imply 3 units if chosen), 3603 (should imply 1 unit if chosen):
      let APKNDISCAP contain only (DK_FYN_Odense.WasteincinCHP_35)
      let APKNDISCPDATA be given appropriate data to make the solution switch between the two sizes
*/

/*
The investmentcost for WasteincinCHP_35 is given in PROCDATA as 55
For the relevats capacities we find
  APNDISCSIZE  APKNDISCINVCOST
       1201         66055
       3603        198165
Values that are similar, but not necessaryly identical to this are entered in the table above.
*/
