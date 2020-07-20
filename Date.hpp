#ifndef STLSPIELWIESE_DATE_HPP
#define STLSPIELWIESE_DATE_HPP

#include <string>
#include <vector>

class DateFormat;

class Date {
protected:
    int _d, _m, _y, _wd;
    DateFormat *_df;

public:
    Date(int d, int m, int y, int wd, DateFormat *df);
    
    static Date get_current_date();
    
    int get_day();
    
    int get_month();
    
    int get_year();
    
    int get_weekday();
    
    void set_format(DateFormat *df);
    
    std::string to_string();
};

class DateFormat { // mama class
public:
    static std::vector<std::string> short_names;
    static std::vector<std::string> full_names;
    static std::vector<std::string> weekdays;
    
    virtual std::string format(Date *d) = 0; // abstract method
};

class DateFormatNumeric : public DateFormat { // 1st baby class
public:
    std::string format(Date *d) final;
};

class DateFormatShort : public DateFormat {
    std::string format(Date *d) final;
};

class DateFormatLong : public DateFormat {
    std::string format(Date *d) final;
};

class DateFormatFull : public DateFormat {
    std::string format(Date *d) final;
};

std::ostream& operator<<(std::ostream& o, Date d);

#endif //STLSPIELWIESE_DATE_HPP