#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <ui_loginwindow.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    bool on_login_clicked();
    void on_newuser_clicked();

private:
    Ui::LoginWindow *ui;

};

#endif // LOGINWINDOW_H
