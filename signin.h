#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class signIn;
}

class signIn : public QDialog
{
    Q_OBJECT

public:
    explicit signIn(QWidget *parent = nullptr);
    ~signIn();

private:
    Ui::signIn *ui;
};

#endif // SIGNIN_H
