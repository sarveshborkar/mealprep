QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Optional: disable deprecated Qt APIs before Qt 6
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    mealprep.cpp \
    src/IngredientFactory.cpp \
    src/Pantry.cpp \
    src/Recipe.cpp \
    src/RecipeBook.cpp \
    src/ingredients/Ingredient.cpp \
    src/ingredients/CountableIngredient.cpp \
    src/ingredients/LiquidIngredient.cpp \
    src/ingredients/SolidIngredient.cpp \
    src/strategies/CookabilityStrategy.cpp \
    src/strategies/ExactMatchStrategy.cpp \
    src/strategies/VegOnlyStrategy.cpp \
    src/strategies/ExpiringFirstStrategy.cpp

HEADERS += \
    mealprep.h \
    src/IngredientFactory.h \
    src/Pantry.h \
    src/Recipe.h \
    src/RecipeBook.h \
    src/ingredients/Ingredient.h \
    src/ingredients/CountableIngredient.h \
    src/ingredients/LiquidIngredient.h \
    src/ingredients/SolidIngredient.h \
    src/strategies/CookabilityStrategy.h \
    src/strategies/ExactMatchStrategy.h \
    src/strategies/VegOnlyStrategy.h \
    src/strategies/ExpiringFirstStrategy.h

FORMS += \
    mealprep.ui

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
