#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredient.h"
#include "Pantry.h"
#include <vector>
#include <string>

class Recipe {
private:
    std::string name;
    std::vector<Ingredient> required_ingredients;

public:
    Recipe();
    Recipe(std::string name, std::vector<Ingredient> required_ingredients);
    std::string get_name() const;
    std::vector<Ingredient> get_ingredients() const;
    bool can_cook(Pantry& pantry) const;
};

#endif
