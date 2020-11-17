* Location of internal set delarations and definitions used in addons  (for any addon where declarations and definitions are in the same file)


$ifi %OPTIFLOW%==yes $ifi     exist "../addons/OptiFlow/OptiFlow_sim.inc"  $include  "../addons/OptiFlow/OptiFlow_sim.inc";
$ifi %OPTIFLOW%==yes $ifi not exist "../addons/OptiFlow/OptiFlow_sim.inc"  $include  "../../base/addons/OptiFlow/OptiFlow_sim.inc"
