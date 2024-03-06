#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QWidget>

namespace Ui {
class RegisterWindow;
}
class WelcomeWindow;
class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterWindow *ui;
    WelcomeWindow* welcomeWindow;
};

#endif // REGISTERWINDOW_H
