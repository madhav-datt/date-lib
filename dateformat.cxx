/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains implementation of the DateFormat Class
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

typedef MAX_DATE_LENGTH 2
typedef MAX_MONTH_LENGTH 3
typedef MAX_YEAR_LENGTH 4

void formatter_date (const char* dateString, char* dateFormat)
{
    switch (strlen(dateString))
    {
        case 1:
            dateFormat = new char[2];
            strcpy (dateFormat, dateString);
            break;

        case 2:
            dateFormat = new char[2];
            strcpy (dateFormat, dateString);
            break;

        default:
            dateFormat = new char[2];
            strcpy (dateFormat, "0");
    };
}

void formatter_month (const char* dateString, char* dateFormat)
{
    if (strlen(dateString) == 1 || strlen(dateString) == 2)
        strcpy (dateFormat, dateString);
    else
        strcpy (dateFormat, "0");
}

void formatter_year (const char* dateString, char* dateFormat)
{
    if (strlen(dateString) == 1 || strlen(dateString) == 2)
        strcpy (dateFormat, dateString);
    else
        strcpy (dateFormat, "0");
}

// The parameters below takes designated values with the specified format semantics

// dateFormat:
// 0: No date. This is valid for output only.
// "d": single digit date in one digit, double digit date in two digits (7, 23)
// "dd": all dates in two digits with single digit dates with leading 0 (07, 23)
// monthFormat:
// 0: each month in its full name (February, November). This is valid for output only.
// "m": single digit month in one digit, double digit month in two digits (2, 11)
// "mm": all months in two digits with single digit months with leading 0 (02, 11)
// "mmm": each month with first three letters of its name (Feb, Nov). This is valid for output only.
// yearFormat:
// 0: No year. This is valid for output only.
// "yy": year in last two digits (1961 as 61, 2016 as 16)
// "yyyy": year in four digits (1961 as 1961, 2016 as 2016)
DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)
{
    DateFormat::dateFormat = new char[MAX_DATE_LENGTH];
    DateFormat::monthFormat = new char[MAX_MONTH_LENGTH];
    DateFormat::yearFormat = new char[MAX_YEAR_LENGTH];
}

// Single C-string format where dateFormat, monthFormat, and yearFormat are separated by ’-’
// Example: "dd-mmm-yy", "d-mm-yyyy", etc
DateFormat::DateFormat (const char* format)
{

}

// Default DateFormat created as "dd-mmm-yy"
DateFormat::DateFormat ()
{
    // Get current date and time
    time_t current_time = time (0);
    struct tm* now = localtime (&current_time);

    // Assign date values to class members
    date = now -> tm_mday;
    month = now -> tm_mon + 1;
    year = now -> tm_year + 1900;
}

// Destructor for the DateFormat class
DateFormat::~DateFormat ()
{

}
