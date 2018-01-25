#ifndef BAIDUMAP_H
#define BAIDUMAP_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFile>
#include <imageButton/imagebutton.h>

class BaiduMap : public QWidget
{
    Q_OBJECT
public slots:
    void replyFinished(QNetworkReply* reply)
    {
        qDebug()<<"----replyFinished\n";
        QByteArray data = reply->readAll();
        pix.loadFromData(data, "PNG");
        map_label->setPixmap(pix);

        reply->deleteLater();
    }
    void addMarker(double x,double y)
    {
        map_markers += "|" + QString::number(x) + "," + QString::number(y);
    }
    void marker_eql(QString mar)
    {
        map_markers += mar.remove("&marker=").prepend("|");
    }
    void center_eql(QString cen)
    {
        map_center = cen;
        sendRequire();
    }

    void setLocation(double x,double y)
    {
        map_markers = "&markers=" + QString::number(x) + "," + QString::number(y);
        back_x = x;
        back_y = y;
        center_x = x;
        center_y = y;
    }
//    void zoom_changed(int val)
//    {
//        zoom_val = val;
//    }

    void setZoom(int z)
    {
        zoom_val = z;
    }
//    void sendRequire()
//    {
//        map_url = "http://api.map.baidu.com/staticimage/v2?ak=XbtDOSgkG8Hl5Sqr5ACOI3CLvZZNNGgx&mcode=666666&markerStyles=l,0,0xC0C0C0|l,1,0xFF0000|l,2,0xFF0000|l,3,0xFF0000|l,4,0xFF0000|l,5,0xFF0000";
//        map_url = map_url + map_center + map_zoom.arg(zoom_val) + map_markers + map_size.arg(map_w).arg(map_h);
//        manager->get(QNetworkRequest(QUrl(map_url)));
//    }

    void sendRequire()
    {
        map_url = "http://api.map.baidu.com/staticimage/v2?ak=XbtDOSgkG8Hl5Sqr5ACOI3CLvZZNNGgx&mcode=666666&markerStyles=l,0,0xC0C0C0|l,1,0xFF0000|l,2,0xFF0000|l,3,0xFF0000|l,4,0xFF0000|l,5,0xFF0000";
        map_url = map_url + map_center.arg(center_x).arg(center_y) + map_zoom.arg(zoom_val) + map_markers + map_size.arg(map_w).arg(map_h);
        manager->get(QNetworkRequest(QUrl(map_url)));
        qDebug()<<map_url;
    }
protected slots:
    void toUp();
    void toDown();
    void toLeft();
    void toRight();
    void toBack()
    {
        center_x = back_x;
        center_y = back_y;
        sendRequire();
    }
    void zoom_pp()
    {
        if(zoom_val == 19) return;
        ++zoom_val;
        setZoom(zoom_val);
        sendRequire();
    }
    void zoom_dd()
    {
        if(zoom_val == 4) return;
        --zoom_val;
        setZoom(zoom_val);
        sendRequire();
    }
public:
    BaiduMap(QWidget *parent = 0);
    ~BaiduMap();
protected:
    void paintEvent(QPaintEvent *event)
    {
            map_w = map_label->width() < 1024 ? map_label->width() : 1024;
            map_h = map_label->height() < 1024 ? map_label->height() : 1024;
//            sendRequire();
            //float x = (this->width() < this->height())?map_w:map_h;
            //qDebug()<<"map_label"<<map_label->size();
           // qDebug()<<"up"<<up->size();
            up->setFixedSize(map_label->width()/10,map_label->width()/10);
            down->setFixedSize(up->size());
            left->setFixedSize(up->size());
            right->setFixedSize(up->size());
            zoom_in->setFixedSize(up->size());
            zoom_out->setFixedSize(up->size());
            back->setFixedSize(up->size());
            map_label->setFixedSize(this->width(),this->height()-this->width()/10);

    }

    void timerEvent(QTimerEvent *event)
    {
        sendRequire();
    }

private:
    QNetworkAccessManager *manager;
    QLabel *map_label;
    QString map_url,
            map_center="&center=%1,%L2",
            map_zoom="&zoom=%1",
            map_markers,
            map_size="&width=%1&height=%L2";
    int zoom_val = 15,map_w,map_h;
    double center_x,center_y,back_x,back_y;
    QPixmap pix;
    imageButton *up,*down,*left,*right,*zoom_in,*zoom_out,*back;

};

#endif // BAIDUMAP_H
