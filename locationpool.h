#ifndef LOCATIONPOOL_H
#define LOCATIONPOOL_H

#include <QObject>
#include "weatherservice.h"
#include "location.h"

namespace WeatherStation{

class LocationPool : public QObject
{
    Q_OBJECT

public:
    explicit LocationPool(QObject *parent = 0);
    virtual ~LocationPool();

    WeatherService *weatherService() const;
    void setWeatherService(WeatherService *);

    Location *location(int index) const;
    int count() const;

    void addLocation(const LocationInfo &);
    void editLocation(int index, const LocationInfo &);
    void removeLocation(int index);

    void readDataFrom(QDataStream &);
    void writeDataTo(QDataStream &);

signals:
    void locationAdded(const LocationInfo &);
    void locationEdited(int index, const LocationInfo &);
    void locationRemoved(int index);

private:
    Q_DISABLE_COPY(LocationPool)

    WeatherService *m_weatherService;
    QList<Location *> m_locations;
};

} // namespace WeatherStation

#endif // LOCATIONPOOL_H

