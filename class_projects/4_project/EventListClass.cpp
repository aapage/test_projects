

#include <iostream>
#include <string>
#include <fstream>

#include "EventClass.h"
#include "SortedListClass.h"
#include "RiderClass.h"
#include "random.h"
#include "EventListClass.h"
#include "ParkClass.h"

//Programmer:Alex Page
//Class to read in values from txt file
//Then generate events and store them in a list
//base on the probability distributions
//-----------------------------------------------------------------------------


//constructor
EventListClass::EventListClass(string txtFile)
{
  //set all specs from simParams.txt
  
  ifstream file;
  file.open(txtFile.c_str());
  
  if (file.fail())
    {
      cout << "Error, Unable to open file: " <<  txtFile << endl;
      exit(1);
    }
  else
    {
      file >> closingTime;
      file >> riderArrivalMean;
      file >> riderArrivalStddev;
      file >> carArrivalMin;
      file >> carArrivalMax;
      file >> percentSFP;
      file >> percentFP;
      file >> numSFP;
      file >> numFP;
    }
  file.close();
}

void EventListClass::addEventToList(int currentTime, string eventType)
{
  int deltaT;

  if (eventType == "rider")
    {
      deltaT = getNormal(riderArrivalMean,riderArrivalStddev);
      EventClass newEvent(currentTime+deltaT, "rider");
      eventList.insertValue(newEvent);
    }
  else if (eventType == "cart")
    {
      deltaT = getUniform(carArrivalMin,carArrivalMax);
      EventClass newEvent(currentTime+deltaT, "cart");
      eventList.insertValue(newEvent);
    }
  else 
    {
    cout << "error, event Type must be either 'rider' or 'cart'" << endl;
    }
}

bool EventListClass::getNextEvent(int time, EventClass &outEvent)
{
  bool eventReady;
  EventClass nextEvent;

  //check if list is empty and set nextEvent to head of eventList
  if (!eventList.getElemAtIndex(0, nextEvent))
    {
      eventReady = false; cout << "Event list is empty!" << endl;;
    }

  //check if event time is current time, if true 
  //event is ready to go! return it in outEvent
 else if (nextEvent.getTime() == time)
    {
      eventList.removeFront(outEvent);
      eventReady = true;
    }

  //no events ready
  else
    {
      eventReady = false;
    }
  return eventReady;
}


//generate a new rider
RiderClass EventListClass::generateRider(int time)
{

  int priority = getUniform(0,100);  
  int priorityLvl;

  if (priority >= 100-percentSFP) { priorityLvl = lvlSFP;}
  else if (priority >= 100-percentSFP-percentFP) { priorityLvl = lvlFP;}
  else { priorityLvl = lvlSTD;}
 
  RiderClass newRider(time, priorityLvl);
  
  return newRider;
}

ParkClass EventListClass::initiatePark()
{
  ParkClass park(numSFP, numFP);
  return park;
}

int EventListClass::getClosingTime()
{
  return closingTime;
}

void EventListClass::print()
{
  eventList.printForward();
}
