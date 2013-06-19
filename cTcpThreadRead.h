#ifndef CTCPTHREADREAD_H
#define CTCPTHREADREAD_H

#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QByteArray>
#include "mainwindow.h"
#include "cTcpSocket.h"
#include "dataType.h"

class CTcpThreadRead : public QThread
{
public:
    CTcpThreadRead();
    ~CTcpThreadRead();

    void setTcpThreadEnv(TextEdit* edit, QQueue<ProtocalData*>* queueRead, QMutex* mutexRead, QQueue<ProtocalWrite*>* queueWrite, QMutex* mutexWrite)
    { edit_ = edit; tcpSocket.queueRead_ = queueRead_ = queueRead; tcpSocket.mutexRead_ = mutexRead_ = mutexRead; queueWrite_ = queueWrite; mutexWrite_ = mutexWrite;}
    bool connectTcpServer(QString svrName, quint16 srvPort)
    {
        return tcpSocket.tcpConnect(svrName, srvPort); // "127.0.0.1", 8080);
    }

  //  void setTextEdit(TextEdit* edit) { edit_ = edit; };
  //  void setProtocalDataQueue(QQueue<ProtocalData*>* queue) { queue = queue_; };

    void sleep(unsigned long mSecs);
    void exitTcpThread(bool isContinue = false);

protected:
    virtual void run();
    void clearQueues();

private:
    TextEdit * edit_;
    QQueue<ProtocalData*>* queueRead_;
    QQueue<ProtocalWrite*>* queueWrite_;
    bool isContinue_;
    QMutex* mutexRead_;
    QMutex* mutexWrite_;
    CTcpSocket tcpSocket;
};

#endif // CTcpThreadRead_H
