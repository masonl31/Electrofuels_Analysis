$ifi %OPTIFLOW%==yes $ifi     exist '..\addons\OptiFlow\optiflowopt.opt'  $include  '..\addons\OptiFlow\optiflowopt.opt';
$ifi %OPTIFLOW%==yes $ifi not exist '..\addons\OptiFlow\optiflowopt.opt'  $include  '..\..\base\addons\OptiFlow\optiflowopt.opt'
