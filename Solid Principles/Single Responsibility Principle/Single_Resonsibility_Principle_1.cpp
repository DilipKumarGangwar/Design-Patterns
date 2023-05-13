//Classes following SRP

#include<iostream>
using namespace std;

//1st class
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

//2nd class
class Invoice
{
    Marker marker ;
    int quantity;
    public:
    Invoice()
    {
      cout<<endl<<"Invoice Constructor called";
    }
    Invoice(Marker marker , int quantity)
    {
         this->marker = marker;
         this->quantity = quantity;
    }

    int calculateBill()
    {
        return marker.getPrice() * quantity;
    }
};

//3rd class

class InvoiceDAO
{
    Invoice invoice;
    public:
    InvoiceDAO(Invoice invoice)
    {
       this->invoice = invoice;
    }
    void saveToDB()
    {
        cout<<endl<<"Saving to DB";
    }
};

//4th class
class InvoicePrint
{
    Invoice invoice;
    public:
    InvoicePrint(Invoice invoice)
    {
       this->invoice = invoice;
    }
    void printInvoice()
    {
        cout<<endl<<"Printing Invoice";
    }
};
int main()
{
    Marker m1("Cello", "Red",2022, 10);
    Invoice invoice(m1,10);
    cout<<"\nTotal Bill="<<invoice.calculateBill();
    InvoiceDAO in1(invoice);
    in1.saveToDB();
    InvoicePrint in2(invoice);
    in2.printInvoice();

}

