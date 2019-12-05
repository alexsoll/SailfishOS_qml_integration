#include "liststring.h"

ListStrings::ListStrings() : QObject()
{
    this->list = QStringList();
}

void ListStrings::append(QString str)
{
    this->list.append(str.toLower());
    emit listChanged();
}

void ListStrings::removeLast()
{
    if (this->list.count()) {
        this->list.removeLast();
    }
    //this->list.removeLast();
    emit listChanged();
}

QString ListStrings::getText()
{
    QString text = this->list.join(", ");
    return text.replace(0, 1, text[0].toUpper());
}
