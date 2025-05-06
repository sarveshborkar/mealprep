#include "SolidIngredient.h"

using namespace std;

SolidIngredient::SolidIngredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg, bool requires_refrigeration, string texture_type)
                                : Ingredient(name, convert_unit(quantity, unit), "g", expiration_date, is_veg), requires_refrigeration(requires_refrigeration), texture_type(texture_type) {}

string SolidIngredient::get_display_name() const {
    return name;
}

double SolidIngredient::convert_unit(double quantity, string unit) {
    if (unit == "g")
        return quantity;
    
    return quantity * 1000;
}