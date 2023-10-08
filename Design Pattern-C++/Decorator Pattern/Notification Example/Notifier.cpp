#include <iostream>
#include "Notify.h"
using namespace std;

class Notifier: public INotify
{
  void sendMessage(string message)
  {
      cout<<"Sending Message = "<<message<<" via Email "<<endl;
  }
};
