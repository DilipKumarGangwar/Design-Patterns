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
     virtual int getPrice()
     {
          
          return price  ;
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
        int discount = 2;  //2 Rs is discount
        return discount;
    }    
  
      
};
int printBill(MenuItem *m)
{
    
    return  m->getPrice();
  
}

int main()
{
    MenuItem *m = new MenuItem("tea", 20);
    BeverageItem *b = new BeverageItem("coffee", 40 );
  
    int bill= printBill(m);
    cout<<"Total Bill for MenuItem = "<<bill<<endl;
    bill= printBill(b);
    cout<<"Total Bill for Beverages = "<<bill<<endl;
    return 0;
}