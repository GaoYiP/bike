#ifndef BIKE_SOCKET_H
#define BIKE_SOCKET_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>

class bike_socket : public QObject
{
    Q_OBJECT
public:
    explicit bike_socket(QObject *parent = 0);

    void connectToServer(const QString server_ip="192.168.3.245", quint16 port=8888);
    void disconnectFromServer();

protected:
    void msg_resolve(QString msg);
signals:
    void sign_msg(int num);//0:regist#true,1:regist#false; 2:login#true,3:login#false;
    void marker(QString mark);
    void center_var(QString mark);
public slots:
    void set_msg_data(QString data)
    {
        client_socket->write(data.toStdString().c_str());
    }
protected slots:
    void onReadyRead();

private:
    QTcpSocket *client_socket;
};

#endif // BIKE_SOCKET_H
