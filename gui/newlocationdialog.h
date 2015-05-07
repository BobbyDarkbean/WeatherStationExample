#ifndef NEWLOCATIONDIALOG_H
#define NEWLOCATIONDIALOG_H

#include <QDialog>
#include "wsgui_shared.h"

class QLabel;
class QLineEdit;
class QSlider;
class QDoubleSpinBox;
class QPushButton;

namespace WeatherStation {

class WS_GUI_SHARED NewLocationDialog : public QDialog
{
public:
    explicit NewLocationDialog(QWidget *parent = 0);
    ~NewLocationDialog();

private:
    Q_DISABLE_COPY(NewLocationDialog)

    void initializeLayout();

    QLabel *lblDescription;
    QLineEdit *edtDescription;

    QLabel *lblLatitude;
    QSlider *sldLatitude;
    QDoubleSpinBox *spbLatitude;

    QLabel *lblLongitude;
    QSlider *sldLongitude;
    QDoubleSpinBox *spbLongitude;

    QPushButton *btnOk;
    QPushButton *btnCancel;
};

} // namespace WeatherStation

#endif // NEWLOCATIONDIALOG_H
