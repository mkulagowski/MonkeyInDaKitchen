#include "addrecipeingredients.h"
#include "ui_addrecipeingredients.h"

addrecipeingredients::addrecipeingredients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrecipeingredients)
{
    ui->setupUi(this);
    stringArrayPtr ingredientsListStrArr = reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->getIngredients();
    std::string ingredientsListStr;
    std::for_each(ingredientsListStrArr->begin(), ingredientsListStrArr->end(), [&ingredientsListStr](std::string arg){ingredientsListStr += (arg + '\n');});
    ui->plainTextEdit->setPlainText(QString::fromStdString(ingredientsListStr));
}

addrecipeingredients::~addrecipeingredients()
{
    delete ui;
}

void addrecipeingredients::on_pushButton_clicked()
{
    stringArrayPtr ingredientsListStrArr = std::make_shared<stringArray>();
    reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->setIngredients(ingredientsListStrArr);

    auto splitStr = [this](char *sentence)
                    {
                        std::stringstream ss(sentence);
                        std::string to;
                        if (sentence != NULL)
                            while (std::getline(ss,to,'\n'))
                                reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->addIngredient(to);
                    };

    std::string ingridientStr = ui->plainTextEdit->toPlainText().toStdString();
    char *ingridientChar = new char[ingridientStr.length() + 1];
    strcpy(ingridientChar, ingridientStr.c_str());
    splitStr(ingridientChar);
    delete[] ingridientChar;

    reinterpret_cast<addrecipepanel*>(parentWidget())->setCheck("Ingredients", true);
    this->close();
}
