#include "Recipe.h"

Recipe::Recipe(){}

Recipe::Recipe(std::string name, std::vector<Ingredient> required_ingredients)
    : name(name), required_ingredients(required_ingredients) {}

std::string Recipe::get_name() const {
    return name;
}

std::vector<Ingredient> Recipe::get_ingredients() const {
    return required_ingredients;
}

bool Recipe::can_cook(Pantry& pantry) const{
    if(required_ingredients.size() == 0){
        return false;
    }
    for (const auto& ingredient: required_ingredients) {
        if (!pantry.has_ingredient_of_quantity(ingredient.get_name(), ingredient.get_quantity())) {
            return false;
        }
    }
    return true;
}
