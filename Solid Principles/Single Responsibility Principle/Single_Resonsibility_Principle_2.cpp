//Classes following SRP

#include<bits/stdc++.h>
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
   string getMarkerName()
   {
    return name;
   }
};

//2nd class
class Invoice
{
    //list of markers with their quantity
    vector<pair<Marker,int>> listOfItems;
    public:
    Invoice()
    {
      cout<<endl<<"Invoice Constructor called";
    }
    

    void addItems(Marker m,int quantity)
    {
        listOfItems.push_back({m,quantity});
    }
    int calculateBill()
    {
       // return marker.getPrice() * quantity;
       int discount =5,bill=0;
       for(pair<Marker,int> &item: listOfItems)
       {
         //"Cello" marker have discount, so calculate accordingly
         Marker m = item.first;
         int quantity = item.second;
         if(m.getMarkerName() == "Cello")
         {
            bill = bill + (m.getPrice() * quantity) - discount;
            continue;
         }
         bill = bill + (m.getPrice() * quantity);
             
       }
       return bill;
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
    Marker m2("Pilot", "Blue",2021, 5);
    Marker m3("Luxor", "Red",2020, 2);
    Invoice invoice;
    invoice.addItems(m1,2);
    invoice.addItems(m2,3);
    invoice.addItems(m3,5);
    cout<<"\nTotal Bill="<<invoice.calculateBill();
    InvoiceDAO in1(invoice);
    in1.saveToDB();
    InvoicePrint in2(invoice);
    in2.printInvoice();

}

