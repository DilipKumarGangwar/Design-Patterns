#include <iostream>
//#include "RealInternet.cpp"
#include "InternetProxy.cpp"
using namespace std;

int main()
{
    //Normal Scenario
    // Internet * i= new RealInternet();
    // i->Videodownloader("Video1");
    // i->Videodownloader("Video2");
    // i->Videodownloader("Video1");

    //Using proxy
    Internet * i= new InternetProxy();
    i->Videodownloader("Video1");
    i->Videodownloader("Video2");
    i->Videodownloader("Video1");
    return 0;
}