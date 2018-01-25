#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QQuickWidget>
#include "QZXing/QZXing.h"
#include <QLineEdit>
#include <QFile>
#include <QFileDialog>
#include <QTcpSocket>
#include <QCamera>
#include <QLabel>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void bike_num(QString);
public slots:
    void Screenshots();
    void send();
    void scanning(QImage image);
    void input();
private:
    QWidget *mywidget;
    QQuickWidget *quickwidget;// = Q_NULLPTR;
    QPixmap pixmap;
    QPixmap pix;
    QTimer *timer;
    QLineEdit *text;
    QTcpSocket socket;
    QCamera *camera;
    QLabel *label;
    QPushButton *bt;
    QPushButton *ok;
    bool flag;

};

#endif // WIDGET_H
