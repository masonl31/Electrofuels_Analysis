* Convention for entering data:
*   Enter at most one data item for each PROC,
*   If nothing or 0 is entered then the default values corresponding to the declaration of the variable (positive, negative or free) apply.
*   If EPS is entered then the corresponding value will be zero (CHECK IT).
* The unit for the data may differ between (PROC,FLOW).

PARAMETER TRANSFLOWMAX(IAAAE,IAAAI,PROC,FLOW)  "Transport quantity maximum value (ton/h)"

/

/;

TRANSFLOWMAX(IAAAE,IAAAI,'ProcEximTruck',IFLOWEXIM)$(AAAIMPORT(IAAAE) OR AAAIMPORT(IAAAI))=EPS;
TRANSFLOWMAX(IAAAE,IAAAI,'ProcEximShip',IFLOWEXIM)$(NOT AAAIMPORT(IAAAE))=EPS;   