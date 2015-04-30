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

    Weather(const Weather &other);
    Weather &operator =(const Weather &other);

    qreal temperature() const;
    void setTemperature(const qreal value);

    qreal pressure() const;
    void setPressure(const qreal value);

    int humidity() const;
    void setHumidity(int value);

    int windDirection() const;
    void setWindDirection(int value);

    qreal windSpeed() const;
    void setWindSpeed(qreal value);

    WeatherState state() const;
    void setState(const WeatherState &value);

private:
    qreal m_temperature;
    qreal m_pressure;
    int m_humidity;
    int m_windDirection;
    qreal m_windSpeed;
    WeatherState m_state;
};

QDataStream &operator >>(QDataStream &stream, Weather &weather);
QDataStream &operator <<(QDataStream &stream, const Weather &weather);
bool operator ==(const Weather &a, const Weather &b);
bool operator !=(const Weather &a, const Weather &b);

} // namespace WeatherStation

#endif // WEATHER_H
