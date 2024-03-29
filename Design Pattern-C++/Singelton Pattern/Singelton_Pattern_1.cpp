/* Singelton Design pattern

Use: Only One object/Instance is created for this type of class
Useful when we want to create single database connection object, single looging object etc.


Note: This is Not Thread Safe 
*/

#include <bits/stdc++.h> 
using namespace std; 

class Singelton{
  static Singelton *instance;
  int data;
  //private constructor
  Singelton(){ }
 

  public:
   Singelton(const Singelton&) = delete;
    Singelton& operator=(const Singelton&) = delete;
  static Singelton* getInstance(){
    if(instance==nullptr)
       instance= new Singelton();
    return instance;   
  }
  void setData(int x){
     data=x;
  }
  int getData(){
      return data;
  }

};

Singelton* Singelton::instance=nullptr;

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

    //These results in errors as corresponding copy constr and copy assignment op are 
    //mentioned as deleted
   *object1 = *object2; 
   Singelton object3=*object2 ;
   return 0;
}


