#ifndef COOKABILITY_STRATEGY_H
#define COOKABILITY_STRATEGY_H

#include "../Recipe.h"
#include "../Pantry.h"
#include "../observer/ObservablePantry.h"

class CookabilityStrategy {
public:
    virtual ~CookabilityStrategy() = default;
    virtual bool can_cook(const Recipe& recipe, const ObservablePantry& pantry) const = 0;

protected:
    virtual double get_total_available_quantity(const ObservablePantry& pantry, const std::string& name) const;
};

#endif
