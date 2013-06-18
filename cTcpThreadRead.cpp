#include <QDebug>
#include <QtGlobal>
#include "cTcpThreadRead.h"

CTcpThreadRead::CTcpThreadRead()
{
    isContinue_ = true;
    edit_ = NULL;
    mutex_ = NULL;
    queue_ = NULL;
}

CTcpThreadRead::~CTcpThreadRead()
{
    if(isContinue_)
        exitTcpThread();
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


        for(int i = 0; i < 10; ++i) {
            qDebug("intensity:%d", i);

            this->msleep(500);
        }
        break;
    }

    isContinue_ = true;
}
