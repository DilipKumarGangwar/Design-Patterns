#include <iostream>
#include "Internet.h"
using namespace std;

class RealInternet: public Internet
{
    public:
       void Videodownloader(string video )
       {
           cout<<"Video: "<<video<<"Downloaded "<<endl;   

       }
};



