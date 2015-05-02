#include <QDataStream>
#include <qmath.h>
#include "locationinfo.h"

namespace WeatherStation {

const qreal LATITUDE_MIN = -90;
const qreal LATITUDE_MAX = 90;
const qreal LONGITUDE_MIN = -180;
const qreal LONGITUDE_MAX = 180;

LocationInfo::LocationInfo()
    : m_description(),
      m_latitude(0.0),
      m_longitude(0.0)
{ }
LocationInfo::~LocationInfo()
{ }

LocationInfo::LocationInfo(const LocationInfo &other)
    : m_description(other.m_description),
      m_latitude(other.m_latitude),
      m_longitude(other.m_longitude)
{ }

LocationInfo &LocationInfo::operator =(const LocationInfo &other)
{
    m_description = other.m_description;
    m_latitude = other.m_latitude;
    m_longitude = other.m_longitude;

    return *this;
}

QString LocationInfo::description() const
{ return m_description; }
void LocationInfo::setDescription(const QString &value)
{ m_description = value; }

qreal LocationInfo::latitude() const
{ return m_latitude; }
void LocationInfo::setLatitude(qreal value)
{ m_latitude = qBound(LATITUDE_MIN, value, LATITUDE_MAX); }

qreal LocationInfo::longitude() const
{ return m_longitude; }
void LocationInfo::setLongitude(qreal value)
{ m_longitude = qBound(LONGITUDE_MIN, value, LONGITUDE_MAX); }


QDataStream &operator >>(QDataStream &stream, LocationInfo &locationInfo)
{
    QString d;
    qreal lg;
    qreal lt;

    stream >> d >> lg >> lt;

    locationInfo.setDescription(d);
    locationInfo.setLongitude(lg);
    locationInfo.setLatitude(lt);

    return stream;
}

QDataStream &operator <<(QDataStream &stream, const LocationInfo &locatioInfo)
{
    return stream << locatioInfo.description()
           << locatioInfo.longitude()
           << locatioInfo.latitude();
}

bool operator ==(const LocationInfo &a, const LocationInfo &b)
{
    return  a.description() == b.description()
            && static_cast<int>(qFloor(a.longitude() * 1E+4)) == static_cast<int>(qFloor(b.longitude() * 1E+4))
            && static_cast<int>(qFloor(a.latitude() * 1E+4)) == static_cast<int>(qFloor(b.latitude() * 1E+4));
}

bool operator !=(const LocationInfo &a, const LocationInfo &b)
{
    return !(a == b);
}

} // namespace WeatherStation
