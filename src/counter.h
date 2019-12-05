#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>


class Counter : public QObject
{
    int last;
    int prelast;
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
private:
    int count;
public:
    Q_INVOKABLE Counter();
    Q_INVOKABLE void increment();
    Q_INVOKABLE void reset();
    int getCount();
    void setCount(int count);
private slots:
    void print();
signals:
    void countChanged();
};

#endif // COUNTER_H
