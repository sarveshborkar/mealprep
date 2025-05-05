#ifndef COOKABILITY_STRATEGY_H
#define COOKABILITY_STRATEGY_H

#include "Pantry.h"
#include "Recipe.h"

class CookabilityStrategy {
public:
    virtual bool can_cook(const Recipe& recipe, const Pantry& pantry) const = 0;
    virtual ~CookabilityStrategy() {}
};

#endif
