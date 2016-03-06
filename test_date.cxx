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
	cout<<Date(D01,Jan,1950)<<"->"<<(WeekNumber) Date(D01,Jan,1950)<< endl;
         cout<<Date(D01,Jan,1968)<<"->"<<(WeekNumber) Date(D01,Jan,1968)<< endl;
         cout<<Date(D31,Dec,1983)<<"->"<<(WeekNumber) Date(D31,Dec,1983)<< endl;
         cout<<Date(D02,Jan,1990)<<"->"<<(WeekNumber) Date(D02,Jan,1990)<< endl;
         cout<<Date(D30,Dec,1999)<<"->"<<(WeekNumber) Date(D30,Dec,1999)<< endl;
         cout<<Date(D19,May,2000)<<"->"<<(WeekNumber) Date(D19,May,2000)<< endl;
         cout<<Date(D03,Jan,2007)<<"->"<<(WeekNumber) Date(D03,Jan,2007)<< endl;
         cout<<Date(D25,May,2014)<<"->"<<(WeekNumber) Date(D25,May,2014)<< endl;
         cout<<Date(D01,Jan,2020)<<"->"<<(WeekNumber) Date(D01,Jan,2020)<< endl;
         cout<<Date(D29,Dec,2030)<<"->"<<(WeekNumber) Date(D29,Dec,2030)<< endl;
         cout<<Date(D05,Jan,2038)<<"->"<<(WeekNumber) Date(D05,Jan,2038)<< endl;
         cout<<Date(D29,Dec,2049)<<"->"<<(WeekNumber) Date(D29,Dec,2049)<< endl;
    return 0;
}
