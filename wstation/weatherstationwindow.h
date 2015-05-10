#ifndef WEATHERSTATIONWINDOW_H
#define WEATHERSTATIONWINDOW_H

#include <QMainWindow>

namespace WeatherStation {

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

    QAction *actNewLocation;
    QAction *actEditLocation;
    QAction *actRemoveLocation;
    QMenu *mnuLocation;
};

#endif // WEATHERSTATIONWINDOW_H

} // namespace WeatherStation
