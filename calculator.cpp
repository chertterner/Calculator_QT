#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{

    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(Show_Buttons()));
    connect(ui->pushButton_assign,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_null,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_addition,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_substraction,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_multiple,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math()));
     minus=false;
     plus=false;
     div=false;
     mul=false;
}
void Check(bool &a,Ui::Calculator *ui)
{
        ui->Screen->setText(" ");
        a=true;

}
void Math_oper(const double &rez_,Ui::Calculator *ui,QString &s1,bool &b)
{
    ui->Screen->setText(" ");
    s1=QString::number(rez_,'g',15);
    ui->Screen->setText(s1);
    b=false;
}
Calculator::~Calculator()
{
    delete ui;
}
void Calculator::Show_Buttons()
{
    button=(QPushButton*)sender();
    str=ui->Screen->text();
    if(str.contains(".") && button->text()=="0")
    {
        str+=button->text();
        ui->Screen->setText(str);
    }
    else
    {
    digit=(str+button->text()).toDouble();
    str=QString::number(digit,'g',15);
    ui->Screen->setText(str);
    }

}

void Calculator::on_pushButton_dot_clicked()
{
    str=ui->Screen->text();
    if(!(ui->Screen->text().contains('.')))
    {
    str+=".";
    }
    ui->Screen->setText(str);
}
void Calculator::operation()
{
    button=(QPushButton*)sender();
    s=button->text();
    str=ui->Screen->text();
    if(s=="-/+")
    {
        digit=str.toDouble();
        digit*=-1;
        str=QString::number(digit,'g',15);
        ui->Screen->setText(str);
    }
    if(s=="%")
    {
        digit=str.toDouble();
        digit*=0.01;
        str=QString::number(digit,'g',15);
        ui->Screen->setText(str);
    }
    if(s=="AC")
    {
        str="0";
        ui->Screen->setText(str);
    }

}
void Calculator::math()
{
    button=(QPushButton*)sender();
    s=button->text();
    digit2=ui->Screen->text().toDouble();
    if(s=="+")
        Check(plus,ui);
    if(s=="-")
        Check(minus,ui);
    if(s=="/")
        Check(div,ui);
    if(s=="*")
        Check(mul,ui);
}

void Calculator::on_pushButton_equal_clicked()
{
    double rez=0.0;
if(plus)
{
     rez=digit2+digit;
     Math_oper(rez,ui,s1,plus);
}
if(minus)
{
    rez=digit2-digit;
    Math_oper(rez,ui,s1,minus);
}
if(mul)
{
    rez=digit2*digit;
    Math_oper(rez,ui,s1,mul);
}
if(div)
{
        rez=digit2/digit;
        Math_oper(rez,ui,s1,div);

}
}

