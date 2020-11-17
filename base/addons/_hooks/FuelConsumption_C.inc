$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_FuelConsumption_C.inc"  $include  "../addons/OptiFlow/OptiFlow_FuelConsumption_C.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_FuelConsumption_C.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_FuelConsumption_C.inc"

