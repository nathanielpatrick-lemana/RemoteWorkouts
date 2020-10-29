#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <string.h>

newuserwindow::newuserwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuserwindow)
{
    ui->setupUi(this);
}

void newuserwindow::on_CreateButton_clicked() {
    QSqlDatabase loginbase;
    loginbase = QSqlDatabase::addDatabase("QMYSQL");

    loginbase.setHostName("localhost");
    loginbase.setDatabaseName("remoteworkouts");
    loginbase.setUserName("defaultuser");
    loginbase.setPassword("defaultuserpassword");
    loginbase.open();

    const QString username = ui->username->text();
    const QString fname = ui->firstname->text();
    const QString lname = ui->lastname->text();
    const QString password = ui->password->text();

    if (fieldValidation()) {
        if (passwordValidation()) {


            QSqlQuery unattempt, createacct;

            unattempt.prepare("select username from users where username='" + username + "';");
            if (unattempt.exec()) {
                unattempt.next();
                if (username != unattempt.value(0).toString()) {
                    createacct.prepare(
                            "insert into users (username, firstname, lastname, password) values ('" + username +
                            "', '" +
                            fname + "', '" + lname + "', '" + password + "');");
                    createacct.exec();
                    QMessageBox msgBox;
                    msgBox.setText("account created");
                    msgBox.exec();
                }
            } else {
                QMessageBox msgBox;
                msgBox.setText("failed");
                msgBox.exec();
            }
        }
    }
}

bool newuserwindow::fieldValidation(){
    const QString username = ui->username->text();
    const QString fName = ui->firstname->text();
    const QString lName = ui->lastname->text();
    const QString password = ui->password->text();
    const QString confirmPassword = ui->confpw->text();

    std::string usernameStr = username.toStdString();
    std::string fNameStr = fName.toStdString();
    std::string lNameStr = lName.toStdString();
    std::string passwordStr = password.toStdString();
    std::string confirmPwStr = confirmPassword.toStdString();

    if (usernameStr != "" && fNameStr != "" && lNameStr != "" && passwordStr != "" && passwordStr != "" && confirmPwStr != "")
        return true;
    else {
        QMessageBox msgBox;
        msgBox.setText("Not all field are filled in!");
        msgBox.exec();
    }
}

bool newuserwindow::passwordValidation() {
    const QString password = ui->password->text();
    const QString confirmPassword = ui->confpw->text();

    std::string passwordStr = password.toStdString();
    std::string confirmPwStr = confirmPassword.toStdString();

    if (password.compare(confirmPassword) == 0)
        return true;
    else {
        QMessageBox msgBox;
        msgBox.setText("Passwords do not match!");
        msgBox.exec();
    }
}

newuserwindow::~newuserwindow()
{
    delete ui;
}

void newuserwindow::on_close_clicked()
{
    close();
}
