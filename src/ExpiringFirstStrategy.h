#ifndef EXPIRING_FIRST_STRATEGY_H
#define EXPIRING_FIRST_STRATEGY_H

#include "CookabilityStrategy.h"
#include <ctime>

class ExpiringFirstStrategy : public CookabilityStrategy {
public:
    bool can_cook(const Recipe& recipe, const Pantry& pantry) const override;
};

#endif
