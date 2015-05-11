#ifndef LOCATIONSELECTIONWIDGET_H
#define LOCATIONSELECTIONWIDGET_H

#include <QWidget>
#include "wsgui_shared.h"

class QLabel;
class QComboBox;
class QGroupBox;

namespace WeatherStation {

class LocationInfo;

class WS_GUI_SHARED LocationSelectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LocationSelectionWidget(QWidget *parent = 0);
    virtual ~LocationSelectionWidget();

    int selectedLocationIndex() const;

signals:
    void locationIndexSelected(int);

public slots:
    void setSelectedLocationIndex(int);
    void applyLocationAdded(const LocationInfo &);
    void applyLocationEdited(int index, const LocationInfo &);
    void applyLocationRemoved(int index);

private:
    Q_DISABLE_COPY(LocationSelectionWidget)

    QLabel *lblLocation;
    QComboBox *cmbLocation;
    QGroupBox *grbCoordinates;
    QLabel *lblLatitude;
    QLabel *lblLongitude;
};

} // namespace WeatherStation

#endif // LOCATIONSELECTIONWIDGET_H
