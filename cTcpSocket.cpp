#include "cTcpSocket.h"
#include "message.pb.h"

CTcpSocket::CTcpSocket()
{
    isInProtoBuf_ = false;
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

qint64 CTcpSocket::tcpWrite(char* buf, qint64 len)
{
    //this->waitForBytesWritten();
    while(len > 0) {
       qint64 wLen = write(buf, len);
       if(wLen < 0)
           return -1;
       len -= wLen;
    }
    return 0;
}

void CTcpSocket::tcpRead()
{
    qDebug("readin==\n");
    char* buf = new char[bytesAvailable()];
    assert(bytesAvailable() > 12);
    qDebug("bytesAvailable==%s\n", buf);

    this->read(buf, bytesAvailable());

    //mutexRead_->lock();
    if(!isInProtoBuf_) {
        data_ = new ProtocalData();
        curDataLen_ = 0;
        ++indexCmd_;
        qDebug("callID==%d\n", *((int*)&buf[0]));
        data_->callId_ = *((int*)&buf[0]);
        qDebug("cmdID==%d\n", *((int*)&buf[4]));
        data_->cmd_ = *((int*)&buf[4]);
        qDebug("len==%d\n", *((int*)&buf[8]));
        data_->length_ = *((int*)&buf[8]);

        curDataLen_ += bytesAvailable() - 12;
        data_->bypeArray_.append(&buf[12], curDataLen_);
        qDebug("bytearray=len==%d==%s\n", data_->bypeArray_.length(), &buf[12]);

        if(curDataLen_ < data_->length_)
            isInProtoBuf_ = true;
    } else {
        //if(bytesAvailable() < )
        data_->bypeArray_.append(buf, bytesAvailable());
        curDataLen_ += bytesAvailable();
        if(curDataLen_ >= data_->length_)
            isInProtoBuf_ = true;
    }

    qDebug("read ok!\n");
}

void CTcpSocket::tcpClose()
{
    this->close();
}
