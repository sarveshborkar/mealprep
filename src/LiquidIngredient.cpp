#include "LiquidIngredient.h"

using namespace std;

LiquidIngredient::LiquidIngredient(string name, double quantity, string unit,
                                   time_t expiration_date, bool is_veg,
                                   bool is_translucent)
    : Ingredient(name, quantity, unit, expiration_date, is_veg),
      is_translucent(is_translucent) {}

string LiquidIngredient::get_display_name() const {
    return name + " [" + unit + ", Liquid" + (is_translucent ? ", Clear" : ", Opaque") + "]";
}

bool LiquidIngredient::get_is_translucent() const {
    return is_translucent;
}
