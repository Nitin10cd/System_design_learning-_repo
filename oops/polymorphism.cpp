#include <bits/stdc++.h>
using namespace std;

// Base Class
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a generic sound" << endl;
    }
};

// Derived Class 1
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks: Woof Woof!" << endl;
    }
};

// Derived Class 2
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow Meow!" << endl;
    }
};

// Class demonstrating Static Polymorphism (Function Overloading)
class Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    int multiply(int a, int b, int c) {
        return a * b * c;
    }
};

int main() {
    cout << "=== Static Polymorphism Example (Overloading) ===" << endl;
    Calculator calc;
    cout << "2 * 3 = " << calc.multiply(2, 3) << endl;
    cout << "2.5 * 4.5 = " << calc.multiply(2.5, 4.5) << endl;
    cout << "2 * 3 * 4 = " << calc.multiply(2, 3, 4) << endl;

    cout << "\n=== Dynamic Polymorphism Example (Virtual Functions) ===" << endl;
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->sound();  
    animal2->sound(); 

    delete animal1;
    delete animal2;

    return 0;
}
