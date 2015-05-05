#ifndef UNITINFO_H
#define UNITINFO_H

#include "kernel_shared.h"
#include "weather_global.h"

namespace WeatherStation {

class UnitInfo
{
public:
    UnitInfo();
    virtual ~UnitInfo();

    UnitInfo(const UnitInfo &);
    UnitInfo &operator =(const UnitInfo &);

    TemperatureUnit tUnit() const;
    void setTUnit(TemperatureUnit);

    PressureUnit pUnit() const;
    void setPUnit(PressureUnit);

private:
    TemperatureUnit m_tu;
    PressureUnit m_pu;
};

bool operator ==(const UnitInfo &, const UnitInfo &);
bool operator !=(const UnitInfo &, const UnitInfo &);

} // namespace WeatherStation

#endif // UNITINFO_H
