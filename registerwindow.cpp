#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

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

void RegisterWindow::on_pushButton_clicked()
{
    ui->label_warningAlreadyExisting->setVisible(false);
    ui->label_NotMatching->setVisible(false);
    ui->label_warningDate->setVisible(false);
    ui->label_RegisterWarning->setVisible(false);

    QString username = ui->lineEdit_Username->text();
    QString month = ui->comboBox_Month->currentText();
    QString day = ui->comboBox_Day->currentText();
    QString Year = ui->comboBox_Year->currentText();
    QString Pass = ui->lineEdit_Password->text();
    QString Repass = ui->lineEdit_RetypePassword_2->text();
    bool R1 = ui->radioButton_Admin->isChecked();
    bool R2 = ui->radioButton_Female->isChecked();
    bool R3 = ui->radioButton_Male->isChecked();
    bool R4 = ui->radioButton_User->isChecked();
    bool action = ui->checkBox_Action->isChecked();
    bool comedy = ui->checkBox_Comedy->isChecked();
    bool horror = ui->checkBox_Horror->isChecked();
    bool drama = ui->checkBox_Drama->isChecked();
    bool other = ui->checkBox_Other->isChecked();
    bool romance = ui->checkBox_Romance->isChecked();

    bool hasError = false;

    for(int i = 0; i < usersCount; i++)
    {
        if(username == usernames[i])
        {
            ui->label_warningAlreadyExisting->setVisible(true);
            hasError = true;
        }
    }

    if(Pass != Repass)
    {
        ui->label_NotMatching->setVisible(true);
        hasError = true;
    }

    int x = Year.toInt();
    int y = 2024 - x;
    if(y <= 12)
    {
        ui->label_warningDate->setVisible(true);
        hasError = true;
    }

    if(R2 + R3 == 0 || R1 + R4 == 0 || username.isEmpty() || Pass.isEmpty() || Repass.isEmpty() || month.isEmpty() || day.isEmpty() || Year.isEmpty() || action + comedy + horror + other + drama + romance == 0)
    {
        ui->label_RegisterWarning->setVisible(true);
        hasError = true;
    }

    if(!hasError)
    {
        if(usersCount < 100)
        {
            usernames[usersCount] = username;
            passwords[usersCount] = Pass;
            ages[usersCount] = y;
            usersCount++;
        }

        WelcomeWindow *welcomeWindow = new WelcomeWindow(username, y);
        welcomeWindow->show();
        this->hide();
    }


}
