/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains implementation of the Date Computations Header File
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>

#include "date.h"

/**
 * Check validity of (d, m, y) as a triplet
 */
bool is_valid_Date (uint32_t date, uint32_t month, uint32_t year);

/**
 * Check if d or m take invalid values
 */
bool is_valid_Arg (uint32_t date, uint32_t month);

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
    static const uint32_t month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint32_t month_length = month_days[month];

    // Leap year and month is February then length = 29
    if (is_leap_Year (year) && month == 2)
        month_length = 29;

    return month_length;
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
