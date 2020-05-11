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


QString tableName = "Student";
void Dialog::onClick()
{
    QString ex = "";
     QSqlQuery *query = new QSqlQuery();
    switch(type)
    {
        case change:
        query->exec("UPDATE "
                   + tableName + "SET" +
                   " grp =" + ui->grp->currentText() +
                   " firstName =" + ui->name->text() +
                   " lastName=" + ui->lastName->text() +
                   "middleName="+ ui->middleName->text());
         case add:
         query->exec("INSERT INTO "
                    + tableName +
                    "(" + "grp" +
                    "," + "name"+
                    "," + "lastName"+
                    "," + "middleName" +
                    "," + "info" +
                    ") "+ " VALUES " +
                    " ("+ ui->grp->currentText() +
                    "," + ui->name->text() +
                    "," + ui->lastName->text() +
                    "," + ui->middleName->text() +
                    "," + ui->info->text() +
                    ")");

            break;
    }
 qDebug() << query->lastQuery();

}


Dialog::~Dialog()
{
    delete ui;
}
