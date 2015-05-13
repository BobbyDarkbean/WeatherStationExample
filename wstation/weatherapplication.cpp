#include "locationpool.h"
#include "randomweatherservice.h"
#include "weatherapplication.h"

namespace WeatherStation {

WeatherApplication::WeatherApplication(int argc, char **argv)
    : QApplication(argc, argv),
      m_locationPool(new LocationPool),
      m_weatherService(new RandomWeatherService),
      m_imageLoader()
{
    m_locationPool->setParent(this);
    m_locationPool->setWeatherService(m_weatherService);

    loadImages();
    loadData();

    setupLanguage("eng");

    if (!m_locationPool->count()) {
        LocationInfo defaultLocation;
        defaultLocation.setDescription(tr("Default location"));

        m_locationPool->addLocation(defaultLocation);
    }
}

WeatherApplication::~WeatherApplication()
{
    saveData();

    if (m_weatherService)
        delete m_weatherService;
}

LocationPool *WeatherApplication::locationPool() const
{ return m_locationPool; }

WeatherService *WeatherApplication::weatherService() const
{ return m_weatherService; }

const ImageLoader *WeatherApplication::imageLoader() const
{ return &m_imageLoader; }

void WeatherApplication::setupLanguage(const QString &/*lcode*/)
{
    // QTranslator processing

    setApplicationDisplayName(tr("Weather station"));
}

void WeatherApplication::loadImages()
{
    m_imageLoader.registerWeatherImage(WS_NonAvailable, ":/images/na.png");
    m_imageLoader.registerWeatherImage(WS_Clear, ":/images/sunny.png");
    m_imageLoader.registerWeatherImage(WS_PartlyCloudy, ":/images/pcloudy.png");
    m_imageLoader.registerWeatherImage(WS_Clouds, ":/images/cloudy.png");
    m_imageLoader.registerWeatherImage(WS_Rain, ":/images/rain.png");
    m_imageLoader.registerWeatherImage(WS_Showers, ":/images/showers.png");
    m_imageLoader.registerWeatherImage(WS_Storm, ":/images/storm.png");
    m_imageLoader.registerWeatherImage(WS_IceRain, ":/images/icerain.png");
    m_imageLoader.registerWeatherImage(WS_Hail, ":/images/hail.png");
    m_imageLoader.registerWeatherImage(WS_Snow, ":/images/snow.png");
    m_imageLoader.registerWeatherImage(WS_SnowStorm, ":/images/snowstorm.png");
    m_imageLoader.registerWeatherImage(WS_Fog, ":/images/fog.png");

    m_imageLoader.registerColdTemperatureImage(":/images/cold.png");
    m_imageLoader.registerHotTemperatureImage(":/images/hot.png");
    m_imageLoader.registerPressureImage(":/images/pressure.png");
    m_imageLoader.registerHumidityImage(":/images/humidity.png");
}

void WeatherApplication::loadData()
{
    // load list of location
}

void WeatherApplication::saveData()
{
    // save list of location
}

} // namespace WeatherStation
