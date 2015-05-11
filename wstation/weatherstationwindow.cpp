#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>
#include "locationpool.h"
#include "locationselector.h"
#include "newlocationdialog.h"
#include "locationselectionwidget.h"
#include "weatherapplication.h"
#include "weatherstationwindow.h"

namespace WeatherStation {

WeatherStationWindow::WeatherStationWindow(QWidget *parent)
    : QMainWindow(parent),
      actNewLocation(0),
      actEditLocation(0),
      actRemoveLocation(0),
      mnuLocation(0),
      mnuWindows(0),
      wdgtLocSelect(0),
      dckLocSelect(0),
      m_locationSelector(0)
{
    createMenus();
    createWidgets();
    createDocks();
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
    connect(actNewLocation, SIGNAL(triggered()), this, SLOT(newLocation()));

    actEditLocation = new QAction(this);
    actEditLocation->setText(QString("%1...").arg(tr("&Edit location")));
    mnuLocation->addAction(actEditLocation);
    connect(actEditLocation, SIGNAL(triggered()), this, SLOT(editLocation()));

    actRemoveLocation = new QAction(this);
    actRemoveLocation->setText(QString("%1...").arg(tr("&Remove location")));
    mnuLocation->addAction(actRemoveLocation);
    connect(actRemoveLocation, SIGNAL(triggered()), this, SLOT(removeLocation()));

    mnuWindows = new QMenu(this);
    mnuWindows->setTitle(tr("&Windows"));
    menuBar()->addMenu(mnuWindows);
}

void WeatherStationWindow::createWidgets()
{
    const LocationPool *locationPool = wsApp->locationPool();

    m_locationSelector = new LocationSelector(this);
    m_locationSelector->setLocationPool(locationPool);

    wdgtLocSelect = new LocationSelectionWidget(this);
    for (int i = 0; i < locationPool->count(); ++i)
        wdgtLocSelect->applyLocationAdded(locationPool->location(i)->locationInfo());

    connect(locationPool, SIGNAL(locationAdded(LocationInfo)),
            wdgtLocSelect, SLOT(applyLocationAdded(LocationInfo)));
    connect(locationPool, SIGNAL(locationEdited(int, LocationInfo)),
            wdgtLocSelect, SLOT(applyLocationEdited(int, LocationInfo)));
    connect(locationPool, SIGNAL(locationRemoved(int)),
            wdgtLocSelect, SLOT(applyLocationRemoved(int)));

    connect(m_locationSelector, SIGNAL(selectedLocationChanged(int)),
            wdgtLocSelect, SLOT(setSelectedLocationIndex(int)));
    connect(m_locationSelector, SIGNAL(selectedLocationChanged(LocationInfo)),
            wdgtLocSelect, SLOT(setSelectedLocationInfo(LocationInfo)));
    connect(wdgtLocSelect, SIGNAL(locationIndexSelected(int)),
            m_locationSelector, SLOT(setCurrentIndex(int)));

    m_locationSelector->setCurrentIndex(0);
}

void WeatherStationWindow::createDocks()
{
    dckLocSelect = new QDockWidget(this);
    dckLocSelect->setWindowTitle(tr("Location selection"));
    dckLocSelect->setWidget(wdgtLocSelect);
    addDockWidget(Qt::LeftDockWidgetArea, dckLocSelect);

    mnuWindows->addAction(dckLocSelect->toggleViewAction());
}

} // namespace WeatherStation
