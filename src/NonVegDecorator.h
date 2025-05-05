#ifndef NON_VEG_DECORATOR_H
#define NON_VEG_DECORATOR_H

#include "IngredientDecorator.h"

using namespace std;

class NonVegDecorator : public IngredientDecorator {
public:
    NonVegDecorator(Ingredient* ingredient)
        : IngredientDecorator(ingredient) {}

    string get_display_name() const override;
};

#endif
