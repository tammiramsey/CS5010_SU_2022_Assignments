//main 
#include"clock.h"
#include <string>
#include <iostream>

using namespace std;
int main() {
    Clock Clock1("Clock 1", 1, 59, 88);
	Clock Clock2 ("Clock 2");
	Clock Clock3("Clock 3", 1, 12);
	Clock Clock4("Clock 4", 24);
	Clock Clock5("Clock 5", 5, 45, 45);
	Clock Clock6("Clock 6", 5, 45, 45);

	cout << "\n Initial Settings Of All Clocks" << endl;

	Clock1.Print();
	Clock2.Print();
	Clock3.Print();
	Clock4.Print();
	Clock5.Print();
	Clock6.Print();

	cout << "\n ++++++++++ Adding and Subracting Section ++++++++++" << endl;

	cout << "Adding 300 minutes to Clock 3 expecting X \n", Clock3.addMinutes(3500);
	cout << "\nAdding 10000 seconds to Clock 2 expecting 2 hours 46 minutes 40 seconds \n", Clock2.addSeconds(50000);
	cout << "\nAdding 23 hours to Clock 1 expecting 1 day 1 hour 0 minutes 28 seconds \n", Clock1.addHours(13);
	cout << "\nSubtracting 5 hours from Clock 4 expecting 19 hours 0 minutes 0 seconds \n", Clock4.subtractHours(8);
	cout << "\nSubtracting 17 minutes from Clock 1 expecting 14 hours 42 minutes 28 seconds \n", Clock1.subtractMinutes(5);
	cout << "\nSubtracting 27 seconds from Clock 5 expecting 5 hours 45 minutes 18 seconds \n", Clock2.subtractSeconds(77);

	cout << "\n\n Time Format Printing Test" << endl;
	cout << "\nPrinting Time expecting 24 hour format \n" , Clock1.PrintTime(false);
	cout << "\nPrinting Time expecting AM/PM format \n", Clock1.PrintTime(true);
	cout << "\nPrinting Time expecting 24hr format \n" , Clock2.PrintTime(false);
	cout << "\nPrinting Time expecting AM/PM format  \n", Clock2.PrintTime(true); 
	cout << "\nPrinting Time expecting 24hr format  \n" , Clock3.PrintTime(false);
	cout << "\nPrinting Time expecting AM/PM format \n", Clock3.PrintTime(true);
	cout << "\nPrinting Time expecting 24hr format \n" , Clock4.PrintTime(false);
	cout << "\nPrinting Time expecting AM/PM format \n", Clock4.PrintTime(true);
	
	cout << "\n\n Comparisons between clocks" << endl;
	
	Clock5.Print(), Clock6.Print();
	if (Clock5 == Clock6) {
		cout << "These Clocks are the SAME \n" << endl;
	}
	else {
		cout << "ALERT" << endl;
	}
	Clock2.Print(), Clock3.Print();
	if (Clock2 != Clock3) {
		cout << "These clocks are NOT the same \n" << endl;
	}
	else {
		cout << "ALERT" << endl;
	}
	Clock2.Print(), Clock1.Print();
	if (Clock2 < Clock1) {
		cout << "Clock 2 is less than Clock 1 \n" << endl;
	}
	else {
		cout << "ALERT" << endl;
	}	
	if (Clock5 < Clock6) {
		cout << "This error message means something is incorrect";
	}
	else {
		cout << "If you see this message, everything is running as anticiapted\n" << endl;
	}
	Clock6.addSeconds(1), Clock5.Print();
	if (Clock6 >= Clock5) {
		cout << "Clock6 is greater than or equal to Clock 5\n" << endl;
	}
	else {
		cout << "ALERT" << endl;
	}






  return 0;

}