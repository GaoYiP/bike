#include "baidumap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaiduMap w;
    w.setFixedSize(300,600);
    w.setLocation(116.414983,39.910332);
    w.addMarker(116.415019,39.910463);
    w.addMarker(116.414543,39.910684);
    w.addMarker(116.415983,39.910332);
    w.addMarker(116.415405,39.911058);
    w.addMarker(116.415747,39.910857);
    w.setZoom(18);
    w.sendRequire();
    w.show();

    return a.exec();
}
