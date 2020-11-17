* Location of equation assignments used in add-ons

* Example of a generic line for addon integration (replace ADDONNAME for a specific add-on):
$ifi %ADDONNAME%==yes $include    "../../base/addons/ADDONNAME/ADDONNAME_eqndefine.inc";

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_equations.inc"  $include  "../addons/OptiFlow/OptiFlow_equations.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_equations.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_equations.inc"

