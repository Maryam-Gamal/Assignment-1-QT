#include "loginwindow.h"
#include "Users.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_Login_clicked()
{
    QString name = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    for(int i=0; i<100; i++){
        if(name == usernames[i] && password == passwords[i]){
            welcomeWindow = new WelcomeWindow(name, ages[i]);
            welcomeWindow->show();
             this->hide();
        }
        else {
            ui->label_error->setVisible(true);
        }


    }
}

void LoginWindow::on_pushButton_Register_clicked()
{
    registerwindow = new RegisterWindow();
    registerwindow->show();
    this->hide();
}

