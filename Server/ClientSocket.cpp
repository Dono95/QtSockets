#include "ClientSocket.h"
#include <QDebug>
#include <QDateTime>

ClientSocket::ClientSocket(qintptr socketDescriptor) : QTcpSocket(nullptr)
{
    setSocketDescriptor(socketDescriptor);

    connect(this, SIGNAL(readyRead()), this, SLOT(readyRead()),
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

void ClientSocket::ModifeIncomingData(QString& data) const
{
    data += "_" + QDateTime::currentDateTime().time().toString();
    data += "_RegecDomink";
}
