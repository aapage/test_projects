#ifndef _MAPENTITYCLASS_H_
#define _MAPENTITYCLASS_H_

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: To serve as a base class for more specific classes that represent
//         entities that will be drawn onto a map in specific ways, but
//         using the common interface that this class provides..

#include <string>
#include <sstream>
using namespace std;

class MapEntityClass; //forward declaration

#include "MapClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"

class MapEntityClass
{
  protected:
    PixelLocationClass location; //Specific location of this entity within
                                 //a map image..
    ColorClass color; //The color that this entity is to be drawn with
                      //on the map image..

  public:
    //The only ctor available - in order to create something that derives
    //from MapEntityClass, user must provide a location and a color for
    //the entity.
    MapEntityClass(
         const PixelLocationClass &inPixLoc,
         const ColorClass &inColor
         )
    {
      location = inPixLoc;
      color = inColor;
    }

    //A pure virtual interface for drawing the map entity on a map image.
    //The function returns void since it will use exceptions, rather than
    //relying on a boolean return type, to indicate a problem occurred.
    //This function does NOT change 'this' map entity, but does affect
    //the map being pointed to by the parameter.
    virtual void drawOnMap(MapClass *mapObj) const = 0;

    //While this function is virtual, this implementation will be used
    //to convert attributes of this base class to a string, while the 
    //lower-level clases are responsible for their own attributes.
    virtual string toString() const
    {
      ostringstream oss;

      oss.clear();
      oss.str("");
  
      oss << "loc: " << location.toString() <<
             " color: " << color.toString();

      return (oss.str());
    }

    //Common interface for getting the type of a subclass as a string.
    virtual string getType() const = 0;
};

#endif // _MAPENTITYCLASS_H_