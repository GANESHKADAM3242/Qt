#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginbutton.h"
#include "qdebug.h"
#include "databasemanager.h"
#include "signupapp.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Hello Ganesh
    // Here it will open new pop-up and load new info in database
    connect(ui->signUp_pushButton, &QPushButton::clicked,
            this, &MainWindow::openSignupDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSignupDialog()
{


}

void MainWindow::on_login_pushButton_clicked()
{
    const QString userID = ui->userID_lineEdit->text();
    const QString password = ui->password_lineEdit->text();

    qDebug()<<"********************************************";
    qDebug()<<"\t[ Login Detials ]\n";
    qDebug()<<"User Name:"<<userID;
    qDebug()<<"Password:"<<password;

    bool isValid = databasemanager::instance().loginUser(userID, password);


    if (isValid) {
        QMessageBox::information(this, "Success", "Login Successful!");

    } else {
        QMessageBox::warning(this, "Failed", "Wrong User ID or Password");
    }

}


void MainWindow::on_signUp_pushButton_clicked()
{
    // Here it will open new pop-up and load new info in database
    // Create the window on the Stack, but use exec() to pause execution
    signupApp signupWindow;

    // exec() starts its own event loop and waits here until the dialog is closed
    if (signupWindow.exec() == QDialog::Accepted) {
        // Optional: Do something if they finished signing up successfully
        // For example: ui->lineEditUser->setText("NewUser");
    }

}

