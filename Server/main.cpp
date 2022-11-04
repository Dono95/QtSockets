/* QT library */
#include <QCoreApplication>
#include <QDebug>

/* Project specific includes */
#include "ServerMessengerProvider.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    // Create ServerMessengerProvider
    auto server = Server::ServerMessengerProvider::GetInstance();
    if(server->StartListening())
        qDebug() << "Server's started listening ... ";
    else
        qDebug() << "Failed to start listening ... ";

    return a.exec();
}
