

#include "RiderClass.h"

using namespace std;


//Programmer: Alex Page
//Purpose: contains all information about a rider at the park and generates
//arrival times based normal distributions and priority based on a uniform dist
//-----------------------------------------------------------------------------

//constructor
RiderClass::RiderClass(int inArrival, int inPriority)
{
  arrivalTime = inArrival;
  priority = inPriority;
  waitTimeInLine = 0;
}

RiderClass::RiderClass()
{;}

//operators

bool RiderClass::operator<(const RiderClass inRider) const
{
  bool lessThan;
  if (arrivalTime < inRider.arrivalTime) {lessThan = true;}
  else { lessThan = false;}
  
  return lessThan; 
}


bool RiderClass::operator>(RiderClass inRider) const
{
  bool greaterThan;
  if (this->arrivalTime < inRider.arrivalTime) {greaterThan = true;}
  else { greaterThan = false;}

  return greaterThan;
}


//memeber functions

int RiderClass::getTime() const
{
  return arrivalTime;
}

int RiderClass::getPriority() const
{
  return priority;
}

void RiderClass::setWaitTime(int inWaitTime)
{
  waitTimeInLine = inWaitTime;
}

int RiderClass::getWaitTime() const
{
  return waitTimeInLine;
}

void RiderClass::incrementWaitTime()
{
  waitTimeInLine++;
}



//insertion operator for RiderClass--------------------------------------------
ostream& operator<<(ostream &os, const RiderClass &inRider)
{
  os << "(" << inRider.getTime() << ")";
  return os;
}





