#include <iostream>
#include "BankAccount.h"
#include <vector>

class Animal {
    public:
        void eat() {
            std::cout << "Animal eats \n";
        }
    private:
        int secret = 42;
    protected:
        void sleep() {
            std::cout << "Animal slepps\n";
        }
};

class Dog : public Animal {
    public: 
        void bark() {
            std::cout << "Woof!\n";
        }
        void doStoff() {
            eat();      // ✔ public inherited
            sleep();    // ✔ protected inherited
            // secret = 4;  خطأ — secret private في Base
        }
};

class Engin
{
private:
    /* data */
    int model;
public:
    void start() {
        std::cout<< "Engine Started\n";
    }
    void stop() {
        std::cout << "Engine Stopped";
    }
    Engin(/* args */);
    Engin(const Engin& p);
    Engin(int p);
    ~Engin();
};

Engin::Engin(/* args */)
{
    std::cout << "1 - The Engine Constructor is started.\n";
}

Engin::~Engin()
{
    std::cout << "2 - The Engine DeConstructor is Stoped\n";
}
Engin::Engin(const Engin& p) { // copy constrctor
    model = p.model;
}

Engin::Engin() : Engin(4) {} // delegating constructorha

class Car : private Engin {
    public: 
        void drive() {
            start();
            std::cout << "Driving...\n";
        }
        void park() {
            stop();
        }
        Car();
        ~Car();
};

Car::Car() {
    std::cout << "1 - The Car Constructor is started.\n";
}
Car::~Car() {
    std::cout << "2 - The Car DeConstructor is Stoped\n";
}



int main() {
    BankAccount acc(100);
    acc.deposit(50);
    std::cout << acc.getBalance();

    Car c;
    c.drive();
    // c.stop();
}
