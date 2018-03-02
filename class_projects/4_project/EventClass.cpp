#include "EventClass.h"

using namespace std;

//Programmer:Alex Page
//Event objects hold the arrival time and type of event
//-----------------------------------------------------------------------------

EventClass::EventClass()
{;}

EventClass::EventClass(int inTime, string inType)
{
  arrivalTime = inTime;
  eventType = inType;
}

bool EventClass::operator<(const EventClass inEvent) const
{
  bool lessThan;
  if (arrivalTime < inEvent.arrivalTime) {lessThan = true;}
  else { lessThan = false;}

  return lessThan;
}

int EventClass::getTime() const
{
  return arrivalTime;
}

string EventClass::getType() const
{
  return eventType;
}

//insertion operator for EventClass--------------------------------------------
ostream& operator<<(ostream &os, const EventClass &inEvent)
{
  os << "(" << inEvent.getTime() << "," << inEvent.getType() << ")";
  return os;
}


