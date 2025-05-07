#include "RecipeBook.h"
#include "src/observer/ObservablePantry.h"

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

vector<Recipe*> RecipeBook::get_cookable_recipes(const ObservablePantry& pantry, CookabilityStrategy* strategy) const {
    vector<Recipe*> result;

    for (Recipe* r : recipes) {
        if (strategy->can_cook(*r, pantry)) {
            result.push_back(r);
        }
    }
    return result;
}

Recipe* RecipeBook::get_recipe(const string& name) {
    for (Recipe* recipe : recipes) {
        if (recipe->get_name() == name) {
            return recipe;
        }
    }
    return nullptr;
}

void RecipeBook::cook_recipe(ObservablePantry& pantry, const string& name) {
    Recipe* recipe = get_recipe(name);
    if (!recipe) return;

    for (Ingredient* ing : recipe->get_ingredients()) {
        if (!pantry.has_ingredient(ing->get_name(), ing->get_quantity())) {
            cerr << "Missing or insufficient ingredient: " << ing->get_name() << endl;
            return;
        }
    }

    for (Ingredient* ing : recipe->get_ingredients()) {
        pantry.use_ingredient(ing->get_name(), ing->get_quantity());
    }
}
