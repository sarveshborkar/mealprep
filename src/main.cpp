// #include <iostream>
// #include <ctime>
// #include "ingredients/IngredientFactory.h"
// #include "Pantry.h"
// #include "Recipe.h"
// #include "RecipeBook.h"
// #include "strategies/ExactMatchStrategy.h"
// #include "strategies/VegOnlyStrategy.h"
// #include "strategies/ExpiringFirstStrategy.h"

// using namespace std;

// int main() {
//     // Create Pantry
//     Pantry pantry;

//     // Create Ingredients and add to Pantry
//     time_t now = time(nullptr);
//     time_t exp_soon = now + (2 * 24 * 60 * 60);  // 2 days from now
//     time_t exp_later = now + (10 * 24 * 60 * 60); // 10 days from now

//     Ingredient* milk = IngredientFactory::create("Milk", 1.5, "liters", exp_soon, true);
//     Ingredient* egg = IngredientFactory::create("Egg", 6, "pieces", exp_later, false);
//     Ingredient* flour = IngredientFactory::create("Flour", 500, "grams", exp_later, true);

//     pantry.add_ingredient(milk);
//     pantry.add_ingredient(egg);
//     pantry.add_ingredient(flour);

//     // Create Recipe
//     Recipe* pancake = new Recipe("Pancakes");
//     pancake->add_ingredient(IngredientFactory::create("Milk", 1.0, "liters", exp_soon, true));
//     pancake->add_ingredient(IngredientFactory::create("Flour", 300, "grams", exp_later, true));
//     pancake->add_ingredient(IngredientFactory::create("Egg", 2, "pieces", exp_later, false));

//     // Create another veg-only Recipe
//     Recipe* vegan_bread = new Recipe("Vegan Bread");
//     vegan_bread->add_ingredient(IngredientFactory::create("Flour", 400, "grams", exp_later, true));
//     vegan_bread->add_ingredient(IngredientFactory::create("Milk", 1.0, "liters", exp_soon, true));

//     // Add Recipes to RecipeBook
//     RecipeBook book;
//     book.add_recipe(pancake);
//     book.add_recipe(vegan_bread);

//     // Run Strategies
//     cout << "\n=== Using ExactMatchStrategy ===" << endl;
//     ExactMatchStrategy exact;
//     for (Recipe* r : book.get_cookable_recipes(pantry, &exact)) {
//         cout << "Can cook: " << r->get_name() << endl;
//     }

//     cout << "\n=== Using VegOnlyStrategy ===" << endl;
//     VegOnlyStrategy veg;
//     for (Recipe* r : book.get_cookable_recipes(pantry, &veg)) {
//         cout << "Can cook (veg only): " << r->get_name() << endl;
//     }

//     cout << "\n=== Using ExpiringFirstStrategy ===" << endl;
//     ExpiringFirstStrategy expFirst;
//     for (Recipe* r : book.get_cookable_recipes(pantry, &expFirst)) {
//         cout << "Can cook (using expiring items): " << r->get_name() << endl;
//     }

//     return 0;
// }
