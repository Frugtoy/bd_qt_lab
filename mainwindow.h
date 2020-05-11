#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QMainWindow>
#include <QSqlTableModel>
#include <dialog.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Dialog * faculty_add_window;
    QSqlDatabase db;
    QSqlQueryModel query_model;
    QSqlTableModel *model;
    void dialog();
    void setupModel(const QString &tableName , const QStringList &headers);
    void createUI();
private slots:
    void click();
    void change();
 };

#endif // MAINWINDOW_H
