#include "Recipe.h"
#include <QMessageBox>
Recipe::Recipe():
    m_ingredients(nullptr),
    m_name("default"),
    m_recipeTxt(""),
    m_id(0),
    m_cookingTime(0),
    m_photoPath("")
{
    m_ingredients = std::make_shared<stringArray>();
}

Recipe::~Recipe()
{
}

stringArrayPtr Recipe::getIngredients()
{
    return m_ingredients;
}

void Recipe::addIngredient(std::string ingredient)
{
    m_ingredients->push_back(ingredient);
}

void Recipe::setIngredients(stringArrayPtr ingredientsArray)
{
    m_ingredients = ingredientsArray;
}

std::string Recipe::getName()
{
    return m_name;
}

void Recipe::setName(std::string name)
{
    m_name = name;
}

std::string Recipe::getRecipeTxt()
{
    return m_recipeTxt;
}

void Recipe::setRecipeTxt(std::string recipeTxt)
{
    m_recipeTxt = recipeTxt;
}

int Recipe::getId()
{
    return m_id;
}

void Recipe::setId(int id)
{
    m_id = id;
}

int Recipe::getCookingTime()
{
    return m_cookingTime;
}

void Recipe::setCookingTime(int time)
{
    m_cookingTime = time;
}

std::string Recipe::getPhotoPath()
{
    return m_photoPath;
}

void Recipe::setPhotoPath(std::string photoPath)
{
    m_photoPath = photoPath;
}

void Recipe::importFromTxt(std::ifstream &fileStream)
{
    QMessageBox *mb = new QMessageBox;
    std::string line;
    mb->setText("check");
    if (fileStream.is_open())
    {
        std::getline(fileStream, line);

        if (line.compare("__NAME"))
        {
            mb->setText(QString::fromStdString("check name:\n" + line));
            mb->exec();
            return;
        }
        std::getline(fileStream, line, '_');
        if (line.length() > 0)
            line.pop_back(); //used to delete '\n' from the end
        this->setName(line);

        std::getline(fileStream, line);
        if (line.compare("_PHOTOPATH"))
        {
            mb->setText(QString::fromStdString("check photo:\n" + line));
            mb->exec();
            return;
        }
        std::getline(fileStream, line);
        //if (line.length() > 0)
        //    line.pop_back(); //used to delete '\n' from the end
        this->setPhotoPath(line);

        std::getline(fileStream, line);
        if (line.compare("__RECIPETXT"))
        {
            mb->setText(QString::fromStdString("check txt:\n" + line));
            mb->exec();
            return;
        }
        std::getline(fileStream, line, '_');
        if (line.length() > 0)
            line.pop_back(); //used to delete '\n' from the end
        this->setRecipeTxt(line);

        std::getline(fileStream, line);
        if (line.compare("_INGREDIENTS"))
        {
            mb->setText(QString::fromStdString("check ing:\n" + line));
            mb->exec();
            return;
        }
        std::getline(fileStream, line, '_');
        auto splitStr = [this](char* goodPotato)
                        {
                            std::stringstream ss(goodPotato);
                            std::string to;
                            if (goodPotato != NULL)
                                while ( std::getline(ss, to, '\n') )
                                    this->addIngredient(to);
                        };

        char *ingridientChar = new char[line.length() + 1];
        strcpy(ingridientChar, line.c_str());
        splitStr(ingridientChar);
    }
}

void Recipe::exportToTxt(std::ofstream &fileStream)
{
    if (fileStream.is_open())
    {
        fileStream << "__RECIPE_BEG" << std::endl;
        fileStream << "__NAME" << std::endl << this->getName() << std::endl;
        fileStream << "__PHOTOPATH" << std::endl << this->getPhotoPath() << std::endl;
        fileStream << "__RECIPETXT" << std::endl << this->getRecipeTxt() << std::endl;
        fileStream << "__INGREDIENTS" << std::endl;
        auto ingredientsArray = this->getIngredients();
        std::for_each(ingredientsArray->begin(), ingredientsArray->end(), [&fileStream](std::string badPotato){ fileStream << badPotato << std::endl; });
        fileStream << "__RECIPE_END" << std::endl;
    }
}
