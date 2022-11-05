#include "ClientSocket.h"
#include <QDebug>
#include <QDateTime>

ClientSocket::ClientSocket(qintptr socketDescriptor) :
    QTcpSocket(nullptr), mSocketDescriptor(socketDescriptor)
{
    setSocketDescriptor(socketDescriptor);

    connect(this, SIGNAL(readyRead()), this, SLOT(readyRead()),
        Qt::DirectConnection);

    connect(this, SIGNAL(disconnected()), this, SLOT(disconnect()),
        Qt::DirectConnection);
}

ClientSocket::~ClientSocket()
{
}

void ClientSocket::readyRead()
{
    QString data = readAll();

    ModifeIncomingData(data);

    write(data.toStdString().c_str());
    flush();
}

void ClientSocket::disconnect()
{
    qDebug() << "Client with descriptor [" << mSocketDescriptor
             << "] disconnected";
    deleteLater();
}

void ClientSocket::ModifeIncomingData(QString& data) const
{
    data += "_" + QDateTime::currentDateTime().time().toString();
    data += "_" + QDateTime::currentDateTime().date().toString();
    data += "_RegecDominik";
}
