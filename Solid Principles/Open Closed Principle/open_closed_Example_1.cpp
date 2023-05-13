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


//Interface 
class InvoiceDAO
{
   public:
      virtual void save(Invoice ) = 0;

};

class DatabaseInvoiceDAO: public InvoiceDAO
{
    
    public:
   
    void save(Invoice invoice )
    {
        cout<<endl<<"Saving to DB";
    }
};


class FileInvoiceDAO: public InvoiceDAO
{
    
    public:
   
    void save(Invoice invoice )
    {
        cout<<endl<<"Saving to File";
    }
};

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
    cout<<"Total Bill="<<invoice.calculateBill();
    InvoiceDAO *in1 ;
    DatabaseInvoiceDAO dbInvoice;
    in1=&dbInvoice;
    in1->save(invoice);
     
    InvoiceDAO *in2;
    FileInvoiceDAO fileInvoice;
    in2=&fileInvoice;
    in2->save(invoice);     

}

