#ifndef _RIDERCLASS_H_
#define _RIDERCLASS_H_

#include <iostream>
using namespace std;


//Programmer: Alex Page
//Purpose: contains all information about a rider at the park and generates
//arrival times based normal distributions and priority based on a uniform dist
//-----------------------------------------------------------------------------

class RiderClass
{
 private:
  int arrivalTime;
  int priority;
  int waitTimeInLine;

  
 public:
  //constructors
  RiderClass();
  RiderClass(int inArrival, int inPriority);
  
  //operator overloading for greater than and less than
  bool operator<(RiderClass inRider) const;
  bool operator>(RiderClass inRider) const;

  //memberfunctions
  int getTime() const;
  int getPriority() const;
  void  setWaitTime(int inWaitTime);
  int getWaitTime() const;
  void incrementWaitTime(); //not going to be used in this project
};

ostream& operator<<(ostream &os, const RiderClass &inRider);

#endif
