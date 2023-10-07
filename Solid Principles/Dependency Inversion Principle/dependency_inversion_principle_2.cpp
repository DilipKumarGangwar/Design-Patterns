//Dependency Inversion Principle
#include<bits/stdc++.h>
using namespace std;


// Scenario 1:
// Paymnent DOne via Stripe API

// class Stripe
// {
//     string user;
//     public:
//     Stripe(string user)
//     {
//        this->user = user;
//     }
//      void makePayment(int amount)
//      {
//         cout<<"Via Stripe: "<<user<< " did Payment for "<<amount<<endl;
//      }

// };



// class Payment
// {
//     Stripe *stripe;
//    public:
//    Payment(Stripe * stripe)
//    {
//        //make stripe object;
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
//    Payment *payment = new Payment(new Stripe("Dilip")); //Dilip is the user who wants to make payment
//    payment->purchaseBike(100); //100 is amount to pay for purcahsing bike 
//    payment->purchaseHelmet(50); //50 is amount to pay for purcahsing bike
//    return 0;
// }


//Scenario 2:
/*
  Stripe is now taking more money for using their API, So we changed to using Paypal API
  Constraint: Paypal API : makePayment() takes 2 parameters as makePayment(string user, int amount)
  It's constructor doesnot take anything
*/



// class Paypal
// {
    
//     public:
   
//      void makePayment(string user,int amount)
//      {
//         cout<<"Via Paypal: "<<user<< " did Payment for "<<amount<<endl;
//      }
// };

// class Payment
// {
//     string user;
//     //Stripe *stripe;
//     Paypal *paypal;
//    public:
//    Payment(string user,Paypal *paypal)
//    {
//        //make stripe object;
//        //this->stripe = new Stripe(user); 

//        // store user and make Paypal object;
//        this->user = user;
//        this->paypal =paypal; 

//    }

//    void purchaseBike(int amount)
//    {
//     //call Paypal API
//        paypal->makePayment(user, amount);
//    }
//    void purchaseHelmet(int amount)
//    {
//        //call Paypal API 
//        paypal->makePayment(user, amount);
//    }


// };



// int main()
// {
//    Payment *payment = new Payment("Dilip", new Paypal()); //Dilip is the user who wants to make payment
  
//    payment->purchaseBike(200); //100 is amount to pay for purcahsing bike 
//     payment->purchaseHelmet(50); //50 is amount to pay for purcahsing bike

//    return 0;
// }




// To avoid all this 
// Use DI principle and make a interface PaymentProcessor having a API pay()

class IPaymentProcessor
{
   public:
     virtual void pay(string user, int amount)=0;
};

class Stripe
{
    public:
    void makePayment(string user,int amount)
    {
       cout<<"Via Stripe: "<<user <<"  did Payment for "<<amount<<endl;
    }

};


class Paypal
{
   
   //  string user;
    public:
    // Paypal(string user)
    // {
    //    this->user = user;
    // }
   
     void makePayment( string user,int amount)
     {
        cout<<"Via Paypal: "<< user<<" did Payment for "<<amount<<endl;
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
       //make stripe object;
       //this->stripe = new Stripe(user); 

       // store user and make Paypal object;
    //    this->user = user;
    //    this->paypal = new Paypal(); 
         this->paymentProcessor = paymentProcessor;      

   }

   void purchaseBike(int amount)
   {
    //call paymentProcessor API =>  Class Payment ( low level module) depend on Interface/abstraction

       paymentProcessor->pay(user, amount);
   }
   void purchaseHelmet(int amount)
   {
        //call paymentProcessor API =>  Class Payment ( low level module) depend on Interface/abstraction
       paymentProcessor->pay(user, amount);
   }


};


class StripeAdapter : public IPaymentProcessor
{
    Stripe *stripe;
    string user;
    public:
    StripeAdapter(string user)
    {
       this->user = user;
    }
    //wrap the makepayment of Stripe inside pay
    void pay(string user, int amount)
    {
        //call to makepayment of Stripe
        stripe->makePayment(user,amount);

    }
};


class PaypalAdapter : public IPaymentProcessor
{
    Paypal *paypal;
    string user;
    public:
    PaypalAdapter(string user)
    {
       this->user = user;
    }
    //wrap the makepayment of paypal inside pay
    void pay(string user, int amount)
    {
        //call to makepayment of Stripe
        paypal->makePayment(user,amount);

    }
};

int main()
{
    
   Payment *payment = new Payment(new StripeAdapter("Dilip")); 
   payment->purchaseBike(100); //100 is amount to pay for purcahsing bike 
    payment->purchaseHelmet(50); //50 is amount to pay for purcahsing bike

     payment = new Payment(new PaypalAdapter("Joy")); 
   payment->purchaseBike(200); //100 is amount to pay for purcahsing bike 
    payment->purchaseHelmet(150); //50 is amount to pay for purcahsing bike

   return 0;
}