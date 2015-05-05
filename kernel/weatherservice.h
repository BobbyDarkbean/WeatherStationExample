#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include "kernel_shared.h"
#include "weather_global.h"

namespace WeatherStation {

class Location;
class WS_KERNEL_SHARED WeatherService
{
public:
    WeatherService();
    virtual void acquireWeather(Location *) = 0;
    virtual ~WeatherService() = 0;

private:
    Q_DISABLE_COPY(WeatherService)
};

} // namespace WeatherStation

#endif // WEATHERSERVICE_H
