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

    Weather(const Weather &);
    Weather &operator =(const Weather &);

    qreal temperature() const;
    void setTemperature(qreal);

    qreal pressure() const;
    void setPressure(qreal);

    int humidity() const;
    void setHumidity(int);

    int windDirection() const;
    void setWindDirection(int);

    qreal windSpeed() const;
    void setWindSpeed(qreal);

    WeatherState state() const;
    void setState(WeatherState);

private:
    qreal m_temperature;
    qreal m_pressure;
    int m_humidity;
    int m_windDirection;
    qreal m_windSpeed;
    WeatherState m_state;
};

QDataStream &operator >>(QDataStream &, Weather &);
QDataStream &operator <<(QDataStream &, const Weather &);
bool operator ==(const Weather &, const Weather &);
bool operator !=(const Weather &, const Weather &);

} // namespace WeatherStation

#endif // WEATHER_H
