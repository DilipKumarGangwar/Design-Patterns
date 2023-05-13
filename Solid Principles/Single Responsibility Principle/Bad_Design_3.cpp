// Here the class Employee is badly designed to have all Responsibility

#include<bits/stdc++.h>
using namespace std;

class Employee
{
   string name;
   int getRegularHours()
   {
    //logic for calculating Regular working hours
   }

   public:
     int calculateSalary()  //used by CFO
     {
        //logic for calculate salary
        int h = getRegularHours(); 
     }
     int calculateHours()   //USed by HR
     {
        //logic for calculating total hours in office
        //.................
        //..............
        int h = getRegularHours(); 
        //...............
     }
     int saveEmpData()    //Used by Technical Person
     {
      //logic for saving Employee data
     }

};

