#ifndef CTCPSOCKET_H
#define CTCPSOCKET_H

#include <QTcpSocket>
#include <QDataStream>
#include <QIODevice>
#include <QQueue>
#include <QMutex>
#include <QString>
#include "dataType.h"

class CTcpSocket : public QTcpSocket
{
    Q_OBJECT
public slots:
    qint64 tcpWrite(char* buf, qint64 len);
    void tcpRead();
    void displayError(QAbstractSocket::SocketError socketError);
public:
    CTcpSocket();

    bool tcpConnect(QString svrName, quint16 srvPort);
    void tcpClose();

    QQueue<ProtocalData*>* queueRead_;
    QMutex* mutexRead_;
    bool isInProtoBuf_;
    qint64 indexCmd_;
    qint64 curDataLen_;
    ProtocalData * data_;
};

#endif // CTCPSOCKET_H
