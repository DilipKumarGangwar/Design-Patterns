#include <iostream>
#include "BaseDecorator.h"
using namespace std;

class WhatsappNotifier: public IBaseDecorator
{
  INotify * ntfy;

  public:
  WhatsappNotifier(INotify * ntfy)
  {
    this->ntfy = ntfy;
  }
    
  void sendMessage(string message) 
  {
      this->ntfy->sendMessage(message);
      cout<<"Sending Message = "<<message<<" via Whatsapp "<<endl;
  }
};
