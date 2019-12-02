#ifndef LISTSTRING_H
#define LISTSTRING_H

#include <QObject>
#include <QString>
#include <QStringList>


class ListStrings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString list READ getText NOTIFY listChanged)
private:
    QStringList list;
public:
    ListStrings();
    Q_INVOKABLE void append(QString str);
    Q_INVOKABLE void removeLast();
    QString getText();
signals:
    void listChanged();
};

#endif // LISTSTRING_H
