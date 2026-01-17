#include "signupapp.h"
#include "ui_signupapp.h"

signupApp::signupApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupApp)
{
    ui->setupUi(this);

}
