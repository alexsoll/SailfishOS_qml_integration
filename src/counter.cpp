#include "counter.h"
#include <QDebug>

Counter::Counter() : QObject()
{
    this->last = 1;
    this->prelast = 1;
    this->count = 0;
}

void Counter::increment()
{
    this->prelast = this->last;
    this->last = this->count;
    this->count = this->prelast + this->last;
    emit countChanged();
}

void Counter::reset()
{
    this->count = 0;
    this->prelast = 1;
    this->last = 1;
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
