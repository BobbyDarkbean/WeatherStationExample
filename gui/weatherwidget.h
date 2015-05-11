#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <QWidget>
#include <QLabel>
#include "weather.h"
#include "wsgui_shared.h"

namespace WeatherStation {

class LocationPool;
//class MeasurementOptions;
class ImageLoader;

class WS_GUI_SHARED WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = 0);
    virtual ~WeatherWidget();

    const LocationPool *locationPool() const;

private:
    Q_DISABLE_COPY(WeatherWidget)

    //void drawWeather(Weather, MeasurementOptions);

    const LocationPool *m_locationPool;
    ImageLoader *m_imageLoader;

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
