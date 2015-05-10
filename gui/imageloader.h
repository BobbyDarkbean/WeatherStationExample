#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QPixmap>
#include <QHash>
#include "wsgui_shared.h"
#include "weather_global.h"

namespace WeatherStation {

class WS_GUI_SHARED ImageLoader
{
public:
    ImageLoader();
    virtual ~ImageLoader();

    QPixmap weatherImage(WeatherState state);
    const QPixmap &pressureImage();
    const QPixmap &humidityImage();
    const QPixmap &hotTemperatureImage();
    const QPixmap &coldTemperatureImage();

    void registerWeatherImage(WeatherState state, const QString &filename);
    void registerPressureImage(const QString &filename);
    void registerHumidityImage(const QString &filename);
    void registerHotTemperatureImage(const QString &filename);
    void registerColdTemperatureImage(const QString &filename);

private:
    Q_DISABLE_COPY(ImageLoader)

    QHash<int, QPixmap> m_weatherImgMap;
    QPixmap m_pressureImg;
    QPixmap m_humidityImg;
    QPixmap m_hotTemperatureImg;
    QPixmap m_coldTemperatureImg;
    const QPixmap m_defaultImg;
};

} // namespace WeatherStation

#endif // IMAGELOADER_H
