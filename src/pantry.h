#ifndef PANTRY_H
#define PANTRY_H

#include "Ingredient.h"
#include <vector>
#include <string>

using namespace std;

class Pantry {
private:
    vector<Ingredient*> ingredients;

public:
    void add_ingredient(Ingredient* ing);
    const vector<Ingredient*>& get_ingredients() const;

    bool has_ingredient(const string& name,
                        double required_quantity,
                        const string& unit) const;

    ~Pantry();
};

#endif
