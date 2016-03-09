/**
 * Contains implementation of the Date Class
 * Copyright (C)   2016    Madhav Datt
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *
 */

#include <iostream>
#include <exception>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "date.h"
#include "date-comp-lib/date_comp.h"

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
Date::Date (Day d, Month m, Year y) throw (invalid_argument, domain_error, out_of_range) :
date (d), month (m), year (y)
{
    // Throw exception if date or month are invalid
    if (is_valid_Arg (date, month) == false)
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Throw exception if (d, m, y) is not a valid date
    if (is_valid_Date (date, month, year) == false)
        throw domain_error (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Domain Error"));

    // Throw exception if date is out of range
    if (year >= 2050 || year <= 1949)
        throw out_of_range (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Out of Range"));
}

/**
 * Construct a Date from string
 * Parse as static DateFormat member - format
 *
 * Throw exceptions when:
 * invalid_argument - d or m is invalid
 * domain_error - (d, m, y) as a triplet does not define a valid date
 * out_of_range - Date is out of range
 */
Date::Date (const char* date_in) throw (invalid_argument, domain_error, out_of_range)
{
    // Check for NULL values
    if (date_in == NULL)
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Temperory format and date, month, year fields
    string tmp_field[3];
    string tmp_format (date_in);
    uint32_t pos = 0, i = 0;

    // Take '-' as delimiter to break string date
    while ((pos = tmp_format.find (delimiter)) != string::npos && i < 3)
    {
        tmp_field[i] = tmp_format.substr (0, pos);
        i++;

        // Remove already considered portion from string
        tmp_format.erase (0, pos + delimiter.length ());
    }

    // Check format for date from string against Date::format
    if (check_dateFormat (tmp_field[0], (*this).getFormat ().get_dateFormat ()) == true)
        date = atoi (tmp_field[0].c_str ());
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Check format for month from string against Date::format
    if (check_monthFormat (tmp_field[1],  (*this).getFormat ().get_monthFormat ()) == true)
    {
        // If Month is in numberical form
        if (strcmp ((*this).getFormat ().get_monthFormat (), "m") == 0 || strcmp ((*this).getFormat ().get_monthFormat (), "mm") == 0)
            month = atoi (tmp_field[1].c_str ());

        // If Month name/full name is used
        else
            for (int i = 1; i < 12; i++)
            {
                // Check match for names against each month for format
                if (tmp_field[1] == month_name (i) || tmp_field[1] == month_name_full (i))
                {
                    month = i;
                    break;
                }
            }
    }
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Check format for month from string against Date::format
    if (check_yearFormat (tmp_field[2], (*this).getFormat ().get_yearFormat ()) == true)
        year = atoi (tmp_field[2].c_str ());
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Convert 2 digit year (in "yy" format) to full 2 digit year values  ("yyyy" format)
    if (year < 50)
        // For years 2000 to 2049
        year = year + 2000;
    else if (year <= 99)
        // For year 1950 to 1999
        year = year + 1900;

    // Check Initialized Date for errors

    // Throw exception if date or month are invalid
    if (is_valid_Arg (date, month) == false)
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Throw exception if (d, m, y) is not a valid date
    if (is_valid_Date (date, month, year) == false)
        throw domain_error (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Domain Error"));

    // Throw exception if date is out of range
    if (year >= 2050 || year <= 1949)
        throw out_of_range (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Out of Range"));
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
        throw out_of_range (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Out of Range"));
}

/**
 * Copy Constructor for Date
 */
Date::Date (const Date& cpy_date): date (cpy_date.date), month (cpy_date.month), year (cpy_date.year)
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
    year = equal_Date.year;

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
    return (this -> to_days () > otherDate.to_days ()) ? (this -> to_days () - otherDate.to_days ()) : (otherDate.to_days () - this -> to_days ());
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
        throw domain_error (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Domain Error"));

    // Throw exception if date is out of range
    if (shifted_Date.year >= 2050 || shifted_Date.year <= 1949)
        throw out_of_range (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Out of Range"));

    return shifted_Date;
}

// Implementation of CAST OPERATORS

/**
 * Cast current date to week number of the year
 */
Date::operator WeekNumber () const
{
    int week_num;

    // Handle beginning of domain (underflow) cases - 1,2,3rd Jan, 1950
    if (year == 1950 && month == 1)
    {
        if (date == 1)
            return static_cast<WeekNumber> (52);
        else if (date == 2 || date == 3)
            return static_cast<WeekNumber> (1);
    }

    // Find first Thursday of year
    Date year_start (static_cast<Day> (1), static_cast<Month> (1), year);
    while ((WeekDay)year_start != 4)
        ++year_start;

    // Find start of Week 1 of year
    year_start = year_start + (-3);

    // Number of days between first week and current Date
    int num_days = this -> to_days () - year_start.to_days ();

    // Consider days before week containing first Thursday of year
    if (num_days < 0)
        // Fall in last week of previous year
        week_num = number_of_weeks (year - 1);
    else
        week_num = static_cast<int> (num_days / 7) + 1;

    // Handle end of year special case
    // Year end falls in next years first week
    if (week_num = number_of_weeks (year))
    {
        // Handle end of domain (overflow) cases
        if (year == 2049)
            return static_cast<WeekNumber> (week_num);

        Date next_year (static_cast<Day> (1), static_cast<Month> (1), year + 1);
        int weekStart = (WeekDay)next_year;

        // Consider days at end of year, falling in the first week of next year
        // If year yyyy starts with a Tuesday, then 31/12/(yyyy-1) is a Monday, in week 1 of yyyy
        if (weekStart > 1 && weekStart <= 4)
            if (next_year - (*this) < weekStart)
                week_num = 1;
    }

    return static_cast<WeekNumber> (week_num);
}

/**
 * Cast current date to the month of the year
 */
Date::operator Month () const
{
    // Month of current Date
    return static_cast<Month> (month);
}

/**
 * Cast current date to the day of the week
 */
Date::operator WeekDay () const
{
    // Array of constant pre-determined values to optimize computation
    // Based on recurring day-of-week patterns at the beginning of each month/year
    static const int fixed[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int year_mod = year - (month < 3);
    int DayofWeek = (year_mod + year_mod / 4 - year_mod / 100 + year_mod / 400 + fixed[month - 1] + date) % 7;

    // Change Sunday DayofWeek value from 0 to 7
    if (DayofWeek == 0)
        DayofWeek = 7;

    return static_cast<WeekDay> (DayofWeek);
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
    uint64_t day_mult = (10000 * num_days + 14780);
    y = num_days / 365.2425 + 14780.0 / 3652425.0;

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
    y = y + (month_con_cal + 2) / 12;

    // Get date by subtracting days in counted month from remaining days
    // Number of days in months (according to modified calendar) = (month_con_cal * 306 + 5) / 10
    d = day_remaining - (month_con_cal * 306 + 5) / 10 + 1;

    // Create and return date object
    Date conv_Date (static_cast<Day> (d), static_cast<Month> (m), y);
    return conv_Date;
}

// Implementation of Date Class friend functions for BASIC I/O using Date::format

/**
 * Date object output operator
 */
ostream& operator<< (ostream& os, const Date& date_out)
{
    // Output DATE as per Date::format
    // "d": single digit date in one digit, double digit date in two digits
    if (strcmp (date_out.getFormat ().get_dateFormat (), "d") == 0)
        os << date_out.date << "-";

    // "dd": all dates in two digits with single digit dates with leading 0
    else if (strcmp (date_out.getFormat ().get_dateFormat (), "dd") == 0)
    {
        if (date_out.date < 10)
            // Format single digit with 0 as prefix
            os << "0" << date_out.date << "-";
        else
            os << date_out.date << "-";
    }

    // Output MONTH as per Date::format
    // "m": single digit month in one digit, double digit month in two digits
    if (strcmp (date_out.getFormat ().get_monthFormat (), "m") == 0)
        os << date_out.month;

    // "mm": all months in two digits with single digit months with leading 0
    else if (strcmp (date_out.getFormat ().get_monthFormat (), "mm") == 0)
    {
        if (date_out.month < 10)
            // Format single digit with 0 as prefix
            os << "0" << date_out.month;
        else
            os << date_out.month;
    }

    // "mmm": each month with first three letters of its name
    else if (strcmp (date_out.getFormat ().get_monthFormat (), "mmm") == 0)
        os << month_name (date_out.month);

    // 0: each month in its full name
    else if (strcmp (date_out.getFormat ().get_monthFormat (), "0") == 0)
        os << month_name_full (date_out.month);

    // Output YEAR as per Date::format
    // "yy": year in last two digits
    if (strcmp (date_out.getFormat ().get_yearFormat (), "yy") == 0)
    {
        if (date_out.year % 100 < 10)
            // Format single digit with 0 as prefix
            os << "-" << "0" << (date_out.year % 100);
        else
            os << "-" << (date_out.year % 100);
    }

    // "yyyy": year in four digits
    else if (strcmp (date_out.getFormat ().get_yearFormat (), "yyyy") == 0)
        os << "-" << (date_out.year);

    return os;
}

/**
 * Date object input operator
 */
istream& operator>> (istream& is, Date& date_in)
{
    // Allocate tmp variables to check format
    string tmp_date, tmp_month, tmp_year;

    // Get input from input stream, using '-' as delimiter
    getline(is, tmp_date, '-');
    getline(is, tmp_month, '-');
    getline(is, tmp_year);

    // Check format for date from string against Date::format
    // is_input flag set to true
    if (check_dateFormat (tmp_date, date_in.getFormat ().get_dateFormat (), true) == true)
        date_in.date = stoi (tmp_date);
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Check format for month from string against Date::format
    // is_input flag set to true
    if (check_monthFormat (tmp_month, date_in.getFormat ().get_monthFormat (), true) == true)
        date_in.month = stoi (tmp_month);
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    // Check format for month from string against Date::format
    // is_input flag set to true
    if (check_yearFormat (tmp_year, date_in.getFormat ().get_yearFormat (), true) == true)
        date_in.year = stoi (tmp_year);
    else
        throw invalid_argument (create_message (__PRETTY_FUNCTION__, __LINE__, __FUNCTION__, "Invalid Argument"));

    return is;
}

// Format Functions to get/set Date Format

// Initialize static member format with default DateFormat
DateFormat Date::format;

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
DateFormat& Date::getFormat ()
{
    return format;
}
