#ifndef EXACT_MATCH_STRATEGY_H
#define EXACT_MATCH_STRATEGY_H

#include "CookabilityStrategy.h"

class ExactMatchStrategy : public CookabilityStrategy {
public:
    bool can_cook(const Recipe& recipe, const Pantry& pantry) const override;
};

#endif
