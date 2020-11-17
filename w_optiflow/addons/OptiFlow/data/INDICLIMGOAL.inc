PARAMETER INDICLIMGOAL(FLOWINDIC,iINDICLIMGOALSET) "Limits, desirable quantities and weight of Indics"
/
*Weight of -1  must be applied for GHG and +1 for costs to get it right (the non used INDIC is then given a weight of 0)


OPERATIONCOST         . INDICWEIGHT   1
GHGEMISSION_nonbio    . INDICWEIGHT   0
GHGEMISSION_bio       . INDICWEIGHT   0

*----------------------------------------------------------------------------------------------------------------------------------------------------
* Remaining part of file is preliminary, but sketching the ideas.

** TIL VISSE DEBUG HAR JEG  REDUCERET, SÅ ** UDGÅR
**Landoccupation    . INDICMIN      -INF
**Landoccupation    . INDICMAX     10000
**Landoccupation    . INDICGOAL     5000
**Landoccupation    . INDICWEIGHT    0.5

**CADMIUM           . INDICMIN      -INF
**CADMIUM           . INDICMAX     10000
**CADMIUM           . INDICGOAL     5000
**CADMIUM           . INDICWEIGHT    0.5

**TOTALCOSTINCOME   . INDICMIN      -INF
**TOTALCOSTINCOME   . INDICMAX     10000
**TOTALCOSTINCOME   . INDICGOAL     5000
**TOTALCOSTINCOME   . INDICWEIGHT    0.5

**CO2                 . INDICMIN     -INF
**CO2                 . INDICMAX     999
**CO2                 . INDICGOAL    0
**CO2                 . INDICWEIGHT  1.3

/;
