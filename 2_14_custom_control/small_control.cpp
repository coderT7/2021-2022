#include "small_control.h"
#include "ui_small_control.h"

Small_Control::Small_Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Small_Control)
{
    ui->setupUi(this);

    void (QSpinBox:: * value)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,value,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}
void Small_Control::set_num(int num)
{
    ui->spinBox->setValue(num);
}
int Small_Control::get_num()
{
    return ui->horizontalSlider->value();
}

Small_Control::~Small_Control()
{
    delete ui;
}
