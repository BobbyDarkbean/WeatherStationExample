#include "unitinfo.h"

namespace WeatherStation {

UnitInfo::UnitInfo()
    : m_tu(TU_Celcius),
      m_pu(PU_MmHg)
{ }

UnitInfo::~UnitInfo() { }

UnitInfo::UnitInfo(const UnitInfo &other)
    : m_tu(other.m_tu),
      m_pu(other.m_pu)
{ }

UnitInfo &UnitInfo::operator=(const UnitInfo &other)
{
    m_tu = other.m_tu;
    m_pu = other.m_pu;

    return *this;
}

TemperatureUnit UnitInfo::tUnit() const
{ return m_tu; }
void UnitInfo::setTUnit(TemperatureUnit tu)
{ m_tu = tu; }

PressureUnit UnitInfo::pUnit() const
{ return m_pu; }
void UnitInfo::setPUnit(PressureUnit pu)
{ m_pu = pu; }

bool operator==(const UnitInfo &a, const UnitInfo &b)
{
    return a.tUnit() == b.tUnit() && a.pUnit() == b.pUnit();
}

bool operator!=(const UnitInfo &a, const UnitInfo &b)
{
    return !(a == b);
}

} // namespace WeatherStation
