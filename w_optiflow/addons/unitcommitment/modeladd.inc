* Unit commitment add-on to Balmorel.

* Additional equations in model definition:

QUCMINVGF
QUCMINVGFN
QUCMAXVGF
QUCMAXVGFN
QUCSTARTQ
QUCSTARTQN

$ifi %UnitCmin%==yes    QUCUT
$ifi %UnitCmin%==yes    QUCDT
$ifi %UnitCmin%==yes    QUCUTN
$ifi %UnitCmin%==yes    QUCDTN

$ifi %UnitCramp%==yes   QUCRAMPU
$ifi %UnitCramp%==yes   QUCRAMPUN
$ifi %UnitCramp%==yes   QUCRAMPD
$ifi %UnitCramp%==yes   QUCRAMPDN

