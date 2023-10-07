#include "../Headers/AbstractVehicleFactory.h"
#include "../Headers/LuxuryFactory.h"
#include "../Headers/OrdinaryFactory.h"

IVehicleFactory * AbstractVehicleFactory:: CreateCategoryObject(string choice)
{
    IVehicleFactory * obj = nullptr;
    if(choice == "LUXURY")
      obj = new LuxuryFactory();
    else if(choice == "ORDINARY")
      obj = new OrdinaryFactory();
    return obj;  
}