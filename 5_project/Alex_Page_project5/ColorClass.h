#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <fstream>
#include <string>
using namespace std;

const int MAX_COLOR = 255;

class ColorClass
{
  private:
    int red;   //Amount of red, green, and blue that make up a color object.
    int green; //Each value must be between 0 and the constant MAX_COLOR,
    int blue;  //inclusive.  The interface to this class will never allow
               //these values to be set outside of this range,

  public:
    //Default ctor initializes color to black
    ColorClass()
    {
      red = 0;
      green = 0;
      blue = 0;
    }

    //Value ctor initializes color to requested RGB values
    ColorClass(const int inRed, const int inGreen, const int inBlue)
    {
      red = inRed;
      green = inGreen;
      blue = inBlue;
    }

    //This function directly modifies the data members, ensuring that
    //they are never set outside the valid range.  If ANY of the input
    //parameters is not within range, the data members are not modified
    //in any way.
    bool setColor(int inR, int inG, int inB);

    //Directly sets the data members to be of color full red
    void setRed();

    //Directly sets the data members to be of color full green
    void setGreen();

    //Directly sets the data members to be of color full blue
    void setBlue();

    //Directly sets the data members to be of color full white
    void setWhite();

    //Directly sets the data members to be of color full black
    void setBlack();

    //Attempts to read three integers from the input file stream passed
    //as a parameter.  If successful, the values read are used to attempt
    //to set the data members.  This function does NOT directly modify
    //the data members, it makes use of other member functions that
    //perform the required error checking.  If the values are read in
    //successfully and the color is correctly set, the function returns
    //true, otherwise false is returned.
    bool readFromFile(ifstream &inFile);

    //This function writes three integers, with one space separating them,
    //to the output file stream passed as a parameter.  If the function
    //successfully writes the values to the stream, true is returned, 
    //otherwise, false is returned.
    bool writeToFile(ofstream &outFile) const;

    //This function returns true if, and only if, the attributes of the color
    //that is passed in are the same as the attributes of the color object
    //on which the function was called.  Otherwise, false is returned.
    bool isSameColor(const ColorClass &inColor) const;

    //This function prompts the user to select a color from a menu,
    //and, when the user enters a valid value, assigns the color object
    //attributes to the color chosen.  This function does NOT directly 
    //modify the data members, it makes use of other member functions that
    //perform the required action.  The user is re-prompted until valid
    //input is recevied, therefore, the function will not exit until
    //the color is set to a valid value, and therefore, no return value
    //is needed.  The label parameter is printed during the prompt after
    //the menu is displayed to the user
    void getInfoFromUser(const string &label);

    //Converts this color object to a printable string.
    string toString() const;
};

#endif //_COLORCLASS_H_