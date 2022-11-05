#include "ClientUI.h"
#include "Message.h"

#include <QDebug>

ClientUI::ClientUI(QObject* parent) : QObject{parent}
{
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

    emit messagesChanged(typ, message);
}

void ClientUI::SetQmlContextPropertiex(QQmlContext* context)
{
    if(!context)
        return;

    context->setContextProperty("ClientUI", this);
}
