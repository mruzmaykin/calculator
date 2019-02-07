#include "calculator.h"
#include "ui_calculator.h"
#include <stack>

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->button_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button_9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_18,SIGNAL(released()),this,SLOT(equal_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_11,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_15,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(clear_pressed()));

}

Calculator::~Calculator()
{
    delete ui;
}
void Calculator::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;
    double labelNum;
    labelNum= (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNum,'g', 15);
    ui->label->setText(newLabel);
}
void Calculator::operation_pressed(){
    QPushButton* button = (QPushButton*)sender();
    if(!lastNum)
        lastNum = ui->label->text().toDouble();
    QString operatorLabel = button->text();
    if(operatorLabel=="+")
        operation = 1;
    else if (operatorLabel == "-")
        operation = 2;
    else if (operatorLabel == "/")
        operation = 3;
    else if (operatorLabel == "X")
        operation = 4;
    ui->label->setNum(0);
}
void Calculator::equal_pressed(){
    double result;
    switch(operation){
    case 1: result = lastNum + ui->label->text().toDouble(); break;
    case 2: result = lastNum - ui->label->text().toDouble(); break;
    case 3: result = lastNum / ui->label->text().toDouble(); break;
    case 4: result = lastNum * ui->label->text().toDouble(); break;
    }
    lastNum = result;
    ui->label->setNum(result);
}
void Calculator::clear_pressed(){
    lastNum = 0;
    ui->label->setNum(0);
    operation = 0;
}
