#include "bike_socket.h"

bike_socket::bike_socket(QObject *parent) : QObject(parent)
{
    client_socket = 0;
}

void bike_socket::connectToServer(const QString server_ip, quint16 port)
{
    if(client_socket) return;
    client_socket = new QTcpSocket(this);
    connect(client_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    client_socket->connectToHost(server_ip, port);
}
void bike_socket::onReadyRead()
{
    QString recv_data(client_socket->readAll());
//    qDebug()<<"onReadyRead="<<recv_data;
    msg_resolve(recv_data);/*解析*/

}
void bike_socket::disconnectFromServer()
{
    client_socket->close();
    client_socket->deleteLater();
    client_socket = 0;
}

void bike_socket::msg_resolve(QString msg)
{
    qDebug()<<"msg_resolve="<<msg;
    if(msg.startsWith("regist#"))
    {
        if(msg.endsWith("true"))
        {
            emit sign_msg(0);
        }
        else
        if(msg.endsWith("false"))
        {
            emit sign_msg(1);
        }
    }
    if(msg.startsWith("login#"))
    {
        if(msg.endsWith("true"))
        {
            emit sign_msg(2);
        }
        else
        if(msg.endsWith("false"))
        {
            emit sign_msg(3);
        }
    }
    if(msg.startsWith("&marker="))
    {
        emit marker(msg);
    }
    if(msg.startsWith("&center="))
    {
        emit center_var(msg);
    }
}
