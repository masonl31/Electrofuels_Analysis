$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_variables.inc"  $include  "../addons/OptiFlow/OptiFlow_variables.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_variables.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_variables.inc"

