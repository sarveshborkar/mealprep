#include "NonVegDecorator.h"

using namespace std;

string NonVegDecorator::get_display_name() const {
    if (!wrapped->get_is_veg()) {
        return wrapped->get_display_name() + " [NON-VEG]";
    }
    return wrapped->get_display_name();
}
