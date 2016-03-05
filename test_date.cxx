/**
 * Madhav Datt - 14CS30015
 *
 * Software Engineering Lab - Assignment 3
 * Contains Main function
 * Tests Date, DateFormat Classes and functionalities
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "date.h"

int main (void)
{
    Date a (static_cast<Day> (2), static_cast<Month> (5),2007);
    cout << a << "\n";
    return 0;
}
