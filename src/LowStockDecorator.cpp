#include "LowStockDecorator.h"

using namespace std;

string LowStockDecorator::get_display_name() const {
    return wrapped->get_display_name() + " [LOW]";
}
