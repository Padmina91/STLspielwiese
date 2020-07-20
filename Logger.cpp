#include <iostream>
#include "Logger.hpp"
#include "Date.hpp"
#include "Time.hpp"

void Logger::print_date() {
    Date now = Date::get_current_date();
    DateFormatNumeric df;
    now.set_format(&df);
    _f << now << " ";
}

void Logger::print_time() {
    Time now = Time::get_current_time();
    _f << now.to_string() << " ";
}

void Logger::print_level(Logger::Level lvl) {
    switch(lvl) {
        case Level::INFO:
            _f << "[INFO ]: ";
            break;
        case Level::WARN:
            _f << "[WARN ]: ";
            break;
        case Level::ERROR:
            _f << "[ERROR]: ";
            break;
        default:
            _f << "Fehler. Konnte Warnstufe nicht finden.\n";
            break;
    }
}

Logger::Logger(const std::string& filename) {
    _f.open(filename, std::ios::app);
    if (!_f) {
        std::cout << "failed to open " << filename << std::endl;
    }
}

Logger::~Logger() {
    _f.close();
}

void Logger::log(Logger::Level lvl, const std::string& message) {
    print_date();
    print_time();
    print_level(lvl);
    _f << message << std::endl;
}