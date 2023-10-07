#include "ToppingsDecorator.h"

class OnionTopping: public IToppingsDecorator
{
   IBasePizza *basePizza;   // has a realtionship
  public: 
     OnionTopping(IBasePizza *b)
     {
         basePizza = b;
     }
     int cost()
     {
        cout<<"Onion Topping  "<<endl;
        return basePizza->cost() + 10;
     }

};