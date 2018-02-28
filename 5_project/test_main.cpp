#include <iostream>
using namespace std;


#include "MapEntityClass.h"
#include "HouseClass.h"
#include "SchoolClass.h"
#include "RoadClass.h"
#include "ParkClass.h"
#include "MapClass.h"
#include "ColorClass.h"
#include "MapExceptionClass.h"

#include <iostream>
#include <string>
#include <vector>


//#include "RectangularEntityClass.h"
//#include "HouseClass.h"



int main()
{

  PixelLocationClass pixel1(120, 220);
  HouseClass house1(pixel1, 100000);
  cout << house1.toString() << endl;

  SchoolClass school1(pixel1, 220);
  cout << school1.toString() << endl;

  RoadClass road1(pixel1, 300, 4, true);
  cout << road1.toString() << endl;

  
  cout << "END" << endl;

 return 0;
}
