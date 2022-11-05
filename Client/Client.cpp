#include "Client.h"
#include "Message.h"

#include <QGuiApplication>
#include <QDebug>

Client::Client(QObject* parent) : QObject(parent), mSocket(new QTcpSocket())
{
    mEngine = new QQmlApplicationEngine();
    mRootContext = mEngine->rootContext();

    // Create client UI class
    mClientUI = new ClientUI();
    if(mClientUI)
        mClientUI->SetQmlContextPropertiex(mRootContext);

    connect(mClientUI, &ClientUI::messageSend, this,
        [&](const int typ, const QString& message)
        {
            auto messageTyp = static_cast<Message::MessageTyp>(typ);
            if(messageTyp == Message::MessageTyp::UNDEFINED)
                return;

            mClientUI->StoreMessage(messageTyp, message);
            mSocket->write(message.toStdString().c_str());
        });

    connect(mSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()),
        Qt::DirectConnection);

    if(!ConnectToServer(QHostAddress::LocalHost, 20201))
    {
        qDebug() << "Client failed to connect to server.";
        exit(1);
    }
}

Client::~Client()
{
}

void Client::readyRead()
{
    QVector<std::pair<Message::MessageTyp, QString>> messagesList;

    while(!mSocket->atEnd())
    {
        QString rawMessage = mSocket->readLine();

        Message::MessageTyp typ;
        if(rawMessage.at(1) == 'S')
        {
            typ = Message::MessageTyp::SERVER_MESSAGE;
            rawMessage.chop(2);
            rawMessage = rawMessage.remove(0, 3);
        }
        else if(rawMessage.at(1) == 'C')
        {
            typ = Message::MessageTyp::CLIENT_MESSAGE;
            rawMessage.chop(2);
            rawMessage = rawMessage.remove(0, 3);
        }
        else
            typ = Message::MessageTyp::SERVER_MESSAGE;

        messagesList.append({typ, rawMessage});
    }
    for(const auto& message_pair : qAsConst(messagesList))
    {
        mClientUI->StoreMessage(message_pair.first, message_pair.second);
    }
}

void Client::connected()
{
    qDebug() << "Client is connected to server.";
    mEngine->load(QUrl(QStringLiteral("../UI/main.qml")));

    mSocket->write("init_0_Dominik");
}

bool Client::ConnectToServer(const QHostAddress& address, const quint16 port)
{
    mSocket->connectToHost(address, port);

    return mSocket->waitForConnected(1000);
}
