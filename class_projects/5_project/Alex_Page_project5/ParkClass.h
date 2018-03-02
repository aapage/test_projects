#ifndef _PARKCLASS_H_
#define _PARKCLASS_H_

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: Provide a class that will represent a park, which is a specific
//         type of map entity that will be able to be drawn onto a map
//         image via a description of the park.

#include <iostream>
#include <string>
using namespace std;

#include "MapEntityClass.h"
#include "ColorClass.h"
#include "MapClass.h"

//Some park-specific global constants..
const string PARK_TYPE_STR = "Park";
const ColorClass PARK_COLOR = ColorClass(0, 255, 0);
const int PARK_ACRES_PER_PIXEL = 25;

class ParkClass : public MapEntityClass
{
  private:
    int numAcres; //# of acres the park consists of

  public:
    //The only ctor that is available - parks are described via a 
    //location they are to be positioned within a map and a number
    //of acres the park consists of - the color of the park is 
    //maintained as a global constant specific to parks.
    ParkClass(
         const PixelLocationClass &inPixLoc,
         int inNumAcres
         ) : MapEntityClass(inPixLoc, PARK_COLOR)
    {
      numAcres = inNumAcres;
    }

    //Simply creates a printable string from a park object, making sure
    //to only be responsible for those attributes directly associated
    //with the actual ParkClass, and leaving higher-level attributes to
    //higher-level classes.
    string toString() const
    {
      ostringstream oss;
      oss.clear();
      oss.str("");
      oss << PARK_TYPE_STR << " Acres: " << numAcres << " " <<
             MapEntityClass::toString();

      return (oss.str());
    }

    //The required polymorphic interface for drawing a map entity onto
    //a map - this implementation draws a park as a circular icon on the
    //map being pointed to by the parameter.
    void drawOnMap(MapClass *mapObj) const;

    //The required polymorphic interface for getting the type of a
    //map entity as a string.
    string getType() const
    {
      return PARK_TYPE_STR;
    }
};

#endif // _PARKCLASS_H_