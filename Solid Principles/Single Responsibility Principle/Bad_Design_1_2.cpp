// Here the class Marker is badly designed to have all Responsibility

#include<iostream>
using namespace std;

class Marker
{
   string name;
   string color;
   int year;
   int price;

   public:
   Marker()
   {
      cout<<endl<<"Marker Constructor called";
   }
   Marker( string name, string color, int year, int price)
   {
      this->name = name;
      this->color =  color;
      this->year= year;
      this->price= price;
   }
  
   int getPrice()
   {
    return price;
   }
   
};

class Invoice
{
    Marker marker ;
    int quantity;
    public:
   

    Invoice(Marker marker , int quantity)
    {
         this->marker = marker;
         this->quantity = quantity;
    }

    // Responsility 1 to calculate Bill ( business logic)
    int calculateBill()
    {
        return marker.getPrice() * quantity;
    }



    //Responsility 2 to save to Database
    void saveToDB()
    {
       cout<<endl<<"Saving to DB";
    }
    
    //Responsility 3 to print Invoice to Black/white Printer
    void printInvoiceOnBWPrinter()
    {
         cout<<endl<<"Printing Invoice";
    }
};

int main()
{
   Marker m1("Cello","Red",2022,10);
   Invoice invoice(m1,10);
   cout<<"\nTotal Bill="<<invoice.calculateBill();
   invoice.saveToDB();
   invoice.printInvoiceOnBWPrinter(); 
   return 0;

}

