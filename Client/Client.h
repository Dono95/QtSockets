#ifndef CLIENT_H
#define CLIENT_H

/* Qt libraries */
#include <QObject>
#include <QQmlApplicationEngine>

/* Project specific includes */
#include "ClientUI.h"

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject* parent = nullptr);
    ~Client();

private:
    /* Client UI class */
    ClientUI* mClientUI;

    /* Pointer to QML application engine */
    QQmlApplicationEngine* mEngine;
    /* Pointer to QML context */
    QQmlContext* mRootContext;
};
#endif// CLIENT_H
