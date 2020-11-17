* Unit commitment add-on to Balmorel.

* Variables

*==================================================================================================================================================

INTEGER VARIABLE   VUCON(AAA,G,S,T)            'Unit commitment (0,1) on electricity generation, existing units'
INTEGER VARIABLE   VUCONN(AAA,G,S,T)           'Unit commitment (0,1) on electricity generation, new units'

POSITIVE VARIABLE
   VUCU(AAA,G,S,T)             'Start up, Unit commitment (0,1) on electricity generation, existing units'
   VUCD(AAA,G,S,T)             'Unit commitment Shutdown (0,1) on electricity generation, existing units'
   VUCUN(AAA,G,S,T)            'Start up, Unit commitment (0,1) on electricity generation, new units'
   VUCDN(AAA,G,S,T)            'Unit commitment Shutdown (0,1) on electricity generation, new units'
;

