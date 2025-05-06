#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <ctime>

using namespace std;

class Ingredient {
protected:
    string name;
    double quantity;
    string unit;
    time_t expiration_date;
    bool is_veg;

public:
    Ingredient(string name, double quantity, string unit, time_t expiration_date, bool is_veg);
    virtual string get_display_name() const = 0;
    virtual string get_name() const;
    virtual double get_quantity() const;
    virtual string get_unit() const;
    virtual time_t get_expiration_date() const;
    virtual bool get_is_veg() const;
    virtual void set_quantity(double q);
    virtual bool operator==(const Ingredient& other) const;
    virtual ~Ingredient() = default;
};

#endif
