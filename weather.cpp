#include <QDataStream>
#include "weather.h"


namespace WeatherStation {

Weather::Weather()
    : temperature(0.0), pressure(0.0), humidity(0), windDirection(0), windSpeed(0), state(WS_NonAvailable)
{

}

Weather::Weather(const Weather &weather)
    :temperature(weather.temperature), pressure(weather.pressure),
     humidity(weather.humidity), windDirection(weather.windDirection),
     windSpeed(weather.windSpeed), state(weather.state)
{

}

Weather Weather::operator =(const Weather &weather)
{
    temperature = weather.temperature;
    pressure = weather.pressure;
    humidity = weather.humidity;
    windDirection = weather.windDirection;
    windSpeed = weather.windSpeed;
    state = weather.state;

    return *this;
}

Weather::~Weather()
{

}


qreal Weather::Temperature() const
{
    return temperature;
}

void Weather::setTemperature(const qreal &value)
{
    temperature = value;
}
qreal Weather::Pressure() const
{
    return pressure;
}

void Weather::setPressure(const qreal &value)
{
    pressure = value;
}
int Weather::Humidity() const
{
    return humidity;
}

void Weather::setHumidity(int value)
{
    humidity = value;
}
int Weather::WindDirection() const
{
    return windDirection;
}

void Weather::setWindDirection(int value)
{
    windDirection = value;
}
int Weather::WindSpeed() const
{
    return windSpeed;
}

void Weather::setWindSpeed(int value)
{
    windSpeed = value;
}
WeatherState Weather::State() const
{
    return state;
}

void Weather::setState(const WeatherState &value)
{
    state = value;
}

QDataStream &operator >>(QDataStream &stream, Weather &weather)
{
    int h;
    qreal p;
    int s;
    qreal t;
    int wd;
    int ws;

    stream >> h >> p >> s >> t >> wd >> ws;

    weather.setHumidity(h);
    weather.setPressure(p);
    weather.setState(static_cast<WeatherState>(s));
    weather.setTemperature(t);
    weather.setWindDirection(wd);
    weather.setWindSpeed(ws);

    return stream;
}

QDataStream &operator <<(QDataStream &stream, const Weather &weather)
{
    return stream << weather.Humidity()
           << weather.Pressure()
           << static_cast<int>(weather.State())
           << weather.Temperature()
           << weather.WindDirection()
           << weather.WindSpeed();
}

bool operator ==(const Weather &weatherOne, const Weather &weatherTwo)
{
    if( weatherOne.Humidity() == weatherTwo.Humidity()
        && weatherOne.Pressure() == weatherTwo.Pressure()
        && weatherOne.State() == weatherTwo.State()
        && weatherOne.Temperature() == weatherTwo.Temperature()
        && weatherOne.WindDirection() == weatherTwo.WindDirection()
        && weatherOne.WindSpeed() == weatherTwo.WindSpeed())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator !=(const Weather &weatherOne, const Weather &weatherTwo)
{
      return !(weatherOne == weatherTwo);
}

} // namespace WeatherStation
