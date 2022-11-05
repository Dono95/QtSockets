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
    bool IsInitData(const QString data);
    void SaveLogin(const QString& data);
    void SendArchive(const QString& data);

    void ModifeIncomingData(QString& data) const;

    const int mSocketDescriptor;
    QString mLogin;
};

#endif// CLIENTSOCKET_H
