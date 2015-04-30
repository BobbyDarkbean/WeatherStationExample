#ifndef WEATHER_H
#define WEATHER_H

#include <qobjectdefs.h>
#include "weather_global.h"

namespace WeatherStation {

class Weather
{
public:
    Weather();
    virtual ~Weather();

    Weather(const Weather &weather);

    Weather operator =(const Weather &weather);

    qreal Temperature() const;
    void setTemperature(const qreal &value);

    qreal Pressure() const;
    void setPressure(const qreal &value);

    int Humidity() const;
    void setHumidity(int value);

    int WindDirection() const;
    void setWindDirection(int value);

    int WindSpeed() const;
    void setWindSpeed(int value);

    WeatherState State() const;
    void setState(const WeatherState &value);

private:
    qreal temperature;
    qreal pressure;
    int humidity;
    int windDirection;
    int windSpeed;
    WeatherState state;
};

QDataStream &operator >>(QDataStream &stream, Weather &weather);
QDataStream &operator <<(QDataStream &stream, const Weather &weather);
bool operator ==(const Weather &weatherOne, const Weather &weatherTwo);
bool operator !=(const Weather &weatherOne, const Weather &weatherTwo);

} // namespace WeatherStation

#endif // WEATHER_H
