#ifndef WEATHER_HELPER_H
#define WEATHER_HELPER_H

#include <QString>
#include "kernel_shared.h"
#include "weather_global.h"

namespace WeatherStation {

WS_KERNEL_SHARED qreal fahrenheitTemperature(qreal celcius);
WS_KERNEL_SHARED qreal millibarPressure(qreal mmHg);

WS_KERNEL_SHARED WindDirection windDirection(int degrees);

WS_KERNEL_SHARED QString weatherStateStr(WeatherState ws);
WS_KERNEL_SHARED QString windDirectionStr(WindDirection wd);
WS_KERNEL_SHARED QString temperatureUnitStr(TemperatureUnit tu);
WS_KERNEL_SHARED QString pressureUnitStr(PressureUnit pu);

WS_KERNEL_SHARED QString latitudeStr(qreal latitude);
WS_KERNEL_SHARED QString longitudeStr(qreal longitude);

} // namespace WeatherStation

#endif // WEATHER_HELPER_H
