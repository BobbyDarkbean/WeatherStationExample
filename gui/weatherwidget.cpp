#include <QBoxLayout>
#include "imageloader.h"
#include "weatherwidget.h"
#include "weather_helper.h"

namespace WeatherStation {

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget(parent),
      m_locationPool(0),
      m_imageLoader(new ImageLoader),
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
      lblWindSpeedVal(new QLabel)
{
    lblPressure->setText(QString("%1: ").arg(tr("Pressure")));
    lblHumidity->setText(QString("%1: ").arg(tr("Humidity")));
    lblWind->setText(QString("%1: ").arg(tr("Wind")));

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

    QBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
}

WeatherWidget::~WeatherWidget() { }

const LocationPool *WeatherWidget::locationPool() const
{ return m_locationPool; }

//void WeatherWidget::drawWeather(Weather weather, MeasurementOptions)
//{
//    lblWeatherStateVal->setText(weatherStateStr(weather.state()));
//    lblTemperatureVal->setText(QString::number(weather.temperature()));
//    lblHumidityVal->setText(QString::number(weather.humidity()));
//    lblWindDirVal->setText(QString::number(weather.windDirection()));
//    lblWindSpeedVal->setText(QString::number(weather.windSpeed()));
//}

} // namespace WeatherStation
