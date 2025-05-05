#ifndef EXPIRING_SOON_DECORATOR_H
#define EXPIRING_SOON_DECORATOR_H

#include "IngredientDecorator.h"

using namespace std;

class ExpiringSoonDecorator : public IngredientDecorator {
public:
    ExpiringSoonDecorator(Ingredient* ingredient)
        : IngredientDecorator(ingredient) {}

    string get_display_name() const override;
};

#endif
