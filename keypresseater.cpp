#include "keypresseater.h"

KeyPressEater::KeyPressEater()
{

}

bool KeyPressEater::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Space)
        {
            return true;
        }
        return true;
    } else {
        return QObject::eventFilter(watched, event);
    }
}
