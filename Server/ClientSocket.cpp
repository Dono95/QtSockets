#include "ClientSocket.h"
#include <QDebug>
#include <QDateTime>

#include "ArchiveManager.h"

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

    if(IsInitData(data))
    {
        SaveLogin(data);
        SendArchive(data);
        return;
    }

    const auto archiveManager = ArchiveManager::GetInstance();

    archiveManager->SaveMessage(mLogin, "_C_", data);
    ModifeIncomingData(data);
    archiveManager->SaveMessage(mLogin, "_S_", data);

    write(data.toStdString().c_str());
    flush();
}

void ClientSocket::disconnect()
{
    qDebug() << "Client with descriptor [" << mSocketDescriptor
             << "] disconnected";
    deleteLater();
}

bool ClientSocket::IsInitData(const QString data)
{
    return data.mid(0, 4).compare("init") == 0;
}

void ClientSocket::SaveLogin(const QString& data)
{
    QStringList list = data.split('_');
    mLogin = list.at(2);
}

void ClientSocket::SendArchive(const QString& data)
{
    auto archiveManager = ArchiveManager::GetInstance();

    if(!archiveManager->ExistFile(mLogin))
    {
        qDebug() << "No data for:" << mLogin;
        return;
    }

    QVector<QString> archiveData;
    archiveManager->LoadArchiveData(archiveData, mLogin);

    for(const auto& message : qAsConst(archiveData))
    {
        write(message.toStdString().c_str());
    }
    flush();
}

void ClientSocket::ModifeIncomingData(QString& data) const
{
    data += "_" + QDateTime::currentDateTime().time().toString();
    data += "_" + QDateTime::currentDateTime().date().toString();
    data += "_RegecDominik";
}
