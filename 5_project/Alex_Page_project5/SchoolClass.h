#ifndef _SCHOOLCLASS_H_
#define _SCHOOLCLASS_H_

#include <string>
#include <iostream>
using namespace std;

#include "RectangularEntityClass.h"
#include "PixelLocationClass.h"
#include "ColorClass.h"

//Programmer: Alex Page
//SchoolClass are school objects that contain all information necessary to draw
//them on the map

//constants for houses
const ColorClass SCHOOL_COLOR = ColorClass(63,63,255); //red
const int STUDENTS_PER_PIXEL = 50;
const string SCHOOL_TYPE = "School";

class SchoolClass: public RectangularEntityClass
{
 private:
  int numStudents;
  int numRows;
  int numCols;

 public:
  //makes a house with pixel location and dollar value set

  SchoolClass(PixelLocationClass inPixel,
             int inNumStudents,
             ColorClass inColor = SCHOOL_COLOR);

  //toString prints out relavent info
  string toString() const;

  //getType returns a string of the object type 
  string getType() const;

  //get Number of rows
  int getNumRows() const;

  //get Num of cols
  int getNumCols() const;

};


#endif
