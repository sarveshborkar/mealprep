#include "mealprep.h"
#include "ui_mealprep.h"
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QListWidgetItem>

mealprep::mealprep(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mealprep)
{
    ui->setupUi(this);
    //Pantry();
    //RecipeBook();

    ui->tabWidget->setCurrentIndex(0);

    // Pantry Table Initialization
    ui->pantry_table ->setColumnCount(3);
    QStringList headers_pantry = {"Name", "Quantity", "Unit"};
    ui->pantry_table->setHorizontalHeaderLabels(headers_pantry);
    ui->pantry_table->horizontalHeader()->setStretchLastSection(true);

    // Cookable Recipe Ingredients Table Initialization
    ui->cookable_recipe_ingredients_table->setColumnCount(3);
    QStringList headers_cookable_recipe = {"Name", "Quantity", "Unit"};
    ui->cookable_recipe_ingredients_table->setHorizontalHeaderLabels(headers_cookable_recipe);
    ui->cookable_recipe_ingredients_table->horizontalHeader()->setStretchLastSection(true);

    // Recipe Book Ingredients Table Initialization
    ui->recipe_book_ingredients_table->setColumnCount(3);
    QStringList headers_recipe_book = {"Name", "Quantity", "Unit"};
    ui->recipe_book_ingredients_table->setHorizontalHeaderLabels(headers_recipe_book);
    ui->recipe_book_ingredients_table->horizontalHeader()->setStretchLastSection(true);

    updatePantryTable();
    updateCookableRecipeList();
    updateRecipeBookList();
}

mealprep::~mealprep()
{
    delete ui;
}

void mealprep::on_add_button_clicked()
{
    QString ingredient_name = ui->ingredient_line_edit->text();
    double ingredient_quantity = ui->quantity_spin_box->value();
    QString ingredient_unit = ui->unit_combo_box->currentText();

    std::string validation_result = pantry.validate_added_ingredient(ingredient_name.toStdString(), ingredient_quantity, ingredient_unit.toStdString());

    if(validation_result != ""){
        QMessageBox::information(this, "Add", QString::fromStdString(validation_result));
    }
    else{
        Ingredient added_ingredient(ingredient_name.toStdString(), ingredient_quantity, ingredient_unit.toStdString());
        pantry.add_ingredient(added_ingredient);
        updatePantryTable();
        QMessageBox::information(this, "Add", "Ingredient added succesfully to the pantry.");
    }
    ui->ingredient_line_edit->clear();
    ui->quantity_spin_box->setValue(1.00);
    ui->unit_combo_box->setCurrentIndex(1);
}

void mealprep::updatePantryTable(){
    std::vector<Ingredient> ingredients  = pantry.get_all_ingredients();
    ui->pantry_table->setRowCount(ingredients.size());
    for (int i=0; i<ingredients.size(); i++) {
        const auto& ing = ingredients[i];
        ui->pantry_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing.get_name())));
        ui->pantry_table->setItem(i, 1, new QTableWidgetItem(QString::number(ing.get_quantity())));
        ui->pantry_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing.get_unit())));
    }
}

void mealprep::updateCookableRecipeList(){
    ui->cookable_recipe_list_view->clear();
    std::vector<Recipe> recipes = recipe_book.get_cookable_recipes(this->pantry);
    std::cout << recipes.size() << std::endl;
    for(auto& recipe : recipes){
        ui->cookable_recipe_list_view->addItem(QString::fromStdString(recipe.get_name()));
    }

}

void mealprep::updateCookableRecipeIngredientsTable(Recipe& recipe){
    ui->cookable_recipe_ingredients_table->clear();
    std::vector<Ingredient> ingredients = recipe.get_ingredients();
    std::cout<<"updateCookableRecipeIngredientsTable:" << ingredients.size()<<std::endl;
    ui->cookable_recipe_ingredients_table->setRowCount(ingredients.size());
    for (int i=0; i<ingredients.size(); i++) {
        const auto& ing = ingredients[i];
        ui->cookable_recipe_ingredients_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing.get_name())));
        ui->cookable_recipe_ingredients_table->setItem(i, 1, new QTableWidgetItem(QString::number(ing.get_quantity())));
        ui->cookable_recipe_ingredients_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing.get_unit())));
    }
}


void mealprep::on_cookable_recipe_list_view_itemClicked(QListWidgetItem *item)
{
    std::string recipe_name = item->text().toStdString();
    Recipe recipe = recipe_book.get_recipe(recipe_name);
    updateCookableRecipeIngredientsTable(recipe);

}


void mealprep::on_get_cookable_recipe_button_clicked()
{
    updateCookableRecipeList();
    ui->tabWidget->setCurrentIndex(1);
}


void mealprep::updateRecipeBookList(){
    ui->recipe_book_list_view->clear();
    std::vector<Recipe> recipes = recipe_book.get_all_recipes(this->pantry);
    std::cout << recipes.size() << std::endl;
    for(auto& recipe : recipes){
        ui->recipe_book_list_view->addItem(QString::fromStdString(recipe.get_name()));
    }

}

void mealprep::updateRecipeBookIngredientsTable(Recipe& recipe){
    ui->recipe_book_ingredients_table->clear();
    std::vector<Ingredient> ingredients = recipe.get_ingredients();
    ui->recipe_book_ingredients_table->setRowCount(ingredients.size());
    for (int i=0; i<ingredients.size(); i++) {
        const auto& ing = ingredients[i];
        ui->recipe_book_ingredients_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing.get_name())));
        ui->recipe_book_ingredients_table->setItem(i, 1, new QTableWidgetItem(QString::number(ing.get_quantity())));
        ui->recipe_book_ingredients_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing.get_unit())));
    }
}


void mealprep::on_recipe_book_list_view_itemClicked(QListWidgetItem *item)
{
    std::string recipe_name = item->text().toStdString();
    Recipe recipe = recipe_book.get_recipe(recipe_name);
    updateRecipeBookIngredientsTable(recipe);
}

