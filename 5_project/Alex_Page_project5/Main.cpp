#include "MapEntityClass.h"
#include "HouseClass.h"
#include "SchoolClass.h"
#include "RoadClass.h"
#include "ParkClass.h"
#include "MapClass.h"
#include "ColorClass.h"
#include "MapExceptionClass.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: Demonstrate implementations of functionality relating to forming
//         a map image from a description of map entities, which initially
//         include houses, schools, roads, and parks..

int main(int argc, char *argv[])
{
  vector< MapEntityClass *> mapEntVec;
  vector< MapEntityClass *>::iterator mapEntIter;
  MapEntityClass *mapEntPtr;
  MapClass *mapPtr;
  int entInd;
  string outFname;

  //Generate a bunch of entities in a specific order now..  The entities
  //will be drawn in this order, so if there ends up being overlap between
  //the entities, then the earlier-drawn entity's pixels will be 
  //overwritten by the later-drawn entity's pixels..
  mapEntVec.push_back(new HouseClass(PixelLocationClass(120, 220), 100000));
  mapEntVec.push_back(new SchoolClass(PixelLocationClass(50, 50), 252));
  mapEntVec.push_back(new RoadClass(PixelLocationClass(5, 5), 75, 4, true));
  mapEntVec.push_back(new RoadClass(PixelLocationClass(160, 20), 212,
                                                       3, false));
  mapEntVec.push_back(new SchoolClass(PixelLocationClass(151, 115), 516));
  mapEntVec.push_back(new ParkClass(PixelLocationClass(90, 280), 350));
  mapEntVec.push_back(new RoadClass(PixelLocationClass(100, 250), 53, 2, false));
  mapEntVec.push_back(new ParkClass(PixelLocationClass(18, 281), 515));
  mapEntVec.push_back(new SchoolClass(PixelLocationClass(100, 150), 1266));
  mapEntVec.push_back(new RoadClass(PixelLocationClass(1, 142), 190, 4, true));
  mapEntVec.push_back(new HouseClass(PixelLocationClass(5, 135), 300000));

  //Print out all the entities that are going to be drawn on the map,
  //in the order they will be drawn
  for (mapEntIter = mapEntVec.begin(); 
       mapEntIter != mapEntVec.end();
       mapEntIter++)
  {
    //Note: mapEntIter is an iterator that points to a node with a
    //      MapEntityClass* in it, so (*mapEntIter) is a
    //      MapEntityClass*...  That's what we want to operate on..
    mapEntPtr = *mapEntIter;
    cout << mapEntPtr->toString() << endl;
  }

  //Generate map of specific size
  mapPtr = new MapClass(200, 300, ColorClass(33, 33, 33));

  //Now, request that each entity, in order, be drawn to the map..
  entInd = 0;
  for (mapEntIter = mapEntVec.begin(); 
       mapEntIter != mapEntVec.end();
       mapEntIter++)
  {
    mapEntPtr = *mapEntIter;

    cout << "---------------------------------------" << endl;
    cout << "Drawing entity #" << entInd <<
            " type: " << mapEntPtr->getType() << endl;

    try
    {
      mapEntPtr->drawOnMap(mapPtr);

      cout << "Entity #" << entInd << ": drawOnMap completed successfully!" <<
              endl;
    }
    catch (MapExceptionClass mapExcep)
    {
      cout << "Entity #" << entInd << ": Caught a map exception!" << endl;
      cout << "  " << mapExcep.toString() << endl;
    }

    entInd++;
  }

  outFname = "outMap.ppm";
  cout << "Writing map to output image: " << outFname << endl;
  mapPtr->writeToFile(outFname);
  return 0;
}