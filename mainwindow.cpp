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
    signin_window = new signIn;
    signin_window ->exec();
    ui->setupUi(this);
    connect(ui->admin,&QPushButton::clicked, this,&MainWindow::click);
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::dialog);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::change);
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(":memory:");
    db.open();

    QSqlQuery query;
    //memory db preset
    query.exec((R"(
                CREATE TABLE Faculty(
                facultyId INTEGER PRIMARY KEY AUTOINCREMENT,
                name VARCHAR(64) NOT NULL
                )
            )"));

    query.exec((R"(
                CREATE TABLE Groups (
                groupId INTEGER PRIMARY KEY AUTOINCREMENT,
                facultyID INTEGER REFERENCES Faculty(facultyId),
                name VARCHAR(64) NOT NULL
                )
            )"));

    query.exec((R"(
                 CREATE TABLE Student(
                 studentId INTEGER PRIMARY KEY AUTOINCREMENT,
                 groupId INTEGER REFERENCES Groups(groupID),
                 firstName VARCHAR(64) NOT NULL,
                 lastName VARCHAR(64) NOT NULL,
                 middleName VARCHAR(64),
                 info VARCHAR
                )
             )"));
    query.exec((R"(
        INSERT INTO Faculty
               name
               VALUES
             CYBERNETICA

)"));

   // select * from faculty

    query.exec((R"(
                INSERT INTO Groups
                (
                facultyID,
                name
                )

                VALUES
               (
                0,
                КМБО-05-18,

                )

                )"));

    //query.exec(("CREATE TABLE students(id INTEGER PRIMARY KEY AUTOINCREMENT, faculty VARCHAR(20), grp VARCHAR(20), name VARCHAR(20), lastName VARCHAR(20));"));
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
