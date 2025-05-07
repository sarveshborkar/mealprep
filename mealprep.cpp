#include "mealprep.h"
#include "ui_mealprep.h"
#include "src/IngredientFactory.h"
#include "src/ingredients/SolidIngredient.h"
#include "src/ingredients/LiquidIngredient.h"
#include "src/ingredients/CountableIngredient.h"
#include "src/Recipe.h"

#include <QMessageBox>
#include <QDateTime>

using namespace std;

mealprep::mealprep(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_window_mealprep)
{
    ui->setupUi(this);
    ui->tab_widget_main->setCurrentIndex(0);
    ui->date_edit_expiry->setDate(QDate::currentDate());
    ui->date_edit_expiry->setMinimumDate(QDate::currentDate().addDays(-5));

    ui->check_box_translucent->hide();
    ui->check_box_fragile->hide();
    ui->check_box_shell->hide();

    ui->table_pantry->setColumnCount(4);
    ui->table_pantry->setHorizontalHeaderLabels({"Name", "Quantity", "Unit", "Expiry Date"});
    ui->table_pantry->horizontalHeader()->setStretchLastSection(true);
    ui->table_pantry->setColumnWidth(0, 400);
    ui->table_pantry->setColumnWidth(1, 80);
    ui->table_pantry->setColumnWidth(2, 100);
    ui->table_pantry->setColumnWidth(3, 100);

    ui->table_recipe_ingredients->setColumnCount(3);
    ui->table_recipe_ingredients->setHorizontalHeaderLabels({"Name", "Quantity", "Unit"});
    ui->table_recipe_ingredients->horizontalHeader()->setStretchLastSection(true);

    ui->table_book_ingredients->setColumnCount(3);
    ui->table_book_ingredients->setHorizontalHeaderLabels({"Name", "Quantity", "Unit"});
    ui->table_book_ingredients->horizontalHeader()->setStretchLastSection(true);
    load_demo_data();

    observable_pantry.add_observer(this);

    update_pantry_table();
    update_recipe_book_list();
    update_cookable_recipe_list();
}

mealprep::~mealprep() {
    delete ui;
}

void mealprep::update() {
    update_pantry_table();
    update_cookable_recipe_list();
}

void mealprep::on_push_button_add_clicked() {
    QString name = ui->line_edit_ingredient->text();
    double quantity = ui->spin_box_quantity->value();
    QString unit = ui->combo_box_unit->currentText();
    bool is_veg = ui->check_box_veg->isChecked();
    QDate date = ui->date_edit_expiry->date();
    time_t expiry = QDateTime(date, QTime(23, 59, 59)).toSecsSinceEpoch();
    bool is_translucent = ui->check_box_translucent->isChecked();
    bool requires_refrigeration = ui->check_box_refrigerate->isChecked();
    bool is_fragile = ui->check_box_fragile->isChecked();
    bool has_shell = ui->check_box_shell->isChecked();
    QString texture = ui->line_edit_texture_type->text();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Ingredient name cannot be empty.");
        return;
    }

    Ingredient* ingredient = IngredientFactory::create(
        name.toStdString(),
        quantity,
        unit.toStdString(),
        expiry,
        is_veg,
        is_fragile, has_shell,
        is_translucent, requires_refrigeration,
        texture.toStdString()
        );

    observable_pantry.add_ingredient(ingredient);
    observable_pantry.notify();

    ui->line_edit_ingredient->clear();
    ui->spin_box_quantity->setValue(1.0);
    ui->combo_box_unit->setCurrentIndex(0);
    ui->check_box_veg->setChecked(true);
    ui->date_edit_expiry->setDate(QDate::currentDate());

    QMessageBox::information(this, "Success", "Ingredient added to pantry.");
}

void mealprep::update_pantry_table() {
    ui->table_pantry->clearContents();
    ui->table_pantry->setRowCount(0);

    vector<Ingredient*> items = observable_pantry.get_ingredients();

    sort(items.begin(), items.end(), [](Ingredient* a, Ingredient* b) {
        if (a->get_name() != b->get_name())
            return a->get_name() < b->get_name();
        return a->get_expiration_date() < b->get_expiration_date();
    });

    ui->table_pantry->setRowCount(static_cast<int>(items.size()));

    for (size_t i = 0; i < items.size(); ++i) {
        auto* ing = items[i];
        ui->table_pantry->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing->get_name())));
        ui->table_pantry->setItem(i, 1, new QTableWidgetItem(QString::number(ing->get_quantity())));
        ui->table_pantry->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing->get_unit())));
        QDateTime expiry = QDateTime::fromSecsSinceEpoch(ing->get_expiration_date());
        ui->table_pantry->setItem(i, 3, new QTableWidgetItem(expiry.toString("yyyy-MM-dd")));
    }
}

CookabilityStrategy* mealprep::get_selected_strategy() {
    QString strategy = ui->combo_box_strategy->currentText();
    if (strategy == "Veg Only") return new VegOnlyStrategy();
    if (strategy == "Expiring First") return new ExpiringFirstStrategy();
    return new ExactMatchStrategy();
}

void mealprep::update_cookable_recipe_list() {
    ui->list_widget_cookable->clear();

    unique_ptr<CookabilityStrategy> strategy(get_selected_strategy());
    vector<Recipe*> cookable = recipe_book.get_cookable_recipes(observable_pantry, strategy.get());

    for (auto* recipe : cookable) {
        ui->list_widget_cookable->addItem(QString::fromStdString(recipe->get_name()));
    }

    ui->table_recipe_ingredients->clearContents();
}

void mealprep::update_cookable_recipe_ingredients_table(const Recipe& recipe) {
    const auto& ingredients = recipe.get_ingredients();
    ui->table_recipe_ingredients->setRowCount(static_cast<int>(ingredients.size()));
    for (size_t i = 0; i < ingredients.size(); ++i) {
        auto* ing = ingredients[i];
        ui->table_recipe_ingredients->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing->get_name())));
        ui->table_recipe_ingredients->setItem(i, 1, new QTableWidgetItem(QString::number(ing->get_quantity())));
        ui->table_recipe_ingredients->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing->get_unit())));
    }
}

void mealprep::on_list_widget_cookable_itemClicked(QListWidgetItem *item) {
    if (!item) return;
    string name = item->text().toStdString();
    Recipe* recipe = recipe_book.get_recipe(name);
    if (recipe) {
        update_cookable_recipe_ingredients_table(*recipe);
    }
}

void mealprep::on_push_button_get_recipes_clicked() {
    observable_pantry.notify();
    ui->tab_widget_main->setCurrentIndex(2);
}

void mealprep::update_recipe_book_list() {
    ui->list_widget_recipe_book->clear();
    const auto& all_recipes = recipe_book.get_all_recipes();
    for (auto* recipe : all_recipes) {
        ui->list_widget_recipe_book->addItem(QString::fromStdString(recipe->get_name()));
    }
}

void mealprep::update_recipe_book_ingredients_table(const Recipe& recipe) {
    const auto& ingredients = recipe.get_ingredients();
    ui->table_book_ingredients->setRowCount(static_cast<int>(ingredients.size()));
    for (size_t i = 0; i < ingredients.size(); ++i) {
        auto* ing = ingredients[i];
        ui->table_book_ingredients->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(ing->get_name())));
        ui->table_book_ingredients->setItem(i, 1, new QTableWidgetItem(QString::number(ing->get_quantity())));
        ui->table_book_ingredients->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(ing->get_unit())));
    }
}

void mealprep::on_list_widget_recipe_book_itemClicked(QListWidgetItem *item) {
    if (!item) return;
    string name = item->text().toStdString();
    Recipe* recipe = recipe_book.get_recipe(name);
    if (recipe) update_recipe_book_ingredients_table(*recipe);
}

void mealprep::on_push_button_cook_recipe_clicked() {
    auto* item = ui->list_widget_cookable->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Error", "Please select a cookable recipe.");
        return;
    }

    string name = item->text().toStdString();
    Recipe* recipe = recipe_book.get_recipe(name);
    if (recipe) {
        recipe_book.cook_recipe(observable_pantry, name);
        QMessageBox::information(this, "Success", "Recipe cooked successfully.");
        observable_pantry.notify();
        ui->tab_widget_main->setCurrentIndex(0);
    }
}

void mealprep::on_combo_box_unit_currentTextChanged(const QString& unit) {
    QString u = unit.toLower();

    ui->check_box_translucent->hide();
    ui->check_box_refrigerate->hide();
    ui->check_box_fragile->hide();
    ui->check_box_shell->hide();
    ui->label_texture->hide();
    ui->line_edit_texture_type->hide();

    if (u == "ml" || u == "l") {
        ui->check_box_translucent->show();
    } else if (u == "g" || u == "kg") {
        ui->check_box_refrigerate->show();
        ui->label_texture->show();
        ui->line_edit_texture_type->show();
    } else {
        ui->check_box_fragile->show();
        ui->check_box_shell->show();
    }
}

void mealprep::load_demo_data() {
    time_t flour_expiry = QDateTime(QDate::currentDate().addDays(60), QTime(23, 59, 59)).toSecsSinceEpoch();
    time_t sugar_expiry = QDateTime(QDate::currentDate().addDays(45), QTime(23, 59, 59)).toSecsSinceEpoch();
    time_t milk_expiry = QDateTime(QDate::currentDate().addDays(7),  QTime(23, 59, 59)).toSecsSinceEpoch();
    time_t egg_expiry = QDateTime(QDate::currentDate().addDays(10), QTime(23, 59, 59)).toSecsSinceEpoch();
    time_t oats_expiry  = QDateTime(QDate::currentDate().addDays(50), QTime(23, 59, 59)).toSecsSinceEpoch();
    time_t salt_expiry =  QDateTime(QDate::currentDate().addDays(90), QTime(23, 59, 59)).toSecsSinceEpoch();

    observable_pantry.add_ingredient(new SolidIngredient("Flour", 1000, "g", flour_expiry, true, false, "powder"));
    observable_pantry.add_ingredient(new SolidIngredient("Sugar", 500, "g", sugar_expiry, true, false, "crystals"));
    observable_pantry.add_ingredient(new LiquidIngredient("Milk", 2, "l", milk_expiry, true, true));
    observable_pantry.add_ingredient(new CountableIngredient("Egg", 3, "pcs", egg_expiry, false, true, true));
    observable_pantry.add_ingredient(new SolidIngredient("Oats", 500, "g", oats_expiry, true, false, "flakes"));
    observable_pantry.add_ingredient(new SolidIngredient("Salt", 100, "g", salt_expiry, true, false, "crystals"));

    Recipe* pancakes = new Recipe("Pancakes");
    pancakes->add_ingredient(new SolidIngredient("Flour", 200, "g", 0, true, false, "powder"));
    pancakes->add_ingredient(new SolidIngredient("Sugar", 50, "g", 0, true, false, "crystals"));
    pancakes->add_ingredient(new LiquidIngredient("Milk", 1, "l", 0, true, true));
    pancakes->add_ingredient(new CountableIngredient("Egg", 2, "pcs", 0, false, true, true));
    recipe_book.add_recipe(pancakes);

    Recipe* omelette = new Recipe("Omelette");
    omelette->add_ingredient(new CountableIngredient("Egg", 2, "pcs", 0, false, true, true));
    omelette->add_ingredient(new SolidIngredient("Salt", 5, "g", 0, true, false, "crystals"));
    recipe_book.add_recipe(omelette);

    Recipe* oatmeal = new Recipe("Oatmeal");
    oatmeal->add_ingredient(new SolidIngredient("Oats", 100, "g", 0, true, false, "flakes"));
    oatmeal->add_ingredient(new LiquidIngredient("Milk", 1, "l", 0, true, true));
    recipe_book.add_recipe(oatmeal);
}
