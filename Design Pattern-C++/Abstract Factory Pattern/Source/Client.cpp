#include <iostream>
#include "../Headers/Vehicle_INTF.h"
#include "../Headers/BMW.h"
#include "../Headers/Hyundi.h"
#include "../Headers/Mercedez.h"
#include "../Headers/Swift.h"
#include "../Headers/AbstractVehicleFactory.h"

using namespace std;

int main()
{
    string category,choice;   // choice : CAR, BIKE
    cout<<"Enter which Category of car do you want"<<endl;
    cin>> category;
    cout<<"Enter which Exact car do you want"<<endl;
    cin>> choice;

    //get the object as per Category from factory
    //Hey Factory, give me object as per my Category asked
    IVehicleFactory * VehicleFactory = AbstractVehicleFactory::CreateCategoryObject(category);

   //get the Actual object of Car as per choice from factory
    //Hey Factory, give me object as asked
    Vehicle * actualVehicleObj = IVehicleFactory::getVehicle(choice);

    
    if(actualVehicleObj != nullptr)
       actualVehicleObj->drive();        
    else
      cout<<"You entered wrong choices";
    return 0;
}