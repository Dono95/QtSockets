#ifndef CLIENTUI_H
#define CLIENTUI_H

#include <QObject>

class ClientUI : public QObject
{
    Q_OBJECT
public:
    explicit ClientUI(QObject *parent = nullptr);

signals:

};

#endif // CLIENTUI_H
