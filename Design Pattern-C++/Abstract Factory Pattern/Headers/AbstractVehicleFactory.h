#ifndef ABSTRACT_VECHICLE_H
#define ABSTRACT_VECHICLE_H
#include "VehicleFactory.h"


class AbstractVehicleFactory
{
    public:
      static IVehicleFactory * CreateCategoryObject(string choice);

};

#endif