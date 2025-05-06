#ifndef OBSERVABLE_PANTRY_H
#define OBSERVABLE_PANTRY_H

#include "../Pantry.h"
#include "Observer.h"
#include <vector>

using namespace std;

class ObservablePantry : public Pantry {
private:
    Pantry pantry;
    vector<Observer*> observers;

public:
    void add_observer(Observer* obs);
    void remove_observer(Observer* obs);
    void notify();

    void add_ingredient(Ingredient* ing);
    void use_ingredient(const string& name, double amount);
    bool has_ingredient(const string& name, double quantity) const;
    vector<Ingredient*> get_ingredients() const;
    vector<Ingredient*> get_ingredient_by_name(const string& name) const;
};

#endif
