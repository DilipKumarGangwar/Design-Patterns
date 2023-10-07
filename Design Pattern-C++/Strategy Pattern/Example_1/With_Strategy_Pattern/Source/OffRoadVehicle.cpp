
#include "../Headers/OffRoadVehicle.h"
#include "../Strategy/Headers/SpecialStrategy.h"


OffRoadVehicle::OffRoadVehicle():Vehicle(new SpecialStrategy())
{

}

