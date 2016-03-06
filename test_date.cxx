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

void testCastOperators(Date & d1){
	cout<<"Testing Cast Operators true statements will be printed"<<endl<<endl;
	cout<<d1<<" as WeekNumber is "<<static_cast<WeekNumber>(d1)<<endl;
	cout<<d1<<" as Month is "<<static_cast<Month>(d1)<<endl;
	cout<<d1<<" as WeekDay is "<<static_cast<WeekDay>(d1)<<endl;
	cout<<endl;
}
void testRelationalOperators(Date & d1 , Date & d2){
	cout<<"Checking Relational Operators All The True Statements will be printed"<<endl<<endl;
	if(d1==d2){
		cout<<d1<<" is == to "<<d2<<endl;
	}
	if(d1!=d2){
		cout<<d1<<" is != to "<<d2<<endl;
	}
	if(d1<d2){
		cout<<d1<<" is < than "<<d2<<endl;
	}
	if(d1<=d2){
		cout<<d1<<" is <= than "<<d2<<endl;
	}
	if(d1>d2){
		cout<<d1<<" is > than "<<d2<<endl;
	}
	if(d1>=d2){
		cout<<d1<<" is >= than "<<d2<<endl;
	}
	cout<<endl;
}
void testSetAndGetFormat(){
	cout<<"Checking Set And Get Format All The True Statements will be printed"<<endl<<endl;
	DateFormat f;
	Date::setFormat(f);
	Date d;

	cout<<"Initially the default format dd-mmm-yy is set  using setFormat"<<endl;
	cout<<"The output in this format is "<<d<<endl;

	DateFormat f2("dd-mm-yyyy");
	Date::getFormat()=f2;
	cout<<"Using getFormat to get the format and changed the format to dd-mm-yyyy - as refrence is returned"<<endl;
	cout<<"The output in this format is "<<d<<endl;

	cout<<"Set and Get Format Are Working Correctly"<<endl<<endl;

}

int main (void)
{
	DateFormat f("dd-mm-yyyy");
	Date::setFormat(f);
	Date a ("31-12-1952");
	Date b;

testCastOperators (a);
testCastOperators (b);

    return 0;
}
