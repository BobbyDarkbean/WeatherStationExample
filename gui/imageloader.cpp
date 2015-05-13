#include "imageloader.h"

namespace WeatherStation {

ImageLoader::ImageLoader()
    : m_weatherImgMap(),
      m_pressureImg(),
      m_humidityImg(),
      m_hotTemperatureImg(),
      m_coldTemperatureImg(),
      m_defaultImg() { }

ImageLoader::~ImageLoader() { }

QPixmap ImageLoader::weatherImage(WeatherState state) const
{ return m_weatherImgMap.value(state, m_defaultImg); }

const QPixmap &ImageLoader::pressureImage() const
{ return m_pressureImg; }

const QPixmap &ImageLoader::humidityImage() const
{ return m_humidityImg; }

const QPixmap &ImageLoader::hotTemperatureImage() const
{ return m_hotTemperatureImg; }

const QPixmap &ImageLoader::coldTemperatureImage() const
{ return m_coldTemperatureImg; }

void ImageLoader::registerWeatherImage(WeatherState state, const QString &filename)
{ m_weatherImgMap[state].load(filename, "png"); }

void ImageLoader::registerPressureImage(const QString &filename)
{ m_pressureImg.load(filename, "png"); }

void ImageLoader::registerHumidityImage(const QString &filename)
{ m_humidityImg.load(filename, "png"); }

void ImageLoader::registerHotTemperatureImage(const QString &filename)
{ m_hotTemperatureImg.load(filename, "png"); }

void ImageLoader::registerColdTemperatureImage(const QString &filename)
{ m_coldTemperatureImg.load(filename, "png"); }

} // namespace WeatherStation
