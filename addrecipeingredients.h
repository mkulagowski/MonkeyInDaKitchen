#ifndef ADDRECIPEINGREDIENTS_H
#define ADDRECIPEINGREDIENTS_H

#include <QDialog>
#include <sstream>
#include <cstring>
#include "addrecipepanel.h"

namespace Ui {
class addrecipeingredients;
}

class addrecipeingredients : public QDialog
{
    Q_OBJECT

public:
    explicit addrecipeingredients(QWidget *parent = 0);
    ~addrecipeingredients();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addrecipeingredients *ui;
};

#endif // ADDRECIPEINGREDIENTS_H
