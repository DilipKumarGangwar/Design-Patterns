//We should make copy construvtor and assignment operator also PRIVATE

#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    // Making the copy constructor public (problematic)
     // Singleton(const Singleton&) = default;
    //In C++11 => we are saying this is like making it private 
      Singleton(const Singleton&) = delete;
     
     Singleton& operator=(const Singleton&) = delete;

    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }

private:
    Singleton() {}
    static Singleton* instance;
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    // Creating a copy of the Singleton, which shouldn't be allowed
    Singleton singleton2 ( *singleton1);  // Copy constructor called
    *singleton1 = singleton2;  //operator = called

    return 0;
}