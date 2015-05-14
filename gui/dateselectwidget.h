#ifndef DATESELECTWIDGET_H
#define DATESELECTWIDGET_H

#include <QWidget>
#include "wsgui_shared.h"

class QCalendarWidget;

namespace WeatherStation {

class WS_GUI_SHARED  DateSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DateSelectWidget(QWidget *parent = 0);
    virtual ~DateSelectWidget();

    QDate selectedDate();

signals:
    void dateSelected(const QDate &);

public slots:
    void setSelectedDate(const QDate &);

private:
    Q_DISABLE_COPY(DateSelectWidget)

    QCalendarWidget *calDateSelect;
};

#endif // DATESELECTWIDGET_H

} // namespace WeatherStation
