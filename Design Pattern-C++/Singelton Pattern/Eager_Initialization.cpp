/* Singelton Design pattern

Use: Only One object/Instance is created for this type of class
Useful when we want to create single database connection object, single looging object etc.


Note: This is Not Thread Safe 
*/

#include <bits/stdc++.h> 
using namespace std; 

class Singelton{
  static Singelton *instance ;
  int data;
   // Not needed as it is default one
//   //private constructor
//   Singelton(){ }
 

  public:
  
  static Singelton* getInstance(){
  
    return instance;   
  }
  void setData(int x){
     data=x;
  }
  int getData(){
      return data;
  }

};

Singelton * Singelton::instance = new Singelton();

int main(){
   Singelton* object1=Singelton::getInstance();
   cout<<"Object Pointed by object1="<<object1<<endl;
   object1->setData(100);
   cout<<"Data="<<object1->getData()<<endl;
   Singelton* object2=Singelton::getInstance();   //object 2 is again same as object 1
   cout<<"Object Pointed by object2="<<object2<<endl;
   if(object1 == object2)
   cout<<"equal ";
   else
    cout<<" Not Equal";

    
   return 0;
}


