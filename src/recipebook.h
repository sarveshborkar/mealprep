#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include "Recipe.h"
#include <vector>
#include <unordered_map>


class RecipeBook {
private:
    std::unordered_map<std::string, Recipe> recipes;

public:
    RecipeBook();
    void add_or_update_recipe(const Recipe& recipe);
    std::vector<Recipe> get_cookable_recipes(Pantry& pantry);
    std::vector<Recipe> get_all_recipes(Pantry& pantry);
    bool has_recipe(const std::string name);
    Recipe get_recipe(std::string name);
    Recipe get_ingredients_by_recipe_name(std::string name);

private:
    void load_default_recipes();
};

#endif
