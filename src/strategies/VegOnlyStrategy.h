#ifndef VEG_ONLY_STRATEGY_H
#define VEG_ONLY_STRATEGY_H

#include "CookabilityStrategy.h"

class VegOnlyStrategy : public CookabilityStrategy {
public:
    bool can_cook(const Recipe& recipe, const Pantry& pantry) const override;
};

#endif
