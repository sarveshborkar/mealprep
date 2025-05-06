#ifndef COUNTABLE_INGREDIENT_H
#define COUNTABLE_INGREDIENT_H

#include "../ingredients/Ingredient.h"
#include <string>

using namespace std;

class CountableIngredient : public Ingredient {
private:
    bool is_fragile;
    bool has_shell_or_peel;

public:
    CountableIngredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg,
                        bool is_fragile = false, bool has_shell_or_peel = false);
};

#endif
