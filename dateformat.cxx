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
#include <cstring>
#include <ctime>

#include "date.h"
#include "date_comp.h"

using namespace std;

/**
 * Format semantics for date, month, year formatter
 *
 * dateFormat:
 * 0: No date. This is valid for output only.
 * "d": single digit date in one digit, double digit date in two digits (7, 23)
 * "dd": all dates in two digits with single digit dates with leading 0 (07, 23)
 *
 * monthFormat:
 * 0: each month in its full name (February, November). This is valid for output only.
 * "m": single digit month in one digit, double digit month in two digits (2, 11)
 * "mm": all months in two digits with single digit months with leading 0 (02, 11)
 * "mmm": each month with first three letters of its name (Feb, Nov). This is valid for output only.
 *
 * yearFormat:
 * 0: No year. This is valid for output only.
 * "yy": year in last two digits (1961 as 61, 2016 as 16)
 * "yyyy": year in four digits (1961 as 1961, 2016 as 2016)
 */

/**
 * Constructor for DateFormat Class
 * Convert passed to dateFormat, monthFormat, yearFormat to accepted formatting
 */
DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat) 
{
    // Date, Month and Year string formatters
    formatter_date (dateFormat, DateFormat::dateFormat);
    formatter_month (monthFormat, DateFormat::monthFormat);
    formatter_year (yearFormat, DateFormat::yearFormat);
}

/**
 * Single C-string format Constructor for DateFormat Class
 * dateFormat, monthFormat, and yearFormat separated by ’-’
 * "dd-mmm-yy", "d-mm-yyyy", etc. formats
 */
DateFormat::DateFormat (const char* format)
{
    // Take '-' as delimiter to break string
    char* tmp_date = strtok (format,"-");
    char* tmp_month = strtok (NULL,"-");
    char* tmp_year = strtok (NULL,"-");

    // Date, Month and Year string formatters
    formatter_date (tmp_date, dateFormat);
    formatter_month (tmp_month, monthFormat);
    formatter_year (tmp_year, yearFormat);
}

/**
 * Default DateFormat created as "dd-mmm-yy"
 * Use current date from system
 */
DateFormat::DateFormat ()
{
    uint32_t date, month, year;

    // Allocate space for data members
    dateFormat = new char[3];
    monthFormat = new char[4];
    yearFormat = new char[3];

    // Get current date and time
    time_t current_time = time (0);
    struct tm* now = localtime (&current_time);

    // Assign date values - d, m, y
    date = now -> tm_mday;
    month = now -> tm_mon + 1;
    year = now -> tm_year + 1900;

    // Format date field
    if (date < 10)
    {
        // Formator to 2 digits 0d form
        strcat (dateFormat, "0");
        strcat (dateFormat, to_string (date));
    }
    else
        // Copy 2 digit date, as-is
        strcat (dateFormat, to_string (date));

    // Format month field
    strcat (monthFormat, month_name (month));

    // Format year field
    strcat (yearFormat, to_string (year % 100));
}

/**
 * Destructor for the DateFormat class
 */
DateFormat::~DateFormat ()
{
    delete[] dateFormat;
    delete[] monthFormat;
    delete[] yearFormat;
}
