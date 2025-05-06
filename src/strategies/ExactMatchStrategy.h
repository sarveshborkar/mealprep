#ifndef EXACT_MATCH_STRATEGY_H
#define EXACT_MATCH_STRATEGY_H

#include "CookabilityStrategy.h"

class ExactMatchStrategy : public CookabilityStrategy {
public:
    bool can_cook(const Recipe& recipe, const ObservablePantry& pantry) const override;
};

#endif
