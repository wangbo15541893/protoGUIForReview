#include <QApplication>
#include <QTime>
#include <QtNetwork>
#include "mainwindow.h"
#include "amessage.pb.h"
#include "cTcpThreadRead.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEdit mw;
    //mw.maximumSize(QSize(0, 0));
    mw.resize( 00, 00 );

    //Message msg1;
    mw.printText(QString("Andy test!\n"));
    mw.show();

    CTcpThreadRead tcpRead;
    QQueue<ProtocalData*> queueRead_;
    QQueue<ProtocalWrite*> queueWrite_;
    QMutex mutexRead_;
    QMutex mutexWrite_;

    tcpRead.setTcpThreadEnv(&mw, &queueRead_, &mutexRead_, &queueWrite_, &mutexWrite_);
    tcpRead.connectTcpServer("192.168.1.100", 8080);
    tcpRead.start();

//    tcpRead.exitTcpThread();


    return a.exec();
}
