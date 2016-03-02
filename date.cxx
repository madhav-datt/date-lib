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
#include <cstring>
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
 * Parse as static DateFormat member - format
 *
 * Throw exceptions when:
 * invalid_argument - d or m is invalid
 * domain_error - (d, m, y) as a triplet does not define a valid date
 * out_of_range - Date is out of range
 */
explicit Date::Date (const char* date_in) throw(invalid_argument, domain_error, out_of_range)
{
    // Take '-' as delimiter to break string date
    char* tmp_date = strtok (date_in,"-");
    char* tmp_month = strtok (NULL,"-");
    char* tmp_year = strtok (NULL,"-");

    // Check format for date from string against Date::format
    if (check_dateFormat (tmp_date, date_in.getFormat ().get_dateFormat ()) == true)
        date = stoi (tmp_date);
    else
        throw format_error ();

    // Check format for month from string against Date::format
    if (check_monthFormat (tmp_month, date_in.getFormat ().get_monthFormat ()) == true)
        month = stoi (tmp_month);
    else
        throw format_error ();

    // Check format for month from string against Date::format
    if (check_yearFormat (tmp_year, date_in.getFormat ().get_yearFormat ()) == true)
        year = stoi (tmp_year);
    else
        throw format_error ();

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
    // Increment by 1 day, using + operator
    (*this) = (*this) + 1;
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
    // Decrement by 1 day, using + operator
    (*this) = (*this) + (-1);
    return *this;
}

/**
 * Postfix -- Operator
 * Return Date for same day previous week
 */
Date& Date::operator-- (int)
{
    // Decrement by 7 days, using + operator
    (*this) = (*this) + (-7);
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
 * Optimized to work in constant time
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
operator Date::WeekNumber () const
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
operator Date::Month () const
{
    // Month of current Date
    Month month_val = month;
    return month_val;
}

/**
 * Cast current date to the day of the week
 */
operator Date::WeekDay () const
{
    // Array of constant pre-determined values to optimize computation
    // Based on recurring day-of-week patterns at the beginning of each month/year
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
bool Date::leapYear () const
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

/**
 * Give number of days from YEAR 0 (Reference Date Point) to (d, m, y) Date
 * End date is excluded in calculation
 */
uint32_t Date::to_days () const
{
    // Convert calendar to make March first month of year
    // Moves leap day in February to last day of leap year
    // Years now start in March, end in February
    // Month March is represented by 0, ... , February by 11
    uint32_t month_mod = (month + 9) % 12;

    // Modify year number according to new modified calendar
    uint32_t year_mod = year - month_mod / 10;

    // Total days in given years from Reference = 365 * year_mod + year_mod / 4 - year_mod / 100 + year_mod / 400
    // Total days in given months from year = month_mod * 306 + 5
    // Total days from start of month to date = date - 1
    return 365 * year_mod + year_mod / 4 - year_mod / 100 + year_mod / 400 + (month_mod * 306 + 5) / 10 + (date - 1);
}

/**
 * Give Date based on number of days from YEAR 0 (Reference Date Point)
 * End date is excluded in calculation
 */
Date Date::to_Date (uint32_t num_days)
{
    uint32_t d, m, y;

    // Close approximation for the year given a number of days
    // y = num_days / 365.2425 (Considers leap years)
    y = (10000 * num_days + 14780) / 3652425;

    // Total days in given years from Reference = 365 * year + year / 4 - year / 100 + year / 400
    // Removing years from total days from Reference
    uint32_t day_remaining = num_days - (365 * y + y / 4 - y / 100 + y / 400);

    // Handle overshoot
    if (day_remaining < 0)
    {
        y = y - 1;
        // Update remaing days after removing years from total days from Reference
        day_remaining = num_days - (365 * y + y / 4 - y / 100 + y / 400);
    }

    // Use converted calendar with March as first month of year
    // month_con_cal Month March is represented by 0, ... , February by 11
    // Total months from remainging days = (100 * day_remaining + 52) / 3060
    uint32_t month_con_cal = (100 * day_remaining + 52) / 3060;

    // Modifying calendar back to Gregorian calendar
    // January as first month and December as last
    m = (month_con_cal + 2) % 12 + 1;

    // Modify year number back to Gregorian calendar
    y = y + (month_con_cal + 2) / 12

    // Get date by subtracting days in counted month from remaining days
    // Number of days in months (according to modified calendar) = (month_con_cal * 306 + 5) / 10
    d = day_remaining - (month_con_cal * 306 + 5) / 10 + 1;

    // Create and return date object
    Date conv_Date (d, m, y);
    return conv_Date;
}

// Implementation of Date Class friend functions for BASIC I/O using Date::format

/**
 * Date object output operator
 */
ostream& Date::operator<< (ostream& os, const Date& date_out)
{
    os << date_formatting ()
    return os;
}

/**
 * Date object input operator
 */
istream& Date::operator>> (istream& is, Date& date_in)
{
    // Allocate tmp variables to check format
    char* tmp_date = new char[3];
    char* tmp_month = new char[4];
    char* tmp_year = new char[5];

    // Get input from input stream, using '-' as delimiter
    getline(is, tmp_date, '-');
    getline(is, tmp_month, '-');
    getline(is, tmp_year);

    // Check format for date from string against Date::format
    // is_input flag set to true
    if (check_dateFormat (tmp_date, date_in.getFormat ().get_dateFormat (), true) == true)
        date = stoi (tmp_date);
    else
        throw format_error ();

    // Check format for month from string against Date::format
    // is_input flag set to true
    if (check_monthFormat (tmp_month, date_in.getFormat ().get_monthFormat (), true) == true)
        month = stoi (tmp_month);
    else
        throw format_error ();

    // Check format for month from string against Date::format
    // is_input flag set to true
    if (check_yearFormat (tmp_year, date_in.getFormat ().get_yearFormat (), true) == true)
        year = stoi (tmp_year);
    else
        throw format_error ();

    return is;
}

// Format Functions to get/set Date Format

// Initialize static member format with default DateFormat
DateFormat Date::format ();

/**
 * Set Date Format for input/output of Dates
 * setFormat is a static function
 */
void Date::setFormat (DateFormat& date_formatting_input)
{
    format = date_formatting_input;
}

/**
 * Get previously set Date Format for input/output of Dates
 * getFormat is a static function
 */
DateFormat& Date::getFormat () const
{
    return format;
}
