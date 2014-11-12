#ifndef RECIPE_H
#define RECIPE_H
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>

typedef std::vector<std::string> stringArray;
typedef std::shared_ptr<stringArray> stringArrayPtr;

class Recipe;
typedef std::shared_ptr<Recipe> RecipePtr;
typedef std::vector<RecipePtr> RecipeArray;
typedef std::shared_ptr<RecipeArray> RecipeArrayPtr;

class Recipe
{
private:
    stringArrayPtr m_ingredients;
    std::string m_name;
    std::string m_recipeTxt;
    int m_id;
    int m_cookingTime;
    std::string m_photoPath;

public:
    Recipe();
    ~Recipe();
    stringArrayPtr getIngredients();
    void addIngredient(std::string ingredient);
    void setIngredients(stringArrayPtr);
    std::string getName();
    void setName(std::string name);
    std::string getRecipeTxt();
    void setRecipeTxt(std::string recipeTxt);
    int getId();
    void setId(int id);
    int getCookingTime();
    void setCookingTime(int time);
    std::string getPhotoPath();
    void setPhotoPath(std::string photoPath);

    void importFromTxt(std::ifstream &stream);
    void exportToTxt(std::ofstream &stream);
};

#endif // RECIPE_H
