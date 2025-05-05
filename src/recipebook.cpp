#include "RecipeBook.h"

using namespace std;

RecipeBook::~RecipeBook() {
    for (Recipe* r : recipes) {
        delete r;
    }
}

void RecipeBook::add_recipe(Recipe* recipe) {
    recipes.push_back(recipe);
}

const vector<Recipe*>& RecipeBook::get_all_recipes() const {
    return recipes;
}

vector<Recipe*> RecipeBook::get_cookable_recipes(const Pantry& pantry,
                                                 CookabilityStrategy* strategy) const {
    vector<Recipe*> result;
    for (Recipe* r : recipes) {
        if (strategy->can_cook(*r, pantry)) {
            result.push_back(r);
        }
    }
    return result;
}
