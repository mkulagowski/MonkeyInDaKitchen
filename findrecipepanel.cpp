#include "findrecipepanel.h"
#include "ui_findrecipepanel.h"

findrecipepanel::findrecipepanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findrecipepanel)
{
    ui->setupUi(this);
}

findrecipepanel::~findrecipepanel()
{
    delete ui;
}

void findrecipepanel::on_findBtn_clicked()
{

    std::string keyword = ui->ingredientName->text().toStdString();
    QStringList ingridientsList;
    for(auto i:*(RecipeBook::getInstance()->getRecipeArray()))
        if (std::any_of(i->getIngredients()->begin(), i->getIngredients()->end(), [&](std::string arg){ if (arg.find(keyword) != std::string::npos)
                                                                                                            return true;
                                                                                                          else
                                                                                                            return false;
                                                                                                       }
        ))
        {
            ingridientsList << QString::fromStdString(i->getName());
        }

    ui->listView->reset();
    ui->listView->setModel(new QStringListModel(ingridientsList));
    ui->listView->setMovement(QListView::Static);
}

void findrecipepanel::on_viewBtn_clicked()
{
    int index = ui->listView->currentIndex().row();
    if (index < 0)
        index = 0;
    std::string name = ui->listView->model()->index(index, 0).data(Qt::DisplayRole).toString().toStdString();
    reinterpret_cast<MainWindow*>(parentWidget())->setCurrentRecipe(RecipeBook::getInstance()->getRecipe(name));
    reinterpret_cast<MainWindow*>(parentWidget())->updateRecipeWindows();
    this->close();
}

void findrecipepanel::on_closeBtn_clicked()
{
    this->close();
}
