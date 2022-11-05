/* Qt libraries*/
#include <QGuiApplication>

//#include <QApplication>
//#include <QHostAddress>
//#include <QTcpSocket>

/* Project specific includes */
#include "Client.h"

int main(int argc, char* argv[])
{
    QGuiApplication gui(argc, argv);
    Client client;

    return gui.exec();
}
