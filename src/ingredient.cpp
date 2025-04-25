#include "Ingredient.h"

Ingredient::Ingredient(){}

Ingredient::Ingredient(const std::string name, const double quantity, std::string unit)
    : name(name), quantity(quantity), unit(unit) {}

std::string Ingredient::get_name() const {
    return name;
}

double Ingredient::get_quantity() const {
    return quantity;
}

std::string Ingredient::get_unit() const {
    return unit;
}

void Ingredient::add_quantity(const double amount) {
    quantity += amount;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return name == other.name && unit == other.unit;
}
