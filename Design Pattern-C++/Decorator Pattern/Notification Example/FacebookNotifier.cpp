#include <iostream>
#include "BaseDecorator.h"
using namespace std;

class FacebookNotifier: public IBaseDecorator
{
  INotify * ntfy;

  public:
  FacebookNotifier(INotify * ntfy)
  {
    this->ntfy = ntfy;
  }
    
  void sendMessage(string message) 
  {
      this->ntfy->sendMessage(message);
      cout<<"Sending Message = "<<message<<" via facebook "<<endl;
  }
};
