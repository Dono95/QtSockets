#include "Client.h"
#include "Message.h"

#include <QDebug>

Client::Client(QObject* parent) : QObject(parent), mSocket(new QTcpSocket())
{
    mEngine = new QQmlApplicationEngine();
    mRootContext = mEngine->rootContext();

    // Create client UI class
    mClientUI = new ClientUI();
    if(mClientUI)
        mClientUI->SetQmlContextPropertiex(mRootContext);

    connect(mClientUI, &ClientUI::messagesChanged, this,
        [&](const int typ, const QString& message)
        {
            if(static_cast<Message::MessageTyp>(typ) !=
                Message::MessageTyp::CLIENT_MESSAGE)
                return;

            mSocket->write(message.toStdString().c_str());
        });

    connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()),
        Qt::DirectConnection);

    mEngine->load(QUrl(QStringLiteral("../UI/main.qml")));

    ConnectToServer(QHostAddress::LocalHost, 20201);
}

Client::~Client()
{
}

void Client::readyRead()
{
    QString data = mSocket->readAll();

    mClientUI->addMessage(static_cast<int>(Message::MessageTyp::SERVER_MESSAGE),
        data);
}

void Client::ConnectToServer(const QHostAddress& address, const quint16 port)
{
    mSocket->connectToHost(address, port);
}
