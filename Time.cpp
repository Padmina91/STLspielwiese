#include "Time.hpp"
#include <sstream>
#include <iomanip>

Time::Time(int h, int min) : _h(h), _min(min) {}

std::string Time::to_string() const {
    std::ostringstream res;
    res << std::setw(2) << std::setfill('0') << _h << ":" << std::setw(2) << std::setfill('0') << _min;
    return res.str();
}

Time Time::get_current_time() {
    time_t now = time(nullptr);
    tm *t = localtime(&now);
    return {t->tm_hour, t->tm_min};
}