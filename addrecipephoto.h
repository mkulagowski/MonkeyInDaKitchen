#ifndef ADDRECIPEPHOTO_H
#define ADDRECIPEPHOTO_H

#include <QDialog>
#include <QFileDialog>
#include "addrecipepanel.h"

namespace Ui {
class addrecipephoto;
}

class addrecipephoto : public QDialog
{
    Q_OBJECT

public:
    explicit addrecipephoto(QWidget *parent = 0);
    ~addrecipephoto();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addrecipephoto *ui;
};

#endif // ADDRECIPEPHOTO_H
