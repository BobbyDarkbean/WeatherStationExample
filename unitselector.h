#ifndef UNITSELECTOR_H
#define UNITSELECTOR_H

#include <QObject>
#include "unitinfo.h"

namespace WeatherStation {

class UnitSelector : public QObject
{
    Q_OBJECT

public:
    explicit UnitSelector(QObject *parent = 0);
    virtual ~UnitSelector();

    UnitInfo unitInfo() const;
    void setUnitInfo(const UnitInfo &unitInfo);

    TemperatureUnit temperatureUnit() const;
    PressureUnit pressureUnit() const;

public slots:
    void setTemperatureUnit(TemperatureUnit);
    void setPressureUnit(PressureUnit);

signals:
    void temperatureUnitChanged(TemperatureUnit);
    void pressureUnitChanged(PressureUnit);

private:
    Q_DISABLE_COPY(UnitSelector)

    UnitInfo m_unitInfo;
};

} // namespace WeatherStation

#endif // UNITSELECTOR_H
