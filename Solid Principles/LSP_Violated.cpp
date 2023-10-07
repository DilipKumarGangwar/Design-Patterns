//Liskov Substitution Principle - Violated
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
          
          return price ;
     }
   
};


class BeverageItem: public MenuItem
{
    public:
      BeverageItem(string name , int price): MenuItem(name,price)
      {
         
      }

    int getPriceWithDiscount(int discount)
     {
          
          return  price - discount;
     }

      
};

//LSP is viloated here
int printBill(MenuItem *m)
{
    BeverageItem * b = dynamic_cast<BeverageItem*>(m);
    if(b)
    {
        cout<<"Passed instance is of type BeverageItem "<<endl;
        return b->getPriceWithDiscount(2); //2 rs is discount
        
    }  
    else
    {
      cout<<"Passed instance is of type MenuItem "<<endl;
      return m->getPrice();
    }
  
}

int main()
{
    MenuItem *m = new MenuItem("tea", 20);
    BeverageItem *b = new BeverageItem("coffee", 40 );
  
    int bill= printBill(m);
    cout<<"Total Bill = "<<bill<<endl;
    bill= printBill(b);
    cout<<"Total Bill = "<<bill<<endl;
    return 0;
}