/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains implementation of the Date Class
 *
 */

#include <iostream>
#include <exception>
#include <cstdio>
#include <string>
#include <ctime>

#include "date.h"
#include "date_comp.h"

using namespace std;

// Implementation of Date Class CONSTRUCTORS

/**
 * Construct a Date from (d, m, y) values
 *
 * Throw exceptions when:
 * invalid_argument - d or m is invalid
 * domain_error - (d, m, y) as a triplet does not define a valid date
 * out_of_range - Date is out of range
 */
Date::Date (Day d, Month m, Year y) throw (invalid_argument, domain_error, out_of_range):
    date (d),
    month (m),
    year (y)
{
    // Throw exception if date or month are invalid
    if (is_valid_Arg (date, month) == false)
        throw invalid_argument ();

    // Throw exception if (d, m, y) is not a valid date
    if (is_valid_Date (date, month, year) == false)
        throw domain_error ();

    // Throw exception if date is out of range
    if (year >= 2050 || year <= 1949)
        throw out_of_range ();
}

/** TODO
 * Construct a Date from string
 * Parse as static DateFormat member  - format
 *
 * Throw exceptions when:
 * invalid_argument - d or m is invalid
 * domain_error - (d, m, y) as a triplet does not define a valid date
 * out_of_range - Date is out of range
 */
explicit Date::Date (const char* date) throw(invalid_argument, domain_error, out_of_range)
{
    // Throw exception if date or month are invalid
    if (is_valid_Arg (date, month) == false)
        throw invalid_argument ();

    // Throw exception if (d, m, y) is not a valid date
    if (is_valid_Date (date, month, year) == false)
        throw domain_error ();

    // Throw exception if date is out of range
    if (year >= 2050 || year <= 1949)
        throw out_of_range ();
}

/**
 * Default Constructor - construct ’today’
 * Initializes date values to today's date from system
 */
Date::Date () throw (domain_error, out_of_range)
{
    // Get current date and time
    time_t current_time = time (0);
    struct tm* now = localtime (&current_time);

    // Assign date values to class members
    date = now -> tm_mday;
    month = now -> tm_mon + 1;
    year = now -> tm_year + 1900;

    // Throw exception if date is out of range
    if (year >= 2050 || year <= 1949)
        throw out_of_range ();
}

/**
 * Copy Constructor for Date
 */
Date::Date (const Date& cpy_date):
    date (cpy_date.date),
    month (cpy_date.month),
    year (cpy_date.year)
{
}

// Implementation of Date Class DESTRUCTOR

/**
 * Destructor for Date
 */
Date::~Date ()
{
}

// Implementation of BASIC ASSIGNMENT OPERATOR

/**
 * Copy Assignment Operator for Date objects
 */
Date& Date::operator= (const Date& equal_Date)
{
    date = equal_Date.date;
    month = equal_Date.month;
    year = equal_date.year;

    return *this;
}

// Implementation of UNARY ARITHMETIC OPERATORS

/**
 * Prefix ++ Operator
 * Return Date for next day
 */
Date& Date::operator++ ()
{
    date++; // Increment date by 1

    // Handle end of month situation
    if (is_valid_Date (date, month, year) == false)
    {
        date = 1;
        month++;

        // Handle end of year situation
        // Month will be invalid after increment at end of year
        if (is_valid_Arg (date, month) == false)
        {
            month = 1;
            year++;

            // Handle end of range situation
            if (year >= 2050)
                throw out_of_range ();
        }
    }
    return *this;
}

/**
 * Postfix ++ Operator
 * Return Date for same day next week
 */
Date& Date::operator++ (int)
{
    // Increment by 7 days, using + operator
    (*this) = (*this) + 7;
    return *this;
}

/**
 * Prefix -- Operator
 * Return Date for previous day
 */
Date& Date::operator-- ()
{
    date--; // Decrement date by 1

    // Handle beginning of month situation
    if (date == 0)
    {
        month--;
        // Handle beginning of year situation
        if (month == 0)
        {
            year--;
            month = 12;
            // Handle end of range situation
            if (year <= 1949)
                throw out_of_range ();
        }
        date = month_length (month, year);
    }
    return *this;
}

/**
 * Postfix -- Operator
 * Return Date for same day previous week
 */
Date& Date::operator-- (int)
{
    // Decrement by 7 days, using + operator
    (*this) = (*this) + 7;
    return *this;
}

// Implementation of BINARY ARITHMETIC OPERATORS

/**
 * Give number of days between otherDate and current date
 */
unsigned int Date::operator- (const Date& otherDate)
{
    return this -> to_days () - otherDate.to_days ();
}

/**
 * Give Date noOfDays after (before) the current date (based on sign of noOfDays)
 */
Date Date::operator+ (int noOfDays) throw (domain_error, out_of_range)
{
    Date shifted_Date (to_Date (this -> to_days () + noOfDays));

    // Throw exception if (d, m, y) is not a valid date
    if (is_valid_Date (shifted_Date.date, shifted_Date.month, shifted_Date.year) == false)
        throw domain_error ();

    // Throw exception if date is out of range
    if (shifted_Date.year >= 2050 || shifted_Date.year <= 1949)
        throw out_of_range ();

    return shifted_Date;
}

// Implementation of CAST OPERATORS

/**
 * Cast current date to week number of the year
 */
operator Date::WeekNumber() const
{
    WeekNumber week_num;

    // Find first Thursday of year
    Date year_start (1, 1, year);
    while ((WeekDay)year_start != 4)
        ++year_start;

    // Find start of Week 1 of year
    year_start = year_start + (-3);

    // Number of days between first week and current Date
    int num_days = (*this) - year_start;

    // Consider days before week containing first Thursday of year
    if (num_days < 0)
        // Fall in last week of previous year
        week_num = number_of_weeks (year - 1);
    else
        week_num = static_cast<int> (num_days / 7) + 1;

    return week_num;
}

/**
 * Cast current date to the month of the year
 */
operator Date::Month() const
{
    Month month_val = month;
    return month_val;
}

/**
 * Cast current date to the day of the week
 */
operator Date::WeekDay() const
{
    // Array of constant pre-determined values to optimize computation
    static const int fixed[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year = year - (month < 3);
    WeekDay DayofWeek = (year + year / 4 - year / 100 + year / 400 + fixed[m-1] + date) % 7;

    // Change Sunday DayofWeek value from 0 to 7
    if (DayofWeek == 0)
        DayofWeek = 7;

    return DayofWeek;
}

/**
 * Check if the year of the current date is a leap year
 */
bool Date::leapYear() const
{
    return is_leap_Year (year);
}

// Implementation of BINARY RELATIONAL OPERATORS

/**
 * Check if current date and otherDate are equal
 */
bool Date::operator== (const Date& otherDate)
{
    if ((date == otherDate.date) && (month == otherDate.month) && (year == otherDate.year))
        return true;

    return false;
}

/**
 * Check if current date and otherDate are not equal
 */
bool Date::operator!= (const Date& otherDate)
{
    if ((*this) == otherDate)
        return false;

    return true;
}

/**
 * Check if current date is less than (comes before) otherDate
 */
bool Date::operator< (const Date& otherDate)
{
    bool flag = false;

    // Earlier year before otherDate year
    if (year < otherDate.year)
        flag = true;

    // Same year as otherDate. Earlier month before otherDate month
    else if ((year == otherDate.year) && (month < otherDate.month))
        flag = true;

    // Same year, month as otherDate. Earlier date before otherDate date
    else if ((year == otherDate.year) && (month == otherDate.month) && (date < otherDate.date))
        flag = true;

    return flag;
}

/**
 * Check if current date is less than equal to (comes before) otherDate
 */
bool Date::operator<= (const Date& otherDate)
{
    if (((*this) < otherDate) || ((*this) == otherDate))
        return true;

    return false;
}

/**
 * Check if current date is greater than (comes after) otherDate
 */
bool Date::operator> (const Date& otherDate)
{
    bool flag = false;

    // Later year after otherDate year
    if (year > otherDate.year)
        flag = true;

    // Same year as otherDate. Later month after otherDate month
    else if ((year == otherDate.year) && (month > otherDate.month))
        flag = true;

    // Same year, month as otherDate. Later date after otherDate date
    else if ((year == otherDate.year) && (month == otherDate.month) && (date > otherDate.date))
        flag = true;

    return flag;
}

/**
 * Check if current date is greater than equal to (comes after) otherDate
 */
bool Date::operator>= (const Date& otherDate)
{
    if (((*this) > otherDate) || ((*this) == otherDate))
        return true;

    return false;
}

/**TODO
 * Give number of days from 01/01/1950 (beginning of range) to (d, m, y) Date
 * End date is excluded in calculation
 */
uint32_t Date::to_days () const
{
    uint32_t num_days = 0;

    // Convert (years - 1950) to days
    for (int y = 1950; y < year; y++)
    {
        if (is_leap_Year(y) == true)
            num_days = num_days + 366;
        else
            num_days = num_days + 365;
    }

    // Convert months to days
    for (int m = 1; m < month; m++)
    {
        num_days = num_days + month_length (m, y);
    }

    // Add days to day count
    num_days = num_days + date - 1;

    return num_days;
}

/**TODO
 * Give Date based on number of days from 01/01/1950
 * End date is excluded in calculation
 */
Date Date::to_Date (uint32_t num_days)
{
    uint32_t d, m, y;

    // Convert days to years from 1950
    for (y = 1950; num_days >= 365; y++)
    {
        if (is_leap_Year(y) == true && num_days >= 366)
            num_days = num_days - 366;
        else if (is_leap_Year(y) == false)
            num_days = num_days - 365;
    }

    // Convert days to months
    for (m = 1; num_days > month_length (m, y); m++)
    {
        num_days = num_days - month_length (m, y);
    }

    // Convert days to date
    d = num_days + 1;

    Date conv_Date (d, m, y);
    return conv_Date;
}
