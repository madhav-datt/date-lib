/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Custom defined exception classes for Date handling
 *
 */

#ifndef _DATE_EXCEPTION_H_
#define _DATE_EXCEPTION_H_

class Exception
{
public:
    Exception (char* function, uint32_t line);
    friend ostream& operator<<(ostream& os, const Exception& e);

private:
    char* function;
    uint32_t line_num;
};

class invalid_argument : public Exception
{
public:
    invalid_argument (char* function, uint32_t line, uint32_t date, uint32_t month);
    friend ostream& operator<< (ostream& os, const invalid_argument& e);

private:

};

class domain_error : public Exception
{
public:
    domain_error (char* function, uint32_t line, uint32_t date, uint32_t month, uint32_t year);
    friend ostream& operator<< (ostream& os, const domain_error& e);

private:

};

class out_of_range : public Exception
{
public:
    out_of_range (char* function, uint32_t line, uint32_t year);
    friend ostream& operator<< (ostream& os, const out_of_range& e);

private:

};

class format_error : public Exception
{
public:
    format_error (char* function, uint32_t line, char* format);
    friend ostream& operator<< (ostream& os, const format_error& e);

private:

};

#endif
