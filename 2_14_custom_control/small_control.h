#ifndef SMALL_CONTROL_H
#define SMALL_CONTROL_H

#include <QWidget>

namespace Ui {
class Small_Control;
}

class Small_Control : public QWidget
{
    Q_OBJECT

public:
    explicit Small_Control(QWidget *parent = nullptr);

    ~Small_Control();

    void set_num(int num);
    int get_num();
private:
    Ui::Small_Control *ui;
};

#endif // SMALL_CONTROL_H
