#ifndef _MAPCLASS_H_
#define _MAPCLASS_H_

//Programmer: Andrew Morgan
//Date: April 2016
//Purpose: Provide a class to store a map in an image, with the
//         ability to write it out to a PPM formatted file..

class MapClass; //forward declaration

#include "MapEntityClass.h"
#include "ColorClass.h"
#include "PixelLocationClass.h"
#include <string>
using namespace std;

const string MAP_MAGICNUMBER = "P3";

class MapClass
{
  private:
    int numRows; //how many rows the map image has
    int numCols; //how many columns the map image has
    ColorClass **pixels; //"2d" array of pixel values

  public:
    MapClass(
         const int inNumRows, 
         const int inNumCols, 
         const ColorClass &bgColor
         );
 
    ~MapClass();

    //Draws the current state of the map to a properly formatted PPM file
    void writeToFile(
         const string &inFname
         ) const;

    //Sets an individual pixel in the image to the color specified.  If the
    //requested pixel location is out-of-bounds an exception is thrown and
    //the map image is not modified in any way.
    void setMapPixel(
         const PixelLocationClass &pixLoc,
         const ColorClass &color
         );
};

#endif // _MAPCLASS_H_