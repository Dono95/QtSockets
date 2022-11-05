#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ClientSocket(qintptr socketDescriptor);
    ~ClientSocket();
signals:

public slots:
    void readyRead();
    void disconnect();

private:
    void ModifeIncomingData(QString& data) const;

    const int mSocketDescriptor;
};

#endif// CLIENTSOCKET_H
