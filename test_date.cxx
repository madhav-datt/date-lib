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

void testDateConstructor(){

	// cout<<"Testing Date Format First Constructor(Day,Month,Year) true statements will be printed"<<endl<<endl;
	//
	// Day day[]={D01,D15,D28,D29,D30,D31};
	// Month month[]={Jan,Feb,Jul,Aug,Nov};
	// Year year[]={1949,1950,2000,2049,2050};
	//
	// for(int i=0;i<6;++i){
	// 	for(int j=0;j<5;++j){
	// 		for(int k=0;k<5;++k){
	// 			try{
	// 				Date d(day[i],month[j],year[k]);
	// 				cout<<"Date type constructed"<<" with day- "<<day[i]<<" month- "<<month[j]<<" year- "<<year[k]<<endl;
	// 			}
	// 			catch(invalid_argument e){
	// 				cout<<"***ERROR invalid_argument- "<<e.what()<<" with day- "<<day[i]<<" month- "<<month[j]<<" year- "<<year[k]<<endl;
	// 			}
	// 			catch(domain_error e){
	// 				cout<<"***ERROR domain_error- "<<e.what()<<" with day- "<<day[i]<<" month- "<<month[j]<<" year- "<<year[k]<<endl;
	// 			}
	// 			catch(out_of_range e){
	// 				cout<<"***ERROR out_of_range-"<<e.what()<<" with day- "<<day[i]<<" month- "<<month[j]<<" year- "<<year[k]<<endl;
	// 			}
	// 		}
	// 	}
	// }
	//
	// cout<<endl;
	cout<<"Testing Format not meant for input true statements will be printed"<<endl<<endl;
	DateFormat formats[]={DateFormat("dd-mm-yy")};//,DateFormat("0","mm","yy"),DateFormat("dd","0","yy"),DateFormat("dd","mmm","yy"),DateFormat("dd","mm","0")};
	for(int i=0;i<1;++i){
		Date::setFormat(formats[i]);
		try{

			Date d("12-03-99");
		}
		catch(invalid_argument e){
			cout<<"***ERROR invalid_argument- "<<e.what()<<endl;

		}
		catch(domain_error e){
			cout<<"***ERROR domain_error- "<<e.what()<<endl;
		}
		catch(out_of_range e){
			cout<<"***ERROR out_of_range- "<<e.what()<<endl;
		}
		catch(exception e){
			cout<<"***ERROR Unknow Exception"<<endl;
		}
		try{
			Date d("12-Jan-99");
		}
		catch(invalid_argument e){
			cout<<"***ERROR invalid_argument- "<<e.what()<<endl;

		}
		catch(domain_error e){
			cout<<"***ERROR domain_error- "<<e.what()<<endl;
		}
		catch(out_of_range e){
			cout<<"***ERROR out_of_range- "<<e.what()<<endl;
		}
		catch(exception e){
			cout<<"***ERROR Unknow Exception"<<endl;
		}
	}


	try{

			cout<<"up";
		}
		catch(invalid_argument e){
			cout<<"***ERROR invalid_argument- "<<e.what()<<endl;

		}
		catch(domain_error e){
			cout<<"***ERROR domain_error- "<<e.what()<<endl;
		}
		catch(out_of_range e){
			cout<<"***ERROR out_of_range- "<<e.what()<<endl;
		}
		catch(exception e){
			cout<<"***ERROR Unknow Exception"<<endl;
		}

	cout<<endl;

	DateFormat f("d-mm-yyyy");
	Date::setFormat(f);
	cout<<"Testing Date Format Second Constructor(const char *) with input format dd-mm-yyyy true statements will be printed"<<endl<<endl;
	string days[]={"1-","1","28-","29-","30-","31-","32-"};
	string months[]={"1-","2","01-","12-","13-"};
	string years[]={"1949","99","1950","2016","2049","2050"};
}

int main (void)
{
    //Date a (static_cast<Day> (2), static_cast<Month> (5),2007);
	DateFormat f("dd-mm-yy");
	Date::setFormat(f);
	//cout << Date::getFormat().get_dateFormat () << " " << Date::getFormat().get_monthFormat () << " " << Date::getFormat().get_yearFormat ();
	Date a ("03-04-13");
    cout << a << "\n\n";
    //testDateConstructor();
    return 0;
}
