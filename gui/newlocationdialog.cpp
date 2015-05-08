#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <qmath.h>
#include "locationinfo.h"
#include "newlocationdialog.h"

namespace WeatherStation {

NewLocationDialog::NewLocationDialog(QWidget *parent)
    : QDialog(parent),
      lblDescription(new QLabel),
      edtDescription(new QLineEdit),
      grbCoordinates(new QGroupBox),
      lblLatitude(new QLabel),
      sldLatitude(new QSlider),
      spbLatitude(new QDoubleSpinBox),
      lblLongitude(new QLabel),
      sldLongitude(new QSlider),
      spbLongitude(new QDoubleSpinBox),
      btnOk(new QPushButton),
      btnCancel(new QPushButton),
      lblOutputLatitude(new QLabel),
      lblOutputLongitude(new QLabel)

{
    initializeLayout();
    establishConnections();
}

NewLocationDialog::~NewLocationDialog() { }

void NewLocationDialog::applySpinLatitude(int lat)
{
    if (static_cast<int>(qFloor(spbLatitude->value())) != lat)
        spbLatitude->setValue(lat);
}

void NewLocationDialog::applySliderLatitude(double lat)
{
    sldLatitude->setValue(static_cast<int>(qFloor(lat)));
}

void NewLocationDialog::applySpinLongitude(int lon)
{
    if (static_cast<int>(qFloor(spbLongitude->value())) != lon)
        spbLongitude->setValue(lon);
}

void NewLocationDialog::applySliderLongitude(double lon)
{
    sldLongitude->setValue(static_cast<int>(qFloor(lon)));
}

void NewLocationDialog::initializeLayout()
{
    lblDescription->setText(QString("%1: ").arg(tr("Description")));
    lblDescription->setBuddy(edtDescription);

    lblLatitude->setText(QString("%1: ").arg(tr("Latitude")));
    sldLatitude->setOrientation(Qt::Horizontal);
    sldLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);
    spbLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);

    lblLongitude->setText(QString("%1: ").arg(tr("Longitude")));
    sldLongitude->setOrientation(Qt::Horizontal);
    sldLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);
    spbLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);

    btnOk->setText(tr("OK"));
    btnCancel->setText(tr("Cancel"));

    grbCoordinates->setTitle(tr("Coordinates"));

    QBoxLayout *descriptionLayout = new QHBoxLayout;
    descriptionLayout->addWidget(lblDescription);
    descriptionLayout->addWidget(edtDescription);

    QBoxLayout *latitudeLayout = new QHBoxLayout;
    latitudeLayout->addWidget(lblLatitude);
    latitudeLayout->addWidget(sldLatitude);
    latitudeLayout->addWidget(spbLatitude);

    QBoxLayout *longitudeLayout = new QHBoxLayout;
    longitudeLayout->addWidget(lblLongitude);
    longitudeLayout->addWidget(sldLongitude);
    longitudeLayout->addWidget(spbLongitude);

    QBoxLayout *coordsOutputLayout = new QHBoxLayout;
    coordsOutputLayout->addStretch();
    coordsOutputLayout->addWidget(lblOutputLatitude);
    coordsOutputLayout->addWidget(lblLongitude);
    coordsOutputLayout->addStretch();

    QBoxLayout *coordinatesLayout = new QVBoxLayout(grbCoordinates);
    coordinatesLayout->addLayout(latitudeLayout);
    coordinatesLayout->addLayout(longitudeLayout);
    coordinatesLayout->addLayout(coordsOutputLayout);

    QBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(btnOk);
    buttonLayout->addWidget(btnCancel);

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(descriptionLayout);
    mainLayout->addWidget(grbCoordinates);
    mainLayout->addLayout(buttonLayout);
}

void NewLocationDialog::establishConnections()
{
    connect(spbLatitude, SIGNAL(valueChanged(double)), this, SLOT(applySliderLatitude(double)));
    connect(sldLatitude, SIGNAL(valueChanged(int)), this, SLOT(applySpinLatitude(int)));
    connect(spbLongitude, SIGNAL(valueChanged(double)), this, SLOT(applySliderLongitude(double)));
    connect(sldLongitude, SIGNAL(valueChanged(int)), this, SLOT(applySpinLongitude(int)));

    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

} // namespace WeatherStation
