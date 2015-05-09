#include "locationpool.h"
#include "weatherapplication.h"

namespace WeatherStation {

WeatherApplication::WeatherApplication(int argc, char **argv)
    : QApplication(argc, argv),
      m_locationPool(new LocationPool)
{
    m_locationPool->setParent(this);

    loadImages();
    loadData();

    setupLanguage("eng");
}

WeatherApplication::~WeatherApplication()
{
    saveData();
}

LocationPool *WeatherApplication::locationPool() const
{ return m_locationPool; }

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
