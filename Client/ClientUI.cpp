#include "ClientUI.h"
#include "Message.h"

ClientUI::ClientUI(QObject* parent) : QObject{parent}
{
    mMessages.append(
        new Message(Message::MessageTyp::CLIENT_MESSAGE, "Client message"));
    mMessages.insert(0,
        new Message(Message::MessageTyp::SERVER_MESSAGE, "Server message"));
}

ClientUI::~ClientUI()
{
}

QList<QObject*> ClientUI::GetMessages() const
{
    return mMessages;
}

quint64 ClientUI::GetCount() const
{
    return mMessages.count();
}

void ClientUI::addMessage(int typ, const QString& message)
{
    mMessages.insert(0,
        new Message(static_cast<Message::MessageTyp>(typ), message));

    emit messagesChanged();
}

void ClientUI::SetQmlContextPropertiex(QQmlContext* context)
{
    if(!context)
        return;

    context->setContextProperty("ClientUI", this);
}
