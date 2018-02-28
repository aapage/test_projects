#include "RectangularEntityClass.h"


#include "MapClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"
#include "MapEntityClass.h"
#include "MapExceptionClass.h"

//Programmer: Alex Page
//Date: April 2016
//Purpose: Inherits from MapEntityClass.
//This class will serve as a base class for
//three different rectangular objects: HouseClass, RoadClass, and SchoolClass
//-----------------------------------------------------------------------------

//default constructor must call MapEntityClass ctor
RectangularEntityClass::RectangularEntityClass(PixelLocationClass inPixel,
					       ColorClass inColor):
                                               MapEntityClass(inPixel, inColor)
{
  ; //only passing arguments up to MapEntityClass
}



void RectangularEntityClass::drawOnMap(MapClass *mapObj) const
{

  bool hadAProblem = false;  

  //start loop to draw rect
  for (int i = 0; i < getNumRows(); i++)
    {
      for (int j = 0; j < getNumCols(); j++)
	{
	   try
	     {
	       mapObj->setMapPixel(location + PixelLocationClass(i, j), color);
	     }
	   catch (MapExceptionClass mapExcep)
	     {
	       cout << "RectangularEntityClass::drawOnMap caught exception: "
		    << mapExcep.toString() << endl;
	       hadAProblem = true;
	     }
	}
    }

  //following the same style exception throw by Andre Morgan in ParkClass.cpp
  if (hadAProblem)
    {
      ostringstream excOSS;
      
      excOSS.clear();
      excOSS.str("");
      excOSS << "Attempted to draw out of bounds";
      
      throw MapExceptionClass(excOSS.str());
    }
  


}

