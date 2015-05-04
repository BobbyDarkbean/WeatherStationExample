#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mWin;
    mWin.showMaximized();

    return app.exec();
}
