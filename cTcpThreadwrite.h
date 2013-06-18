#ifndef CTCPTHREADWRITE_H
#define CTCPTHREADWRITE_H

#include <QThread>
#include <QQueue>
#include <QMutex>

class ProtocalData {
    int callId_;
    int cmd_;
    int length_;
    void* protoBuf_;
};


class CTcpThreadWrite : public QThread
{
    Q_OBJECT
public:
    explicit CTcpThreadWrite(QObject *parent = 0);
    ~CTcpThreadWrite();

    void setTcpThreadEnv(QQueue<ProtocalData*>* queue, QMutex* mutex)
    { queue_ = queue; mutex_ = mutex; }
    void exitTcpThread(bool isContinue = false);
    
signals:
    
public slots:

protected:
    virtual void run();

private:
    QQueue<ProtocalData*>* queue_;
    bool isContinue_;
    QMutex* mutex_;
    
};

#endif // CTCPTHREADWRITE_H
