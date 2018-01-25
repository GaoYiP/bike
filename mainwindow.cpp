#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{

     map = new BaiduMap(this);
     map->setLocation(104.07359,30.647005);
//     map->addMarker(104.073698,30.647728);
//     map->addMarker(104.075351,30.646318);
//     map->addMarker(104.072225,30.647378);
//     map->addMarker(104.076285,30.646637);
//     map->addMarker(104.074884,30.647197);
     map->setZoom(18);
//     map->sendRequire();

     wig = new topwigget(this);
     dia = new signdialog;

     tcp_socket = new bike_socket(this);
     tcp_socket->connectToServer();
     tcp_socket->set_msg_data("location");
     //tcp_socket->connectToServer("192.168.3.123");

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(wig);
     vbox->addWidget(map);
     vbox->setContentsMargins(0,0,0,1);

     c_wig = new QWidget(this);
     this->setCentralWidget(c_wig);
     c_wig->setLayout(vbox);



     connect(wig->bt1,SIGNAL(clicked(bool)),this,SLOT(mysign()));
     connect(wig->bt2,SIGNAL(clicked(bool)),this,SLOT(sao_yi_sao()));
     connect(dia,SIGNAL(dia_close()),this,SLOT(dia_close_bt_pushed()));
     connect(dia, SIGNAL(msg(QString)), tcp_socket, SLOT(set_msg_data(QString)));
     connect(tcp_socket, SIGNAL(sign_msg(int)), dia, SLOT(sign_msg(int)));
     connect(tcp_socket, SIGNAL(center_var(QString)), map, SLOT(center_eql(QString)));
     connect(tcp_socket, SIGNAL(marker(QString)), map, SLOT(marker_eql(QString)));
}

MainWindow::~MainWindow()
{

}
