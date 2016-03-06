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

void testAddNumberOfDays(Date & d1, int days){
	cout<<"Testing Adding Number Of Days true statements will be printed"<<endl<<endl;
	cout<<d1<<" + "<<days<<" is "<<(d1+days);
	cout<<endl;
}
void testDifferenceOperator(Date & d1,Date & d2){
	cout<<"Testing Difference in days true statements will be printed"<<endl<<endl;
	cout<<d1<<" - "<<d2<<" is "<<(d1-d2);
	cout<<d2<<" - "<<d1<<" is "<<(d2-d1);
	cout<<endl;
}
void testLeapYear(Date & d1){
	cout<<"Testing LeapYear Function true statements will be printed"<<endl<<endl;
	if(d1.leapYear()){
		cout<<d1<<" is a leap year"<<endl;
	}else{
		cout<<d1<<" is not a leap year"<<endl;
	}
	cout<<endl;
}

int main (void)
{
    //Date a (static_cast<Day> (2), static_cast<Month> (5),2007);
	DateFormat f("dd-mm-yy");
	Date::setFormat(f);
	//cout << Date::getFormat().get_dateFormat () << " " << Date::getFormat().get_monthFormat () << " " << Date::getFormat().get_yearFormat ();
	Date a ("01-01-00");
	Date b;

	testAddNumberOfDays(b, -25);
	testDifferenceOperator(b, a);
	testLeapYear(a);

//Date(D01,Jan,1950);
//cout << Date(D01,Jan,1950);

	    //cout<<Date(D01,Jan,1950)<<"->"<<(WeekNumber) Date(D01,Jan,1950)<< endl;
//        cout<<Date("01-01-53")<<"->"<<(WeekNumber) Date("01-01-53")<< endl;
        //  cout<<Date(D31,Dec,1983)<<"->"<<(WeekNumber) Date(D31,Dec,1983)<< endl;
        //  cout<<Date(D02,Jan,1990)<<"->"<<(WeekNumber) Date(D02,Jan,1990)<< endl;
        //  cout<<Date(D30,Dec,1999)<<"->"<<(WeekNumber) Date(D30,Dec,1999)<< endl;
        //  cout<<Date(D19,May,2000)<<"->"<<(WeekNumber) Date(D19,May,2000)<< endl;
        //  cout<<Date(D03,Jan,2007)<<"->"<<(WeekNumber) Date(D03,Jan,2007)<< endl;
        //  cout<<Date(D25,May,2014)<<" -> "<<(WeekNumber) Date(D25,May,2014)<< endl;
        //  cout<<Date(D01,Jan,2020)<<"->"<<(WeekNumber) Date(D01,Jan,2020)<< endl;
        //  cout<<Date(D29,Dec,2030)<<"->"<<(WeekNumber) Date(D29,Dec,2030)<< endl;
        //  cout<<Date(D05,Jan,2038)<<"->"<<(WeekNumber) Date(D05,Jan,2038)<< endl;
        //  cout<<Date(D29,Dec,2049)<<"->"<<(WeekNumber) Date(D29,Dec,2049)<< endl;

//	cout << a.to_days() << "\n" << Date::to_Date (a.to_days());
//	++a;
//	cout << a << "\n";
//	--a;
	//cout << a << "\n";
	// cout << b << "\n";
	// b++;
	// cout << b << "\n";
	// b--;
	// cout << b << "\n";
	// ++b;
	// cout << b << "\n";
	// --b;
	// cout << b << "\n";
	//test (b);

//testCopyAssignment(b, a);
    //cout << a << "\n\n";
    //testDateConstructor();
    return 0;
}
