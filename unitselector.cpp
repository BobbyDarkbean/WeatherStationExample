#include "unitselector.h"

namespace WeatherStation {

UnitSelector::UnitSelector(QObject *parent)
    : QObject(parent),
      m_unitInfo()
{ }

UnitSelector::~UnitSelector()
{ }

UnitInfo UnitSelector::unitInfo() const
{ return m_unitInfo; }

void UnitSelector::setUnitInfo(const UnitInfo &unitInfo)
{
    if (m_unitInfo == unitInfo)
        return;

    m_unitInfo = unitInfo;
    emit temperatureUnitChanged(m_unitInfo.tUnit());
    emit pressureUnitChanged(m_unitInfo.pUnit());
}

TemperatureUnit UnitSelector::temperatureUnit() const
{ return m_unitInfo.tUnit(); }

PressureUnit UnitSelector::pressureUnit() const
{ return m_unitInfo.pUnit(); }

void UnitSelector::setTemperatureUnit(TemperatureUnit tu)
{
    if (temperatureUnit() == tu)
        return;

    m_unitInfo.setTUnit(tu);
    emit temperatureUnitChanged(m_unitInfo.tUnit());
}

void UnitSelector::setPressureUnit(PressureUnit pu)
{
    if (pressureUnit() == pu)
        return;

    m_unitInfo.setPUnit(pu);
    emit pressureUnitChanged(m_unitInfo.pUnit());
}

} // namespace WeatherStation
