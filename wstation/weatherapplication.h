#ifndef WEATHERAPPLICATION_H
#define WEATHERAPPLICATION_H

#include <QApplication>
#include "imageloader.h"

namespace WeatherStation {

class LocationPool;
class WeatherService;

class WeatherApplication : public QApplication
{
    Q_OBJECT

public:
    WeatherApplication(int argc, char **argv);
    virtual ~WeatherApplication();

    LocationPool *locationPool() const;
    WeatherService *weatherService() const;

    const ImageLoader *imageLoader() const;

private:
    Q_DISABLE_COPY(WeatherApplication)

    void setupLanguage(const QString &lcode);

    void loadImages();

    void loadData();
    void saveData();

    LocationPool *m_locationPool;
    WeatherService *m_weatherService;

    ImageLoader m_imageLoader;
};

} // namespace WeatherStation

#define wsApp qobject_cast< ::WeatherStation::WeatherApplication *>(qApp)

#endif // WEATHERAPPLICATION_H
