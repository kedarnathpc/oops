#include <bits/stdc++.h>
using namespace std;


// constructor (same name is class name)
// -> instance member function of a class (cannot be static) 
// -> no return type 
// -> is implicitly invoked when an object is created 
// -> used to solve the problem of initialization
// -> why called as constructor ?
//    because it makes an object a object.
//    if you define a car class and make a shift gear method 
//    initially the gear variable has to set to some value otherwise
//    it will be changed / incremented / decremented from a garbage value to garbage value
//    so we have to initialise it with some default value assigned when created an object of a class 


// default constructor (empty)
// -> compiler : implicit default constructor (change in object file not in source file)
// -> if we define out own constructor then no default constructor will be made

// parameterized constructor 
// -> when we pass arguments to initialize variables 
// -> multiple constructors can be made with multiple arguments -> constructor overloading

class Complex {
private:
    int a, b;
public:
    // default constructor
    Complex () {}
    
    // parameterized constructor and constructor overloading
    Complex (int x) {
        a = x;
    }

    Complex (int x, int y) {
        a = x, b = y;
    }

    // copy constructor (argument type is of object)
    // why pass by reference ?
    // -> Prevents Infinite Recursion: If you were to pass the object by value to the copy constructor, 
    //    it would involve calling the copy constructor itself to create the copy, 
    //    leading to infinite recursion and a stack overflow.
    
    Complex (Complex &C) {
        a = C.a, b = C.b;
    }
};

int main () {
    Complex C1, C2(1), C3(1,3);

    // copy constructor
    // -> if a class does not have a constructor then compiler will create 2 constructors
    //    default and copy constructor 
    // -> if we create a default constructor by ourself, compiler will not create default
    //    but still compiler will create copy constructor
    // -> if we create a copy constructor by ourself then the compiler will not create any constructor

    Complex C4(C1);
    return 0;
}