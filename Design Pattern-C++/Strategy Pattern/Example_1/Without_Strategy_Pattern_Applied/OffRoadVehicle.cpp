#ifndef OFFROAD_VEHICLE_HPP
#define OFFROAD_VEHICLE_HPP
#include "Vehicle.cpp"
#include<iostream>
using namespace std;

class OffRoadVehicle: public Vehicle
{
    public:
     void drive()
     {
        cout<<"Driving with  Special Strategy"<<endl;
     }
};
#endif
