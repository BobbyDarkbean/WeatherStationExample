#include "location.h"
#include "randomweatherservice.h"

namespace WeatherStation {

namespace {

qreal randomTemperature(qreal latitude)
{
    if (!(latitude > 20.0)) {
        return qreal(qrand() % 350) / 10 + 10;      // +10.0 - +44.9
    } else if (20.0 < latitude && !(latitude > 35.0)) {
        return qreal(qrand() % 400) / 10 + 5;       // +5.0 - +44.9
    } else if (35.0 < latitude && !(latitude > 45.0)) {
        return qreal(qrand() % 350) / 10 + 5;       // +5.0 - +39.9
    } else if (45.0 < latitude && !(latitude > 52.5)) {
        return qreal(qrand() % 450) / 10 - 5;       // -5.0 - +39.9
    } else if (52.5 < latitude && !(latitude > 60.0)) {
        return qreal(qrand() % 600) / 10 - 20;      // -20.0 - +39.9
    } else if (60.0 < latitude && !(latitude > 75.0)) {
        return qreal(qrand() % 600) / 10 - 40;      // -40.0 - +19.9
    } else {
        return qreal(qrand() % 800) / 10 - 75;      // -75.0 - +4.9
    }
}

qreal randomPredictionalTemperature(qreal seed, int days)
{
    int ext = qMin(50, qMax(days, 0) * 2);
    return qBound(-75.0,
                  qreal(qrand() % (100 + ext * 2) - ext) / 10 + seed - 5,
                  45.0);
}

qreal randomPressure()
{
    return qreal(qrand() % 800) / 10 + 711;
}

int randomHumidity(qreal pressure)
{
    if (pressure < 740.0) {
        return qrand() % 30 + 71;                   // 71% - 100%
    } else if (!(pressure < 740.0) && pressure < 750.0) {
        return qrand() % 40 + 61;                   // 61% - 100%
    } else if (!(pressure < 750.0) && pressure < 760.0) {
        return qrand() % 60 + 41;                   // 41% - 100%
    } else if (!(pressure < 760.0) && pressure < 770.0) {
        return qrand() % 90 + 1;                    // 1% - 90%
    } else {
        return qrand() % 50 + 1;                    // 1% - 50%
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
        return qreal(qrand() % 50 + 1) / 10;        // 0.1 - 5.0
    case WS_Rain:
    case WS_Snow:
        return qreal(qrand() % 80 + 1) / 10 + 2;    // 2.1 - 10.0
    case WS_Showers:
    case WS_IceRain:
        return qreal(qrand() % 80 + 1) / 10 + 7;    // 7.1 - 15.0
    case WS_Storm:
    case WS_Hail:
    case WS_SnowStorm:
        return qreal(qrand() % 80 + 1) / 10 + 12;   // 12.1 - 20.0
    default:
        return qreal(qrand() % 150 + 1) / 10;       // 0.1 - 15.0
    }
}

} // namespace

RandomWeatherService::RandomWeatherService() :
    WeatherService() { }

void RandomWeatherService::acquireWeather(Location *loc)
{
    if (!loc)
        return;
    loc->clearWeatherData();

    const int MaxDays = 30;

    qreal seed = randomTemperature(loc->locationInfo().latitude());
    QDate today = QDate::currentDate();

    for (int i = 0; i < MaxDays; ++i) {
        Weather w;
        w.setTemperature(randomPredictionalTemperature(seed, i));
        w.setPressure(randomPressure());
        w.setHumidity(randomHumidity(w.pressure()));
        w.setState(randomWeatherState(w.temperature(), w.pressure(), w.humidity()));
        w.setWindSpeed(randomWindSpeed(w.state()));
        w.setWindDirection(randomWindDirectionDegrees());

        loc->addWeather(today.addDays(i), w);

        /*seed = temp;*/
    }
}

RandomWeatherService::~RandomWeatherService() { }

} // namespace WeatherStation
