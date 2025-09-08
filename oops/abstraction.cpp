#include <bits/stdc++.h>
using namespace std;

// Demonstrating abstraction: Interface (Car) with pure virtual functions
class Car {
public:
    virtual void start_engine() = 0;
    virtual void shift_gear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void stop() = 0;
    virtual void stop_engine() = 0;
    virtual ~Car() {}
};

// Concrete class implementing the abstract Car interface
class SportsCar : public Car {
public:
    string brand;
    string model;
    bool isEngineOn;
    int current_speed;
    int current_gear;

    SportsCar(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        current_speed = 0;
        current_gear = 0;
    }

    void start_engine() override {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void shift_gear(int gear) override {
        if (!isEngineOn) {
            cout << "Cannot shift gear. Engine is off." << endl;
            return;
        }

        current_gear = gear;
        cout << brand << " " << model << " : Shifted to gear " << current_gear << "." << endl;
    }

    void accelerate() override {
        if (!isEngineOn || current_gear == 0) {
            cout << "Cannot accelerate. Engine is off or gear is neutral." << endl;
            return;
        }

        current_speed += 10;
        cout << brand << " " << model << " : Accelerating. Current speed: " << current_speed << " km/h." << endl;
    }

    void stop() override {
        current_speed = 0;
        cout << brand << " " << model << " : Car stopped." << endl;
    }

    void stop_engine() override {
        if (current_speed > 0) {
            cout << "Stop the car before turning off the engine!" << endl;
            return;
        }

        isEngineOn = false;
        current_gear = 0;
        cout << brand << " " << model << " : Engine stopped." << endl;
    }

    ~SportsCar() {
        cout << brand << " " << model << " destroyed." << endl;
    }
};



int main() {
    SportsCar car("Ferrari", "F8");

    car.start_engine();
    car.shift_gear(1);
    car.accelerate();
    car.shift_gear(2);
    car.accelerate();
    car.stop();
    car.stop_engine();

    return 0;
}
