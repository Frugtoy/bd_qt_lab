#include "signin.h"
#include "ui_signin.h"

signIn::signIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signIn)
{
    ui->setupUi(this);
}

signIn::~signIn()
{
    delete ui;
}
