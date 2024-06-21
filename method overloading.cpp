#include <bits/stdc++.h>
using namespace std;

class A {
public:
    void f1 () {}    
    void f2 () {}
};

class B : public A {
    void f1 () {}      // method overriding
    void f2 (int x) {} // method hiding (differ by arguments and one function is in parent and other is in child)
    void f2 (int x, int y) {} // method overloading (differ by arguments and both funtions are in same class)
};

// when a function is called by the object, first it will search the name of the function in child
// if it exists but arguments differ then it gives error 
// but if the function does not exist in child then the compiler will search in parent class 

int main () {   

    // early binding : when obj.f1() is called
    //    its compiler duty to decide which f1() will be called
    //    and which should be chosen will be binded to the call
    B obj;
    // obj.f1(); function from the B class will be called

    // obj.f2(); error
    // obj.f2(3); -> B 
    return 0;
}