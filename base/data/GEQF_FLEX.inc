*Last time modified (Amalia, 11-05-2015)
*Parameter created to take into account weekly (s) requirements related to required fuel consumption within a year
* This parameter represents a percentage, where 0, means that the required annual amount of fuel consumption defined in GEQF can be used freely within the year.
* A value of 1 (100%) means that the total annual fuel consumption has to be distributed proportionaly (taken into account weight_S) through all the year, assuring some weekly consumptions


PARAMETER GEQF_FLEX(YYY,CCCRRRAAA,FFF)

/
2014.DK_E.MUNI_WASTE  1
2014.DK_W.MUNI_WASTE  1
2020.DK_E.MUNI_WASTE  1
2020.DK_W.MUNI_WASTE  1
2025.DK_E.MUNI_WASTE  1
2025.DK_W.MUNI_WASTE  1
2030.DK_E.MUNI_WASTE  1
2030.DK_W.MUNI_WASTE  1
2035.DK_E.MUNI_WASTE  1
2035.DK_W.MUNI_WASTE  1
2040.DK_E.MUNI_WASTE  1
2040.DK_W.MUNI_WASTE  1
2045.DK_E.MUNI_WASTE  1
2045.DK_W.MUNI_WASTE  1
2050.DK_E.MUNI_WASTE  1
2050.DK_W.MUNI_WASTE  1

2014.SWEDEN.MUNI_WASTE  1
2020.SWEDEN.MUNI_WASTE  1
2025.SWEDEN.MUNI_WASTE  1
2030.SWEDEN.MUNI_WASTE  1
2035.SWEDEN.MUNI_WASTE  1
2040.SWEDEN.MUNI_WASTE  1
2045.SWEDEN.MUNI_WASTE  1
2050.SWEDEN.MUNI_WASTE  1

2014.NORWAY.MUNI_WASTE  1
2020.NORWAY.MUNI_WASTE  1
2025.NORWAY.MUNI_WASTE  1
2030.NORWAY.MUNI_WASTE  1
2035.NORWAY.MUNI_WASTE  1
2040.NORWAY.MUNI_WASTE  1
2045.NORWAY.MUNI_WASTE  1
2050.NORWAY.MUNI_WASTE  1

2014.FINLAND.MUNI_WASTE  1
2020.FINLAND.MUNI_WASTE  1
2025.FINLAND.MUNI_WASTE  1
2030.FINLAND.MUNI_WASTE  1
2035.FINLAND.MUNI_WASTE  1
2040.FINLAND.MUNI_WASTE  1
2045.FINLAND.MUNI_WASTE  1
2050.FINLAND.MUNI_WASTE  1

2014.GERMANY.MUNI_WASTE  1
2020.GERMANY.MUNI_WASTE  1
2025.GERMANY.MUNI_WASTE  1
2030.GERMANY.MUNI_WASTE  1
2035.GERMANY.MUNI_WASTE  1
2040.GERMANY.MUNI_WASTE  1
2045.GERMANY.MUNI_WASTE  1
2050.GERMANY.MUNI_WASTE  1

2014.DENMARK.HAZARDOUSWASTE  1
2020.DENMARK.HAZARDOUSWASTE  1
2025.DENMARK.HAZARDOUSWASTE  1
2030.DENMARK.HAZARDOUSWASTE  1
2035.DENMARK.HAZARDOUSWASTE  1
2040.DENMARK.HAZARDOUSWASTE  1
2045.DENMARK.HAZARDOUSWASTE  1
2050.DENMARK.HAZARDOUSWASTE  1

2014.DK_E_Rural.Biogas_net  1
2014.DK_W_Rural.Biogas_net  1
2020.DK_E_Rural.Biogas_net  1
2020.DK_W_Rural.Biogas_net  1
2025.DK_E_Rural.Biogas_net  1
2025.DK_W_Rural.Biogas_net  1
2030.DK_E_Rural.Biogas_net  1
2030.DK_W_Rural.Biogas_net  1
2035.DK_E_Rural.Biogas_net  1
2035.DK_W_Rural.Biogas_net  1
2040.DK_E_Rural.Biogas_net  1
2040.DK_W_Rural.Biogas_net  1
2045.DK_E_Rural.Biogas_net  1
2045.DK_W_Rural.Biogas_net  1
2050.DK_E_Rural.Biogas_net  1
2050.DK_W_Rural.Biogas_net  1


/
;


Parameter GEQF_FLEX_Y(CCCRRRAAA,FFF) Required fuel use (GJ) per year
;

GEQF_FLEX_Y(CCCRRRAAA,FFF)= SUM(Y,GEQF_FLEX(Y,CCCRRRAAA,FFF))/CARD(Y);

