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
    // load images for WeatherWidget from .qrc
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
