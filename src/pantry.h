#ifndef PANTRY_H
#define PANTRY_H

#include "ingredient.h"
#include <vector>
#include <string>
#include <unordered_map>


class Pantry {
private:
    std::unordered_map<std::string, Ingredient> ingredients;

private:
    void load_default_pantry_ingredients();

public:
    Pantry();
    void add_ingredient(const Ingredient& ingredient);
    void delete_ingredient(const Ingredient& ingredient);
    bool has_ingredient(const std::string ingredient_name) const;
    bool has_ingredient_of_quantity(const std::string ingredient_name, const double quantity);
    std::vector<Ingredient> get_all_ingredients() const;
    std::string validate_added_ingredient(const std::string name, const double quantity, const std::string unit);
};

#endif
