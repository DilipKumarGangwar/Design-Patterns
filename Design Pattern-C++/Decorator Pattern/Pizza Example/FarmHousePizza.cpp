#include "BasePizza.h"

class FarmHousePizza: public IBasePizza
{
   public:
     int cost()
     {
         cout<<"Farmhouse Pizza "<<endl;
        return 10;
     }
};