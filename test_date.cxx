/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains Main function
 * Tests Date, DateFormat Classes and functionalities
 * Unit tests for all functions/operators/Constructors
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "date.h"

/**
 * Test DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)
 */
void DateFormat_Constructor1 ()
{
	cout << "Testing DateFormat::DateFormat (const char* dateFormat, const char* monthFormat, const char* yearFormat)" << "\n\n";

	// Input arrays
	const char* date[] = {"0", "d", "dd", NULL, "ddd", "de"};
	const char* month[] = {"0", "m", "mm", "mmm", NULL, "mt", "mtm"};
	const char* year[] = {"0", "yy", "yyyy", NULL, "ye", "yeay"};

	cout << "All accepted formats for the Constructor:\n\n";

	// Iterate over all accpetable input formats and create DateFormat Object
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
			{
				try
				{
					DateFormat format_test (date[i], month[j], year[k]);
					cout << "DateFormat object constructed: " << date[i] << " " << month[j] << " " << year[k] << "\n";
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

	// Iterate over all non-accpetable input formats and throw exceptions
	for (int i = 3; i < 6; i++)
		for (int j = 4; j < 7; j++)
			for (int k = 3; k < 6; k++)
			{
				try
				{
					DateFormat format_test (date[i], month[j], year[k]);
					cout << "DateFormat object constructed: " << ((date[i] != NULL) ? date[i] : "NULL") << " "
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
					cout << e.what () << " with inputs " << << ((date[i] != NULL) ? date[i] : "NULL") << " "
					<< ((month[j] != NULL) ? month[j] : "NULL") << " " << ((year[k] != NULL) ? year[k] : "NULL") << "\n";
				}
			}

	cout << "\n\n";
}

int main (void)
{
	// Calling unit test functions
	DateFormat_Constructor1 ();
    return 0;
}
