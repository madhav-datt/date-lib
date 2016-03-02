/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Implementation of custom defined exception classes for Date handling
 *
 */

 #include <iostream>
 #include <exception>
 #include <cstdio>
 #include <cstring>

 #include "date_exception.h"

 using namespace std;

// Implementation of Constructors

/**
 * Base Exception Class
 */
Exception::Exception (char* function, uint32_t line) :
function_name (function), line_num (line)
{
}

/**
 * Invalid argument exception class
 * One or more of the arguments d or m is/are invalid (27, 13, 13)
 */
invalid_argument::invalid_argument (char* function, uint32_t line, uint32_t date, uint32_t month) :
Exception (function, line), invalid_argument::date (date), invalid_argument::month (month)
{
}

/**
 * domain_error exception class
 * (d, m, y) as a triplet does not define a valid date (30, 2, 61)
 */
domain_error::domain_error (char* function, uint32_t line, uint32_t date, uint32_t month, uint32_t year) :
Exception (function, line), domain_error::date (date), domain_error::month (month), domain_error::year (year)
{
}

/**
 * out_of_range exception class
 * Date is out of range (4, 7, 2053)
 */
out_of_range::out_of_range (char* function, uint32_t line, uint32_t year) :
Exception (function, line), out_of_range::year (year)
{
}

/**
 * format_error exception class
 * Incorrect format input provided
 */
format_error::format_error (char* function, uint32_t line, char* format) :
Exception (function, line), format_error::format (format)
{
}

// Implementation of overloaded I/O Operators

/**
 * Output operator for Base Exception Class
 */
ostream& operator<< (ostream& os, const Exception& e)
{
    os << e.line_num << ": " << e.function_name << "\n";
    return os;
}

/**
 * Output operator for invalid_argument Exception Class
 */
ostream& operator<< (ostream& os, const invalid_argument& e)
{
    os << "Invalid Argument Exception:\n";
    os << "\t At: (date " << e.date << ", month " << e.month << ")\n";
    os << "\t" << static_cast<const Exception&> (e);
    return os;
}

/**
 * Output operator for domain_error Exception Class
 */
ostream& operator<< (ostream& os, const domain_error& e)
{
    os << "Domain Error (Invalid Date) Exception:\n";
    os << "\t At: (date " << e.date << ", month " << e.month << ", year " << e.year << ")\n";
    os << "\t" << static_cast<const Exception&> (e);
    return os;
}

/**
 * Output operator for out_of_range Exception Class
 */
ostream& operator<< (ostream& os, const out_of_range& e)
{
    os << "Invalid Argument Exception:\n";
    os << "\t At: (date " << e.date << ", month " << e.month << ")\n";
    os << "\t" << static_cast<const Exception&> (e);
    return os;
}
