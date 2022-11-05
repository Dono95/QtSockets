#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <mutex>

#include <QMap>

class ArchiveManager
{
public:
    static ArchiveManager* GetInstance();

    bool ExistFile(const QString& login) const;

    void LoadArchiveData(QVector<QString>& archiveData,
        const QString& login) const;
    void SaveMessage(const QString& login, const QString& typ,
        const QString message) const;

private:
    explicit ArchiveManager();
    ~ArchiveManager();

    static ArchiveManager* mManager;
    static std::mutex mMutexManager;
};

#endif// ARCHIVEMANAGER_H
