
*Shipment costs:http://worldfreightrates.com/freight 45 ft container (Capacity of 27 ton: https://www.hapag-lloyd.com/es/fleet/container_45_standard_highcube.html
*Assumed a capacity of 25 ton and deducted the cost in fuel consumption
*Fuel consumption of the truck, assuming it is 75% charged (Reference from TEMA2010 Et værktøj til beregning af transporters energiforbrug og emissioner i Danmark , COWI)
*In a further stage we should implement the different type of costs, so that there is a fix cost per load/unload, and then per km, as it happens during shipping . DONE (AP)

*In order to make it more general, we should call instead of Money, km, ton, more like Money, distance, units of flow

TABLE TRANSCOST(TRANSCOSTDATASET,TRANSDISTWEIGHT,PROC,FLOWINDIC)  "Transport 'cost' in terms of INDICS"
                                                         OPERATIONCOST    GHGEMISSION_nonbio  GHGEMISSION_bio
*                                                          Money            Ton
*TCDMONEYDISTFLOW.ITRANSDWDISTWEIGHT.ProcEximTruck         -9.0943           EPS
TCDMONEYDISTFLOW.ITRANSDWDISTWEIGHT.ProcEximTruck         -0.0943           EPS
TCDMONEYFLOW  .ITRANSDWWEIGHT.ProcEximShip                 0                EPS

;

PARAMETER TRANSPORTFUEL(YYY,TRANSCOSTDATASET,PROC,FLOW)
/
2011. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2014. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2020. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2025. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2030. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2035. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2040. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2045. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020
2050. TCDMONEYDISTFLOW. ProcEximTruck.DIESELFLOW     -0.0020


*2050. TCDMONEYDISTFLOW. ProcEximTruck.BIOOILFLOW     -0.0020

*2011. TCDMONEYDISTFLOW. ProcEximShip.FUELOILFLOW     -0.0003
*2012. TCDMONEYDISTFLOW. ProcEximShip.FUELOILFLOW     -0.0003
*2025. TCDMONEYDISTFLOW. ProcEximShip.FUELOILFLOW     -0.0003
*2035. TCDMONEYDISTFLOW. ProcEximShip.FUELOILFLOW     -0.0003
*2050. TCDMONEYDISTFLOW. ProcEximShip.DIESELFLOW      -0.0003

/;


TRANSCOST(TRANSCOSTDATASET,TRANSDISTWEIGHT,PROCEXIM,FLOWINDIC)= TRANSCOST(TRANSCOSTDATASET,TRANSDISTWEIGHT,PROCEXIM,FLOWINDIC)+SUM((Y,FLOW),TRANSPORTFUEL(Y,TRANSCOSTDATASET,PROCEXIM,FLOW)*SUM(PROCBUFFER,SOSIBU2INDIC(Y,PROCBUFFER,FLOW,FLOWINDIC)));



