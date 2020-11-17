* File balbase3.inc for handling additions of equations an addon in the definition of Balmorel model balbase3

$ifi not %bb3%==yes $goto endoffile


$ifi %COMBTECH%==yes $ifi     exist "../addons/combtech/combtech_balbase3.inc"  $include  "../addons/combtech/combtech_balbase3.inc";
$ifi %COMBTECH%==yes $ifi not exist "../addons/combtech/combtech_balbase3.inc"  $include  ".../../base/addons/combtech/combtech_balbase3.inc"

$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_modeldef.inc"  $include  "../addons/OptiFlow/OptiFlow_modeldef.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_modeldef.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_modeldef.inc"


$label endoffile
