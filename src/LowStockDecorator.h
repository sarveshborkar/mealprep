#ifndef LOW_STOCK_DECORATOR_H
#define LOW_STOCK_DECORATOR_H

#include "IngredientDecorator.h"

using namespace std;

class LowStockDecorator : public IngredientDecorator {
public:
    LowStockDecorator(Ingredient* ingredient)
        : IngredientDecorator(ingredient) {}

    string get_display_name() const override;
};

#endif
