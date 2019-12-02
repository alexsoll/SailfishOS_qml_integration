#include "counter.h"
#include <QDebug>

Counter::Counter() : QObject()
{
    this->count = 0;
}

void Counter::increment()
{
    this->count++;
    emit countChanged();
}

void Counter::reset()
{
    this->count = 0;
    emit countChanged();
}

void Counter::print()
{
    qDebug() << "Current count: " << this->count;
}

int Counter::getCount()
{
    return this->count;
}

void Counter::setCount(int count)
{
    this->count = count;
    emit countChanged();
}
