#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredient.h"
#include <vector>
#include <string>

using namespace std;

class Recipe {
private:
    string name;
    vector<Ingredient*> ingredients;

public:
    Recipe(const string& name);
    ~Recipe();

    void add_ingredient(Ingredient* ing);
    const string& get_name() const;
    const vector<Ingredient*>& get_ingredients() const;
};

#endif
