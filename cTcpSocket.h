#ifndef CTCPSOCKET_H
#define CTCPSOCKET_H

#include <QTcpSocket>
#include <QDataStream>
#include <QIODevice>

class CTcpSocket : public QTcpSocket
{
    Q_OBJECT
public slots:
    void tcpWrite(char* buf, qint64 len);
    void tcpRead();
    void displayError(QAbstractSocket::SocketError socketError);
public:
    CTcpSocket();

    bool tcpConnect(QString svrName, quint16 srvPort);

    void tcpClose();
};

#endif // CTCPSOCKET_H
