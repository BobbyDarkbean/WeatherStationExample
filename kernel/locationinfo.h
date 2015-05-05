#ifndef LOCATIONINFO_H
#define LOCATIONINFO_H

#include "kernel_shared.h"

namespace WeatherStation {

class WS_KERNEL_SHARED LocationInfo
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

WS_KERNEL_SHARED QDataStream &operator >>(QDataStream &, LocationInfo &);
WS_KERNEL_SHARED QDataStream &operator <<(QDataStream &, const LocationInfo &);
WS_KERNEL_SHARED bool operator ==(const LocationInfo &, const LocationInfo &);
WS_KERNEL_SHARED bool operator !=(const LocationInfo &, const LocationInfo &);

} // namespace WeatherStation

#endif // LOCATIONINFO_H
