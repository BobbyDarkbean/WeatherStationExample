#ifndef WEATHER_GLOBAL_H
#define WEATHER_GLOBAL_H

namespace WeatherStation {

enum WeatherState
{
    WS_NonAvailable,
    WS_Clear,
    WS_PartlyCloudy,
    WS_Clouds,
    WS_Rain,
    WS_Showers,
    WS_Storm,
    WS_IceRain,
    WS_Hail,
    WS_Snow,
    WS_SnowStorm,
    WS_Fog
};

enum WindDirection
{
    WD_North,
    WD_NorthEast,
    WD_East,
    WD_SouthEast,
    WD_South,
    WD_SouthWest,
    WD_West,
    WD_NorthWest
};

enum TemperatureUnit
{
    TU_Celcius,
    TU_Fahrenheit
};

enum PressureUnit
{
    PU_MillimeterMercuryColumn,
    PU_Millibars
};

} // namespace WeatherStation

#endif // WEATHER_GLOBAL_H