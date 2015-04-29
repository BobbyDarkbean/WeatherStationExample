#include <QObject>
#include "weather_helper.h"

namespace WeatherStation {

qreal fahrenheitTemperature(qreal celcius)
{
    return celcius * 1.8 + 32;
}

qreal millibarPressure(qreal mmHg)
{
    return mmHg * 1.3332199208;
}

WindDirection windDirection(int degrees)
{
    return WindDirection(((degrees + 22) / 45) % WD_COUNT);
}

QString weatherStateStr(WeatherState ws)
{
    switch (ws) {
    case WS_Clear:          return QObject::tr("Clear");
    case WS_PartlyCloudy:   return QObject::tr("Partly cloudy");
    case WS_Clouds:         return QObject::tr("Clouds");
    case WS_Rain:           return QObject::tr("Rain");
    case WS_Showers:        return QObject::tr("Showers");
    case WS_Storm:          return QObject::tr("Storm");
    case WS_IceRain:        return QObject::tr("Ice rain");
    case WS_Hail:           return QObject::tr("Hail");
    case WS_Snow:           return QObject::tr("Snow");
    case WS_SnowStorm:      return QObject::tr("Snow storm");
    case WS_Fog:            return QObject::tr("Fog");
    default:                return QObject::tr("N/A");
    }
}

QString windDirectionStr(WindDirection wd)
{
    switch (wd) {
    case WD_North:          return QObject::tr("N");
    case WD_NorthEast:      return QObject::tr("NE");
    case WD_East:           return QObject::tr("E");
    case WD_SouthEast:      return QObject::tr("SE");
    case WD_South:          return QObject::tr("S");
    case WD_SouthWest:      return QObject::tr("SW");
    case WD_West:           return QObject::tr("W");
    case WD_NorthWest:      return QObject::tr("NW");
    default:                return QObject::tr("n/a");
    }
}

QString temperatureUnitStr(TemperatureUnit tu)
{
    switch (tu) {
    case TU_Celcius:        return QString("%1C").arg(QChar(0xb0));
    case TU_Fahrenheit:     return QString("F");
    default:                return QObject::tr("n/a");
    }
}

QString pressureUnitStr(PressureUnit pu)
{
    switch (pu) {
    case PU_MmHg:           return QObject::tr("mm Hg");
    case PU_Mbar:           return QObject::tr("mbar");
    default:                return QObject::tr("n/a");
    }
}

} // WeatherStation
