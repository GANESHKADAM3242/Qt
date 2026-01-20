#include "mycamera.h"
#include "ui_mycamera.h"

myCamera::myCamera(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myCamera)
{
    ui->setupUi(this);
}

myCamera::~myCamera()
{
    delete ui;
}
