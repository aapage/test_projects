#ifndef _EVENTCLASS_H_
#define _EVENTCLASS_H_

#include "SortedListClass.h";
#include "RiderClass.h"
#include "random.h"
#include <string>

using namespace std;

//Programmer:Alex Page
//Event objects hold the arrival time and type of event
//-----------------------------------------------------------------------------

class EventClass
{
 private:
  int arrivalTime;
  string eventType; // 'rider' for rider or 'cart' for cart
 public:
  EventClass(); //defualt constr
  EventClass(int inTime, string inType);
  
  //operator overloading
  bool operator<(EventClass inEvent) const;
  string getType() const;
  int getTime() const;
  
};

ostream& operator<<(ostream &os, const EventClass &inEvent); //for print()


#endif
