
$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_parameters.inc"  $include  "../addons/OptiFlow/OptiFlow_parameters.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_parameters.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_parameters.inc"
