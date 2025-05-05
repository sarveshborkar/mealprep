#ifndef SOLID_INGREDIENT_H
#define SOLID_INGREDIENT_H

#include "Ingredient.h"
#include <string>

using namespace std;

class SolidIngredient : public Ingredient {
private:
    bool requires_refrigeration;
    string texture_type;  // e.g., "chunky", "powder", "smooth"

public:
    SolidIngredient(string name, double quantity, string unit,
                    time_t expiration_date, bool is_veg,
                    bool requires_refrigeration = false,
                    string texture_type = "chunky");

    string get_display_name() const override;

    // Getters
    bool get_requires_refrigeration() const;
    string get_texture_type() const;
};

#endif
