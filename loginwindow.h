#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE
class WelcomeWindow;
class RegisterWindow;
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Register_clicked();

private:
    Ui::LoginWindow *ui;
    WelcomeWindow* welcomeWindow;
    RegisterWindow* registerwindow;
    QWidget *parent;

};
#endif // LOGINWINDOW_H
