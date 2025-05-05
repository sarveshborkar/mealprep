#include "DecoratorUtils.h"
#include "LowStockDecorator.h"
#include "NonVegDecorator.h"
#include "ExpiringSoonDecorator.h"

using namespace std;

Ingredient* DecoratorUtils::apply_all(Ingredient* base) {
    if (base->get_quantity() < 1.0) {
        base = new LowStockDecorator(base);
    }
    if (!base->get_is_veg()) {
        base = new NonVegDecorator(base);
    }
    // ExpiringSoonDecorator is always applied last
    base = new ExpiringSoonDecorator(base);
    return base;
}
