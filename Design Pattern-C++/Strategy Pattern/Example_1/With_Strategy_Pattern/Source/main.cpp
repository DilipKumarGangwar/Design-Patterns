#include<iostream>
#include "../Headers/Vehicle.h"
#include "../Headers/NormalVehicle.h"
#include "../Headers/OffRoadVehicle.h"
#include "../Headers/SportVehicle.h"

using namespace std;

int main()
{
    Vehicle* vehicle1 = new NormalVehicle();
    Vehicle* vehicle2 = new OffRoadVehicle();
    Vehicle* vehicle3 = new SportVehicle();

    vehicle1->drive();
    vehicle2->drive();
    vehicle3->drive();

    delete vehicle1;
    delete vehicle2;
    delete vehicle3;

}