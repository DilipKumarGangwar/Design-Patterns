#include <iostream>
#include "../Headers/Vehicle_INTF.h"
#include "../Headers/Bike.h"
#include "../Headers/Car.h"
#include "../Headers/Factory.h"
using namespace std;

int main()
{
    string choice;   // choice : CAR, BIKE
    cout<<"Enter whose object you need"<<endl;
    cin>> choice;

    //get the object from factory
    //Hey Factory, give me object as per my choice
    Vehicle  *obj = Factory::getObject(choice);
    if(obj != nullptr)
       obj->drive();        
    else
      cout<<"You entered wrong choice";
    return 0;
}