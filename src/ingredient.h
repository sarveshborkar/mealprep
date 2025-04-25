#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity;
    std::string unit;

public:
    Ingredient();
    Ingredient(const std::string name, const double quantity, const std::string unit);
    std::string get_name() const;
    double get_quantity() const;
    std::string get_unit() const;
    void add_quantity(const double amount);

    bool operator==(const Ingredient& other) const;
};

#endif
