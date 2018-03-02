#include <iostream>
using namespace std;

#include "ParkClass.h"
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"
#include "RiderClass.h"



//Programmer:Alex Page
//ParkClass objects are single rides at the park
//they contain the FIFOQueues which represent lines of various priority levels
//aswell as a function for loading passengers based on priority
//-----------------------------------------------------------------------------

const string ParkClass::attractionName = "Space Mountain";

//constructor

ParkClass::ParkClass(int inNumSFP, int inNumFP)
{
  numSFP = inNumSFP;
  numFP = inNumFP;
}

//memeber functions

//add rider to rideLines base on priority
void ParkClass::addRiderToLine(RiderClass &newRider)
{
  int priorityLvl = newRider.getPriority();
  rideLines[priorityLvl].enqueue(newRider);
}


//fill cart up with available RiderClass from riderLines
int ParkClass::fillCart(int time)
{
  
  //keep track of number of each type of passenger
  int numPassTotal = 0;
 
  int numPassSFP = 0;
  int numPassFP = 0;
  int numPassSTD = 0;
  int numAddFP = 0; //added FP passengers to fill SFP empty spots
  
  bool queueSFPempty = false;
  bool queueFPempty = false;
  bool queueSTDempty = false;
  RiderClass newPassenger;
  
  //Not sure how to make the below loops cleaner

  //Take SFP riders in line if available-------------------------------------
  //-------------------------------------------------------------------------  
  while (numPassSFP < numSFP && queueSFPempty == false)
    {
      queueSFPempty = !rideLines[lvlSFP].dequeue(newPassenger);
    
      if (queueSFPempty == false)
	{
	  numPassSFP++;
	  numPassTotal++;

	  //calculate wait time for passenger = current time - arrival time
	  newPassenger.setWaitTime(time - newPassenger.getTime());

	  //add newPassenger to SortedList for SFP class riders
	  previousRiders[lvlSFP].insertValue(newPassenger);
	}
    }
  cout << numPassSFP << " SFP passengers boarded" << endl;
  
  //Take FP riders in line if available--------------------------------------
  //-------------------------------------------------------------------------
  while (numPassFP < numFP && queueFPempty == false)
    {
      queueFPempty = !rideLines[lvlFP].dequeue(newPassenger);
      if (!queueFPempty)
        {
          numPassFP++;
          numPassTotal++;

          //calculate wait time for passenger = current time - arrival time
          newPassenger.setWaitTime(time - newPassenger.getTime());

          //add newPassenger to SortedList for SFP class riders
          previousRiders[lvlFP].insertValue(newPassenger);
        }
    }

  //Add more FP passengers if SPF Line is empty and there are still seats ----
  //--------------------------------------------------------------------------
  while (numPassSFP + numAddFP < numSFP && queueFPempty == false)
    {
      queueFPempty = !rideLines[lvlFP].dequeue(newPassenger);
      if (!queueFPempty)
        {
          numAddFP++;
	  numPassFP++;
          numPassTotal++;

          //calculate wait time for passenger = current time - arrival time
          newPassenger.setWaitTime(time - newPassenger.getTime());

          //add newPassenger to SortedList for SFP class riders
          previousRiders[lvlFP].insertValue(newPassenger);
        }
    }

  cout << numPassFP << " FP passengers boarded" << endl;

  //Add Std passengers until the seats are full or queue is empty--------------
  //---------------------------------------------------------------------------
  while (numPassTotal < numSeat && queueSTDempty == false)
    {
      queueSTDempty = !rideLines[lvlSTD].dequeue(newPassenger);
      if (!queueSTDempty)
        {
	  numPassSTD++;
          numPassTotal++;

          //calculate wait time for passenger = current time - arrival time
          newPassenger.setWaitTime(time - newPassenger.getTime());

          //add newPassenger to SortedList for SFP class riders
          previousRiders[lvlSTD].insertValue(newPassenger);
        }
    }

  cout << numPassSTD << " Std passengers boarded" << endl;

  //summarize
  cout << "( " << numPassTotal << " total passengers boarded)" << endl;

  //update lists for statistics  
  numPassList[lvlSFP].insertValue(numPassSFP);
  numPassList[lvlFP].insertValue(numPassFP);
  numPassList[lvlSTD].insertValue(numPassSTD);
  numPassList[indxTotal].insertValue(numPassTotal);

  return numPassTotal;
}

//prints list of all Riders that boarded the ride for the day
void ParkClass::printPreviousRiders()
{
  cout << "List of past riders by arrival time: " << endl;
  cout << "(arrival time, priority, wait time)" << endl;

  string priLvl;

  for (int i = 0; i < numPriority; i++)
    {
      if (i == lvlSFP) {priLvl = "SFP";}
      else if (i == lvlFP) {priLvl = "FP";}
      else if (i == lvlSTD) {priLvl = "Std";}
      cout << "Piority lvl: " << priLvl << endl;
      previousRiders[i].printForward();
    }
}


//print out all ride lines
void ParkClass::printRideLines()
{
  cout << "Current Queue for ride: " << attractionName << endl; 
  cout << "(arrival time)" << endl;

  string priLvl;

  for (int i = 0; i < numPriority; i++)
    {
      if (i == lvlSFP) {priLvl = "SFP";}
      else if (i == lvlFP) {priLvl = "FP";}
      else if (i == lvlSTD) {priLvl = "Std";}
      cout << "Piority lvl: " << priLvl << endl;
      rideLines[i].print();
    }
}

void ParkClass::calculateStatistics()
{

  int tempTotal;
  int tempNumElemn;
  int totalNumberOfRiders[numPriority] = {0,0,0};
  RiderClass temp;

  for (int i = 0 ;i < numPriority; i++)
    {
      tempTotal = 0;
      tempNumElemn = 0;
      longestLine[i] = 0;// it was uninitialized in class def

      for (int j = 0 ;j < previousRiders[i].getNumElems(); j++)
	{
	  previousRiders[i].getElemAtIndex(j,temp);
	  tempTotal += temp.getWaitTime();

	  if (temp.getWaitTime() > longestLine[i])
	    {
	      longestLine[i] = temp.getWaitTime();
	    }
	}
      avgWait[i] = double(tempTotal)/previousRiders[i].getNumElems();      
    }
 
  //total riders in each lvl
  int totNumOfRiders[numListTotal] = {previousRiders[lvlSFP].getNumElems(),
					  previousRiders[lvlFP].getNumElems(),
				      previousRiders[lvlSTD].getNumElems(),
				      previousRiders[lvlSFP].getNumElems()+
				      previousRiders[lvlFP].getNumElems()+
                                      previousRiders[lvlSTD].getNumElems()};
  
  //calculate weighted avg
  double allRiderAvgWait = (avgWait[lvlSTD]*totNumOfRiders[lvlSTD]
			    +avgWait[lvlFP]*totNumOfRiders[lvlFP]
			    +avgWait[lvlSFP]*totNumOfRiders[lvlSFP])/
    (totNumOfRiders[lvlSTD]+totNumOfRiders[lvlFP]+totNumOfRiders[lvlSFP]);
 

  //output average wait times----------------------------------
  cout << "\n\n\n";
  cout << "##################################" << endl;
  cout << "###########Statistics#############" << endl;

  cout << "\nTotal number of riders by prioirity:"<< endl;
  cout << "All riders: " << totNumOfRiders[indxTotal] << endl;
  cout << "SFP: " << totNumOfRiders[lvlSFP] << endl;
  cout << "FP: " <<  totNumOfRiders[lvlFP] << endl;
  cout << "STD: " << totNumOfRiders[lvlSTD] << endl;


  cout << "\nAverage wait time by priority:" << endl;
  cout << "All riders: " << allRiderAvgWait << endl;
  cout << "SFP: " << avgWait[lvlSFP] << endl;
  cout << "FP: " <<  avgWait[lvlFP] << endl;
  cout << "STD: " << avgWait[lvlSTD] << endl;



  //Longest Line stats------------------------------------------
  cout << endl << "Longest Line:"<< endl;
  cout << "SFP: " << longestLine[lvlSFP] << endl;
  cout << "FP: " <<  longestLine[lvlFP] << endl;
  cout << "STD: " << longestLine[lvlSTD] << endl;

  // number of passengers per cart stats------------------------
  int tempNumPass;
 
  for (int i = 0; i < numListTotal; i++)
    {
      tempNumPass = 0;
      avgNumPass[i] = 0;//not initialized in class def

      for (int j = 0 ;j < numPassList[i].getNumElems(); j++)
	{
	  numPassList[i].getElemAtIndex(j, tempNumPass);
	  avgNumPass[i] += tempNumPass;
	}
      avgNumPass[i] = avgNumPass[i]/numPassList[i].getNumElems();
    }
  
  cout << "\nAverage number of passengers per Cart:"<< endl;
  cout << "Total: " << avgNumPass[indxTotal] << endl;
  cout << "SFP: " << avgNumPass[lvlSFP] << endl;
  cout << "FP: " <<  avgNumPass[lvlFP] << endl;
  cout << "STD: " <<  avgNumPass[lvlSTD] << endl;


}
