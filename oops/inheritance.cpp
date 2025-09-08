#include <bits/stdc++.h>
using namespace std;

// Base Class
class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << "Car Engine is On" << endl;
    }

    virtual void accelerate() {
        if (!isEngineOn) {
            cout << "Car Engine is off right now" << endl;
        } else {
            cout << brand << " model: " << model << " is running" << endl;
            currentSpeed += 20;
            cout << "Current speed: " << currentSpeed << " km/h" << endl;
        }
    }

    void break_car() {
        if (currentSpeed <= 0) {
            cout << "Car is already stopped" << endl;
        } else {
            currentSpeed -= 20;
            cout << "Car speed reduced by 20. Current speed: " << currentSpeed << " km/h" << endl;
        }
    }

    virtual ~Car() {}
};

// First Child Class: ManualCar
class ManualCar : public Car {
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m) {
        currentGear = 0;
    }

    void shiftGear(int gear) {
        if (gear < 0 || gear > 5) {
            cout << "Invalid gear. Please select between 0 (neutral) and 5." << endl;
        } else {
            currentGear = gear;
            cout << "Shifted to gear: " << currentGear << endl;
        }
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << "Cannot accelerate. Engine is off." << endl;
        } else if (currentGear == 0) {
            cout << "Cannot accelerate in neutral gear." << endl;
        } else {
            currentSpeed += 10 * currentGear;
            cout << brand << " " << model << " (Manual) accelerating in gear " << currentGear
                 << ". Current speed: " << currentSpeed << " km/h" << endl;
        }
    }
};

// Second Child Class: ElectricCar
class ElectricCar : public Car {
public:
    ElectricCar(string b, string m) : Car(b, m) {}

    void accelerate() override {
        if (!isEngineOn) {
            cout << "Cannot accelerate. Engine is off." << endl;
        } else {
            currentSpeed += 15;
            cout << brand << " " << model << " (Electric) accelerated. Current speed: "
                 << currentSpeed << " km/h" << endl;
        }
    }

    void chargeBattery() {
        cout << "Charging battery of " << brand << " " << model << "..." << endl;
    }
};

// Main function to test both cars
int main() {
    cout << "--- Manual Car Test ---" << endl;
    ManualCar manual("Toyota", "Corolla");
    manual.startEngine();
    manual.shiftGear(1);
    manual.accelerate();
    manual.shiftGear(2);
    manual.accelerate();
    manual.break_car();

    cout << "\n--- Electric Car Test ---" << endl;
    ElectricCar electric("Tesla", "Model S");
    electric.startEngine();
    electric.accelerate();
    electric.accelerate();
    electric.chargeBattery();
    electric.break_car();

    return 0;
}
