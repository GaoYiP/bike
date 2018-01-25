#ifndef TOPWIGGET_H
#define TOPWIGGET_H
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QPixmap>
#include <imageButton/imagebutton.h>
class topwigget : public QWidget
{
    Q_OBJECT
public:
    explicit topwigget(QWidget *parent = 0);

protected:

signals:

public slots:

public:
    imageButton *bt1,*bt2;
    QLabel *lb;
};

#endif // TOPWIGGET_H
