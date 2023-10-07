//Thread safe with Double check
#include<iostream>

#include<thread>
#include<mutex>

using namespace std;


class Singleton {
public:
    static Singleton* getInstance() {
      if(instance == nullptr)
      {
        mtx.lock();
        if (instance == nullptr) {
            instance = new Singleton();
            counter++;
        }
        mtx.unlock();
      }
        return instance;
    }
   
    static int getValue()  {
        return counter;
    }
private:
    Singleton() {} // Private constructor to prevent instantiation.
    //Singleton(Singleton const&) = delete; // Delete copy constructor.
    //void operator=(Singleton const&) = delete; // Delete assignment operator.
     static Singleton* instance;
     static  int counter;
     static mutex mtx;
};
Singleton* Singleton:: instance = nullptr;
int Singleton:: counter =0;
mutex Singleton::mtx;

void fun1()
{
    Singleton *singleton1 = Singleton::getInstance();
    cout<<Singleton::getValue()<<endl;
}

void fun2()
{
   Singleton *singleton2 = Singleton::getInstance();
    cout<<Singleton::getValue()<<endl;
}

int main()
{
    thread t1(fun1);
    thread t2(fun2);
    
    t1.join();
    t2.join();
    
}