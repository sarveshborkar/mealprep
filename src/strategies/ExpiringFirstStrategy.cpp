#include "ExpiringFirstStrategy.h"
#include "../ingredients/Ingredient.h"
#include <ctime>
#include <iostream>

using namespace std;

static time_t get_earliest_expiry(const ObservablePantry& pantry, const std::string& name) {
    time_t now = time(nullptr);
    time_t earliest = now + 365 * 24 * 60 * 60;

    for (Ingredient* ing : pantry.get_ingredient_by_name(name)) {
        cout << ing->get_name() << ": " << ing->get_expiration_date();
        if (ing->get_expiration_date() >= now && ing->get_expiration_date() < earliest) {
            earliest = ing->get_expiration_date();
        }
    }

    return earliest;
}

bool ExpiringFirstStrategy::can_cook(const Recipe& recipe, const ObservablePantry& pantry) const {
    time_t now = time(nullptr);

    for (Ingredient* req : recipe.get_ingredients()) {
        double total = get_total_available_quantity(pantry, req->get_name());
        if (total < req->get_quantity()) 
            return false;

        time_t earliest = get_earliest_expiry(pantry, req->get_name());
        double days_left = difftime(earliest, now) / (60 * 60 * 24);
        //cout << req->get_name() << ": " << days_left << endl;
        if (days_left < 3)
            return true;
    }

    return false;
}
