#include "RecipeBook.h"
#include <QMessageBox>

RecipeBook::RecipeBook():
    m_recipe(nullptr)
{
    m_recipe = std::make_shared<RecipeArray>();
    importFromTxt();
}

RecipeBook::~RecipeBook()
{
    exportToTxt();
}

RecipeBookPtr RecipeBook::getInstance()
{
    static RecipeBookPtr instance(new RecipeBook());
    return instance;
}

RecipeArrayPtr RecipeBook::getRecipeArray()
{
    return m_recipe;
}

RecipePtr RecipeBook::getRecipe(std::string name)
{
    for(auto i:*(m_recipe))
    {
        if(!i->getName().compare(name))
            return i;
    }
    return nullptr;
}

RecipePtr RecipeBook::getRecipe(int id)
{
    if (id < m_recipe->size())
        return m_recipe->at(id);
    else
        return nullptr;
}

void RecipeBook::addRecipe(RecipePtr recipe)
{
    m_recipe->push_back(recipe);
}

void RecipeBook::removeRecipe(int id)
{
    if (!m_recipe->empty())
        m_recipe->erase(m_recipe->begin() + id);
}

void RecipeBook::importFromTxt()
{
    QMessageBox *mb = new QMessageBox;
    mb->setText("check");
    std::ifstream fileStream;
    fileStream.open("recipes_list.recipe");
    std::string line;

    std::getline(fileStream, line);
    std::string str="_RECIPES";
    //mb->setText(QString::fromStdString("check000: '" + line + "'\ncmp = " + std::to_string(line.compare("_RECIPES")) + "\n lengths = " + std::to_string(line.length()) + ", " + std::to_string(str.length())));
    //mb->exec();
    if (line.compare("_RECIPES"))
    {
        mb->setText("check recipes");
        mb->exec();
        return;
    }
    std::getline(fileStream, line);
    while (!line.compare("__RECIPE_BEG"))
    {
        RecipePtr recipe = std::make_shared<Recipe>();
        recipe->importFromTxt(fileStream);
        this->addRecipe(recipe);
        fileStream.ignore(12); //ignoring optional '__RECIPE_END'
        std::getline(fileStream, line);
    }
    fileStream.close();
}

void RecipeBook::exportToTxt()
{
    std::ofstream fileStream;
    fileStream.open("recipes_list.recipe");
    fileStream << "_RECIPES" << std::endl;
    auto recipesArray = this->getRecipeArray();
    std::for_each( recipesArray->begin(), recipesArray->end(), [&fileStream](RecipePtr recipe){ recipe->exportToTxt(fileStream); });
    fileStream << "_END" << std::endl;
    fileStream.close();
}
