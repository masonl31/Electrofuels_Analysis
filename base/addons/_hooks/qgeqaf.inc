* File qgeqaf.inc for Balmorel addons that are relevant for equation QEEQ
* Last revision...

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_qgeqaf.inc"  $include  "../addons/OptiFlow/OptiFlow_qgeqaf.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_qgeqaf.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_qgeqaf.inc";


