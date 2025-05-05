#include "Pantry.h"

using namespace std;

void Pantry::add_ingredient(Ingredient* ing) {
    ingredients.push_back(ing);
}

const vector<Ingredient*>& Pantry::get_ingredients() const {
    return ingredients;
}

bool Pantry::has_ingredient(const string& name,
                            double required_quantity,
                            const string& unit) const {
    for (Ingredient* ing : ingredients) {
        if (ing->get_name() == name &&
            ing->get_unit() == unit &&
            ing->get_quantity() >= required_quantity) {
            return true;
        }
    }
    return false;
}

Pantry::~Pantry() {
    for (Ingredient* ing : ingredients) {
        delete ing;
    }
}
