#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    accept();
}


QString Dialog::getUserName(){
    return ui->lineEdit->text();
}

QString Dialog::getPassword(){
    return ui->lineEdit_2->text();
}

