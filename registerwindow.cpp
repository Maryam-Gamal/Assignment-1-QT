#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->label_warningAlreadyExisting->setVisible(false);
    ui->label_NotMatching->setVisible(false);
    ui->label_warningDate->setVisible(false);
    ui->label_RegisterWarning->setVisible(false);

}


RegisterWindow::~RegisterWindow()
{
    delete ui;
}

