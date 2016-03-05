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

void testDateFormatConstructor()
{
	cout<<"Testing Date Format First Constructor true statements will be printed"<<endl<<endl;
	const char*  day[]={"0","d","dd","abd","de"};
	const char*  month[]={"0","m","mm","mmm","ad","amm"};
	const char* year[]={"0","yy","yyyy","as","ayyy"};
	for(int i=0;i<5;++i){
		for(int j=0;j<6;++j){
			for(int k=0;k<5;++k){cout << day[i] << " " << month[j] << " " << year [k] << "\n";
				try{
					DateFormat f(day[i],month[j],year[k]);
					cout<<"DateFormat type constructed with type "<<((day[i]!=NULL)?day[i]:"NULL")<<" "<<((month[j]!=NULL)?month[j]:"NULL")<<" "<<((year[k]!=NULL)?year[k]:"NULL")<<endl;
				}
				catch(invalid_argument e){
					cout<<"***ERROR invalid_argument- "<<e.what()<<" with type "<<((day[i]!=NULL)?day[i]:"NULL")<<" "<<((month[j]!=NULL)?month[j]:"NULL")<<" "<<((year[k]!=NULL)?year[k]:"NULL")<<endl;
				}
				catch(domain_error e){
					cout<<"***ERROR domain_error- "<<e.what()<<" with type "<<((day[i]!=NULL)?day[i]:"NULL")<<" "<<((month[j]!=NULL)?month[j]:"NULL")<<" "<<((year[k]!=NULL)?year[k]:"NULL")<<endl;
				}
				catch(out_of_range e){
					cout<<"***ERROR out_of_range- "<<e.what()<<" with type "<<((day[i]!=NULL)?day[i]:"NULL")<<" "<<((month[j]!=NULL)?month[j]:"NULL")<<" "<<((year[k]!=NULL)?year[k]:"NULL")<<endl;
				}
			}
		}
	}
	cout<<endl;
	cout<<"Testing Date Format Second Constructor true statements will be printed"<<endl<<endl;
	string  days[]={"-","d-","dd-","d","abd-","de"};
	string  months[]={"-","m-","mm-","mmm-","ad-","--"};
	string years[]={"","yy","yyyy","as","ayyy"};

	for(int i=0;i<6;++i){
		for(int j=0;j<6;++j){
			for(int k=0;k<5;++k){
				try{
					DateFormat f((days[i]+months[j]+years[k]).c_str());
					cout<<"DateFormat type constructed with type "<<(days[i]+months[j]+years[k])<<endl;
				}
				catch(invalid_argument e){
					cout<<"***ERROR invalid_argument- "<<e.what()<<" with type "<<(days[i]+months[j]+years[k])<<endl;
				}
				catch(domain_error e){
					cout<<"***ERROR domain_error- "<<e.what()<<" with type "<<(days[i]+months[j]+years[k])<<endl;
				}
				catch(out_of_range e){
					cout<<"***ERROR out_of_range- "<<e.what()<<" with type "<<(days[i]+months[j]+years[k])<<endl;
				}
			}
		}
	}

	cout<<endl;
	cout<<"Testing Date Format Default Constructor true statements will be printed"<<endl<<endl;

	DateFormat f;
	cout<<"DateFormat default constructed"<<endl;
	cout<<endl;
}

int main (void)
{
    Date a (static_cast<Day> (2), static_cast<Month> (5),2007);
    cout << a << "\n\n";
    const char* day = "0";
    const char* month = "0";
    const char* year = "0";
    DateFormat f(day,month,year);
//    DateFormat f(day,month,year);
    //testDateFormatConstructor();
    return 0;
}
