* Location of internal set delarations used in add-ons

* Example of a generic line for addon integration (replace ADDONNAME for a specific add-on):
$ifi %ADDONNAME%==yes  $include "../../base/addons/ADDONNAME/ADDONNAME_isetdeclare.inc";