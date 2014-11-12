#include "removerecipepanel.h"
#include "ui_removerecipepanel.h"

removerecipepanel::removerecipepanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removerecipepanel)
{
    ui->setupUi(this);
    QStringList ingridientsList;
    for(auto i:*(RecipeBook::getInstance()->getRecipeArray()))
    {
        ingridientsList << QString::fromStdString(i->getName());
    }
    ui->recipesList->setModel(new QStringListModel(ingridientsList));
    ui->recipesList->setMovement(QListView::Static);
}

removerecipepanel::~removerecipepanel()
{
    delete ui;
}

void removerecipepanel::on_removeRecipeBtn_clicked()
{
    int index = ui->recipesList->currentIndex().row();
    if (index < 0)
        index = 0;
    RecipeBook::getInstance()->removeRecipe(index);
    this->close();
}

void removerecipepanel::on_closeBtn_clicked()
{
    this->close();
}
