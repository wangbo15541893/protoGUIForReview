#include <QDebug>
#include <QtGlobal>
#include "cTcpThreadRead.h"

CTcpThreadRead::CTcpThreadRead()
{
    isContinue_ = true;
    edit_ = NULL;
    mutexRead_ = NULL;
    queueRead_ = NULL;
    mutexWrite_ = NULL;
    queueWrite_ = NULL;
}

CTcpThreadRead::~CTcpThreadRead()
{
    if(isContinue_)
        exitTcpThread();
    clearQueues();
}

void CTcpThreadRead::clearQueues()
{
  //clear read/write queue
}

void CTcpThreadRead::exitTcpThread(bool isContinue)
{
    isContinue_ = isContinue;
    while(!isContinue_)
        msleep(100);
    isContinue_ = false;
}

void CTcpThreadRead::sleep(unsigned long mSecs)
{
    this->msleep(mSecs);
}

void CTcpThreadRead::run()
{
    //Q_ASSERT_X((edit_ != NULL && queue_ != NULL), "error", "Invalid pointer in CTcpThread!");

    while (isContinue_) {
        mutexWrite_->lock();
        if(!queueWrite_->empty()) {
            if(tcpSocket.tcpWrite(queueWrite_->head()->buf_, queueWrite_->head()->len_)) {
                qDebug("tcpWrite:%s\n", queueWrite_->head()->buf_);
                delete queueWrite_->head()->buf_;
                queueWrite_->erase(queueWrite_->begin()); //???
            }
        }
        mutexWrite_->unlock();
        qDebug("tcpRead:in sleep redlen == %d", tcpSocket.readBufferSize());
        this->msleep(500);
    }

    isContinue_ = true;
}
