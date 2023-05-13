//Dependency Inversion Principle
#include<iostream>
using namespace std;

//Interface
class Keyboard
{
    public:
    virtual string getType() = 0;
};

//Interface
class Mouse
{
    public:
    virtual string getType()=0;
};


class WiredMouse : public Mouse
{
    string getType()
    {
       // cout<<"Wired Mouse"<<endl;
       return "Wired Mouse";
    }
};

class WirelessMouse : public Mouse
{
    string getType()
    {
       // cout<<"Wireless Mouse"<<endl;
       return "Wireless Mouse";
    }
};


class WiredKeyboard : public Keyboard
{
    string getType()
    {
        //cout<<"Wired keyboard"<<endl;
        return "Wired keyboard";
    }
};

class WirelessKeyboard: public Keyboard
{
    string getType()
    {
        return "Wireless keyboard";
    }
};

class MacBook
{
   Keyboard *keyboard;
   Mouse *mouse;
   public:
   //laptop has keyboard and mouse
   MacBook(Keyboard *keyboard, Mouse *mouse)
   {
      this->keyboard = keyboard;
      this->mouse = mouse;
   }
   void MacBookConfig()
   {
     cout<<"Keyboard=" << keyboard->getType()<<endl;
     cout<<"Mouse=" <<mouse->getType()<<endl;
   }
};



int main()
{
   cout<<"Enter your choice of keyboard , Mouse to add in laptop  1. Wired  2.Wireless"<<endl;
   int ch;
   cin>>ch;

   if(ch==1)
   {
     MacBook m(new WiredKeyboard(),new WiredMouse());  
     m.MacBookConfig();
   }
   else
   {
     MacBook m(new WirelessKeyboard(),new WirelessMouse()); 
     m.MacBookConfig();
   }
        
}