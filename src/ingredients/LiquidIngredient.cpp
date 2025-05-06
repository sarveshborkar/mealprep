#include "LiquidIngredient.h"

using namespace std;

LiquidIngredient::LiquidIngredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg, bool is_translucent)
    : Ingredient(name, convert_unit(quantity, unit), "ml", expiration_date, is_veg), is_translucent(is_translucent) {}

double LiquidIngredient::convert_unit(double quantity, string unit) {
    if (unit == "ml")
        return quantity;
    
    return quantity * 1000;
}