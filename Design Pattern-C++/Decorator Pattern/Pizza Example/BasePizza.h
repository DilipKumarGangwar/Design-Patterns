#ifndef BASE_PIZZA_H
#define BASE_PIZZA_H
#include <iostream>
using namespace std;

class IBasePizza
{
     public:
      virtual int cost()=0;
};

#endif