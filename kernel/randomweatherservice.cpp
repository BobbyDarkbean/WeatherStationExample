#include <ctime>
#include "location.h"
#include "randomweatherservice.h"

namespace WeatherStation {

namespace {

enum ClimaticZone
{
    CZ_Equatorial,
    CZ_Tropical,
    CZ_Subtropical,
    CZ_Temperate,
    CZ_Boreal,
    CZ_Tundra,
    CZ_Polar,

    CZ_Min = CZ_Equatorial,
    CZ_Max = CZ_Polar,
    CZ_Count
};

enum TemRangeBound { TRB_Min, TRB_Max, TRB_Count };

int temRange[CZ_Count][TRB_Count] = {
    { +10, +45 },                       // Equatorial
    {  +5, +45 },                       // Tropical
    {  +5, +40 },                       // Subtropical
    {  -5, +40 },                       // Temperate
    { -20, +40 },                       // Boreal
    { -40, +20 },                       // Tundra
    { -75,  +5 }                        // Polar
};

ClimaticZone climaticZone(qreal latitude)
{
    if        (                   !(latitude > 20.0)) { return CZ_Equatorial;
    } else if (20.0 < latitude && !(latitude > 35.0)) { return CZ_Tropical;
    } else if (35.0 < latitude && !(latitude > 45.0)) { return CZ_Subtropical;
    } else if (45.0 < latitude && !(latitude > 52.5)) { return CZ_Temperate;
    } else if (52.5 < latitude && !(latitude > 60.0)) { return CZ_Boreal;
    } else if (60.0 < latitude && !(latitude > 75.0)) { return CZ_Tundra;
    } else                                            { return CZ_Polar;
    }
}

qreal randomTemperature(qreal latitude)
{
    ClimaticZone cz = climaticZone(latitude);
    int range = 10 * (temRange[cz][TRB_Max] - temRange[cz][TRB_Min]);
    return static_cast<qreal>(qrand() % range) / 10 + temRange[cz][TRB_Min];
}

qreal randomPredictionalTemperature(qreal latitude, qreal seed)
{
    const int Range = 100;
    ClimaticZone cz = climaticZone(latitude);
    qreal tMin = qBound(static_cast<qreal>(temRange[cz][TRB_Min]),
                        seed - Range / 20,
                        static_cast<qreal>(temRange[cz][TRB_Max] - Range / 10));
    return static_cast<qreal>(qrand() % 100) / 10 + tMin;
}

qreal randomPressure()
{
    return static_cast<qreal>(qrand() % 800) / 10 + 711;        // 711.0 - 790.9
}

int randomHumidity(qreal pressure)
{
    if (pressure < 740.0) {
        return qrand() % 30 + 71;                               // 71% - 100%
    } else if (!(pressure < 740.0) && pressure < 750.0) {
        return qrand() % 40 + 61;                               // 61% - 100%
    } else if (!(pressure < 750.0) && pressure < 760.0) {
        return qrand() % 60 + 41;                               // 41% - 100%
    } else if (!(pressure < 760.0) && pressure < 770.0) {
        return qrand() % 90 + 1;                                // 1% - 90%
    } else {
        return qrand() % 50 + 1;                                // 1% - 50%
    }
}

WeatherState randomWeatherState(qreal temperature, qreal pressure, int humidity)
{
    if (!(pressure > 725.0))
        return WS_Fog;

    bool cloudy = false;
    if (!(temperature < 25.0)) {
        cloudy = (pressure < 740.0);
    } else if (!(temperature < 15.0) && temperature < 25.0) {
        cloudy = (pressure < 750.0);
    } else if (!(temperature < -5.0) && temperature < 15.0) {
        cloudy = (pressure < 760.0);
    } else {
        cloudy = (pressure < 750.0);
    }

    if (!cloudy) {
        return (qrand() % 2) ? WS_Clear : WS_PartlyCloudy;
    }

    WeatherState states[][4] = {
        { WS_Clouds, WS_Rain, WS_Showers, WS_Storm },
        { WS_Clouds, WS_Rain, WS_Showers, WS_Hail },
        { WS_Clouds, WS_Snow, WS_IceRain, WS_SnowStorm },
        { WS_Clouds, WS_Snow, WS_Snow, WS_SnowStorm }
    };

    int precip = (humidity > 75) ? (qrand() % 3 + 1) : 0;

    if (!(temperature < 15.0)) {
        return states[0][precip];
    } else if (!(temperature < 5.0) && temperature < 15.0) {
        return states[1][precip];
    } else if (!(temperature < -1.0) && temperature < 5.0) {
        return states[2][precip];
    } else {
        return states[3][precip];
    }
}

int randomWindDirectionDegrees()
{
    return qrand() % 360;
}

qreal randomWindSpeed(WeatherState weatherState)
{
    switch (weatherState)
    {
    case WS_Fog:
        return static_cast<qreal>(qrand() % 50 + 1) / 10;       // 0.1 - 5.0
    case WS_Rain:
    case WS_Snow:
        return static_cast<qreal>(qrand() % 80 + 1) / 10 + 2;   // 2.1 - 10.0
    case WS_Showers:
    case WS_IceRain:
        return static_cast<qreal>(qrand() % 100 + 1) / 10 + 5;  // 5.1 - 15.0
    case WS_Storm:
    case WS_Hail:
    case WS_SnowStorm:
        return static_cast<qreal>(qrand() % 100 + 1) / 10 + 10; // 10.1 - 20.0
    default:
        return static_cast<qreal>(qrand() % 150 + 1) / 10;      // 0.1 - 15.0
    }
}

} // namespace

RandomWeatherService::RandomWeatherService()
    : WeatherService()
{
    qsrand(static_cast<unsigned>(time(static_cast<time_t>(0))));
    qrand();
    qrand();
}

void RandomWeatherService::acquireWeather(Location *loc)
{
    if (!loc)
        return;
    loc->clearWeatherData();

    const int MaxDays = 30;

    qreal latitude = loc->locationInfo().latitude();

    qreal seed = randomTemperature(latitude);
    QDate today = QDate::currentDate();

    for (int i = 0; i < MaxDays; ++i) {
        Weather w;
        w.setTemperature(randomPredictionalTemperature(latitude, seed));
        w.setPressure(randomPressure());
        w.setHumidity(randomHumidity(w.pressure()));
        w.setState(randomWeatherState(w.temperature(), w.pressure(), w.humidity()));
        w.setWindSpeed(randomWindSpeed(w.state()));
        w.setWindDirection(randomWindDirectionDegrees());

        loc->addWeather(today.addDays(i), w);

        seed = w.temperature();
    }
}

RandomWeatherService::~RandomWeatherService() { }

} // namespace WeatherStation
