#include <iomanip>
#include "Date.hpp"

std::vector<std::string> DateFormat::short_names = {"Jan", "Feb", "Mrz", "Apr", "Mai", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez"};
std::vector<std::string> DateFormat::full_names = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};
std::vector<std::string> DateFormat::weekdays = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

Date::Date(int d, int m, int y, int wd, DateFormat *df) : _d(d), _m(m), _y(y), _wd(wd), _df(df) {}

Date Date::get_current_date() {
    time_t now = time(nullptr);
    tm *t = localtime(&now);
    return {t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_wday, nullptr};
}

int Date::get_day() {
    return _d;
}

int Date::get_month() {
    return _m;
}

int Date::get_year() {
    return _y;
}

int Date::get_weekday() {
    return _wd;
}

void Date::set_format(DateFormat *df) {
    _df = df;
}

std::string Date::to_string() {
    return _df->format(this);
}

std::string DateFormatNumeric::format(Date *d) {
    std::ostringstream res;
    res << std::setw(2) << std::setfill('0') << d->get_day() << "."
        << std::setw(2) << std::setfill('0') << d->get_month() << "."
        << d->get_year();
    return res.str();
}

std::string DateFormatShort::format(Date *d) {
    std::ostringstream res;
    int index = d->get_month() - 1;
    std::string month_name = short_names.at(index);
    res << std::setw(2) << std::setfill('0') << d->get_day() << ". "
        << month_name << " "
        << d->get_year();
    return res.str();
}

std::string DateFormatLong::format(Date *d) {
    std::ostringstream res;
    int index = d->get_month() - 1;
    std::string month_name = full_names.at(index);
    res << d->get_day() << ". "
        << month_name << " "
        << d->get_year();
    return res.str();
}

std::string DateFormatFull::format(Date *d) {
    std::ostringstream res;
    int index = d->get_month() - 1;
    std::string month_name = full_names.at(index);
    int index_weekday = d->get_weekday();
    std::string weekday = weekdays.at(index_weekday);
    res << weekday << ", "
        << d->get_day() << ". "
        << month_name << " "
        << d->get_year();
    return res.str();
}

std::ostream& operator<<(std::ostream& o, Date d) {
    o << d.to_string();
    return o;
}