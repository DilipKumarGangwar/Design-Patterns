#ifndef BIKE_H
#define BIKE_H
#include "Vehicle_INTF.h"
using namespace std;

class Bike : public Vehicle
{
    public:
        void drive();
};

#endif