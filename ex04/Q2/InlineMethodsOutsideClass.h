#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
  Date() {}
  void set(int m, int d, int y);
  void print() const;
  int get_month() const;
  int get_day() const;
  int get_year() const;
private:
  int month, day, year;
};

inline void Date::set(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

inline void Date::print() const{
  std::cout << year << "/" << month << "/" << day;
}

inline int Date::get_month() const{
  return month;
}

inline int Date::get_day() const{
  return day;
}

inline int Date::get_year() const{
  return year;
}

#endif

