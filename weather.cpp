#include <QDataStream>
#include <qmath.h>
#include "weather.h"

namespace WeatherStation {

const qreal TEMPERATURE_MIN = -273.3;
const qreal PRESSURE_MIN = 0.0;
const int HUMIDITY_MIN = 0;
const int HUMIDITY_MAX = 100;
const int WIND_DIRECTION_MIN = 0;
const int WIND_DIRECTION_MAX = 359;
const qreal WIND_SPEED_MIN = 0.0;

Weather::Weather()
    : m_temperature(0.0),
      m_pressure(0.0),
      m_humidity(0),
      m_windDirection(0),
      m_windSpeed(0.0),
      m_state(WS_NonAvailable)
{ }
Weather::~Weather()
{ }

Weather::Weather(const Weather &other)
    : m_temperature(other.m_temperature),
      m_pressure(other.m_pressure),
      m_humidity(other.m_humidity),
      m_windDirection(other.m_windDirection),
      m_windSpeed(other.m_windSpeed),
      m_state(other.m_state)
{ }

Weather &Weather::operator =(const Weather &other)
{
    m_temperature = other.m_temperature;
    m_pressure = other.m_pressure;
    m_humidity = other.m_humidity;
    m_windDirection = other.m_windDirection;
    m_windSpeed = other.m_windSpeed;
    m_state = other.m_state;

    return *this;
}

qreal Weather::temperature() const
{ return m_temperature; }
void Weather::setTemperature(qreal value)
{ m_temperature = qMax(value, TEMPERATURE_MIN); }

qreal Weather::pressure() const
{ return m_pressure; }
void Weather::setPressure(qreal value)
{ m_pressure = qMax(value, PRESSURE_MIN); }

int Weather::humidity() const
{ return m_humidity; }
void Weather::setHumidity(int value)
{ m_humidity = qBound(HUMIDITY_MIN, value, HUMIDITY_MAX); }

int Weather::windDirection() const
{ return m_windDirection; }
void Weather::setWindDirection(int value)
{ m_windDirection = qBound(WIND_DIRECTION_MIN, value, WIND_DIRECTION_MAX); }

qreal Weather::windSpeed() const
{ return m_windSpeed; }
void Weather::setWindSpeed(qreal value)
{ m_windSpeed = qMax(value, WIND_SPEED_MIN); }

WeatherState Weather::state() const
{ return m_state; }
void Weather::setState(WeatherState value)
{ m_state = value; }

QDataStream &operator >>(QDataStream &stream, Weather &weather)
{
    qreal t;
    qreal p;
    int h;
    int wd;
    int ws;
    int s;

    stream >> t >> p >> h >> wd >> ws >> s;

    weather.setTemperature(t);
    weather.setPressure(p);
    weather.setHumidity(h);
    weather.setWindDirection(wd);
    weather.setWindSpeed(ws);
    weather.setState(static_cast<WeatherState>(s));

    return stream;
}

QDataStream &operator <<(QDataStream &stream, const Weather &weather)
{
    return stream << weather.temperature()
           << weather.pressure()
           << weather.humidity()
           << weather.windDirection()
           << weather.windSpeed()
           << static_cast<int>(weather.state());
}

bool operator ==(const Weather &a, const Weather &b)
{
    return  static_cast<int>(qFloor(a.temperature()) * 10) == static_cast<int>(qFloor(b.temperature()) * 10)
            && static_cast<int>(qFloor(a.pressure()) * 10) == static_cast<int>(qFloor(b.pressure()) * 10)
            && a.humidity() == b.humidity()
            && a.windDirection() == b.windDirection()
            && static_cast<int>(qFloor(a.windSpeed()) * 10) == static_cast<int>(qFloor(b.windSpeed()) * 10)
            && a.state() == b.state();

}

bool operator !=(const Weather &a, const Weather &b)
{
    return !(a == b);
}

} // namespace WeatherStation
