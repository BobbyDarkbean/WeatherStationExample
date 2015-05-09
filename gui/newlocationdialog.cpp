#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <qmath.h>
#include "newlocationdialog.h"
#include "weather_helper.h"

namespace WeatherStation {

NewLocationDialog::NewLocationDialog(QWidget *parent)
    : QDialog(parent),
      frmDescription(new QFrame),
      lblDescription(new QLabel),
      edtDescription(new QLineEdit),
      grbCoordinates(new QGroupBox),
      lblLatitude(new QLabel),
      sldLatitude(new QSlider),
      spbLatitude(new QDoubleSpinBox),
      lblLongitude(new QLabel),
      sldLongitude(new QSlider),
      spbLongitude(new QDoubleSpinBox),
      lblOutputLatitude(new QLabel),
      lblOutputLongitude(new QLabel),
      frmButtons(new QFrame),
      btnOk(new QPushButton),
      btnCancel(new QPushButton)
{
    adjustComponents();
    initializeLayout();
    establishConnections();
}

NewLocationDialog::~NewLocationDialog() { }

LocationInfo NewLocationDialog::locationInfo() const
{
    LocationInfo locInfo;

    locInfo.setDescription(edtDescription->text());
    locInfo.setLatitude(spbLatitude->value());
    locInfo.setLongitude(spbLongitude->value());

    return locInfo;
}

void NewLocationDialog::applySpinLatitude(int lat)
{
    if (static_cast<int>(qFloor(spbLatitude->value())) != lat)
        spbLatitude->setValue(lat);
}

void NewLocationDialog::applySliderLatitude(double lat)
{ sldLatitude->setValue(static_cast<int>(qFloor(lat))); }

void NewLocationDialog::applySpinLongitude(int lon)
{
    if (static_cast<int>(qFloor(spbLongitude->value())) != lon)
        spbLongitude->setValue(lon);
}

void NewLocationDialog::applySliderLongitude(double lon)
{ sldLongitude->setValue(static_cast<int>(qFloor(lon))); }

void NewLocationDialog::applyLatitudeOutput(double lat)
{ lblOutputLatitude->setText(latitudeStr(lat)); }

void NewLocationDialog::applyLongitudeOutput(double lon)
{ lblOutputLongitude->setText(longitudeStr(lon)); }

void NewLocationDialog::adjustComponents()
{
    frmDescription->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    lblDescription->setText(QString("%1: ").arg(tr("Description")));
    lblDescription->setBuddy(edtDescription);
    edtDescription->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    grbCoordinates->setTitle(tr("Coordinates"));

    lblLatitude->setText(QString("%1: ").arg(tr("Latitude")));
    sldLatitude->setOrientation(Qt::Horizontal);
    sldLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);
    sldLatitude->setTickPosition(QSlider::TicksBelow);
    sldLatitude->setTickInterval(45);
    sldLatitude->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    sldLatitude->setValue(0);
    spbLatitude->setDecimals(3);
    spbLatitude->setSingleStep(0.001);
    spbLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);
    spbLatitude->setAccelerated(true);
    spbLatitude->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    spbLatitude->setAlignment(Qt::AlignRight);
    spbLatitude->setValue(0.0);

    lblLongitude->setText(QString("%1: ").arg(tr("Longitude")));
    sldLongitude->setOrientation(Qt::Horizontal);
    sldLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);
    sldLongitude->setTickPosition(QSlider::TicksBelow);
    sldLongitude->setTickInterval(45);
    sldLongitude->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    sldLongitude->setValue(0);
    spbLongitude->setDecimals(3);
    spbLongitude->setSingleStep(0.001);
    spbLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);
    spbLongitude->setAccelerated(true);
    spbLongitude->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    spbLongitude->setAlignment(Qt::AlignRight);
    spbLongitude->setValue(0.0);

    frmButtons->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    btnOk->setText(tr("OK"));
    btnCancel->setText(tr("Cancel"));

    applyLatitudeOutput(0.0);
    applyLongitudeOutput(0.0);
}

void NewLocationDialog::initializeLayout()
{
    QBoxLayout *descriptionLayout = new QHBoxLayout(frmDescription);
    descriptionLayout->addWidget(lblDescription);
    descriptionLayout->addWidget(edtDescription);

    QBoxLayout *labelLayout = new QVBoxLayout;
    labelLayout->addWidget(lblLatitude);
    labelLayout->addWidget(lblLongitude);

    QBoxLayout *sliderLayout = new QVBoxLayout;
    sliderLayout->addWidget(sldLatitude);
    sliderLayout->addWidget(sldLongitude);

    QBoxLayout *spinBoxLayout = new QVBoxLayout;
    spinBoxLayout->addWidget(spbLatitude);
    spinBoxLayout->addWidget(spbLongitude);

    QBoxLayout *coordsInputLayout = new QHBoxLayout;
    coordsInputLayout->addLayout(labelLayout);
    coordsInputLayout->addLayout(sliderLayout);
    coordsInputLayout->addLayout(spinBoxLayout);

    QBoxLayout *coordsOutputLayout = new QHBoxLayout;
    coordsOutputLayout->addStretch();
    coordsOutputLayout->addWidget(lblOutputLatitude);
    coordsOutputLayout->addWidget(lblOutputLongitude);
    coordsOutputLayout->addStretch();

    QBoxLayout *coordinatesLayout = new QVBoxLayout(grbCoordinates);
    coordinatesLayout->addLayout(coordsInputLayout);
    coordinatesLayout->addStretch();
    coordinatesLayout->addLayout(coordsOutputLayout);

    QBoxLayout *buttonLayout = new QHBoxLayout(frmButtons);
    buttonLayout->addStretch();
    buttonLayout->addWidget(btnOk);
    buttonLayout->addWidget(btnCancel);

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(frmDescription);
    mainLayout->addWidget(grbCoordinates);
    mainLayout->addWidget(frmButtons);
}

void NewLocationDialog::establishConnections()
{
    connect(spbLatitude, SIGNAL(valueChanged(double)), this, SLOT(applySliderLatitude(double)));
    connect(spbLatitude, SIGNAL(valueChanged(double)), this, SLOT(applyLatitudeOutput(double)));
    connect(sldLatitude, SIGNAL(valueChanged(int)), this, SLOT(applySpinLatitude(int)));

    connect(spbLongitude, SIGNAL(valueChanged(double)), this, SLOT(applySliderLongitude(double)));
    connect(spbLongitude, SIGNAL(valueChanged(double)), this, SLOT(applyLongitudeOutput(double)));
    connect(sldLongitude, SIGNAL(valueChanged(int)), this, SLOT(applySpinLongitude(int)));

    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

} // namespace WeatherStation
