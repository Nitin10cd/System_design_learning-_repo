#include<iostream>
#include<string>
using namespace std;

// class that represents the person
class Person {
    // adding the private members that will be hidden
    int socialID;
    string name;

    public:
    Person(string n , int id): name(n), socialID(id){}

    // getter setters for the name and the id
    string getName() const {
        return name;
    }

    void setName (string newName) {
        name = newName;
    }

    // validaiting the social id
    bool validateID() const {
        return (socialID >= 0 && socialID <= 1000);
    }

};


int main () {
    Person p1("Nitin",20);

    if(!p1.validateID()) {
        cout<< "Invalid Id (or age)\n";
    }
    cout << "Name: " << p1.getName() << endl;
    return 0;
}