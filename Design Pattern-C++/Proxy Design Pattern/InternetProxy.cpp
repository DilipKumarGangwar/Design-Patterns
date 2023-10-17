#include <iostream>
#include "Internet.h"
#include "RealInternet.cpp"
#include <vector>
#include<algorithm>
using namespace std;

class InternetProxy: public Internet
{
    Internet *internet;
    vector<string> Videos;
    public:
    InternetProxy()
    {
        internet = new RealInternet();
    }
    void Videodownloader(string Video)
    {
        cout<<"Checking if Video already Exists.."<<endl;
        auto it = find(Videos.begin(), Videos.end(), Video);
        if(it != Videos.end())
        {
            cout<<"Video Already in cache..Returning same video.."<<endl;
            //return the same video , do not contact Real Internet
            return ;
        }
        cout<<Video <<" Doesnot Exists already In Proxy Server..contacting Real Internet "<<endl;
        internet->Videodownloader(Video);
        Videos.push_back(Video); //storing for future
        cout<<Video<<"  Successfully taken from Internet by Proxy "<<endl;
    }
    

       
};



