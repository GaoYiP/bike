/*
 * camera
 */
#include "widget.h"
#include <QScreen>
#include <QGuiApplication>
#include <QVBoxLayout>
#include <QUrl>
#include <QImage>
#include <QQuickItem>
#include <QHBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    flag = false;
    this->setAutoFillBackground(true);
    this->setMinimumSize(1300,800);
    this->setMaximumSize(1300,800);
    mywidget = new QWidget;
    quickwidget = new QQuickWidget(mywidget);
    timer = new QTimer;
    text = new QLineEdit;
    text->setReadOnly(true);
    bt = new QPushButton(mywidget);
    bt->setText(tr("手动输入车牌"));
    ok = new QPushButton(mywidget);
    ok->setText(tr("OK"));
    ok->setEnabled(false);
    label = new QLabel(mywidget);
    label->setText(tr("对准车牌上的二维码，即可自动扫描"));
    label->adjustSize();
    label->setMaximumSize(1300,20);
    label->setGeometry(500,20,100,30);
    camera = new QCamera;

    quickwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    QUrl sources("qrc:/qml.qml");
    quickwidget->setSource(sources);
    //QQuickItem* root = quickwidget->rootObject();
    //camera = root->findChild<QCamera*>("camera");
    //label->setScaledContents(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(label);
    hbox->addStretch();

    QHBoxLayout *hbox1 = new QHBoxLayout;
    hbox1->addStretch();
    hbox1->addWidget(bt);
    hbox1->addStretch();

    QHBoxLayout *hbox2 = new QHBoxLayout;
    hbox2->addWidget(ok);
    hbox2->addWidget(text);

    QVBoxLayout *vbox = new QVBoxLayout(mywidget);
    vbox->addLayout(hbox);
    vbox->addWidget(quickwidget);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    //vbox->addWidget(label);
    setLayout(vbox);

    connect(bt,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Screenshots()));
    timer->start(2000);
    //socket.connectToHost("192.168.3.166",8686);


}

Widget::~Widget()
{

}
void Widget::scanning(QImage image)
{
    QZXing decoder;
    QString msg = decoder.decodeImage(image);
    int len = msg.length();
    if(len > 0)
    {
        qDebug()<<msg;
        text->setText(msg);
        //char *p = msg.toLatin1().data();
        //socket.write(p);
        emit bike_num(text->text());
        flag = true;
    }

}
void Widget::Screenshots()
{
    //qDebug()<<"test";
    if(flag == false){
        pixmap = QWidget::grab();
        QImage image = pixmap.toImage();
        scanning(image);
    }
    //qDebug()<<image;

}
void Widget::input()
{
    timer->stop();
    quickwidget->close();
    mywidget->close();
    ok->setEnabled(true);
    text->setReadOnly(false);
}
void Widget::send()
{
    emit bike_num(text->text());
    //qDebug()<<"hhhhhhhhhhhhhhhhhhhhhhhhh";
}
