#include "ExpiringFirstStrategy.h"

bool ExpiringFirstStrategy::can_cook(const Recipe& recipe, const Pantry& pantry) const {
    time_t now = time(nullptr);

    for (Ingredient* ing : recipe.get_ingredients()) {
        double days_left = difftime(ing->get_expiration_date(), now) / (60 * 60 * 24);
        if (days_left <= 3) {
            return true;  // we want to prioritize recipes with at least one soon-expiring item
        }
    }

    return false;
}
