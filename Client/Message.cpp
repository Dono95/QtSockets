#include "Message.h"

Message::Message(MessageTyp typ, const QString& message) :
    mTyp(typ), mMessage(message)
{
}

Message::~Message()
{
}

int64_t Message::GetTyp() const
{
    return static_cast<int64_t>(mTyp);
}

QString Message::GetMessage() const
{
    return mMessage;
}
