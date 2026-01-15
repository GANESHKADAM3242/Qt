#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginbutton.h"
#include "qdebug.h"

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
    qDebug()<<"t\t[ Login Detials ]\n";
    qDebug()<<"User Name:"<<userID;
    qDebug()<<"Password:"<<password;
}


void MainWindow::on_signUp_pushButton_clicked()
{
    // Here it will open new pop-up and load new info in database
    connect(ui->signup_pushButton, &QPushButton::clicked,
            this, &MainWindow::openSignupDialog);
}

