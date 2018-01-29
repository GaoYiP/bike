#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QPushButton>
#include <QToolBar>
#include <QDebug>
#include <QString>
#include <QBuffer>
#include <QMap>
#include <QTcpSocket>
#include <QTcpServer>
#include <QAbstractSocket>
#include <QByteArray>
#include <QInputDialog>
#include <QEvent>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include "topwigget.h"
#include "signdialog.h"
#include "BMap/baidumap.h"
#include "bike_socket/bike_socket.h"
#include "widget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
//public:
//    bool eventFilter(QObject *watched, QEvent *event)
//    {
//        if(watched == wig->bt1){
//            qDebug()<<"**********1";
//            if(event->type() == QEvent::MouseButtonDblClick)
//            {
//                qDebug()<<"**********1";
//                dia->exec();
//            }
//        }
//        return true;
//    }
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void get_bike_num(QString bikenum)
    {
        //qDebug()<<"hhhhhhhhhhhhhhhhhhh2";
        if(dia->signok == false)
        {
            QMessageBox::about(this,"something","请登录");
            saoma->close();
            saoma->deleteLater();
            return;
        }
        tcp_socket->set_msg_data("unlock#" + bikenum);
        QMessageBox::about(this,"something","扫码成功");
        saoma->close();
        saoma->deleteLater();
    }
    void mysign(void)
    {
        map->setDisabled(true);
        dia->exec();

    }
    void sao_yi_sao()
    {

        saoma = new Widget(this);
        saoma->show();
        saoma->setFixedSize(this->size());
        connect(saoma,SIGNAL(bike_num(QString)),this,SLOT(get_bike_num(QString)));
    }
    void dia_close_bt_pushed()
    {
        dia->close();
        map->setDisabled(false);
        map->sendRequire();
    }

protected:
    void paintEvent(QPaintEvent *event)
    {

        float width = this->width();
        float height = this->height();
        map->setFixedSize(width,height/1.2);
        //qDebug()<<"map.size"<<map->size();
        //wig->setFixedSize(width,height/12);
        width /= 1.5;
        height /= 2;
        dia->setFixedSize(width,height);
    }
private:

    QToolBar *tooltool;
    QAction *sign,*mess;
    topwigget *wig;
    signdialog *dia;
    BaiduMap *map;
    bike_socket *tcp_socket;
    QWidget *c_wig;
    Widget *saoma;
};

#endif // MAINWINDOW_H
