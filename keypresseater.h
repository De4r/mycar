#ifndef KEYPRESSEATER_H
#define KEYPRESSEATER_H

#include <QEvent>
#include <QKeyEvent>
#include <QObject>

class KeyPressEater : public QObject
{
    Q_OBJECT

public:
    KeyPressEater();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // KEYPRESSEATER_H
