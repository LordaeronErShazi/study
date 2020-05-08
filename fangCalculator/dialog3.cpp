#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    ui->lineEdit_shouyuegong->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_huanzonge_2->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_lixi_2->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_yueshu_2->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_daizonge_2->setFocusPolicy(Qt::NoFocus);
}

Dialog3::~Dialog3()
{
    delete ui;
}
