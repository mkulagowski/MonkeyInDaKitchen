#include "addrecipephoto.h"
#include "ui_addrecipephoto.h"

addrecipephoto::addrecipephoto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrecipephoto)
{
    ui->setupUi(this);
    QString photoPathQStr = QString::fromStdString(reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->getPhotoPath());
    ui->lineEdit->setText(photoPathQStr);
}

addrecipephoto::~addrecipephoto()
{
    delete ui;
}

void addrecipephoto::on_pushButton_clicked()
{
    QFileDialog filedialog(this);
    filedialog.setAcceptMode(QFileDialog::AcceptOpen);
    filedialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    filedialog.setFileMode(QFileDialog::ExistingFile);
    filedialog.setViewMode(QFileDialog::List);
    filedialog.show();
    ui->lineEdit->setText(filedialog.getOpenFileName());
}

void addrecipephoto::on_pushButton_2_clicked()
{
    reinterpret_cast<addrecipepanel*>(parentWidget())->getRecipe()->setPhotoPath(ui->lineEdit->text().toStdString());
    reinterpret_cast<addrecipepanel*>(parentWidget())->setCheck("Photo", true);
    this->close();
}
