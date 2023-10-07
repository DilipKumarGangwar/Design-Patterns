
#include "OffRoadVehicle.h"
#include "SpecialStrategy.h"


OffRoadVehicle::OffRoadVehicle():Vehicle(new SpecialStrategy())
{

}

