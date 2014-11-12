#ifndef RECIPESPANEL_H
#define RECIPESPANEL_H

#include <QDialog>
#include <QStringListModel>
#include "mainwindow.h"

namespace Ui {
class recipespanel;
}

class recipespanel : public QDialog
{
    Q_OBJECT

public:
    explicit recipespanel(QWidget *parent = 0);
    ~recipespanel();

private slots:

    void on_closeBtn_clicked();

    void on_viewRecipeBtn_clicked();

private:
    Ui::recipespanel *ui;
};

#endif // RECIPESPANEL_H
