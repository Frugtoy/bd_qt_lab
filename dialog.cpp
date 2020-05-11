#include "dialog.h"
#include "ui_dialog.h"

#include <QSqlQuery>
#include <QDebug>
Dialog::Dialog(QWidget *parent, Dialog::Type type) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->type = type;
    connect(ui->add, &QPushButton::clicked, this, &Dialog::onClick);
}

Dialog::Dialog(QWidget *parent, Dialog::Type type, int id) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->type = type;
    connect(ui->add, &QPushButton::clicked, this, &Dialog::onClick);
    this->id = id;
}


QString tableName = "students";
void Dialog::onClick()
{
    QString ex = "";
     QSqlQuery *query = new QSqlQuery();
    switch(type)
    {
        case change:
        query->exec("UPDATE "
                   + tableName + "SET" +
                   " faculty =" + ui->comboBox->currentText() +
                   " grp =" + ui->comboBox_2->currentText() +
                   " name =" + ui->name->text() +
                   " lastName=" + ui->lastName->text()); +
                   ") WHERE id=" + id;
         case add:
         query->exec("INSERT INTO "
                    + tableName +
                    "(" + "faculty" +
                    "," + "grp" +
                    "," + "name" +
                    "," + "lastName" +
                    ") "+ " VALUES " +
                    " ("+ ui->comboBox->currentText() +
                    "," + ui->comboBox_2->currentText() +
                    "," + ui->name->text() +
                    "," + ui->lastName->text() +
                    ")");

            break;
    }
 qDebug() << query->lastQuery();

}


Dialog::~Dialog()
{
    delete ui;
}
