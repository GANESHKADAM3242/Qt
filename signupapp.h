#ifndef SIGNUPAPP_H
#define SIGNUPAPP_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class signupApp;
}
QT_END_NAMESPACE

class signupApp : public QDialog
{
    Q_OBJECT
public:
    explicit signupApp(QWidget *parent = nullptr);

signals:

private:
    Ui::signupApp *ui;

};

#endif // SIGNUPAPP_H
