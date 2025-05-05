#include "ExpiringSoonDecorator.h"
#include <ctime>

using namespace std;

string ExpiringSoonDecorator::get_display_name() const {
    time_t now = time(nullptr);
    double seconds_left = difftime(wrapped->get_expiration_date(), now);
    int days_left = static_cast<int>(seconds_left / (60 * 60 * 24));
    if (days_left <= 3) {
        return wrapped->get_display_name() + " [EXP]";
    } else {
        return wrapped->get_display_name();
    }
}
