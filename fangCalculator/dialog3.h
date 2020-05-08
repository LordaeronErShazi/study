#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include"widget.h"
namespace Ui {
class Dialog3;
}

class Dialog3 :virtual public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    ~Dialog3();
    //设置Widget为友元类
    friend class Widget;
private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
