#ifndef MYCAMERA_H
#define MYCAMERA_H

#include <QDialog>

namespace Ui {
class myCamera;
}

class myCamera : public QDialog
{
    Q_OBJECT

public:
    explicit myCamera(QWidget *parent = nullptr);
    ~myCamera();

private:
    Ui::myCamera *ui;
};

#endif // MYCAMERA_H
