#ifndef SOLID_INGREDIENT_H
#define SOLID_INGREDIENT_H

#include "../ingredients/Ingredient.h"
#include <string>

using namespace std;

class SolidIngredient : public Ingredient {
private:
    bool requires_refrigeration;
    string texture_type;

public:
    SolidIngredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg, bool requires_refrigeration = false, string texture_type = "chunky");
    double convert_unit(double quantity, string unit);
};

#endif
