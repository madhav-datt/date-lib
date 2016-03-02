/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Custom defined exception classes for Date handling
 *
 */

#ifndef _DATE_EXCEPTION_H_
#define _DATE_EXCEPTION_H_

#include <iostream>
#include <exception>
#include <cstdio>
#include <cstring>

using namespace std;

/**
 * Base Exception Class
 */
class Exception
{
public:
    // Constructor for Exception
    Exception (char* function, uint32_t line);

    // I/O using friend overloaded operators
    friend ostream& operator<<(ostream& os, const Exception& e);

private:
    char* function_name; // Name of function for where exception is thrown
    uint32_t line_num; // Line number of exception thrown
};

/**
 * Invalid argument exception class
 * One or more of the arguments d or m is/are invalid (27, 13, 13)
 */
class invalid_argument : public Exception
{
public:
    // Constructor for invalid_argument exception
    invalid_argument (char* function, uint32_t line, uint32_t date, uint32_t month);

    // I/O using friend overloaded operators
    friend ostream& operator<< (ostream& os, const invalid_argument& e);

private:
    uint32_t date, month;
};

/**
 * domain_error exception class
 * (d, m, y) as a triplet does not define a valid date (30, 2, 61)
 */
class domain_error : public Exception
{
public:
    // Constructor for domain_error exception
    domain_error (char* function, uint32_t line, uint32_t date, uint32_t month, uint32_t year);

    // I/O using friend overloaded operators
    friend ostream& operator<< (ostream& os, const domain_error& e);

private:
    uint32_t date, month, year;
};

/**
 * out_of_range exception class
 * Date is out of range (4, 7, 2053)
 */
class out_of_range : public Exception
{
public:
    // Constructor for out_of_range exception
    out_of_range (char* function, uint32_t line, uint32_t year);

    // I/O using friend overloaded operators
    friend ostream& operator<< (ostream& os, const out_of_range& e);

private:
    uint32_t year;
};

/**
 * format_error exception class
 * Incorrect format input provided
 */
class format_error : public Exception
{
public:
    // Constructor for format_error exception
    format_error (char* function, uint32_t line, char* format);

    // I/O using friend overloaded operators
    friend ostream& operator<< (ostream& os, const format_error& e);

private:
    char* format;
};

#endif // _DATE_EXCEPTION_H_
