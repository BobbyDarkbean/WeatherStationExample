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
{
    //m_weatherData[date] = weather;
    m_weatherData.insert(date, weather);
}

Weather Location::weather(const QDate &date)
{
    //return m_weatherData.value(date);
    return m_weatherData.value(date, Weather());
}

void Location::clearWeatherData()
{ m_weatherData.clear(); }

//void Location::readDataFrom(QDataStream &stream)
//{
//    size_t size;
//    m_weatherData.clear();

//    stream >> m_locationInfo >> size;
//    for(size_t i=0; i<size; ++i)
//    {
//        stream >> m_weatherData;
//    }
//}

void Location::readDataFrom(QDataStream &stream)
{
    size_t size;
    QDate date;
    Weather weather;
    m_weatherData.clear();

    stream >> m_locationInfo >> size;
    for(size_t i=0; i<size; ++i)
    {
        stream >> date << weather;
        m_weatherData.insert(date, weather);
    }
}

void Location::writeDataTo(QDataStream &stream)
{
    stream << m_locationInfo << m_weatherData.size();

//    QMap<QDate, Weather>::const_iterator i = m_weatherData.constBegin();
//    while (i != m_weatherData.constEnd()) {
//        stream << i.key() << i.value();
//        ++i;
//    }

//    QMap<QDate, Weather>::const_iterator i = m_weatherData.constBegin();
//    for (; i != m_weatherData.constEnd(); ++i) {
//        stream << i.key() << i.value();
//    }

    QMap<QDate, Weather>::const_iterator i;
    for (i = m_weatherData.constBegin(); i != m_weatherData.constEnd(); ++i) {
        stream << i.key() << i.value();
    }

}


} // namespace WeatherStation
