#include "Ingredient.h"
#include <cctype>
#include <algorithm>

Ingredient::Ingredient(){}

Ingredient::Ingredient(const std::string name, const double quantity, std::string unit)
{
    this->name = to_lower_case(name);
    this->display_name = name;
    this->quantity = quantity;
    this->unit = unit;
}

std::string Ingredient::get_name() const {
    return name;
}

std::string Ingredient::get_display_name() const {
    return display_name;
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

void Ingredient::delete_quantity(const double amount) {
    quantity -= amount;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return name == other.name && unit == other.unit;
}

std::string Ingredient::to_lower_case(std::string input) const{
    std::string result = input;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return tolower(c); });
    return result;
}
