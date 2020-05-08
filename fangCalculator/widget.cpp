#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
#include"ui_dialog.h"
#include"ui_dialog2.h"
#include"ui_dialog3.h"
#include<QDebug>
#include<math.h>
#include<QString>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置提示文字
    ui->lineEdit_shangdaie->setPlaceholderText("没有请输入“0”                                       单位：万元");
    ui->lineEdit_gongjijine->setPlaceholderText("没有请输入“0”                                     单位：万元");
    ui->lineEdit_shangdaililv->setPlaceholderText("没有请输入“0”         %");
    ui->lineEdit_gongjijinlilv->setPlaceholderText("没有请输入“0”       %");
    //设置Line Edit只允许输入数字
    ui->lineEdit_gongjijine->setValidator(new QDoubleValidator(0,1000000,2,this));
    ui->lineEdit_shangdaie->setValidator(new QDoubleValidator(0,1000000,2,this));
    ui->lineEdit_gongjijinlilv->setValidator(new QDoubleValidator(0,100,2,this));
    ui->lineEdit_shangdaililv->setValidator(new QDoubleValidator(0,100,2,this));
    //设置radio button 默认选中
    ui->radioButton_benjin->setChecked(true);
    //输入并实时获取Line Edit的值
    connect(ui->lineEdit_shangdaie,&QLineEdit::textChanged,this,[=](){
        shangdaie = ui->lineEdit_shangdaie->text().toDouble();
        //qDebug()<<shangdaie;
    });
    connect(ui->lineEdit_gongjijine,&QLineEdit::textChanged,this,[=](){
        gongdaie = ui->lineEdit_gongjijine->text().toDouble();
        //qDebug()<<gongdaie;
    });
    connect(ui->lineEdit_shangdaililv,&QLineEdit::textChanged,this,[=](){
        shanglv =  ui->lineEdit_shangdaililv->text().toDouble()*0.01/12;
        //qDebug()<<shanglv;
    });
    connect(ui->lineEdit_gongjijinlilv,&QLineEdit::textChanged,this,[=](){
        gonglv = ui->lineEdit_gongjijinlilv->text().toDouble()*0.01/12;
        //qDebug()<<gonglv;
    });
    //选择并实时获取Combo Box的值
//    connect(ui->comboBox_anjiecehngshu,&QComboBox::currentTextChanged,[=](){
//        QString str1 = ui->comboBox_anjiecehngshu->currentText();
//        switch (str1) {
//        case "8成": anjiecheng = 0.8; break;
//        case "7.5成": anjiecheng = 0.75; break;
//        case "7成": anjiecheng = 0.7; break;
//        case "6.5成": anjiecheng = 0.65; break;
//        case "6成": anjiecheng = 0.6; break;
//        case "5.5成": anjiecheng = 0.55; break;
//        case "5成": anjiecheng = 0.5; break;
//        case "4.5成": anjiecheng = 0.45; break;
//        case "4成": anjiecheng = 0.4; break;
//        case "3.5成": anjiecheng = 0.35; break;
//        case "3成": anjiecheng = 0.3; break;
//        case "2.5成": anjiecheng = 0.25; break;
//        case "2成": anjiecheng = 0.2; break;
//        default: qDebug()<<"error!"; break;
//        }    switch语句编译错误，原因未知，故改用if语句
//        if(str1=="8成") anjiecheng = 0.8;
//        if(str1=="7.5成") anjiecheng = 0.75;
//        if(str1=="7成") anjiecheng = 0.7;
//        if(str1=="6.5成") anjiecheng = 0.65;
//        if(str1=="6成") anjiecheng = 0.6;
//        if(str1=="5.5成") anjiecheng = 0.55;
//        if(str1=="5成") anjiecheng = 0.5;
//        if(str1=="4.5成") anjiecheng = 0.45;
//        if(str1=="4成") anjiecheng = 0.4;
//        if(str1=="3.5成") anjiecheng = 0.35;
//        if(str1=="3成") anjiecheng = 0.3;
//        if(str1=="2.5成") anjiecheng = 0.25;
//        if(str1=="2成") anjiecheng = 0.2;
//        //qDebug()<<str1<<"  "<<anjiecheng;
//    });

    connect(ui->comboBox_anjienianshu,&QComboBox::currentTextChanged,[=](){
        QString str2 = ui->comboBox_anjienianshu->currentText();
        if(str2=="25年（300期）") anjienian = 25;
        if(str2=="24年（288期）") anjienian = 24;
        if(str2=="23年（276期）") anjienian = 23;
        if(str2=="22年（264期）") anjienian = 22;
        if(str2=="21年（252期）") anjienian = 21;
        if(str2=="20年（240期）") anjienian = 20;
        if(str2=="19年（228期）") anjienian = 19;
        if(str2=="18年（216期）") anjienian = 18;
        if(str2=="17年（204期）") anjienian = 17;
        if(str2=="16年（192期）") anjienian = 16;
        if(str2=="15年（180期）") anjienian = 15;
        if(str2=="14年（168期）") anjienian = 14;
        if(str2=="13年（156期）") anjienian = 13;
        if(str2=="12年（144期）") anjienian = 12;
        if(str2=="11年（132期）") anjienian = 11;
        if(str2=="10年（120期）") anjienian = 10;
        if(str2=="9年（108期）") anjienian = 9;
        if(str2=="8年（96期）") anjienian = 8;
        if(str2=="7年（84期）") anjienian = 7;
        if(str2=="6年（72期）") anjienian = 6;
        if(str2=="5年（60期）") anjienian = 5;
        if(str2=="4年（48期）") anjienian = 4;
        if(str2=="3年（36期）") anjienian = 3;
        if(str2=="2年（24期）") anjienian = 2;
        if(str2=="1年（12期）") anjienian = 1;
        //qDebug()<<str2<<"   "<<anjienian;
    });
    //获取还款方式
    connect(ui->radioButton_benjin,&QRadioButton::clicked,[=](){
        wayprime = 0;
        //qDebug()<<wayprime;
    });
    connect(ui->radioButton_benxi,&QRadioButton::clicked,[=](){
        wayprime = 1;
        //qDebug()<<wayprime;
    });
    //按下"开始计算"后计算 每月月供(首月月供、每月递减)、贷款总额、支付利息、还款总额、还款月数
    connect(ui->pushButton_jisuan,&QPushButton::clicked,[=](){
        double yuegong,shouyuegong, daizonge,lixi,huanzonge;
        int yueshu;
        //检查数据是否正确输入
        int rprime = 1;
        if(ui->lineEdit_gongjijine->text()=='\0'||ui->lineEdit_shangdaie->text()=='\0'||
                ui->lineEdit_gongjijinlilv->text()=='\0'||ui->lineEdit_shangdaililv->text()=='\0')
        {
            rprime = -1;
            QMessageBox::critical(this,"请输入数据！","贷款额与贷款利率均不能为空！");
        }
        if((ui->lineEdit_gongjijinlilv->text().toDouble()>=100||ui->lineEdit_shangdaililv->text().toDouble()>=100)&&rprime!=-1)
        {
            rprime = 0;
            QMessageBox::critical(this,"错误输入","贷款利率不能大于100%！");
        }
        if((shangdaie>=1000000||gongdaie>=1000000)&&rprime!=-1)
        {
            rprime = 0;
            QMessageBox::critical(this,"错误输入","贷款额不能大于1000000万！");
        }
        if(wayprime==1&&rprime==1)
        {
            if(shanglv!=0&&gonglv!=0)
            yuegong = (shangdaie*10000*shanglv*pow(1+shanglv,anjienian*12))/(pow(1+shanglv,anjienian*12)-1)
                    +(gongdaie*10000*gonglv*pow(1+gonglv,anjienian*12))/(pow(1+gonglv,anjienian*12)-1);
            if(shanglv==0&&gonglv!=0)
            yuegong = (gongdaie*10000*gonglv*pow(1+gonglv,anjienian*12))/(pow(1+gonglv,anjienian*12)-1);
            if(shanglv!=0&&gonglv==0)
            yuegong = (shangdaie*10000*shanglv*pow(1+shanglv,anjienian*12))/(pow(1+shanglv,anjienian*12)-1);
            daizonge = (shangdaie + gongdaie)*10000;
            lixi = yuegong*anjienian*12 - daizonge;
            huanzonge = yuegong*anjienian*12;
            yueshu = anjienian*12;
            qDebug()<<yuegong<<" "<<daizonge<<" "<<lixi<<" "<<huanzonge<<" "<<yueshu;
            //弹出模态对话框显示计算结果
            Dialog result;
            result.setWindowTitle("计算结果");
            QString yueg = QString::number(yuegong,10,2);
            QString dai = QString::number(daizonge,10,2);
            QString li = QString::number(lixi,10,2);
            QString huan = QString::number(huanzonge,10,2);
            QString yues = QString::number(yueshu);
            result.ui->lineEdit_yuegong->setText(yueg);
            result.ui->lineEdit_daizonge_1->setText(dai);
            result.ui->lineEdit_lixi_1->setText(li);
            result.ui->lineEdit_huanzonge_1->setText(huan);
            result.ui->lineEdit_yueshu_1->setText(yues);
            result.exec();
        }
        if(wayprime==0&&rprime==1)
        {
            shouyuegong = (shangdaie*10000/(anjienian*12))+shangdaie*10000*shanglv+
                    (gongdaie*10000/(anjienian*12))+gongdaie*10000*gonglv;
            daizonge = (shangdaie + gongdaie)*10000;
            lixi = (anjienian*12 + 1)*shangdaie*10000*shanglv/2 + (anjienian*12 + 1)*gongdaie*10000*gonglv/2;
            huanzonge = lixi + daizonge;
            yueshu = anjienian*12;
            qDebug()<<shouyuegong<<" "<<daizonge<<" "<<lixi<<" "<<huanzonge<<" "<<yueshu;
            //弹出模态对话框显示计算结果
            Dialog3 result;
            result.setWindowTitle("计算结果");
            QString shou = QString::number(shouyuegong,10,2);
            QString dai = QString::number(daizonge,10,2);
            QString li = QString::number(lixi,10,2);
            QString huan = QString::number(huanzonge,10,2);
            QString yues = QString::number(yueshu);
            result.ui->lineEdit_shouyuegong->setText(shou);
            result.ui->lineEdit_daizonge_2->setText(dai);
            result.ui->lineEdit_lixi_2->setText(li);
            result.ui->lineEdit_huanzonge_2->setText(huan);
            result.ui->lineEdit_yueshu_2->setText(yues);
            result.exec();
        }
    });
    //按下"清空重填"弹出dialog2
    connect(ui->pushButton_qingkong,&QPushButton::clicked,[=](){
        Dialog2 *clear = new Dialog2;
        clear->setWindowTitle("稍等！");
        connect(clear->ui->pushButton_no,&QPushButton::clicked,clear,&Dialog2::close);
        connect(clear->ui->pushButton_yes,&QPushButton::clicked,[=](){
            ui->lineEdit_gongjijine->clear();
            ui->lineEdit_gongjijinlilv->clear();
            ui->lineEdit_shangdaie->clear();
            ui->lineEdit_shangdaililv->clear();
            ui->comboBox_anjienianshu->setCurrentText("25年（300期）");
            clear->close();
        });
        clear->exec();
    });
}
Widget::~Widget()
{
    delete ui;
}
