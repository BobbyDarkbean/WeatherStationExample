#ifndef NEWLOCATIONDIALOG_H
#define NEWLOCATIONDIALOG_H

#include <QDialog>
#include "wsgui_shared.h"

namespace WeatherStation {

class WS_GUI_SHARED NewLocationDialog : public QDialog
{
public:
    explicit NewLocationDialog(QWidget *parent = 0);
    ~NewLocationDialog();

private:
    Q_DISABLE_COPY(NewLocationDialog)
};

} // namespace WeatherStation

#endif // NEWLOCATIONDIALOG_H
