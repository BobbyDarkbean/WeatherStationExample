#ifndef WEATHERAPPLICATION_H
#define WEATHERAPPLICATION_H

#include <QApplication>

namespace WeatherStation {

class LocationPool;

class WeatherApplication : public QApplication
{
    Q_OBJECT

public:
    WeatherApplication(int argc, char **argv);
    virtual ~WeatherApplication();

    LocationPool *locationPool() const;

private:
    Q_DISABLE_COPY(WeatherApplication)

    void setupLanguage(const QString &lcode);

    void loadImages();

    void loadData();
    void saveData();

    LocationPool *m_locationPool;
};

} // namespace WeatherStation

#define wsApp qobject_cast< ::WeatherStation::WeatherApplication *>(qApp)

#endif // WEATHERAPPLICATION_H
