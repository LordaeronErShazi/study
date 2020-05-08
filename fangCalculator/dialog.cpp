#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("计算结果");
    ui->lineEdit_daizonge_1->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_huanzonge_1->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_lixi_1->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_yuegong->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_yueshu_1->setFocusPolicy(Qt::NoFocus);
}

Dialog::~Dialog()
{
    delete ui;
}

