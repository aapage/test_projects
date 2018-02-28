#include <sstream>
#include <iostream>
using namespace std;

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: Implementation of non-insignificant methods for the MapClass

#include "MapClass.h"
#include "ColorClass.h"
#include "MapExceptionClass.h"

MapClass::MapClass(
     const int inNumRows, 
     const int inNumCols, 
     const ColorClass &bgColor
     )
{
  if (inNumRows > 0 && inNumCols > 0)
  {
    numRows = inNumRows;
    numCols = inNumCols;

    //pixels is a ColorClass**, so dynamically allocate pixels accordingly
    //to look and work like a 2D array..
    pixels = new ColorClass*[numRows];
    for (int rInd = 0; rInd < numRows; rInd++)
    {
      pixels[rInd] = new ColorClass[numCols];

      //initialize all pixels to requested background color
      for (int cInd = 0; cInd < numCols; cInd++)
      {
        pixels[rInd][cInd] = bgColor;
      }
    }
  }
  else
  {
    ostringstream excOSS;
    excOSS.clear();
    excOSS.str("");
    excOSS << "ERROR: Requested map size is invalid!" << endl;
    excOSS << "  Requested: " << inNumRows << " x " << inNumCols;
    throw MapExceptionClass(excOSS.str());
  }
}

MapClass::~MapClass()
{
  for (int rInd = numRows; rInd < numRows; rInd++)
  {
    delete [] pixels[rInd];
  }

  delete [] pixels;
}

void MapClass::writeToFile(
     const string &inFname
     ) const
{
  ofstream outFile;

  outFile.open(inFname.c_str());

  if (!outFile)
  {
    ostringstream excOSS;
    excOSS.clear();
    excOSS.str("");
    excOSS << "ERROR: Unable to open output file: " << inFname;
    throw MapExceptionClass(excOSS.str());
  }

  outFile << MAP_MAGICNUMBER << endl;
  outFile << numCols << " " << numRows << endl;
  outFile << MAX_COLOR << endl;
  for (int rInd = 0; rInd < numRows; rInd++)
  {
    for (int cInd = 0; cInd < numCols; cInd++)
    {
      if (!pixels[rInd][cInd].writeToFile(outFile))
      {
        ostringstream excOSS;
        excOSS.clear();
        excOSS.str("");
        excOSS << "ERROR: Unable to write pixel RC " << rInd << "," << cInd;
        throw MapExceptionClass(excOSS.str());
      }
      outFile << " ";
    }
    outFile << endl;
  }

  outFile.close();
}

void MapClass::setMapPixel(
     const PixelLocationClass &pixLoc,
     const ColorClass &color
     )
{
  int rowVal;
  int colVal;

  rowVal = pixLoc.getRow();
  colVal = pixLoc.getCol();

  if (rowVal < 0 || rowVal >= numRows ||
      colVal < 0 || colVal >= numCols)
  {
    ostringstream excOSS;
    excOSS.clear();
    excOSS.str("");
    excOSS << "ERROR: Unable to set pixel " << pixLoc.toString() <<
              " - out of bounds: " << numRows << ", " << numCols;
    throw MapExceptionClass(excOSS.str());
  }

  pixels[rowVal][colVal] = color;
}
