#include "bookclassroom.h"
#include "ui_bookclassroom.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include<QPixmap>
#include <QDateTime>
#include <QTimer>
#include<addedsuccessfully.h>

bookClassroom::bookClassroom(const QString &rno,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookClassroom)
    ,rno(rno)
{
    ui->setupUi(this);
}


bookClassroom::~bookClassroom()
{
    delete ui;
}
bool bookClassroom::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("kakshya");
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open()) {
        return false;
    }
    return true;
}


void bookClassroom::on_pushButtonAdd_clicked()
{
    QString timeSlot;
    QString selectedvalue = ui->comboBoxStream->currentText();
    QString sname = ui->lineEditsname->text();
    QString tname = ui->lineEdittname->text();
    QString day = QDateTime::currentDateTime().toString("dddd");
    int Time = QDateTime::currentDateTime().toString("HH").toInt();
    if(Time>=9 && Time<=11){
        timeSlot = "9-11";
    }
    else if(Time>=12 && Time<=14){
        timeSlot = "12-14";
    }
    else if(Time>=14 && Time<=16){
        timeSlot = "14-16";
    }

    QSqlQuery dquery;
    dquery.prepare(QString("DELETE FROM %1 where day = :day AND time_slot = :timeslot")
                       .arg(selectedvalue));
    dquery.bindValue(":day", day);
    dquery.bindValue(":timeslot", timeSlot);

    if(dquery.exec()){
        QSqlQuery query;
        query.prepare(QString("INSERT INTO %1 (day,time_slot,subject_name,instructor,room) "
                              "VALUES (:day, :timeslot, :sname, :tname, :rno)")
                          .arg(selectedvalue));
        query.bindValue(":day", day);
        query.bindValue(":timeslot", timeSlot);
        query.bindValue(":sname", sname);
        query.bindValue(":tname", tname);
        query.bindValue(":rno", rno);
        if(query.exec()){
            close();
            ads = new addedsuccessfully(this);
            ads->show();
        }
    }
}

