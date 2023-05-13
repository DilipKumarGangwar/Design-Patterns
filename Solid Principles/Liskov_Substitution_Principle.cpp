//Liskov Substitution Principle
#include<iostream>
using namespace std;

class MenuItem
{
  public:
    string itemName;
    int price;
  public:
     MenuItem(string name , int price)
     {
        this->itemName = name;
        this->price = price ;
     }
     int getPrice()
     {
          
          return price - getDiscount() ;
     }
  private:
  virtual  int getDiscount()
    {  cout<<"sds";
        return 0;
    }  
};


class BeverageItem: public MenuItem
{
    public:
      BeverageItem(string name , int price): MenuItem(name,price)
      {
         
      }

     int getPrice()
     {
          
          return  price - getDiscount();
     }
 private:
     int getDiscount()
    {
        int discount =10;
        return discount;
    }    
    //   int getPriceWithDiscount(int discount)
    //   {
    //     return price - discount*0.01;
    //   }
      
};
int printBill(MenuItem *m)
{
    
    return  m->getPrice();
  
}

int main()
{
    MenuItem *m = new MenuItem("tea", 20);
  //  cout<<m->getPrice();
    BeverageItem *b = new BeverageItem("coffee", 40 );
   // cout<<b->getPrice();
    cout<<printBill(b);
    return 0;
}