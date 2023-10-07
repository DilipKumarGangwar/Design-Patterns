#include<iostream>
#include "../Headers/Vehicle_INTF.h"
#include "../Headers/Hyundi.h"
#include "../Headers/Swift.h"
#include "../Headers/VehicleFactory.h"

using namespace std;

Vehicle * IVehicleFactory::getVehicle(string choice)
{
    Vehicle * v= nullptr;
    if( choice == "HYUNDI")
      v = new Hyundi();
    else if( choice == "SWIFT")
      v = new Swift();
    return v;  
}
