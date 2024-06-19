#include <bits/stdc++.h>
using namespace std;


// why structures in c++ when there are classes in c++ ?
// -> to have backward compatibility with C

// properties of member functions of a class
// -> members of class are by default private and of struct are public
// -> can directly access any data member of class
// -> can be defined outside of class using scope resolution operator and membership label
// -> when a member function is defined inside of a class, it is by default inline, but when defined outside
//    the class, we have to explicitly mention the inline keyword


// class is a description of an object

class Complex {
private:
    // instance member variables
    int a, b; 
    
public:
    // instance member functions
    void changeDataAndShow (int, int);
    void getData (int x, int y) {
        a = x, b = y;
    }

    void showData () {
        cout << "a = " << a << " b = " << b << endl;
    }

    Complex addData (Complex C) {
        Complex temp;

        temp.a = a + C.a;
        temp.b = b + C.b;

        return temp;
    }
};

void Complex:: changeDataAndShow (int x, int y) {
    a = x, b = y;

    cout << "a = " << a << " b = " << b << endl;
}

// function call by passing object and returning object 
// the state of an object should only be changed by its methods

int main () {
    Complex C1, C2, C3; // object is an instance of a class
    C1.getData(2, 4);
    C1.showData();
    C2.getData(2, 5);
    C2.showData();

    C3 = C1.addData(C2);
    C3.showData();

    return 0;
}