#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include "Recipe.h"
#include "Pantry.h"
#include "CookabilityStrategy.h"
#include <vector>

using namespace std;

class RecipeBook {
private:
    vector<Recipe*> recipes;

public:
    ~RecipeBook();
    void add_recipe(Recipe* recipe);
    const vector<Recipe*>& get_all_recipes() const;

    vector<Recipe*> get_cookable_recipes(const Pantry& pantry,
                                         CookabilityStrategy* strategy) const;
};

#endif
