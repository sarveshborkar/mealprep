#include "ExpiringFirstStrategy.h"
#include "../ingredients/Ingredient.h"
#include <ctime>

static time_t get_earliest_expiry(const Pantry& pantry, const std::string& name) {
    time_t now = time(nullptr);
    time_t earliest = now + 365 * 24 * 60 * 60;

    for (Ingredient* ing : pantry.get_all_ingredients_by_name(name)) {
        if (ing->get_expiration_date() >= now && ing->get_expiration_date() < earliest) {
            earliest = ing->get_expiration_date();
        }
    }

    return earliest;
}

bool ExpiringFirstStrategy::can_cook(const Recipe& recipe, const Pantry& pantry) const {
    time_t now = time(nullptr);

    for (Ingredient* req : recipe.get_ingredients()) {
        double total = get_total_available_quantity(pantry, req->get_name());
        if (total < req->get_quantity()) 
            return false;

        time_t earliest = get_earliest_expiry(pantry, req->get_name());
        double days_left = difftime(earliest, now) / (60 * 60 * 24);
        if (days_left < 3)
            return true;
    }

    return false;
}
