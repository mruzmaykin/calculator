#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stack>
#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    std::stack<double> st;
    double lastNum = 0;
    int operation;
private slots:
    void digit_pressed();
    void operation_pressed();
    void equal_pressed();
    void clear_pressed();

};

#endif // CALCULATOR_H
