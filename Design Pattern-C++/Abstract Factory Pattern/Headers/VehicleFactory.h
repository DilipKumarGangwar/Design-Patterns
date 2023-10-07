#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H
#include "Vehicle_INTF.h"

#include <iostream>
using namespace std;

class IVehicleFactory
{
    public:
     static  Vehicle * getVehicle(string);
};

#endif