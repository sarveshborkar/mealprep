#include "Pantry.h"
#include <iostream>

Pantry::Pantry(){
    load_default_pantry_ingredients();
}

void Pantry::load_default_pantry_ingredients(){
    ingredients["egg"] = Ingredient("Egg", 7.00, "pcs");
    ingredients["butter"] = Ingredient("Butter", 3.00, "tbsp");
    ingredients["salt"] = Ingredient("Salt", 3.00, "tbsp");
}

void Pantry::add_ingredient(const Ingredient& ingredient) {
    if(!has_ingredient(ingredient.get_name())){
        ingredients[ingredient.get_name()] = ingredient;
    }
    else{
        ingredients[ingredient.get_name()].add_quantity(ingredient.get_quantity());
    }
}

void Pantry::delete_ingredient(const Ingredient& ingredient) {
    ingredients[ingredient.get_name()].delete_quantity(ingredient.get_quantity());
}

bool Pantry::has_ingredient(const std::string ingredient_name) const {
    return ingredients.find(ingredient_name) != ingredients.end();
}

bool Pantry::has_ingredient_of_quantity(const std::string ingredient_name, const double quantity) {
    if (ingredients.find(ingredient_name) == ingredients.end())
        return false;
    Ingredient ingredient = ingredients[ingredient_name];
    if(ingredient.get_quantity() >= quantity){
        return true;
    }
    return false;
}

std::vector<Ingredient> Pantry::get_all_ingredients() const{
    std::vector<Ingredient> ingredientsVector;
    for(auto& it: ingredients){
        ingredientsVector.push_back(it.second);
    }
    return ingredientsVector;
}


std::string Pantry::validate_added_ingredient(const std::string name, const double quantity, const std::string unit){
    if(name == ""){
        return "Ingredient name cannot be empty";
    }
    if(quantity == 0.00){
        return "Ingredient must have non-zero quantity";
    }
    if (ingredients.find(name) != ingredients.end()){
        Ingredient existing_ingredient = ingredients[name];
        if(existing_ingredient.get_unit() != unit){
            return "Ingredient unit does not match with existing ingredient unit.";
        }
    }
    return "";
}
