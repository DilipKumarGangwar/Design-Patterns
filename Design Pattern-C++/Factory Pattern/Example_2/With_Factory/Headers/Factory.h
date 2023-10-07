#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
using namespace std;

#include "Vehicle_INTF.h"

class Factory
{
     public:
      static Vehicle * getObject(string choice);
};

#endif