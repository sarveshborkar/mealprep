#include "Recipe.h"

using namespace std;

Recipe::Recipe(const string& name) : name(name) {}

void Recipe::add_ingredient(Ingredient* ing) {
    ingredients.push_back(ing);
}

const string& Recipe::get_name() const {
    return name;
}

const vector<Ingredient*>& Recipe::get_ingredients() const {
    return ingredients;
}

Recipe::~Recipe() {
    for (Ingredient* ing : ingredients) {
        delete ing;
    }
}
