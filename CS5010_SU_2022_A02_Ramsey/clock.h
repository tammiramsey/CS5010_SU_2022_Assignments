// CLOCK.H HEADER FILE
#ifndef clock_h
#define clock_h
#include <string>

using namespace std;

class Clock {
		
	public:
// Overloading operators
		bool operator==(const Clock& c1);
		bool operator!=(const Clock& c1);
		bool operator>(const Clock& c1);
		bool operator<(const Clock& c1);
		bool operator<=(const Clock& c1);
		bool operator>=(const Clock& c1);
		

//Constructors 
		Clock(string name, int hours, int minutes, int seconds);
		Clock(string name, int hours, int minutes);
		Clock(string name, int hours);
		Clock(string name);
		Clock();

//Minute and Second Overflow and Underflow Corrections
		void TimeSortUp();
		void TimeSortDown();
		
//Setter Getter Name & Print
		void SetName(string clockName);
		string GetName();
		void Print();

//Setter Getter Time
		void SetTime(int hoursIn, int minutesIn, int secondsIn);
        int GetHours();
        int GetMinutes();
        int GetSeconds();

//Basic Hours Math
		void addHours(int h);
		void subtractHours(int h);
//Basic Minutes Math
		void addMinutes(int m);
		void subtractMinutes(int m);
//Basic Seconds Math
		void addSeconds(int s);
		void subtractSeconds(int s);

//Boolean Print Choice
		void PrintTime(bool twelveHr);

//Print Choice Converter Functions
		void ConvertTwnFour();
		void ConvertTwelve();

//Comparison Overload
//        bool operator==(Clock& lhs, Clock& rhs);
	
	private:
		string clockName;
		int hours, minutes, seconds;
		int temp_hours, temp_minutes, temp_seconds;
		bool twelveHr;
		string AMPM;





};

#endif