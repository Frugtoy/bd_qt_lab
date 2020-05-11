#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include<QtSql/QSqlDatabase>

#include<QSqlQueryModel>
#include<QSqlError>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    signin_window = new signIn;
    signin_window ->exec();
    ui->setupUi(this);
    connect(ui->admin,&QPushButton::clicked, this,&MainWindow::click);
    connect(ui->add,&QPushButton::clicked,this,&MainWindow::dialog);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my_awesome_bd");
    db.open();
    ui->tableView->setModel(&query_model);
    faculty_add_window = new Dialog;
}
void MainWindow::click(){

    QSqlQuery query;
    query.exec(ui->textEdit->toPlainText());
    query_model.setQuery(query);
    statusBar()->showMessage(query.lastError().text());
}
void MainWindow::dialog(){
     faculty_add_window->exec();
}
MainWindow::~MainWindow()
{
    delete ui;
    delete faculty_add_window;
}

