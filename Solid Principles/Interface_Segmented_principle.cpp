//Interface_Segmented_principle
#include<iostream>

using namespace std;
//Interface

/*
class RestaurantEmployee
{
    public:
        virtual void decideMenu() =0;
        virtual void cookFood() =0;
        virtual void takeOrder() = 0;
        virtual void serveFood() = 0;
        virtual void wash() = 0;
};

class Waiter : public RestaurantEmployee
{
    public:
    //implement every method, although many are not of any use to waiter
    void decideMenu() 
    {

    }
     void cookFood() 
     {

     }
    void takeOrder()
    {
       //take order
    }
    void serveFood()
    {
       //serve food
    }
    void wash() 
    {

    }
};

int main()
{
    Waiter w;
    w.takeOrder();
    w.serveFood();
    return 0;
}

*/

//Interface
class ChefInterface
{
    public:
        virtual void decideMenu() =0;
        virtual void cookFood() =0;
        
       
};


//Interface

class WaiterInterface
{
    public:
    
        virtual void takeOrder() = 0;
        virtual void serveFood() = 0;
     
};

class HelperInterface
{
    public:
        virtual void wash() = 0;
};

class Chef : public ChefInterface
{
    public:
    void decideMenu()
    {

    }

    void cookFood()
    {

    }
};

class Waiter : public WaiterInterface
{
    public:
    
    void takeOrder()
    {
       //take order
    }
    void serveFood()
    {
       //serve food
    }
  
};

class Helper: public HelperInterface
{
    public:
    void wash()
    {

    }
};

int main()
{
   Chef c;
   c.decideMenu();
   c.cookFood();

   Waiter w;
   w.takeOrder();
   w.serveFood();

   Helper h;
   h.wash();
   
    return 0;
}