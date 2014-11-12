#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QVector>
#include "RecipeBook.h"
#include "recipespanel.h"
#include "addrecipepanel.h"
#include "removerecipepanel.h"
#include "findrecipepanel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setCurrentRecipe(RecipePtr recipe);
    void updateRecipeWindows();
    ~MainWindow();

private slots:
    void on_RecipiesBtn_clicked();

    void on_addRecipeBtn_clicked();

    void on_removeRecipeBtn_clicked();

    void on_useIngridientBtn_clicked();

protected:
   // void resizeEvent(QResizeEvent *);

private:
    RecipePtr m_currentRecipe;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
