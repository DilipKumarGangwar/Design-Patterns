#include<iostream>

using namespace std;


class Singleton {
public:
    Singleton& getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return *instance;
    }
    void setValue(int value) {
        this->value = value;
    }
    int getValue() const {
        return value;
    }
private:
    Singleton() {} // Private constructor to prevent instantiation.
    //Singleton(Singleton const&) = delete; // Delete copy constructor.
    //void operator=(Singleton const&) = delete; // Delete assignment operator.
    Singleton* instance = nullptr;
    int value = 0;
};

int main()
{
    Singleton& singleton1 = Singleton::getInstance();
    Singleton& singleton2 = Singleton::getInstance();

}