#include "NormalVehicle.h"
#include "NormalStrategy.h"




NormalVehicle::NormalVehicle():Vehicle(new NormalStrategy())
{

}


