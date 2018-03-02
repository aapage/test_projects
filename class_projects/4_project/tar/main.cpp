#include <iostream>
#include <string>
using namespace std;


#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"

#include "RiderClass.h"
#include "EventClass.h"
#include "EventListClass.h"
#include "ParkClass.h"

//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{

  string fileName;
  //command line arguments------------------------------------------
  if (argc == 2)
    {
      //load park specific parameters
      fileName = argv[1];  // should be "simParams.txt";
    }
  else
    {
      cout << " Error: Exatly 1 command line argument is";
      cout <<"required for file name of parameter text file";
      exit(1);
    }  

  //set seed for RNG-------------------------------------------------
  const int seedNum = 0;
  setSeed(seedNum);



  //initialize Park settings-----------------------------------------
  //create list of events that will be generated as the sim runs
  EventListClass eventList(fileName);
  
  //initialize the park ride, in this case, spacemountain
  ParkClass spaceMountain = eventList.initiatePark();
  
  //define types of events
  const string rider = "rider"; //a person arrives at the park to ride the ride
  const string cart = "cart"; //a cart arrives to take people on the ride
  
  //park opens at time = 0
  int time = 0;
  
  //start simulation out at time=0 with 1 rider and 1 cart event
  eventList.addEventToList(time, rider);
  eventList.addEventToList(time, cart);
  


  //main loop variables-----------------------------------------------
  EventClass nextEvent; //temp holding the next event that occurs
  RiderClass newRider; //temp holding new rider to be added to rideLines
  string priLvl;
 
  int currentTime = 0;//start sim at t = 0
  int closingTime = eventList.getClosingTime();
  int ridersInLine = 0;//total number of riders in line
  int numPassengers; //the number loaded in to a cart

  bool parkIsOpen = true; //will be set to false when all riders leave
  bool allLinesEmpty;//gets set when cart is filled

  //splash-------------------------------------------------------------
  cout << "--------------------------------------" << endl;
  cout << "--------------PARK OPEN---------------";
  cout << "--------------------------------------" << endl;





 

  //----------------------BEGIN SIMULATION-------------------------------------
  //---------------------------------------------------------------------------

  while (parkIsOpen)
    {
      cout << "Current Time: " << currentTime << endl;

      //lool while ready events are available, execute each event in order
      while (eventList.getNextEvent(currentTime, nextEvent))
	{
	  cout << "--------------------------------------" << endl;
	  cout << "EVENT: " << nextEvent.getType() << " arrives" <<
	    " at Time: " << currentTime <<endl;

	  //Rider type Events---------------------------------------
	  //--------------------------------------------------------
	  if (nextEvent.getType() == rider) 
	    {
	      //generate new RiderClass obj and add to line
	      newRider = eventList.generateRider(currentTime);
	      spaceMountain.addRiderToLine(newRider);
	      ridersInLine++;
	      
	      if (newRider.getPriority() == 0) {priLvl = "SFP";}
	      else if (newRider.getPriority() == 1) {priLvl = "FP";}
	      else if (newRider.getPriority() == 2) {priLvl = "Std";}
	      cout << "Priority level: " << priLvl << endl << endl;

	      cout << "Total riders waiting in line: " << ridersInLine << endl;
	      spaceMountain.printRideLines();
	      
	      //repopulate rider event in eventList if its before closing 
	      if (currentTime < closingTime)
		{
		  eventList.addEventToList(currentTime, rider);
		  cout << "New Rider added to event list" << endl;
		}

	      cout << "--------------------------------------" << endl;
	    }

	  //Cart type events ---------------------------------------
	  //--------------------------------------------------------
	  else if (nextEvent.getType() == cart) 
	    {
	      //fill cart up from riderLines
	      numPassengers = spaceMountain.fillCart(currentTime);
	      cout << endl;

	      //keep track of total riders in line
              ridersInLine -= numPassengers;
	      cout << "Total riders waiting in line: " << ridersInLine << endl;
	      spaceMountain.printRideLines();
	      
	      //repopulate cart event in eventLis
	      cout << "New cart added to event list" << endl;
	      eventList.addEventToList(currentTime, cart);
	      cout << "--------------------------------------" << endl;
	    }
	}
     
      if (currentTime == closingTime)
	{
	  cout << "CLOSING TIME (no new riders allowed in)" << endl;
	}

      if (currentTime >= closingTime && ridersInLine ==0)
	{
	  parkIsOpen = false;
	  cout << "All guests gone, Park is now Closed" << endl;
	}
      
      currentTime++;
    }
  //print out statistics of simulation
  spaceMountain.calculateStatistics();

  //end
  return 0;
}
