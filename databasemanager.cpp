#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QCryptographicHash> // NEW: Required for hashing

databasemanager::databasemanager() {

    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

databasemanager& databasemanager::instance()
{
    static databasemanager instance;
    return instance;
}

QString databasemanager::hashPassword(const QString& plainText)
{
    QByteArray hash = QCryptographicHash::hash(plainText.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool databasemanager::init()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug()<<"App Path: "<<path;
    QDir dir(path);
    if (!dir.exists()) dir.mkpath(".");

    QString dbPath = path + "/ganesh.db";
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qDebug() << "Error: Could not open database.";
        return false;
    }

    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS login (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE,
            password TEXT,
            role TEXT
        )
    )";
    // Note: The 'password' column now holds the Hash, not the real password.

    query.exec(createTable);

    // Check for Admin
    query.prepare("SELECT COUNT(*) FROM login WHERE username = :user");
    query.bindValue(":user", "admin");
    if (query.exec() && query.next()) {
        if (query.value(0).toInt() == 0) {
            qDebug() << "Seeding default admin user...";
            // We pass the plain password here, but registerUser will hash it automatically!
            registerUser("admin", "admin123", "admin");
        }
    }

    return true;
}

bool databasemanager::registerUser(const QString& username, const QString& password, const QString& role)
{
    QSqlQuery query;
    query.prepare("INSERT INTO login (username, password, role) VALUES (:user, :pass, :role)");

    query.bindValue(":user", username);

    // NEW: We hash the password before saving it!
    QString encryptedPass = hashPassword(password);
    query.bindValue(":pass", encryptedPass);

    query.bindValue(":role", role);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Registration failed:" << query.lastError();
        return false;
    }
}

bool databasemanager::loginUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM login WHERE username = :user");
    query.bindValue(":user", username);

    if (query.exec() && query.next()) {
        QString storedHash = query.value(0).toString();

        // NEW: Hash the input password and compare it to the stored hash
        QString inputHash = hashPassword(password);

        if (storedHash == inputHash) {
            return true;
        }
    }
    return false;
}
