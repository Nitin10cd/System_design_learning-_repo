#include<bits/stdc++.h>
using namespace std;

// in simple word how we can understand the SRP : the class must do only one work means 
// we need to have only one reason to perform changes or can say that the single car can do single work not different work
// ex: remote , particular type of remote can do particular work (ac remote for ac , tv for tv)

// example code 

// product class representing the any items of any E com


//  THIS CODE IS WHEN THE CONDITION OF THE SRE FAIL ----->

// class Product {
//     public: 
//     string name;
//     double price;

//     Product(string name , double price) {
//         this -> name = name;
//         this -> price = price;
//     }
// };

// // taking the example which violate the SRP rule making the cart which handes the multiple requests
// class ShoppingCart {
//     private: 
//     vector<Product *> products; // one to many relatioship with the priduct class
//     public: 

//     // getter and the setter
//     void addProduct(Product *p){
//         products.push_back(p);
//     }
//     const vector<Product *>& getProducts() {
//         return products;
//     } 

//     // Making the functions to represent it doing the multiple jobs 

//     // 1: calculate the price
//     double calculateTotal() {
//         double total = 0;
//         for (auto p: products) {
//             total+=p->price;
//         }
//         return total;
//     }

//     // 2: Print Invoices 
//     void printInvoices() {
//         cout << "Shopping cart Invoices: \n";
//         for (auto p: products) {
//             cout << p -> name << " -$" << p -> price << endl;
//         }
//         cout << "Total: " << calculateTotal() << endl;
//     }

//     // 3: save to db
//     void saveToDatabase() {
//         cout << "Save data to the database" <<endl;
//     }
// };



//  CORRECT IMPLENTAION IN THE ACTUAL FORMATE OF SRE----->

class Product {
    public: 
    string name;
    double price;

    Product(string name , double price) {
        this -> name = name;
        this -> price = price;
    }
};

// taking the example which violate the SRP rule making the cart which handes the multiple requests
// following the sre as only one feature have
class ShoppingCart {
    private: 
    vector<Product *> products; // one to many relatioship with the priduct class
    public: 

    // getter and the setter
    void addProduct(Product *p){
        products.push_back(p);
    }
    const vector<Product *>& getProducts() {
        return products;
    } 

    // Making the functions to represent it doing the multiple jobs 

    // 1: calculate the price
    double calculateTotal() {
        double total = 0;
        for (auto p: products) {
            total+=p->price;
        }
        return total;
    } 
};


// making the another clas
class ShoppingCartPrinter {
    private: 
    ShoppingCart* cart;

    public: 
    ShoppingCartPrinter (ShoppingCart* cart) {
        this -> cart = cart;
    }

     // 2: Print Invoices 
    void printInvoices() {
        cout << "Shopping cart Invoices: \n";
        for (auto p: cart -> getProducts()) {
            cout << p -> name << " -$" << p -> price << endl;
        }
        cout << "Total: " << cart -> calculateTotal() << endl;
    }
};
// it againg  following the rule 