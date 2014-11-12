#include "addrecipepanel.h"
#include "ui_addrecipepanel.h"

addrecipepanel::addrecipepanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrecipepanel),
    m_recipe(new Recipe())
{
    ui->setupUi(this);
}

addrecipepanel::~addrecipepanel()
{
    delete ui;
}

void addrecipepanel::setCheck(std::string checkType, bool value)
{
    QMessageBox *msgBox = new QMessageBox(this);
    if (!checkType.compare("Ingredients")){
        ui->checkIngredients->setChecked(value);
    }
    else if (!checkType.compare("Photo")){
        ui->checkPhoto->setChecked(value);
    }
    else if (!checkType.compare("Txt")){
        ui->checkTxt->setChecked(value);
    }
    else
    {
        msgBox->setText("checking NOTHING!");
        msgBox->exec();
    } 
}

RecipePtr addrecipepanel::getRecipe()
{
    return m_recipe;
}

void addrecipepanel::on_photoBtn_clicked()
{
    addrecipephoto *photoWindow = new addrecipephoto(this);
    photoWindow->show();
}

void addrecipepanel::on_ingredientsBtn_clicked()
{
    addrecipeingredients *ingredientsWindow = new addrecipeingredients(this);
    ingredientsWindow->show();
}

void addrecipepanel::on_txtBtn_clicked()
{
    addrecipetxt *txtWindow = new addrecipetxt(this);
    txtWindow->show();
}

void addrecipepanel::on_addRecipeBtn_clicked()
{
    if (ui->checkIngredients->isChecked()
        && ui->checkTxt->isChecked()
        && ui->name->text().size() > 0)
    {
        m_recipe->setName(ui->name->text().toStdString());
        RecipeBook::getInstance()->addRecipe(m_recipe);
        this->close();
    } else {
        QMessageBox msgBox;
        msgBox.setText("No ingredients, recipe text or recipe name!");
        msgBox.exec();
    }
}

void addrecipepanel::on_closeBtn_clicked()
{
    this->close();
}
