#include "descriptiondialog.h"
#include "ui_descriptiondialog.h"
#include <string>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <iostream>
#include <QTimer>

descriptionDialog::descriptionDialog(QWidget *parent) :
    QDialog(parent),
    time { 0 },
    ui(new Ui::descriptionDialog)
{
    ui->setupUi(this);
}

descriptionDialog::~descriptionDialog()
{
    delete ui;
}

void descriptionDialog::setIndexID(int rec)
{
    indexID = rec;
}

int descriptionDialog::getIndexID()
{
    return indexID;
}

void descriptionDialog::setTableIndex(int rec)
{
    tableIndex = rec;
}

int descriptionDialog::getTableIndex()
{
    return tableIndex;
}

void descriptionDialog::loadData()
{
    QString ID = QString::number(indexID);

    QSqlQuery exercise;

    switch (tableIndex) {
    case 1:
        exercise.prepare("select ExerciseName, ExerciseDesc from cardio where ExerciseID='" + ID + "';");
        break;
    case 2:
        exercise.prepare("select ExerciseName, ExerciseDesc from core where ExerciseID='" + ID + "';");
        break;
    case 3:
        exercise.prepare("select ExerciseName, ExerciseDesc from lowerbody where ExerciseID='" + ID + "';");
        break;
    case 4:
        exercise.prepare("select ExerciseName, ExerciseDesc from lowerbody where ExerciseID='" + ID + "';");
        break;
    }

    exercise.exec();
    exercise.next();

    ui->exerciseName->setText(exercise.value(0).toString());
    ui->exerciseDesc->setText(exercise.value(1).toString());


    //ui->label->setText(ID);
}

void descriptionDialog::updateUI()
{
    ui->timer->setText(QString::fromStdString(timeStr));
}

void descriptionDialog::on_start_clicked()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

}

void descriptionDialog::updateTime()
{
    time = time + 1;
    timeStr = std::to_string(time);
    updateUI();

}

void descriptionDialog::on_stop_clicked()
{
    timer->stop();
}

void descriptionDialog::on_reset_clicked()
{
    time = 0;
    timeStr = std::to_string(time);
    timer->stop();
    updateUI();
}