#include "ExactMatchStrategy.h"
#include "../ingredients/Ingredient.h"

using namespace std;

bool ExactMatchStrategy::can_cook(const Recipe& recipe, const ObservablePantry& pantry) const {
    for (Ingredient* req : recipe.get_ingredients()) {
        if (get_total_available_quantity(pantry, req->get_name()) < req->get_quantity()) {
            return false;
        }
    }
    return true;
}
