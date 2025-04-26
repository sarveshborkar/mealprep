#include "RecipeBook.h"


RecipeBook::RecipeBook(){
    load_default_recipes();
}

void RecipeBook::load_default_recipes(){
    std::vector<Ingredient> omlette_ingredients;

    // Omlette
    omlette_ingredients.push_back(Ingredient("egg", 2.00, "pcs"));
    omlette_ingredients.push_back(Ingredient("butter", 1.00, "tbsp"));
    omlette_ingredients.push_back(Ingredient("salt", 1.00, "tbsp"));
    recipes["omlette"] = Recipe("omlette", omlette_ingredients);
}

void RecipeBook::add_or_update_recipe(const Recipe& recipe) {
    recipes[recipe.get_name()] = recipe;
}

std::vector<Recipe> RecipeBook::get_cookable_recipes(Pantry& pantry){
    std::vector<Recipe> result;
    for (const auto& it: recipes) {
        Recipe recipe = it.second;
        if (recipe.can_cook(pantry)) {
            result.push_back(recipe);
        }
    }
    return result;
}

std::vector<Recipe> RecipeBook::get_all_recipes(Pantry& pantry){
    std::vector<Recipe> result;
    for (const auto& it: recipes) {
        Recipe recipe = it.second;
        result.push_back(recipe);
    }
    return result;
}

bool RecipeBook::has_recipe(const std::string name){
    return recipes.find(name) != recipes.end();
}

Recipe RecipeBook::get_recipe(std::string name){
    return recipes[name];
}

void RecipeBook::cook_recipe(Pantry& pantry, Recipe recipe){
    std::vector<Ingredient> required_ingredients = recipe.get_ingredients();
    for(Ingredient& ingredient : required_ingredients){
        pantry.delete_ingredient(ingredient);
    }
}



