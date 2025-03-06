#include <iostream>

class BulgarianDate {
    unsigned DAYS_IN_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    unsigned day = 1;
    unsigned month = 1;
    unsigned year = 1;

    mutable bool isModified = false;
    mutable int dayOfWeek = 5;

    bool isValid = true;
    bool isValidDate(unsigned day, unsigned month, unsigned year) const;
    bool isLeapYear(unsigned year) const;

public:
    BulgarianDate() = default;
    BulgarianDate(unsigned day, unsigned month, unsigned year);

    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;

    bool setDay(unsigned day);
    bool setMonth(unsigned month);
    bool setYear(unsigned year);

    bool good() const;

    void goToNextDay();

    unsigned getDayOfWeek() const;

};

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs);
