#ifndef ADDRECIPETXT_H
#define ADDRECIPETXT_H

#include <QDialog>
#include "addrecipepanel.h"

namespace Ui {
class addrecipetxt;
}

class addrecipetxt : public QDialog
{
    Q_OBJECT

public:
    explicit addrecipetxt(QWidget *parent = 0);
    ~addrecipetxt();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addrecipetxt *ui;
};

#endif // ADDRECIPETXT_H
