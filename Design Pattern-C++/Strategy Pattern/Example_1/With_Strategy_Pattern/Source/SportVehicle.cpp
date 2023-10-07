
#include "../Headers/SportVehicle.h"
#include "../Strategy/Headers/SpecialStrategy.h"



SportVehicle::SportVehicle():Vehicle(new SpecialStrategy())
{
    
}



