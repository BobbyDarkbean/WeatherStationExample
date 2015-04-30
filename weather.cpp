#include <QDataStream>
#include "weather.h"

namespace WeatherStation {

const qreal TEMPERATURE_MIN = -273.3;
const qreal PRESSURE_MIN = 0.0;
const int HUMDITY_MIN = 0;
const int HUMDITY_MAX = 100;
const int WINDDIRECTION_MIN = 0;
const int WINDDIRECTION_MAX = 359;
const qreal WINDSPEED_MIN = 0.0;

Weather::Weather()
    : m_temperature(0.0),
      m_pressure(0.0),
      m_humidity(0),
      m_windDirection(0),
      m_windSpeed(0),
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
void Weather::setTemperature(const qreal value)
{ m_temperature = qMax(value, TEMPERATURE_MIN); }

qreal Weather::pressure() const
{ return m_pressure; }
void Weather::setPressure(const qreal value)
{ m_pressure = qMax(value, PRESSURE_MIN); }

int Weather::humidity() const
{ return m_humidity; }
void Weather::setHumidity(int value)
{ m_humidity = qBound(HUMDITY_MIN, value, HUMDITY_MAX); }

int Weather::windDirection() const
{ return m_windDirection; }
void Weather::setWindDirection(int value)
{ m_windDirection = qBound(WINDDIRECTION_MIN, value, WINDDIRECTION_MAX); }

qreal Weather::windSpeed() const
{ return m_windSpeed; }
void Weather::setWindSpeed(qreal value)
{ m_windSpeed = qMax(value, WINDSPEED_MIN); }

WeatherState Weather::state() const
{ return m_state; }
void Weather::setState(const WeatherState &value)
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
    return  static_cast<int>(a.temperature() * 10) == static_cast<int>(b.temperature() * 10)
            && static_cast<int>(a.pressure() * 10) == static_cast<int>(b.pressure() * 10)
            && a.humidity() == b.humidity()
            && a.windDirection() == b.windDirection()
            && static_cast<int>(a.windSpeed() * 10) == static_cast<int>(b.windSpeed() * 10)
            && a.state() == b.state();

}

bool operator !=(const Weather &a, const Weather &b)
{
      return !(a == b);
}

} // namespace WeatherStation
