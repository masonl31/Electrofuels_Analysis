SET  GDATASET 'Generation technology data'
/
GDTYPE                          "Generation type"
GDFUEL                          "Fuel type"
GDCV                            "Cv-value for CHP-Ext"
GDCB                            "Cb-value for CHP"
$ifi %bypass%==yes GDBYPC "Bypass coefficient for backpressure type units (non-negative; 0 means no bypass possibility) ()"
GDFE                            "Fuel efficiency"
GDDESO2                         "Degree of desulphoring"
GDNOX                           "NOx-factor (mg/MJ)"
GDCH4                           "CH4-factor (mg/MJ)"
GDINVCOST0                      "Investment cost (MMoney/MW)(default value)"
GDOMVCOST0                      "Variable operating and maintenance costs (Money/MWh)(default value)"
GDOMFCOST0                      "Annual operating and maintenance costs (kMoney/MW/year)(default value)"
GDFROMYEAR                      "Technology available from this year"
GDLASTYEAR                      "Technology investment expires from this year (blank or 0 implies no expiration)"
GDMOTHBALL                      "Year when a unit is mothballed"
GDLIFETIME                      "Economic lifetime (years)"
GDKVARIABL                      "Capacity is a variable to be found for each year (1/0)"
GDSTOHLOAD                      "Hours to load storage"
GDSTOHUNLD                      "Hours to unload storage"
GDLOADLOSS                      "Loss when loading a storage (MWh loss/MWh loading input)"
GDSTOLOSS                       "Stationary loss from storage (MWh loss per time period/MWh energy content in storage)"
GDUC                            "Unit commitment: the unit participates in unit commitment (0/1)"
GDUCUNITSIZE                    "Standard size of unit type (MW)"
GDUCGMIN                        "Unit commitment: minimum production (share of nominal capacity)"
GDUCUCOST                       "Unit commitment: startup cost (Money)"
GDUCCOST0                       "Unit commitment: fixed hourly cost (Money)"
GDUCF0                          "Unit commitment: fixed hourly fuel use (MWh)"
GDUCDCOST                       "Unit commitment: shutdown cost (Money)"
GDUCDTMIN                       "Unit commitment: minimum down time (hours)"
GDUCUTMIN                       "Unit commitment: minimum up time (hours)"
GDUCDURD                        "Unit commitment: duration of shut down process (hours)"
GDUCDURU                        "Unit commitment: duration of start up process (hours)"
GDUCRAMPU                       "Unit commitment: ramp-up limit (% of capacity/h)"
GDUCRAMPD                       "Unit commitment: ramp-down limit (% of capacity/h)"
GDSTOINTERS
GDBYPASSC                       "By-pass coefficient"

GDCOMB            "Combination technology, primal (1) or secondary (2)"                                                                  !! Addon combtech
GDCOMBGUP         "Combination technology group's sum-of-generation's (MW) maximum share of primal rated capacity (default 1) ([0;1])"   !! Addon combtech
GDCOMBGSHAREK1    "Combination technology, maximum generation (MW) share of primal rated capacity (default 1) ([0;1])"                   !! Addon combtech
GDCOMBFUP         "Combination technology group's sum-of-fuel-use's (GJ) maximum share of primal rated capacity ([0;1])"                 !! Addon combtech   Presently no in use         Units?
GDCOMBFSHAREK1    "Combination technology, maximum fuel (GJ) share of primal rated capacity ([0;1])"                                     !! Addon combtech   Presently no in use         Units?
GDCOMBGSHARELO    "Combination technology, minimum generation (MW) share of total generation ([0;1])"                                    !! Addon combtech
GDCOMBGSHAREUP    "Combination technology, maximum generation (MW) share of total generation ([0;1])"                                    !! Addon combtech
GDCOMBFSHARELO    "Combination technology, minimum fuel (GJ) share of total fuel use ([0;1])"                                            !! Addon combtech
GDCOMBFSHAREUP    "Combination technology, maximum fuel (GJ) share of total fuel use ([0;1])"                                            !! Addon combtech

/;
