* File setdeclare.inc for handling SET declarations for Balmorel addons


$ifi %COMBTECH%==yes  $include   "../../base/addons/combtech/combtech_setdeclare.inc";

$ifi %combtech%==yes $ifi     exist "../addons/combtech/combtech_setdeclare.inc"  $include  "../addons/combtech/combtech_setdeclare.inc";
$ifi %combtech%==yes $ifi not exist "../addons/combtech/combtech_setdeclare.inc"  $include  "../../base/addons/combtech/combtech_setdeclare.inc"
