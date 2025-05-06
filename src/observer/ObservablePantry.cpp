#include "ObservablePantry.h"
#include <algorithm>
#include <ctime>

using namespace std;

void ObservablePantry::add_observer(Observer* obs) {
    observers.push_back(obs);
}

void ObservablePantry::remove_observer(Observer* obs) {
    observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
}

void ObservablePantry::notify() {
    for (Observer* obs : observers) {
        if (obs) obs->update();
    }
}

void ObservablePantry::add_ingredient(Ingredient* ing) {
    pantry.add_ingredient(ing);
    notify();
}

void ObservablePantry::use_ingredient(const string& name, double amount) {
    pantry.use_ingredient(name, amount);
    notify();
}

bool ObservablePantry::has_ingredient(const string& name, double quantity) const {
    return pantry.has_ingredient(name, quantity);
}

vector<Ingredient*> ObservablePantry::get_ingredients() const {
    return pantry.get_ingredients();
}

vector<Ingredient*> ObservablePantry::get_ingredient_by_name(const string& name) const {
    return pantry.get_all_ingredients_by_name(name);
}
