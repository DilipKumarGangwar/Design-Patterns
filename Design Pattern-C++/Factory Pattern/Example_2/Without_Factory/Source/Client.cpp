#include <iostream>
#include "../Headers/Vehicle_INTF.h"
#include "../Headers/Bike.h"
#include "../Headers/Car.h"

using namespace std;

int main()
{
    string choice;   // choice : CAR, BIKE
    cout<<"Enter whose object you need"<<endl;
    cin>> choice;

    Vehicle * v = nullptr;
    if(choice == "CAR")
       v = new Car();
    else if(choice == "BIKE")
      v = new Bike();

    if(v!=nullptr)
      v->drive();     
    else
      cout<<"You entered wrong choice";
    return 0;
}