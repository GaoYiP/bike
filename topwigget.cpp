#include "topwigget.h"

topwigget::topwigget(QWidget *parent) : QWidget(parent)
{
    //setFixedSize(600,150);
/***********set backgroundcolor******************/
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background,Qt::lightGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
/**************set widget********************/
    bt1 = new imageButton(QPixmap(":/ICON/Icon/sign.ico"),QPixmap(":/ICON/Icon/sign.ico"),this);
    bt1->setMinimumSize(60,60);

    bt2 = new imageButton(QPixmap(":/ICON/Icon/saoma3.png"),QPixmap(":/ICON/Icon/saoma1.png"),this);
    bt2->setMinimumSize(60,60);

    lb = new QLabel(this);
    lb->setAttribute(Qt::WA_TranslucentBackground, false);
/*********set label size color palce***********/
    QFont ft;
    ft.setPointSize(32);
    lb->setFont(ft);
    lb->setAlignment(Qt::AlignCenter);
    lb->setText(QObject::tr("<font color = red>%1</font>").arg("随 心 单 车"));
    lb->setScaledContents(true);
    lb->adjustSize();
    lb->setWordWrap(true);
    QHBoxLayout *hbox = new QHBoxLayout;
    //hbox->setMargin(0);
    hbox->addWidget(bt1);
    hbox->addStretch();
    hbox->addWidget(lb);
    hbox->addStretch();
    hbox->addWidget(bt2);
    setLayout(hbox);

    //bt1->installEventFilter(this);

}
