#ifndef LOCATIONINFO_H
#define LOCATIONINFO_H

#include "kernel_shared.h"

namespace WeatherStation {

class LocationInfo
{
public:
    LocationInfo();
    virtual ~LocationInfo();

    LocationInfo(const LocationInfo &);
    LocationInfo &operator =(const LocationInfo &);

    QString description() const;
    void setDescription(const QString &);

    qreal latitude() const;
    void setLatitude(qreal);

    qreal longitude() const;
    void setLongitude(qreal);

private:
    QString m_description;
    qreal m_latitude;
    qreal m_longitude;

};

QDataStream &operator >>(QDataStream &, LocationInfo &);
QDataStream &operator <<(QDataStream &, const LocationInfo &);
bool operator ==(const LocationInfo &, const LocationInfo &);
bool operator !=(const LocationInfo &, const LocationInfo &);

} // namespace WeatherStation

#endif // LOCATIONINFO_H
