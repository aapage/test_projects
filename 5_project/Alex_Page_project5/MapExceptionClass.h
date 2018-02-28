#ifndef _MAPEXCEPTIONCLASS_H_
#define _MAPEXCEPTIONCLASS_H_

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: Provide a very simple exception class to be used in conjunction
//         with a program that draws city entities onto a map.  In reality
//         this is a generic exception class with limited functionality..
//
#include <iostream>
#include <string>
using namespace std;

class MapExceptionClass
{
 private:
  string excDescrip; //A descriptive message explaining what happened

 public:
  MapExceptionClass(
         const string &inDescrip
		    )
    {
      excDescrip = inDescrip;
    }

  //Converts the exception to a string so it can be printed when caught
  string toString() const
  {
    ostringstream oss;
    oss.clear();
    oss.str("");
  
    oss << "MapException: " << excDescrip;

    return oss.str();
  }
};

#endif // _MAPEXCEPTIONCLASS_H_
