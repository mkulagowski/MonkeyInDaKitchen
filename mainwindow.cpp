#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_currentRecipe(nullptr)
{
    ui->setupUi(this);
    ui->photoLabel->setScaledContents(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RecipiesBtn_clicked()
{
    recipespanel *recipepanel = new recipespanel(this);
    recipepanel->show();
}

void MainWindow::setCurrentRecipe(RecipePtr recipe)
{
    m_currentRecipe = recipe;
}

void MainWindow::updateRecipeWindows()
{
    if (m_currentRecipe)
    {
        QStringList ingridientsList;
        for(auto i:*(m_currentRecipe->getIngredients()))
        {
            ingridientsList << QString::fromStdString(i);
        }
        ui->recipeIngridients->setModel(new QStringListModel(ingridientsList));
        ui->recipeTxt->setText(QString::fromStdString(m_currentRecipe->getRecipeTxt()));
        ui->recipeNameLabel->setText(QString::fromStdString(m_currentRecipe->getName()));
        auto h = ui->photoLabel->height();
        auto w = ui->photoLabel->width();
        ui->photoLabel->setPixmap(QPixmap(QString::fromStdString(m_currentRecipe->getPhotoPath())).scaled(w,h,Qt::KeepAspectRatio));
    }
    else
    {
        ui->recipeIngridients->reset();
        ui->recipeTxt->reload();
        ui->recipeNameLabel->setText("");
        ui->photoLabel->setPixmap(QPixmap(""));
    }
}

void MainWindow::on_addRecipeBtn_clicked()
{
    addrecipepanel *addpanel = new addrecipepanel(this);
    addpanel->show();
}
/*
void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    QSize pixSize = ui->photoLabel->pixmap()->size();
    pixSize.scale(size(), Qt::KeepAspectRatio);
    ui->photoLabel->setFixedSize(pixSize);
}
*/
void MainWindow::on_removeRecipeBtn_clicked()
{
    removerecipepanel *removepanel = new removerecipepanel(this);
    removepanel->show();
}

void MainWindow::on_useIngridientBtn_clicked()
{
    findrecipepanel *findpanel = new findrecipepanel(this);
    findpanel->show();
}
