#ifndef CLIENT_H
#define CLIENT_H

/* Qt libraries */
#include <QObject>
#include <QQmlApplicationEngine>

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject* parent = nullptr);
    ~Client();

private:
};
#endif// CLIENT_H
