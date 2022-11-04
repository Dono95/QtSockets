#include "ServerMessengerProvider.h"

using namespace Server;

/******************************************************************/
/**************              PUBLIC API              **************/
/******************************************************************/
ServerMessengerProvider* ServerMessengerProvider::mInstance{nullptr};
std::mutex ServerMessengerProvider::mMutex;

ServerMessengerProvider* ServerMessengerProvider::GetInstance()
{
    std::lock_guard<std::mutex> lock(mMutex);
    if(!mInstance)
        mInstance = new ServerMessengerProvider();

    return mInstance;
}

bool ServerMessengerProvider::StartListening()
{
    return listen(QHostAddress::LocalHost, 20201);
}

void ServerMessengerProvider::incomingConnection(qintptr handle)
{
    qDebug() << "__func__";
}

/******************************************************************/
/**************             PRIVATE API              **************/
/******************************************************************/

ServerMessengerProvider::ServerMessengerProvider(QObject* parent) :
    QTcpServer{parent}
{
    // mServer = new QTcpServer(this);
}

ServerMessengerProvider::~ServerMessengerProvider()
{
}
