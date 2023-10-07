#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include<iostream>

using namespace std;

class Vehicle
{
   public:
      virtual void drive() 
      {
        cout<<"Driving with  Normal xyz  Strategy"<<endl;
      }
     
};
#endif