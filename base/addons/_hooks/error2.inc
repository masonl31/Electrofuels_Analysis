* File error2.inc for Balmorel addons, holding check of input data for obvious errors or dubious information
* Last revision 20160614(hr)

$ifi %COMBTECH%==yes $ifi     exist "../addons/combtech/combtech_error2.inc"  $include  "../addons/combtech/combtech_error2.inc";
$ifi %COMBTECH%==yes $ifi not exist "../addons/combtech/combtech_error2.inc"  $include  "../../base/addons/combtech/combtech_error2.inc"

