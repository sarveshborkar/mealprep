#ifndef MEALPREP_H
#define MEALPREP_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDate>
#include "src/pantry.h"
#include "src/recipebook.h"
#include "src/strategies/CookabilityStrategy.h"
#include "src/strategies/ExactMatchStrategy.h"
#include "src/strategies/VegOnlyStrategy.h"
#include "src/strategies/ExpiringFirstStrategy.h"
#include "src/observer/Observer.h"
#include "src/observer/ObservablePantry.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_mealprep;
}
QT_END_NAMESPACE

class mealprep : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit mealprep(QWidget *parent = nullptr);
    ~mealprep();
    void update() override;

private slots:
    void on_push_button_add_clicked();
    void on_list_widget_cookable_itemClicked(QListWidgetItem *item);
    void on_push_button_get_recipes_clicked();
    void on_list_widget_recipe_book_itemClicked(QListWidgetItem *item);
    void on_push_button_cook_recipe_clicked();
    void on_combo_box_unit_currentTextChanged(const QString& unit);

private:
    Ui::main_window_mealprep *ui;
    ObservablePantry observable_pantry;
    RecipeBook recipe_book;

    void update_pantry_table();
    void update_cookable_recipe_list();
    void update_cookable_recipe_ingredients_table(const Recipe& recipe);
    void update_recipe_book_list();
    void update_recipe_book_ingredients_table(const Recipe& recipe);
    void load_demo_data();
    CookabilityStrategy* get_selected_strategy();
};
#endif // MEALPREP_H
