#ifndef LOGINBUTTON_H
#define LOGINBUTTON_H

#include <QWidget>

class loginbutton : public QWidget
{
    Q_OBJECT
public:
    explicit loginbutton(QWidget *parent = nullptr);
private:
    loginbutton *ui;
signals:
};

#endif // LOGINBUTTON_H
