* File Created 27-07-2011
* Lars Bregnbæk.
* This file is included from the QGFEQ equation in Balmorel.gms.

* Add cost of fixed hourly fuel use
+ (GDATA(G,'GDUCUNITSIZE')*VUCON(IA,G,IS3,T)*GDATA(G,'GDUCF0')/(GDATA(G,'GDFE')* (1-GEFFDERATE(IA,G))))$IGUC(G)

* Correct for using average efficiency as marginal efficiency.
  -(GDATA(G,'GDUCF0')*VGE_T(IA,G,IS3,T)/(GDATA(G,'GDFE')* (1-GEFFDERATE(IA,G))))$(IGUC(G) and IGE(G) and IGNOTETOH(G))
  -(GDATA(G,'GDUCF0')*GDATA(G,'GDCV')*VGH_T(IA,G,IS3,T)/(GDATA(G,'GDFE')*(1-GEFFDERATE(IA,G))))$(IGUC(G) and IGH(G))

