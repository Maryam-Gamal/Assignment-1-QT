#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow (QString username, int age, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString ageStr = QString::number(age);
    ui->label_Hello->setText("Hello " + username +" " +ageStr);

    QPixmap pix("C:\\Users\\marya\\Downloads\\1000_F_64072711_bTSr69baZ41c0u0PhhwgBX0UwX1M95Rb.jpg");
    int w = ui->label_image->width();
    int h = ui->label_image->height();
    ui->label_image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}


WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_logout_clicked()
{
    loginwindow = new LoginWindow();
    loginwindow->show();
    this->hide();

}

