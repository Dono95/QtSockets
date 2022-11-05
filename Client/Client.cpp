#include "Client.h"

Client::Client(QObject* parent) : QObject(parent)
{
    mEngine = new QQmlApplicationEngine();
    mRootContext = mEngine->rootContext();

    // Create client UI class
    mClientUI = new ClientUI();
    if(mClientUI)
        mClientUI->SetQmlContextPropertiex(mRootContext);

    mEngine->load(QUrl(QStringLiteral("../UI/main.qml")));
}

Client::~Client()
{
}
