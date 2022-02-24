#ifndef MYACTION_H
#define MYACTION_H

#include <QLabel>

class MyAction : public QLabel
{
    Q_OBJECT
public:
    explicit MyAction(QWidget *parent = nullptr);
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);


signals:

};

#endif // MYACTION_H
