#include <QLabel>
#include <QBoxLayout>
#include "imageloader.h"
#include "location.h"
#include "locationselector.h"
#include "weather.h"
#include "weather_helper.h"
#include "weatherwidget.h"

namespace WeatherStation {

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget(parent),
      frmMain(new QFrame),
      lblWeatherStateImg(new QLabel),
      lblWeatherStateVal(new QLabel),
      lblTemperatureImg(new QLabel),
      lblTemperatureVal(new QLabel),
      lblPressureImg(new QLabel),
      lblPressure(new QLabel),
      lblPressureVal(new QLabel),
      lblHumidityImg(new QLabel),
      lblHumidity(new QLabel),
      lblHumidityVal(new QLabel),
      lblWind(new QLabel),
      lblWindDirVal(new QLabel),
      lblWindSpeedVal(new QLabel),
      m_locationPool(0),
      m_imageLoader(0),
      m_unitInfo(),
      m_cacheIndex(LocationSelector::NoSelection),
      m_cacheDate(QDate::currentDate())

{
    lblPressure->setText(tr("Pressure"));
    lblHumidity->setText(tr("Humidity"));
    lblWind->setText(tr("Wind"));

    QBoxLayout *weatherStateLayout = new QVBoxLayout;
    weatherStateLayout->addWidget(lblWeatherStateImg);
    weatherStateLayout->addWidget(lblWeatherStateVal);

    QBoxLayout *temperatureLayout = new QHBoxLayout;
    temperatureLayout->addWidget(lblTemperatureImg);
    temperatureLayout->addWidget(lblTemperatureVal);

    QBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(weatherStateLayout);
    leftLayout->addLayout(temperatureLayout);

    QBoxLayout *pressureLayout = new QHBoxLayout;
    pressureLayout->addWidget(lblPressureImg);
    pressureLayout->addWidget(lblPressure);
    pressureLayout->addWidget(lblPressureVal);

    QBoxLayout *humidityLayout = new QHBoxLayout;
    humidityLayout->addWidget(lblHumidityImg);
    humidityLayout->addWidget(lblHumidity);
    humidityLayout->addWidget(lblHumidityVal);

    QBoxLayout *windLayout = new QHBoxLayout;
    windLayout->addWidget(lblWind);
    windLayout->addWidget(lblWindDirVal);
    windLayout->addWidget(lblWindSpeedVal);

    QBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addLayout(pressureLayout);
    rightLayout->addLayout(humidityLayout);
    rightLayout->addLayout(windLayout);
    rightLayout->addStretch();

    QBoxLayout *mainLayout = new QHBoxLayout(frmMain);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    QBoxLayout *widgetLayout = new QVBoxLayout(this);
    widgetLayout->addWidget(frmMain);
}

WeatherWidget::~WeatherWidget() { }

const LocationPool *WeatherWidget::locationPool() const
{ return m_locationPool; }
void WeatherWidget::setLocationPool(const LocationPool *locationPool)
{ m_locationPool = locationPool; }

ImageLoader *WeatherWidget::imageLoader() const
{ return m_imageLoader; }
void WeatherWidget::setImageLoader(ImageLoader *imageLoader)
{ m_imageLoader = imageLoader; }

const UnitInfo &WeatherWidget::unitInfo() const
{ return m_unitInfo; }

void WeatherWidget::applySelectedLocation(int index)
{
    if (!m_locationPool || index == m_cacheIndex)
        return;

    m_cacheIndex = index;
    drawWeather();
}

void WeatherWidget::applySelectedDate(const QDate &date)
{
    if (!m_locationPool || date == m_cacheDate)
        return;

    m_cacheDate = date;
    drawWeather();
}

void WeatherWidget::drawWeather()
{
    Location *location = m_locationPool->location(m_cacheIndex);
    Weather weather = location ? location->weather(m_cacheDate) : Weather();

    lblWeatherStateVal->setText(weatherStateStr(weather.state()));
    lblTemperatureVal->setText(QString("%1 %2")
                        .arg(QString::number(weather.temperature(), 'f', 1))
                        .arg(temperatureUnitStr(m_unitInfo.tUnit())));
    lblPressureVal->setText(QString("%1 %2")
                        .arg(QString::number(weather.pressure(), 'f', 1))
                        .arg(pressureUnitStr(m_unitInfo.pUnit())));
    lblHumidityVal->setText(QString("%1\%").arg(QString::number(weather.humidity(), 'f', 1)));
    lblWindDirVal->setText(windDirectionStr(windDirection(weather.windDirection())));
    lblWindSpeedVal->setText(QString::number(weather.windSpeed()));
}

} // namespace WeatherStation
