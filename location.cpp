#include <QDataStream>
#include "location.h"

namespace WeatherStation {

Location::Location()
    : m_locationInfo(),
      m_weatherData()
{ }

Location::~Location()
{ }

LocationInfo Location::locationInfo() const
{ return m_locationInfo; }
void Location::setLocationInfo(const LocationInfo &locationInfo)
{ m_locationInfo = locationInfo; }

void Location::addWeather(const QDate &date, const Weather &weather)
{ m_weatherData.insert(date, weather); }

Weather Location::weather(const QDate &date)
{ return m_weatherData.value(date, Weather()); }

void Location::clearWeatherData()
{ m_weatherData.clear(); }

void Location::readDataFrom(QDataStream &stream)
{
    m_weatherData.clear();

    int size;
    QDate date;
    Weather weather;

    stream >> m_locationInfo >> size;
    for (int i = 0; i < size; ++i)
    {
        stream >> date >> weather;
        m_weatherData.insert(date, weather);
    }
}

void Location::writeDataTo(QDataStream &stream)
{
    stream << m_locationInfo << m_weatherData.size();

    QMap<QDate, Weather>::ConstIterator end = m_weatherData.end();
    for (QMap<QDate, Weather>::ConstIterator itr = m_weatherData.begin(); itr != end; ++itr)
    {
        stream << itr.key() << itr.value();
    }
}

} // namespace WeatherStation
