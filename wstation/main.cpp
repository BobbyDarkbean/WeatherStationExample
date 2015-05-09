#include <QMainWindow>
#include "weatherapplication.h"

int main(int argc, char *argv[])
{
    WeatherStation::WeatherApplication app(argc, argv);

    QMainWindow mWin;
    mWin.showMaximized();

    return app.exec();
}
