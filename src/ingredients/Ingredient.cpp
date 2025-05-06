#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg) : name(name), 
                        quantity(quantity), unit(unit), expiration_date(expiration_date), is_veg(is_veg) {}

string Ingredient::get_name() const {
    return name;
}

double Ingredient::get_quantity() const {
    return quantity;
}

string Ingredient::get_unit() const {
    return unit;
}

time_t Ingredient::get_expiration_date() const {
    return expiration_date;
}

bool Ingredient::get_is_veg() const {
    return is_veg;
}

void Ingredient::set_quantity(double q) {
    this->quantity = q;
}

bool Ingredient::operator==(const Ingredient& other) const {
    return name == other.name &&
           unit == other.unit &&
           expiration_date == other.expiration_date;
}
