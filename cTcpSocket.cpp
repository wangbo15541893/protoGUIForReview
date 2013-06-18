#include "cTcpSocket.h"
#include "message.pb.h"

CTcpSocket::CTcpSocket()
{
}

void CTcpSocket::displayError(QAbstractSocket::SocketError socketError)
{
    //com::liqu::protobuf::AppList::ParseFromString()
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug("RemoteHostClosedError");
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug("The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug("The connection was refused by the peer.Make sure the fortune server is running,and check that the host name and port settings are correct.");
        break;
    default:
        qDebug("The following error occurred: %s", (char*)(this->errorString().data()));
    }
}
bool CTcpSocket::tcpConnect(QString svrName, quint16 srvPort)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(tcpRead()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    const int tOut = 5 * 1000;
    connectToHost(svrName, srvPort);
    if (!waitForConnected(tOut)) {
        qDebug("waitForConnected:error\n");
        //emit error(socket.error(), socket.errorString());
        return false;
    }
    qDebug("connect ok!\n");
    return true;
}

void CTcpSocket::tcpWrite(char* buf, qint64 len)
{
    //this->waitForBytesWritten();
    write(buf, len);
}

void CTcpSocket::tcpRead()
{
    qDebug("readin==\n");
    QByteArray datagram;
    datagram.resize(this->bytesAvailable());
    qDebug("bytesAvailable==%d\n", bytesAvailable());

    this->read(datagram.data(), datagram.size());
    QDataStream in(&datagram, QIODevice::ReadOnly);

    int m1;
    in >> m1;
    qDebug("read1==%d\n", m1);
    in >> m1;
    qDebug("read2==%d\n", m1);
    in >> m1;
    qDebug("read3==%d\n", m1);
    in >> m1;
    qDebug("read4==%d\n", m1);

    qDebug("read ok!\n");
}

void CTcpSocket::tcpClose()
{
    this->close();
}
