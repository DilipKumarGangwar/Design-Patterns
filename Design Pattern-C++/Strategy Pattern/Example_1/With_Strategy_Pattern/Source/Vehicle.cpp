
#include<iostream>
#include "../Strategy/Headers/Strategy_INTF.h"
#include "../Headers/Vehicle.h"

using namespace std;



//constructor injection
Vehicle::Vehicle(IStrategy *strategy)
{
   this->strategy = strategy;
}
void Vehicle::drive() 
{
   strategy->makeStrategy();
}
     
