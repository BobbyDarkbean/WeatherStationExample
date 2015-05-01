#include "location.h"

namespace WeatherStation {

Location::Location()
{

}

Location::~Location()
{

}

LocationInfo Location::locationInfo() const
{ return m_locationInfo; }
void Location::setLocationInfo(const LocationInfo &locationInfo)
{ m_locationInfo = locationInfo; }

Location::addWeather(const QDate &, const Weather &)
{

}

Location::weather(const QDate &)
{

}

Location::clearWeatherData()
{

}

Location::readDataFrom(const QDataStream &)
{

}

Location::writeDataTo(QDataStream &)
{

}


} // namespace WeatherStation
