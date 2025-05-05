#include "ExactMatchStrategy.h"
#include "Ingredient.h"

bool ExactMatchStrategy::can_cook(const Recipe& recipe, const Pantry& pantry) const {
    for (Ingredient* required : recipe.get_ingredients()) {
        if (!pantry.has_ingredient(required->get_name(),
                                    required->get_quantity(),
                                    required->get_unit())) {
            return false;
        }
    }
    return true;
}
