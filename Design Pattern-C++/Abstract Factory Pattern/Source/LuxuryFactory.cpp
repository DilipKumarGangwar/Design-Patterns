#include<iostream>
#include "../Headers/Vehicle_INTF.h"
#include "../Headers/BMW.h"
#include "../Headers/Mercedez.h"
#include "../Headers/VehicleFactory.h"

using namespace std;

Vehicle * IVehicleFactory::getVehicle(string choice)
{
    Vehicle * v= nullptr;
    if( choice == "BMW")
      v = new BMW();
    else if( choice == "Mercedez")
      v = new Mercedez();
    return v;  
}
