
SET PROCTECHTYPE(PROC,TECHTYPE) 'Type of technology aggrupated'%semislash%

$if     EXIST '../addons/OptiFlow/data/PROCTECHTYPE.inc' $INCLUDE         '../addons/OptiFlow/data/PROCTECHTYPE.inc';
$if not EXIST '../addons/OptiFlow/data/PROCTECHTYPE.inc' $INCLUDE '../../base/addons/OptiFlow/data/PROCTECHTYPE.inc';
%semislash%;

