/**
 * Contains Main function
 * Tests Date, DateFormat Classes and functionalities
 * Unit tests for all functions/operators/Constructors
 *
 * Copyright (C)   2016    Madhav Datt
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "date-lib/date.h"

/**
 * Test DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)
 */
void DateFormat_Constructor1 ()
{
	cout << "Testing DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)\n\n";

	// Input arrays
	const char* date[] = {"0", "d", "dd", NULL, "ddd", "de"};
	const char* month[] = {"0", "m", "mm", "mmm", NULL, "mt", "mtm"};
	const char* year[] = {"0", "yy", "yyyy", NULL, "ye", "yeay"};

	cout << "All accepted formats for the Constructor:\n\n";

	// Iterate over all acceptable input formats and create DateFormat Object
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
			{
				try
				{
					DateFormat format_test (date[i], month[j], year[k]);
					cout << "***** DateFormat object constructed: " << date[i] << " " << month[j] << " " << year[k] << "\n";
				}
				catch (invalid_argument e)
				{
					cout << e.what () << " with inputs " << date[i] << " " << month[j] << " " << year[k] << "\n";
				}
				catch (domain_error e)
				{
					cout << e.what () << " with inputs " << date[i] << " " << month[j] << " " << year[k] << "\n";
				}
				catch (out_of_range e)
				{
					cout << e.what () << " with inputs " << date[i] << " " << month[j] << " " << year[k] << "\n";
				}
			}

	cout << "\n";

	// Iterate over all non-acceptable input formats and throw exceptions
	for (int i = 3; i < 6; i++)
		for (int j = 4; j < 7; j++)
			for (int k = 3; k < 6; k++)
			{
				try
				{
					DateFormat format_test (date[i], month[j], year[k]);
					cout << "***** DateFormat object constructed: " << ((date[i] != NULL) ? date[i] : "NULL") << " "
					<< ((month[j] != NULL) ? month[j] : "NULL") << " " << ((year[k] != NULL) ? year[k] : "NULL") << "\n";
				}
				catch (invalid_argument e)
				{
					cout << e.what () << " with inputs " << ((date[i] != NULL) ? date[i] : "NULL") << " "
					<< ((month[j] != NULL) ? month[j] : "NULL") << " " << ((year[k] != NULL) ? year[k] : "NULL") << "\n";
				}
				catch (domain_error e)
				{
					cout << e.what () << " with inputs " << ((date[i] != NULL) ? date[i] : "NULL") << " "
					<< ((month[j] != NULL) ? month[j] : "NULL") << " " << ((year[k] != NULL) ? year[k] : "NULL") << "\n";
				}
				catch (out_of_range e)
				{
					cout << e.what () << " with inputs " << ((date[i] != NULL) ? date[i] : "NULL") << " "
					<< ((month[j] != NULL) ? month[j] : "NULL") << " " << ((year[k] != NULL) ? year[k] : "NULL") << "\n";
				}
			}

	cout << "\n\n";
}

/**
 * Test DateFormat::DateFormat (const char* format)
 */
void DateFormat_Constructor2 ()
{
	cout << "Testing DateFormat::DateFormat (const char* format)\n\n";

	// Input Arrays
	const char* date[] = {"0-", "d-", "dd-", "-", "d", "ded-", "de"};
	const char* month[] = {"0-", "m-", "mm-", "mmm-", "-", "me-", "--"};
	const char* year[] = {"0", "yy", "yyyy", "-", "-yy", "ye", "yeay"};

	// String to hold concatenation of various input types
	char* format_string = new char[15];

	// Iterate over all acceptable input formats and create DateFormat Object
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
			{
				try
				{
					// Concatenate input array values to get format
					strcpy (format_string, date[i]);
					strcat (format_string, month[i]);
					strcat (format_string, year[i]);

					DateFormat format_test (format_string);
					cout << "***** DateFormat object constructed: " << date[i] << month[j] << year[k] << "\n";
				}
				catch (invalid_argument e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
				catch (domain_error e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
				catch (out_of_range e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
			}

	cout << "\n";

	// Iterate over all non-acceptable input formats and throw exceptions
	for (int i = 3; i < 7; i++)
		for (int j = 4; j < 7; j++)
			for (int k = 3; k < 7; k++)
			{
				try
				{
					// Concatenate input array values to get format
					strcpy (format_string, date[i]);
					strcat (format_string, month[i]);
					strcat (format_string, year[i]);

					DateFormat format_test (format_string);
					cout << "***** DateFormat object constructed: " << date[i] << month[j] << year[k] << "\n";
				}
				catch (invalid_argument e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
				catch (domain_error e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
				catch (out_of_range e)
				{
					cout << e.what () << " with inputs " << date[i] << month[j] << year[k] << "\n";
				}
			}

	cout << "\n\n";
	delete[] format_string;
}

/**
 * Test DateFormat::DateFormat ()
 * Default Constructor
 */
void DateFormat_Constructor3 ()
{
	cout << "Testing DateFormat::DateFormat ()\n\n";
	DateFormat format_test;
	cout << "***** Default DateFormat Constructed " << format_test.get_dateFormat () << " " << format_test.get_monthFormat () << " " << format_test.get_yearFormat ();
	cout << "\n\n";
}

/**
 * Test Date::Date (Day d, Month m, Year y)
 */
void Date_Constructor1 ()
{
	cout << "Testing Date::Date (Day d, Month m, Year y)\n\n";

	// Input arrays
	int date[] = {1, 12, 28, 29, 30, 31, 0};
	int month[] = {1, 3, 8, 12, 2, 0};
	int year[] = {1950, 2000, 2010, 2049, 1949, 2050};

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Iterate over all acceptable/mon-acceptable dates and create Date Object/throw exceptions
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++)
			{
				try
				{
					Date test_date (static_cast<Day> (date[i]), static_cast<Month> (month[j]), year[k]);
					cout << "***** Date object constructed: " << test_date << "\n";
				}
				catch (invalid_argument e)
				{
					cout << e.what () << " with inputs " << date[i] << "-" << month[j] << "-" << year[k] << "\n";
				}
				catch (domain_error e)
				{
					cout << e.what () << " with inputs " << date[i] << "-" << month[j] << "-" << year[k] << "\n";
				}
				catch (out_of_range e)
				{
					cout << e.what () << " with inputs " << date[i] << "-" << month[j] << "-" << year[k] << "\n";
				}
			}

	cout << "\n\n";
}

/**
 * Test Date::Date (const char* date)
 */
void Date_Constructor2 ()
{
	cout << "Testing Date::Date (const char* date)\n\n";

	// Array of formats
	DateFormat formatter[] = {DateFormat ("dd", "m", "yy"), DateFormat("d", "mm", "yy"), DateFormat("d", "m", "yyyy"), DateFormat ("dd", "0", "yyyy")};

	// String to hold concatenation of various input types
	const char* format_string[] = {"1-01-19", "01-1-19", "01-01-19", "20-11-2050", "20-0-2010"};

	// Create Date object with multiple DateFormat formats and throw exceptions
	for (int k = 0; k < 4; k++)
		for (int i = 0; i < 5; i++)
		{
			try
			{
				Date::setFormat (formatter[k]);
				Date test_date (format_string[i]);
				cout << "***** Date object constructed: " << test_date << "\n";
			}
			catch (invalid_argument e)
			{
				cout << e.what () << " with inputs " << format_string[i] << "\n";
			}
			catch (domain_error e)
			{
				cout << e.what () << " with inputs " << format_string[i] << "\n";
			}
			catch (out_of_range e)
			{
				cout << e.what () << " with inputs " << format_string[i] << "\n";
			}
		}

	cout << "\n\n";
}

/**
 * Test Date::Date ()
 * Default Constructor
 */
void Date_Constructor3 ()
{
	cout << "Testing Date::Date ()\n\n";

	DateFormat form;
	Date::setFormat (form);
	Date date_test;

	cout << "***** Default Date (Today's) Constructed " << date_test;
	cout << "\n\n";
}

/**
 * Test Date::Date (const Date&)
 * Copy Constructor
 */
void Date_Constructor4 ()
{
	cout << "Testing Date::Date (const Date&)\n\n";

	DateFormat form;
	Date::setFormat (form);

	Date date_orig (D21, Mar, 1998);
	Date date_copy (date_orig);

	cout << "***** Copy Date (Copy of 21-Mar-1998) Constructed " << date_copy;
	cout << "\n\n";
}

/**
 * Test Date& operator= (const Date&)
 */
void Date_operator1 ()
{
	cout << "Testing Date& operator= (const Date&)\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	Date date_orig (D21, Mar, 1998);
	Date date_copy;
	date_copy = date_orig;

	cout << "date_orig = " << date_orig
	<< "\ndate_copy = date_orig"
	<< "\ndate_copy = " << date_copy;
	cout << "\n\n";
}

/**
 * Test Date& operator++ ()
 */
void Date_operator2 ()
{
	cout << "Testing Date& operator++ ()\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D31, Dec, 2004), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 6; i++)
	{
		try
		{
			cout << "++ (" << datelist[i] << ") = ";
			++datelist[i];
			cout << datelist[i] << "\n";
		}
		catch (invalid_argument e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (domain_error e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (out_of_range e)
		{
			cout << "\n" << e.what () <<"\n";
		}
	}

	cout << "\n\n";
}

/**
 * Test Date& operator++ (int)
 */
void Date_operator3 ()
{
	cout << "Testing Date& operator++ (int)\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D31, Dec, 2004), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 6; i++)
	{
		try
		{
			cout << "(" << datelist[i] << ") ++ = ";
			datelist[i]++;
			cout << datelist[i] << "\n";
		}
		catch (invalid_argument e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (domain_error e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (out_of_range e)
		{
			cout << "\n" << e.what () <<"\n";
		}
	}

	cout << "\n\n";
}

/**
 * Test Date& operator-- ()
 */
void Date_operator4 ()
{
	cout << "Testing Date& operator-- ()\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D31, Dec, 2004), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 6; i++)
	{
		cout << "-- (" << datelist[i] << ") = ";
		try
		{
			--datelist[i];
			cout << datelist[i] << "\n";
		}
		catch (invalid_argument e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (domain_error e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (out_of_range e)
		{
			cout << "\n" << e.what () <<"\n";
		}
	}

	cout << "\n\n";
}

/**
 * Test Date& operator-- (int)
 */
void Date_operator5 ()
{
	cout << "Testing Date& operator-- (int)\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D31, Dec, 2004), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 6; i++)
	{
		cout << "(" << datelist[i] << ") -- = ";
		try
		{
			datelist[i]--;
			cout << datelist[i] << "\n";
		}
		catch (invalid_argument e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (domain_error e)
		{
			cout << "\n" << e.what () <<"\n";
		}
		catch (out_of_range e)
		{
			cout << "\n" << e.what () <<"\n";
		}
	}

	cout << "\n\n";
}

/**
 * Test operator WeekNumber () const
 * Test operator Month () const
 * Test operator WeekDay () const
 */
void Date_cast ()
{
	cout << "Testing casting operators\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D22, Jun, 2014), Date (D31, Dec, 2004), Date (D03, Sep, 2007), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 8; i++)
		cout << datelist[i] << ": WeekNumber: " << static_cast<WeekNumber> (datelist[i]) << " WeekDay: " << static_cast<WeekDay> (datelist[i]) << " Month: " << static_cast<Month> (datelist[i]) << "\n";

	cout << "\n\n";
}

/**
 * Test bool leapYear () const
 */
void Date_leap ()
{
	cout << "Testing bool leapYear () const\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date datelist[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D28, Feb, 1998), Date (D31, Dec, 2004), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};

	for (int i = 0; i < 6; i++)
	{
		if (datelist[i].leapYear ())
			cout << datelist[i] << " is a leap year\n";
		else
			cout << datelist[i] << " is not a leap year\n";
	}

	cout << "\n\n";
}

/**
 * Test bool operator== (const Date& otherDate)
 * Test bool operator!= (const Date& otherDate)
 * Test bool operator< (const Date& otherDate)
 * Test bool operator<= (const Date& otherDate)
 * Test bool operator> (const Date& otherDate)
 * Test bool operator>= (const Date& otherDate)
 */
void Date_bin_logic ()
{
	cout << "Testing Binary Logical Operators ==, !=, <, <=, >, >=\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input arrays
	Date datelist1[] = {Date (D22, Jun, 2014), Date (D03, Sep, 2007), Date (D27, Mar, 2015), Date (D19, Oct, 2004)};
	Date datelist2[] = {Date (D31, Dec, 2049), Date (D01, Jan, 1950), Date (D03, Sep, 2007)};

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			// Check for each logical operator
			if (datelist1[i] == datelist2[j])
				cout << datelist1[i] << " == " << datelist2[j] << "\n";
			if (datelist1[i] != datelist2[j])
				cout << datelist1[i] << " != " << datelist2[j] << "\n";
			if (datelist1[i] < datelist2[j])
				cout << datelist1[i] << " <  " << datelist2[j] << "\n";
			if (datelist1[i] <= datelist2[j])
				cout << datelist1[i] << " <= " << datelist2[j] << "\n";
			if (datelist1[i] > datelist2[j])
				cout << datelist1[i] << " >  " << datelist2[j] << "\n";
			if (datelist1[i] >= datelist2[j])
				cout << datelist1[i] << " >= " << datelist2[j] << "\n";
		}

	cout << "\n\n";
}

/**
 * Test unsigned int operator- (const Date& otherDate)
 * Test Date operator+ (int noOfDays)
 */
void Date_bin_arth ()
{
	cout << "Testing Binary Arithmetic Operators +, -\n\n";

	DateFormat form ("dd-mm-yyyy");
	Date::setFormat (form);

	// Input array
	Date end (D31, Dec, 2049);
	Date first (D22, Jun, 2014);
	Date second (D22, Jul, 2014);

	cout << second << " - " << first << " = " << second - first << "\n";
	cout << first << " - " << second << " = " << first - second << "\n\n";

	int num_days = second - first;
	cout << first << " + " << num_days << " = " << first + num_days;

	cout << "\n" << end << " + " << " 5 = ";
	try
	{
		cout << end + 5;
	}
	catch (invalid_argument e)
	{
		cout << "\n" << e.what () <<"\n";
	}
	catch (domain_error e)
	{
		cout << "\n" << e.what () <<"\n";
	}
	catch (out_of_range e)
	{
		cout << "\n" << e.what () <<"\n";
	}

	cout << "\n\n";
}

/**
 * Calling unit test functions
 */
void TestDate ()
{
	// DateFormat Constructors
	DateFormat_Constructor1 ();
	DateFormat_Constructor2 ();
	DateFormat_Constructor3 ();

	// Date Constructors
	Date_Constructor1 ();
	Date_Constructor2 ();
	Date_Constructor3 ();
	Date_Constructor4 ();

	// Copy assignment Operator
	Date_operator1 ();

	// Unary Arithmetic Operators
	Date_operator2 ();
	Date_operator3 ();
	Date_operator4 ();
	Date_operator5 ();

	// Date Binary Arithmetic Operators
	Date_bin_arth ();

	// Date Casting Operators
	Date_cast ();

	// Date leap year check
	Date_leap ();

	// Binary Logical Operators
	Date_bin_logic ();
}

int main (void)
{
	// Test Date Class and Functionalities
	TestDate ();

	// Other tested functionalities
	cout << "Other Functionalities Tested through Test DateFormat::DateFormat ():\n"
	<< "\tchar* DateFormat::get_dateFormat () const;\n"
	<< "\tchar* DateFormat::get_monthFormat () const;\n"
	<< "\tchar* DateFormat::get_yearFormat () const;\n\n";

	cout << "Other Functionalities Tested through Date Constructor Tests:\n"
	<< "\tostream& operator<< (ostream&, const Date&);\n"
	<< "\tstatic void setFormat (DateFormat&);\n"
	<< "\tstatic DateFormat& getFormat ();\n\n";

    return 0;
}
