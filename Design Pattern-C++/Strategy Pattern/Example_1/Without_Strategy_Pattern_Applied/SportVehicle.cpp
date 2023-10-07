#ifndef SPORT_VEHICLE_HPP
#define SPORT_VEHICLE_HPP
#include "Vehicle.cpp"
#include<iostream>
using namespace std;

class SportVehicle: public Vehicle
{
    public:
     void drive()
     {
        cout<<"Driving with  Special Strategy"<<endl;
     }
};

#endif
