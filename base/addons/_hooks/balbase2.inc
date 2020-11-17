* File balbase2.inc for handling additions of equations an addon in the definition of Balmorel model balbase2

$ifi not %bb2%==yes $goto endoffile

$ifi %COMBTECH%==yes $ifi     exist "../addons/combtech/combtech_balbase2.inc"  $include  "../addons/combtech/combtech_balbase2.inc";
$ifi %COMBTECH%==yes $ifi not exist "../addons/combtech/combtech_balbase2.inc"  $include  ".../../base/addons/combtech/combtech_balbase2.inc"

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_modeldef.inc"  $include  "../addons/OptiFlow/OptiFlow_modeldef.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_modeldef.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_modeldef.inc"


$label endoffile
