#ifndef WEATHERSTATIONWINDOW_H
#define WEATHERSTATIONWINDOW_H

#include <QMainWindow>

namespace WeatherStation {

class LocationSelector;
class LocationSelectionWidget;
class WeatherWidget;
class DateSelectWidget;

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

    DateSelectWidget *wdgtDateSelect;
    QDockWidget *dckDateSelect;

    LocationSelector *m_locationSelector;
    WeatherWidget *m_weatherWidget;
};

#endif // WEATHERSTATIONWINDOW_H

} // namespace WeatherStation
