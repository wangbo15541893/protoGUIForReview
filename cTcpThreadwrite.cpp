#include "cTcpThreadwrite.h"

CTcpThreadWrite::CTcpThreadWrite(QObject *parent) :
    QThread(parent)
{
    isContinue_ = true;
    mutex_ = NULL;
    queue_ = NULL;
}

CTcpThreadWrite::~CTcpThreadWrite()
{
    if(isContinue_)
        exitTcpThread();
}

void CTcpThreadWrite::exitTcpThread(bool isContinue)
{
    isContinue_ = isContinue;
    while(!isContinue_)
        msleep(100);
    isContinue_ = false;
}

void CTcpThreadWrite::run()
{
    //Q_ASSERT_X((queue_ != NULL), "error", "Invalid pointer in CTcpThread!");

    while (isContinue_) {


        for(int i = 0; i < 10; ++i) {
            qDebug("intensity:%d", i);

            this->msleep(500);
        }
        break;
    }

    isContinue_ = true;
}

