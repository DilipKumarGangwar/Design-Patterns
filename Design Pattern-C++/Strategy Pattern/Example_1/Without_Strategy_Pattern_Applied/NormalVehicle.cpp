#ifndef NORMAL_VEHICLE_HPP
#define NORMAL_VEHICLE_HPP

#include "Vehicle.cpp"
#include<iostream>
using namespace std;

class NormalVehicle: public Vehicle
{
    public:
     void drive()
     {
        cout<<"Driving with  Normal Strategy"<<endl;
     }
};

#endif
