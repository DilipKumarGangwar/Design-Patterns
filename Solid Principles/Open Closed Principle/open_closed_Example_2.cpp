//Bad Design:
//Adding  a new  operation  in the existing well tested old class
//=> disturbing the exsisting functionality and creating room for bugs in code

/*
#include<bits/stdc++.h>
using namespace std;

class Calculator
{
    public:
     int PerformOperation(char operation , int a, int b)
     {
        if(operation == '+' )
          return a+b;
        else if(operation == '-')
          return a-b;
         //adding new operation in this class itself as and when they come 
         //thus disturbing/modifying the existing tested class  
     }
};

int main()
{
    int a,b;
    Calculator cal;
    cout<<"Addition="<<cal.PerformOperation('+',2,5)<<endl;
    cout<<"Subtraction="<<cal.PerformOperation('-',2,5);
    return 0;
}
*/

//Good Design Following OCP

//Bad Design:
//Adding  a new  operation  in the existing well tested old class
//=> disturbing the exsisting functionality and creating room for bugs in code

#include<bits/stdc++.h>
using namespace std;

//Interface
class IOperation
{
   
    public:
      virtual int performOperation(int ,int)=0;
};

class Addition:public IOperation
{
    public:
      int performOperation(int a,int b)
      {
        return a+b;
      }
};

class Subtraction:public IOperation
{
    public:
      int performOperation(int a,int b)
      {
        return a - b;
      }
};

class Multiply:public IOperation
{
    public:
      int performOperation(int a,int b)
      {
        return a * b;
      }
};

class Calculator
{
    public:
     int calculate(IOperation *op,int a,int b)
     {
        //Here op is replaced by the respective Object of the class(i.e. Addition,Subtraction) who implements IOperation
        //if op have Addition object, then this call is like
        //=> AdditionObject->performOperation(a,b);
        return op->performOperation(a,b);
     }
};

int main()
{
    int a,b;
    IOperation *op = new Addition();
    Calculator cal;
    cout<<"Addition="<<cal.calculate(op,2,3)<<endl;
    //Addition add;      ok
    // cout<<"Addition="<<cal.calculate(&add,2,3)<<endl;      //ok
    op = new Subtraction();
    cout<<"Subtraction="<<cal.calculate(op,2,3)<<endl;
    op = new Multiply();
    cout<<"Multiply="<<cal.calculate(op,2,3)<<endl;
    return 0;
}
