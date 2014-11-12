#include "addrecipetxt.h"
#include "ui_addrecipetxt.h"

addrecipetxt::addrecipetxt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrecipetxt)
{
    ui->setupUi(this);
    QString recipeTxtQStr = QString::fromStdString(reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->getRecipeTxt());
    ui->plainTextEdit->setPlainText(recipeTxtQStr);
}

addrecipetxt::~addrecipetxt()
{
    delete ui;
}

void addrecipetxt::on_pushButton_clicked()
{
    std::string recipeTxtStr = ui->plainTextEdit->toPlainText().toStdString();
    reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->setRecipeTxt(recipeTxtStr);
    reinterpret_cast<addrecipepanel*>(parentWidget())->setCheck("Txt", true);
    this->close();
}
