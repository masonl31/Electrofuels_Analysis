* Location of equation declarations used in add-ons

* Example of a generic line for addon integration (replace ADDONNAME for a specific add-on):

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_deceq.inc"  $include  "../addons/OptiFlow/OptiFlow_deceq.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_deceq.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_deceq.inc"

