#ifndef RECIPE_H
#define RECIPE_H

#include "ingredients/Ingredient.h"
#include <vector>
#include <string>

using namespace std;

class Recipe {
private:
    string name;
    vector<Ingredient*> ingredients;

public:
    Recipe(const string& name);
    void add_ingredient(Ingredient* ing);
    const string& get_name() const;
    const vector<Ingredient*>& get_ingredients() const;
    ~Recipe();
};

#endif
