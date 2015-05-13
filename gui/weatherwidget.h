#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QDate>
#include "unitinfo.h"
#include "wsgui_shared.h"

class QFrame;
class QLabel;

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

    const ImageLoader *imageLoader() const;
    void setImageLoader(const ImageLoader *);

    const UnitInfo &unitInfo() const;

public slots:
    void applySelectedLocation(int index);
    void applySelectedDate(const QDate &);

private:
    Q_DISABLE_COPY(WeatherWidget)

    void drawWeather();

    QFrame *frmMain;
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

    const LocationPool *m_locationPool;
    const ImageLoader *m_imageLoader;
    UnitInfo m_unitInfo;
    int m_cacheIndex;
    QDate m_cacheDate;
};

} // namespace WeatherStation

#endif // WEATHERWIDGET_H
