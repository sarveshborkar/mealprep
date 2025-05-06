#include "IngredientFactory.h"
#include "ingredients/LiquidIngredient.h"
#include "ingredients/SolidIngredient.h"
#include "ingredients/CountableIngredient.h"

#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

Ingredient* IngredientFactory::create(const string& name, double quantity, const string& unit, time_t expiration_date, bool is_veg,
    bool is_fragile, bool has_shell_or_peel, bool is_translucent, bool requires_refrigeration, string texture_type) {
    
    string lower_unit = unit;
    transform(lower_unit.begin(), lower_unit.end(), lower_unit.begin(), ::tolower);

    Ingredient* ing = nullptr;
    double standardized_quantity = quantity;
    string standardized_unit = unit;

    static unordered_set<string> liquid_units = {"ml", "l"};
    static unordered_set<string> solid_units = {"g", "kg"};

    if (liquid_units.count(lower_unit)) {
        ing = new LiquidIngredient(name, standardized_quantity, lower_unit, expiration_date, is_veg, is_translucent);
    } else if (solid_units.count(lower_unit)) {
        ing = new SolidIngredient(name, standardized_quantity, lower_unit, expiration_date, is_veg, requires_refrigeration, texture_type);
    } else {
        ing = new CountableIngredient(name, quantity, lower_unit, expiration_date, is_veg, is_fragile, has_shell_or_peel);
    }

    return ing;
}
