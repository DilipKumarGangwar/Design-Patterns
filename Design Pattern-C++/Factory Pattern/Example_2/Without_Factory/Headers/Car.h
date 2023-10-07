#ifndef CAR_H
#define CAR_H

#include "Vehicle_INTF.h"
using namespace std;

class Car : public Vehicle
{
    public:
        void drive();
};

#endif