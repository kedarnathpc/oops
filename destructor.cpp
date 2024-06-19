#include <bits/stdc++.h>
using namespace std;

// destructor 
// -> instance member function (cannot be static)
// -> same name as class with (~) preceding 
// -> no return type 
// -> no arguments
// -> cannot be overloaded
// -> by default the compiler will create an empty destructor
// -> it is invoked implicitly when object is going to be destroyed
// -> it should be defined to release resources allocated to the object

class Complex {
private:
    int a, b;
public:
    ~Complex () {
        cout << "destructor called" << endl;
    }    
};

void func () {
    Complex C1;
}

int main () {
    func();
    
    return 0;
}