#ifndef _OBJECT3DCLASS_H_
#define _OBJECT3DCLASS_H_

#include "constants.h"

class Object3dClass
{
 private:
  float position[3];
  float velocity[3];
  float mass;
 public:
  Object3dClass( float posX, float posY, float posZ, float vX, float vY,
		 float vZ, float inMass);
  Object3dClass();
  void setMass(float inMass);
  void getPosition(float inPosition[3]);
  void setPosition(float x, float y, float z);
  void setPosition(float newPosition[3]);
  void setVelocity(float x, float y, float z);
  void setVelocity(float newVelocity[3]);
  void print();
  
  //force and update functions
  void updatePosition();
  void addForce(float force[3]);
  void addForce(float x, float y, float z);


};

#endif
