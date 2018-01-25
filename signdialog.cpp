#include "signdialog.h"
#include <QBrush>
signdialog::signdialog()
{
    s = new QList<QString>;
    s->append(":/ICON/Icon/mobike0.jpg");
    s->append(":/ICON/Icon/mobike1.jpg");
    s->append(":/ICON/Icon/mobike2.jpg");
    s->append(":/ICON/Icon/mobike3.jpg");
    s->append(":/ICON/Icon/mobike4.jpg");
    s->append(":/ICON/Icon/mobike5.jpg");
    s->append(":/ICON/Icon/mobike6.jpg");
    startTimer(800);

    lb =new QLabel(this);
    lb->setStyleSheet("background:transparent");
    QFont ft;
    ft.setPointSize(20);
    lb->setFont(ft);
    lb->setAlignment(Qt::AlignCenter);
    lb->setText(QObject::tr("<font color = black>%1</font>").arg("输入账户和密码"));
    lb->adjustSize();

    le_id =new QLineEdit(this);
    le_id->setPlaceholderText("请输入手机号码");
    QRegExp reg("[0-9]+$");//限制输入内容为数字
    QRegExpValidator *pValidator = new QRegExpValidator;
    pValidator->setRegExp(reg);
    le_id->setValidator(pValidator);

    le_pswd = new QLineEdit(this);
    le_pswd->setPlaceholderText("请输入密码");//设置预留信息

    bt_sign = new imageButton(QPixmap(":/ICON/Icon/login0.png"),QPixmap(":/ICON/Icon/login1.png"),this);

    bt_register = new imageButton(QPixmap(":/ICON/Icon/regist0.png"),QPixmap(":/ICON/Icon/register1.png"),this);

    closebt = new imageButton(QPixmap(":/ICON/Icon/close.png"),QPixmap(":/ICON/Icon/close.png"),this);


    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setContentsMargins(0,0,0,0);
    hbox->addStretch();
    hbox->addWidget(bt_sign);
    hbox->addWidget(bt_register);
    hbox->addStretch();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->setContentsMargins(0,0,0,this->height()/10);
    vbox->addWidget(closebt,0,Qt::AlignLeft);
    vbox->addWidget(lb,0,Qt::AlignCenter);
    vbox->addStretch(0);
    vbox->addWidget(le_id,0,Qt::AlignCenter);
    vbox->addWidget(le_pswd,0,Qt::AlignCenter);
    //vbox->addStretch(0);//不设大小的弹簧
    vbox->addSpacing(this->height()/15);
    vbox->addLayout(hbox);

    setLayout(vbox);
    //this->setContentsMargins(0,0,0,0);
    /**/
    //this->setWindowFlags(Qt::FramelessWindowHint);


    connect(le_id,SIGNAL(textEdited(QString)),this,SLOT(lb_show1()));
    connect(le_pswd,SIGNAL(textEdited(QString)),this,SLOT(lb_show2()));
    connect(closebt,SIGNAL(clicked(bool)),this,SLOT(dia_windowclose()));
    connect(bt_sign,SIGNAL(clicked(bool)),this,SLOT(bt_sign_pushed()));
    connect(bt_register, SIGNAL(clicked(bool)), this, SLOT(bt_register_pushed()));
}
