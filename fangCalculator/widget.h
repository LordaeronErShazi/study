#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"dialog.h"
#include"dialog2.h"
#include"dialog3.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    friend class Dialog2;
private:
    Ui::Widget *ui;
    double shangdaie = 0,gongdaie = 0,shanglv = 0,gonglv = 0,anjiecheng = 8;
    int anjienian = 25,wayprime = 0;
};

#endif // WIDGET_H
