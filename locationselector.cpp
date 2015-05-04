#include "locationselector.h"

namespace WeatherStation{

const int LocationSelector::NoSelection = -1;

LocationSelector::LocationSelector(QObject *parent)
    : QObject(parent),
      m_currentIndex(NoSelection),
      m_currentDate(),
      m_locationPool(0)
{ }

LocationSelector::~LocationSelector()
{ }

const Location *LocationSelector::currentLocation() const
{
    //if (!m_locationPool)

    return m_locationPool->location(m_currentIndex);
}

int LocationSelector::currentIndex() const
{ return m_currentIndex; }

QDate LocationSelector::currentDate() const
{ return m_currentDate; }


const LocationPool *LocationSelector::locationPool() const
{ return m_locationPool; }
void LocationSelector::setLocationPool(const LocationPool *locationPool)
{
    if (!locationPool)
        return;

    m_locationPool = locationPool;
}

void LocationSelector::setCurrentIndex(int cur_index)
{
    if (!m_locationPool)
        return;

    if (m_currentIndex == cur_index)
        return;

    if (cur_index <= NoSelection || cur_index >= m_locationPool->count())
        return;

    m_currentIndex = cur_index;
    emit selectedLocationChanged(m_currentIndex);
}

void LocationSelector::setCurrentDate(const QDate &date)
{
    if(!m_locationPool)
        return;

    if (m_currentDate == date)
        return;

//    const Location *location = currentLocation();
//    if (!location || location->weather(date) == Weather())
//        return;

    m_currentDate = date;
    emit selectedDateChanged(m_currentDate);
}

} // namespace WeatherStation



