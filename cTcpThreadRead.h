#ifndef CTCPTHREADREAD_H
#define CTCPTHREADREAD_H

#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QByteArray>
#include "mainwindow.h"

class ProtocalData {
    int callId_;
    int cmd_;
    int length_;
    QByteArray bypeArray_; //pic == context multi cellphone support
};


class CTcpThreadRead : public QThread
{
public:
    CTcpThreadRead();
    ~CTcpThreadRead();

    void setTcpThreadEnv(TextEdit* edit, QQueue<ProtocalData*>* queue, QMutex* mutex)
    { edit_ = edit; queue_ = queue; mutex_ = mutex; }

    void setTextEdit(TextEdit* edit) { edit_ = edit; };
    void setProtocalDataQueue(QQueue<ProtocalData*>* queue) { queue = queue_; };

    void sleep(unsigned long mSecs);

    void exitTcpThread(bool isContinue = false);

protected:
    virtual void run();

private:
    TextEdit * edit_;
    QQueue<ProtocalData*>* queue_;
    bool isContinue_;
    QMutex* mutex_;
};

#endif // CTcpThreadRead_H
