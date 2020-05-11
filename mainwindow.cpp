#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include<QtSql/QSqlDatabase>

#include<QSqlQueryModel>
#include<QSqlError>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->admin,&QPushButton::clicked, this,&MainWindow::click);
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::dialog);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::change);
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("my_awesome_bd");
    db.open();

    QSqlQuery query;
    query.exec(("CREATE TABLE students(id INTEGER PRIMARY KEY AUTOINCREMENT, faculty VARCHAR(20), grp VARCHAR(20), name VARCHAR(20), lastName VARCHAR(20));"));
     statusBar()->showMessage(query.lastError().text());
    ui->tableView->setModel(&query_model);
}

void MainWindow::click()
{
    QSqlQuery query;
    query.exec(ui->textEdit->toPlainText());
    query_model.setQuery(query);
    statusBar()->showMessage(query.lastError().text());
}

void MainWindow::change()
{
    bool ok;
    int row = QInputDialog::getInt(this, tr("Input row"),
                                   tr("Row: "), 0, 0, ui->tableView->rowHeight(0), 1, &ok);
    if(ok)
    {
        Dialog *dialog = new Dialog(this, Dialog::Type::change, row);
        dialog->exec();
    }
}

void MainWindow::dialog()
{
    Dialog *dialog = new Dialog(this, Dialog::Type::add, 0);
    dialog->exec();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete faculty_add_window;
}
