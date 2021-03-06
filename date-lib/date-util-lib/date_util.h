/**
 * Contains declarations of Date Computation Functions
 * Date Computations contains functions to help in various Date operations
 *
 * Copyright (C)   2016    Madhav Datt
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 */

#ifndef _DATE_UTIL_H_
#define _DATE_UTIL_H_

#include <cstdio>
#include <string>
#include <cstdint>

#include "../date.h"

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
bool is_leap_Year (uint32_t year);

/**
 * Give length of month for given year
 * Consider leap years and February
 */
uint32_t month_length (uint32_t month, uint32_t year);

/**
 * Give three letter name of month
 */
const char* month_name (uint32_t month);

/**
 * Give full name of month - "January" etc.
 */
const char* month_name_full (uint32_t month);

/**
 * Give number of weeks in year y
 * A week starts on Monday and ends on Sunday. Weeks are numbered in a year from 1 to 52/53.
 * Week 1 (W01) of a year starts contains the first Thursday of the year.
 */
int number_of_weeks (uint32_t year);

/**
 * Date formatter function
 * Accept date in specified format
 *
 * dateFormat:
 * 0: No date. This is valid for output only.
 * "d": single digit date in one digit, double digit date in two digits (7, 23)
 * "dd": all dates in two digits with single digit dates with leading 0 (07, 23)
 */
void formatter_date (const char* dateString, char** dateFormatter) throw (invalid_argument);

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
void formatter_month (const char* dateString, char** monthFormatter) throw (invalid_argument);

/**
 * Year formatter function
 * Accept year in specified format
 *
 * yearFormat:
 * 0: No year. This is valid for output only.
 * "yy": year in last two digits (1961 as 61, 2016 as 16)
 * "yyyy": year in four digits (1961 as 1961, 2016 as 2016)
 */
void formatter_year (const char* dateString, char** yearFormatter) throw (invalid_argument);

/**
 * Check if passed dateString matches format value for field date
 */
bool check_dateFormat (string dateString, const char* format, bool is_input = false);

/**
 * Check if passed dateString matches format value for field month
 */
bool check_monthFormat (string dateString, const char* format, bool is_input = false);

/**
 * Check if passed dateString matches format value for field year
 */
bool check_yearFormat (string dateString, const char* format, bool is_input = false);

/**
 * Generate error messages for exceptions thrown
 * Error message includes type of exception, throwing function and line
 */
const string create_message (const char* function, uint32_t line, const char* filename, string error_type);

#endif // _DATE_UTIL_H_
