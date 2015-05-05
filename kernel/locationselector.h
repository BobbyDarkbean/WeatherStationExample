#ifndef LOCATIONSELECTOR_H
#define LOCATIONSELECTOR_H

#include <QObject>
#include "kernel_shared.h"
#include "locationpool.h"

namespace WeatherStation {

class LocationSelector : public QObject
{
    Q_OBJECT

public:
    explicit LocationSelector(QObject *parent = 0);
    virtual ~LocationSelector();

    const Location *currentLocation() const;
    int currentIndex() const;
    QDate currentDate() const;

    const LocationPool *locationPool() const;
    void setLocationPool(const LocationPool *);

    static const int NoSelection;

signals:
    void selectedLocationChanged(int index);
    void selectedDateChanged(const QDate &);

public slots:
    void setCurrentIndex(int);
    void setCurrentDate(const QDate &);

private:
    Q_DISABLE_COPY(LocationSelector)

    int m_currentIndex;
    QDate m_currentDate;
    const LocationPool *m_locationPool;
};

} // namespace WeatherStation

#endif // LOCATIONSELECTOR_H
