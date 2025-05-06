#include "CookabilityStrategy.h"
#include "../ingredients/Ingredient.h"
#include <ctime>

double CookabilityStrategy::get_total_available_quantity(const Pantry& pantry, const std::string& name) const {
    double total = 0.0;
    time_t now = time(nullptr);

    for (Ingredient* ing : pantry.get_all_ingredients_by_name(name)) {
        if (ing->get_expiration_date() >= now) {
            total += ing->get_quantity();
        }
    }

    return total;
}
