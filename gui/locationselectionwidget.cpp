#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QBoxLayout>
#include "weather_helper.h"
#include "locationinfo.h"
#include "locationselectionwidget.h"

namespace WeatherStation {

LocationSelectionWidget::LocationSelectionWidget(QWidget *parent)
    : QWidget(parent),
      lblLocation(new QLabel),
      cmbLocation(new QComboBox),
      grbCoordinates(new QGroupBox),
      lblLatitude(new QLabel),
      lblLongitude(new QLabel)
{
    lblLocation->setText(QString("%1: ").arg(tr("Location")));
    lblLocation->setBuddy(cmbLocation);

    grbCoordinates->setTitle(tr("Coordinates"));

    QBoxLayout *locationLayout = new QHBoxLayout;
    locationLayout->addWidget(lblLocation);
    locationLayout->addWidget(cmbLocation);

    QBoxLayout *coordinatesOutputLayout = new QHBoxLayout(grbCoordinates);
    coordinatesOutputLayout->addStretch();
    coordinatesOutputLayout->addWidget(lblLatitude);
    coordinatesOutputLayout->addStretch();
    coordinatesOutputLayout->addWidget(lblLongitude);
    coordinatesOutputLayout->addStretch();

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(locationLayout);
    mainLayout->addWidget(grbCoordinates);
    mainLayout->addStretch();

    connect(cmbLocation, SIGNAL(currentIndexChanged(int)), this, SIGNAL(locationIndexSelected(int)));
}

LocationSelectionWidget::~LocationSelectionWidget() { }

int LocationSelectionWidget::selectedLocationIndex() const
{ return cmbLocation->currentIndex(); }

void LocationSelectionWidget::setSelectedLocationIndex(int index)
{ cmbLocation->setCurrentIndex(index); }

void LocationSelectionWidget::setSelectedLocationInfo(const LocationInfo &locationInfo)
{
    lblLatitude->setText(latitudeStr(locationInfo.latitude()));
    lblLongitude->setText(longitudeStr(locationInfo.longitude()));
}

void LocationSelectionWidget::applyLocationAdded(const LocationInfo &locationInfo)
{ cmbLocation->addItem(locationInfo.description()); }

void LocationSelectionWidget::applyLocationEdited(int index, const LocationInfo &locationInfo)
{
    cmbLocation->setItemText(index, locationInfo.description());
    if (cmbLocation->currentIndex() == index)
        emit locationIndexSelected(index);
}

void LocationSelectionWidget::applyLocationRemoved(int index)
{
    int selected = cmbLocation->currentIndex();
    cmbLocation->removeItem(index);
    if (selected == index)
    {
        selected = index < (cmbLocation->count()) ? index : (cmbLocation->count() - 1);
        cmbLocation->setCurrentIndex(selected);
    }
}

} // namespace WeatherStation
