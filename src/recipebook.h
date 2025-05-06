#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include "Recipe.h"
#include "Pantry.h"
#include "observer/ObservablePantry.h"
#include "strategies/CookabilityStrategy.h"
#include <vector>

using namespace std;

class RecipeBook {
private:
    vector<Recipe*> recipes;

public:
    void add_recipe(Recipe* recipe);
    const vector<Recipe*>& get_all_recipes() const;
    Recipe* get_recipe(const std::string& name);
    void cook_recipe(ObservablePantry& pantry, const std::string& name);
    vector<Recipe*> get_cookable_recipes(const ObservablePantry& pantry, CookabilityStrategy* strategy) const;
    ~RecipeBook();
};

#endif
