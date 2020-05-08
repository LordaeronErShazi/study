#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include"widget.h"
namespace Ui {
class Dialog2;
}

class Dialog2 :virtual public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    //设置Widget为友元类
    friend class Widget;
private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
