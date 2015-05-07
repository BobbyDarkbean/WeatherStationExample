#ifndef NEWLOCATIONDIALOG_H
#define NEWLOCATIONDIALOG_H

#include <QDialog>
#include "wsgui_shared.h"

class QLabel;
class QLineEdit;
class QSlider;
class QSpinBox;
class QPushButton;

namespace WeatherStation {

class WS_GUI_SHARED NewLocationDialog : public QDialog
{
public:
    explicit NewLocationDialog(QWidget *parent = 0);
    ~NewLocationDialog();

private:
    Q_DISABLE_COPY(NewLocationDialog)

    QLabel *lblDescription;
    QLineEdit *edtDescription;

    QLabel *lblLatitude;
    QSlider *sldLatitude;
    QSpinBox *spbLatitude;

    QLabel *lblLongitude;
    QSlider *sldLongitude;
    QSpinBox *spbLongitude;

    QPushButton *btnOk;
    QPushButton *btnCancel;

    void initializeLayout();


};

} // namespace WeatherStation

#endif // NEWLOCATIONDIALOG_H
