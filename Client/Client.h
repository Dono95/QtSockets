#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
};
#endif // CLIENT_H
