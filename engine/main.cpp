
#include <iostream>
#include <string>
using namespace std;

#include "constants.h"
#include "Object3dClass.h"


int main()
{
  Object3dClass obj1;
  obj1.print();
  Object3dClass obj2(0,1,2,3,4,5,1.0);
  obj2.print();
  float pos1[] = {0,0,0};
  obj2.setPosition(pos1);
  obj2.print();
  obj2.setVelocity(pos1);
  obj2.print();
  obj2.setMass(2.0);
  obj2.print();
  
  cout << "update Position:" << endl;
  obj2.updatePosition();
  obj2.print();
  obj2.setVelocity(1,1,0);
  obj2.updatePosition();
  obj2.print();

  for (int i =0; i <10; i++)
    {
      obj2.updatePosition();
      cout << i << ": ";
      obj2.print();

      obj2.addForce(0,0,-1);
      
    }

  return 1;
}
