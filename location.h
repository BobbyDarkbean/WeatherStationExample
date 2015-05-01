#ifndef LOCATION_H
#define LOCATION_H

#include <QMap>
#include <QDate>
//#include <qobjectdefs.h> //почему не ругается на Q_DISABLE_COPY(Location)?

#include "weather.h"
#include "locationinfo.h"

namespace WeatherStation {

class Location
{
public:
    Location();
    virtual ~Location();

    Q_DISABLE_COPY(Location)

    LocationInfo locationInfo() const;
    void setLocationInfo(const LocationInfo &locationInfo);

    addWeather(const QDate &, const Weather &);
    weather(const QDate &);
    clearWeatherData();

    readDataFrom(const QDataStream &);
    writeDataTo(QDataStream &);

private:
    LocationInfo m_locationInfo;
    QMap<QDate, Weather> m_weatherData;

};

} // namespace WeatherStation

#endif // LOCATION_H
