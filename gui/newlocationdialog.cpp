#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QBoxLayout>
#include "locationinfo.h"
#include "newlocationdialog.h"

namespace WeatherStation {

NewLocationDialog::NewLocationDialog(QWidget *parent)
    : QDialog(parent),
      lblDescription(new QLabel),
      edtDescription(new QLineEdit),
      lblLatitude(new QLabel),
      sldLatitude(new QSlider),
      spbLatitude(new QSpinBox),
      lblLongitude(new QLabel),
      sldLongitude(new QSlider),
      spbLongitude(new QSpinBox),
      btnOk(new QPushButton),
      btnCancel(new QPushButton)
{ initializeLayout(); }

NewLocationDialog::~NewLocationDialog() { }

void NewLocationDialog::initializeLayout()
{
    lblDescription->setText(tr("Description: "));
    lblDescription->setBuddy(edtDescription);

    lblLatitude->setText(tr("Latitude: "));
    sldLatitude->setOrientation(Qt::Horizontal);
    sldLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);
    spbLatitude->setRange(LATITUDE_MIN, LATITUDE_MAX);

    lblLongitude->setText(tr("Longitude: "));
    sldLongitude->setOrientation(Qt::Horizontal);
    sldLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);
    spbLongitude->setRange(LONGITUDE_MIN, LONGITUDE_MAX);

    btnOk->setText(tr("OK"));
    btnCancel->setText(tr("Cancel"));

    QBoxLayout *hltDescription = new QHBoxLayout;
    hltDescription->addWidget(lblDescription);
    hltDescription->addWidget(edtDescription);

    QBoxLayout *hltLatitude = new QHBoxLayout;
    hltLatitude->addWidget(lblLatitude);
    hltLatitude->addWidget(sldLatitude);
    hltLatitude->addWidget(spbLatitude);

    QBoxLayout *hltLongitude = new QHBoxLayout;
    hltLongitude->addWidget(lblLongitude);
    hltLongitude->addWidget(sldLongitude);
    hltLongitude->addWidget(spbLongitude);

    QBoxLayout *hltButton = new QHBoxLayout;
    hltButton->addStretch();
    hltButton->addWidget(btnOk);
    hltButton->addWidget(btnCancel);

    QBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(hltDescription);
    mainLayout->addLayout(hltLatitude);
    mainLayout->addLayout(hltLongitude);
    mainLayout->addLayout(hltButton);
}

} // namespace WeatherStation
