#include "baidumap.h"

BaiduMap::BaiduMap(QWidget *parent)
    : QWidget(parent)
{
    map_label = new QLabel(this);
    //QPushButton *up,*down,*left,*right,zoom_in,zoom_out;
    up = new imageButton(QPixmap(":/map_icon/BMap/icon/Up.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    down = new imageButton(QPixmap(":/map_icon/BMap/icon/Down.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    left = new imageButton(QPixmap(":/map_icon/BMap/icon/Left.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    right = new imageButton(QPixmap(":/map_icon/BMap/icon/Right.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    zoom_in = new imageButton(QPixmap(":/map_icon/BMap/icon/zoomin.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    zoom_out = new imageButton(QPixmap(":/map_icon/BMap/icon/zoomout.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);

    back = new imageButton(QPixmap(":/map_icon/BMap/icon/locate.png"),QPixmap(":/map_icon/BMap/icon/press.png"),this);


    map_label->setPixmap(QPixmap(":/map_icon/BMap/icon/v2.png"));
    map_label->setAlignment(Qt::AlignCenter);


    QHBoxLayout *hbox0 = new QHBoxLayout;
    hbox0->setMargin(0);
    hbox0->addWidget(zoom_in);
    hbox0->addWidget(zoom_out);
    hbox0->addWidget(up);
    hbox0->addWidget(down);
    hbox0->addWidget(left);
    hbox0->addWidget(right);
    hbox0->addWidget(back);

    QVBoxLayout *vbox0 = new QVBoxLayout;
    vbox0->setMargin(0);
    vbox0->addWidget(map_label);
    vbox0->addLayout(hbox0);
    this->setLayout(vbox0);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    connect(zoom_in,SIGNAL(clicked(bool)),this,SLOT(zoom_pp()));
    connect(zoom_out,SIGNAL(clicked(bool)),this,SLOT(zoom_dd()));
    connect(up,SIGNAL(clicked(bool)),this,SLOT(toUp()));
    connect(down,SIGNAL(clicked(bool)),this,SLOT(toDown()));
    connect(left,SIGNAL(clicked(bool)),this,SLOT(toLeft()));
    connect(right,SIGNAL(clicked(bool)),this,SLOT(toRight()));
    connect(back,SIGNAL(clicked(bool)),this,SLOT(toBack()));

    this->startTimer(10000);

}

BaiduMap::~BaiduMap()
{

}
void BaiduMap::toUp()
{
    switch (zoom_val) {
    case 19:
        center_y += 0.0002;
        break;
    case 18:
        center_y += 0.0004;
        break;
    case 17:
        center_y += 0.0008;
        break;
    case 16:
        center_y += 0.0016;
        break;
    case 15:
        center_y += 0.0032;
        break;
    case 14:
        center_y += 0.0064;
        break;
    case 13:
        center_y += 0.0128;
        break;
    case 12:
        center_y += 0.0256;
        break;
    case 11:
        center_y += 0.0512;
        break;
    case 10:
        center_y += 0.1024;
        break;
    case 9:
        center_y += 0.2048;
        break;
    case 8:
        center_y += 0.4096;
        break;
    case 7:
        center_y += 0.8192;
        break;
    case 6:
        center_y += 1.6384;
        break;
    case 5:
        center_y += 3.2786;
        break;
    case 4:
        center_y += 6.5536;
        break;
    case 3:
        center_y += 13.1072;
        break;
    default:
        break;
    }
    sendRequire();
}
void BaiduMap::toDown()
{
    switch (zoom_val) {
    case 19:
        center_y -= 0.0002;
        break;
    case 18:
        center_y -= 0.0004;
        break;
    case 17:
        center_y -= 0.0008;
        break;
    case 16:
        center_y -= 0.0016;
        break;
    case 15:
        center_y -= 0.0032;
        break;
    case 14:
        center_y -= 0.0064;
        break;
    case 13:
        center_y -= 0.0128;
        break;
    case 12:
        center_y -= 0.0256;
        break;
    case 11:
        center_y -= 0.0512;
        break;
    case 10:
        center_y -= 0.1024;
        break;
    case 9:
        center_y -= 0.2048;
        break;
    case 8:
        center_y -= 0.4096;
        break;
    case 7:
        center_y -= 0.8192;
        break;
    case 6:
        center_y -= 1.6384;
        break;
    case 5:
        center_y -= 3.2786;
        break;
    case 4:
        center_y -= 6.5536;
        break;
    case 3:
        center_y -= 13.1072;
        break;
    default:
        break;
    }
    sendRequire();
}
void BaiduMap::toLeft()
{
    switch (zoom_val) {
        case 19:
            center_x -= 0.001;
            break;
        case 18:
            center_x -= 0.001;
            break;
        case 17:
            center_x -= 0.001;
            break;
        case 16:
            center_x -= 0.0016;
            break;
        case 15:
            center_x -= 0.0032;
            break;
        case 14:
            center_x -= 0.0064;
            break;
        case 13:
            center_x -= 0.0128;
            break;
        case 12:
            center_x -= 0.0256;
            break;
        case 11:
            center_x -= 0.0512;
            break;
        case 10:
            center_x -= 0.1024;
            break;
        case 9:
            center_x -= 0.2048;
            break;
        case 8:
            center_x -= 0.4096;
            break;
        case 7:
            center_x -= 0.8192;
            break;
        case 6:
            center_x -= 1.6384;
            break;
        case 5:
            center_x -= 3.2786;
            break;
        case 4:
            center_x -= 6.5536;
            break;
        case 3:
            center_x -= 13.1072;
            break;
        default:
            break;
    }
    sendRequire();
}
void BaiduMap::toRight()
{
    switch (zoom_val) {
        case 19:
            center_x += 0.001;
            break;
        case 18:
            center_x += 0.001;
            break;
        case 17:
            center_x += 0.001;
            break;
        case 16:
            center_x += 0.0016;
            break;
        case 15:
            center_x += 0.0032;
            break;
        case 14:
            center_x += 0.0064;
            break;
        case 13:
            center_x += 0.0128;
            break;
        case 12:
            center_x += 0.0256;
            break;
        case 11:
            center_x += 0.0512;
            break;
        case 10:
            center_x += 0.1024;
            break;
        case 9:
            center_x += 0.2048;
            break;
        case 8:
            center_x += 0.4096;
            break;
        case 7:
            center_x += 0.8192;
            break;
        case 6:
            center_x += 1.6384;
            break;
        case 5:
            center_x += 3.2786;
            break;
        case 4:
            center_x += 6.5536;
            break;
        case 3:
            center_x += 13.1072;
            break;
        default:
            break;
    }
    sendRequire();
}
