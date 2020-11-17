SET APKNDISCSIZESET     "Set of possible sizes for discrete capacity investments in Processes (addon apkndisc) ()"
/



APKNDISCPSIZE_10       "Size 10 (U/h)"
APKNDISCPSIZE_30       "Size 30 (U/h)"
APKNDISCPSIZE_100      "Size 100 (U/h)"
APKNDISCPSIZE_300      "Size 300 (U/h)"
APKNDISCPSIZE_1000     "Size 1000 (U/h)"
APKNDISCPSIZE_3000     "Size 3000 (U/h)"
* Add more if needed; also possible to give more informative names.

APKNDISCPSIZE_1201     "Size 1201 (U/h)"
APKNDISCPSIZE_3603     "Size 3603 (U/h)"



/;


/*


$ontext

With present data I get the following new investments WITHOUT discrete size investments addon APKNdisc:
----  93552 VARIABLE VPROCKAPNEW.L  New capacity (/h)
                    WasteincinCHP_35   BiogasCHP   Boiler-WO
2010.DK_CA_KBH          3601.640        137.233     423.781
I therefore think that interesting values for testing with discrete size investments APKNdisc are:
  on WasteincinCHP_35: 1201 (should imply 3 units if chosen), 3603 (should imply 1 unit if chosen):
      let APKNDISCAP contain only (DK_FYN_Odense.WasteincinCHP_35)
      let APKNDISCPDATA be given appropriate data to make the solution switch between the two sizes

$ontext

*/
