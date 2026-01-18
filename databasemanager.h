#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class databasemanager
{

    public:
        databasemanager();

        static databasemanager& instance();

        bool init();
        bool loginUser(const QString& username, const QString& password);
        bool registerUser(const QString& username, const QString& password, const QString& role);

    private:
        QSqlDatabase m_db;

        // NEW: Helper function to encrypt passwords
        QString hashPassword(const QString& plainText);

};

#endif // DATABASEMANAGER_H
