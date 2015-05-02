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
    m_weatherData[date] = weather;
}

Weather Location::weather(const QDate &date)
{
    // Что возвращать, если такая дата не найдена?
    return m_weatherData[date];
}

void Location::clearWeatherData()
{

}

void Location::readDataFrom(const QDataStream &stream)
{

}

void Location::writeDataTo(QDataStream &stream)
{

}


} // namespace WeatherStation
