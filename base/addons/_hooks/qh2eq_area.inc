* File qh2eq_area.inc for Balmorel addons that are relevant for equation QEEQ
* Last revision...

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_qh2eq_area.inc"  $include  "../addons/OptiFlow/OptiFlow_qh2eq_area.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_qh2eq_area.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_qh2eq_area.inc"


