#ifndef STLSPIELWIESE_TIME_HPP
#define STLSPIELWIESE_TIME_HPP

#include <string>

class Time {
protected:
    int _h, _min;
public:
    Time(int h, int min);
    
    std::string to_string() const;
    
    static Time get_current_time();
};

#endif //STLSPIELWIESE_TIME_HPP