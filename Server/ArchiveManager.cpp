#include "ArchiveManager.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

ArchiveManager* ArchiveManager::mManager;
std::mutex ArchiveManager::mMutexManager;

ArchiveManager::ArchiveManager()
{
}
ArchiveManager::~ArchiveManager()
{
}

ArchiveManager* ArchiveManager::GetInstance()
{
    std::lock_guard<std::mutex> lock(mMutexManager);
    if(!mManager)
        mManager = new ArchiveManager();

    return mManager;
}

bool ArchiveManager::ExistFile(const QString& login) const
{
    return QFileInfo::exists("../Archive/" + login + ".txt");
}

void ArchiveManager::LoadArchiveData(QVector<QString>& archiveData,
    const QString& login) const
{
    QFile file("../Archive/" + login + ".txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    while(!in.atEnd())
    {
        archiveData.append(in.readLine() + "\r\n");
    }
    file.close();
}

void ArchiveManager::SaveMessage(const QString& login, const QString& typ,
    const QString message) const
{
    QFile file("../Archive/" + login + ".txt");
    file.open(QIODevice::Append | QIODevice::Text);

    QTextStream out(&file);
    out << typ << message << "\r\n";
    file.close();
}
