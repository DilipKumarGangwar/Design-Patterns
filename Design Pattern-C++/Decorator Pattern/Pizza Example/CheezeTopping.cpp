#include "ToppingsDecorator.h"

class CheezeTopping: public IToppingsDecorator
{
   IBasePizza *basePizza;    // has a realtionship
  public: 
     CheezeTopping(IBasePizza *b)
     {
         basePizza = b;
     }
     int cost()
     {
        cout<<"Cheeze Topping  "<<endl;
        return basePizza->cost() + 5;
     }

};