#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H
#include <string>
#include <vector>
#include <memory>
#include "Recipe.h"

class RecipeBook;
typedef std::shared_ptr<RecipeBook> RecipeBookPtr;

class RecipeBook
{
private:
    RecipeArrayPtr m_recipe;

    void clearRecipeArray();
public:
    RecipeBook();
    ~RecipeBook();
    static RecipeBookPtr getInstance();
    RecipeArrayPtr getRecipeArray();
    RecipePtr getRecipe(std::string name);
    RecipePtr getRecipe(int id);
    void addRecipe(RecipePtr recipe);
    void removeRecipe(int id);

    void importFromTxt();
    void exportToTxt();
};

#endif // RECIPEBOOK_H
