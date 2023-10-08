#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <iostream>
using namespace std;

class INotify
{
     public:
      virtual void sendMessage(string message)=0;
      
};

#endif