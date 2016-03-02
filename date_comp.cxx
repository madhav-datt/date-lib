/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains implementation of the Date Computations Functions
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <regex>
#include <exception>

#include "date_comp.h"
#include "date.h"
#include "date_exception.h"

/**
 * Check validity of (d, m, y) as a triplet
 */
bool is_valid_Date (uint32_t date, uint32_t month, uint32_t year)
{
    // Check validity of passed d and m values
    if (is_valid_Arg (date, month) == false)
        return false;

    // Check if date in month
    if (date > month_length (month, year))
        return false;

    return true;
}

/**
 * Check if d or m take invalid values
 */
bool is_valid_Arg (uint32_t date, uint32_t month)
{
    // date or month are out of bounds/take invalid values
    if (date > 31 || date < 1 || month > 12 || month < 1)
        return false;

    return true;
}

 /**
  * Check if y is a leap year
  */
bool is_leap_Year (uint32_t year)
{
    bool flag = false;

    // Leap year - divisible by 4 & if divisible by 100, then also by 400
    if (year % 100 == 0 && year % 400 == 0)
        flag = true;
    else if (year % 100 != 0 && year % 4 == 0)
        flag = true;

    return flag;
}

/**
 * Give length of month for given year
 * Consider leap years and February
 */
uint32_t month_length (uint32_t month, uint32_t year)
{
    // month_days[i] = number of days in ith month
    static const uint32_t month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint32_t month_length = month_days[month];

    // Leap year and month is February then length = 29
    if (is_leap_Year (year) && month == 2)
        month_length = 29;

    return month_length;
}

/**
 * Give three letter name of month
 */
char* month_name (uint32_t month)
{
    // month_days[i] = three letter name of ith month
    static const char month_name[][4] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return month[i];
}

/**
 * Give full name of month - "January" etc.
 */
char* month_name_full (uint32_t month)
{
    // month_days[i] = fulll name of ith month
    static const char month_name[][4] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month[i];
}

/**
 * Give number of weeks in year y
 * A week starts on Monday and ends on Sunday. Weeks are numbered in a year from 1 to 52/53.
 * Week 1 (W01) of a year starts contains the first Thursday of the year.
 */
int number_of_weeks (uint32_t year)
{
    // Last day of year (falls in last week)
    Date year_end (31, 12, year);

    // Find first Thursday of year
    Date year_start (1, 1, year);
    while ((WeekDay)year_start != 4)
        ++year_start;

    // Find start of Week 1 of year
    year_start = year_start + (-3);

    // Number of days between first week and end of year
    int num_days = year_end - year_start;

    // Return week number in which end of year falls
    return static_cast<int> (num_days / 7) + 1;
}

/**
 * Date formatter function
 * Accept date in specified format
 *
 * dateFormat:
 * 0: No date. This is valid for output only.
 * "d": single digit date in one digit, double digit date in two digits (7, 23)
 * "dd": all dates in two digits with single digit dates with leading 0 (07, 23)
 */
void formatter_date (const char* dateString, char* dateFormat) throw (format_error)
{
    // "d": single digit date in one digit, double digit date in two digits
    if (strcmp (dateString, "d") == 0)
        dateFormat = new char[2];

    // "dd": all dates in two digits with single digit dates with leading 0
    else if (strcmp (dateString, "dd") == 0)
        dateFormat = new char[3];

    // 0: No date
    else if (strcmp (dateString, "0") == 0)
        dateFormat = new char[2];

    // Incorrect format entered
    else
        throw format_error ();

    strcpy (dateFormat, dateString);
}

/**
 * Month formatter function
 * Accept month in specified format
 *
 * monthFormat:
 * 0: each month in its full name (February, November). This is valid for output only.
 * "m": single digit month in one digit, double digit month in two digits (2, 11)
 * "mm": all months in two digits with single digit months with leading 0 (02, 11)
 * "mmm": each month with first three letters of its name (Feb, Nov). This is valid for output only.
 */
void formatter_month (const char* dateString, char* monthFormat) throw (format_error)
{
    // "m": single digit month in one digit, double digit month in two digits
    if (strcmp (dateString, "m") == 0)
        monthFormat = new char[2];

    // "mm": all months in two digits with single digit months with leading 0
    else if (strcmp (dateString, "mm") == 0)
        monthFormat = new char[3];

    // "mmm": each month with first three letters of its name
    else if (strcmp (dateString, "mmm") == 0)
        monthFormat = new char[4];

    // 0: each month in its full name
    else if (strcmp (dateString, "0") == 0)
        monthFormat = new char[2];

    // Incorrect format entered
    else
        throw format_error ();

    strcpy (monthFormat, dateString);
}

/**
 * Year formatter function
 * Accept year in specified format
 *
 * yearFormat:
 * 0: No year. This is valid for output only.
 * "yy": year in last two digits (1961 as 61, 2016 as 16)
 * "yyyy": year in four digits (1961 as 1961, 2016 as 2016)
 */
void formatter_year (const char* dateString, char* yearFormat) throw (format_error)
{
    // "yy": year in last two digits
    if (strcmp (dateString, "yy") == 0)
        yearFormat = new char[3];

    // "yyyy": year in four digits
    else if (strcmp (dateString, "yyyy") == 0)
        yearFormat = new char[5];

    // 0: No year
    else if (strcmp (dateString, "0") == 0)
        yearFormat = new char[2];

    // Incorrect format entered
    else
        throw format_error ();

    strcpy (yearFormat, dateString);
}

/**
 * Check if passed dateString matches format value for field date
 */
bool check_dateFormat (char* dateString, const char* format, bool is_input)
{
    bool flag = false;

    // "d": single digit date in one digit, double digit date in two digits
    if (strcmp (format, "d") == 0)
        if (regex_match (dateString, regex ("[1-3]?[0-9]")) == true)
            flag = true;

    // "dd": all dates in two digits with single digit dates with leading 0
    else if (strcmp (format, "dd") == 0)
        if (regex_match (dateString, regex ("0[1-9]|[1-3][0-9]")) == true)
            flag = true;

    // 0: No date
    else if (strcmp (format, "0") == 0 && is_input == false)
        if (strcmp (dateString, "") == true)
            flag = true;

    return flag;
}

/**
 * Check if passed dateString matches format value for field month
 */
bool check_monthFormat (char* dateString, const char* format, bool is_input)
{
    bool flag = false;

    // "m": single digit month in one digit, double digit month in two digits
    if (strcmp (format, "m") == 0)
        if (regex_match (dateString, regex ("1?[0-9]")) == true)
            flag = true;

    // "mm": all months in two digits with single digit months with leading 0
    else if (strcmp (format, "mm") == 0)
        if (regex_match (dateString, regex ("0[1-9]|1[0-2]")) == true)
            flag = true;

    // "mmm": each month with first three letters of its name
    // 0: each month in its full name
    else if ((strcmp (format, "mmm") == 0 || strcmp (format, "0") == 0) && is_input == false)
    {
        for (int i = 1; i < 12; i++)
        {
            // Check match for names against each month for format
            if (strcmp (dateString, month_name (i)) == 0 || strcmp (dateString, month_name_full (i)) == 0)
            {
                flag = true;
                break
            }
        }
    }

    return flag;
}

/**
 * Check if passed dateString matches format value for field year
 */
bool check_yearFormat (char* dateString, const char* format, bool is_input)
{
    bool flag = false;

    // "yy": year in last two digits
    if (strcmp (format, "yy") == 0)
        if (regex_match (dateString, regex ("[0-9][0-9]")) == true)
            flag = true;

    // "yyyy": year in four digits
    else if (strcmp (format, "yyyy") == 0)
        if (regex_match (dateString, regex ("[1-2][09][0-9][0-9]")) == true)
            flag = true;

    // 0: No year
    else if (strcmp (format, "0") == 0 && is_input == false)
        if (strcmp (dateString, "") == true)
            flag = true;

    return flag;
}
