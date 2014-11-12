#include "recipespanel.h"
#include "ui_recipespanel.h"

recipespanel::recipespanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recipespanel)
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

recipespanel::~recipespanel()
{
    delete ui;
}

void recipespanel::on_closeBtn_clicked()
{
    this->close();
}
void recipespanel::on_viewRecipeBtn_clicked()
{
    int index = ui->recipesList->currentIndex().row();
    if (index < 0)
        index = 0;
    reinterpret_cast<MainWindow*>(parentWidget())->setCurrentRecipe(RecipeBook::getInstance()->getRecipe(index));
    reinterpret_cast<MainWindow*>(parentWidget())->updateRecipeWindows();
    this->close();
}
