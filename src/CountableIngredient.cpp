#include "CountableIngredient.h"

using namespace std;

CountableIngredient::CountableIngredient(string name, double quantity, string unit,
                                         time_t expiration_date, bool is_veg,
                                         bool is_fragile, bool has_shell_or_peel)
    : Ingredient(name, quantity, unit, expiration_date, is_veg),
      is_fragile(is_fragile), has_shell_or_peel(has_shell_or_peel) {}

string CountableIngredient::get_display_name() const {
    return name + " [" + unit + ", Countable" +
           (is_fragile ? ", Fragile" : "") +
           (has_shell_or_peel ? ", Shell/Peel" : "") + "]";
}

bool CountableIngredient::get_is_fragile() const {
    return is_fragile;
}

bool CountableIngredient::get_has_shell_or_peel() const {
    return has_shell_or_peel;
}
