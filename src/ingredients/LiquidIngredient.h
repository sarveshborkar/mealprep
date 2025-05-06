#ifndef LIQUID_INGREDIENT_H
#define LIQUID_INGREDIENT_H

#include "Ingredient.h"
#include <string>

using namespace std;

class LiquidIngredient : public Ingredient {
private:
    bool is_translucent;

public:
    LiquidIngredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg, bool is_translucent = false);
    double convert_unit(double quantity, string unit);
};

#endif
