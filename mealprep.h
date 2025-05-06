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

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_mealprep;
}
QT_END_NAMESPACE

class mealprep : public QMainWindow
{
    Q_OBJECT

public:
    mealprep(QWidget *parent = nullptr);
    ~mealprep();

private slots:
    void on_push_button_add_clicked();
    void on_list_widget_cookable_itemClicked(QListWidgetItem *item);
    void on_push_button_get_recipes_clicked();
    void on_list_widget_recipe_book_itemClicked(QListWidgetItem *item);
    void on_push_button_cook_recipe_clicked();

private:
    Ui::main_window_mealprep *ui;
    Pantry pantry;
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
