#ifndef REMOVERECIPEPANEL_H
#define REMOVERECIPEPANEL_H

#include <QDialog>
#include <QStringListModel>
#include "mainwindow.h"

namespace Ui {
class removerecipepanel;
}

class removerecipepanel : public QDialog
{
    Q_OBJECT

public:
    explicit removerecipepanel(QWidget *parent = 0);
    ~removerecipepanel();

private slots:
    void on_removeRecipeBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::removerecipepanel *ui;
};

#endif // REMOVERECIPEPANEL_H
