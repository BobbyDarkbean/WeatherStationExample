#ifndef WEATHER_H
#define WEATHER_H
#include <qobjectdefs.h>

namespace WeatherStation {

class Weather
{
public:
    Weather();
    ~Weather();
    qreal getTemperature() const;
    void setTemperature(const qreal &value);

private:
    qreal temperature;
};

} // namespace WeatherStation

#endif // WEATHER_H
