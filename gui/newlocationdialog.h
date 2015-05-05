#ifndef NEWLOCATIONDIALOG_H
#define NEWLOCATIONDIALOG_H

#include <QDialog>

namespace WeatherStation {

class NewLocationDialog : public QDialog
{
public:
    explicit NewLocationDialog(QWidget *parent = 0);
    ~NewLocationDialog();

private:
    Q_DISABLE_COPY(NewLocationDialog)
};

} // namespace WeatherStation

#endif // NEWLOCATIONDIALOG_H
