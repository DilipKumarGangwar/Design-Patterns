
#include "SportVehicle.h"
#include "SpecialStrategy.h"



SportVehicle::SportVehicle():Vehicle(new SpecialStrategy())
{
    
}



