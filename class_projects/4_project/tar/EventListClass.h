#ifndef _EVENTLISTCLASS_H_
#define _EVENTLISTCLASS_H_

#include "SortedListClass.h";
#include "RiderClass.h"
#include "random.h"
#include "ParkClass.h"
#include <string>

using namespace std;

//Programmer:Alex Page
//Class to read in values from txt file
//Then generate events and store them in a list
//base on the probability distributions
//-----------------------------------------------------------------------------


class EventListClass
{
 private:
  //levels of priority
  static const int lvlSFP = 0;
  static const int lvlFP = 1;
  static const int lvlSTD = 2;

  //number of priority levels
  static const int numPriority = 3;

  //specs from simPrams.txt
  int closingTime;
  float riderArrivalMean;
  float riderArrivalStddev;
  int carArrivalMin;
  int carArrivalMax;
  int percentSFP;
  int percentFP;
  int numSFP;
  int numFP;

  //main event list sorted by arrival time
  SortedListClass< EventClass > eventList;
  
 public:
  //contructor
  EventListClass(string txtFile);

  //create new EventClass with type rider or cart
  void addEventToList(int currentTime, string eventType);

  //if the next event's arrival time matches the current time, the 
  //event is returned in outEvent, and function returns true.
  //if no events arrival match the current time, return false
  bool getNextEvent(int time, EventClass &outEvent);




  //create new RiderClass object with priority
  RiderClass generateRider(int time);

  //Initiate ParkClass 
  ParkClass initiatePark();

  int getClosingTime();
  void print();
};

#endif
