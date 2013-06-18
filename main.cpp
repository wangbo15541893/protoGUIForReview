#include <QApplication>
#include <QTime>
#include <QtNetwork>
#include "mainwindow.h"
#include "amessage.pb.h"
#include "cTcpThreadRead.h"
#include "cTcpSocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEdit mw;
    //mw.maximumSize(QSize(0, 0));
    mw.resize( 00, 00 );

    //Message msg1;

    CTcpThreadRead tcpRead;
    mw.printText(QString("Andy test!\n"));
    mw.show();

    CTcpSocket tcpSocket;
    tcpSocket.tcpConnect("127.0.0.1", 8080);

    tcpSocket.write("adfffffffffa");

    tcpRead.setTextEdit(&mw);
    tcpRead.start();

    tcpRead.exitTcpThread();


    return a.exec();
}
