#include "IngredientFactory.h"

#include "LiquidIngredient.h"
#include "SolidIngredient.h"
#include "CountableIngredient.h"
#include "DecoratorUtils.h"

#include <algorithm>
#include <unordered_set>

using namespace std;

Ingredient* IngredientFactory::create(const string& name,
                                      double quantity,
                                      const string& unit,
                                      time_t expiration_date,
                                      bool is_veg) {
    // Normalize unit to lowercase
    string lower_unit = unit;
    transform(lower_unit.begin(), lower_unit.end(), lower_unit.begin(), ::tolower);

    Ingredient* raw = nullptr;

    static unordered_set<string> liquid_units = {"ml", "milliliter", "liters", "liter"};
    static unordered_set<string> solid_units = {"grams", "g", "kg", "kilograms"};
    static unordered_set<string> countable_units = {"pieces", "units", "pcs"};

    if (liquid_units.count(lower_unit)) {
        raw = new LiquidIngredient(name, quantity, unit, expiration_date, is_veg,
                                   /* is_translucent */ false); // can infer later
    } else if (solid_units.count(lower_unit)) {
        raw = new SolidIngredient(name, quantity, unit, expiration_date, is_veg,
                                  /* requires_refrigeration */ false,
                                  /* texture_type */ "chunky");
    } else if (countable_units.count(lower_unit)) {
        raw = new CountableIngredient(name, quantity, unit, expiration_date, is_veg,
                                      /* is_fragile */ false,
                                      /* has_shell_or_peel */ false);
    } else {
        // Default fallback
        raw = new SolidIngredient(name, quantity, unit, expiration_date, is_veg);
    }

    return DecoratorUtils::apply_all(raw);
}
