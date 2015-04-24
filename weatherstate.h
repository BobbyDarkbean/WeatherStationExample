#ifndef WEATHERSTATE_H
#define WEATHERSTATE_H


namespace WeatherStation {


enum WeatherState
{
    WS_Clear,
    WS_Clouds,
    WS_Rain,
    WS_HeavyRain,
    WS_Storm,
    WS_IceRain,
    WS_Hail,
    WS_Snow,
    WS_SnowStorm,
    WS_Fog
};


} // namespace WeatherStation


#endif // WEATHERSTATE_H
