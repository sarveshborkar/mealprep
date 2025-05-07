#include "Pantry.h"
#include <algorithm>

using namespace std;

void Pantry::add_ingredient(Ingredient* new_ing) {
    for (Ingredient* ing : ingredients) {
        if (ing->get_name() == new_ing->get_name() && ing->get_unit() == new_ing->get_unit() && ing->get_expiration_date() == new_ing->get_expiration_date()) {
            ing->set_quantity(ing->get_quantity() + new_ing->get_quantity());
            delete new_ing;
            return;
        }
    }
    ingredients.push_back(new_ing);
}

const vector<Ingredient*>& Pantry::get_ingredients() const {
    return ingredients;
}

bool Pantry::has_ingredient(const string& name, double amount) const {
    double total = 0.0;
    time_t now = time(nullptr);

    for (Ingredient* ing : ingredients) {
        if (ing->get_name() == name && ing->get_expiration_date() >= now) {
            total += ing->get_quantity();
        }
        if (total >= amount)
            return true;
    }
    return false;
}


vector<Ingredient*> Pantry::get_all_ingredients_by_name(const string& name) const {
    vector<Ingredient*> matches;
    for (Ingredient* ing : ingredients) {
        if (ing->get_name() == name) {
            matches.push_back(ing);
        }
    }
    return matches;
}

void Pantry::use_ingredient(const string& name, double amount) {
    sort(ingredients.begin(), ingredients.end(), [](Ingredient* a, Ingredient* b) {
        if (a->get_name() != b->get_name())
            return a->get_name() < b->get_name();
        return a->get_expiration_date() < b->get_expiration_date();
    });

    time_t now = time(nullptr);

    for (auto it = ingredients.begin(); it != ingredients.end() && amount > 0;) {
        Ingredient* ing = *it;

        if (ing->get_name() != name || ing->get_expiration_date() < now) {
            ++it;
            continue;
        }

        double available = ing->get_quantity();
        double used = min(available, amount);
        ing->set_quantity(available - used);
        amount -= used;

        if (ing->get_quantity() <= 0) {
            delete ing;
            it = ingredients.erase(it);
        } else {
            ++it;
        }
    }
}

Pantry::~Pantry() {
    for (Ingredient* ing : ingredients) {
        delete ing;
    }
}
