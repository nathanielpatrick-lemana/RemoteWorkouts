#include "newuserwindow.h"
#include "ui_newuserwindow.h"

newuserwindow::newuserwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuserwindow)
{
    ui->setupUi(this);
}

newuserwindow::~newuserwindow()
{
    delete ui;
}
