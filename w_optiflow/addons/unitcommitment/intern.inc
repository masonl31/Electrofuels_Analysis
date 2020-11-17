* Unit commitment add-on to Balmorel.
* Implemented by Hans Ravn 2006-2007.
* See the documentation for details and inspiration.

* Internal sets

SET IGUCE(G) ;
IGUCE(IGKE)$GDATA(IGKE,'GDUC')=yes;

SET IGUCH(G);
IGUCH(IGKHNOSTO)$GDATA(IGKHNOSTO,'GDUC')=yes;

SET IGUC(G);
IGUC(IGUCE)=YES;
IGUC(IGUCH)=YES;

$ifi %UnitCramp%==yes UCGSHUTD(IGUC,IUCT)$(ord(IUCT) LE GDATA(IGUC,'GDUCDURD') and GDATA(IGUC,'GDUCDURD'))  = SUM((IA),GKFX('2015',IA,IGUC)*(GDATA(IGUC,'GDUCDURD')-ord(IUCT))/GDATA(IGUC,'GDUCDURD')*GDATA(IGUC,'GDUCGMIN'));
$ifi %UnitCramp%==yes UCGSTARTU(IGUC,IUCT)$(ord(IUCT) LE GDATA(IGUC,'GDUCDURU') and GDATA(IGUC,'GDUCDURU'))  = SUM((IA),GKFX('2015',IA,IGUC)*(ord(IUCT))/GDATA(IGUC,'GDUCDURU')*GDATA(IGUC,'GDUCGMIN'));



