/* Qt libraries*/
#include <QGuiApplication>

#include <QApplication>
#include <QHostAddress>
#include <QTcpSocket>

#include "Client.h"
int main(int argc, char* argv[])
{
    QGuiApplication gui(argc, argv);

    return gui.exec();
    // QApplication a(argc, argv);
    // Client w;
    // w.show();
    // return a.exec();

    // QTcpSocket socket;
    // socket.connectToHost(QHostAddress::LocalHost, 20201);

    return 0;
}
