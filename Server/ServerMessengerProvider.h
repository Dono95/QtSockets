#ifndef SERVERMESSENGERPROVIDER_H
#define SERVERMESSENGERPROVIDER_H

/* QT library */
#include <QObject>
#include <QVector>
/* QT Network library */
#include <QTcpServer>

/* STD library*/
#include <mutex>

/* Project specific includes */
#include "ClientSocket.h"

namespace Server
{
    class ServerMessengerProvider : private QTcpServer
    {
        Q_OBJECT
    public:
        /**
         * @brief Static method to get instance of ServerMessengerProvider
         * @return ServerMessengerProvider* : Pointer to ServerMessengerProvider
         */
        static ServerMessengerProvider* GetInstance();

        /**
         * @brief ServerMessengerProvider - Singletons should not be cloneable.
         * @param other
         */
        ServerMessengerProvider(ServerMessengerProvider& other) = delete;

        /**
         * @brief operator = Singletons should not be assignable.
         */
        void operator=(const ServerMessengerProvider&) = delete;

        /**
         * @brief StartListening - Method to create QTCPServer and start
         * listening
         * @return bool    true  : Server started listening
         *                 false : Server could not start listen
         */
        bool StartListening();

    protected:
        virtual void incomingConnection(qintptr socketDescriptor) override;

    private:
        /**
         * @brief ServerMessengerProvider constructor
         * @param parent    : pointer to parent QObject
         */
        explicit ServerMessengerProvider(QObject* parent = nullptr);

        /**
         * @brief ServerMessengerProvider destructor
         */
        ~ServerMessengerProvider();

        /* Singelton instance to ServerMessengerProvider*/
        static ServerMessengerProvider* mInstance;

        /* Mutex to protect multi-thread access to ServerMessengerProvider*/
        static std::mutex mMutex;

        /* Vector of client's sockets*/
        QVector<ClientSocket*> mClientsSockets;
    };
}// namespace Server

#endif// SERVERMESSENGERPROVIDER_H
