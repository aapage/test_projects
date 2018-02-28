#include "SchoolClass.h"

#include <string>
#include <iostream>
using namespace std;

#include "PixelLocationClass.h"
#include "ColorClass.h"
#include "RectangularEntityClass.h"

//Programmer: Alex Page
//HouseClass are house objects that contain all information necessary to draw
//them on the map

SchoolClass::SchoolClass(PixelLocationClass inPixel,
                       int inNumStudents,
                       ColorClass inColor):RectangularEntityClass(
                                                                  inPixel,
                                                                  inColor)
{
  //set number of students  and numRows,numCols
  if (inNumStudents < 0) 
    {
      cout << "SchoolCLass Error:" <<
	"number of students cannot be less than 0" << endl;
      cout << "taking absolute value" << endl;
      
      numStudents = -inNumStudents;
    }

  else { numStudents = inNumStudents;}

  //starts at 1 pixel, rounded to down to int
  numRows = numCols = 1 + numStudents/STUDENTS_PER_PIXEL;
}

string SchoolClass::toString() const
{
  ostringstream oss;
  oss.clear();
  oss.str("");

  //print to screen all important info
  oss << SCHOOL_TYPE << " #Students: " << numStudents << " " <<
    MapEntityClass::toString();

  return (oss.str());
}

string SchoolClass::getType() const
{
  return SCHOOL_TYPE;
}

int SchoolClass::getNumRows() const
{
  return numRows;
}

int SchoolClass::getNumCols() const
{
  return numCols;
}

