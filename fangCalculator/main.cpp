#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.QWidget::setWindowTitle("简易房贷计算器");
    w.QWidget::show();

    return a.exec();
}
