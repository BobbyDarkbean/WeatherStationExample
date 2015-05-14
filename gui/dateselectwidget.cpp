#include <QCalendarWidget>
#include <QBoxLayout>
#include "dateselectwidget.h"

namespace WeatherStation {

DateSelectWidget::DateSelectWidget(QWidget *parent)
    : QWidget(parent),
      calDateSelect(new QCalendarWidget)
{
    calDateSelect->setMinimumDate(QDate::currentDate());

    QBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(calDateSelect);

    connect(calDateSelect, SIGNAL(clicked(QDate)),
            this, SIGNAL(dateSelected(QDate)));
}

DateSelectWidget::~DateSelectWidget() { }

QDate DateSelectWidget::selectedDate()
{ return calDateSelect->selectedDate(); }

void DateSelectWidget::setSelectedDate(const QDate &date)
{ calDateSelect->setSelectedDate(date); }

} // namespace WeatherStation

