#include "mealprep.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mealprep w;
    w.show();
    return a.exec();
}
