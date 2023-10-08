#ifndef DECORATOR_H
#define DECORATOR_H

#include "Notify.h"
#include <iostream>
using namespace std;

class IBaseDecorator : public INotify  //Inheritance
{
      public:
      virtual void sendMessage(string message)=0;
};

#endif