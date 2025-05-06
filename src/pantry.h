#ifndef PANTRY_H
#define PANTRY_H

#include "ingredients/Ingredient.h"
#include <vector>
#include <string>

using namespace std;

class Pantry {
private:
    vector<Ingredient*> ingredients;

public:
    void add_ingredient(Ingredient* ing);
    const vector<Ingredient*>& get_ingredients() const;
    vector<Ingredient*> get_all_ingredients_by_name(const string& name) const;
    bool has_ingredient(const string& name, double amount) const;
    void use_ingredient(const string& name, double amount);
    ~Pantry();
};

#endif
