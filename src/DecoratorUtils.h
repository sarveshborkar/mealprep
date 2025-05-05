#ifndef DECORATOR_UTILS_H
#define DECORATOR_UTILS_H

#include "Ingredient.h"

using namespace std;

class DecoratorUtils {
public:
    static Ingredient* apply_all(Ingredient* base);
};

#endif
