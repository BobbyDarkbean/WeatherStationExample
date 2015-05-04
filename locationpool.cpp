#include <QDataStream>
#include "locationpool.h"

namespace WeatherStation{

LocationPool::LocationPool(QObject *parent)
    : QObject(parent),
      m_weatherService(0),
      m_locations()
{ }

LocationPool::~LocationPool()
{
    QList<Location *>::Iterator end = m_locations.end();
    for (QList<Location *>::Iterator itr = m_locations.begin(); itr != end; ++itr)
    {
        delete *itr;
    }
}

WeatherService *LocationPool::weatherService() const
{ return m_weatherService; }

void LocationPool::setWeatherService(WeatherService *weatherService)
{ m_weatherService = weatherService; }

Location *LocationPool::location(int index) const
{
    if (0 <= index && index < m_locations.size())
        return m_locations.at(index);

    return 0;
}

int LocationPool::count() const
{ return m_locations.size(); }

void LocationPool::addLocation(const LocationInfo &locationInfo)
{
    Location *location = new Location;
    location->setLocationInfo(locationInfo);

    if (m_weatherService)
        m_weatherService->acquireWeather(location);

    m_locations.append(location);
    emit locationAdded(locationInfo);
}

void LocationPool::editLocation(int index, const LocationInfo &locationInfo)
{
    if (!(0 <= index && index < m_locations.size()))
        return;

    Location *location = m_locations.at(index);

    if (location->locationInfo() == locationInfo)
        return;

    location->setLocationInfo(locationInfo);

    if (m_weatherService)
        m_weatherService->acquireWeather(location);

    emit locationEdited(index, locationInfo);
}

void LocationPool::removeLocation(int index)
{
    if (!(0 <= index && index < m_locations.size()))
        return;

    delete m_locations.takeAt(index);
    emit locationRemoved(index);
}

void LocationPool::readDataFrom(QDataStream &stream)
{
    while (!m_locations.isEmpty())
        delete m_locations.takeFirst();

    int size;
    stream >> size;

    for (int i = 0; i < size; ++i)
    {
        Location *location = new Location;
        location->readDataFrom(stream);
        m_locations.append(location);
    }
}

void LocationPool::writeDataTo(QDataStream &stream)
{
    stream << m_locations.size();

    QList<Location *>::ConstIterator end = m_locations.end();
    for (QList<Location *>::ConstIterator itr = m_locations.begin(); itr != end; ++itr)
    {
        (*itr)->writeDataTo(stream);
    }
}

} // namespace WeatherStation
