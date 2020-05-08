#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"widget.h"
namespace Ui {
class Dialog;
}

class Dialog :virtual public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //设置Widget为友元类
    friend class Widget;
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
