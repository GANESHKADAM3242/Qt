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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_pushButton_clicked()
{
    qDebug()<<"Login Button";
}

