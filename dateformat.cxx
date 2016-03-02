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
#include "date_exception.h"

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

using namespace std;

/**
 * Constructor for DateFormat Class
 * Convert passed to dateFormat, monthFormat, yearFormat to accepted formatting
 */
DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat) throw (format_error)
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
DateFormat::DateFormat (const char* format) throw (format_error)
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
    // Allocate space for data members
    dateFormat = new char[3];
    monthFormat = new char[4];
    yearFormat = new char[3];

    // Create format as dd-mmm-yy
    strcpy (dateFormat, "dd");
    strcpy (monthFormat, "mmm");
    strcpy (yearFormat, "yy");
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

// Getter functions for private format specifying members

/**
 * Get dateFormat for Date I/O
 */
char* DateFormat::get_dateFormat () const
{
    return dateFormat;
}

/**
 * Get monthFormat for Date I/O
 */
char* DateFormat::get_monthFormat () const
{
    return monthFormat;
}

/**
 * Get yearFormat for Date I/O
 */
char* DateFormat::get_yearFormat () const
{
    return yearFormat;
}
