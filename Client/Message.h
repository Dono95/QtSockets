#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 typ READ GetTyp NOTIFY messageChanged)
    Q_PROPERTY(QString message READ GetMessage NOTIFY messageChanged)
    Q_PROPERTY(qint64 length READ GetLength NOTIFY messageChanged)

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
    int64_t GetLength() const;

signals:
    void messageChanged();

private:
    MessageTyp mTyp;
    QString mMessage;
    int64_t mLength;
};

#endif// MESSAGE_H
