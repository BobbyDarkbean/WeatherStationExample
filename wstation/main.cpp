#include "weatherapplication.h"
#include "weatherstationwindow.h"

int main(int argc, char *argv[])
{
    WeatherStation::WeatherApplication app(argc, argv);

    WeatherStation::WeatherStationWindow mWin;
    mWin.show();

    return app.exec();
}
