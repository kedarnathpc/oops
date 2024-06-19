#include <bits/stdc++.h>
using namespace std;

// static members in c++ : local variables, member variables, member functions

// static local variable (by default valus is 0) 
// -> lifetime is throughout the program 
// -> memory is allocated when program is started, but if a variable is declared without static 
//    then memory is allocated at the function beginning
// -> memory of static variables is not destroyed until the program ends 
//    and a single copy will exist throughout the program execution

void func () {
    static int x;
    int y;

    cout << x << " " << y << endl;
}

// static member variable (variable declared inside a class using static keyword)
// -> must be defined outside the class 
// -> does not belong to any object but to whole class 
// -> there will be only one copy of static member variable for the whole class and also for multiple objects 
// -> any object can use the same copy of the class variable
// -> they can also be used with class name
// -> will be created even if an object is not created 

// static member functions (also called as class function : qualified with the keyword static)
// -> they can only access static member variables in the class
// -> they can be invoked with or without creating an object 


class Account {
private: 
    int balance;  // Instance member variable
    static float rateOfInterest;  // Static member variable or class variable

public:
    void setBalance(int b) {
        this->balance = b;
    }

    int getBalance() {
        return balance;
    }

    static void setRateOfInterest(float rate) {
        rateOfInterest = rate;
    }

    static float getRateOfInterest() {
        return rateOfInterest;
    }
};

float Account:: rateOfInterest = 3.5;

int main () {
    Account A1, A2, A3;

    A1.setRateOfInterest(3.2);
    Account::setRateOfInterest(4.4);

    cout << "success" << endl;
    return 0;
}