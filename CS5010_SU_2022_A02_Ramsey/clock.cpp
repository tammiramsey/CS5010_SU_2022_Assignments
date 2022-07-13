// CLOCK CPP FILE
#include <iostream>
#include <string>
#include "clock.h"
using namespace std;


/*
<<<<<<<<<<<<< CONSTRUCTOR SECTION >>>>>>>>>>>>>
*/
// Default Constructor
Clock::Clock() {
  clockName = "NoName";
  hours = 0;
  minutes = 0;
  seconds = 0;
  TimeSortUp();
  TimeSortDown();
}
// Constructor will all inputs
Clock::Clock(string name, int hours, int minutes, int seconds) {
  this->clockName = name;
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
  TimeSortUp();
  TimeSortDown();
}
// Constructor without seconds
Clock::Clock(string name, int hours, int minutes) {
  this->clockName = name;
  this->hours = hours;
  this->minutes = minutes;
  seconds = 0;
  TimeSortUp();
  TimeSortDown();
}
// Constructor without seconds and minutes
Clock::Clock(string name, int hours) {
  this->clockName = name;
  this->hours = hours;
  minutes = 0;
  seconds = 0;
  TimeSortUp();
  TimeSortDown();
}
// Constructor with name only
Clock::Clock(string clockName) {
  this->clockName = clockName;
  hours = 0;
  minutes = 0;
  seconds = 0;
  TimeSortUp();
  TimeSortDown();
}
/*  >>>>>>>>>> END CONSTRUCTOR SECTION <<<<<<<<<<  */
//
void Clock::SetTime(int hoursIn, int minutesIn, int secondsIn) {
  hours = hoursIn;
  minutes = minutesIn;
  seconds = secondsIn;
  if ((minutes < 0) || (seconds < 0)) {
    TimeSortDown();
  } else {
    TimeSortUp();
  }
}
int Clock::GetHours() {
	return hours;
}
int Clock::GetMinutes() {
	return minutes;
}
int Clock::GetSeconds() {
	return seconds;
}

/*  ++++||++++ Overflow and Underflow Correction ++++||++++  */

// overflow (more than 60 seconds or minutes)
void Clock::TimeSortUp() {
  temp_hours = hours;
  temp_minutes = minutes;
  temp_seconds = seconds;

  while (temp_seconds > 59) {
    temp_minutes = temp_minutes + 1;
    temp_seconds = temp_seconds - 60;
  }
  while (temp_minutes > 59) {
    temp_hours = temp_hours + 1;
    temp_minutes = temp_minutes - 60;		
  }
  hours = temp_hours;
  minutes = temp_minutes;
  seconds = temp_seconds;
}

// underflow (less than zero seconds or minutes)
void Clock::TimeSortDown() {
  temp_hours = hours;
  temp_minutes = minutes;
  temp_seconds = seconds;
  while (temp_seconds < 0) {
    temp_minutes = temp_minutes - 1;
    temp_seconds = temp_seconds + 60;
  }
  while (temp_minutes < 0) {
    temp_hours = temp_hours - 1;
    temp_minutes = temp_minutes + 60;
  }
  hours = temp_hours;
  minutes = temp_minutes;
  seconds = temp_seconds;
}


void Clock::SetName(string nameInput) { clockName = nameInput; }
string Clock::GetName() { return clockName; }

void Clock::Print() {
  cout << clockName << " current values: ";
  cout << hours << " Hours ";
  cout << minutes << " Minutes: ";
  cout << seconds << " Seconds: " << endl;
}

/*
_____________ WARNING _____________
_________ CLOCK MATH AHEAD ________
*/
// Basic Hours Math
void Clock::addHours(int h) { 
  hours = hours + h; 
  Print();
}

void Clock::subtractHours(int h) {
  hours = hours - h;
  Print();
}

// Basic Minutes Math
void Clock::addMinutes(int m) {
  minutes = minutes + m;
  TimeSortUp();
  Print();
}

void Clock::subtractMinutes(int m) {
  minutes = minutes - m;
  TimeSortDown();
  Print();
}

// Basic Seconds Math
void Clock::addSeconds(int s) {
  seconds = seconds + s;
  TimeSortUp();
  Print();
}

void Clock::subtractSeconds(int s) {
  seconds = seconds - s;
  TimeSortDown();
  Print();
}

// Boolean Printing 24 hour or 12 hour conversion function
void Clock::PrintTime(bool twelveHr) {
  if (twelveHr == true) {
    ConvertTwelve();
  }
  else {
    ConvertTwnFour();
  }
}
// Boolean Choice Printing Conversion 24
void Clock::ConvertTwnFour() {
  temp_hours = hours;
  if (temp_hours > 23) {
    temp_hours = (temp_hours % 24);
  }
  AMPM = "24hr";
  cout << clockName << " says the time is: ";
  cout << temp_hours << ":" << minutes << ":";
  cout << seconds << " " << AMPM << endl;
}

// Boolean Choice Printing Conversion 12
void Clock::ConvertTwelve() {
  temp_hours = hours;
  if (temp_hours > 23) {
    temp_hours = (temp_hours % 24);
  }
  if (temp_hours == 0) {
    AMPM = "AM";
    temp_hours = 12;
  }
  else if (temp_hours < 12) {
    AMPM = "AM";
  }
  else if (temp_hours == 12) {
    AMPM = "PM";
  }
  else {
    AMPM = "PM";
    temp_hours = temp_hours - 12;
  }
  cout << clockName << " says the time is: ";
  cout << temp_hours << ":" << minutes << ":";
  cout << seconds << " " << AMPM << endl;
}
/*
__________ OVERLOADING COMPARISONS __________
*/

bool Clock::operator==(const Clock& c1) {
	return (c1.hours == hours) && (c1.minutes == minutes) && (c1.seconds == seconds);
}

bool Clock::operator!=(const Clock& c1) {
  return (c1.hours != hours) || (c1.minutes != minutes) || (c1.seconds != seconds);
}

bool Clock::operator<(const Clock& c1) {
  if (c1.hours != hours) {
    if (hours < c1.hours) {
      return true;
    }
    else {return false; }
  }
  else { 
    if (minutes != c1.minutes) {
      if (minutes < c1.minutes) {
        return true;
      }
      else {return false;}
    }
    else {
      if (seconds != c1.seconds) {
        if (seconds < c1.seconds) {
          return true;
        }
        else {return false;}
      }
      else {return false;}
    }
  }
}

bool Clock::operator>(const Clock& c1) {
  cout << "testing opposite";
  if (c1.hours != hours) {
    if (hours > c1.hours) {
      return true;
    }
    else {return false; }
  }
  else { 
    if (minutes != c1.minutes) {
      if (minutes > c1.minutes) {
        return true;
      }
      else {return false;}
    }
    else {
      if (seconds != c1.seconds) {
        if (seconds > c1.seconds) {
          return true;
        }
        else {return false;}
      }
      else {return false;}
    }
  }
}

bool Clock::operator<=(const Clock& c1) {
  if (hours == c1.hours) {
    if (minutes == c1.minutes) {
      if (seconds == c1.seconds) {
        return true;
      }
      else {
        if (seconds < c1.seconds) {
        return true;
        }
        else {return false;}
      }
    }
    else {
      if (minutes < c1.minutes) {
        return true;
      }
      else {return false;}
    }
  }
  else {
    if (hours < c1.hours) {
      return true;
    }
    else {return false; }
  }
}

bool Clock::operator>=(const Clock& c1) {
  if (hours == c1.hours) {
    if (minutes == c1.minutes) {
      if (seconds == c1.seconds) {
        return true;
      }
      else {
        if (seconds > c1.seconds) {
        return true;
        }
        else {return false;}
      }
    }
    else {
      if (minutes > c1.minutes) {
        return true;
      }
      else {return false;}
    }
  }
  else {
    if (hours > c1.hours) {
      return true;
    }
    else {return false; }
  }
}

