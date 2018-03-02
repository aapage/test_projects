#ifndef _PIXELLOCATIONCLASS_H_
#define _PIXELLOCATIONCLASS_H_

#include <string>
using namespace std;

class PixelLocationClass
{
  private:
    int row;  //The row value of a location
    int col;  //The column value of a location

  public:
    PixelLocationClass()
    {
      row = 0;
      col = 0;
    }

    PixelLocationClass(
         int inRow,
         int inCol
         )
    {
      row = inRow;
      col = inCol;
    }

    //This function prompts the user with the string:
    //"Enter <label> row and column: " where <label> is replaced with the
    //contents of the string parameter passed in.  If the user enters two
    //valid integers, the row and column are set, respectively.  Upon
    //invalid entry (i.e. invalid data type), the message 
    //"Invalid data entered" is printed, and the user is re-prompted
    //for both the row and column (regardless of whether ANY valid
    //input was found).  This continues until the user enters valid
    //integers for row and column.  No range checking is required, and since
    //the program will not exit until valid input was found, no return
    //value is required.
    void getInfoFromUser(const string &label);

    //This function "blindly" (without any range checking) assigns the
    //pixel location row to inR and the column to inC.  No return value.
    void assign(int inR, int inC);

    //Simple reader function to return the row value of the pixel location
    int getRow() const;

    //Simple reader function to return the column value of the pixel location
    int getCol() const;

    //Converts this pixel location object to a printable string
    string toString() const;

    //Add two pixel locations together to form a sum
    PixelLocationClass operator+(
         const PixelLocationClass &rhs
         ) const
    {
      return PixelLocationClass(row + rhs.row, col + rhs.col);
    }

    //Subtract two pixel locations together to form a difference
    PixelLocationClass operator-(
         const PixelLocationClass &rhs
         ) const
    {
      return PixelLocationClass(row - rhs.row, col - rhs.col);
    }
};

#endif //_PIXELLOCATIONCLASS_H_