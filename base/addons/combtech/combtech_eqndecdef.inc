* Equation declarations and definitions used in addon combtech

*todo: cHECK, AT DEFAULT 1 OGS� ANVENDES ANDRE STEDER END I GDCOMBGUP  !
* QECOMBGSHARELO og evt. andre:    !! To sidste: er vel overfl�digt med chekc p� b�de comb1 og comb2, tech-erne skal v�re samme techtype, se ogs� error2    TODO
* TODO: See QNECOMBGUP og the 'simplified' always-use version for existing tech. Which to use?  The eqn may sometimes be superfluous (if sum of shares <=1) but requires more elaborate coding due to default '0 means irrelevant'



EQUATIONS
   QCOMBFUP(AAA,G,S,T)            "Existing combtech, sum of fuel (GJ/s) use any (S,T) limited by rated capacity (MW) on primal (0 means irrelevant) ({eps,(0;1]})" !! UNIT hvad skriver vi her??  p.t. GJ/s

   QECOMBGUP(AAA,G,S,T)           "Existing combtech, sum of production (MW) any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
   QECOMBGSHARELO(AAA,G,S,T)      "Existing combtech in IGKE, minimum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QECOMBGSHAREUP(AAA,G,S,T)      "Existing combtech in IGKE, maximum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QECOMBFSHARELO(AAA,G,S,T)      "Existing combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QECOMBFSHAREUP(AAA,G,S,T)      "Existing combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"

   QHCOMBGUP(AAA,G,S,T)           "Existing combtech, sum of production any (S,T) limited by rated capacity on primal, (0 means irrelevant) heat (MW)"
   QHCOMBGSHARELO(AAA,G,S,T)      "Existing combtech in IGKE, minimum share any (S,T) of total generation for this combtech group, heat (0 means irrelevant) ([0;1])"
   QHCOMBGSHAREUP(AAA,G,S,T)      "Existing combtech in IGKE, maximum share any (S,T) of total generation for this combtech group, heat (0 means irrelevant) ([0;1])"
   QHCOMBFSHARELO(AAA,G,S,T)      "Existing combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, heat (0 means irrelevant) ([0;1])"
   QHCOMBFSHAREUP(AAA,G,S,T)      "Existing combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, heat (0 means irrelevant) ([0;1])"


   QNCOMBFUP(AAA,G,S,T)           "New combtech, sum of fuel (GJ) use any (S,T) limited by rated capacity (MW) on primal (0 means irrelevant) (GJ)"

   QNECOMBGUP(AAA,G,S,T)          "New combtech, sum of production any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
   QNECOMBGSHAREK11(AAA,G,S,T)    "New primal combtech, production any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
   QNECOMBGSHAREK12(AAA,G,G,S,T)  "New secondary combtech, production any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
   QNECOMBGSHARELO(AAA,G,S,T)     "New combtech in IGKE, minimum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QNECOMBGSHAREUP(AAA,G,S,T)     "New combtech in IGKE, maximum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QNECOMBFSHARELO(AAA,G,S,T)     "New combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
   QNECOMBFSHAREUP(AAA,G,S,T)     "New combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"

   QNHCOMBGUP(AAA,G,S,T)          "New combtech, sum of production any (S,T) limited by rated capacity on primal, heat (0 means irrelevant) (MW)"
   QNHCOMBGSHAREK11(AAA,G,S,T)    "New primal combtech, production any (S,T) limited by rated capacity on primal, heat (0 means irrelevant) (MW)"
   QNHCOMBGSHAREK12(AAA,G,G,S,T)  "New secondary combtech, production any (S,T) limited by rated capacity on primal, heat (0 means irrelevant) (MW)"
   QNHCOMBGSHARELO(AAA,G,S,T)     "New combtech in IGKH, minimum share any (S,T) of total generation for this combtech group, heat (0 means irrelevant) ([0;1])"
   QNHCOMBGSHAREUP(AAA,G,S,T)     "New combtech in IGKH, maximum share any (S,T) of total generation for this combtech group, heat (0 means irrelevant) ([0;1])"
   QNHCOMBFSHARELO(AAA,G,S,T)     "New combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, heat (0 means irrelevant) ([0;1])"
   QNHCOMBFSHAREUP(AAA,G,S,T)     "New combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, heat (0 means irrelevant) ([0;1])"
;




* Existing capacity:  ----------------------------------------------------------

* Existing combtech, sum of fuel (GJ/s) use any (S,T) limited by rated capacity (MW) on primal (0 means irrelevant) ({eps,(0;1]})
QCOMBFUP(IA,IGCOMB1,IS3,T)$(IAGK_Y(IA,IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBFUP'))..
  (IGKVACCTOY(IA,IGCOMB1) + IGKFX_Y(IA,IGCOMB1)) * (1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * GDATA(IGCOMB1,'GDCOMBFUP')
          =G=
  (VGF_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T))) * IOF3P6;

* Bounds on individual units are assigned individually to .UP, however, the sum-of-bounds may exceed 1
QECOMBGUP(IA,IGCOMB1,IS3,T)$(IAGK_Y(IA,IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGUP') AND IGKE(IGCOMB1))..
  (IGKVACCTOY(IA,IGCOMB1) + IGKFX_Y(IA,IGCOMB1)) * (1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * (GDATA(IGCOMB1,'GDCOMBGUP')$GDATA(IGCOMB1,'GDCOMBGUP')+1$(NOT GDATA(IGCOMB1,'GDCOMBGUP')))
          =G=
  VGE_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGE_T(IA,IGCOMB2,IS3,T));


* Existing combtech in IGKE, any combtech minimum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])
QECOMBGSHARELO(IA,IGKE,IS3,T)$(IAGK_Y(IA,IGKE) AND GDATA(IGKE,'GDCOMBGSHARELO') AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)))..
  VGE_T(IA,IGKE,IS3,T) =G= GDATA(IGKE,'GDCOMBGSHARELO')*(
      (SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGE_T(IA,IGCOMB2,IS3,T)) + VGE_T(IA,IGKE,IS3,T))$IGCOMB1(IGKE)
    + (SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGE_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGE_T(IA,IGCOMB2,IS3,T))))$IGCOMB2(IGKE));


* Existing combtech in IGKE, maximum share any (S,T) of total generation for this combtech group, electricity (0 means irrelevant) ([0;1])
QECOMBGSHAREUP(IA,IGKE,IS3,T)$(IAGK_Y(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBGSHAREUP'))..
  GDATA(IGKE,'GDCOMBGSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGE_T(IA,IGCOMB2,IS3,T)) + VGE_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGE_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGE_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)
  )
         =G=
  VGE_T(IA,IGKE,IS3,T);


* Existing combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])
QECOMBFSHARELO(IA,IGKE,IS3,T)$(IAGK_Y(IA,IGKE) AND GDATA(IGKE,'GDCOMBFSHARELO') AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)))..
  VGF_T(IA,IGKE,IS3,T) =G=
  GDATA(IGKE,'GDCOMBFSHARELO')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T)) + VGF_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGF_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)     !! HOV:
  );


* Existing combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])
QECOMBFSHAREUP(IA,IGKE,IS3,T)$(IAGK_Y(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBFSHAREUP'))..
  GDATA(IGKE,'GDCOMBFSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T)) + VGF_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGF_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)
  )
         =G=
  VGF_T(IA,IGKE,IS3,T);



* Bounds on individual units are assigned individually to .UP, however, the sum-of-bounds may exceed 1
QHCOMBGUP(IA,IGCOMB1,IS3,T)$(IAGK_Y(IA,IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGUP') AND IGKH(IGCOMB1))..
  (IGKVACCTOY(IA,IGCOMB1) + IGKFX_Y(IA,IGCOMB1))*(1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * (GDATA(IGCOMB1,'GDCOMBGUP')$GDATA(IGCOMB1,'GDCOMBGUP')+1$(NOT GDATA(IGCOMB1,'GDCOMBGUP')))
        =G=
  VGH_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGH_T(IA,IGCOMB2,IS3,T))
;


QHCOMBGSHARELO(IA,IGKH,IS3,T)$(IAGK_Y(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBGSHARELO'))..
  VGH_T(IA,IGKH,IS3,T)  =G=  GDATA(IGKH,'GDCOMBGSHARELO')*
  (
    ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGH_T(IA,IGCOMB2,IS3,T)) + VGH_T(IA,IGKH,IS3,T))$IGCOMB1(IGKH)
  + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGH_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGH_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  )
;


QHCOMBGSHAREUP(IA,IGKH,IS3,T)$(IAGK_Y(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBGSHAREUP'))..
  GDATA(IGKH,'GDCOMBGSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGH_T(IA,IGCOMB2,IS3,T)) + VGH_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGH_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGH_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  )
         =G=
  VGH_T(IA,IGKH,IS3,T)
;



* Existing combtech in IGKH, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])
QHCOMBFSHARELO(IA,IGKH,IS3,T)$(IAGK_Y(IA,IGKH) AND GDATA(IGKH,'GDCOMBFSHARELO') AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)))..
  VGF_T(IA,IGKH,IS3,T) =G=
  GDATA(IGKH,'GDCOMBFSHARELO')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T)) + VGF_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGF_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)     !! HOV:
  );


* Existing combtech in IGKH, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])
QHCOMBFSHAREUP(IA,IGKH,IS3,T)$(IAGK_Y(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBFSHAREUP'))..
  GDATA(IGKH,'GDCOMBFSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T)) + VGF_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGF_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGF_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  )
         =G=
  VGF_T(IA,IGKH,IS3,T);



* New capacity: ----------------------------------------------------------------

* New combtech, sum of fuel (GJ) use any (S,T) limited by rated capacity (MW) on primal (GJ)

* "New combtech, sum of fuel (GJ) use any (S,T) limited by rated capacity (MW) on primal (0 means irrelevant) (GJ)"
QNCOMBFUP(IA,IGCOMB1,IS3,T)$(IAGKN(IA,IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBFUP'))..
  VGKN(IA,IGCOMB1)*(1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * (GDATA(IGCOMB1,'GDCOMBFUP')$GDATA(IGCOMB1,'GDCOMBFUP')+1$(NOT GDATA(IGCOMB1,'GDCOMBFUP'))) * GDATA(IGCOMB1,'GDCOMBFUP')
          =G=
  (VGFN_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T))) * IOF3P6;


* Bounds on individual units are handled individually in QNECOMBGSHAREK11 and QNECOMBGSHAREK12, however, the sum-of-bounds may exceed 1
QNECOMBGUP(IA,IGCOMB1,IS3,T)$(IAGKN(IA,IGCOMB1) AND IGKE(IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGUP'))..
  VGKN(IA,IGCOMB1)*(1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * (GDATA(IGCOMB1,'GDCOMBGUP')$GDATA(IGCOMB1,'GDCOMBGUP')+1$(NOT GDATA(IGCOMB1,'GDCOMBGUP')))
         =G=
  VGEN_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGEN_T(IA,IGCOMB2,IS3,T))
;

* "New primal combtech, production any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
QNECOMBGSHAREK11(IA,IGCOMB1,IS3,T)$(IAGKN(IA,IGCOMB1) AND IGKE(IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGSHAREK1'))..
    VGEN_T(IA,IGCOMB1,IS3,T) =L= VGKN(IA,IGCOMB1) * GDATA(IGCOMB1,'GDCOMBGSHAREK1');


* "New secondary combtech, production any (S,T) limited by rated capacity on primal, electricity (0 means irrelevant) (MW)"
QNECOMBGSHAREK12(IA,IGCOMB1,IGCOMB2,IS3,T)$(IAGKN(IA,IGCOMB2) AND IGKE(IGCOMB2) AND GGCOMB(IGCOMB1,IGCOMB2) AND GDATA(IGCOMB2,'GDCOMBGSHAREK1'))..
    VGEN_T(IA,IGCOMB2,IS3,T) =L= VGKN(IA,IGCOMB1) * GDATA(IGCOMB2,'GDCOMBGSHAREK1');


QNECOMBGSHAREUP(IA,IGKE,IS3,T)$(IAGKN(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBGSHAREUP'))..
  GDATA(IGKE,'GDCOMBGSHAREUP')*(
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGEN_T(IA,IGCOMB2,IS3,T)) + VGEN_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGEN_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGEN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE))
  )
         =G=
  VGEN_T(IA,IGKE,IS3,T)
;


QNECOMBGSHARELO(IA,IGKE,IS3,T)$(IAGKN(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBGSHARELO'))..
  VGEN_T(IA,IGKE,IS3,T) =G= GDATA(IGKE,'GDCOMBGSHARELO')*
  (
    ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGEN_T(IA,IGCOMB2,IS3,T)) + VGEN_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
  + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGEN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGEN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)
  )
;


* "New combtech in IGKE, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
QNECOMBFSHARELO(IA,IGKE,IS3,T)$(IAGKN(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBFSHARELO'))..
  VGFN_T(IA,IGKE,IS3,T) =G= GDATA(IGKE,'GDCOMBFSHARELO')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T)) + VGFN_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGFN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)
  );


* "New combtech in IGKE, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
QNECOMBFSHAREUP(IA,IGKE,IS3,T)$(IAGKN(IA,IGKE) AND (IGCOMB1(IGKE) OR IGCOMB2(IGKE)) AND GDATA(IGKE,'GDCOMBFSHAREUP'))..
  VGFN_T(IA,IGKE,IS3,T) =G= GDATA(IGKE,'GDCOMBFSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKE,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T)) + VGFN_T(IA,IGKE,IS3,T) )$IGCOMB1(IGKE)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKE), VGFN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKE)
  );



* Bounds on individual units are handled individually in QNHCOMBGSHAREK11 and QNHCOMBGSHAREK12, however, the sum-of-bounds may exceed 1
QNHCOMBGUP(IA,IGCOMB1,IS3,T)$(IAGKN(IA,IGCOMB1) AND IGKH(IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGUP'))..
  VGKN(IA,IGCOMB1)*(1$(NOT IGKRATE(IA,IGCOMB1,IS3,T)) + IGKRATE(IA,IGCOMB1,IS3,T)) * (GDATA(IGCOMB1,'GDCOMBGUP')$GDATA(IGCOMB1,'GDCOMBGUP')+1$(NOT GDATA(IGCOMB1,'GDCOMBGUP')))
  =G=
  VGHN_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGHN_T(IA,IGCOMB2,IS3,T))
;

* "New primal combtech, production any (S,T) limited by rated capacity on primal, heat (0 means irrelevant) (MW)"
QNHCOMBGSHAREK11(IA,IGCOMB1,IS3,T)$(IAGKN(IA,IGCOMB1) AND IGKH(IGCOMB1) AND GDATA(IGCOMB1,'GDCOMBGSHAREK1'))..
    VGHN_T(IA,IGCOMB1,IS3,T) =L= VGKN(IA,IGCOMB1) * GDATA(IGCOMB1,'GDCOMBGSHAREK1');

* "New secondary combtech, production any (S,T) limited by rated capacity on primal, heat (0 means irrelevant) (MW)"
QNHCOMBGSHAREK12(IA,IGCOMB1,IGCOMB2,IS3,T)$(IAGKN(IA,IGCOMB2) AND IGKH(IGCOMB2) AND GGCOMB(IGCOMB1,IGCOMB2) AND GDATA(IGCOMB2,'GDCOMBGSHAREK1'))..
    VGHN_T(IA,IGCOMB2,IS3,T) =L= VGKN(IA,IGCOMB1) * GDATA(IGCOMB2,'GDCOMBGSHAREK1');


QNHCOMBGSHARELO(IA,IGKH,IS3,T)$(IAGKN(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBGSHARELO'))..
  VGHN_T(IA,IGKH,IS3,T) =G= GDATA(IGKH,'GDCOMBGSHARELO')*(
      (SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGHN_T(IA,IGCOMB2,IS3,T)) + VGHN_T(IA,IGKH,IS3,T))$IGCOMB1(IGKH)
    + (SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGHN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGHN_T(IA,IGCOMB2,IS3,T))))$IGCOMB2(IGKH))
;


QNHCOMBGSHAREUP(IA,IGKH,IS3,T)$(IAGKN(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBGSHAREUP'))..
  GDATA(IGKH,'GDCOMBGSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGHN_T(IA,IGCOMB2,IS3,T)) + VGHN_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGHN_T(IA,IGCOMB1,IS3,T) + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGHN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  )
         =G=
  VGHN_T(IA,IGKH,IS3,T)
;


* "New combtech in IGKH, minimum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
QNHCOMBFSHARELO(IA,IGKH,IS3,T)$(IAGKN(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBFSHARELO'))..
  VGFN_T(IA,IGKH,IS3,T) =G= GDATA(IGKH,'GDCOMBFSHARELO')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T)) + VGFN_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGFN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  );


* "New combtech in IGKH, maximum share any (S,T) of total fuel use for this combtech group, electricity (0 means irrelevant) ([0;1])"
QNHCOMBFSHAREUP(IA,IGKH,IS3,T)$(IAGKN(IA,IGKH) AND (IGCOMB1(IGKH) OR IGCOMB2(IGKH)) AND GDATA(IGKH,'GDCOMBFSHAREUP'))..
  VGFN_T(IA,IGKH,IS3,T) =G= GDATA(IGKH,'GDCOMBFSHAREUP')*
  (  ( SUM(IGCOMB2$GGCOMB(IGKH,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T)) + VGFN_T(IA,IGKH,IS3,T) )$IGCOMB1(IGKH)
   + ( SUM(IGCOMB1$GGCOMB(IGCOMB1,IGKH), VGFN_T(IA,IGCOMB1,IS3,T)  + SUM(IGCOMB2$GGCOMB(IGCOMB1,IGCOMB2), VGFN_T(IA,IGCOMB2,IS3,T))) )$IGCOMB2(IGKH)
  );





