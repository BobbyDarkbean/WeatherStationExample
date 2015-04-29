#include "weather.h"

namespace WeatherStation {

Weather::Weather()
{

}

Weather::~Weather()
{

}


qreal Weather::getTemperature() const
{
    return temperature;
}

void Weather::setTemperature(const qreal &value)
{
    temperature = value;
}

} // namespace WeatherStation
