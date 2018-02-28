#include "Object3dClass.h" 

#include <iostream>
using namespace std;

Object3dClass::Object3dClass(float posX, float posY, float posZ, float vX, float vY, float vZ, float inMass)
{
  this->setPosition(posX, posY, posZ);
  this->setVelocity(vX,vY,vZ);
  this->setMass(inMass);
}
Object3dClass::Object3dClass()
{
  for( int i =0; i < 3; i++)
    {
      position[i] = 0.0;
      velocity[i] = 0.0;
    }
  mass = 1.0;
}

void Object3dClass::setMass(float inMass)
{
  mass = inMass;
}


void Object3dClass::getPosition(float inPosition[3])
  {
    for( int i =0; i < 3; i++)
       {
	 inPosition[i] = position[i];
       }
  }
void Object3dClass::setPosition(float x, float y, float z)
{
  position[0] = x;
  position[1] = y;
  position[2] = z;
}

void Object3dClass::setPosition(float newPosition[3])
{
  for( int i =0; i < 3; i++)
    {
      position[i] = newPosition[i];
    }  
}

void Object3dClass::setVelocity(float x, float y, float z)                            
{                                                                            
  velocity[0] = x;                                                      
  velocity[1] = y;                                                      
  velocity[2] = z;                                                     
} 
void Object3dClass::setVelocity(float newVelocity[3])
{
  for( int i =0; i < 3; i++)
    {
      velocity[i] = newVelocity[i];
    }

}


void Object3dClass::print()
{
  cout << "(" << position[0] << ", " << position[1] << ", " << position[2] <<
    "), (" << velocity[0]<< ", "<< velocity[1] << ", " << velocity[2]
       << "), mass :" << mass <<  endl;
}

//------------------------------------
//force and update functions
//------------------------------------

void Object3dClass::updatePosition()
{
  for (int i = 0; i<3; i++)
    {
      position[i]+= velocity[i]*dt;  
    }
}

void Object3dClass::addForce(float force[3])
{
  for (int i = 0; i<3; i++)
    {
      velocity[i]+= force[i]/mass;
    }  
}

void Object3dClass::addForce(float forceX, float forceY, float forceZ)
{
  velocity[0] += forceX/mass;
  velocity[1] += forceY/mass;
  velocity[2] += forceZ/mass;
}



