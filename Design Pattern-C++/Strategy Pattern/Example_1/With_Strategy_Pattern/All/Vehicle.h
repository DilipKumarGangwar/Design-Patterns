#ifndef VEHICLE_HPP
#define VEHICLE_HPP


#include "../Strategy/Headers/Strategy_INTF.h"

class Vehicle
{
   IStrategy *strategy;
   public:
      //constructor injection
      Vehicle(IStrategy *strategy);
      void drive();
     
};
#endif