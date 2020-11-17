* Location of equation declarations and definitions used in addons (for any addon where declarations and definitions are in the same file)

$ifi %BB4%==yes $goto beginbb4

$ifi %COMBTECH%==yes $ifi     exist '..\addons\combtech\combtech_eqndecdef.inc'  $include  '..\addons\combtech\combtech_eqndecdef.inc';
$ifi %COMBTECH%==yes $ifi not exist '..\addons\combtech\combtech_eqndecdef.inc'  $include  '..\..\base\addons\combtech\combtech_eqndecdef.inc'



$ifi not %BB4%==yes $goto endoffile

$label  beginbb4

$ifi %COMBTECH%==yes $ifi     exist '..\addons\combtech\bb4\combtech_eqndecdef.inc'  $include  '..\addons\combtech\bb4\combtech_eqndecdef.inc';
$ifi %COMBTECH%==yes $ifi not exist '..\addons\combtech\bb4\combtech_eqndecdef.inc'  $include  '..\..\base\addons\combtech\bb4\combtech_eqndecdef.inc'


$label endoffile


