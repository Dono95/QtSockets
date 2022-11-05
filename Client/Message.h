#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 typ READ GetTyp NOTIFY messageChanged)
    Q_PROPERTY(QString message READ GetMessage NOTIFY messageChanged)

public:
    enum class MessageTyp
    {
        UNDEFINED,
        SERVER_MESSAGE,
        CLIENT_MESSAGE,
    };

    explicit Message(MessageTyp typ, const QString& message);
    ~Message();

    int64_t GetTyp() const;
    QString GetMessage() const;

signals:
    void messageChanged();

private:
    MessageTyp mTyp;
    QString mMessage;
};

#endif// MESSAGE_H
