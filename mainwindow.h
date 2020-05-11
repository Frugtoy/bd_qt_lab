#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QMainWindow>
#include <QSqlTableModel>
#include <dialog.h>
#include<signin.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    enum Roles
    {
        ADMIN = 0,
        MODER = 1,
        USER = 2

    };


private:
    Ui::MainWindow *ui;
    Dialog * faculty_add_window;
    signIn * signin_window;
    QSqlDatabase db;
    QSqlQueryModel query_model;
    QSqlTableModel *model;
    void dialog();
    void setupModel(const QString &tableName , const QStringList &headers);
    void createUI();
private slots:
    void click();
 };

#endif // MAINWINDOW_H
