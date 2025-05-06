#include "VegOnlyStrategy.h"

bool VegOnlyStrategy::can_cook(const Recipe& recipe, const ObservablePantry& pantry) const {
    for (Ingredient* req : recipe.get_ingredients()) {
        if (!req->get_is_veg()) 
            return false;
        if (get_total_available_quantity(pantry, req->get_name()) < req->get_quantity()) {
            return false;
        }
    }
    return true;
}
