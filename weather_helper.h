#ifndef WEATHER_HELPER_H
#define WEATHER_HELPER_H

#include <QString>
#include "weather_global.h"

namespace WeatherStation {

QString weatherStateStr(WeatherState ws);
QString windDirectionStr(WindDirection wd);
QString temperatureUnitStr(TemperatureUnit tu);
QString pressureUnitStr(PressureUnit pu);

} // namespace WeatherStation

#endif // WEATHER_HELPER_H
