#include "BasePizza.h"
#include "VegDelightPizza.cpp"
#include "FarmHousePizza.cpp"
#include "CheezeTopping.cpp"
#include "OnionTopping.cpp"

int main()
{
    //construct BasePizza
    IBasePizza *bp1= new VegDelightPizza ();
    //Add toppings
    IBasePizza *bp2= new CheezeTopping(bp1);

    //Calculate Prize
    cout<<bp2->cost();

    //construct  Farmhouse Pizza with Onion Topping
    IBasePizza *bp3 =new OnionTopping(new FarmHousePizza());
    //Calculate Pizza
    cout<<bp3->cost();
    return 0;
}