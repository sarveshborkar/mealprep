#include "SolidIngredient.h"

using namespace std;

SolidIngredient::SolidIngredient(string name, double quantity, string unit,
                                 time_t expiration_date, bool is_veg,
                                 bool requires_refrigeration, string texture_type)
    : Ingredient(name, quantity, unit, expiration_date, is_veg),
      requires_refrigeration(requires_refrigeration),
      texture_type(texture_type) {}

string SolidIngredient::get_display_name() const {
    return name + " [" + unit + ", Solid, " + texture_type +
           (requires_refrigeration ? ", Keep Cold" : "") + "]";
}

bool SolidIngredient::get_requires_refrigeration() const {
    return requires_refrigeration;
}

string SolidIngredient::get_texture_type() const {
    return texture_type;
}
