#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDate>
#include "unitinfo.h"
#include "wsgui_shared.h"

class QFrame;

namespace WeatherStation {

class LocationPool;
class ImageLoader;

class WS_GUI_SHARED WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = 0);
    virtual ~WeatherWidget();

    const LocationPool *locationPool() const;
    void setLocationPool(const LocationPool *);

    ImageLoader *imageLoader() const;
    void setImageLoader(ImageLoader *);

    const UnitInfo &unitInfo() const;

public slots:
    void applySelectedLocation(int index);
    void applySelectedDate(const QDate &);

private:
    Q_DISABLE_COPY(WeatherWidget)

    void drawWeather();

    QFrame *frmMain;

    const LocationPool *m_locationPool;
    ImageLoader *m_imageLoader;
    UnitInfo m_unitInfo;
    int m_cacheIndex;
    QDate m_cacheDate;

    QLabel *lblWeatherStateImg;
    QLabel *lblWeatherStateVal;
    QLabel *lblTemperatureImg;
    QLabel *lblTemperatureVal;
    QLabel *lblPressureImg;
    QLabel *lblPressure;
    QLabel *lblPressureVal;
    QLabel *lblHumidityImg;
    QLabel *lblHumidity;
    QLabel *lblHumidityVal;
    QLabel *lblWind;
    QLabel *lblWindDirVal;
    QLabel *lblWindSpeedVal;
};

} // namespace WeatherStation

#endif // WEATHERWIDGET_H
