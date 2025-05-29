#include <iostream>
#include "BulgarianDate.h"

bool BulgarianDate::isValidDate(unsigned day, unsigned month, unsigned year) const {
    return !(month == 0 || month > 12) ||
        (day == 0 || day > DAYS_IN_MONTH[day - 1]) ||
        year == 1916 && month == 4 && day < 14;
}

bool BulgarianDate::isLeapYear(unsigned year) const {
    if (year == 1916) {
        return year % 4 == 0;
    }
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

BulgarianDate::BulgarianDate(unsigned day, unsigned month, unsigned year) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

unsigned BulgarianDate::getDay() const {
    if (isValid) {
        return day;
    }
    return 0;
}

unsigned BulgarianDate::getMonth() const {
    if (isValid) {
        return month;
    }
    return 0;
}

unsigned BulgarianDate::getYear() const {
    if (isValid) {
        return year;
    }
    return 0;
}

bool BulgarianDate::setDay(unsigned day) {
    this->day = day;
    isValid = isValidDate(day, month, year);
    isModified = true;
    return isValid;
}

bool BulgarianDate::setMonth(unsigned month) {
    this->month = month;
    isValid = isValidDate(day, month, year);
    isModified = true;
    return isValid;
}

bool BulgarianDate::setYear(unsigned year) {
    this->year = year;
    
    if (isLeapYear(year)) {
        DAYS_IN_MONTH[1] = 29;
    }
    else {
        DAYS_IN_MONTH[1] = 28;
    }

    isValid = isValidDate(day, month, year);
    isModified = true;
    return isValid;
}

bool BulgarianDate::good() const {
    return isValid;
}

void BulgarianDate::goToNextDay()
{
    if (!good()) return;
    if (year == 1916 && month == 3 && day == 31) //Julian to the Gregorian calendar
    {
        day = 14;
        month = 4;
    }
    else
    {
        day++;
        if (day > DAYS_IN_MONTH[month - 1])
        {
            day = 1;
            setMonth(month == 12 ? 1 : (month + 1));
            if (month == 1)
                setYear(year + 1);
        }
    }
    isModified = true;
}

unsigned BulgarianDate::getDayOfWeek() const {
    if (!good()) {
        return 0;
    }
    if (!isModified) {
        return dayOfWeek;
    }
    BulgarianDate start;
    while (compareBulgarianDates(*this, start)) {
        start.goToNextDay();
        dayOfWeek++;
        dayOfWeek %= 7;
    }

    isModified = false;
    return dayOfWeek + 1;
}

int compareBulgarianDates(const BulgarianDate& lhs, const BulgarianDate& rhs)
{
    if (lhs.getYear() < rhs.getYear())
    {
        return -1;
    }
    else if (lhs.getYear() > rhs.getYear())
    {
        return 1;
    }
    else
    { // years are equal, compare months
        if (lhs.getMonth() < rhs.getMonth())
        {
            return -1;
        }
        else if (lhs.getMonth() > rhs.getMonth())
        {
            return 1;
        }
        else
        { // months are equal, compare days
            if (lhs.getDay() < rhs.getDay())
            {
                return -1;
            }
            else if (lhs.getDay() > rhs.getDay())
            {
                return 1;
            }
            else
            {
                return 0; // All are equal
            }
        }
    }
}
