// //Dependency Inversion Principle
// #include<bits/stdc++.h>
// using namespace std;

// // Scenario 1:
// // Paymnent DOne via Stripe API

// class Stripe
// {
   
//     public:
   
//      void makePayment(int amount)
//      {
//         cout<<"Via Stripe: did Payment for "<<amount<<endl;
//      }

// };



// class Payment
// {
//     Stripe *stripe;
//    public:
//    Payment(Stripe *stripe)
//    {
//        //initialise
//        this->stripe = stripe; 
//    }

//    void purchaseBike(int amount)
//    {
//     //call Stripe API
//        stripe->makePayment(amount);
//    }
//    void purchaseHelmet(int amount)
//    {
//        //call Stripe API 
//        stripe->makePayment(amount);
//    }


// };



// int main()
// {
//    Payment *payment = new Payment(new Stripe()); //Dilip is the user who wants to make payment
//    payment->purchaseBike(100); //100 is amount to pay for purcahsing bike 
//    payment->purchaseHelmet(50); //50 is amount to pay for purcahsing bike
//    return 0;
// }


//Dependency Inversion Principle
#include<bits/stdc++.h>
using namespace std;


class IPaymentProcessor
{
   public:
     virtual void makePayment( int amount)=0;
};

class Stripe : public IPaymentProcessor
{
   
    public:
    void makePayment(int amount)
    {
       cout<<"Via Stripe:  did Payment for "<<amount<<endl;
    }

};


class Paypal:  public IPaymentProcessor
{
   
    public:
   
     void makePayment(int amount)
     {
        cout<<"Via Paypal:  did Payment for "<<amount<<endl;
     }
};

class Payment
{
    string user;
    //Stripe *stripe;
    //Paypal *paypal;
    
    //Now we use PaymentProcessor type instance;
   IPaymentProcessor *paymentProcessor;
   public:
   Payment(IPaymentProcessor *paymentProcessor)
   {
      
         this->paymentProcessor = paymentProcessor;      

   }

   void purchaseBike(int amount)
   {
    //call paymentProcessor API =>  Class Payment ( low level module) depend on Interface/abstraction

       paymentProcessor->makePayment( amount);
   }
   void purchaseHelmet(int amount)
   {
        //call paymentProcessor API =>  Class Payment ( low level module) depend on Interface/abstraction
       paymentProcessor->makePayment( amount);
   }


};



int main()
{
    
   Payment *payment = new Payment(new Stripe()); 
   payment->purchaseBike(100); //100 is amount to pay for purcahsing bike 
    payment->purchaseHelmet(50); //50 is amount to pay for purcahsing bike

    payment = new Payment(new Paypal()); 
   payment->purchaseBike(200); //100 is amount to pay for purcahsing bike 
    payment->purchaseHelmet(150); //50 is amount to pay for purcahsing bike

   return 0;
}