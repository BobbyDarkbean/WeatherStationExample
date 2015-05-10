#ifndef NEWLOCATIONDIALOG_H
#define NEWLOCATIONDIALOG_H

#include <QDialog>
#include "wsgui_shared.h"
#include "locationinfo.h"

class QLabel;
class QLineEdit;
class QSlider;
class QDoubleSpinBox;
class QPushButton;
class QFrame;
class QGroupBox;

namespace WeatherStation {

class WS_GUI_SHARED NewLocationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLocationDialog(QWidget *parent = 0);
    virtual ~NewLocationDialog();

    LocationInfo locationInfo() const;

private slots:
    void applySpinLatitude(int lat);
    void applySliderLatitude(double lat);
    void applySpinLongitude(int lon);
    void applySliderLongitude(double lon);
    void applyLatitudeOutput(double lat);
    void applyLongitudeOutput(double lon);

private:
    Q_DISABLE_COPY(NewLocationDialog)

    void adjustComponents();
    void initializeLayout();
    void establishConnections();

    QFrame *frmMain;

    QFrame *frmDescription;

    QLabel *lblDescription;
    QLineEdit *edtDescription;

    QGroupBox *grbCoordinates;

    QLabel *lblLatitude;
    QSlider *sldLatitude;
    QDoubleSpinBox *spbLatitude;

    QLabel *lblLongitude;
    QSlider *sldLongitude;
    QDoubleSpinBox *spbLongitude;

    QLabel *lblOutputLatitude;
    QLabel *lblOutputLongitude;

    QFrame *frmButtons;

    QPushButton *btnOk;
    QPushButton *btnCancel;
};

} // namespace WeatherStation

#endif // NEWLOCATIONDIALOG_H
