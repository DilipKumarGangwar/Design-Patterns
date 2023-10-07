#include "BasePizza.h"

class VegDelightPizza: public IBasePizza
{
   public:
     int cost()
     {
        cout<<"Veg Pizza "<<endl;
        return 10;
     }
};