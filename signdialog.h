#ifndef SIGNDIALOG_H
#define SIGNDIALOG_H

#include <QWidget>
#include <QWidget>
#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegExpValidator>
#include <QDebug>
#include <QEvent>
#include <QToolButton>
#include <QPixmap>
#include <QStyle>
#include <QPalette>
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QMessageBox>
#include <imageButton/imagebutton.h>

class signdialog : public QDialog
{
    Q_OBJECT
public:
    signdialog();
    QLineEdit *le_id;
    bool signok=false;
protected:
//    void eventFilter(QObject *watched, QEvent *event)
//    {
//        if(watched == bt_sign)
//    }
    void timerEvent(QTimerEvent *event)
    {
        ++i;
        if(i == 7)
            i=0;
        update();
    }
    void paintEvent(QPaintEvent *event)
    {
          QPainter painter(this);
          QPixmap pixmap = QPixmap(s->at(i));
          painter.drawPixmap(QRect(0,0,this->width(),this->height()),pixmap);

          float width = this->width();
          width /= 1.5;
          float height = this->height();
          height /= 7;
          lb->setFixedSize(width,height);
          //qDebug()<<this->size()<<"lb"<<lb->size();

          le_id->setFixedSize(width,height);
          le_pswd->setFixedSize(width,height);
          height /= 1.5;
          bt_sign->setFixedSize(width/2,height);
          bt_register->setFixedSize(width/2,height);
          closebt->setFixedSize(width/12,width/12);
    }
signals:
    void dia_close();
    void msg(QString);

public slots:
    void sign_msg(int num)//0:regist#true,1:regist#false; 2:login#true,3:login#false;
    {
        qDebug()<<"sign_msg"<<num;
        switch (num) {
        case 0:
            lb->setPixmap(QPixmap(":/ICON/Icon/registerok.png"));
            le_id->clear();
            le_pswd->clear();
            break;
        case 1:
            lb->setPixmap(QPixmap(":/ICON/Icon/accounterror.png"));
            le_id->clear();
            le_pswd->clear();
            break;
        case 2:
            lb->setPixmap(QPixmap(":/ICON/Icon/signok.png"));
            signok=true;
            le_id->clear();
            le_pswd->clear();
            dia_windowclose();
            break;
        case 3:
            lb->setPixmap(QPixmap(":/ICON/Icon/signerror.png"));
            le_id->clear();
            le_pswd->clear();
            break;
        default:
            break;
        }
    }

private slots:
    void lb_show1(void)
    {
        lb->setPixmap(QPixmap(":/ICON/Icon/account.png"));
    }
    void lb_show2(void)
    {
        lb->setPixmap(QPixmap(":/ICON/Icon/password.png"));
    }
    void dia_windowclose(void)
    {
        emit dia_close();
        this->close();
    }
    void bt_sign_pushed()
    {
        if(le_id->text().isEmpty())
        {
            return;
        }
        if(le_pswd->text().isEmpty())
        {

            return;
        }
        emit msg("login#" + le_id->text()+ "#" +le_pswd->text());
    }
    void bt_register_pushed()
    {
        if(le_id->text().isEmpty())
        {

            return;
        }
        if(le_pswd->text().isEmpty())
        {

            return;
        }
        emit msg("regist#" + le_id->text()+ "#" +le_pswd->text());
    }
private:
    QLabel *lb;
    QLineEdit *le_pswd;
    imageButton *bt_sign,*bt_register,*closebt;
    QList<QString> *s;
    int i = 0;

};

#endif // SIGNDIALOG_H
