#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT


public:
    enum Type
    {
      change = 0,
      add = 1,
    };
    explicit Dialog(QWidget *parent = nullptr, Type type = change);
    explicit Dialog(QWidget *parent = nullptr, Type type = change, int id = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int id;
    Type type;

private slots:
      void onClick();
};

#endif // DIALOG_H
