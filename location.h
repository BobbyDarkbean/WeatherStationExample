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

    LocationInfo locationInfo() const;
    void setLocationInfo(const LocationInfo &locationInfo);

    void addWeather(const QDate &, const Weather &);
    Weather weather(const QDate &);
    void clearWeatherData();

    void readDataFrom(const QDataStream &);
    void writeDataTo(QDataStream &);

private:
    Q_DISABLE_COPY(Location)

    LocationInfo m_locationInfo;
    QMap<QDate, Weather> m_weatherData;

};

} // namespace WeatherStation

#endif // LOCATION_H
