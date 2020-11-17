*Last time modified (Amalia,15-06-2015) 
* Amalia, HAZARDOUSWASTE added with FDNB = 43.
* FDCO2, FDSO2 , FDN2O = 0

TABLE FDATA(FFF,FDATASET) "Fuel specific values"
                 FDACRONYM          FDNB       FDCO2       FDSO2       FDN2O        FDRE

NUCLEAR          NUCLEAR          1.0000      0.0000                                0.00
NAT_GAS          NAT_GAS          2.0000     56.8000                  0.0010
COAL             COAL             3.0000     95.0000      0.7140      0.0030
LIGNITE          LIGNITE          4.0000    101.0000      1.4280      0.0030
FUELOIL          FUELOIL          5.0000     78.0000      0.4460      0.0020
LIGHTOIL         LIGHTOIL         6.0000     74.0000      0.0230      0.0020
ORIMULSION       ORIMULSION       7.0000     80.0000      1.3370      0.0020
SHALE            SHALE            8.0000    106.0000      1.4280      0.0030
PEAT             PEAT             9.0000    107.0000      0.2400      0.0030
MUNI_WASTE       MUNI_WASTE      10.0000     32.4600      0.1560      0.0040      0.7287
STRAW            STRAW           11.0000     11.0000      0.0250      0.0040      1.0000
WOOD             WOOD            12.0000      0.0000      0.0250      0.0040      1.0000
WOOD_WASTE       WOOD_WASTE      13.0000      0.0000      0.0250      0.0040      1.0000
WIND             WIND            14.0000                                          1.0000
WATER            WATER           15.0000                                          1.0000
SUN              SUN             16.0000                                          1.0000
ELECTRIC         ELECTRIC        17.0000
DUMMY            DUMMY           18.0000
HEAT             HEAT            19.0000
WOOD_PELLETS     WOOD_PELLETS    21.0000      1.0000      0.0250      0.0040      1.0000
STRAW_PELLETS    STRAW_PELLETS   20.0000      11.0000     0.0250      0.0040      1.0000
COAL_CCS         COAL_CCS        22.0000      9.5000      0.7140      0.0030
BIOGAS           BIOGAS          23.0000     -77.4000                 0.0010      1.0000
BIOGAS_net       BIOGAS_net      24.0000     -77.4000                 0.0010      1.0000
SURPLUS_H        SURPLUS_H       25.0000                                          1.0000
WAVE             WAVE            26.0000                                          1.0000
COAL2            COAL2           27.0000     95.0000      0.9360      0.0030
MUNI_WASTE_RE    MUNI_WASTE_RE   28.0000                  0.1560      0.0040      1.0000
WP_CCS           WP_CCS          29.0000    -79.7500      0.0250      0.0040      1.0000
LFGAS            LFGAS           30.0000                              0.0010      1.0000
GeoEl            GeoEl           31.0000                                          1.0000
NG_CCS           NG_CCS          32.0000      8.6000                  0.0010
BIOOIL           BIOOIL          33.0000                              0.0010      1.0000
Retort_gas       Retort_gas      34.0000     56.8000                  0.0010
COKE             COKE            35.0000    106.0000      1.4280      0.0030
BIOGAS_EC        BIOGAS_EC       36.0000    -77.4000                  0.0010      1.0000
BIOGAS_EC_net    BIOGAS_EC_net   37.0000    -77.4000                  0.0010      1.0000
MUNI_WASTE_CPH   MUNI_WASTE_CPH  38.0000     37.0000      0.1560      0.0040      0.5900
WOOD_CPH         WOOD_CPH        39.0000     0.0000       0.0250      0.0040      1.0000
STRAW_CPH        STRAW_CPH       40.0000     11.0000      0.0250      0.0040      1.0000
BIO_PEAK         BIO_PEAK        41.0000    -77.4000      0.0250      0.0040      1.0000
BIO_PEAKgas      BIO_PEAKgas     42.0000    -77.4000      0.0250      0.0040      1.0000
HAZARDOUSWASTE   HAZARDOUSWASTE  43.0000     0.0000                                 0
GH2FUEL          GH2FUEL         44.0000                                          1.0000
;

*CO2 emissions from Municipal Solid Waste will change over time, as the composition and recycling of waste will evolve
*Using the econometric tool FRIDA to forecast waste amounts and compositions, the following evolution of CO2 emissions is predicted
*These values might also change depending on the treatment of the organic fraction of MSW, therefore might need to be exogeneously updated
*Here, predicted recycling of 30% of the organic waste generated from 2025
*Currently, the parameter FDATA cannot hanlde different years, so GHG emissions have to be changed manually
$ontext
         FDCO2   FDRE
2012     32.46   0.7287
2013     30.61   0.7337
2014     29.52   0.7391
2015     28.29   0.7437
2016     27.18   0.7514
2017     26.01   0.7596
2018     24.76   0.7684
2019     23.91   0.7661
2020     23.03   0.7654
2021     22.13   0.7617
2022     21.19   0.7576
2023     21.23   0.7584
2024     21.25   0.7595
2025     21.26   0.7607
2026     21.25   0.7612
2027     21.23   0.7619
2028     21.22   0.7634
2029     21.21   0.7646
2030     21.21   0.7651
2031     21.22   0.7666
2032     21.21   0.7674
2033     21.21   0.7688
2034     21.20   0.7698
2035     21.22   0.7695
2036     21.24   0.7707
2037     21.26   0.7710
2038     21.28   0.7717
2039     21.30   0.7721
2040     21.35   0.7714
2041     21.39   0.7722
2042     21.42   0.7723
2043     21.44   0.7729
2044     21.47   0.7732
2045     21.53   0.7724
2046     21.57   0.7732
2047     21.60   0.7731
2048     21.63   0.7736
2049     21.66   0.7739
2050     21.72   0.7733

$offtext


$ONTEXT


PARAMETER FDATA(FFF,FDATASET) "Fuel specific values"

/
NUCLEAR                          . FDNB                                                      1.0000
NAT_GAS                          . FDNB                                                      2.0000
NAT_GAS                          . FDCO2                                                    56.8000
NAT_GAS                          . FDN2O                                                     0.0010
COAL                             . FDNB                                                      3.0000
COAL                             . FDCO2                                                    95.0000
COAL                             . FDSO2                                                     0.7140
COAL                             . FDN2O                                                     0.0030
LIGNITE                          . FDNB                                                      4.0000
LIGNITE                          . FDCO2                                                   101.0000
LIGNITE                          . FDSO2                                                     1.4280
LIGNITE                          . FDN2O                                                     0.0030
FUELOIL                          . FDNB                                                      5.0000
FUELOIL                          . FDCO2                                                    78.0000
FUELOIL                          . FDSO2                                                     0.4460
FUELOIL                          . FDN2O                                                     0.0020
LIGHTOIL                         . FDNB                                                      6.0000
LIGHTOIL                         . FDCO2                                                    74.0000
LIGHTOIL                         . FDSO2                                                     0.0230
LIGHTOIL                         . FDN2O                                                     0.0020
ORIMULSION                       . FDNB                                                      7.0000
ORIMULSION                       . FDCO2                                                    80.0000
ORIMULSION                       . FDSO2                                                     1.3370
ORIMULSION                       . FDN2O                                                     0.0020
SHALE                            . FDNB                                                      8.0000
SHALE                            . FDCO2                                                   106.0000
SHALE                            . FDSO2                                                     1.4280
SHALE                            . FDN2O                                                     0.0030
PEAT                             . FDNB                                                      9.0000
PEAT                             . FDCO2                                                   107.0000
PEAT                             . FDSO2                                                     0.2400
PEAT                             . FDN2O                                                     0.0030
MUNI_WASTE                       . FDNB                                                     10.0000
MUNI_WASTE                       . FDCO2                                                    37.0000
MUNI_WASTE                       . FDSO2                                                     0.1560
MUNI_WASTE                       . FDN2O                                                     0.0040
MUNI_WASTE                       . FDRE                                                      0.5900
STRAW                            . FDNB                                                     11.0000
STRAW                            . FDSO2                                                     0.0250
STRAW                            . FDN2O                                                     0.0040
STRAW                            . FDRE                                                      1.0000
WOOD                             . FDNB                                                     12.0000
WOOD                             . FDSO2                                                     0.0250
WOOD                             . FDN2O                                                     0.0040
WOOD                             . FDRE                                                      1.0000
WOOD_WASTE                       . FDNB                                                     13.0000
WOOD_WASTE                       . FDSO2                                                     0.0250
WOOD_WASTE                       . FDN2O                                                     0.0040
WOOD_WASTE                       . FDRE                                                      1.0000
WIND                             . FDNB                                                     14.0000
WIND                             . FDRE                                                      1.0000
WATER                            . FDNB                                                     15.0000
WATER                            . FDRE                                                      1.0000
SUN                              . FDNB                                                     16.0000
SUN                              . FDRE                                                      1.0000
ELECTRIC                         . FDNB                                                     17.0000
DUMMY                            . FDNB                                                     18.0000
HEAT                             . FDNB                                                     19.0000
WOOD_PELLETS                     . FDNB                                                     21.0000
WOOD_PELLETS                     . FDSO2                                                     0.0250
WOOD_PELLETS                     . FDN2O                                                     0.0040
WOOD_PELLETS                     . FDRE                                                      1.0000
STRAW_PELLETS                    . FDNB                                                     20.0000
STRAW_PELLETS                    . FDSO2                                                     0.0250
STRAW_PELLETS                    . FDN2O                                                     0.0040
STRAW_PELLETS                    . FDRE                                                      1.0000
COAL_CCS                         . FDNB                                                     22.0000
COAL_CCS                         . FDCO2                                                     9.5000
COAL_CCS                         . FDSO2                                                     0.7140
COAL_CCS                         . FDN2O                                                     0.0030
BIOGAS                           . FDNB                                                     23.0000
BIOGAS                           . FDN2O                                                     0.0010
BIOGAS                           . FDRE                                                      1.0000
BIOGAS_net                       . FDNB                                                     24.0000
BIOGAS_net                       . FDN2O                                                     0.0010
BIOGAS_net                       . FDRE                                                      1.0000
SURPLUS_H                        . FDNB                                                     25.0000
SURPLUS_H                        . FDRE                                                      1.0000
WAVE                             . FDNB                                                     26.0000
WAVE                             . FDRE                                                      1.0000
COAL2                            . FDNB                                                     27.0000
COAL2                            . FDCO2                                                    95.0000
COAL2                            . FDSO2                                                     0.9360
COAL2                            . FDN2O                                                     0.0030
MUNI_WASTE_RE                    . FDNB                                                     28.0000
MUNI_WASTE_RE                    . FDSO2                                                     0.1560
MUNI_WASTE_RE                    . FDN2O                                                     0.0040
MUNI_WASTE_RE                    . FDRE                                                      1.0000
WP_CCS                           . FDNB                                                     29.0000
WP_CCS                           . FDCO2                                                   -80.7500
WP_CCS                           . FDSO2                                                     0.0250
WP_CCS                           . FDN2O                                                     0.0040
WP_CCS                           . FDRE                                                      1.0000
LFGAS                            . FDNB                                                     30.0000
LFGAS                            . FDN2O                                                     0.0010
LFGAS                            . FDRE                                                      1.0000
GeoEl                            . FDNB                                                     31.0000
GeoEl                            . FDRE                                                      1.0000
NG_CCS                           . FDNB                                                     32.0000
NG_CCS                           . FDCO2                                                     8.6000
NG_CCS                           . FDN2O                                                     0.0010
BIOOIL                           . FDNB                                                     33.0000
BIOOIL                           . FDN2O                                                     0.0010
BIOOIL                           . FDRE                                                      1.0000
Retort_gas                       . FDNB                                                     34.0000
Retort_gas                       . FDCO2                                                    56.8000
Retort_gas                       . FDN2O                                                     0.0010
COKE                             . FDNB                                                     35.0000
COKE                             . FDCO2                                                   106.0000
COKE                             . FDSO2                                                     1.4280
COKE                             . FDN2O                                                     0.0030
BIOGAS_EC                        . FDNB                                                     36.0000
BIOGAS_EC                        . FDN2O                                                     0.0010
BIOGAS_EC                        . FDRE                                                      1.0000
BIOGAS_EC_net                    . FDNB                                                     37.0000
BIOGAS_EC_net                    . FDN2O                                                     0.0010
BIOGAS_EC_net                    . FDRE                                                      1.0000
MUNI_WASTE_CPH                   . FDNB                                                     38.0000
MUNI_WASTE_CPH                   . FDCO2                                                    37.0000
MUNI_WASTE_CPH                   . FDSO2                                                     0.1560
MUNI_WASTE_CPH                   . FDN2O                                                     0.0040
MUNI_WASTE_CPH                   . FDRE                                                      0.5900
WOOD_CPH                         . FDNB                                                     39.0000
WOOD_CPH                         . FDSO2                                                     0.0250
WOOD_CPH                         . FDN2O                                                     0.0040
WOOD_CPH                         . FDRE                                                      1.0000
STRAW_CPH                        . FDNB                                                     40.0000
STRAW_CPH                        . FDSO2                                                     0.0250
STRAW_CPH                        . FDN2O                                                     0.0040
STRAW_CPH                        . FDRE                                                      1.0000
BIO_PEAK                         . FDNB                                                     41.0000
BIO_PEAK                         . FDSO2                                                     0.0250
BIO_PEAK                         . FDN2O                                                     0.0040
BIO_PEAK                         . FDRE                                                      1.0000
BIO_PEAKgas                      . FDNB                                                     42.0000
BIO_PEAKgas                      . FDSO2                                                     0.0250
BIO_PEAKgas                      . FDN2O                                                     0.0040
BIO_PEAKgas                      . FDRE                                                      1.0000
HAZARDOUSWASTE                   . FDNB                                                     43.0000
HAZARDOUSWASTE                   . FDSO2                                                     0.0000
HAZARDOUSWASTE                   . FDN2O                                                     0.0000
HAZARDOUSWASTE                   . FDRE                                                      0.0000
/;

$OffTEXT
