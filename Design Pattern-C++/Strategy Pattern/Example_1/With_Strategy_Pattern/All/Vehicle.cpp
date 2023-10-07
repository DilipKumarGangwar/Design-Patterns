
#include<iostream>
#include "Strategy_INTF.h"
#include "Vehicle.h"

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
     
