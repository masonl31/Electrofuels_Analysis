*Data from Samfundsøkonomiske beregningsforudsætninger page 18
*Socioeconomic costs of utilising electricity i.e. using the distribution grid is 193 kr/MWh
*193 kr/MWh = 25.9408 EUR/MWh (note 7.44 is used to convert kr to EUR)
*25.9408 EUR2017/MWh = 15.08476 EUR90/MWh (Multiplying factor 0.581505687 , from base year currency converter 2016)

PARAMETER TAX_GF(YYY,AAA,G) "Fuel taxes on generation units (Money/MWh)"

/

$ontext


2014    .        DK_CA_KBH              .  Geo_EL_HeatPump-10_19           15.08476
2014    .        DK_CA_KBH              .  GeothermalEl-10_19              15.08476
2014    .        DK_CA_KBH              .  HeatPump-EL-10_19               15.08476


2030    .        DK_CA_KBH              .  Geo_EL_HeatPump-10_19          15.08476
2030    .        DK_CA_KBH              .  Geo_EL_HeatPump-20             15.08476
2030    .        DK_CA_KBH              .  GeothermalEl-10_19             15.08476
2030    .        DK_CA_KBH              .  GeothermalEl-20_29             15.08476
2030    .        DK_CA_KBH              .  HeatPump-EL-10_19              15.08476
2030    .        DK_CA_KBH              .  HeatPump-EL-20_29              15.08476
2030    .        DK_CA_KBH              .  HeatPump-EL-30_49              15.08476



2050    .        DK_CA_KBH              .  Geo_EL_HeatPump-10_19          9.6
2050    .        DK_CA_KBH              .  Geo_EL_HeatPump-20             9.6
2050    .        DK_CA_KBH              .  GeothermalEl-10_19             9.6
2050    .        DK_CA_KBH              .  GeothermalEl-20_29             9.6
2050    .        DK_CA_KBH              .  GeothermalEl-30_50             9.6
2050    .        DK_CA_KBH              .  HeatPump-EL-10_19              9.6
2050    .        DK_CA_KBH              .  HeatPump-EL-20_29              9.6
2050    .        DK_CA_KBH              .  HeatPump-EL-30_49              9.6
2050    .        DK_CA_KBH              .  HeatPump-EL-50                 9.6



$offtext



2050    .        DK_CA_KBH              .  Geo_EL_HeatPump-10_19          5.0
2050    .        DK_CA_KBH              .  Geo_EL_HeatPump-20             5.0
2050    .        DK_CA_KBH              .  GeothermalEl-10_19             5.0
2050    .        DK_CA_KBH              .  GeothermalEl-20_29             5.0
2050    .        DK_CA_KBH              .  GeothermalEl-30_50             5.0
2050    .        DK_CA_KBH              .  HeatPump-EL-10_19              5.0
2050    .        DK_CA_KBH              .  HeatPump-EL-20_29              5.0
2050    .        DK_CA_KBH              .  HeatPump-EL-30_49              5.0
2050    .        DK_CA_KBH              .  HeatPump-EL-50                 5.0



















/;

TAX_GF('2014',AAA,G)=TAX_GF('2014','DK_CA_KBH',G);
TAX_GF('2030',AAA,G)=TAX_GF('2030','DK_CA_KBH',G);
TAX_GF('2050',AAA,G)=TAX_GF('2050','DK_CA_KBH',G);




