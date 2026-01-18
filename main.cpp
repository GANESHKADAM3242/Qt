#include "mainwindow.h"
#include "databasemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!databasemanager::instance().init()) {
        qDebug() << "Database failed to start!";
        return -1; // Stop the app if database fails
    }

    MainWindow w;
    w.show();
    return a.exec();
}
