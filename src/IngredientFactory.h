#ifndef INGREDIENT_FACTORY_H
#define INGREDIENT_FACTORY_H

#include "ingredients/Ingredient.h"
#include <string>
#include <ctime>

using namespace std;

class IngredientFactory {
public:
    static Ingredient* create(const string& name, double quantity, const string& unit, time_t expiration_date, bool is_veg);
};

#endif
