#include "weatherapplication.h"
#include "newlocationdialog.h"

int main(int argc, char *argv[])
{
    WeatherStation::WeatherApplication app(argc, argv);

    WeatherStation::NewLocationDialog mWin;
    mWin.show();

    return app.exec();
}
