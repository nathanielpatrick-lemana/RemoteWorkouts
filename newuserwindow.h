#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QDialog>

namespace Ui {
class newuserwindow;
}

class newuserwindow : public QDialog
{
    Q_OBJECT

public:
    explicit newuserwindow(QWidget *parent = nullptr);
    ~newuserwindow();

private:
    Ui::newuserwindow *ui;
};

#endif // NEWUSERWINDOW_H
