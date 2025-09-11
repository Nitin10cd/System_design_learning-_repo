#include<bits/stdc++.h>
using namespace std;

// scenerio => 
// consider a car => (make the 3-4 behaviours as per choice)
   // => car is only of two types => manual , electric
      // => in manual car we have function change-gear(), in electric we have the function charge-battery()
// => or this scenerio make a uml diagram (class diagram) , pick either from the inheritance or the composition (if composition so which)

// both the excel draw img and the code file 


// best way to do this is using the inheritance 
// so first using that then using composiotion
class Car {
    protected:
        string make;
        string model;

    public:
        // costructor
        Car(string mk , string ml): make(mk), model(ml) {

        }


        // common behaviour function
        void start() {
            cout<<"common feature 1 start the car" << endl;
        }

        void stop() {
            cout << "common feature 2 break the car" << endl;
        }

        void drive(){
            cout << "common feature 3 drive the car" << endl;
        }

        // special function of the car 
        virtual void SpecialFunction () = 0;
    
};



class ManualCar : public Car {
public:
    ManualCar(string mk, string mdl) : Car(mk, mdl) {}

    void changeGear() {
        cout << "Changing gear manually in " << make << " " << model << "." << endl;
    }

    // overide the special fuction according the  the use of the current car 
    void SpecialFunction() override {
        changeGear();
    }
};

class ElectricCar : public Car {
public:
    ElectricCar(string mk, string mdl) : Car(mk, mdl) {}

    void chargeBattery() {
        cout << "Charging battery of " << make << " " << model << "." << endl;
    }

    void SpecialFunction() override {
        chargeBattery();
    }
};


int main() {
    ManualCar manualCar("Toyota", "Corolla");
    ElectricCar electricCar("Tesla", "Model 3");

    cout << "--- Manual Car ---" << endl;
    manualCar.start();
    manualCar.drive();
    manualCar.SpecialFunction();
    manualCar.stop();

    cout << "\n--- Electric Car ---" << endl;
    electricCar.start();
    electricCar.drive();
    electricCar.SpecialFunction();
    electricCar.stop();

    return 0;
}