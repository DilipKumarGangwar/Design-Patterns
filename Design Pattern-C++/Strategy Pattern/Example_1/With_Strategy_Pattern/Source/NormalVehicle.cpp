#include "../Headers/NormalVehicle.h"
#include "../Strategy/Headers/NormalStrategy.h"




NormalVehicle::NormalVehicle():Vehicle(new NormalStrategy())
{

}


