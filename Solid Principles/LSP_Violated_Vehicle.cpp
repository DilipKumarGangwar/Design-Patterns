//Liskov Substitution Principle - Violated
#include<bits/stdc++.h>
using namespace std;

class Vehicle
{
  public:
   virtual int getNoOfWheels()
    {
      return 2;
    }
    virtual bool hasEngine()
    {
      return true;
    }
};

class MotorCycle:public Vehicle
{
    
};

class Car :public Vehicle
{
  public:
    int getNoOfWheels()
    {
      return 4;
    }
};

class Bicycle :public Vehicle
{
    public:
      bool hasEngine()
      {
        return NULL;
      }
};

int main()
{
    vector<Vehicle*> vehicleList;
    vehicleList.push_back(new MotorCycle());
    vehicleList.push_back(new Car());
    vehicleList.push_back(new Bicycle());
    // for(auto it= vehicleList.begin(); it!= vehicleList.end();it++)
    // {
    //     cout<< "Engine= "<<to_string((*it)->hasEngine())<<endl;
    //   // cout<< "Engine= "<<(*it)->hasEngine()<<endl;
    //     cout<< "Wheels= "<<(*it)->getNoOfWheels()<<endl;
    // }

     for(auto it: vehicleList)
    {
        cout<< "Engine= "<<it->hasEngine()<<endl;
      
        cout<< "Wheels= "<<it->getNoOfWheels()<<endl;
    }


  
    return 0;
}