#include "signupapp.h"
#include "ui_signupapp.h"
#include "databasemanager.h"
#include <QMessageBox>

signupApp::signupApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupApp)
{
    ui->setupUi(this);

}

void signupApp::on_submitNewUser_pushButton_clicked()
{
    QString newUser = ui->enterName_lineEdit->text();
    QString pass = ui->enterPassword_lineEdit->text();
    QString role = ui->selectRole_comboBox->currentText();

    qDebug()<<"********************************************";
    qDebug()<<"New User name:"<<newUser;
    qDebug()<<"     Password:"<<pass;
    qDebug()<<"         Role:"<<role;
    qDebug()<<"********************************************";

    // Use .instance() to get the object
    bool success = databasemanager::instance().registerUser(newUser, pass, role);
    if (success) {
        // Show success message
        QMessageBox::information(this, "Success", "Account created! You can now login.");

        // 2. THIS COMMAND CLOSES THE WINDOW
        this->accept();
    }
    else {
        QMessageBox::warning(this, "Error", "Registration failed. Username may exist.");
    }

}

