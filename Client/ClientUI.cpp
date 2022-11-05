#include "ClientUI.h"

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

void ClientUI::sendMessage(int typ, const QString& message)
{
    emit messageSend(typ, message);
}

void ClientUI::StoreMessage(Message::MessageTyp typ, const QString& message)
{
    mMessages.insert(0, new Message(typ, message));

    emit messagesChanged();
}

void ClientUI::SetQmlContextPropertiex(QQmlContext* context)
{
    if(!context)
        return;

    context->setContextProperty("ClientUI", this);
}
