#include "VegOnlyStrategy.h"

bool VegOnlyStrategy::can_cook(const Recipe& recipe, const Pantry& pantry) const {
    for (Ingredient* ing : recipe.get_ingredients()) {
        if (!ing->get_is_veg()) {
            return false;
        }
    }
    return true;
}
