#ifndef INGREDIENT_DECORATOR_H
#define INGREDIENT_DECORATOR_H

#include "Ingredient.h"

using namespace std;

class IngredientDecorator : public Ingredient {
protected:
    Ingredient* wrapped;

public:
    IngredientDecorator(Ingredient* ingredient)
        : Ingredient(*ingredient), wrapped(ingredient) {}

    virtual ~IngredientDecorator() {
        delete wrapped;
    }

    // Forward all basic methods to wrapped object
    string get_name() const override { return wrapped->get_name(); }
    double get_quantity() const override { return wrapped->get_quantity(); }
    string get_unit() const override { return wrapped->get_unit(); }
    time_t get_expiration_date() const override { return wrapped->get_expiration_date(); }
    bool get_is_veg() const override { return wrapped->get_is_veg(); }

    bool operator==(const Ingredient& other) const override {
        return wrapped->operator==(other);
    }
};

#endif
