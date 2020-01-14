#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    QString str,s,s1;
    double digit,digit2;
    QPushButton *button;
    bool minus,plus,div,mul;
private slots:
    void Show_Buttons();
    void on_pushButton_dot_clicked();
    void operation();
    void math();
    void on_pushButton_equal_clicked();
};
#endif // CALCULATOR_H
