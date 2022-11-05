#ifndef CLIENTUI_H
#define CLIENTUI_H

/* Qt libraries */
#include <QObject>
#include <QQmlContext>
#include <QVector>

class ClientUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> messages READ GetMessages NOTIFY messagesChanged)
    Q_PROPERTY(quint64 messagesCount READ GetCount NOTIFY messagesChanged)
public:
    explicit ClientUI(QObject* parent = nullptr);
    ~ClientUI();

    QList<QObject*> GetMessages() const;
    quint64 GetCount() const;

    Q_INVOKABLE void addMessage(int typ, const QString& message);

    void SetQmlContextPropertiex(QQmlContext* context);
signals:
    void messagesChanged();

private:
    QList<QObject*> mMessages;
};

#endif// CLIENTUI_H
