#ifndef FINDRECIPEPANEL_H
#define FINDRECIPEPANEL_H

#include <QDialog>
#include <QStringListModel>
#include "mainwindow.h"

namespace Ui {
class findrecipepanel;
}

class findrecipepanel : public QDialog
{
    Q_OBJECT

public:
    explicit findrecipepanel(QWidget *parent = 0);
    ~findrecipepanel();

private slots:
    void on_findBtn_clicked();

    void on_viewBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::findrecipepanel *ui;
};

#endif // FINDRECIPEPANEL_H
