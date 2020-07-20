#ifndef STLSPIELWIESE_LOGGER_HPP
#define STLSPIELWIESE_LOGGER_HPP

#include <fstream>
#include <string>

class Logger {
    using string = std::string;
public:
    enum class Level {
        INFO,
        WARN,
        ERROR
    };
    using Level = Logger::Level;

protected:
    std::ofstream _f;
    
    void print_date();
    
    void print_time();
    
    void print_level(Level lvl);
    
public:
    explicit Logger(const string& filename);
    
    ~Logger();
    
    void log(Level lvl, const string& message);
};


#endif //STLSPIELWIESE_LOGGER_HPP