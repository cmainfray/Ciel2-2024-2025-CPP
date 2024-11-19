#ifndef MAINWIGET_H
#define MAINWIGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWiget;
}
QT_END_NAMESPACE

class MainWiget : public QWidget
{
    Q_OBJECT

public:
    MainWiget(QWidget *parent = nullptr);
    ~MainWiget();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWiget *ui;
};
#endif // MAINWIGET_H
