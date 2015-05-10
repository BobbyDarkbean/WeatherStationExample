#include <QMenu>
#include <QMenuBar>
#include "locationpool.h"
#include "newlocationdialog.h"
#include "weatherapplication.h"
#include "weatherstationwindow.h"

namespace WeatherStation {

WeatherStationWindow::WeatherStationWindow(QWidget *parent)
    : QMainWindow(parent),
      actNewLocation(0),
      actEditLocation(0),
      actRemoveLocation(0),
      mnuLocation(0)
{
    createMenus();

    connect(actNewLocation, SIGNAL(triggered()), this, SLOT(newLocation()));
    connect(actEditLocation, SIGNAL(triggered()), this, SLOT(editLocation()));
    connect(actRemoveLocation, SIGNAL(triggered()), this, SLOT(removeLocation()));
}

WeatherStationWindow::~WeatherStationWindow() { }

void WeatherStationWindow::newLocation()
{
    NewLocationDialog dialog(this);
    if (dialog.exec()) {
        wsApp->locationPool()->addLocation(dialog.locationInfo());
    }
}

void WeatherStationWindow::editLocation() { }

void WeatherStationWindow::removeLocation() { }

void WeatherStationWindow::createMenus()
{
    mnuLocation = new QMenu(this);
    mnuLocation->setTitle(tr("&Location"));
    menuBar()->addMenu(mnuLocation);

    actNewLocation = new QAction(this);
    actNewLocation->setText(QString("%1...").arg(tr("&New location")));
    mnuLocation->addAction(actNewLocation);

    actEditLocation = new QAction(this);
    actEditLocation->setText(QString("%1...").arg(tr("&Edit location")));
    mnuLocation->addAction(actEditLocation);

    actRemoveLocation = new QAction(this);
    actRemoveLocation->setText(QString("%1...").arg(tr("&Remove location")));
    mnuLocation->addAction(actRemoveLocation);
}

} // namespace WeatherStation
