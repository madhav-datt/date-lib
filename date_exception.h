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
    Exception (char *file, unsigned int line);
    friend ostream& operator<<(ostream& os, const Exception& e);

private:
    char *fileName;
    unsigned int lineNo;
};

class invalid_argument : public Exception
{
public:
    friend ostream& operator<< (ostream& os, const invalid_argument& e);

private:

};

class domain_error : public Exception
{
public:
    friend ostream& operator<< (ostream& os, const domain_error& e);

private:

};

class out_of_range : public Exception
{
public:
    friend ostream& operator<< (ostream& os, const out_of_range& e);

private:

};

class format_error : public Exception
{
public:
    friend ostream& operator<< (ostream& os, const format_error& e);

private:

};

class Exception
{
    char *fileName; unsigned int lineNo; public: virtual ~Exception() = 0 {}
    Exception(char *file, unsigned int line) : fileName(file), lineNo(line) {}
    friend ostream& operator<<(ostream& os, const Exception& e) { os << "File = ";
    printf("%s. ", e.fileName); os << "Line = " << e.lineNo << endl; return os; }
};

class BinaryOpException : public Exception
{
    const Byte& arg1, arg2; public:
    BinaryOpException(char *file, unsigned int line, const Byte& a1, const Byte& a2) :
    Exception(file, line), arg1(a1), arg2(a2) {}
    friend ostream& operator<<(ostream& os, const BinaryOpException& e);
};

class OverflowException : public BinaryOpException
{
    public:
    OverflowException(char *file, unsigned int line, const Byte& a1, const Byte& a2) :
    BinaryOpException(file, line, a1, a2) {}
    friend ostream& operator<<(ostream& os, const OverflowException& e) {
        os << "Overflow for: " << static_cast<const BinaryOpException&>(e); return os; }
};

#endif
