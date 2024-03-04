#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>

namespace Ui {
class WelcomeWindow;
}
class LoginWindow;
class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QString username, int age, QWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void on_pushButton_logout_clicked();

private:
    Ui::WelcomeWindow *ui;
    LoginWindow *loginwindow;

};

#endif // WELCOMEWINDOW_H
