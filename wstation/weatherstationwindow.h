#ifndef WEATHERSTATIONWINDOW_H
#define WEATHERSTATIONWINDOW_H

#include <QMainWindow>

namespace WeatherStation {

class LocationSelector;
class LocationSelectionWidget;

class WeatherStationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeatherStationWindow(QWidget *parent = 0);
    virtual ~WeatherStationWindow();

public slots:
    void newLocation();
    void editLocation();
    void removeLocation();

private:
    void createMenus();
    void createWidgets();
    void createDocks();

    QAction *actNewLocation;
    QAction *actEditLocation;
    QAction *actRemoveLocation;
    QMenu *mnuLocation;

    QMenu *mnuWindows;

    LocationSelectionWidget *wdgtLocSelect;
    QDockWidget *dckLocSelect;

    LocationSelector *m_locationSelector;
};

#endif // WEATHERSTATIONWINDOW_H

} // namespace WeatherStation
