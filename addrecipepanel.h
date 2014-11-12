#ifndef ADDRECIPEPANEL_H
#define ADDRECIPEPANEL_H
#include <QDialog>
#include <QMessageBox>
#include "RecipeBook.h"

#include "addrecipeingredients.h"
#include "addrecipetxt.h"
#include "addrecipephoto.h"

namespace Ui {
class addrecipepanel;
}

class addrecipepanel : public QDialog
{
    Q_OBJECT

public:
    explicit addrecipepanel(QWidget *parent = 0);
    RecipePtr getRecipe();
    void setCheck(std::string checkType, bool value);
    ~addrecipepanel();

private slots:
    void on_photoBtn_clicked();

    void on_ingredientsBtn_clicked();

    void on_txtBtn_clicked();

    void on_addRecipeBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::addrecipepanel *ui;
    RecipePtr m_recipe;
};

#endif // ADDRECIPEPANEL_H
