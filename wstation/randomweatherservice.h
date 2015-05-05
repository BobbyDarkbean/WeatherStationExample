#ifndef RANDOMWEATHERSERVICE_H
#define RANDOMWEATHERSERVICE_H

#include "weatherservice.h"

namespace WeatherStation {

class RandomWeatherService : public WeatherService
{
public:
    RandomWeatherService();
    void acquireWeather(Location *);
    ~RandomWeatherService();

private:
    Q_DISABLE_COPY(RandomWeatherService)
};

} // namespace WeatherStation

#endif // RANDOMWEATHERSERVICE_H
