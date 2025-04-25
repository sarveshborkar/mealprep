#ifndef MEALPREP_H
#define MEALPREP_H

#include <QMainWindow>
#include <src/pantry.h>
#include <src/recipebook.h>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class mealprep;
}
QT_END_NAMESPACE

class mealprep : public QMainWindow
{
    Q_OBJECT

public:
    mealprep(QWidget *parent = nullptr);
    ~mealprep();

private slots:
    void on_add_button_clicked();
    void on_cookable_recipe_list_view_itemClicked(QListWidgetItem *item);

    void on_get_cookable_recipe_button_clicked();

    void on_recipe_book_list_view_itemClicked(QListWidgetItem *item);

private:
    Ui::mealprep *ui;
    Pantry pantry;
    RecipeBook recipe_book;

private:
    void updatePantryTable();
    void updateCookableRecipeList();
    void updateCookableRecipeIngredientsTable(Recipe& recipe);
    void updateRecipeBookList();
    void updateRecipeBookIngredientsTable(Recipe& recipe);
};
#endif // MEALPREP_H
