QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mealprep.cpp \
    src/ingredient.cpp \
    src/pantry.cpp \
    src/recipe.cpp \
    src/recipebook.cpp

HEADERS += \
    mealprep.h \
    src/ingredient.h \
    src/pantry.h \
    src/recipe.h \
    src/recipebook.h

FORMS += \
    mealprep.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
