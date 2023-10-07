#include <iostream>
using namespace std;

#include "../Headers/Factory.h"
#include "../Headers/Bike.h"
#include "../Headers/Car.h"

Vehicle * Factory:: getObject(string choice)
{
    Vehicle * obj = nullptr;
    if(choice == "CAR")
       obj = new Car();
    else if(choice == "BIKE")
       obj = new Bike();

    return obj; 
     
}