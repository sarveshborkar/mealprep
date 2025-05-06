#ifndef COOKABILITY_STRATEGY_H
#define COOKABILITY_STRATEGY_H

#include "../Recipe.h"
#include "../Pantry.h"

class CookabilityStrategy {
public:
    virtual ~CookabilityStrategy() = default;
    virtual bool can_cook(const Recipe& recipe, const Pantry& pantry) const = 0;

protected:
    double get_total_available_quantity(const Pantry& pantry, const std::string& name) const;
};

#endif
