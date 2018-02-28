#ifndef _PARKCLASS_H_
#define _PARKCLASS_H_

#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"
#include "RiderClass.h"


using namespace std;

//Programmer:Alex Page
//ParkClass objects are single rides at the park
//they contain the FIFOQueues which represent lines of various priority levels
//aswell as a function for loading passengers based on priority
//-----------------------------------------------------------------------------

class ParkClass
{
 private:
  //park details
  static const string attractionName; //"Space Mountain" initialized afterclass
  static const int numSeat = 20; //set base on ride
  static const int numPriority = 3; //Number of priority levels
 
  //levels of priority
  static const int lvlSFP = 0;
  static const int lvlFP = 1;
  static const int lvlSTD = 2;

  //relevant specs from simParams.txt, get from EventListClass
  int numSFP;
  int numFP;

  //Lines for the ride, one for each piorirty class
  //riderClass priority corresponds to index in rideLines array
  FIFOQueueClass< RiderClass > rideLines[numPriority];

  //statistics on riders and lines
  double avgWait[numPriority];
  int longestLine[numPriority];  

  //array of sorted list for each priority to store wait times
  SortedListClass< RiderClass > previousRiders[numPriority];

  //array of sorted list for each priority to store passengers/cart
  //last index [3]  is for total passengers/cart
  static const int numListTotal = numPriority+1;
  static const int indxTotal = numListTotal-1;
  SortedListClass<int> numPassList[numListTotal];

  //average number of passengers per cart for each lvl and total
  double avgNumPass[numListTotal];

 
 //end statistics attributes

 public:
  //constructor
  ParkClass(int inNumSFP, int inNumFP);

  //memberfucntions--------------------------------
  //add rider to rideLines base on priority
  void addRiderToLine(RiderClass &newRider); 

  //fill up cart with riders from rideLines
  //returns true if all lines are empty after filling
  int fillCart(int time);

  //statistics functions------
 
  //prints list of all Riders that boarded the ride for the day
  void printPreviousRiders();

  //prints lists of the current lines by priority
  void printRideLines();

  //calculate statistics and print out
  void calculateStatistics();
  
};



#endif
